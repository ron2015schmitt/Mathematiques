#!/usr/bin/python3

import os, sys
from string import Template


usage="""
USAGE: python3 fun_ternary.py DIR_MATHQ
"""
n = len(sys.argv)
if n != 2:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)
DIR_MATHQ = sys.argv[1]


def delete(fname):
  if os.path.exists(fname):  
    os.chmod(fname, 0o777)
    os.remove(fname)

myname = os.path.basename(__file__)
fn_functor = DIR_MATHQ+"/include-templates/fun_ternary_functor.h"
fn_functions = DIR_MATHQ+"/include-templates/fun_ternary_functions.h"
fn_output = DIR_MATHQ+"/include/fun_ternary_AUTO.h"
namespace = "mathq"


funcs = [
["std::sph_legendre","sph_legendre", "MultType"],
["std::assoc_legendre","assoc_legendre", "MultType"],
["std::assoc_laguerre","assoc_laguerre", "MultType"],
["std::ellint_3","ellint_3", "MultType"],
["std::comp_ellint_3","comp_ellint_3", "MultType"],
]


contents = ""

# -----------------------------------------------------
# functors
# -----------------------------------------------------
contents += """


//********************************************************************
//--------------------------------------------------------------------
//                        Functors
//--------------------------------------------------------------------
//********************************************************************


"""


with open(fn_functor, 'r') as file_functor:
    contents0 = file_functor.read()

contents0 = contents0.replace("##MYFILENAME##",fn_functor)
contents0 = contents0.replace("##SCRIPTNAME##",myname)
    
count = 0
for func in funcs:
    fun = contents0
    fun = fun.replace("##FUNCTION##",func[0])
    fun = fun.replace("##NAME##",func[1])
    contents += fun
    count += 1

    

# -----------------------------------------------------
# functions
# -----------------------------------------------------
contents += """


//********************************************************************
//--------------------------------------------------------------------
//                           Functions
//--------------------------------------------------------------------
//********************************************************************


"""
with open(fn_functions, 'r') as file_functions:
    contents0 = file_functions.read()

contents0 = contents0.replace("##MYFILENAME##",fn_functions)
contents0 = contents0.replace("##SCRIPTNAME##",myname)


count = 0
for func in funcs:
    fun = contents0
    fun = fun.replace("##OP##",func[1])
    fun = fun.replace("##FUNCTION##",func[1])
    fun = fun.replace("##NAME##",func[1])
    fun = fun.replace("##COMMENTNAME##",func[1])
    fun = fun.replace("##TYPECLASS##",func[2])
    contents += fun
    count += 1


    
# -----------------------------------------------------
# write to file
# -----------------------------------------------------


fn_output_str=os.path.basename(fn_output).upper().split(".")[0]

NAMESPACE = namespace.upper()
defvar = NAMESPACE+"__"+fn_output_str+"_H"

prologue = """#ifndef """+defvar+"""
#define """+defvar+""" 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT '"""+myname+"""'

namespace """+namespace+""" { 
"""


epilogue = """}; // namespace mathq 
#endif // """+defvar



contents = prologue + contents + epilogue

#print(contents)
delete(fn_output)
with open(fn_output, 'w') as file_output:
    file_output.write(contents)
