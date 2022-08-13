#!/usr/bin/python3

import os, sys
from string import Template

def delete(fname):
  if os.path.exists(fname):  
    os.chmod(fname, 0o777)
    os.remove(fname)


usage="""
USAGE: python3 fun_unary.py DIR_MATHQ
"""

n = len(sys.argv)
if n != 2:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)
DIR_MATHQ = sys.argv[1]

myname = os.path.basename(__file__)
fn_functor_op = DIR_MATHQ+"/include-templates/fun_unary_op_functor.h"
fn_functor = DIR_MATHQ+"/include-templates/fun_unary_functor.h"
fn_functions = DIR_MATHQ+"/include-templates/fun_unary_functions.h"
fn_realonly_functions = DIR_MATHQ+"/include-templates/fun_unary_real_functions.h"
fn_output = DIR_MATHQ+"/include/fun_unary_AUTO.h"
namespace = "mathq"

ops = [
["+", "pos", "pos", "Num", "Num"],
["-", "neg", "neg", "Num", "Num"],
["!", "not", "not", "Num", "Num"]
]


funcs = [
["std", "sin", "sin", "sin", "Num", "Num"],
["std", "cos", "cos", "cos", "Num", "Num"],
["std", "tan", "tan", "tan", "Num", "Num"],
["std", "asin", "asin", "asin", "Num", "Num"],
["std", "acos", "acos", "acos", "Num", "Num"],
["std", "atan", "atan", "atan", "Num", "Num"],
["std", "sinh", "sinh", "sinh", "Num", "Num"],
["std", "cosh", "cosh", "cosh", "Num", "Num"],
["std", "tanh", "tanh", "tanh", "Num", "Num"],
["std", "asinh", "asinh", "asinh", "Num", "Num"],
["std", "acosh", "acosh", "acosh", "Num", "Num"],
["std", "atanh", "atanh", "atanh", "Num", "Num"],
["std", "sqrt", "sqrt", "sqrt", "Num", "Num"],
["std", "cbrt", "cbrt", "cbrt", "Num", "Num"],
["mathq", "sqr", "sqr", "sqr", "Num", "Num"],
["mathq", "cube", "cube", "cube", "Num", "Num"],
["std", "exp", "exp", "exp", "Num", "Num"],
["std", "exp2", "exp2", "exp2", "Num", "Num"],
["std", "expm1", "expm1", "expm1", "Num", "Num"],
["std", "log", "log", "log", "Num", "Num"],
["std", "log10", "log10", "log10", "Num", "Num"],
["std", "log2", "log2", "log2", "Num", "Num"],
["std", "log1p", "log1p", "log1p", "Num", "Num"],
["std", "logb", "logb", "logb", "Num", "Num"],
["mathq", "sgn", "sgn", "sgn", "Num", "Num"],
["std", "ceil", "ceil", "ceil", "Num", "Num"],
["std", "floor", "floor", "floor", "Num", "Num"],
["std", "round", "round", "round", "Num", "Num"],
["std", "trunc", "trunc", "trunc", "Num", "Num"],
["std", "erf", "erf", "erf", "Num", "Num"],
["std", "erfc", "erfc", "erfc", "Num", "Num"],
["std", "tgamma", "tgamma", "tgamma", "Num", "Num"],
["std", "lgamma", "lgamma", "lgamma", "Num", "Num"],
["std", "expint", "expint", "expint", "Num", "Num"],
["std", "riemann_zeta", "riemann_zeta", "riemann_zeta", "Num", "Num"],
["std", "comp_ellint_1", "comp_ellint_1", "comp_ellint_1", "Num", "Num"],
["std", "comp_ellint_2", "comp_ellint_2", "comp_ellint_2", "Num", "Num"],
["mathq", "zero", "zero", "zero", "Num", "Num"],
["std", "ilogb", "ilogb", "ilogb", "Num", "int"],

["mathq", "Imaginary", "imaginary", "imaginary", "Num", "mathq::Imaginary<Num>"],
["mathq", "conj", "conj", "conj_imag", "mathq::Imaginary<Num>", "mathq::Imaginary<Num>"],
["mathq", "real", "real", "real_imag", "mathq::Imaginary<Num>", "Num"],
["mathq", "imag", "imag", "imag_imag", "mathq::Imaginary<Num>", "Num"],
["mathq", "abs", "abs", "abs_imag", "mathq::Imaginary<Num>", "Num"],
["mathq", "arg", "arg", "arg_imag", "mathq::Imaginary<Num>", "Num"],
["mathq", "proj", "proj", "proj_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "exp", "exp", "exp_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "log", "log", "log_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "log10", "log10", "log10_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "sqrt", "sqrt", "sqrt_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "sin", "sin", "sin_imag", "mathq::Imaginary<Num>", "mathq::Imaginary<Num>"],
["mathq", "cos", "cos", "cos_imag", "mathq::Imaginary<Num>", "Num"],
["mathq", "tan", "tan", "tan_imag", "mathq::Imaginary<Num>", "mathq::Imaginary<Num>"],
["mathq", "asin", "asin", "asin_imag", "mathq::Imaginary<Num>", "mathq::Imaginary<Num>"],
["mathq", "acos", "acos", "acos_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "atan", "atan", "atan_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "sinh", "sinh", "sinh_imag", "mathq::Imaginary<Num>", "mathq::Imaginary<Num>"],
["mathq", "cosh", "cosh", "cosh_imag", "mathq::Imaginary<Num>", "Num"],
["mathq", "tanh", "tanh", "tanh_imag", "mathq::Imaginary<Num>", "mathq::Imaginary<Num>"],
["mathq", "asinh", "asinh", "asinh_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "acosh", "acosh", "acosh_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],
["mathq", "atanh", "atanh", "atanh_imag", "mathq::Imaginary<Num>", "std::complex<Num>"],

["std", "conj", "conj", "conj_complex", "std::complex<Num>", "std::complex<Num>"],
["std", "real", "real", "real_complex", "std::complex<Num>", "Num"],
["std", "imag", "imag", "imag_complex", "std::complex<Num>", "Num"],
["std", "abs", "abs", "abs_complex", "std::complex<Num>", "Num"],
["std", "arg", "arg", "arg_complex", "std::complex<Num>", "Num"],
["std", "proj", "proj", "proj_complex", "std::complex<Num>", "std::complex<Num>"],
["mathq", "round", "round", "round_complex", "std::complex<Num>", "std::complex<Num>"],
["mathq", "log2", "log2", "log2_complex", "std::complex<Num>", "std::complex<Num>"],
["mathq", "floor", "floor", "floor_complex", "std::complex<Num>", "std::complex<Num>"],
["mathq", "ceil", "ceil", "ceil_complex", "std::complex<Num>", "std::complex<Num>"],

["mathq", "Quaternion", "quaternion", "quaternion", "Num", "mathq::Quaternion<Num>"],
["mathq", "conj", "conj", "conj_quat", "mathq::Quaternion<Num>", "mathq::Quaternion<Num>"],
["mathq", "real", "real", "real_quat", "mathq::Quaternion<Num>", "Num"],
["mathq", "imag", "imag", "imag_quat", "mathq::Quaternion<Num>", "Num"],
["mathq", "jmag", "jmag", "jmag_quat", "mathq::Quaternion<Num>", "Num"],
["mathq", "kmag", "kmag", "kmag_quat", "mathq::Quaternion<Num>", "Num"],
["mathq", "abs", "abs", "abs_quat", "mathq::Quaternion<Num>", "Num"],
["mathq", "exp", "exp", "exp_quat", "mathq::Quaternion<Num>", "mathq::Quaternion<Num>"],
["mathq", "log", "log", "log_quat", "mathq::Quaternion<Num>", "mathq::Quaternion<Num>"],


]




rfuncs = [
["mathq", "conj", "conj", "conj_real", "Num", "Num"],
["mathq", "real", "real", "real_real", "Num", "Num"],
["mathq", "imag", "imag", "imag_real", "Num", "Num"],
["std", "abs", "abs", "abs_real", "Num", "Num"],
["std", "arg", "arg", "arg_real", "Num", "Num"],
["std", "proj", "proj", "proj_real", "Num", "std::complex<Num>"],
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
with open(fn_functor_op, 'r') as file_functor_op:
    contents0 = file_functor_op.read()

contents0 = contents0.replace("__MYFILENAME__",fn_functor)
contents0 = contents0.replace("__SCRIPTNAME__",myname)

count = 0
for op in ops:
    function = op[0]
    name = op[1]
    functorname = op[2]
    fun = contents0
    fun = fun.replace("__FUNCTION__",function)
    fun = fun.replace("__FUNCTORNAME__",functorname)
    contents += fun
    count += 1



with open(fn_functor, 'r') as file_functor:
    contents0 = file_functor.read()

contents0 = contents0.replace("__MYFILENAME__",fn_functor)
contents0 = contents0.replace("__SCRIPTNAME__",myname)
    
count = 0
for func in funcs:
    function_namespace = func[0]
    function = func[1]
    name = func[2]
    functorname = func[3]
    fun = contents0
    fun = fun.replace("__NAMESPACE__",function_namespace)
    fun = fun.replace("__FUNCTION__",function)
    fun = fun.replace("__FUNCTORNAME__",functorname)
    contents += fun
    count += 1

count = 0
for func in rfuncs:
    function_namespace = func[0]
    function = func[1]
    name = func[2]
    functorname = func[3]
    fun = contents0
    fun = fun.replace("__NAMESPACE__",function_namespace)
    fun = fun.replace("__FUNCTION__",function)
    fun = fun.replace("__FUNCTORNAME__",functorname)
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

contents0 = contents0.replace("__MYFILENAME__",fn_functor)
contents0 = contents0.replace("__SCRIPTNAME__",myname)

count = 0
for op in ops:
    function = "operator"+op[0]
    name = op[1]
    functorname = op[2]
    typeIN = op[3]
    typeOUT = op[4]
    fun = contents0
    fun = fun.replace("using namespace __NAMESPACE__;","")
    fun = fun.replace("__FUNCTION__",function)
    fun = fun.replace("__NAME__",name)
    fun = fun.replace("__COMMENTNAME__",name)
    fun = fun.replace("__FUNCTOR__","FUNCTOR_"+functorname)
    fun = fun.replace("__DIN__",typeIN)
    fun = fun.replace("__DOUT__",typeOUT)
    contents += fun
    count += 1

count = 0
for func in funcs:
    function_namespace = func[0]
    function = func[1]
    name = func[2]
    functorname = func[3]
    typeIN = func[4]
    typeOUT = func[5]
    fun = contents0
    fun = fun.replace("__NAMESPACE__",function_namespace)
    fun = fun.replace("__FUNCTION__",name)
    fun = fun.replace("__NAME__",name)
    fun = fun.replace("__COMMENTNAME__",name)
    fun = fun.replace("__FUNCTOR__","FUNCTOR_"+functorname)
    fun = fun.replace("__DIN__",typeIN)
    fun = fun.replace("__DOUT__",typeOUT)
    contents += fun
    count += 1


with open(fn_realonly_functions, 'r') as file_functions:
    contents0 = file_functions.read()

contents0 = contents0.replace("__MYFILENAME__",fn_realonly_functions)
contents0 = contents0.replace("__SCRIPTNAME__",myname)

count = 0
for func in rfuncs:
    function_namespace = func[0]
    function = func[1]
    name = func[2]
    functorname = func[3]
    typeIN = func[4]
    typeOUT = func[5]
    fun = contents0
    fun = fun.replace("__NAMESPACE__",function_namespace)
    fun = fun.replace("__FUNCTION__",name)
    fun = fun.replace("__NAME__",name)
    fun = fun.replace("__COMMENTNAME__",name)
    fun = fun.replace("__FUNCTOR__","FUNCTOR_"+functorname)
    fun = fun.replace("__DIN__",typeIN)
    fun = fun.replace("__DOUT__",typeOUT)
    contents += fun
    count += 1
    

    
# -----------------------------------------------------
# write to file
# -----------------------------------------------------


fn_output_str=os.path.basename(fn_output).upper().split(".")[0]

NAMESPACE = namespace.upper()
defvar = NAMESPACE+"__"+fn_output_str

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
