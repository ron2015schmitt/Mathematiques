

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



// (111) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , MultiArray<E3(D3)>

template <class A, class B, class C, class E1, class E2, class E3, class NT1, class NT2, class D3, int depth, int rank>
auto ##FUNCTION##(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<NT1, NT2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    MArrayExpR<C, E3, D3, depth, rank>,
    E1, E2, E3, E4, NT1, NT2, D3, D4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, E2, E3, E4, NT1, NT2, D3, D4> >(x1, x2, x3);
}



// (110) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , D3

template <class A, class B, class E1, class E2, class NT1, class NT2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<D3>::value>>
auto ##FUNCTION##(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<NT1, NT2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, NT1, depth, rank>,
    MArrayExpR<B, E2, NT2, depth, rank>,
    D3,
    E1, E2, D3, E4, NT1, NT2, D3, D4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, E2, D3, E4, NT1, NT2, D3, D4> >(x1, x2, x3);
}

// (101) MultiArray<E1(NT1)> , NT2 , MultiArray<E3(D3)>

template <class A, class C, class E1, class E3, class NT1, class NT2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto ##FUNCTION##(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<NT1, NT2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, NT1, depth, rank>,
    NT2,
    MArrayExpR<C, E3, D3, depth, rank>,
    E1, NT2, E3, E4, NT1, NT2, D3, D4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, NT2, E3, E4, NT1, NT2, D3, D4> >(x1, x2, x3);
}

// (100) MultiArray<E1(NT1)> , NT2 , D3

template <class A, class E1, class NT1, class NT2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value&& NumberTrait<D3>::value>>
auto ##FUNCTION##(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<NT1, NT2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E1, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<MArrayExpR<A, E1, NT1, depth, rank>,
    NT2,
    D3,
    E1, NT2, D3, E4, NT1, NT2, D3, D4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<E1, NT2, D3, E4, NT1, NT2, D3, D4> >(x1, x2, x3);
}

// (011) NT1 , MultiArray<E2(NT2)> , MultiArray<E3(D3)>

template <class B, class C, class E2, class E3, class NT1, class NT2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto ##FUNCTION##(const NT1& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<NT1, NT2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<NT1,
    MArrayExpR<B, E2, NT2, depth, rank>,
    MArrayExpR<C, E3, D3, depth, rank>,
    NT1, E2, E3, E4, NT1, NT2, D3, D4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<NT1, E2, E3, E4, NT1, NT2, D3, D4> >(x1, x2, x3);
}


// (010) NT1, MultiArray<E2(NT2)> , D3

template <class B, class E2, class NT1, class NT2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<D3>::value>>
auto ##FUNCTION##(const NT1& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2, const D3& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<NT1, NT2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E2, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<NT1,
    MArrayExpR<B, E2, NT2, depth, rank>,
    D3,
    NT1, E2, D3, E4, NT1, NT2, D3, D4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<NT1, E2, D3, E4, NT1, NT2, D3, D4> >(x1, x2, x3);
}

// (001) NT1 , NT2 , MultiArray<E3(D3)>

template <class C, class E3, class NT1, class NT2, class D3, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT2>::value>>
auto ##FUNCTION##(const NT1& x1, const NT2& x2, const MArrayExpR<C, E3, D3, depth, rank>& x3) {
  typedef typename ##TYPECLASS##<typename ##TYPECLASS##<NT1, NT2>::Type, D3>::Type D4;
  typedef typename NumberTrait<E3, D4>::ReplaceTypeD E4;   // see TODO note above
  return  TER_Ternary<NT1,
    NT2,
    MArrayExpR<C, E3, D3, depth, rank>,
    NT1, NT2, E3, E4, NT1, NT2, D3, D4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR_##NAME##<NT1, NT2, E3, E4, NT1, NT2, D3, D4> >(x1, x2, x3);
}
