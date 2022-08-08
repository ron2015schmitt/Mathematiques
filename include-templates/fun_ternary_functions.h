

// ----------------------------------------------------------------
// __COMMENTNAME__
// template functions for '__OP__'
//
//    Note: generated from template file '__MYFILENAME__'
//          using Python script '__SCRIPTNAME__'
// ----------------------------------------------------------------

//----------------------------------------------
// __COMMENTNAME__ (__OP__)
//----------------------------------------------



// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



// (111) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class A, class B, class C, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank>
auto __FUNCTION__(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename __TYPECLASS__<typename __TYPECLASS__<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, E2, E3, E4, NT1, NT2, NT3, NT4, depth, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR___NAME__<E1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}



// (110) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> , NT3

template <class A, class B, class E1, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT3>::value>>
auto __FUNCTION__(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename __TYPECLASS__<typename __TYPECLASS__<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    E1, E2, NT3, E4, NT1, NT2, NT3, NT4, depth, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR___NAME__<E1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (101) MultiArray<E1(NT1)> , NT2 , MultiArray<E3(NT3)>

template <class A, class C, class E1, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto __FUNCTION__(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename __TYPECLASS__<typename __TYPECLASS__<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    E1, NT2, E3, E4, NT1, NT2, NT3, NT4, depth, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR___NAME__<E1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (100) MultiArray<E1(NT1)> , NT2 , NT3

template <class A, class E1, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value&& NumberTrait<NT3>::value>>
auto __FUNCTION__(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const NT3& x3) {
  typedef typename __TYPECLASS__<typename __TYPECLASS__<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E1, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
    NT2,
    NT3,
    E1, NT2, NT3, E4, NT1, NT2, NT3, NT4, depth, 0, 0, depth, rank, rank, rank, rank,
    FUNCTOR___NAME__<E1, NT2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (011) NT1 , MultiArray<E2(NT2)> , MultiArray<E3(NT3)>

template <class B, class C, class E2, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto __FUNCTION__(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename __TYPECLASS__<typename __TYPECLASS__<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, E2, E3, E4, NT1, NT2, NT3, NT4, 0, depth, depth, depth, rank, rank, rank, rank,
    FUNCTOR___NAME__<NT1, E2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}


// (010) NT1, MultiArray<E2(NT2)> , NT3

template <class B, class E2, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT3>::value>>
auto __FUNCTION__(const NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const NT3& x3) {
  typedef typename __TYPECLASS__<typename __TYPECLASS__<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E2, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    ExpressionR<B, E2, NT2, depth, rank>,
    NT3,
    NT1, E2, NT3, E4, NT1, NT2, NT3, NT4, 0, depth, 0, depth, rank, rank, rank, rank,
    FUNCTOR___NAME__<NT1, E2, NT3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}

// (001) NT1 , NT2 , MultiArray<E3(NT3)>

template <class C, class E3, class NT1, class NT2, class NT3, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value&& NumberTrait<NT2>::value>>
auto __FUNCTION__(const NT1& x1, const NT2& x2, const ExpressionR<C, E3, NT3, depth, rank>& x3) {
  typedef typename __TYPECLASS__<typename __TYPECLASS__<NT1, NT2>::Type, NT3>::Type NT4;
  typedef typename ReplacedNumberTrait<E3, NT4>::Type E4;   // see TODO note above
  return  ExpressionR_Ternary<NT1,
    NT2,
    ExpressionR<C, E3, NT3, depth, rank>,
    NT1, NT2, E3, E4, NT1, NT2, NT3, NT4, 0, 0, depth, depth, rank, rank, rank, rank,
    FUNCTOR___NAME__<NT1, NT2, E3, E4, NT1, NT2, NT3, NT4> >(x1, x2, x3);
}
