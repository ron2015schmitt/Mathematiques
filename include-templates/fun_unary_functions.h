

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

template <class X, class Element, typename Number, int depth, int rank>
auto ##FUNCTION##(const MArrayExpR<X, Element, ##DIN##, depth, rank>& x) {
  typedef typename NumberTrait<Element, ##DOUT##>::ReplacedNumberType EOUT;
  return  TER_Unary<MArrayExpR<X, Element, ##DIN##, depth, rank>, EOUT, ##DOUT##, depth, rank, ##FUNCTOR##<Element, EOUT, ##DIN##, ##DOUT##>>(x);
}
