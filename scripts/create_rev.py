#!/usr/bin/env python3

import inspect
import sys
import os, os.path
from colorama import init, Fore, Back, Style

import bashutil


init()

def delete(fname):
  if os.path.exists(fname):  
    os.chmod(fname, 0o777)
    os.remove(fname)

def split_tag(tag):
  error = ""
  
  # split out full_release+metadata
  split=tag.split("+")
  full_release=split[0]
  meta_data=""
  if len(split) > 1:
    meta_data=split[1]
  if len(split) > 2:
    meta_data="+".join(split[1:])
    error += "[More than one '+' encountered]"

  # split out main_tag-pr_tag
  split=full_release.split("-")
  main_tag=split[0]
  pr_tag=""
  if len(split) > 1:
    pr_tag=split[1]
  if len(split) > 2:
      error += "[More than one '-' encountered]"

  # split main_tag
  major=""
  minor=""
  patch=""
  split=main_tag.split(".")
  if len(split) > 0:
    major=split[0]
  if len(split) > 1:
    minor=split[1]
  if len(split) > 2:
    patch=split[2]
  if len(split) > 3:
    error += "[More than 3 numbers in main_tag]"

  # split main_tag
  pr_name=""
  pr_number=""
  split=pr_tag.split(".")
  if len(split) > 0:
    pr_name=split[0]
  if len(split) > 1:
    pr_number=split[1]
  if len(split) > 2:
    error += "[More than 2 vars in pr_tag]"
  
  return { 
    "major": major,
    "minor": minor,
    "patch": patch,
    "prerelease-name": pr_name,
    "prerelease-number": pr_number,
    "meta_data": meta_data,
    "error": error,
  }

usage="""
USAGE: python3 create_rev.py   FEATURE_VERSION_MATHQ_FILE  CPP_VERSION_FILE  PRERELEASE_NAME_FILE  TAG_FILE_MATHQ  TAG_ANNOTATION_FILE
"""

n = len(sys.argv)
if n != 6:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)


FEATURE_VERSION_MATHQ_FILE = sys.argv[1]   # input
CPP_VERSION_FILE = sys.argv[2]   # input
PRERELEASE_NAME_FILE = sys.argv[3]   # input
TAG_FILE_MATHQ = sys.argv[4]       # output
TAG_ANNOTATION_FILE = sys.argv[5]  # output

# get DIR_MATHQ, the top-level dir for this repo
filename = inspect.getframeinfo(inspect.currentframe()).filename
path     = os.path.dirname(os.path.abspath(filename))
split = path.split("/")
split.pop()
DIR_MATHQ = "/".join(split)
print(DIR_MATHQ)


# get the most recent tag
print("  reading from: "+FEATURE_VERSION_MATHQ_FILE)
env = bashutil.source(FEATURE_VERSION_MATHQ_FILE)
FEATURE_VERSION_MATHQ = env["FEATURE_VERSION_MATHQ"]
print(f"{FEATURE_VERSION_MATHQ=}")

# get the C++ version
fn=CPP_VERSION_FILE
print("  reading from: "+fn)
with open(fn, 'r') as f:
  CPP_VERSION = f.readline()
  CPP_VERSION = CPP_VERSION.replace("+","p")
print(f"{CPP_VERSION=}")


META_DATA=CPP_VERSION

# check for a pre-release tag
fn=PRERELEASE_NAME_FILE
print("  reading from: "+fn)
with open(fn, 'r') as f:
  PRERELEASE_NAME = f.readline()
print(f"{PRERELEASE_NAME=}")
print("len={}".format(len(PRERELEASE_NAME)))


# create a new tag
TAG_NEW = FEATURE_VERSION_MATHQ
split = TAG_NEW.split(".")
MAJOR = split[0]
MINOR = split[1]
print(f"{MAJOR=} {MINOR=}")

# git tag -l uses https://man7.org/linux/man-pages/man3/fnmatch.3.html for pattern matching
# -l, --list
#          List tags. With optional <pattern>..., e.g.  git tag --list 'v-*', list only the tags that match the pattern(s).
#          Running "git tag" without arguments also lists all tags. The pattern is a shell wildcard (i.e., matched using fnmatch(3)). Multiple patterns may be given; if any of them matches, the tag is shown.
#          This option is implicitly supplied if any other list-like option such as --contains is provided. See the documentation for each of those options for details.
TAG_PATTERN="{}.{}.*[!-]".format(MAJOR, MINOR)
 
print('\nloading git tags for: TAG_PATTERN="{}"'.format(TAG_PATTERN))
VERSIONS_STR = bashutil.getstdout('git tag -l "{}" | cat'.format(TAG_PATTERN)) 
VERSIONS = VERSIONS_STR.split("\n")
print(f"  {VERSIONS=}")

# get greatest patch/REV for this feature release
REV = -1
for tag in VERSIONS:
  if len(tag) == 0: continue
  stag=split_tag(tag)
  if len(stag['error']) > 0:
    print("  found tag stag=",stag, Style.BRIGHT + Fore.RED + stag['error'] + Style.RESET_ALL)
  else:
    print(f"  found tag {stag=}")    
  myrev=int(stag['patch'])
  if myrev > REV:
    REV = myrev
if REV >= 0:
  print(f"Largest patch found for {MAJOR=}.{MINOR=} is {REV=}")
else:
  print(f"No previous releases found for {MAJOR=}.{MINOR=}")

# if prelease, look for prereleases
PRERELEASE_NUMBER = -1
if len(PRERELEASE_NAME) > 0:
  TAG_PATTERN="{}.*-{}".format(TAG_NEW,PRERELEASE_NAME)
  print('\nloading git tags for pre-release="{}": TAG_PATTERN="{}"'.format(PRERELEASE_NAME,TAG_PATTERN))
  VERSIONS_STR = bashutil.getstdout('git tag -l "{}" | cat'.format(TAG_PATTERN)) 
  VERSIONS = VERSIONS_STR.split("\n")
  print(f"  {VERSIONS=}")

  for tag in VERSIONS:
    if len(tag) == 0: continue
    stag=split_tag(tag)
    print(f"  found tag {stag=}")
    num=int(stag['prerelease-number'])
    # print(f"{num=}")
    if num > PRERELEASE_NUMBER:
      PRERELEASE_NUMBER = num
  PRERELEASE_NUMBER=PRERELEASE_NUMBER+1
  print(f"  {PRERELEASE_NUMBER=}")
  if REV < 0:
    REV = 0

# increment by 1 if not a pre-release
if len(PRERELEASE_NAME) == 0:
  REV=REV+1

# print(f"{MAJOR=} {MINOR=} {REV=}")
MAIN_TAG = "{}.{}".format(TAG_NEW, REV)
print(f"{MAIN_TAG=}")

#make full
FULL_TAG = MAIN_TAG
if len(PRERELEASE_NAME) > 0:
  FULL_TAG += "-"+PRERELEASE_NAME+"."+str(PRERELEASE_NUMBER).rjust(3, '0')
if len(META_DATA) > 0:
  FULL_TAG += "+"+META_DATA

print("\nRESULTS:")
print("  new tag="+FULL_TAG)
print("  writing to: "+TAG_FILE_MATHQ)
delete(TAG_FILE_MATHQ)
with open(TAG_FILE_MATHQ, "w") as f:
  f.write(FULL_TAG)

print("  reading from: "+FEATURE_VERSION_MATHQ_FILE)
with open(FEATURE_VERSION_MATHQ_FILE, 'r') as f:
  version_file_contents = f.read()

print("  writing to: "+TAG_ANNOTATION_FILE)
delete(TAG_ANNOTATION_FILE)
with open(TAG_ANNOTATION_FILE, "w") as f:
  doc = FULL_TAG + "\n" + version_file_contents
  f.write(doc)

# output to screen
print("  FEATURE_VERSION_MATHQ" + Style.RESET_ALL + "=" + Style.BRIGHT + Fore.GREEN + FEATURE_VERSION_MATHQ + Style.RESET_ALL)   
print("  Tag for this commit: " + Style.BRIGHT + Fore.GREEN + FULL_TAG + Style.RESET_ALL)   



