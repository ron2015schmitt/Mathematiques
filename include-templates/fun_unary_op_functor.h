
// ----------------------------------------------------------------
// __FUNCTORNAME__: template class for function '__FUNCTION__'
//
//    Note: generated from template file '__MYFILENAME__'
//          using Python script '__SCRIPTNAME__'
// ----------------------------------------------------------------

template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR___FUNCTORNAME__ {
public:
  typedef DIN NumberType;
  typedef DOUT DoutType;
  typedef Element ElementType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return __FUNCTION__(d);
  }
  template <class T = Element>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const Element& e) {
    EOUT* e2 = new EOUT();
    *e2 = __FUNCTION__(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("__FUNCTION__")+"("+ sa + ")";
    return sout;
  }
  inline const std::string expression_name() const {
    using namespace display;
    Element e;
    return functor_namestyle.apply("FUNCTOR___FUNCTORNAME__")+display::bracketAndStyleTypename(e);
  }
};

