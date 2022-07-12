

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

// (1) MultiArray<E1(NT1)> ##OP## MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
auto ##FUNCTION##(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2) {
  typedef typename ##TYPECLASS##<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3;   // see TODO note above
  return  ExpressionR_Binary<ExpressionR<A, E1, NT1, depth, rank>,
    ExpressionR<B, E2, NT2, depth, rank>,
    E1, E2, E3, NT1, NT2, NT3, depth, depth, depth, rank, rank, rank,
    FUNCTOR_##NAME##<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}




// (2A) MultiArray<Element(NT1)> ##OP## NT2

template <class A, class NT2, class Element, class NT1, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT2>::value>>
auto ##FUNCTION##(const ExpressionR<A, Element, NT1, depth, rank>& x1, const NT2& x2) {
  typedef typename ##TYPECLASS##<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplacedNumberType E3;
  return  ExpressionR_Binary<ExpressionR<A, Element, NT1, depth, rank>,
    NT2,
    Element, NT2, E3, NT1, NT2, NT3, depth, 0, depth, rank, rank, rank,
    FUNCTOR_##NAME##<Element, NT2, E3, NT1, NT2, NT3> >(x1, x2);
}



// (2B) NT1 ##OP## MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, size_t depth, size_t rank, typename = std::enable_if_t<NumberTrait<NT1>::value>>
auto ##FUNCTION##(const NT1& x1, const ExpressionR<B, Element, NT2, depth, rank>& x2) {
  typedef typename ##TYPECLASS##<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<Element, NT3>::ReplacedNumberType E3;
  return  ExpressionR_Binary<NT1,
    ExpressionR<B, Element, NT2, depth, rank>,
    NT1, Element, E3, NT1, NT2, NT3, 0, depth, depth, rank, rank, rank,
    FUNCTOR_##NAME##<NT1, Element, E3, NT1, NT2, NT3> >(x1, x2);
}



// (3A) element-wise ##COMMENTNAME##: x1[i] ##OP## x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)


template <class A, class B, class E1, class E2, class NT1, class NT2, size_t D1, size_t D2, size_t R1, size_t R2,
  EnableIf<(D1==D2+1)&&(IsMultiArrayOrExpression<E1>::value)&&(E1::rank_value==R2)> = 0 >
  auto ##FUNCTION##(const ExpressionR<A, E1, NT1, D1, R1>& x1, const ExpressionR<B, E2, NT2, D2, R2>& x2) {
  typedef typename ##TYPECLASS##<NT1, NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr size_t R3 = R1;
  constexpr size_t D3 = D1;
  typedef typename NumberTrait<Element, NT3>::ReplacedNumberType E3;
  //    MOUT << "A" <<std::endl;
  return  ExpressionR_Binary<ExpressionR<A, E1, NT1, D1, R1>,
    ExpressionR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_##NAME##<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (3B) element-wise ##COMMENTNAME##: x1 ##OP## x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, size_t D1, size_t D2, size_t R1, size_t R2,
  EnableIf<(D1+1==D2)&&(IsMultiArrayOrExpression<E2>::value)&&(E2::rank_value==R1)> = 0 >
  auto ##FUNCTION##(const ExpressionR<A, E1, NT1, D1, R1>& x1, const ExpressionR<B, E2, NT2, D2, R2>& x2) {
  typedef typename ##TYPECLASS##<NT1, NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr size_t R3 = R2;
  constexpr size_t D3 = D2;
  typedef typename NumberTrait<Element, NT3>::ReplacedNumberType E3;
  //    MOUT << "B" <<std::endl;
  return  ExpressionR_Binary<ExpressionR<A, E1, NT1, D1, R1>,
    ExpressionR<B, E2, NT2, D2, R2>,
    E1, E2, E3, NT1, NT2, NT3, D1, D2, D3, R1, R2, R3,
    FUNCTOR_##NAME##<Element, Element, E3, NT1, NT2, NT3> >(x1, x2);
}


// (4A) MultiArray<NT1,rank,depth> ##OP## MultiArray<NT2,rank,1>

// Depending on rank and dimensions, this may be top-level or element wise ##COMMENTNAME##
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

template <class A, class B, class E1, class NT1, class NT2, size_t D1, size_t D2, size_t rank,
  EnableIf<(D1>=2)&&(D2==1)&&(IsMultiArrayOrExpression<E1>::value)> = 0  >
  auto ##FUNCTION##(const ExpressionR<A, E1, NT1, D1, rank>& x1, const ExpressionR<B, NT2, NT2, D2, rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef ExpressionR<B, NT2, NT2, D2, rank> E2;

  typedef typename ##TYPECLASS##<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3;   // see TODO note above
  constexpr size_t D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  ExpressionR_Binary<ExpressionR<A, E1, NT1, D1, rank>,
    ExpressionR<B, NT2, NT2, D2, rank>,
    E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_##NAME##<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}

// (4B) MultiArray<NT1,rank,1> ##OP## MultiArray<NT2,rank,depth>

// Depending on rank and dimensions, this may be top-level or element wise ##COMMENTNAME##
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, size_t D1, size_t D2, size_t rank,
  EnableIf<(D1==1)&&(D2>=2)&&(IsMultiArrayOrExpression<E2>::value)> = 0  >
  auto ##FUNCTION##(const ExpressionR<A, NT1, NT1, D1, rank>& x1, const ExpressionR<B, E2, NT2, D2, rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef ExpressionR<A, NT1, NT1, D1, rank> E1;
  typedef typename ##TYPECLASS##<NT1, NT2>::Type NT3;
  typedef typename NumberTrait<E2, NT3>::ReplacedNumberType E3;   // see TODO note above
  constexpr size_t D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  ExpressionR_Binary<ExpressionR<A, NT1, NT1, D1, rank>,
    ExpressionR<B, E2, NT2, D2, rank>,
    NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
    FUNCTOR_##NAME##<E1, E2, E3, NT1, NT2, NT3> >(x1, x2);
}



