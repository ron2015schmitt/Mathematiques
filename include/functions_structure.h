#ifndef MATRICKS__FUNCTIONS_STRUCTURE_H
#define MATRICKS__FUNCTIONS_STRUCTURE_H 1


namespace mathq {



  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************




  // transpose(A) 

  template <class X, class Element, class Number, int depth, int R>
  auto transpose(const MArrayExpR<X, Element, Number, depth, R>& x) {
    return TER_Transpose<MArrayExpR<X, Element, Number, depth, R>, Element, Number, depth, R, FUNCTOR_pos<Element, Element, Number, Number>>(x);
  }

  // adjoint(A) - conjugate transpose - complex

  template <class X, class Element, class Number, int depth, int R>
  auto adjoint(const MArrayExpR<X, Element, std::complex<Number>, depth, R>& x) {
    return TER_Transpose<MArrayExpR<X, Element, std::complex<Number>, depth, R>, Element, std::complex<Number>, depth, R, FUNCTOR_conj_complex<Element, Element, std::complex<Number>, std::complex<Number>>>(x);
  }



  // adjoint(A) - conjugate transpose - Imaginary

  template <class X, class Element, class Number, int depth, int R>
  auto adjoint(const MArrayExpR<X, Element, Imaginary<Number>, depth, R>& x) {
    return TER_Transpose<MArrayExpR<X, Element, Imaginary<Number>, depth, R>, Element, Imaginary<Number>, depth, R, FUNCTOR_conj_imag<Element, Element, Imaginary<Number>, Imaginary<Number>>>(x);
  }




  // ~A conjugate transpose operator

  template <class X, class Element, class Number, int depth, int R>
  auto operator~(const MArrayExpR<X, Element, Number, depth, R>& x) {
    return adjoint(x);
  }













  // join - LHS

  // NOTE: Without the const qualifiers, the C++ compiler refuses to use this function
  //       in the case where one or both inputs are an expression, eg. join((V1,V2),V3)
  //       Only work-around I have come up with i sto use conts and then cast the const away

  template <class A, class B, class Element, class Number, int depth, int R, typename = EnableIf<R==1> >
  auto join(const MArrayExpRW<A, Element, Number, depth, R>& x1, const MArrayExpRW<B, Element, Number, depth, R>& x2) {
    MArrayExpRW<A, Element, Number, depth, R>& a1 = const_cast<MArrayExpRW<A, Element, Number, depth, R>&>(x1);
    MArrayExpRW<B, Element, Number, depth, R>& a2 = const_cast<MArrayExpRW<B, Element, Number, depth, R>&>(x2);
    return TERW_Join<MArrayExpRW<A, Element, Number, depth, R>, MArrayExpRW<B, Element, Number, depth, R>, Element, Number, depth>(a1, a2);
  }


  // operator, - LHS

  // Note above applies here as well.

  template <class A, class B, class Element, class Number, int depth, int R, typename = EnableIf<R==1> >
  auto operator,(const MArrayExpRW<A, Element, Number, depth, R>& x1, const MArrayExpRW<B, Element, Number, depth, R>& x2) {
    MArrayExpRW<A, Element, Number, depth, R>& a1 = const_cast<MArrayExpRW<A, Element, Number, depth, R>&>(x1);
    MArrayExpRW<B, Element, Number, depth, R>& a2 = const_cast<MArrayExpRW<B, Element, Number, depth, R>&>(x2);
    return join(a1, a2);
  }


  // join - RHS

  template <class A, class B, class Element, class Number, int depth, int R, typename = EnableIf<(R==1)>  >
  auto join(const MArrayExpR<A, Element, Number, depth, R>& x1, const MArrayExpR<B, Element, Number, depth, R>& x2) {
    return  TER_Join<MArrayExpR<A, Element, Number, depth, R>, MArrayExpR<B, Element, Number, depth, R>, Element, Number, depth>(x1, x2);
  }


  // operator, - RHS

  template <class A, class B, class Element, class Number, int depth, int R, typename = EnableIf<(R==1)>  >
  auto operator,(const MArrayExpR<A, Element, Number, depth, R>& x1, const MArrayExpR<B, Element, Number, depth, R>& x2) {
    return join(x1, x2);
  }



  // rep(v,m)

  template <class A, class Number>
  auto rep(const MArrayExpR<A, Number, Number, 1, 1>& a, const size_t m) {
    return TER_Rep<MArrayExpR<A, Number, Number, 1, 1>, Number>(a, m);
  }








};

#endif 
