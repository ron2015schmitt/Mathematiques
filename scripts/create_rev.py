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



usage="""
USAGE: python3 create_rev.py   FEATURE_VERSION_MATHQ_FILE  CPP_VERSION_FILE  PRERELEASE_TAG_FILE  TAG_FILE_MATHQ  TAG_ANNOTATION_FILE
"""

n = len(sys.argv)
if n != 6:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)


FEATURE_VERSION_MATHQ_FILE = sys.argv[1]   # input
CPP_VERSION_FILE = sys.argv[2]   # input
PRERELEASE_TAG_FILE = sys.argv[3]   # input
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
print(f"{CPP_VERSION=}")

# check for a pre-release tag
fn=PRERELEASE_TAG_FILE
print("  reading from: "+fn)
with open(fn, 'r') as f:
  PRERELEASE_TAG = f.readline()
print(f"{PRERELEASE_TAG=}")


# create a new tag
TAG_NEW = FEATURE_VERSION_MATHQ
split = TAG_NEW.split(".")
MAJOR = split[0]
MINOR = split[1]
print(f"{MAJOR=} {MINOR=}")
print("  loading git tags for: "+TAG_NEW)
VERSIONS_STR = bashutil.getstdout('git tag -l "v{}.*" | cat'.format(TAG_NEW))
VERSIONS = VERSIONS_STR.split("\n")
REV = 0
if len(VERSIONS) == 1 and VERSIONS[0] == '':
    REV = 0
else:    
    REV = len(VERSIONS)
#print("REV={}".format(REV))

FULL_TAG = "{}.{}".format(TAG_NEW, REV)+"+"+CPP_VERSION
print("  new tag="+FULL_TAG)

print("  writing to: "+TAG_FILE_MATHQ)
delete(TAG_FILE_MATHQ)
f = open(TAG_FILE_MATHQ, "w")
f.write(FULL_TAG)
f.close()

print("  reading from: "+FEATURE_VERSION_MATHQ_FILE)
f = open(FEATURE_VERSION_MATHQ_FILE, 'r')
version_file_contents = f.read()
f.close()

print("  writing to: "+TAG_ANNOTATION_FILE)
delete(TAG_ANNOTATION_FILE)
f = open(TAG_ANNOTATION_FILE, "w")
doc = FULL_TAG + "\n" + version_file_contents
f.write(doc)
f.close()

# output to screen
print("  FEATURE_VERSION_MATHQ" + Style.RESET_ALL + "=" + Style.BRIGHT + Fore.GREEN + FEATURE_VERSION_MATHQ + Style.RESET_ALL)   
print("  Tag for this commit: " + Style.BRIGHT + Fore.GREEN + FULL_TAG + Style.RESET_ALL)   



