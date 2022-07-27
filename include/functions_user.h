#ifndef MATHQ__FUNCTIONS_USER
#define MATHQ__FUNCTIONS_USER 1


namespace mathq {





  //********************************************************************
  //--------------------------------------------------------------------
  //                           Functions
  //--------------------------------------------------------------------
  //********************************************************************



  // ----------------------------------------------------------------
  // op1: unary user function
  // ----------------------------------------------------------------


  template <class X, class Element, typename Number, size_t depth, size_t rank>
  auto op1(const typename FunctionType1<Number, Number>::type& f, const ExpressionR<X, Element, Number, depth, rank>& x) {
    return  ExpressionR_Unary_User<ExpressionR<X, Element, Number, depth, rank>, Element, Number, depth, rank>(f, x);
  }

  // ----------------------------------------------------------------
  // op2: binary user function
  // ----------------------------------------------------------------

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
  auto op2(const typename FunctionType2<NT1, NT2, typename AddType<NT1, NT2>::Type>::type& f, const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3;   // see TODO note above
    return  ExpressionR_Binary_User<ExpressionR<A, E1, NT1, depth, rank>,
      ExpressionR<B, E2, NT2, depth, rank>,
      E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank>(f, x1, x2);
  }



}; // namespace mathq 
#endif // MATHQ__FUNCTIONS_USER
