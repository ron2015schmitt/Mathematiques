import sys
import datetime
import json
import os
import re
 
def delete(fname):
  # print("DELETE: "+os.getcwd())
  if os.path.exists(fname):
    os.chmod(fname, 0o777)
    os.remove(fname)

today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

cmd = "python3 " + sys.argv[0]
fullcmd = "python3 " + ' '.join(sys.argv)

usage="""
USAGE: {} TAG_FILE_MATHQ --chapters-and-headings CHAPTER1 ... [--branches CHAPTERS_THAT_HAVE_OWN_MAKEFILE1= ...] [--headings HEADER1= ...]

""".format(cmd)

N = len(sys.argv)

# #help
# if N >= 2 and sys.argv[1] == "--help": 
#     print("\nHELP: {}\n".format(usage))
#     sys.exit(1)


# if N < 3: 
#     print("\nInvalid number of command line arguments ({}): {}\n".format(n,cmd) + usage)
#     sys.exit(1)

# read in template file
lines = []
fn = "template.src.md"
with open(fn, 'r') as f:
  print("  FOUND: "+fn)
  body = f.read()

# read in version file
lines = []
fn = "../../versioning/config.compiler.out.txt"
with open(fn, 'r') as f:
  print("  FOUND: "+fn)
  info = f.read()

# print(info)
body = body.replace("__BUILD_INFO__",info)
# print(body)

# write body temp file
fn = "script.temp.md"
delete(fn)
with open(fn, "w") as f:
  f.write(body)
