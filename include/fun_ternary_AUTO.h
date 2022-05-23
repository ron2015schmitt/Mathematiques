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


template <class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4> class FUNCTOR_sph_legendre {
public:
  static D4 apply(const D1 d1, const D2 d2, const D3 d3) {
    return std::sph_legendre(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::sph_legendre(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const D2 d2, const E3& e3) {
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
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
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


template <class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4> class FUNCTOR_assoc_legendre {
public:
  static D4 apply(const D1 d1, const D2 d2, const D3 d3) {
    return std::assoc_legendre(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_legendre(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const D2 d2, const E3& e3) {
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
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
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


template <class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4> class FUNCTOR_assoc_laguerre {
public:
  static D4 apply(const D1 d1, const D2 d2, const D3 d3) {
    return std::assoc_laguerre(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::assoc_laguerre(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const D2 d2, const E3& e3) {
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
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
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


template <class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4> class FUNCTOR_ellint_3 {
public:
  static D4 apply(const D1 d1, const D2 d2, const D3 d3) {
    return std::ellint_3(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::ellint_3(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const D2 d2, const E3& e3) {
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
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
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


template <class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4> class FUNCTOR_comp_ellint_3 {
public:
  static D4 apply(const D1 d1, const D2 d2, const D3 d3) {
    return std::comp_ellint_3(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = std::comp_ellint_3(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const D2 d2, const E3& e3) {
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
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
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



// (111) Tensor<E1(D1)> , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class D1, class D2, class D3, int M, int R>
auto sph_legendre(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    E1, E2, E3, E4, D1, D2, D3, D4, M, M, M, M, R, R, R, R,
    FUNCTOR_sph_legendre<E1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}



// (110) Tensor<E1(D1)> , Tensor<E2(D2)> , D3

template <class A, class B, class E1, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D3>::value>>
auto sph_legendre(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    D3,
    E1, E2, D3, E4, D1, D2, D3, D4, M, M, 0, M, R, R, R, R,
    FUNCTOR_sph_legendre<E1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (101) Tensor<E1(D1)> , D2 , Tensor<E3(D3)>

template <class A, class C, class E1, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>>
auto sph_legendre(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    TensorR<C, E3, D3, M, R>,
    E1, D2, E3, E4, D1, D2, D3, D4, M, 0, M, M, R, R, R, R,
    FUNCTOR_sph_legendre<E1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (100) Tensor<E1(D1)> , D2 , D3

template <class A, class E1, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value&& NumberType<D3>::value>>
auto sph_legendre(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    D3,
    E1, D2, D3, E4, D1, D2, D3, D4, M, 0, 0, M, R, R, R, R,
    FUNCTOR_sph_legendre<E1, D2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (011) D1 , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class B, class C, class E2, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>>
auto sph_legendre(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    D1, E2, E3, E4, D1, D2, D3, D4, 0, M, M, M, R, R, R, R,
    FUNCTOR_sph_legendre<D1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}


// (010) D1, Tensor<E2(D2)> , D3

template <class B, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D3>::value>>
auto sph_legendre(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    D3,
    D1, E2, D3, E4, D1, D2, D3, D4, 0, M, 0, M, R, R, R, R,
    FUNCTOR_sph_legendre<D1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (001) D1 , D2 , Tensor<E3(D3)>

template <class C, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D2>::value>>
auto sph_legendre(const D1& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    D2,
    TensorR<C, E3, D3, M, R>,
    D1, D2, E3, E4, D1, D2, D3, D4, 0, 0, M, M, R, R, R, R,
    FUNCTOR_sph_legendre<D1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
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



// (111) Tensor<E1(D1)> , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class D1, class D2, class D3, int M, int R>
auto assoc_legendre(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    E1, E2, E3, E4, D1, D2, D3, D4, M, M, M, M, R, R, R, R,
    FUNCTOR_assoc_legendre<E1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}



// (110) Tensor<E1(D1)> , Tensor<E2(D2)> , D3

template <class A, class B, class E1, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D3>::value>>
auto assoc_legendre(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    D3,
    E1, E2, D3, E4, D1, D2, D3, D4, M, M, 0, M, R, R, R, R,
    FUNCTOR_assoc_legendre<E1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (101) Tensor<E1(D1)> , D2 , Tensor<E3(D3)>

template <class A, class C, class E1, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>>
auto assoc_legendre(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    TensorR<C, E3, D3, M, R>,
    E1, D2, E3, E4, D1, D2, D3, D4, M, 0, M, M, R, R, R, R,
    FUNCTOR_assoc_legendre<E1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (100) Tensor<E1(D1)> , D2 , D3

template <class A, class E1, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value&& NumberType<D3>::value>>
auto assoc_legendre(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    D3,
    E1, D2, D3, E4, D1, D2, D3, D4, M, 0, 0, M, R, R, R, R,
    FUNCTOR_assoc_legendre<E1, D2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (011) D1 , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class B, class C, class E2, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>>
auto assoc_legendre(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    D1, E2, E3, E4, D1, D2, D3, D4, 0, M, M, M, R, R, R, R,
    FUNCTOR_assoc_legendre<D1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}


// (010) D1, Tensor<E2(D2)> , D3

template <class B, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D3>::value>>
auto assoc_legendre(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    D3,
    D1, E2, D3, E4, D1, D2, D3, D4, 0, M, 0, M, R, R, R, R,
    FUNCTOR_assoc_legendre<D1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (001) D1 , D2 , Tensor<E3(D3)>

template <class C, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D2>::value>>
auto assoc_legendre(const D1& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    D2,
    TensorR<C, E3, D3, M, R>,
    D1, D2, E3, E4, D1, D2, D3, D4, 0, 0, M, M, R, R, R, R,
    FUNCTOR_assoc_legendre<D1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
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



// (111) Tensor<E1(D1)> , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class D1, class D2, class D3, int M, int R>
auto assoc_laguerre(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    E1, E2, E3, E4, D1, D2, D3, D4, M, M, M, M, R, R, R, R,
    FUNCTOR_assoc_laguerre<E1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}



// (110) Tensor<E1(D1)> , Tensor<E2(D2)> , D3

template <class A, class B, class E1, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D3>::value>>
auto assoc_laguerre(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    D3,
    E1, E2, D3, E4, D1, D2, D3, D4, M, M, 0, M, R, R, R, R,
    FUNCTOR_assoc_laguerre<E1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (101) Tensor<E1(D1)> , D2 , Tensor<E3(D3)>

template <class A, class C, class E1, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>>
auto assoc_laguerre(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    TensorR<C, E3, D3, M, R>,
    E1, D2, E3, E4, D1, D2, D3, D4, M, 0, M, M, R, R, R, R,
    FUNCTOR_assoc_laguerre<E1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (100) Tensor<E1(D1)> , D2 , D3

template <class A, class E1, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value&& NumberType<D3>::value>>
auto assoc_laguerre(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    D3,
    E1, D2, D3, E4, D1, D2, D3, D4, M, 0, 0, M, R, R, R, R,
    FUNCTOR_assoc_laguerre<E1, D2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (011) D1 , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class B, class C, class E2, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>>
auto assoc_laguerre(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    D1, E2, E3, E4, D1, D2, D3, D4, 0, M, M, M, R, R, R, R,
    FUNCTOR_assoc_laguerre<D1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}


// (010) D1, Tensor<E2(D2)> , D3

template <class B, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D3>::value>>
auto assoc_laguerre(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    D3,
    D1, E2, D3, E4, D1, D2, D3, D4, 0, M, 0, M, R, R, R, R,
    FUNCTOR_assoc_laguerre<D1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (001) D1 , D2 , Tensor<E3(D3)>

template <class C, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D2>::value>>
auto assoc_laguerre(const D1& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    D2,
    TensorR<C, E3, D3, M, R>,
    D1, D2, E3, E4, D1, D2, D3, D4, 0, 0, M, M, R, R, R, R,
    FUNCTOR_assoc_laguerre<D1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
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



// (111) Tensor<E1(D1)> , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class D1, class D2, class D3, int M, int R>
auto ellint_3(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    E1, E2, E3, E4, D1, D2, D3, D4, M, M, M, M, R, R, R, R,
    FUNCTOR_ellint_3<E1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}



// (110) Tensor<E1(D1)> , Tensor<E2(D2)> , D3

template <class A, class B, class E1, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D3>::value>>
auto ellint_3(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    D3,
    E1, E2, D3, E4, D1, D2, D3, D4, M, M, 0, M, R, R, R, R,
    FUNCTOR_ellint_3<E1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (101) Tensor<E1(D1)> , D2 , Tensor<E3(D3)>

template <class A, class C, class E1, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>>
auto ellint_3(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    TensorR<C, E3, D3, M, R>,
    E1, D2, E3, E4, D1, D2, D3, D4, M, 0, M, M, R, R, R, R,
    FUNCTOR_ellint_3<E1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (100) Tensor<E1(D1)> , D2 , D3

template <class A, class E1, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value&& NumberType<D3>::value>>
auto ellint_3(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    D3,
    E1, D2, D3, E4, D1, D2, D3, D4, M, 0, 0, M, R, R, R, R,
    FUNCTOR_ellint_3<E1, D2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (011) D1 , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class B, class C, class E2, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>>
auto ellint_3(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    D1, E2, E3, E4, D1, D2, D3, D4, 0, M, M, M, R, R, R, R,
    FUNCTOR_ellint_3<D1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}


// (010) D1, Tensor<E2(D2)> , D3

template <class B, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D3>::value>>
auto ellint_3(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    D3,
    D1, E2, D3, E4, D1, D2, D3, D4, 0, M, 0, M, R, R, R, R,
    FUNCTOR_ellint_3<D1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (001) D1 , D2 , Tensor<E3(D3)>

template <class C, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D2>::value>>
auto ellint_3(const D1& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    D2,
    TensorR<C, E3, D3, M, R>,
    D1, D2, E3, E4, D1, D2, D3, D4, 0, 0, M, M, R, R, R, R,
    FUNCTOR_ellint_3<D1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
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



// (111) Tensor<E1(D1)> , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class D1, class D2, class D3, int M, int R>
auto comp_ellint_3(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    E1, E2, E3, E4, D1, D2, D3, D4, M, M, M, M, R, R, R, R,
    FUNCTOR_comp_ellint_3<E1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}



// (110) Tensor<E1(D1)> , Tensor<E2(D2)> , D3

template <class A, class B, class E1, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D3>::value>>
auto comp_ellint_3(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    D3,
    E1, E2, D3, E4, D1, D2, D3, D4, M, M, 0, M, R, R, R, R,
    FUNCTOR_comp_ellint_3<E1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (101) Tensor<E1(D1)> , D2 , Tensor<E3(D3)>

template <class A, class C, class E1, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>>
auto comp_ellint_3(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    TensorR<C, E3, D3, M, R>,
    E1, D2, E3, E4, D1, D2, D3, D4, M, 0, M, M, R, R, R, R,
    FUNCTOR_comp_ellint_3<E1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (100) Tensor<E1(D1)> , D2 , D3

template <class A, class E1, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value&& NumberType<D3>::value>>
auto comp_ellint_3(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    D3,
    E1, D2, D3, E4, D1, D2, D3, D4, M, 0, 0, M, R, R, R, R,
    FUNCTOR_comp_ellint_3<E1, D2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (011) D1 , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class B, class C, class E2, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>>
auto comp_ellint_3(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    D1, E2, E3, E4, D1, D2, D3, D4, 0, M, M, M, R, R, R, R,
    FUNCTOR_comp_ellint_3<D1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}


// (010) D1, Tensor<E2(D2)> , D3

template <class B, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D3>::value>>
auto comp_ellint_3(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    D3,
    D1, E2, D3, E4, D1, D2, D3, D4, 0, M, 0, M, R, R, R, R,
    FUNCTOR_comp_ellint_3<D1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (001) D1 , D2 , Tensor<E3(D3)>

template <class C, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D2>::value>>
auto comp_ellint_3(const D1& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename MultType<typename MultType<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    D2,
    TensorR<C, E3, D3, M, R>,
    D1, D2, E3, E4, D1, D2, D3, D4, 0, 0, M, M, R, R, R, R,
    FUNCTOR_comp_ellint_3<D1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}
}; // namespace mathq 
#endif // MATHQ__FUN_TERNARY_AUTO_H