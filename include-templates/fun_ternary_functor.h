
// ----------------------------------------------------------------
// FUNCTOR_##NAME##: template class for function '##FUNCTION##'
//
//    Note: generated from template file '##MYFILENAME##'
//          using Python script '##SCRIPTNAME##'
// ----------------------------------------------------------------


template <class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4> class FUNCTOR_##NAME## {
public:
  static D4 apply(const D1 d1, const D2 d2, const D3 d3) {
    return ##FUNCTION##(d1, d2, d3);
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = ##FUNCTION##(e1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = ##FUNCTION##(e1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = ##FUNCTION##(e1, d2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<!std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const E1& e1, const D2 d2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = ##FUNCTION##(e1, d2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = ##FUNCTION##(d1, e2, e3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value&& std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const E2& e2, const D3 d3) {
    E4* e4 = new E4();
    *e4 = ##FUNCTION##(d1, e2, d3);
    return *e4;
  }
  template <class T1 = E1, class T2 = E2, class T3 = E3>
  static typename std::enable_if<std::is_same<T1, D1>::value&& std::is_same<T2, D2>::value&&!std::is_same<T3, D3>::value, E4& >::type
    apply(const D1 d1, const D2 d2, const E3& e3) {
    E4* e4 = new E4();
    *e4 = ##FUNCTION##(d1, d2, e3);
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
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_##NAME##));
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

