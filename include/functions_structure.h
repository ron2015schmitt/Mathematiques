#ifndef MATRICKS__FUNCTIONS_STRUCTURE_H
#define MATRICKS__FUNCTIONS_STRUCTURE_H 1


namespace mathq {



  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************




  // transpose(A) 

  template <class X, class E, class D, int M, int R>
  auto transpose(const MArrayExpR<X, E, D, M, R>& x) {
    return TER_Transpose<MArrayExpR<X, E, D, M, R>, E, D, M, R, FUNCTOR_pos<E, E, D, D>>(x);
  }

  // adjoint(A) - conjugate transpose - complex

  template <class X, class E, class D, int M, int R>
  auto adjoint(const MArrayExpR<X, E, std::complex<D>, M, R>& x) {
    return TER_Transpose<MArrayExpR<X, E, std::complex<D>, M, R>, E, std::complex<D>, M, R, FUNCTOR_conj_complex<E, E, std::complex<D>, std::complex<D>>>(x);
  }



  // adjoint(A) - conjugate transpose - Imaginary

  template <class X, class E, class D, int M, int R>
  auto adjoint(const MArrayExpR<X, E, Imaginary<D>, M, R>& x) {
    return TER_Transpose<MArrayExpR<X, E, Imaginary<D>, M, R>, E, Imaginary<D>, M, R, FUNCTOR_conj_imag<E, E, Imaginary<D>, Imaginary<D>>>(x);
  }




  // ~A conjugate transpose operator

  template <class X, class E, class D, int M, int R>
  auto operator~(const MArrayExpR<X, E, D, M, R>& x) {
    return adjoint(x);
  }













  // join - LHS

  // NOTE: Without the const qualifiers, the C++ compiler refuses to use this function
  //       in the case where one or both inputs are an expression, eg. join((V1,V2),V3)
  //       Only work-around I have come up with i sto use conts and then cast the const away

  template <class A, class B, class E, class D, int M, int R, typename = EnableIf<R==1> >
  auto join(const MArrayExpRW<A, E, D, M, R>& x1, const MArrayExpRW<B, E, D, M, R>& x2) {
    MArrayExpRW<A, E, D, M, R>& a1 = const_cast<MArrayExpRW<A, E, D, M, R>&>(x1);
    MArrayExpRW<B, E, D, M, R>& a2 = const_cast<MArrayExpRW<B, E, D, M, R>&>(x2);
    return TERW_Join<MArrayExpRW<A, E, D, M, R>, MArrayExpRW<B, E, D, M, R>, E, D, M>(a1, a2);
  }


  // operator, - LHS

  // Note above applies here as well.

  template <class A, class B, class E, class D, int M, int R, typename = EnableIf<R==1> >
  auto operator,(const MArrayExpRW<A, E, D, M, R>& x1, const MArrayExpRW<B, E, D, M, R>& x2) {
    MArrayExpRW<A, E, D, M, R>& a1 = const_cast<MArrayExpRW<A, E, D, M, R>&>(x1);
    MArrayExpRW<B, E, D, M, R>& a2 = const_cast<MArrayExpRW<B, E, D, M, R>&>(x2);
    return join(a1, a2);
  }


  // join - RHS

  template <class A, class B, class E, class D, int M, int R, typename = EnableIf<(R==1)>  >
  auto join(const MArrayExpR<A, E, D, M, R>& x1, const MArrayExpR<B, E, D, M, R>& x2) {
    return  TER_Join<MArrayExpR<A, E, D, M, R>, MArrayExpR<B, E, D, M, R>, E, D, M>(x1, x2);
  }


  // operator, - RHS

  template <class A, class B, class E, class D, int M, int R, typename = EnableIf<(R==1)>  >
  auto operator,(const MArrayExpR<A, E, D, M, R>& x1, const MArrayExpR<B, E, D, M, R>& x2) {
    return join(x1, x2);
  }



  // rep(v,m)

  template <class A, class D>
  auto rep(const MArrayExpR<A, D, D, 1, 1>& a, const size_t m) {
    return TER_Rep<MArrayExpR<A, D, D, 1, 1>, D>(a, m);
  }








};

#endif 
