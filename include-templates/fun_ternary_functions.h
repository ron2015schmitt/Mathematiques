

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



// (111) MultiArray<E1(D1)> , MultiArray<E2(D2)> , MultiArray<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class D1, class D2, class D3, int depth, int rank>
auto ##FUNCTION##(const MArrayExpR<A, E1, D1, depth, rank>& x1, const MArrayExpR<B, E2, D2, depth, rank>& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, D1, depth, rank>,
    MArrayExpR<B, E2, D2, depth, rank>,
    MArrayExpR<C, E3, D3, depth, rank>,
    E1, E2, E3, E4, D1, D2, D3, D4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}



// (110) MultiArray<E1(D1)> , MultiArray<E2(D2)> , D3

template <class A, class B, class E1, class E2, class D1, class D2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<D3>::value>>
auto ##FUNCTION##(const MArrayExpR<A, E1, D1, depth, rank>& x1, const MArrayExpR<B, E2, D2, depth, rank>& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, D1, depth, rank>,
    MArrayExpR<B, E2, D2, depth, rank>,
    D3,
    E1, E2, D3, E4, D1, D2, D3, D4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (101) MultiArray<E1(D1)> , D2 , MultiArray<E3(D3)>

template <class A, class C, class E1, class E3, class D1, class D2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<D2>::value>>
auto ##FUNCTION##(const MArrayExpR<A, E1, D1, depth, rank>& x1, const D2& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, D1, depth, rank>,
    D2,
    MArrayExpR<C, E3, D3, depth, rank>,
    E1, D2, E3, E4, D1, D2, D3, D4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (100) MultiArray<E1(D1)> , D2 , D3

template <class A, class E1, class D1, class D2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<D2>::value&& NumberTrait<D3>::value>>
auto ##FUNCTION##(const MArrayExpR<A, E1, D1, depth, rank>& x1, const D2& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, D1, depth, rank>,
    D2,
    D3,
    E1, D2, D3, E4, D1, D2, D3, D4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, D2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (011) D1 , MultiArray<E2(D2)> , MultiArray<E3(D3)>

template <class B, class C, class E2, class E3, class D1, class D2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<D1>::value>>
auto ##FUNCTION##(const D1& x1, const MArrayExpR<B, E2, D2, depth, rank>& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    MArrayExpR<B, E2, D2, depth, rank>,
    MArrayExpR<C, E3, D3, depth, rank>,
    D1, E2, E3, E4, D1, D2, D3, D4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<D1, E2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}


// (010) D1, MultiArray<E2(D2)> , D3

template <class B, class E2, class D1, class D2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<D1>::value&& NumberTrait<D3>::value>>
auto ##FUNCTION##(const D1& x1, const MArrayExpR<B, E2, D2, depth, rank>& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    MArrayExpR<B, E2, D2, depth, rank>,
    D3,
    D1, E2, D3, E4, D1, D2, D3, D4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<D1, E2, D3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}

// (001) D1 , D2 , MultiArray<E3(D3)>

template <class C, class E3, class D1, class D2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<D1>::value&& NumberTrait<D2>::value>>
auto ##FUNCTION##(const D1& x1, const D2& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<D1, D2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<D1,
    D2,
    MArrayExpR<C, E3, D3, depth, rank>,
    D1, D2, E3, E4, D1, D2, D3, D4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<D1, D2, E3, E4, D1, D2, D3, D4> >(x1, x2, x3);
}
