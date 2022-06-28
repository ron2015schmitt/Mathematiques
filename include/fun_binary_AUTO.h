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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_add {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 + d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 + e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 + d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_subtract {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 - d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 - e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 - d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_multiply {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 * d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 * e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 * d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_divide {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 / d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 / e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 / d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_equals {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 == d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 == e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 == d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_notequals {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 != d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 != e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 != d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_greater {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 > d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 > e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 > d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_greatereq {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 >= d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 >= e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 >= d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_less {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 < d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 < e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 < d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_lesseq {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 <= d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 <= e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 <= d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_and {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 && d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 && e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 && d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_or {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 || d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 || e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 || d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_atan2 {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::atan2(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::atan2(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::atan2(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_pow {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::pow(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::pow(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::pow(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_beta {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::beta(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::beta(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::beta(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_legendre {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::legendre(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::legendre(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::legendre(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_laguerre {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::laguerre(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::laguerre(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::laguerre(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_hermite {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::hermite(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::hermite(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::hermite(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_sph_bessel {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::sph_bessel(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::sph_bessel(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::sph_bessel(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_sph_neumann {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::sph_neumann(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::sph_neumann(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::sph_neumann(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_cyl_bessel_i {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::cyl_bessel_i(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_i(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_i(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_cyl_bessel_j {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::cyl_bessel_j(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_j(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_j(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_cyl_bessel_k {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::cyl_bessel_k(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_k(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_bessel_k(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_cyl_neumann {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::cyl_neumann(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::cyl_neumann(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::cyl_neumann(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_ellint_1 {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::ellint_1(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::ellint_1(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::ellint_1(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_ellint_2 {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return std::ellint_2(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = std::ellint_2(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = std::ellint_2(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_Complex {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return mathq::Complex(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = mathq::Complex(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = mathq::Complex(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_polar {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return mathq::polar(d1, d2);
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = mathq::polar(e1, e2);
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = mathq::polar(e1, d2);
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
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
    NT1 d1;
    NT2 d2;
    NT3 d3;
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

// (1) MultiArray<E1(NT1)> + MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator+(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename AddType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_add<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> + NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator+(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename AddType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_add<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 + MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator+(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename AddType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_add<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Addition: x1[i] + x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator+(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename AddType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_add<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Addition: x1 + x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator+(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename AddType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_add<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> + MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator+(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename AddType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_add<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> + MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator+(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename AddType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_add<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> - MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator-(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename SubType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_subtract<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> - NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator-(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename SubType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_subtract<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 - MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator-(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename SubType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_subtract<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Subtraction: x1[i] - x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator-(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename SubType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_subtract<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Subtraction: x1 - x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator-(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename SubType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_subtract<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> - MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator-(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename SubType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_subtract<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> - MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator-(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename SubType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_subtract<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> * MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator*(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_multiply<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> * NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator*(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_multiply<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 * MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator*(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_multiply<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Multiplication: x1[i] * x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator*(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_multiply<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Multiplication: x1 * x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator*(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_multiply<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> * MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator*(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_multiply<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> * MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator*(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_multiply<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> / MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator/(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename DivType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_divide<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> / NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator/(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename DivType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_divide<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 / MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator/(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename DivType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_divide<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Division: x1[i] / x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator/(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename DivType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_divide<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Division: x1 / x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator/(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename DivType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_divide<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> / MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator/(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename DivType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_divide<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> / MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator/(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename DivType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_divide<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> == MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator==(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_equals<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> == NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator==(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_equals<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 == MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator==(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_equals<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Equal to: x1[i] == x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator==(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_equals<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Equal to: x1 == x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator==(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_equals<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> == MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Equal to
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator==(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_equals<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> == MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Equal to
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator==(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_equals<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> != MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator!=(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_notequals<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> != NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator!=(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_notequals<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 != MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator!=(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_notequals<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Not equal to: x1[i] != x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator!=(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_notequals<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Not equal to: x1 != x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator!=(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_notequals<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> != MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Not equal to
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator!=(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_notequals<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> != MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Not equal to
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator!=(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_notequals<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> > MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator>(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_greater<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> > NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator>(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_greater<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 > MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator>(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_greater<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Greater than: x1[i] > x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator>(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_greater<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Greater than: x1 > x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator>(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_greater<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> > MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Greater than
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator>(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_greater<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> > MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Greater than
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator>(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_greater<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> >= MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator>=(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_greatereq<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> >= NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator>=(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_greatereq<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 >= MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator>=(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_greatereq<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Greater than or equal to: x1[i] >= x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator>=(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_greatereq<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Greater than or equal to: x1 >= x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator>=(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_greatereq<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> >= MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Greater than or equal to
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator>=(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_greatereq<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> >= MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Greater than or equal to
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator>=(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_greatereq<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> < MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator<(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_less<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> < NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator<(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_less<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 < MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator<(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_less<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Less than: x1[i] < x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator<(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_less<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Less than: x1 < x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator<(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_less<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> < MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Less than
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator<(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_less<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> < MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Less than
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator<(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_less<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> <= MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator<=(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_lesseq<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> <= NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator<=(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_lesseq<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 <= MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator<=(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_lesseq<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Less than or equal to: x1[i] <= x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator<=(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_lesseq<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Less than or equal to: x1 <= x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator<=(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_lesseq<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> <= MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Less than or equal to
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator<=(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_lesseq<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> <= MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Less than or equal to
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator<=(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename RelType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_lesseq<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> && MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator&&(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename AndType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_and<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> && NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator&&(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename AndType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_and<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 && MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator&&(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename AndType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_and<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise And: x1[i] && x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator&&(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename AndType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_and<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise And: x1 && x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator&&(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename AndType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_and<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> && MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise And
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator&&(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename AndType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_and<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> && MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise And
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator&&(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename AndType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_and<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> || MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto operator||(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename OrType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_or<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> || NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto operator||(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename OrType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_or<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 || MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto operator||(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename OrType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_or<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Or: x1[i] || x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto operator||(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename OrType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_or<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Or: x1 || x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto operator||(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename OrType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_or<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> || MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Or
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto operator||(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename OrType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_or<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> || MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Or
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto operator||(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename OrType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_or<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> atan2 MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto atan2(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_atan2<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> atan2 NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto atan2(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_atan2<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 atan2 MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto atan2(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_atan2<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise atan2: x1[i] atan2 x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto atan2(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_atan2<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise atan2: x1 atan2 x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto atan2(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_atan2<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> atan2 MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise atan2
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto atan2(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_atan2<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> atan2 MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise atan2
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto atan2(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_atan2<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> pow MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto pow(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_pow<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> pow NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto pow(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_pow<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 pow MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto pow(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_pow<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise pow: x1[i] pow x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto pow(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_pow<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise pow: x1 pow x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto pow(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_pow<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> pow MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise pow
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto pow(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_pow<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> pow MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise pow
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto pow(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_pow<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> beta MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto beta(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_beta<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> beta NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto beta(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_beta<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 beta MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto beta(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_beta<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise beta: x1[i] beta x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto beta(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_beta<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise beta: x1 beta x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto beta(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_beta<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> beta MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise beta
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto beta(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_beta<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> beta MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise beta
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto beta(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_beta<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> legendre MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto legendre(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_legendre<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> legendre NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto legendre(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_legendre<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 legendre MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto legendre(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_legendre<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise legendre: x1[i] legendre x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto legendre(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_legendre<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise legendre: x1 legendre x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto legendre(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_legendre<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> legendre MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise legendre
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto legendre(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_legendre<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> legendre MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise legendre
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto legendre(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_legendre<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> laguerre MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto laguerre(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_laguerre<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> laguerre NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto laguerre(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_laguerre<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 laguerre MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto laguerre(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_laguerre<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise laguerre: x1[i] laguerre x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto laguerre(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_laguerre<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise laguerre: x1 laguerre x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto laguerre(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_laguerre<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> laguerre MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise laguerre
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto laguerre(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_laguerre<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> laguerre MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise laguerre
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto laguerre(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_laguerre<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> hermite MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto hermite(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_hermite<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> hermite NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto hermite(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_hermite<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 hermite MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto hermite(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_hermite<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise hermite: x1[i] hermite x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto hermite(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_hermite<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise hermite: x1 hermite x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto hermite(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_hermite<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> hermite MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise hermite
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto hermite(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_hermite<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> hermite MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise hermite
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto hermite(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_hermite<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> sph_bessel MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto sph_bessel(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_sph_bessel<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> sph_bessel NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto sph_bessel(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_sph_bessel<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 sph_bessel MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto sph_bessel(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_sph_bessel<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise sph_bessel: x1[i] sph_bessel x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto sph_bessel(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_sph_bessel<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise sph_bessel: x1 sph_bessel x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto sph_bessel(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_sph_bessel<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> sph_bessel MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise sph_bessel
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto sph_bessel(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_sph_bessel<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> sph_bessel MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise sph_bessel
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto sph_bessel(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_sph_bessel<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> sph_neumann MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto sph_neumann(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_sph_neumann<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> sph_neumann NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto sph_neumann(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_sph_neumann<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 sph_neumann MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto sph_neumann(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_sph_neumann<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise sph_neumann: x1[i] sph_neumann x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto sph_neumann(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_sph_neumann<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise sph_neumann: x1 sph_neumann x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto sph_neumann(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_sph_neumann<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> sph_neumann MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise sph_neumann
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto sph_neumann(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_sph_neumann<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> sph_neumann MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise sph_neumann
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto sph_neumann(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_sph_neumann<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> cyl_bessel_i MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto cyl_bessel_i(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_i<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> cyl_bessel_i NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto cyl_bessel_i(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_i<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 cyl_bessel_i MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto cyl_bessel_i(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_i<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise cyl_bessel_i: x1[i] cyl_bessel_i x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto cyl_bessel_i(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_bessel_i<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise cyl_bessel_i: x1 cyl_bessel_i x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto cyl_bessel_i(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_bessel_i<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> cyl_bessel_i MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_i
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_bessel_i(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_bessel_i<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> cyl_bessel_i MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_i
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_bessel_i(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_bessel_i<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> cyl_bessel_j MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto cyl_bessel_j(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_j<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> cyl_bessel_j NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto cyl_bessel_j(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_j<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 cyl_bessel_j MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto cyl_bessel_j(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_j<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise cyl_bessel_j: x1[i] cyl_bessel_j x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto cyl_bessel_j(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_bessel_j<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise cyl_bessel_j: x1 cyl_bessel_j x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto cyl_bessel_j(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_bessel_j<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> cyl_bessel_j MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_j
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_bessel_j(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_bessel_j<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> cyl_bessel_j MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_j
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_bessel_j(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_bessel_j<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> cyl_bessel_k MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto cyl_bessel_k(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_k<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> cyl_bessel_k NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto cyl_bessel_k(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_k<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 cyl_bessel_k MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto cyl_bessel_k(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_bessel_k<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise cyl_bessel_k: x1[i] cyl_bessel_k x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto cyl_bessel_k(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_bessel_k<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise cyl_bessel_k: x1 cyl_bessel_k x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto cyl_bessel_k(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_bessel_k<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> cyl_bessel_k MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_k
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_bessel_k(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_bessel_k<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> cyl_bessel_k MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise cyl_bessel_k
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_bessel_k(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_bessel_k<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> cyl_neumann MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto cyl_neumann(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_neumann<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> cyl_neumann NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto cyl_neumann(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_cyl_neumann<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 cyl_neumann MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto cyl_neumann(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_cyl_neumann<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise cyl_neumann: x1[i] cyl_neumann x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto cyl_neumann(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_neumann<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise cyl_neumann: x1 cyl_neumann x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto cyl_neumann(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_cyl_neumann<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> cyl_neumann MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise cyl_neumann
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto cyl_neumann(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_neumann<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> cyl_neumann MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise cyl_neumann
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto cyl_neumann(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_cyl_neumann<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> ellint_1 MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto ellint_1(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_ellint_1<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> ellint_1 NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto ellint_1(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_ellint_1<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 ellint_1 MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto ellint_1(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_ellint_1<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise ellint_1: x1[i] ellint_1 x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto ellint_1(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_ellint_1<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise ellint_1: x1 ellint_1 x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto ellint_1(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_ellint_1<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> ellint_1 MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise ellint_1
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto ellint_1(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_ellint_1<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> ellint_1 MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise ellint_1
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto ellint_1(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_ellint_1<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> ellint_2 MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto ellint_2(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_ellint_2<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> ellint_2 NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto ellint_2(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_ellint_2<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 ellint_2 MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto ellint_2(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_ellint_2<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise ellint_2: x1[i] ellint_2 x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto ellint_2(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_ellint_2<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise ellint_2: x1 ellint_2 x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto ellint_2(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_ellint_2<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> ellint_2 MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise ellint_2
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto ellint_2(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_ellint_2<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> ellint_2 MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise ellint_2
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto ellint_2(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename MultType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_ellint_2<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> Complex MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto Complex(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_Complex<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> Complex NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto Complex(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_Complex<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 Complex MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto Complex(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_Complex<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise Complex: x1[i] Complex x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto Complex(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_Complex<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise Complex: x1 Complex x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto Complex(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_Complex<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> Complex MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise Complex
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto Complex(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_Complex<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> Complex MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise Complex
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto Complex(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_Complex<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
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

// (1) MultiArray<E1(NT1)> polar MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
auto polar(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_polar<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> polar NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto polar(const MArrayExpR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<MArrayExpR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_polar<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 polar MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto polar(const NT1& x1, const MArrayExpR<B, Element, NT2, depth, rank>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  return  TER_Binary<NT1,
    MArrayExpR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_polar<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise polar: x1[i] polar x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1==D2+1)&&(IsMathqContainer<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto polar(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_polar<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise polar: x1 polar x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
  EnableIf<(D1+1==D2)&&(IsMathqContainer<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto polar(const MArrayExpR<A, E1, NT1, D1, R1>& x1, const MArrayExpR<B, E2, NT2, D2, R2>& x2) {
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplaceTypeD E3;
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, R1>,
    MArrayExpR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_polar<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> polar MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise polar
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMathqContainer<E1>::value)> = 0  >
  auto polar(const MArrayExpR<A, E1, NT1, D1, rank>& x1, const MArrayExpR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B, NT2, NT2, D2, rank> E2;

  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A, E1, NT1, D1, rank>,
    MArrayExpR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_polar<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> polar MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise polar
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMathqContainer<E2>::value)> = 0  >
  auto polar(const MArrayExpR<A, NT1, NT1, D1, rank>& x1, const MArrayExpR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A, NT1, NT1, D1, rank> E1;
  typedef typename ComplexType<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplaceTypeD E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A, NT1, NT1, D1, rank>,
    MArrayExpR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_polar<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}



}; // namespace mathq 
#endif // MATHQ__FUN_BINARY_AUTO_H