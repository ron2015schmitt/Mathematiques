

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

template <class X, class Element, class Number, int depth, int R, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto ##FUNCTION##(const MArrayExpR<X, Element, ##DIN##, depth, R>& x) {
  typedef typename NumberTrait<Element, ##DOUT##>::ReplaceTypeD EOUT;
  return  TER_Unary<MArrayExpR<X, Element, ##DIN##, depth, R>, EOUT, ##DOUT##, depth, R, ##FUNCTOR##<Element, EOUT, ##DIN##, ##DOUT##>>(x);
}
