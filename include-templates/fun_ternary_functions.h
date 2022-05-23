

// ----------------------------------------------------------------
// ##COMMENTNAME##
// template functions for '##OP##'
//
//    Note: generated from template file '##MYFILENAME##'
//          using Python script '##SCRIPTNAME##'
// ----------------------------------------------------------------

//----------------------------------------------
// ##COMMENTNAME## (##OP##)
//----------------------------------------------



// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



// (111) Tensor<E1(D1)> , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class D1, class D2, class D3, int M, int R>
auto ##FUNCTION##(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    E1, E2, E3, E4, D1, D2, D3, D4, M, M, M, M, R, R, R, R,
    FUNCTOR_##NAME##<E1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}



// (110) Tensor<E1(D1)> , Tensor<E2(D2)> , D3

template <class A, class B, class E1, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D3>::value>>
auto ##FUNCTION##(const TensorR<A, E1, D1, M, R>& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    TensorR<B, E2, D2, M, R>,
    D3,
    E1, E2, D3, E4, D1, D2, D3, D4, M, M, 0, M, R, R, R, R,
    FUNCTOR_##NAME##<E1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (101) Tensor<E1(D1)> , D2 , Tensor<E3(D3)>

template <class A, class C, class E1, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>>
auto ##FUNCTION##(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    TensorR<C, E3, D3, M, R>,
    E1, D2, E3, E4, D1, D2, D3, D4, M, 0, M, M, R, R, R, R,
    FUNCTOR_##NAME##<E1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (100) Tensor<E1(D1)> , D2 , D3

template <class A, class E1, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D2>::value&& NumberType<D3>::value>>
auto ##FUNCTION##(const TensorR<A, E1, D1, M, R>& x1, const D2& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<TensorR<A, E1, D1, M, R>,
    D2,
    D3,
    E1, D2, D3, E4, D1, D2, D3, D4, M, 0, 0, M, R, R, R, R,
    FUNCTOR_##NAME##<E1, D2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (011) D1 , Tensor<E2(D2)> , Tensor<E3(D3)>

template <class B, class C, class E2, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>>
auto ##FUNCTION##(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    TensorR<C, E3, D3, M, R>,
    D1, E2, E3, E4, D1, D2, D3, D4, 0, M, M, M, R, R, R, R,
    FUNCTOR_##NAME##<D1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}


// (010) D1, Tensor<E2(D2)> , D3

template <class B, class E2, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D3>::value>>
auto ##FUNCTION##(const D1& x1, const TensorR<B, E2, D2, M, R>& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    TensorR<B, E2, D2, M, R>,
    D3,
    D1, E2, D3, E4, D1, D2, D3, D4, 0, M, 0, M, R, R, R, R,
    FUNCTOR_##NAME##<D1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (001) D1 , D2 , Tensor<E3(D3)>

template <class C, class E3, class D1, class D2, class D3, int M, int R, typename = std::enable_if_t<NumberType<D1>::value&& NumberType<D2>::value>>
auto ##FUNCTION##(const D1& x1, const D2& x2, const TensorR<C, E3, D3, M, R>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberType<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    D2,
    TensorR<C, E3, D3, M, R>,
    D1, D2, E3, E4, D1, D2, D3, D4, 0, 0, M, M, R, R, R, R,
    FUNCTOR_##NAME##<D1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}
