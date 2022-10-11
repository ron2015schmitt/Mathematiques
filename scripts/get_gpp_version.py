#!/usr/bin/env python3

import inspect
import sys
import os, os.path
from colorama import init, Fore, Back, Style
import re

import bashutil


init()


usage="""
USAGE: python3 get_gpp_version.py
"""

n = len(sys.argv)
if n != 1:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)


 
CMD="g++ --version"
# print('\nrun "{}"'.format(CMD))
RESULT = bashutil.getstdout('{}'.format(CMD)) 
# print(f"  {RESULT=}")


regexp=re.search("\d+\.\d+\.\d+-[a-zA-Z0-9_]+",RESULT)
regexp=None

if regexp == None:
  regexp=re.search("\d+\.\d+\.\d+",RESULT)  
if regexp == None:
  regexp=re.search("\d+\.\d+",RESULT)  
  
print(regexp.group())






