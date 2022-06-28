
// ----------------------------------------------------------------
// FUNCTOR_##NAME##: template class for operator '##OP##'
//
//    Note: generated from template file '##MYFILENAME##'
//          using Python script '##SCRIPTNAME##'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_##NAME## {
public:
  static NT3 apply(const NT1 d1, const NT2 d2) {
    return d1 ##OP## d2;
  }
  template <class T1 = E1, class T2 = E2>
  static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
    apply(const E1& e1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = e1 ##OP## e2;
    return *e3;
  }
  template <class T1 = E1>
  static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
    apply(const E1& e1, const NT2 d2) {
    E3* e3 = new E3();
    *e3 = e1 ##OP## d2;
    return *e3;
  }
  template <class T2 = E2>
  static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
    apply(const NT1 d1, const E2& e2) {
    E3* e3 = new E3();
    *e3 = d1 ##OP## e2;
    return *e3;
  }
  static std::string expression(const std::string& sa, const std::string& sb) {
    using namespace display;
    std::string sout = "";
    sout = sa +" ##OP## "+ sb;
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
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_##NAME##));
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

