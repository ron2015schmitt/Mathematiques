

// ----------------------------------------------------------------
// ##COMMENTNAME##
// template functions for '##NAME##'
//
//    Note: generated from template file '##MYFILENAME##'
//          using Python script '##SCRIPTNAME##'
// ----------------------------------------------------------------

//----------------------------------------------
// ##COMMENTNAME## 
//----------------------------------------------

template <class X, class Element, class D, int M, int R, typename = std::enable_if_t<std::is_arithmetic<D>::value>>
inline auto ##FUNCTION##(const MArrayExpR<X, Element, ##DIN##, M, R>& x) {
  typedef typename NumberTrait<Element, ##DOUT##>::ReplaceTypeD EOUT;
  return  TER_Unary<MArrayExpR<X, Element, ##DIN##, M, R>, EOUT, ##DOUT##, M, R, ##FUNCTOR##<Element, EOUT, ##DIN##, ##DOUT##>>(x);
}
