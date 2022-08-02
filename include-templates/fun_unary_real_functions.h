

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

template <class X, class Element, typename Number, size_t depth, size_t rank, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
inline auto __FUNCTION__(const ExpressionR<X, Element, __DIN__, depth, rank>& x) {
  typedef typename NumberTrait<Element, __DOUT__>::ReplacedNumberType EOUT;
  return  ExpressionR_Unary<ExpressionR<X, Element, __DIN__, depth, rank>, EOUT, __DOUT__, depth, rank, __FUNCTOR__<Element, EOUT, __DIN__, __DOUT__>>(x);
}
