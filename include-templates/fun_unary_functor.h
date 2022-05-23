
// ----------------------------------------------------------------
// ##FUNCTORNAME##: template class for function '##FUNCTION##'
//
//    Note: generated from template file '##MYFILENAME##'
//          using Python script '##SCRIPTNAME##'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_##FUNCTORNAME## {
public:
  typedef DIN DType;
  typedef DOUT DoutType;
  typedef E EType;
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {
    return ##FUNCTION##(d);
  }
  template <class T = E>
  static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
    apply(const E& e) {
    EOUT* e2 = new EOUT();
    *e2 = ##FUNCTION##(e);
    return *e2;
  }
  static std::string expression(const std::string& sa) {
    using namespace display;
    std::string sout = "";
    sout = functor_style.apply("##FUNCTION##")+"("+ sa + ")";
    return sout;
  }
  static std::string classname() {
    using namespace display;
    E e;
    return functor_namestyle.apply("FUNCTOR_##FUNCTORNAME##")+display::getBracketedTypeName(e);
  }
};

