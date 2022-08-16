

// ----------------------------------------------------------------
// __COMMENTNAME__
// template functions for '__NAME__'
//
//    Note: generated from template file '__MYFILENAME__'
//          using Python script '__SCRIPTNAME__'
// ----------------------------------------------------------------

//----------------------------------------------
// __COMMENTNAME__ 
//----------------------------------------------

template <class X, class Element, typename Num, size_t depth, size_t rank>
auto __FUNCTION__(const ExpressionR<X, Element, __DIN__, depth, rank>& x) {
  typedef typename ReplaceNumberTrait<Element, __DOUT__>::Type EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, __DIN__, depth, rank>, EOUT, __DOUT__, depth, rank, __FUNCTOR__<Element, EOUT, __DIN__, __DOUT__>>(x);
}
