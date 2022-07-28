#ifndef MATHQ__FUNCTIONS_STRUCTURE
#define MATHQ__FUNCTIONS_STRUCTURE 1


namespace mathq {



  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************

  // transpose(A) 

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  auto transpose(const ExpressionR<X, Element, Number, depth, rank>& x) {
    return ExpressionR_Transpose<ExpressionR<X, Element, Number, depth, rank>, Element, Number, depth, rank, FUNCTOR_pos<Element, Element, Number, Number>>(x);
  }

  // adjoint(A) - conjugate transpose - complex

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  auto adjoint(const ExpressionR<X, Element, std::complex<Number>, depth, rank>& x) {
    return ExpressionR_Transpose<ExpressionR<X, Element, std::complex<Number>, depth, rank>, Element, std::complex<Number>, depth, rank, FUNCTOR_conj_complex<Element, Element, std::complex<Number>, std::complex<Number>>>(x);
  }



  // adjoint(A) - conjugate transpose - Imaginary

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  auto adjoint(const ExpressionR<X, Element, Imaginary<Number>, depth, rank>& x) {
    return ExpressionR_Transpose<ExpressionR<X, Element, Imaginary<Number>, depth, rank>, Element, Imaginary<Number>, depth, rank, FUNCTOR_conj_imag<Element, Element, Imaginary<Number>, Imaginary<Number>>>(x);
  }

  // ~A conjugate transpose operator

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  auto operator~(const ExpressionR<X, Element, Number, depth, rank>& x) {
    return adjoint(x);
  }


  // join - LHS

  // NOTE: Without the const qualifiers, the C++ compiler refuses to use this function
  //       in the case where one or both inputs are an expression, eg. join((V1,V2),V3)
  //       Only work-around I have come up with i sto use conts and then cast the const away

  template <class A, class B, class Element, typename Number, size_t depth, size_t rank, typename = EnableIf<rank==1> >
  auto join(const ExpressionRW<A, Element, Number, depth, rank>& x1, const ExpressionRW<B, Element, Number, depth, rank>& x2) {
    ExpressionRW<A, Element, Number, depth, rank>& a1 = const_cast<ExpressionRW<A, Element, Number, depth, rank>&>(x1);
    ExpressionRW<B, Element, Number, depth, rank>& a2 = const_cast<ExpressionRW<B, Element, Number, depth, rank>&>(x2);
    return ExpressionRW_Join<ExpressionRW<A, Element, Number, depth, rank>, ExpressionRW<B, Element, Number, depth, rank>, Element, Number, depth>(a1, a2);
  }


  // operator, - LHS

  // Note above applies here as well.

  template <class A, class B, class Element, typename Number, size_t depth, size_t rank, typename = EnableIf<rank==1> >
  auto operator,(const ExpressionRW<A, Element, Number, depth, rank>& x1, const ExpressionRW<B, Element, Number, depth, rank>& x2) {
    ExpressionRW<A, Element, Number, depth, rank>& a1 = const_cast<ExpressionRW<A, Element, Number, depth, rank>&>(x1);
    ExpressionRW<B, Element, Number, depth, rank>& a2 = const_cast<ExpressionRW<B, Element, Number, depth, rank>&>(x2);
    return join(a1, a2);
  }


  // join - RHS

  template <class A, class B, class Element, typename Number, size_t depth, size_t rank, typename = EnableIf<(rank==1)>  >
  auto join(const ExpressionR<A, Element, Number, depth, rank>& x1, const ExpressionR<B, Element, Number, depth, rank>& x2) {
    return  ExpressionR_Join<ExpressionR<A, Element, Number, depth, rank>, ExpressionR<B, Element, Number, depth, rank>, Element, Number, depth>(x1, x2);
  }


  // operator, - RHS

  template <class A, class B, class Element, typename Number, size_t depth, size_t rank, typename = EnableIf<(rank==1)>  >
  auto operator,(const ExpressionR<A, Element, Number, depth, rank>& x1, const ExpressionR<B, Element, Number, depth, rank>& x2) {
    return join(x1, x2);
  }



  // rep(v,m)

  template <class A, typename Number>
  auto rep(const ExpressionR<A, Number, Number, 1, 1>& a, const size_t m) {
    return ExpressionR_Rep<ExpressionR<A, Number, Number, 1, 1>, Number>(a, m);
  }




};

#endif 
