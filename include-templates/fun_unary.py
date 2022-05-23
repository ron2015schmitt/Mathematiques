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
["+", "pos", "pos", "D", "D"],
["-", "neg", "neg", "D", "D"],
["!", "not", "not", "D", "D"]
]


funcs = [
["std::sin", "sin", "sin", "D", "D"],
["std::cos", "cos", "cos", "D", "D"],
["std::tan", "tan", "tan", "D", "D"],
["std::asin", "asin", "asin", "D", "D"],
["std::acos", "acos", "acos", "D", "D"],
["std::atan", "atan", "atan", "D", "D"],
["std::sinh", "sinh", "sinh", "D", "D"],
["std::cosh", "cosh", "cosh", "D", "D"],
["std::tanh", "tanh", "tanh", "D", "D"],
["std::asinh", "asinh", "asinh", "D", "D"],
["std::acosh", "acosh", "acosh", "D", "D"],
["std::atanh", "atanh", "atanh", "D", "D"],
["std::sqrt", "sqrt", "sqrt", "D", "D"],
["std::cbrt", "cbrt", "cbrt", "D", "D"],
["mathq::sqr", "sqr", "sqr", "D", "D"],
["mathq::cube", "cube", "cube", "D", "D"],
["std::exp", "exp", "exp", "D", "D"],
["std::exp2", "exp2", "exp2", "D", "D"],
["std::expm1", "expm1", "expm1", "D", "D"],
["std::log", "log", "log", "D", "D"],
["std::log10", "log10", "log10", "D", "D"],
["std::log2", "log2", "log2", "D", "D"],
["std::log1p", "log1p", "log1p", "D", "D"],
["std::logb", "logb", "logb", "D", "D"],
["mathq::sgn", "sgn", "sgn", "D", "D"],
["std::ceil", "ceil", "ceil", "D", "D"],
["std::floor", "floor", "floor", "D", "D"],
["std::round", "round", "round", "D", "D"],
["std::trunc", "trunc", "trunc", "D", "D"],
["std::erf", "erf", "erf", "D", "D"],
["std::erfc", "erfc", "erfc", "D", "D"],
["std::tgamma", "tgamma", "tgamma", "D", "D"],
["std::lgamma", "lgamma", "lgamma", "D", "D"],
["std::expint", "expint", "expint", "D", "D"],
["std::riemann_zeta", "riemann_zeta", "riemann_zeta", "D", "D"],
["std::comp_ellint_1", "comp_ellint_1", "comp_ellint_1", "D", "D"],
["std::comp_ellint_2", "comp_ellint_2", "comp_ellint_2", "D", "D"],
["mathq::zero", "zero", "zero", "D", "D"],
["std::ilogb", "ilogb", "ilogb", "D", "int"],

["mathq::Imaginary", "imaginary", "imaginary", "D", "mathq::Imaginary<D>"],
["mathq::conj", "conj", "conj_imag", "mathq::Imaginary<D>", "mathq::Imaginary<D>"],
["mathq::real", "real", "real_imag", "mathq::Imaginary<D>", "D"],
["mathq::imag", "imag", "imag_imag", "mathq::Imaginary<D>", "D"],
["mathq::abs", "abs", "abs_imag", "mathq::Imaginary<D>", "D"],
["mathq::arg", "arg", "arg_imag", "mathq::Imaginary<D>", "D"],
["mathq::proj", "proj", "proj_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::exp", "exp", "exp_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::log", "log", "log_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::log10", "log10", "log10_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::sqrt", "sqrt", "sqrt_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::sin", "sin", "sin_imag", "mathq::Imaginary<D>", "mathq::Imaginary<D>"],
["mathq::cos", "cos", "cos_imag", "mathq::Imaginary<D>", "D"],
["mathq::tan", "tan", "tan_imag", "mathq::Imaginary<D>", "mathq::Imaginary<D>"],
["mathq::asin", "asin", "asin_imag", "mathq::Imaginary<D>", "mathq::Imaginary<D>"],
["mathq::acos", "acos", "acos_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::atan", "atan", "atan_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::sinh", "sinh", "sinh_imag", "mathq::Imaginary<D>", "mathq::Imaginary<D>"],
["mathq::cosh", "cosh", "cosh_imag", "mathq::Imaginary<D>", "D"],
["mathq::tanh", "tanh", "tanh_imag", "mathq::Imaginary<D>", "mathq::Imaginary<D>"],
["mathq::asinh", "asinh", "asinh_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::acosh", "acosh", "acosh_imag", "mathq::Imaginary<D>", "std::complex<D>"],
["mathq::atanh", "atanh", "atanh_imag", "mathq::Imaginary<D>", "std::complex<D>"],

["std::conj", "conj", "conj_complex", "std::complex<D>", "std::complex<D>"],
["std::real", "real", "real_complex", "std::complex<D>", "D"],
["std::imag", "imag", "imag_complex", "std::complex<D>", "D"],
["std::abs", "abs", "abs_complex", "std::complex<D>", "D"],
["std::arg", "arg", "arg_complex", "std::complex<D>", "D"],
["std::proj", "proj", "proj_complex", "std::complex<D>", "std::complex<D>"],
["mathq::round", "round", "round_complex", "std::complex<D>", "std::complex<D>"],
["mathq::log2", "log2", "log2_complex", "std::complex<D>", "std::complex<D>"],
["mathq::floor", "floor", "floor_complex", "std::complex<D>", "std::complex<D>"],
["mathq::ceil", "ceil", "ceil_complex", "std::complex<D>", "std::complex<D>"],

["mathq::Quaternion", "quaternion", "quaternion", "D", "mathq::Quaternion<D>"],
["mathq::conj", "conj", "conj_quat", "mathq::Quaternion<D>", "mathq::Quaternion<D>"],
["mathq::real", "real", "real_quat", "mathq::Quaternion<D>", "D"],
["mathq::imag", "imag", "imag_quat", "mathq::Quaternion<D>", "D"],
["mathq::jmag", "jmag", "jmag_quat", "mathq::Quaternion<D>", "D"],
["mathq::kmag", "kmag", "kmag_quat", "mathq::Quaternion<D>", "D"],
["mathq::abs", "abs", "abs_quat", "mathq::Quaternion<D>", "D"],
["mathq::exp", "exp", "exp_quat", "mathq::Quaternion<D>", "mathq::Quaternion<D>"],
["mathq::log", "log", "log_quat", "mathq::Quaternion<D>", "mathq::Quaternion<D>"],


]




rfuncs = [
["mathq::conj", "conj", "conj_real", "D", "D"],
["mathq::real", "real", "real_real", "D", "D"],
["mathq::imag", "imag", "imag_real", "D", "D"],
["std::abs", "abs", "abs_real", "D", "D"],
["std::arg", "arg", "arg_real", "D", "D"],
["std::proj", "proj", "proj_real", "D", "std::complex<D>"],
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
