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
fn_functor = DIR_MATHQ+"/include-templates/fun_unary_functor.h"
fn_functions = DIR_MATHQ+"/include-templates/fun_unary_functions.h"
fn_realonly_functions = DIR_MATHQ+"/include-templates/fun_unary_real_functions.h"
fn_output = DIR_MATHQ+"/include/fun_unary_AUTO.h"
namespace = "mathq"

ops = [
["+", "pos", "pos", "Number", "Number"],
["-", "neg", "neg", "Number", "Number"],
["!", "not", "not", "Number", "Number"]
]


funcs = [
["std::sin", "sin", "sin", "Number", "Number"],
["std::cos", "cos", "cos", "Number", "Number"],
["std::tan", "tan", "tan", "Number", "Number"],
["std::asin", "asin", "asin", "Number", "Number"],
["std::acos", "acos", "acos", "Number", "Number"],
["std::atan", "atan", "atan", "Number", "Number"],
["std::sinh", "sinh", "sinh", "Number", "Number"],
["std::cosh", "cosh", "cosh", "Number", "Number"],
["std::tanh", "tanh", "tanh", "Number", "Number"],
["std::asinh", "asinh", "asinh", "Number", "Number"],
["std::acosh", "acosh", "acosh", "Number", "Number"],
["std::atanh", "atanh", "atanh", "Number", "Number"],
["std::sqrt", "sqrt", "sqrt", "Number", "Number"],
["std::cbrt", "cbrt", "cbrt", "Number", "Number"],
["mathq::sqr", "sqr", "sqr", "Number", "Number"],
["mathq::cube", "cube", "cube", "Number", "Number"],
["std::exp", "exp", "exp", "Number", "Number"],
["std::exp2", "exp2", "exp2", "Number", "Number"],
["std::expm1", "expm1", "expm1", "Number", "Number"],
["std::log", "log", "log", "Number", "Number"],
["std::log10", "log10", "log10", "Number", "Number"],
["std::log2", "log2", "log2", "Number", "Number"],
["std::log1p", "log1p", "log1p", "Number", "Number"],
["std::logb", "logb", "logb", "Number", "Number"],
["mathq::sgn", "sgn", "sgn", "Number", "Number"],
["std::ceil", "ceil", "ceil", "Number", "Number"],
["std::floor", "floor", "floor", "Number", "Number"],
["std::round", "round", "round", "Number", "Number"],
["std::trunc", "trunc", "trunc", "Number", "Number"],
["std::erf", "erf", "erf", "Number", "Number"],
["std::erfc", "erfc", "erfc", "Number", "Number"],
["std::tgamma", "tgamma", "tgamma", "Number", "Number"],
["std::lgamma", "lgamma", "lgamma", "Number", "Number"],
["std::expint", "expint", "expint", "Number", "Number"],
["std::riemann_zeta", "riemann_zeta", "riemann_zeta", "Number", "Number"],
["std::comp_ellint_1", "comp_ellint_1", "comp_ellint_1", "Number", "Number"],
["std::comp_ellint_2", "comp_ellint_2", "comp_ellint_2", "Number", "Number"],
["mathq::zero", "zero", "zero", "Number", "Number"],
["std::ilogb", "ilogb", "ilogb", "Number", "int"],

["mathq::Imaginary", "imaginary", "imaginary", "Number", "mathq::Imaginary<Number>"],
["mathq::conj", "conj", "conj_imag", "mathq::Imaginary<Number>", "mathq::Imaginary<Number>"],
["mathq::real", "real", "real_imag", "mathq::Imaginary<Number>", "Number"],
["mathq::imag", "imag", "imag_imag", "mathq::Imaginary<Number>", "Number"],
["mathq::abs", "abs", "abs_imag", "mathq::Imaginary<Number>", "Number"],
["mathq::arg", "arg", "arg_imag", "mathq::Imaginary<Number>", "Number"],
["mathq::proj", "proj", "proj_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::exp", "exp", "exp_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::log", "log", "log_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::log10", "log10", "log10_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::sqrt", "sqrt", "sqrt_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::sin", "sin", "sin_imag", "mathq::Imaginary<Number>", "mathq::Imaginary<Number>"],
["mathq::cos", "cos", "cos_imag", "mathq::Imaginary<Number>", "Number"],
["mathq::tan", "tan", "tan_imag", "mathq::Imaginary<Number>", "mathq::Imaginary<Number>"],
["mathq::asin", "asin", "asin_imag", "mathq::Imaginary<Number>", "mathq::Imaginary<Number>"],
["mathq::acos", "acos", "acos_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::atan", "atan", "atan_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::sinh", "sinh", "sinh_imag", "mathq::Imaginary<Number>", "mathq::Imaginary<Number>"],
["mathq::cosh", "cosh", "cosh_imag", "mathq::Imaginary<Number>", "Number"],
["mathq::tanh", "tanh", "tanh_imag", "mathq::Imaginary<Number>", "mathq::Imaginary<Number>"],
["mathq::asinh", "asinh", "asinh_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::acosh", "acosh", "acosh_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],
["mathq::atanh", "atanh", "atanh_imag", "mathq::Imaginary<Number>", "std::complex<Number>"],

["std::conj", "conj", "conj_complex", "std::complex<Number>", "std::complex<Number>"],
["std::real", "real", "real_complex", "std::complex<Number>", "Number"],
["std::imag", "imag", "imag_complex", "std::complex<Number>", "Number"],
["std::abs", "abs", "abs_complex", "std::complex<Number>", "Number"],
["std::arg", "arg", "arg_complex", "std::complex<Number>", "Number"],
["std::proj", "proj", "proj_complex", "std::complex<Number>", "std::complex<Number>"],
["mathq::round", "round", "round_complex", "std::complex<Number>", "std::complex<Number>"],
["mathq::log2", "log2", "log2_complex", "std::complex<Number>", "std::complex<Number>"],
["mathq::floor", "floor", "floor_complex", "std::complex<Number>", "std::complex<Number>"],
["mathq::ceil", "ceil", "ceil_complex", "std::complex<Number>", "std::complex<Number>"],

["mathq::Quaternion", "quaternion", "quaternion", "Number", "mathq::Quaternion<Number>"],
["mathq::conj", "conj", "conj_quat", "mathq::Quaternion<Number>", "mathq::Quaternion<Number>"],
["mathq::real", "real", "real_quat", "mathq::Quaternion<Number>", "Number"],
["mathq::imag", "imag", "imag_quat", "mathq::Quaternion<Number>", "Number"],
["mathq::jmag", "jmag", "jmag_quat", "mathq::Quaternion<Number>", "Number"],
["mathq::kmag", "kmag", "kmag_quat", "mathq::Quaternion<Number>", "Number"],
["mathq::abs", "abs", "abs_quat", "mathq::Quaternion<Number>", "Number"],
["mathq::exp", "exp", "exp_quat", "mathq::Quaternion<Number>", "mathq::Quaternion<Number>"],
["mathq::log", "log", "log_quat", "mathq::Quaternion<Number>", "mathq::Quaternion<Number>"],


]




rfuncs = [
["mathq::conj", "conj", "conj_real", "Number", "Number"],
["mathq::real", "real", "real_real", "Number", "Number"],
["mathq::imag", "imag", "imag_real", "Number", "Number"],
["std::abs", "abs", "abs_real", "Number", "Number"],
["std::arg", "arg", "arg_real", "Number", "Number"],
["std::proj", "proj", "proj_real", "Number", "std::complex<Number>"],
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
for op in ops:
    function = op[0]
    name = op[1]
    functorname = op[2]
    fun = contents0
    fun = fun.replace("##FUNCTION##",function)
    fun = fun.replace("##FUNCTORNAME##",functorname)
    contents += fun
    count += 1



contents0 = contents0.replace("##MYFILENAME##",fn_functor)
contents0 = contents0.replace("##SCRIPTNAME##",myname)
    
count = 0
for func in funcs:
    function = func[0]
    name = func[1]
    functorname = func[2]
    fun = contents0
    fun = fun.replace("##FUNCTION##",function)
    fun = fun.replace("##FUNCTORNAME##",functorname)
    contents += fun
    count += 1

count = 0
for func in rfuncs:
    function = func[0]
    name = func[1]
    functorname = func[2]
    fun = contents0
    fun = fun.replace("##FUNCTION##",function)
    fun = fun.replace("##FUNCTORNAME##",functorname)
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

contents0 = contents0.replace("##MYFILENAME##",fn_functor)
contents0 = contents0.replace("##SCRIPTNAME##",myname)

count = 0
for op in ops:
    function = "operator"+op[0]
    name = op[1]
    functorname = op[2]
    typeIN = op[3]
    typeOUT = op[4]
    fun = contents0
    fun = fun.replace("##FUNCTION##",function)
    fun = fun.replace("##NAME##",name)
    fun = fun.replace("##COMMENTNAME##",name)
    fun = fun.replace("##FUNCTOR##","FUNCTOR_"+functorname)
    fun = fun.replace("##DIN##",typeIN)
    fun = fun.replace("##DOUT##",typeOUT)
    contents += fun
    count += 1

count = 0
for func in funcs:
    function = func[0]
    name = func[1]
    functorname = func[2]
    typeIN = func[3]
    typeOUT = func[4]
    fun = contents0
    fun = fun.replace("##FUNCTION##",name)
    fun = fun.replace("##NAME##",name)
    fun = fun.replace("##COMMENTNAME##",name)
    fun = fun.replace("##FUNCTOR##","FUNCTOR_"+functorname)
    fun = fun.replace("##DIN##",typeIN)
    fun = fun.replace("##DOUT##",typeOUT)
    contents += fun
    count += 1


with open(fn_realonly_functions, 'r') as file_functions:
    contents0 = file_functions.read()

contents0 = contents0.replace("##MYFILENAME##",fn_realonly_functions)
contents0 = contents0.replace("##SCRIPTNAME##",myname)

count = 0
for func in rfuncs:
    function = func[0]
    name = func[1]
    functorname = func[2]
    typeIN = func[3]
    typeOUT = func[4]
    fun = contents0
    fun = fun.replace("##FUNCTION##",name)
    fun = fun.replace("##NAME##",name)
    fun = fun.replace("##COMMENTNAME##",name)
    fun = fun.replace("##FUNCTOR##","FUNCTOR_"+functorname)
    fun = fun.replace("##DIN##",typeIN)
    fun = fun.replace("##DOUT##",typeOUT)
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
