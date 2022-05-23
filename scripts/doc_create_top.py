#!/usr/bin/env python3

import sys
import datetime
import json
import os

def delete(fname):
  if os.path.exists(fname):  
    os.chmod(fname, 0o777)
    os.remove(fname)

today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

usage="""
USAGE: python3 {} TAG_FILE_MATHQ body.md
""".format(sys.argv[0])

n = len(sys.argv)
if n != 3: 
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)

tag_file = sys.argv[1]
lines = []
with open(tag_file, 'r') as f:
  for line in f:
    lines.append(line.rstrip())
f.close()
tag = lines[0].strip()


header = """

# Mathématiques {}

""".format(tag)


template = sys.argv[2]
f = open(template, 'r')
body = f.read()
f.close()


footer = ""

delete('README.md')
f = open("README.md", "w")
f.write(header + body + footer)
f.close()

