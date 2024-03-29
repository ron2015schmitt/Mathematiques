#ifndef MATHQ__FUN_UNARY_AUTO
#define MATHQ__FUN_UNARY_AUTO 1

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
  inline const std::string expression_name() const {
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
  inline const std::string expression_name() const {
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
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_not")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sin: template class for function 'sin'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = sin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sin")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sin")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cos: template class for function 'cos'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = cos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("cos")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cos")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tan: template class for function 'tan'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = tan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("tan")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tan")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asin: template class for function 'asin'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = asin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("asin")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asin")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acos: template class for function 'acos'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = acos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("acos")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acos")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atan: template class for function 'atan'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = atan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("atan")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atan")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sinh: template class for function 'sinh'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = sinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sinh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sinh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cosh: template class for function 'cosh'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = cosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("cosh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cosh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tanh: template class for function 'tanh'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = tanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("tanh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tanh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asinh: template class for function 'asinh'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = asinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("asinh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asinh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acosh: template class for function 'acosh'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = acosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("acosh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acosh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atanh: template class for function 'atanh'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = atanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("atanh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atanh")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sqrt: template class for function 'sqrt'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = sqrt(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sqrt")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sqrt")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cbrt: template class for function 'cbrt'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = cbrt(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("cbrt")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cbrt")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sqr: template class for function 'sqr'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = sqr(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sqr")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sqr")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cube: template class for function 'cube'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = cube(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("cube")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cube")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp: template class for function 'exp'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = exp(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("exp")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp2: template class for function 'exp2'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = exp2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("exp2")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp2")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// expm1: template class for function 'expm1'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = expm1(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("expm1")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_expm1")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log: template class for function 'log'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = log(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log10: template class for function 'log10'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = log10(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log10")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log10")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log2: template class for function 'log2'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = log2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log2")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log2")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log1p: template class for function 'log1p'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = log1p(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log1p")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log1p")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// logb: template class for function 'logb'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = logb(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("logb")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_logb")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sgn: template class for function 'sgn'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = sgn(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sgn")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sgn")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// ceil: template class for function 'ceil'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = ceil(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("ceil")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_ceil")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// floor: template class for function 'floor'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = floor(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("floor")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_floor")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// round: template class for function 'round'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = round(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("round")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_round")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// trunc: template class for function 'trunc'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = trunc(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("trunc")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_trunc")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// erf: template class for function 'erf'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = erf(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("erf")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_erf")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// erfc: template class for function 'erfc'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = erfc(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("erfc")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_erfc")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tgamma: template class for function 'tgamma'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = tgamma(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("tgamma")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tgamma")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// lgamma: template class for function 'lgamma'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = lgamma(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("lgamma")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_lgamma")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// expint: template class for function 'expint'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = expint(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("expint")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_expint")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// riemann_zeta: template class for function 'riemann_zeta'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = riemann_zeta(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("riemann_zeta")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_riemann_zeta")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// comp_ellint_1: template class for function 'comp_ellint_1'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = comp_ellint_1(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("comp_ellint_1")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_comp_ellint_1")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// comp_ellint_2: template class for function 'comp_ellint_2'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = comp_ellint_2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("comp_ellint_2")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_comp_ellint_2")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// zero: template class for function 'zero'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = zero(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("zero")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_zero")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// ilogb: template class for function 'ilogb'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = ilogb(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("ilogb")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_ilogb")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imaginary: template class for function 'Imaginary'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = Imaginary(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("Imaginary")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imaginary")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_imag: template class for function 'conj'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("conj")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_imag: template class for function 'real'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("real")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_imag: template class for function 'imag'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("imag")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_imag: template class for function 'abs'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("abs")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// arg_imag: template class for function 'arg'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = arg(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("arg")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_arg_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// proj_imag: template class for function 'proj'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = proj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("proj")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_proj_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp_imag: template class for function 'exp'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = exp(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("exp")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log_imag: template class for function 'log'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = log(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log10_imag: template class for function 'log10'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = log10(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log10")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log10_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sqrt_imag: template class for function 'sqrt'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = sqrt(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sqrt")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sqrt_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sin_imag: template class for function 'sin'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = sin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sin")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sin_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cos_imag: template class for function 'cos'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = cos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("cos")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cos_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tan_imag: template class for function 'tan'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = tan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("tan")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tan_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asin_imag: template class for function 'asin'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = asin(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("asin")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asin_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acos_imag: template class for function 'acos'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = acos(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("acos")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acos_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atan_imag: template class for function 'atan'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = atan(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("atan")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atan_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// sinh_imag: template class for function 'sinh'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = sinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("sinh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_sinh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// cosh_imag: template class for function 'cosh'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = cosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("cosh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_cosh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// tanh_imag: template class for function 'tanh'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = tanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("tanh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_tanh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// asinh_imag: template class for function 'asinh'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = asinh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("asinh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_asinh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// acosh_imag: template class for function 'acosh'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = acosh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("acosh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_acosh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// atanh_imag: template class for function 'atanh'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = atanh(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("atanh")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_atanh_imag")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_complex: template class for function 'conj'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("conj")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_complex: template class for function 'real'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("real")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_complex: template class for function 'imag'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("imag")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_complex: template class for function 'abs'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("abs")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// arg_complex: template class for function 'arg'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = arg(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("arg")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_arg_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// proj_complex: template class for function 'proj'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = proj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("proj")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_proj_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// round_complex: template class for function 'round'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = round(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("round")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_round_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log2_complex: template class for function 'log2'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = log2(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log2")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log2_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// floor_complex: template class for function 'floor'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = floor(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("floor")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_floor_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// ceil_complex: template class for function 'ceil'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = ceil(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("ceil")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_ceil_complex")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// quaternion: template class for function 'Quaternion'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = Quaternion(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("Quaternion")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_quaternion")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_quat: template class for function 'conj'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("conj")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_quat: template class for function 'real'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("real")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_quat: template class for function 'imag'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("imag")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// jmag_quat: template class for function 'jmag'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = jmag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("jmag")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_jmag_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// kmag_quat: template class for function 'kmag'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = kmag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("kmag")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_kmag_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_quat: template class for function 'abs'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("abs")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// exp_quat: template class for function 'exp'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = exp(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("exp")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_exp_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// log_quat: template class for function 'log'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = log(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("log")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_log_quat")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// conj_real: template class for function 'conj'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = conj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("conj")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_conj_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// real_real: template class for function 'real'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = real(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("real")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_real_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// imag_real: template class for function 'imag'
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
    using namespace mathq;
    EOUT* e2 = new EOUT();
    *e2 = imag(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("imag")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_imag_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// abs_real: template class for function 'abs'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = abs(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("abs")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_abs_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// arg_real: template class for function 'arg'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = arg(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("arg")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR_arg_real")+display::bracketAndStyleTypename(e);
  }
};


// ----------------------------------------------------------------
// proj_real: template class for function 'proj'
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
    using namespace std;
    EOUT* e2 = new EOUT();
    *e2 = proj(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("proj")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto operator+(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_pos<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto operator-(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_neg<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto operator!(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_not<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sin(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_sin<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto cos(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_cos<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto tan(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_tan<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto asin(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_asin<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto acos(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_acos<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto atan(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_atan<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sinh(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_sinh<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto cosh(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_cosh<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto tanh(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_tanh<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto asinh(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_asinh<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto acosh(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_acosh<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto atanh(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_atanh<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sqrt(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_sqrt<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto cbrt(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_cbrt<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sqr(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_sqr<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto cube(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_cube<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto exp(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_exp<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto exp2(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_exp2<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto expm1(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_expm1<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_log<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log10(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_log10<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log2(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_log2<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log1p(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_log1p<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto logb(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_logb<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sgn(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_sgn<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto ceil(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_ceil<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto floor(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_floor<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto round(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_round<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto trunc(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_trunc<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto erf(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_erf<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto erfc(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_erfc<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto tgamma(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_tgamma<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto lgamma(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_lgamma<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto expint(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_expint<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto riemann_zeta(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_riemann_zeta<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto comp_ellint_1(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_comp_ellint_1<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto comp_ellint_2(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_comp_ellint_2<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto zero(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_zero<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto ilogb(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, int>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, int, depth, rank, FUNCTOR_ilogb<Element, EOUT, Num, int>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto imaginary(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Imaginary<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, mathq::Imaginary<Num>, depth, rank, FUNCTOR_imaginary<Element, EOUT, Num, mathq::Imaginary<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto conj(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Imaginary<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, mathq::Imaginary<Num>, depth, rank, FUNCTOR_conj_imag<Element, EOUT, mathq::Imaginary<Num>, mathq::Imaginary<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto real(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_real_imag<Element, EOUT, mathq::Imaginary<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto imag(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_imag_imag<Element, EOUT, mathq::Imaginary<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto abs(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_abs_imag<Element, EOUT, mathq::Imaginary<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto arg(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_arg_imag<Element, EOUT, mathq::Imaginary<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto proj(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_proj_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto exp(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_exp_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_log_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log10(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_log10_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sqrt(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_sqrt_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sin(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Imaginary<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, mathq::Imaginary<Num>, depth, rank, FUNCTOR_sin_imag<Element, EOUT, mathq::Imaginary<Num>, mathq::Imaginary<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto cos(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_cos_imag<Element, EOUT, mathq::Imaginary<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto tan(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Imaginary<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, mathq::Imaginary<Num>, depth, rank, FUNCTOR_tan_imag<Element, EOUT, mathq::Imaginary<Num>, mathq::Imaginary<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto asin(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Imaginary<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, mathq::Imaginary<Num>, depth, rank, FUNCTOR_asin_imag<Element, EOUT, mathq::Imaginary<Num>, mathq::Imaginary<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto acos(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_acos_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto atan(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_atan_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto sinh(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Imaginary<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, mathq::Imaginary<Num>, depth, rank, FUNCTOR_sinh_imag<Element, EOUT, mathq::Imaginary<Num>, mathq::Imaginary<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto cosh(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_cosh_imag<Element, EOUT, mathq::Imaginary<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto tanh(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Imaginary<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, mathq::Imaginary<Num>, depth, rank, FUNCTOR_tanh_imag<Element, EOUT, mathq::Imaginary<Num>, mathq::Imaginary<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto asinh(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_asinh_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto acosh(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_acosh_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto atanh(const ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Imaginary<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_atanh_imag<Element, EOUT, mathq::Imaginary<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto conj(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_conj_complex<Element, EOUT, std::complex<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto real(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_real_complex<Element, EOUT, std::complex<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto imag(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_imag_complex<Element, EOUT, std::complex<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto abs(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_abs_complex<Element, EOUT, std::complex<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto arg(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_arg_complex<Element, EOUT, std::complex<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto proj(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_proj_complex<Element, EOUT, std::complex<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto round(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_round_complex<Element, EOUT, std::complex<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log2(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_log2_complex<Element, EOUT, std::complex<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto floor(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_floor_complex<Element, EOUT, std::complex<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto ceil(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, std::complex<Num>, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_ceil_complex<Element, EOUT, std::complex<Num>, std::complex<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto quaternion(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Quaternion<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, mathq::Quaternion<Num>, depth, rank, FUNCTOR_quaternion<Element, EOUT, Num, mathq::Quaternion<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto conj(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Quaternion<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, mathq::Quaternion<Num>, depth, rank, FUNCTOR_conj_quat<Element, EOUT, mathq::Quaternion<Num>, mathq::Quaternion<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto real(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_real_quat<Element, EOUT, mathq::Quaternion<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto imag(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_imag_quat<Element, EOUT, mathq::Quaternion<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto jmag(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_jmag_quat<Element, EOUT, mathq::Quaternion<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto kmag(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_kmag_quat<Element, EOUT, mathq::Quaternion<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto abs(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_abs_quat<Element, EOUT, mathq::Quaternion<Num>, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto exp(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Quaternion<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, mathq::Quaternion<Num>, depth, rank, FUNCTOR_exp_quat<Element, EOUT, mathq::Quaternion<Num>, mathq::Quaternion<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto log(const ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, mathq::Quaternion<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, mathq::Quaternion<Num>, depth, rank>, EOUT, mathq::Quaternion<Num>, depth, rank, FUNCTOR_log_quat<Element, EOUT, mathq::Quaternion<Num>, mathq::Quaternion<Num>>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
inline auto conj(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_conj_real<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
inline auto real(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_real_real<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
inline auto imag(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_imag_real<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
inline auto abs(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_abs_real<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
inline auto arg(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, Num>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, Num, depth, rank, FUNCTOR_arg_real<Element, EOUT, Num, Num>>(x);
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

template <class X, class Element, typename Num, size_t depth, size_t rank, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
inline auto proj(const ExpressionR<X, Element, Num, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, std::complex<Num>>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, Num, depth, rank>, EOUT, std::complex<Num>, depth, rank, FUNCTOR_proj_real<Element, EOUT, Num, std::complex<Num>>>(x);
}
}; // namespace mathq 
#endif // MATHQ__FUN_UNARY_AUTO