#ifndef MATHQ__FUN_UNARY_AUTO_H
#define MATHQ__FUN_UNARY_AUTO_H 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT 'fun_unary.py'

namespace mathq { 



//********************************************************************
//--------------------------------------------------------------------
//                        Functors
//--------------------------------------------------------------------
//********************************************************************



// ----------------------------------------------------------------
// pos: template class for function '+'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_pos {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return +(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = +(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("+")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_pos")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// neg: template class for function '-'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_neg {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return -(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = -(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("-")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_neg")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// not: template class for function '!'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_not {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return !(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = !(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("!")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_not")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sin: template class for function 'std::sin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sin {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::sin(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::sin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::sin")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sin")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cos: template class for function 'std::cos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_cos {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::cos(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::cos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::cos")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cos")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tan: template class for function 'std::tan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_tan {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::tan(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::tan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::tan")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tan")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asin: template class for function 'std::asin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_asin {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::asin(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::asin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::asin")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asin")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acos: template class for function 'std::acos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_acos {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::acos(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::acos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::acos")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acos")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atan: template class for function 'std::atan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_atan {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::atan(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::atan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::atan")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atan")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sinh: template class for function 'std::sinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sinh {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::sinh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::sinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::sinh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sinh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cosh: template class for function 'std::cosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_cosh {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::cosh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::cosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::cosh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cosh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tanh: template class for function 'std::tanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_tanh {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::tanh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::tanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::tanh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tanh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asinh: template class for function 'std::asinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_asinh {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::asinh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::asinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::asinh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asinh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acosh: template class for function 'std::acosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_acosh {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::acosh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::acosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::acosh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acosh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atanh: template class for function 'std::atanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_atanh {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::atanh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::atanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::atanh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atanh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sqrt: template class for function 'std::sqrt'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sqrt {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::sqrt(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::sqrt(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::sqrt")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sqrt")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cbrt: template class for function 'std::cbrt'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_cbrt {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::cbrt(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::cbrt(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::cbrt")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cbrt")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sqr: template class for function 'mathq::sqr'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sqr {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::sqr(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::sqr(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::sqr")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sqr")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cube: template class for function 'mathq::cube'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_cube {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::cube(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::cube(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::cube")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cube")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp: template class for function 'std::exp'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_exp {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::exp(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::exp(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::exp")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp2: template class for function 'std::exp2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_exp2 {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::exp2(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::exp2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::exp2")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp2")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// expm1: template class for function 'std::expm1'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_expm1 {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::expm1(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::expm1(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::expm1")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_expm1")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log: template class for function 'std::log'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::log(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::log(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::log")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log10: template class for function 'std::log10'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log10 {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::log10(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::log10(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::log10")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log10")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log2: template class for function 'std::log2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log2 {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::log2(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::log2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::log2")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log2")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log1p: template class for function 'std::log1p'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log1p {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::log1p(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::log1p(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::log1p")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log1p")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// logb: template class for function 'std::logb'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_logb {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::logb(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::logb(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::logb")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_logb")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sgn: template class for function 'mathq::sgn'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sgn {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::sgn(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::sgn(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::sgn")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sgn")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// ceil: template class for function 'std::ceil'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_ceil {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::ceil(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::ceil(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::ceil")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_ceil")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// floor: template class for function 'std::floor'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_floor {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::floor(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::floor(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::floor")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_floor")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// round: template class for function 'std::round'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_round {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::round(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::round(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::round")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_round")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// trunc: template class for function 'std::trunc'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_trunc {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::trunc(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::trunc(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::trunc")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_trunc")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// erf: template class for function 'std::erf'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_erf {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::erf(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::erf(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::erf")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_erf")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// erfc: template class for function 'std::erfc'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_erfc {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::erfc(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::erfc(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::erfc")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_erfc")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tgamma: template class for function 'std::tgamma'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_tgamma {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::tgamma(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::tgamma(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::tgamma")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tgamma")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// lgamma: template class for function 'std::lgamma'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_lgamma {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::lgamma(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::lgamma(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::lgamma")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_lgamma")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// expint: template class for function 'std::expint'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_expint {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::expint(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::expint(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::expint")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_expint")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// riemann_zeta: template class for function 'std::riemann_zeta'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_riemann_zeta {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::riemann_zeta(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::riemann_zeta(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::riemann_zeta")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_riemann_zeta")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// comp_ellint_1: template class for function 'std::comp_ellint_1'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_comp_ellint_1 {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::comp_ellint_1(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::comp_ellint_1(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::comp_ellint_1")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_comp_ellint_1")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// comp_ellint_2: template class for function 'std::comp_ellint_2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_comp_ellint_2 {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::comp_ellint_2(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::comp_ellint_2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::comp_ellint_2")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_comp_ellint_2")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// zero: template class for function 'mathq::zero'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_zero {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::zero(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::zero(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::zero")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_zero")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// ilogb: template class for function 'std::ilogb'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_ilogb {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::ilogb(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::ilogb(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::ilogb")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_ilogb")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imaginary: template class for function 'mathq::Imaginary'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_imaginary {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::Imaginary(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::Imaginary(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::Imaginary")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imaginary")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_imag: template class for function 'mathq::conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_conj_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::conj(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::conj")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_imag: template class for function 'mathq::real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_real_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::real(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::real")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_imag: template class for function 'mathq::imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_imag_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::imag(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::imag")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_imag: template class for function 'mathq::abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_abs_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::abs(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::abs")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// arg_imag: template class for function 'mathq::arg'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_arg_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::arg(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::arg(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::arg")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_arg_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// proj_imag: template class for function 'mathq::proj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_proj_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::proj(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::proj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::proj")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_proj_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp_imag: template class for function 'mathq::exp'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_exp_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::exp(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::exp(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::exp")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log_imag: template class for function 'mathq::log'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::log(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::log(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::log")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log10_imag: template class for function 'mathq::log10'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log10_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::log10(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::log10(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::log10")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log10_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sqrt_imag: template class for function 'mathq::sqrt'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sqrt_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::sqrt(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::sqrt(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::sqrt")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sqrt_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sin_imag: template class for function 'mathq::sin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sin_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::sin(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::sin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::sin")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sin_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cos_imag: template class for function 'mathq::cos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_cos_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::cos(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::cos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::cos")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cos_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tan_imag: template class for function 'mathq::tan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_tan_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::tan(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::tan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::tan")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tan_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asin_imag: template class for function 'mathq::asin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_asin_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::asin(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::asin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::asin")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asin_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acos_imag: template class for function 'mathq::acos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_acos_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::acos(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::acos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::acos")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acos_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atan_imag: template class for function 'mathq::atan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_atan_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::atan(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::atan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::atan")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atan_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sinh_imag: template class for function 'mathq::sinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_sinh_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::sinh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::sinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::sinh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sinh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cosh_imag: template class for function 'mathq::cosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_cosh_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::cosh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::cosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::cosh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cosh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tanh_imag: template class for function 'mathq::tanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_tanh_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::tanh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::tanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::tanh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tanh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asinh_imag: template class for function 'mathq::asinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_asinh_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::asinh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::asinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::asinh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asinh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acosh_imag: template class for function 'mathq::acosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_acosh_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::acosh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::acosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::acosh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acosh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atanh_imag: template class for function 'mathq::atanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_atanh_imag {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::atanh(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::atanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::atanh")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atanh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_complex: template class for function 'std::conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_conj_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::conj(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::conj")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_complex: template class for function 'std::real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_real_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::real(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::real")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_complex: template class for function 'std::imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_imag_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::imag(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::imag")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_complex: template class for function 'std::abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_abs_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::abs(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::abs")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// arg_complex: template class for function 'std::arg'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_arg_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::arg(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::arg(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::arg")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_arg_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// proj_complex: template class for function 'std::proj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_proj_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::proj(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::proj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::proj")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_proj_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// round_complex: template class for function 'mathq::round'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_round_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::round(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::round(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::round")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_round_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log2_complex: template class for function 'mathq::log2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log2_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::log2(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::log2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::log2")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log2_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// floor_complex: template class for function 'mathq::floor'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_floor_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::floor(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::floor(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::floor")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_floor_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// ceil_complex: template class for function 'mathq::ceil'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_ceil_complex {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::ceil(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::ceil(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::ceil")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_ceil_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// quaternion: template class for function 'mathq::Quaternion'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_quaternion {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::Quaternion(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::Quaternion(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::Quaternion")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_quaternion")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_quat: template class for function 'mathq::conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_conj_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::conj(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::conj")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_quat: template class for function 'mathq::real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_real_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::real(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::real")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_quat: template class for function 'mathq::imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_imag_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::imag(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::imag")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// jmag_quat: template class for function 'mathq::jmag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_jmag_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::jmag(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::jmag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::jmag")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_jmag_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// kmag_quat: template class for function 'mathq::kmag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_kmag_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::kmag(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::kmag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::kmag")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_kmag_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_quat: template class for function 'mathq::abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_abs_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::abs(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::abs")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp_quat: template class for function 'mathq::exp'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_exp_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::exp(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::exp(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::exp")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log_quat: template class for function 'mathq::log'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_log_quat {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::log(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::log(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::log")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_real: template class for function 'mathq::conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_conj_real {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::conj(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::conj")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_real: template class for function 'mathq::real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_real_real {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::real(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::real")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_real: template class for function 'mathq::imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_imag_real {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return mathq::imag(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = mathq::imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("mathq::imag")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_real: template class for function 'std::abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_abs_real {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::abs(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::abs")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// arg_real: template class for function 'std::arg'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_arg_real {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::arg(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::arg(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::arg")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_arg_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// proj_real: template class for function 'std::proj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_proj_real {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return std::proj(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = std::proj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("std::proj")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_proj_real")+display::bracketAndStyleTypename(e);
  }
};




//********************************************************************
//--------------------------------------------------------------------
//                           Functions
//--------------------------------------------------------------------
//********************************************************************




// ----------------------------------------------------------------
// pos
// template functions for 'pos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// pos 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto operator+(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_pos<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// neg
// template functions for 'neg'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// neg 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto operator-(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_neg<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// not
// template functions for 'not'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// not 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto operator!(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_not<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// sin
// template functions for 'sin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sin 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sin(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_sin<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// cos
// template functions for 'cos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cos 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto cos(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_cos<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// tan
// template functions for 'tan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tan 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto tan(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_tan<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// asin
// template functions for 'asin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// asin 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto asin(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_asin<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// acos
// template functions for 'acos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// acos 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto acos(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_acos<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// atan
// template functions for 'atan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// atan 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto atan(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_atan<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// sinh
// template functions for 'sinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sinh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sinh(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_sinh<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// cosh
// template functions for 'cosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cosh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto cosh(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_cosh<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// tanh
// template functions for 'tanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tanh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto tanh(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_tanh<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// asinh
// template functions for 'asinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// asinh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto asinh(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_asinh<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// acosh
// template functions for 'acosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// acosh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto acosh(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_acosh<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// atanh
// template functions for 'atanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// atanh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto atanh(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_atanh<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// sqrt
// template functions for 'sqrt'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sqrt 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sqrt(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_sqrt<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// cbrt
// template functions for 'cbrt'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cbrt 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto cbrt(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_cbrt<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// sqr
// template functions for 'sqr'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sqr 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sqr(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_sqr<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// cube
// template functions for 'cube'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cube 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto cube(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_cube<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// exp
// template functions for 'exp'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// exp 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto exp(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_exp<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// exp2
// template functions for 'exp2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// exp2 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto exp2(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_exp2<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// expm1
// template functions for 'expm1'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// expm1 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto expm1(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_expm1<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// log
// template functions for 'log'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_log<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// log10
// template functions for 'log10'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log10 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log10(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_log10<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// log2
// template functions for 'log2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log2 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log2(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_log2<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// log1p
// template functions for 'log1p'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log1p 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log1p(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_log1p<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// logb
// template functions for 'logb'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// logb 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto logb(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_logb<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// sgn
// template functions for 'sgn'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sgn 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sgn(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_sgn<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// ceil
// template functions for 'ceil'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ceil 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto ceil(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_ceil<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// floor
// template functions for 'floor'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// floor 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto floor(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_floor<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// round
// template functions for 'round'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// round 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto round(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_round<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// trunc
// template functions for 'trunc'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// trunc 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto trunc(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_trunc<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// erf
// template functions for 'erf'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// erf 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto erf(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_erf<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// erfc
// template functions for 'erfc'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// erfc 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto erfc(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_erfc<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// tgamma
// template functions for 'tgamma'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tgamma 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto tgamma(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_tgamma<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// lgamma
// template functions for 'lgamma'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// lgamma 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto lgamma(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_lgamma<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// expint
// template functions for 'expint'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// expint 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto expint(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_expint<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// riemann_zeta
// template functions for 'riemann_zeta'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// riemann_zeta 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto riemann_zeta(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_riemann_zeta<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// comp_ellint_1
// template functions for 'comp_ellint_1'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// comp_ellint_1 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto comp_ellint_1(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_comp_ellint_1<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// comp_ellint_2
// template functions for 'comp_ellint_2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// comp_ellint_2 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto comp_ellint_2(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_comp_ellint_2<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// zero
// template functions for 'zero'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// zero 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto zero(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_zero<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// ilogb
// template functions for 'ilogb'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ilogb 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto ilogb(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, int>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, int, depth, rank, FUNCTOR_ilogb<Element, EOUT, Number, int>>(x);
}


// ----------------------------------------------------------------
// imaginary
// template functions for 'imaginary'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// imaginary 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto imaginary(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Imaginary<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, mathq::Imaginary<Number>, depth, rank, FUNCTOR_imaginary<Element, EOUT, Number, mathq::Imaginary<Number>>>(x);
}


// ----------------------------------------------------------------
// conj
// template functions for 'conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// conj 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto conj(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Imaginary<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, mathq::Imaginary<Number>, depth, rank, FUNCTOR_conj_imag<Element, EOUT, mathq::Imaginary<Number>, mathq::Imaginary<Number>>>(x);
}


// ----------------------------------------------------------------
// real
// template functions for 'real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// real 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto real(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_real_imag<Element, EOUT, mathq::Imaginary<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// imag
// template functions for 'imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// imag 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto imag(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_imag_imag<Element, EOUT, mathq::Imaginary<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// abs
// template functions for 'abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// abs 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto abs(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_abs_imag<Element, EOUT, mathq::Imaginary<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// arg
// template functions for 'arg'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// arg 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto arg(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_arg_imag<Element, EOUT, mathq::Imaginary<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// proj
// template functions for 'proj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// proj 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto proj(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_proj_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// exp
// template functions for 'exp'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// exp 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto exp(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_exp_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// log
// template functions for 'log'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_log_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// log10
// template functions for 'log10'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log10 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log10(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_log10_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// sqrt
// template functions for 'sqrt'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sqrt 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sqrt(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_sqrt_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// sin
// template functions for 'sin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sin 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sin(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Imaginary<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, mathq::Imaginary<Number>, depth, rank, FUNCTOR_sin_imag<Element, EOUT, mathq::Imaginary<Number>, mathq::Imaginary<Number>>>(x);
}


// ----------------------------------------------------------------
// cos
// template functions for 'cos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cos 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto cos(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_cos_imag<Element, EOUT, mathq::Imaginary<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// tan
// template functions for 'tan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tan 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto tan(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Imaginary<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, mathq::Imaginary<Number>, depth, rank, FUNCTOR_tan_imag<Element, EOUT, mathq::Imaginary<Number>, mathq::Imaginary<Number>>>(x);
}


// ----------------------------------------------------------------
// asin
// template functions for 'asin'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// asin 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto asin(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Imaginary<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, mathq::Imaginary<Number>, depth, rank, FUNCTOR_asin_imag<Element, EOUT, mathq::Imaginary<Number>, mathq::Imaginary<Number>>>(x);
}


// ----------------------------------------------------------------
// acos
// template functions for 'acos'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// acos 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto acos(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_acos_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// atan
// template functions for 'atan'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// atan 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto atan(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_atan_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// sinh
// template functions for 'sinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sinh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto sinh(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Imaginary<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, mathq::Imaginary<Number>, depth, rank, FUNCTOR_sinh_imag<Element, EOUT, mathq::Imaginary<Number>, mathq::Imaginary<Number>>>(x);
}


// ----------------------------------------------------------------
// cosh
// template functions for 'cosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cosh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto cosh(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_cosh_imag<Element, EOUT, mathq::Imaginary<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// tanh
// template functions for 'tanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tanh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto tanh(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Imaginary<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, mathq::Imaginary<Number>, depth, rank, FUNCTOR_tanh_imag<Element, EOUT, mathq::Imaginary<Number>, mathq::Imaginary<Number>>>(x);
}


// ----------------------------------------------------------------
// asinh
// template functions for 'asinh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// asinh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto asinh(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_asinh_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// acosh
// template functions for 'acosh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// acosh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto acosh(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_acosh_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// atanh
// template functions for 'atanh'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// atanh 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto atanh(const MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Imaginary<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_atanh_imag<Element, EOUT, mathq::Imaginary<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// conj
// template functions for 'conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// conj 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto conj(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_conj_complex<Element, EOUT, std::complex<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// real
// template functions for 'real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// real 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto real(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_real_complex<Element, EOUT, std::complex<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// imag
// template functions for 'imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// imag 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto imag(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_imag_complex<Element, EOUT, std::complex<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// abs
// template functions for 'abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// abs 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto abs(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_abs_complex<Element, EOUT, std::complex<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// arg
// template functions for 'arg'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// arg 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto arg(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_arg_complex<Element, EOUT, std::complex<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// proj
// template functions for 'proj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// proj 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto proj(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_proj_complex<Element, EOUT, std::complex<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// round
// template functions for 'round'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// round 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto round(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_round_complex<Element, EOUT, std::complex<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// log2
// template functions for 'log2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log2 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log2(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_log2_complex<Element, EOUT, std::complex<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// floor
// template functions for 'floor'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// floor 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto floor(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_floor_complex<Element, EOUT, std::complex<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// ceil
// template functions for 'ceil'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ceil 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto ceil(const MArrayExpR<X, Element, std::complex<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, std::complex<Number>, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_ceil_complex<Element, EOUT, std::complex<Number>, std::complex<Number>>>(x);
}


// ----------------------------------------------------------------
// quaternion
// template functions for 'quaternion'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// quaternion 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto quaternion(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Quaternion<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, mathq::Quaternion<Number>, depth, rank, FUNCTOR_quaternion<Element, EOUT, Number, mathq::Quaternion<Number>>>(x);
}


// ----------------------------------------------------------------
// conj
// template functions for 'conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// conj 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto conj(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Quaternion<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, mathq::Quaternion<Number>, depth, rank, FUNCTOR_conj_quat<Element, EOUT, mathq::Quaternion<Number>, mathq::Quaternion<Number>>>(x);
}


// ----------------------------------------------------------------
// real
// template functions for 'real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// real 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto real(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_real_quat<Element, EOUT, mathq::Quaternion<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// imag
// template functions for 'imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// imag 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto imag(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_imag_quat<Element, EOUT, mathq::Quaternion<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// jmag
// template functions for 'jmag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// jmag 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto jmag(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_jmag_quat<Element, EOUT, mathq::Quaternion<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// kmag
// template functions for 'kmag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// kmag 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto kmag(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_kmag_quat<Element, EOUT, mathq::Quaternion<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// abs
// template functions for 'abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// abs 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto abs(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_abs_quat<Element, EOUT, mathq::Quaternion<Number>, Number>>(x);
}


// ----------------------------------------------------------------
// exp
// template functions for 'exp'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// exp 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto exp(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Quaternion<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, mathq::Quaternion<Number>, depth, rank, FUNCTOR_exp_quat<Element, EOUT, mathq::Quaternion<Number>, mathq::Quaternion<Number>>>(x);
}


// ----------------------------------------------------------------
// log
// template functions for 'log'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_functor.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank>
auto log(const MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>& x) {
  typedef typename NumberTrait<Element, mathq::Quaternion<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, mathq::Quaternion<Number>, depth, rank>, EOUT, mathq::Quaternion<Number>, depth, rank, FUNCTOR_log_quat<Element, EOUT, mathq::Quaternion<Number>, mathq::Quaternion<Number>>>(x);
}


// ----------------------------------------------------------------
// conj
// template functions for 'conj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_real_functions.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// conj 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto conj(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_conj_real<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// real
// template functions for 'real'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_real_functions.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// real 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto real(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_real_real<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// imag
// template functions for 'imag'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_real_functions.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// imag 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto imag(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_imag_real<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// abs
// template functions for 'abs'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_real_functions.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// abs 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto abs(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_abs_real<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// arg
// template functions for 'arg'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_real_functions.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// arg 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto arg(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, Number>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, Number, depth, rank, FUNCTOR_arg_real<Element, EOUT, Number, Number>>(x);
}


// ----------------------------------------------------------------
// proj
// template functions for 'proj'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_unary_real_functions.h'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// proj 
//----------------------------------------------

template <class X, class Element, typename Number, int depth, int rank, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto proj(const MArrayExpR<X, Element, Number, depth, rank>& x) {
  typedef typename NumberTrait<Element, std::complex<Number>>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, Number, depth, rank>, EOUT, std::complex<Number>, depth, rank, FUNCTOR_proj_real<Element, EOUT, Number, std::complex<Number>>>(x);
}
}; // namespace mathq 
#endif // MATHQ__FUN_UNARY_AUTO_H