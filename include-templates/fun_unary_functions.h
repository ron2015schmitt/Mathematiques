

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

template <class X, class Element, typename Number, size_t depth, size_t rank>
auto ##FUNCTION##(const ExpressionR<X, Element, ##DIN##, depth, rank>& x) {
  typedef typename NumberTrait<Element, ##DOUT##>::ReplacedNumberType EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, ##DIN##, depth, rank>, EOUT, ##DOUT##, depth, rank, ##FUNCTOR##<Element, EOUT, ##DIN##, ##DOUT##>>(x);
}
