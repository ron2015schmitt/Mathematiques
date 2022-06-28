#ifndef MATHQ__FUNCTIONS_USER_H
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


  template <class X, class Element, typename Number, int depth, int rank>
  auto op1(const typename FunctionType1<Number, Number>::type& f, const MArrayExpR<X, Element, Number, depth, rank>& x) {
    return  TER_Unary_User<MArrayExpR<X, Element, Number, depth, rank>, Element, Number, depth, rank>(f, x);
  }

  // ----------------------------------------------------------------
  // op2: binary user function
  // ----------------------------------------------------------------

  template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
  auto op2(const typename FunctionType2<NT1, NT2, typename AddType<NT1, NT2>::Type>::type& f, const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
    typedef typename AddType<NT1, NT2>::Type D3;
    typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
    return  TER_Binary_User<MArrayExpR<A, E1, NT1, depth, rank>,
      MArrayExpR<B, E2, NT2, depth, rank>,
      E1, E2, E3, NT1, NT2, D3, depth, depth, depth, rank, rank, rank>(f, x1, x2);
  }



}; // namespace mathq 
#endif // MATHQ__FUNCTIONS_USER_H
