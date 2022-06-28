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


  template <class X, class Element, class Number, int depth, int R>
  auto op1(const typename FunctionType1<Number, Number>::type& f, const MArrayExpR<X, Element, Number, depth, R>& x) {
    return  TER_Unary_User<MArrayExpR<X, Element, Number, depth, R>, Element, Number, depth, R>(f, x);
  }

  // ----------------------------------------------------------------
  // op2: binary user function
  // ----------------------------------------------------------------

  template <class A, class B, class E1, class E2, class D1, class D2, int depth, int R>
  auto op2(const typename FunctionType2<D1, D2, typename AddType<D1, D2>::Type>::type& f, const MArrayExpR<A, E1, D1, depth, R>& x1, const MArrayExpR<B, E2, D2, depth, R>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;   // see TODO note above
    return  TER_Binary_User<MArrayExpR<A, E1, D1, depth, R>,
      MArrayExpR<B, E2, D2, depth, R>,
      E1, E2, E3, D1, D2, D3, depth, depth, depth, R, R, R>(f, x1, x2);
  }



}; // namespace mathq 
#endif // MATHQ__FUNCTIONS_USER_H
