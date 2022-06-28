#ifndef MATHQ__FUN_BINARY_AUTO_H
#define MATHQ__FUN_BINARY_AUTO_H 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT 'fun_binary.py'

namespace mathq { 



//********************************************************************
//--------------------------------------------------------------------
//                        Functors
//--------------------------------------------------------------------
//********************************************************************



// ----------------------------------------------------------------
// FUNCTOR_add: template class for operator '+'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_add {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 + d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 + e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 + d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 + e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" + "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_add));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_subtract: template class for operator '-'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_subtract {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 - d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 - e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 - d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 - e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" - "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_subtract));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_multiply: template class for operator '*'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_multiply {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 * d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 * e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 * d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 * e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" * "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_multiply));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_divide: template class for operator '/'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_divide {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 / d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 / e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 / d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 / e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" / "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_divide));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_equals: template class for operator '=='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_equals {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 == d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 == e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 == d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 == e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" == "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_equals));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_notequals: template class for operator '!='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_notequals {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 != d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 != e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 != d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 != e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" != "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_notequals));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_greater: template class for operator '>'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_greater {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 > d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 > e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 > d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 > e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" > "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_greater));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_greatereq: template class for operator '>='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_greatereq {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 >= d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 >= e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 >= d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 >= e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" >= "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_greatereq));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_less: template class for operator '<'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_less {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 < d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 < e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 < d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 < e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" < "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_less));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_lesseq: template class for operator '<='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_lesseq {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 <= d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 <= e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 <= d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 <= e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" <= "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_lesseq));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_and: template class for operator '&&'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_and {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 && d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 && e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 && d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 && e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" && "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_and));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_or: template class for operator '||'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_op_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_or {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return d1 || d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 || e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = e1 || d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 || e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" || "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_or));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_atan2: template class for function 'std::atan2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_atan2 {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::atan2(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::atan2(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::atan2(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::atan2(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_atan2));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_pow: template class for function 'std::pow'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_pow {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::pow(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::pow(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::pow(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::pow(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_pow));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_beta: template class for function 'std::beta'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_beta {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::beta(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::beta(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::beta(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::beta(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_beta));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_legendre: template class for function 'std::legendre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_legendre {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::legendre(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::legendre(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::legendre(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::legendre(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_legendre));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_laguerre: template class for function 'std::laguerre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_laguerre {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::laguerre(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::laguerre(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::laguerre(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::laguerre(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_laguerre));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_hermite: template class for function 'std::hermite'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_hermite {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::hermite(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::hermite(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::hermite(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::hermite(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_hermite));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_sph_bessel: template class for function 'std::sph_bessel'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_sph_bessel {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::sph_bessel(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::sph_bessel(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::sph_bessel(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::sph_bessel(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_sph_bessel));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_sph_neumann: template class for function 'std::sph_neumann'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_sph_neumann {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::sph_neumann(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::sph_neumann(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::sph_neumann(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::sph_neumann(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_sph_neumann));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_cyl_bessel_i: template class for function 'std::cyl_bessel_i'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_cyl_bessel_i {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::cyl_bessel_i(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_i(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_i(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_i(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_cyl_bessel_i));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_cyl_bessel_j: template class for function 'std::cyl_bessel_j'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_cyl_bessel_j {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::cyl_bessel_j(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_j(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_j(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_j(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_cyl_bessel_j));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_cyl_bessel_k: template class for function 'std::cyl_bessel_k'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_cyl_bessel_k {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::cyl_bessel_k(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_k(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_k(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_k(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_cyl_bessel_k));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_cyl_neumann: template class for function 'std::cyl_neumann'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_cyl_neumann {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::cyl_neumann(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_neumann(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_neumann(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_neumann(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_cyl_neumann));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_ellint_1: template class for function 'std::ellint_1'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_ellint_1 {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::ellint_1(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::ellint_1(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::ellint_1(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::ellint_1(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_ellint_1));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_ellint_2: template class for function 'std::ellint_2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_ellint_2 {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return std::ellint_2(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::ellint_2(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = std::ellint_2(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::ellint_2(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_ellint_2));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_Complex: template class for function 'mathq::Complex'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_Complex {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return mathq::Complex(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = mathq::Complex(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = mathq::Complex(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = mathq::Complex(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_Complex));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
    s += StyledString::get(BRACKET2).get();
    return s;
  }
};


// ----------------------------------------------------------------
// FUNCTOR_polar: template class for function 'mathq::polar'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functor.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_polar {
public:
  static D3 apply(const D1 d1, const D2 d2) {
    return mathq::polar(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = mathq::polar(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
    apply(const E1& e1, const D2 d2) {
    E3* e3 = new E3();
    *e3 = mathq::polar(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
    apply(const D1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = mathq::polar(d1, e2);
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" , "+ sb;
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E1 e1;
    E2 e2;
    E3 e3;
    D1 d1;
    D2 d2;
    D3 d3;
    std::string comma = StyledString::get(COMMA).get();
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_polar));
    s += StyledString::get(BRACKET1).get();
    s += getTypeName(e1);
    s += comma + getTypeName(e2);
    s += comma + getTypeName(e3);
    s += comma + getTypeName(d1);
    s += comma + getTypeName(d2);
    s += comma + getTypeName(d3);
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
// Addition
// template functions for '+'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Addition (+)
//----------------------------------------------

// (1) MultiArray<E1(D1)> + MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator+(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename AddType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_add<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> + D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator+(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename AddType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_add<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 + MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator+(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename AddType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_add<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Addition: x1[i] + x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator+(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename AddType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_add<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Addition: x1 + x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator+(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename AddType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_add<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> + MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator+(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename AddType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_add<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> + MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator+(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename AddType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_add<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Subtraction
// template functions for '-'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Subtraction (-)
//----------------------------------------------

// (1) MultiArray<E1(D1)> - MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator-(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename SubType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_subtract<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> - D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator-(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename SubType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_subtract<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 - MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator-(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename SubType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_subtract<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Subtraction: x1[i] - x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator-(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename SubType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_subtract<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Subtraction: x1 - x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator-(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename SubType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_subtract<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> - MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator-(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename SubType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_subtract<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> - MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator-(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename SubType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_subtract<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Multiplication
// template functions for '*'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Multiplication (*)
//----------------------------------------------

// (1) MultiArray<E1(D1)> * MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator*(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_multiply<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> * D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator*(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_multiply<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 * MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator*(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_multiply<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Multiplication: x1[i] * x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator*(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_multiply<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Multiplication: x1 * x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator*(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_multiply<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> * MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator*(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_multiply<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> * MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator*(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_multiply<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Division
// template functions for '/'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Division (/)
//----------------------------------------------

// (1) MultiArray<E1(D1)> / MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator/(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename DivType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_divide<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> / D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator/(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename DivType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_divide<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 / MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator/(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename DivType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_divide<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Division: x1[i] / x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator/(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename DivType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_divide<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Division: x1 / x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator/(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename DivType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_divide<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> / MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator/(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename DivType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_divide<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> / MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator/(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename DivType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_divide<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Equal to
// template functions for '=='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Equal to (==)
//----------------------------------------------

// (1) MultiArray<E1(D1)> == MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator==(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_equals<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> == D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator==(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_equals<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 == MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator==(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_equals<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Equal to: x1[i] == x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator==(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_equals<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Equal to: x1 == x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator==(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_equals<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> == MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator==(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_equals<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> == MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator==(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_equals<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Not equal to
// template functions for '!='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Not equal to (!=)
//----------------------------------------------

// (1) MultiArray<E1(D1)> != MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator!=(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_notequals<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> != D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator!=(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_notequals<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 != MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator!=(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_notequals<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Not equal to: x1[i] != x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator!=(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_notequals<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Not equal to: x1 != x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator!=(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_notequals<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> != MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Not equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator!=(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_notequals<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> != MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Not equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator!=(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_notequals<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Greater than
// template functions for '>'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Greater than (>)
//----------------------------------------------

// (1) MultiArray<E1(D1)> > MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator>(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_greater<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> > D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator>(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_greater<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 > MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator>(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_greater<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Greater than: x1[i] > x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator>(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_greater<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Greater than: x1 > x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator>(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_greater<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> > MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Greater than
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator>(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_greater<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> > MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Greater than
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator>(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_greater<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Greater than or equal to
// template functions for '>='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Greater than or equal to (>=)
//----------------------------------------------

// (1) MultiArray<E1(D1)> >= MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator>=(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_greatereq<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> >= D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator>=(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_greatereq<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 >= MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator>=(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_greatereq<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Greater than or equal to: x1[i] >= x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator>=(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_greatereq<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Greater than or equal to: x1 >= x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator>=(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_greatereq<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> >= MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Greater than or equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator>=(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_greatereq<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> >= MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Greater than or equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator>=(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_greatereq<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Less than
// template functions for '<'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Less than (<)
//----------------------------------------------

// (1) MultiArray<E1(D1)> < MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator<(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_less<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> < D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator<(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_less<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 < MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator<(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_less<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Less than: x1[i] < x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator<(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_less<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Less than: x1 < x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator<(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_less<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> < MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Less than
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator<(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_less<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> < MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Less than
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator<(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_less<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Less than or equal to
// template functions for '<='
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Less than or equal to (<=)
//----------------------------------------------

// (1) MultiArray<E1(D1)> <= MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator<=(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_lesseq<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> <= D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator<=(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_lesseq<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 <= MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator<=(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_lesseq<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Less than or equal to: x1[i] <= x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator<=(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_lesseq<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Less than or equal to: x1 <= x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator<=(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename RelType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_lesseq<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> <= MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Less than or equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator<=(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_lesseq<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> <= MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Less than or equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator<=(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename RelType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_lesseq<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// And
// template functions for '&&'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// And (&&)
//----------------------------------------------

// (1) MultiArray<E1(D1)> && MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator&&(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename AndType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_and<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> && D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator&&(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename AndType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_and<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 && MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator&&(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename AndType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_and<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise And: x1[i] && x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator&&(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename AndType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_and<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise And: x1 && x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator&&(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename AndType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_and<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> && MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise And
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator&&(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename AndType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_and<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> && MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise And
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator&&(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename AndType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_and<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Or
// template functions for '||'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Or (||)
//----------------------------------------------

// (1) MultiArray<E1(D1)> || MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto operator||(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename OrType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_or<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> || D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto operator||(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename OrType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_or<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 || MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto operator||(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename OrType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_or<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Or: x1[i] || x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto operator||(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename OrType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_or<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Or: x1 || x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto operator||(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename OrType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_or<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> || MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Or
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator||(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename OrType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_or<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> || MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Or
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator||(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename OrType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_or<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// atan2
// template functions for 'atan2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// atan2 (atan2)
//----------------------------------------------

// (1) MultiArray<E1(D1)> atan2 MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto atan2(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_atan2<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> atan2 D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto atan2(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_atan2<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 atan2 MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto atan2(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_atan2<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise atan2: x1[i] atan2 x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto atan2(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_atan2<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise atan2: x1 atan2 x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto atan2(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_atan2<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> atan2 MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise atan2
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto atan2(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_atan2<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> atan2 MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise atan2
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto atan2(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_atan2<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// pow
// template functions for 'pow'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// pow (pow)
//----------------------------------------------

// (1) MultiArray<E1(D1)> pow MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto pow(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_pow<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> pow D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto pow(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_pow<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 pow MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto pow(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_pow<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise pow: x1[i] pow x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto pow(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_pow<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise pow: x1 pow x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto pow(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_pow<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> pow MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise pow
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto pow(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_pow<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> pow MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise pow
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto pow(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_pow<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// beta
// template functions for 'beta'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// beta (beta)
//----------------------------------------------

// (1) MultiArray<E1(D1)> beta MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto beta(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_beta<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> beta D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto beta(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_beta<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 beta MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto beta(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_beta<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise beta: x1[i] beta x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto beta(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_beta<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise beta: x1 beta x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto beta(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_beta<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> beta MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise beta
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto beta(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_beta<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> beta MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise beta
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto beta(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_beta<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// legendre
// template functions for 'legendre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// legendre (legendre)
//----------------------------------------------

// (1) MultiArray<E1(D1)> legendre MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto legendre(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_legendre<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> legendre D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto legendre(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_legendre<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 legendre MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto legendre(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_legendre<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise legendre: x1[i] legendre x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto legendre(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_legendre<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise legendre: x1 legendre x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto legendre(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_legendre<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> legendre MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise legendre
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto legendre(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_legendre<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> legendre MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise legendre
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto legendre(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_legendre<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// laguerre
// template functions for 'laguerre'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// laguerre (laguerre)
//----------------------------------------------

// (1) MultiArray<E1(D1)> laguerre MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto laguerre(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_laguerre<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> laguerre D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto laguerre(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_laguerre<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 laguerre MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto laguerre(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_laguerre<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise laguerre: x1[i] laguerre x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto laguerre(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_laguerre<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise laguerre: x1 laguerre x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto laguerre(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_laguerre<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> laguerre MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise laguerre
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto laguerre(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_laguerre<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> laguerre MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise laguerre
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto laguerre(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_laguerre<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// hermite
// template functions for 'hermite'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// hermite (hermite)
//----------------------------------------------

// (1) MultiArray<E1(D1)> hermite MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto hermite(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_hermite<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> hermite D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto hermite(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_hermite<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 hermite MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto hermite(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_hermite<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise hermite: x1[i] hermite x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto hermite(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_hermite<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise hermite: x1 hermite x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto hermite(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_hermite<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> hermite MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise hermite
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto hermite(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_hermite<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> hermite MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise hermite
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto hermite(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_hermite<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// sph_bessel
// template functions for 'sph_bessel'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sph_bessel (sph_bessel)
//----------------------------------------------

// (1) MultiArray<E1(D1)> sph_bessel MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto sph_bessel(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_sph_bessel<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> sph_bessel D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto sph_bessel(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_sph_bessel<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 sph_bessel MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto sph_bessel(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_sph_bessel<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise sph_bessel: x1[i] sph_bessel x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto sph_bessel(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_sph_bessel<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise sph_bessel: x1 sph_bessel x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto sph_bessel(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_sph_bessel<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> sph_bessel MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise sph_bessel
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto sph_bessel(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_sph_bessel<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> sph_bessel MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise sph_bessel
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto sph_bessel(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_sph_bessel<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// sph_neumann
// template functions for 'sph_neumann'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sph_neumann (sph_neumann)
//----------------------------------------------

// (1) MultiArray<E1(D1)> sph_neumann MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto sph_neumann(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_sph_neumann<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> sph_neumann D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto sph_neumann(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_sph_neumann<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 sph_neumann MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto sph_neumann(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_sph_neumann<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise sph_neumann: x1[i] sph_neumann x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto sph_neumann(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_sph_neumann<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise sph_neumann: x1 sph_neumann x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto sph_neumann(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_sph_neumann<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> sph_neumann MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise sph_neumann
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto sph_neumann(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_sph_neumann<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> sph_neumann MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise sph_neumann
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto sph_neumann(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_sph_neumann<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// cyl_bessel_i
// template functions for 'cyl_bessel_i'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cyl_bessel_i (cyl_bessel_i)
//----------------------------------------------

// (1) MultiArray<E1(D1)> cyl_bessel_i MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto cyl_bessel_i(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_cyl_bessel_i<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> cyl_bessel_i D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto cyl_bessel_i(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_cyl_bessel_i<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 cyl_bessel_i MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto cyl_bessel_i(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_cyl_bessel_i<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise cyl_bessel_i: x1[i] cyl_bessel_i x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto cyl_bessel_i(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_bessel_i<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise cyl_bessel_i: x1 cyl_bessel_i x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto cyl_bessel_i(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_bessel_i<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> cyl_bessel_i MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_i
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_bessel_i(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_bessel_i<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> cyl_bessel_i MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_i
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_bessel_i(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_bessel_i<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// cyl_bessel_j
// template functions for 'cyl_bessel_j'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cyl_bessel_j (cyl_bessel_j)
//----------------------------------------------

// (1) MultiArray<E1(D1)> cyl_bessel_j MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto cyl_bessel_j(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_cyl_bessel_j<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> cyl_bessel_j D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto cyl_bessel_j(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_cyl_bessel_j<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 cyl_bessel_j MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto cyl_bessel_j(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_cyl_bessel_j<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise cyl_bessel_j: x1[i] cyl_bessel_j x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto cyl_bessel_j(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_bessel_j<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise cyl_bessel_j: x1 cyl_bessel_j x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto cyl_bessel_j(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_bessel_j<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> cyl_bessel_j MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_j
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_bessel_j(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_bessel_j<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> cyl_bessel_j MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_j
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_bessel_j(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_bessel_j<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// cyl_bessel_k
// template functions for 'cyl_bessel_k'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cyl_bessel_k (cyl_bessel_k)
//----------------------------------------------

// (1) MultiArray<E1(D1)> cyl_bessel_k MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto cyl_bessel_k(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_cyl_bessel_k<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> cyl_bessel_k D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto cyl_bessel_k(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_cyl_bessel_k<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 cyl_bessel_k MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto cyl_bessel_k(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_cyl_bessel_k<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise cyl_bessel_k: x1[i] cyl_bessel_k x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto cyl_bessel_k(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_bessel_k<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise cyl_bessel_k: x1 cyl_bessel_k x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto cyl_bessel_k(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_bessel_k<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> cyl_bessel_k MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_k
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_bessel_k(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_bessel_k<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> cyl_bessel_k MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_k
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_bessel_k(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_bessel_k<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// cyl_neumann
// template functions for 'cyl_neumann'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cyl_neumann (cyl_neumann)
//----------------------------------------------

// (1) MultiArray<E1(D1)> cyl_neumann MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto cyl_neumann(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_cyl_neumann<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> cyl_neumann D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto cyl_neumann(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_cyl_neumann<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 cyl_neumann MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto cyl_neumann(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_cyl_neumann<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise cyl_neumann: x1[i] cyl_neumann x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto cyl_neumann(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_neumann<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise cyl_neumann: x1 cyl_neumann x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto cyl_neumann(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_cyl_neumann<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> cyl_neumann MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_neumann
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_neumann(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_neumann<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> cyl_neumann MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise cyl_neumann
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_neumann(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_cyl_neumann<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// ellint_1
// template functions for 'ellint_1'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ellint_1 (ellint_1)
//----------------------------------------------

// (1) MultiArray<E1(D1)> ellint_1 MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto ellint_1(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_ellint_1<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> ellint_1 D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto ellint_1(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_ellint_1<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 ellint_1 MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto ellint_1(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_ellint_1<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise ellint_1: x1[i] ellint_1 x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto ellint_1(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_ellint_1<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise ellint_1: x1 ellint_1 x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto ellint_1(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_ellint_1<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> ellint_1 MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise ellint_1
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto ellint_1(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_ellint_1<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> ellint_1 MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise ellint_1
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto ellint_1(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_ellint_1<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// ellint_2
// template functions for 'ellint_2'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ellint_2 (ellint_2)
//----------------------------------------------

// (1) MultiArray<E1(D1)> ellint_2 MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto ellint_2(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_ellint_2<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> ellint_2 D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto ellint_2(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_ellint_2<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 ellint_2 MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto ellint_2(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_ellint_2<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise ellint_2: x1[i] ellint_2 x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto ellint_2(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_ellint_2<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise ellint_2: x1 ellint_2 x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto ellint_2(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename MultType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_ellint_2<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> ellint_2 MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise ellint_2
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto ellint_2(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_ellint_2<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> ellint_2 MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise ellint_2
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto ellint_2(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename MultType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_ellint_2<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// Complex
// template functions for 'Complex'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Complex (Complex)
//----------------------------------------------

// (1) MultiArray<E1(D1)> Complex MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto Complex(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_Complex<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> Complex D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto Complex(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_Complex<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 Complex MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto Complex(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_Complex<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise Complex: x1[i] Complex x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto Complex(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_Complex<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise Complex: x1 Complex x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto Complex(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_Complex<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> Complex MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Complex
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto Complex(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_Complex<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> Complex MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Complex
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto Complex(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_Complex<E1, E2, E3, D1, D2, D3> >(x1, x2);
}





// ----------------------------------------------------------------
// polar
// template functions for 'polar'
//
//    Note: generated from template file '/home/rs2015/Mathematiques/include-templates/fun_binary_functions.h'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// polar (polar)
//----------------------------------------------

// (1) MultiArray<E1(D1)> polar MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
auto polar(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, D1, M, R>,
    MArrayExpR<B, E2, D2, M, R>,
    E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
    FUNCTOR_polar<E1, E2, E3, D1, D2, D3> >(x1, x2);
}




// (2A) MultiArray<Element(D1)> polar D2

template <class A, class D2, class Element, class D1, int M, int R, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto polar(const MArrayExpR<A, Element, D1, M, R>& x1, const D2& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, D1, M, R>,
    D2,
    Element, D2, E3, D1, D2, D3, M, 0, M, R, R, R,
    FUNCTOR_polar<Element, D2, E3, D1, D2, D3> >(x1, x2);
}



// (2B) D1 polar MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int M, int R, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto polar(const D1& x1, const MArrayExpR<B, Element, D2, M, R>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  return  TER_Binary<D1,
    MArrayExpR<B, Element, D2, M, R>,
    D1, Element, E3, D1, D2, D3, 0, M, M, R, R, R,
    FUNCTOR_polar<D1, Element, E3, D1, D2, D3> >(x1, x2);
}



// (3A) element-wise polar: x1[i] polar x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1==M2+1)&&(IsMathqContainer<E1>::value)&&(E1::Rvalue==R2)> = 0 >
  auto polar(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_polar<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (3B) element-wise polar: x1 polar x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
  EnableIf<(M1+1==M2)&&(IsMathqContainer<E2>::value)&&(E2::Rvalue==R1)> = 0 >
  auto polar(const MArrayExpR<A, E1, D1, M1, R1>& x1, const MArrayExpR<B, E2, D2, M2, R2>& x2) {
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element, D3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R1>,
    MArrayExpR<B, E2, D2, M2, R2>,
    E1, E2, E3, D1, D2, D3, M1, M2, M3, R1, R2, R3,
    FUNCTOR_polar<Element, Element, E3, D1, D2, D3> >(x1, x2);
}


// (4A) MultiArray<D1,R,M> polar MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise polar
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1>=2)&&(M2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto polar(const MArrayExpR<A, E1, D1, M1, R>& x1, const MArrayExpR<B, D2, D2, M2, R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, D2, D2, M2, R> E2;

  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, D1, M1, R>,
    MArrayExpR<B, D2, D2, M2, R>,
    E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_polar<E1, E2, E3, D1, D2, D3> >(x1, x2);
}

// (4B) MultiArray<D1,R,1> polar MultiArray<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise polar
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  EnableIf<(M1==1)&&(M2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto polar(const MArrayExpR<A, D1, D1, M1, R>& x1, const MArrayExpR<B, E2, D2, M2, R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, D1, D1, M1, R> E1;
  typedef typename ComplexType<D1, D2>::Type D3;
  typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<MArrayExpR<A, D1, D1, M1, R>,
    MArrayExpR<B, E2, D2, M2, R>,
    D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
    FUNCTOR_polar<E1, E2, E3, D1, D2, D3> >(x1, x2);
}



}; // namespace mathq 
#endif // MATHQ__FUN_BINARY_AUTO_H