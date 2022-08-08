#ifndef MATHQ__FUN_TERNARY_AUTO_H
#define MATHQ__FUN_TERNARY_AUTO_H 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT 'fun_ternary.py'

namespace mathq { 



//********************************************************************
//--------------------------------------------------------------------
//                        Functors
//--------------------------------------------------------------------
//********************************************************************



// ----------------------------------------------------------------
// FUNCTOR_sph_legendre: template class for function 'std::sph_legendre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functor.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class NT4> class FUNCTOR_sph_legendre {
public:
  static NT4 apply(const NT1 d1, const NT2 d2, const NT3 d3) {
    return std::sph_legendre(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(d1, d2, e3);
    return *e4;
  }
  static std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb +" , "+ sc;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    E4 e4;
    NT1 d1;
    NT2 d2;
    NT3 d3;
    NT4 d4;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_sph_legendre));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(e4);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += comma + getTypeName(d4);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_assoc_legendre: template class for function 'std::assoc_legendre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functor.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class NT4> class FUNCTOR_assoc_legendre {
public:
  static NT4 apply(const NT1 d1, const NT2 d2, const NT3 d3) {
    return std::assoc_legendre(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(d1, d2, e3);
    return *e4;
  }
  static std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb +" , "+ sc;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    E4 e4;
    NT1 d1;
    NT2 d2;
    NT3 d3;
    NT4 d4;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_assoc_legendre));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(e4);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += comma + getTypeName(d4);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_assoc_laguerre: template class for function 'std::assoc_laguerre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functor.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class NT4> class FUNCTOR_assoc_laguerre {
public:
  static NT4 apply(const NT1 d1, const NT2 d2, const NT3 d3) {
    return std::assoc_laguerre(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(d1, d2, e3);
    return *e4;
  }
  static std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb +" , "+ sc;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    E4 e4;
    NT1 d1;
    NT2 d2;
    NT3 d3;
    NT4 d4;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_assoc_laguerre));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(e4);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += comma + getTypeName(d4);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_ellint_3: template class for function 'std::ellint_3'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functor.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class NT4> class FUNCTOR_ellint_3 {
public:
  static NT4 apply(const NT1 d1, const NT2 d2, const NT3 d3) {
    return std::ellint_3(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(d1, d2, e3);
    return *e4;
  }
  static std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb +" , "+ sc;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    E4 e4;
    NT1 d1;
    NT2 d2;
    NT3 d3;
    NT4 d4;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_ellint_3));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(e4);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += comma + getTypeName(d4);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_comp_ellint_3: template class for function 'std::comp_ellint_3'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functor.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class NT4> class FUNCTOR_comp_ellint_3 {
public:
  static NT4 apply(const NT1 d1, const NT2 d2, const NT3 d3) {
    return std::comp_ellint_3(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const E1& e1, const NT2 d2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value&& std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const E2& e2, const NT3 d3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, NT1>::value&& std::is_same<T2, NT2>::value&&!std::is_same<T3, NT3>::value, E4& >::type
    apply(const NT1 d1, const NT2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(d1, d2, e3);
    return *e4;
  }
  static std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb +" , "+ sc;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    E4 e4;
    NT1 d1;
    NT2 d2;
    NT3 d3;
    NT4 d4;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_comp_ellint_3));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(e4);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += comma + getTypeName(d4);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};




//********************************************************************
//--------------------------------------------------------------------
//                           Functions
//--------------------------------------------------------------------
//********************************************************************




// ----------------------------------------------------------------
// sph_legendre
// template functions for 'sph_legendre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functions.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sph_legendre (sph_legendre)
//----------------------------------------------



// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



// (111) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class A, class B, class C, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank>
auto sph_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, E2, E3, E4, NT1, NT2, NT3, NT4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_sph_legendre<E1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}



// (110) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , NT3

template <class A, class B, class E1, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT3>::value>>
auto sph_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    E1, E2, NT3, E4, NT1, NT2, NT3, NT4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_sph_legendre<E1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (101) MultiArray<E1(NT1)> , NT2 , MultiArray<E3(NT3)>

template <class A, class C, class E1, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto sph_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, NT2, E3, E4, NT1, NT2, NT3, NT4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_sph_legendre<E1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (100) MultiArray<E1(NT1)> , NT2 , NT3

template <class A, class E1, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value&& NumberTrait<NT3>::value>>
auto sph_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    NT3,
    E1, NT2, NT3, E4, NT1, NT2, NT3, NT4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR_sph_legendre<E1, NT2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (011) NT1 , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class B, class C, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto sph_legendre(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, E2, E3, E4, NT1, NT2, NT3, NT4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_sph_legendre<NT1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// (010) NT1, MultiArray<E2(NT2)> , NT3

template <class B, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT3>::value>>
auto sph_legendre(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    NT1, E2, NT3, E4, NT1, NT2, NT3, NT4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_sph_legendre<NT1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (001) NT1 , NT2 , MultiArray<E3(NT3)>

template <class C, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT2>::value>>
auto sph_legendre(const NT1& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E3, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, NT2, E3, E4, NT1, NT2, NT3, NT4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_sph_legendre<NT1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// ----------------------------------------------------------------
// assoc_legendre
// template functions for 'assoc_legendre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functions.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// assoc_legendre (assoc_legendre)
//----------------------------------------------



// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



// (111) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class A, class B, class C, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank>
auto assoc_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, E2, E3, E4, NT1, NT2, NT3, NT4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_legendre<E1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}



// (110) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , NT3

template <class A, class B, class E1, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT3>::value>>
auto assoc_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    E1, E2, NT3, E4, NT1, NT2, NT3, NT4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_legendre<E1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (101) MultiArray<E1(NT1)> , NT2 , MultiArray<E3(NT3)>

template <class A, class C, class E1, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto assoc_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, NT2, E3, E4, NT1, NT2, NT3, NT4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_legendre<E1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (100) MultiArray<E1(NT1)> , NT2 , NT3

template <class A, class E1, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value&& NumberTrait<NT3>::value>>
auto assoc_legendre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    NT3,
    E1, NT2, NT3, E4, NT1, NT2, NT3, NT4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_legendre<E1, NT2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (011) NT1 , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class B, class C, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto assoc_legendre(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, E2, E3, E4, NT1, NT2, NT3, NT4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_legendre<NT1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// (010) NT1, MultiArray<E2(NT2)> , NT3

template <class B, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT3>::value>>
auto assoc_legendre(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    NT1, E2, NT3, E4, NT1, NT2, NT3, NT4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_legendre<NT1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (001) NT1 , NT2 , MultiArray<E3(NT3)>

template <class C, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT2>::value>>
auto assoc_legendre(const NT1& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E3, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, NT2, E3, E4, NT1, NT2, NT3, NT4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_legendre<NT1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// ----------------------------------------------------------------
// assoc_laguerre
// template functions for 'assoc_laguerre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functions.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// assoc_laguerre (assoc_laguerre)
//----------------------------------------------



// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



// (111) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class A, class B, class C, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank>
auto assoc_laguerre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, E2, E3, E4, NT1, NT2, NT3, NT4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_laguerre<E1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}



// (110) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , NT3

template <class A, class B, class E1, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT3>::value>>
auto assoc_laguerre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    E1, E2, NT3, E4, NT1, NT2, NT3, NT4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_laguerre<E1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (101) MultiArray<E1(NT1)> , NT2 , MultiArray<E3(NT3)>

template <class A, class C, class E1, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto assoc_laguerre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, NT2, E3, E4, NT1, NT2, NT3, NT4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_laguerre<E1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (100) MultiArray<E1(NT1)> , NT2 , NT3

template <class A, class E1, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value&& NumberTrait<NT3>::value>>
auto assoc_laguerre(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    NT3,
    E1, NT2, NT3, E4, NT1, NT2, NT3, NT4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_laguerre<E1, NT2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (011) NT1 , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class B, class C, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto assoc_laguerre(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, E2, E3, E4, NT1, NT2, NT3, NT4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_laguerre<NT1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// (010) NT1, MultiArray<E2(NT2)> , NT3

template <class B, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT3>::value>>
auto assoc_laguerre(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    NT1, E2, NT3, E4, NT1, NT2, NT3, NT4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_laguerre<NT1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (001) NT1 , NT2 , MultiArray<E3(NT3)>

template <class C, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT2>::value>>
auto assoc_laguerre(const NT1& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E3, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, NT2, E3, E4, NT1, NT2, NT3, NT4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_assoc_laguerre<NT1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// ----------------------------------------------------------------
// ellint_3
// template functions for 'ellint_3'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functions.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ellint_3 (ellint_3)
//----------------------------------------------



// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



// (111) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class A, class B, class C, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank>
auto ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, E2, E3, E4, NT1, NT2, NT3, NT4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_ellint_3<E1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}



// (110) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , NT3

template <class A, class B, class E1, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT3>::value>>
auto ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    E1, E2, NT3, E4, NT1, NT2, NT3, NT4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_ellint_3<E1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (101) MultiArray<E1(NT1)> , NT2 , MultiArray<E3(NT3)>

template <class A, class C, class E1, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, NT2, E3, E4, NT1, NT2, NT3, NT4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_ellint_3<E1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (100) MultiArray<E1(NT1)> , NT2 , NT3

template <class A, class E1, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value&& NumberTrait<NT3>::value>>
auto ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    NT3,
    E1, NT2, NT3, E4, NT1, NT2, NT3, NT4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR_ellint_3<E1, NT2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (011) NT1 , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class B, class C, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto ellint_3(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, E2, E3, E4, NT1, NT2, NT3, NT4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_ellint_3<NT1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// (010) NT1, MultiArray<E2(NT2)> , NT3

template <class B, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT3>::value>>
auto ellint_3(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    NT1, E2, NT3, E4, NT1, NT2, NT3, NT4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_ellint_3<NT1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (001) NT1 , NT2 , MultiArray<E3(NT3)>

template <class C, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT2>::value>>
auto ellint_3(const NT1& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E3, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, NT2, E3, E4, NT1, NT2, NT3, NT4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_ellint_3<NT1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// ----------------------------------------------------------------
// comp_ellint_3
// template functions for 'comp_ellint_3'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_ternary_functions.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// comp_ellint_3 (comp_ellint_3)
//----------------------------------------------



// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



// (111) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class A, class B, class C, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank>
auto comp_ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, E2, E3, E4, NT1, NT2, NT3, NT4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_comp_ellint_3<E1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}



// (110) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , NT3

template <class A, class B, class E1, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT3>::value>>
auto comp_ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    E1, E2, NT3, E4, NT1, NT2, NT3, NT4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_comp_ellint_3<E1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (101) MultiArray<E1(NT1)> , NT2 , MultiArray<E3(NT3)>

template <class A, class C, class E1, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto comp_ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, NT2, E3, E4, NT1, NT2, NT3, NT4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_comp_ellint_3<E1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (100) MultiArray<E1(NT1)> , NT2 , NT3

template <class A, class E1, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value&& NumberTrait<NT3>::value>>
auto comp_ellint_3(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    NT3,
    E1, NT2, NT3, E4, NT1, NT2, NT3, NT4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR_comp_ellint_3<E1, NT2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (011) NT1 , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class B, class C, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto comp_ellint_3(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, E2, E3, E4, NT1, NT2, NT3, NT4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_comp_ellint_3<NT1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// (010) NT1, MultiArray<E2(NT2)> , NT3

template <class B, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT3>::value>>
auto comp_ellint_3(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    NT1, E2, NT3, E4, NT1, NT2, NT3, NT4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_comp_ellint_3<NT1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (001) NT1 , NT2 , MultiArray<E3(NT3)>

template <class C, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT2>::value>>
auto comp_ellint_3(const NT1& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename MultType<typename MultType<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E3, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, NT2, E3, E4, NT1, NT2, NT3, NT4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_comp_ellint_3<NT1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}
}; // namespace mathq 
#endif // MATHQ__FUN_TERNARY_AUTO_H