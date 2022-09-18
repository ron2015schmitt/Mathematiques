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

HOME=os.path.expanduser('~')

# read in template file
lines = []
fn = "template.src.md"
with open(fn, 'r') as f:
  # print("  FOUND: "+fn)
  body = f.read()

# read in makefile
lines = []
fn = "../../examples/Makefile"
with open(fn, 'r') as f:
  # print("  FOUND: "+fn)
  makefile = f.read()

makefile = makefile.replace(HOME,"[BUILD_PARENT_DIR]")
makefile = "```Makefile\n" + makefile + "```\n"

# print(info)
body = body.replace("__MAKEFILE__",makefile)
# print(body)

# read in makefile
lines = []
fn = "../../examples/example.cpp"
with open(fn, 'r') as f:
  # print("  FOUND: "+fn)
  src = f.read()

src = "```C++\n" + src + "```\n"

# print(info)
body = body.replace("__SOURCE_FILE__",src)
# print(body)

# write body temp file
fn = "script.temp.md"
delete(fn)
with open(fn, "w") as f:
  f.write(body)
