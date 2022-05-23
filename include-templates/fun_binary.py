#!/usr/bin/python3

import os, sys
from string import Template

def delete(fname):
  if os.path.exists(fname):  
    os.chmod(fname, 0o777)
    os.remove(fname)

usage="""
USAGE: python3 fun_binary.py DIR_MATHQ
"""
n = len(sys.argv)
if n != 2:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)
DIR_MATHQ = sys.argv[1]

myname = os.path.basename(__file__)
fn_op_functor = DIR_MATHQ+"/include-templates/fun_binary_op_functor.h"
fn_functor = DIR_MATHQ+"/include-templates/fun_binary_functor.h"
fn_functions = DIR_MATHQ+"/include-templates/fun_binary_functions.h"
fn_output = DIR_MATHQ+"/include/fun_binary_AUTO.h"
namespace = "mathq"

ops = [
["+", "add", "Addition", "AddType"],
["-", "subtract", "Subtraction", "SubType"],
["*", "multiply", "Multiplication", "MultType"],
["/", "divide", "Division", "DivType"],
["==", "equals", "Equal to", "RelType"],
["!=", "notequals", "Not equal to", "RelType"],
[">", "greater", "Greater than", "RelType"],
[">=", "greatereq", "Greater than or equal to", "RelType"],
["<", "less", "Less than", "RelType"],
["<=", "lesseq", "Less than or equal to", "RelType"],
["&&", "and", "And", "AndType"],
["||", "or", "Or", "OrType"],
]    


funcs = [
["std::atan2", "atan2", "MultType"],
["std::pow", "pow", "MultType"],
["std::beta", "beta", "MultType"],
["std::legendre", "legendre", "MultType"],
["std::laguerre", "laguerre", "MultType"],
["std::hermite", "hermite", "MultType"],
["std::sph_bessel", "sph_bessel", "MultType"],
["std::sph_neumann", "sph_neumann", "MultType"],
["std::cyl_bessel_i", "cyl_bessel_i", "MultType"],
["std::cyl_bessel_j", "cyl_bessel_j", "MultType"],
["std::cyl_bessel_k", "cyl_bessel_k", "MultType"],
["std::cyl_neumann", "cyl_neumann", "MultType"],
["std::ellint_1", "ellint_1", "MultType"],
["std::ellint_2", "ellint_2", "MultType"],
["mathq::Complex", "Complex", "ComplexType"],
["mathq::polar", "polar", "ComplexType"],
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
with open(fn_op_functor, 'r') as file_functor:
    contents0 = file_functor.read()

contents0 = contents0.replace("##MYFILENAME##",fn_op_functor)
contents0 = contents0.replace("##SCRIPTNAME##",myname)

count = 0
for op in ops:
    fun = contents0
    fun = fun.replace("##OP##",op[0])
    fun = fun.replace("##NAME##",op[1])
    contents += fun
    count += 1


with open(fn_functor, 'r') as file_functor:
    contents0 = file_functor.read()

contents0 = contents0.replace("##MYFILENAME##",fn_functor)
contents0 = contents0.replace("##SCRIPTNAME##",myname)
    
count = 0;
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

count = 0;
for op in ops:
    fun = contents0
    fun = fun.replace("##OP##",op[0])
    fun = fun.replace("##FUNCTION##","operator"+op[0])
    fun = fun.replace("##NAME##",op[1])
    fun = fun.replace("##COMMENTNAME##",op[2])
    fun = fun.replace("##TYPECLASS##",op[3])
    contents += fun
    count += 1

count = 0;
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
