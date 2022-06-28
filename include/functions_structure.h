#ifndef MATRICKS__FUNCTIONS_STRUCTURE_H
#define MATRICKS__FUNCTIONS_STRUCTURE_H 1


namespace mathq {



  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************




  // transpose(A) 

  template <class X, class Element, class D, int M, int R>
  auto transpose(const MArrayExpR<X, Element, D, M, R>& x) {
    return TER_Transpose<MArrayExpR<X, Element, D, M, R>, Element, D, M, R, FUNCTOR_pos<Element, Element, D, D>>(x);
  }

  // adjoint(A) - conjugate transpose - complex

  template <class X, class Element, class D, int M, int R>
  auto adjoint(const MArrayExpR<X, Element, std::complex<D>, M, R>& x) {
    return TER_Transpose<MArrayExpR<X, Element, std::complex<D>, M, R>, Element, std::complex<D>, M, R, FUNCTOR_conj_complex<Element, Element, std::complex<D>, std::complex<D>>>(x);
  }



  // adjoint(A) - conjugate transpose - Imaginary

  template <class X, class Element, class D, int M, int R>
  auto adjoint(const MArrayExpR<X, Element, Imaginary<D>, M, R>& x) {
    return TER_Transpose<MArrayExpR<X, Element, Imaginary<D>, M, R>, Element, Imaginary<D>, M, R, FUNCTOR_conj_imag<Element, Element, Imaginary<D>, Imaginary<D>>>(x);
  }




  // ~A conjugate transpose operator

  template <class X, class Element, class D, int M, int R>
  auto operator~(const MArrayExpR<X, Element, D, M, R>& x) {
    return adjoint(x);
  }













  // join - LHS

  // NOTE: Without the const qualifiers, the C++ compiler refuses to use this function
  //       in the case where one or both inputs are an expression, eg. join((V1,V2),V3)
  //       Only work-around I have come up with i sto use conts and then cast the const away

  template <class A, class B, class Element, class D, int M, int R, typename = EnableIf<R==1> >
  auto join(const MArrayExpRW<A, Element, D, M, R>& x1, const MArrayExpRW<B, Element, D, M, R>& x2) {
    MArrayExpRW<A, Element, D, M, R>& a1 = const_cast<MArrayExpRW<A, Element, D, M, R>&>(x1);
    MArrayExpRW<B, Element, D, M, R>& a2 = const_cast<MArrayExpRW<B, Element, D, M, R>&>(x2);
    return TERW_Join<MArrayExpRW<A, Element, D, M, R>, MArrayExpRW<B, Element, D, M, R>, Element, D, M>(a1, a2);
  }


  // operator, - LHS

  // Note above applies here as well.

  template <class A, class B, class Element, class D, int M, int R, typename = EnableIf<R==1> >
  auto operator,(const MArrayExpRW<A, Element, D, M, R>& x1, const MArrayExpRW<B, Element, D, M, R>& x2) {
    MArrayExpRW<A, Element, D, M, R>& a1 = const_cast<MArrayExpRW<A, Element, D, M, R>&>(x1);
    MArrayExpRW<B, Element, D, M, R>& a2 = const_cast<MArrayExpRW<B, Element, D, M, R>&>(x2);
    return join(a1, a2);
  }


  // join - RHS

  template <class A, class B, class Element, class D, int M, int R, typename = EnableIf<(R==1)>  >
  auto join(const MArrayExpR<A, Element, D, M, R>& x1, const MArrayExpR<B, Element, D, M, R>& x2) {
    return  TER_Join<MArrayExpR<A, Element, D, M, R>, MArrayExpR<B, Element, D, M, R>, Element, D, M>(x1, x2);
  }


  // operator, - RHS

  template <class A, class B, class Element, class D, int M, int R, typename = EnableIf<(R==1)>  >
  auto operator,(const MArrayExpR<A, Element, D, M, R>& x1, const MArrayExpR<B, Element, D, M, R>& x2) {
    return join(x1, x2);
  }



  // rep(v,m)

  template <class A, class D>
  auto rep(const MArrayExpR<A, D, D, 1, 1>& a, const size_t m) {
    return TER_Rep<MArrayExpR<A, D, D, 1, 1>, D>(a, m);
  }








};

#endif 
