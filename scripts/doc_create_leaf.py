#!/usr/bin/env python3

import sys, os
import datetime
import json

def delete(fname):
  if os.path.exists(fname):  
    os.chmod(fname, 0o777)
    os.remove(fname)

today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

usage="""
USAGE: python3 createdocleaf.py leafname
"""
#print(sys.argv[0])
# print(type(sys.argv))
# print(str(sys.argv))
# for arg in sys.argv:
#     print(arg)

n = len(sys.argv)
if n != 2:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)

name = sys.argv[1]

# #############################################################
# # read branch.json as dict
# #############################################################
# with open('branch.json') as f:
#     branch = json.load(f)


#############################################################
# read name/node.json as dict
#############################################################
with open(name+'/node.json') as f:
    node = json.load(f)


#############################################################
# read subdir/body.md
#############################################################

with open(name+'/body.temp.md') as f:
  body = f.read()


#############################################################
# create markdown doc
#############################################################

top = top = """

{} {}

""".format("#", node["prefix"] + (len(node["prefix"])>0)*" " + node["title"])

# """.format(node["level"]*"#", node["prefix"] + (len(node["prefix"])>0)*" " + node["title"])

doc = node["header"] + top + body + node["footer"]

#############################################################
# write subdir/README.md
#############################################################

fn = node["name"]+'/README.md'
print("dest="+fn)
delete(fn)
with open(fn, 'w') as f:
  f.write(doc)



