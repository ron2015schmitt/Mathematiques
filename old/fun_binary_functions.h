  
//----------------------------------------------
// Addition (+)
//----------------------------------------------

// MultiArray<E1(NT1)> + MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank> 
auto operator+(const ExpressionR<A,E1,NT1,depth,rank>& x1, const ExpressionR<B,E2,NT2,depth,rank>& x2) {
  typedef typename AddType<NT1,NT2>::Type NT3;
  typedef typename NumberTrait<E1,NT3>::ReplacedElementType E3;   // see TODO note above
  return  TER_Binary<ExpressionR<A,E1,NT1,depth,rank>,
		     ExpressionR<B,E2,NT2,depth,rank>,
		     E1,E2,E3,NT1,NT2,NT3,depth,depth,depth,rank,rank,rank,
		     FUNCTOR_add<E1,E2,E3,NT1,NT2,NT3> >(x1,x2); 
}


  

// MultiArray<Element(NT1)> + NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>> 
auto operator+(const ExpressionR<A,Element,NT1,depth,rank>& x1, const NT2& x2) {
  typedef typename AddType<NT1,NT2>::Type NT3;
  typedef typename NumberTrait<Element,NT3>::ReplacedElementType E3;   
  return  TER_Binary<ExpressionR<A,Element,NT1,depth,rank>,
		     NT2,
		     Element,NullType,E3,NT1,NT2,NT3,depth,0,depth,rank,rank,rank,
		     FUNCTOR_add<Element,NullType,E3,NT1,NT2,NT3> >(x1,x2); 
}


  
// NT1 + MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>> 
auto operator+(const NT1& x1, const ExpressionR<B,Element,NT2,depth,rank>& x2) {
  typedef typename AddType<NT1,NT2>::Type NT3;
  typedef typename NumberTrait<Element,NT3>::ReplacedElementType E3;   
  return  TER_Binary<NT1,
		     ExpressionR<B,Element,NT2,depth,rank>,
		     NullType,Element,E3,NT1,NT2,NT3,0,depth,depth,rank,rank,rank,
		     FUNCTOR_add<NullType,Element,E3,NT1,NT2,NT3> >(x1,x2); 
}


  
// element-wise addition: x1[i] + x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
	  EnableIf<(D1==D2+1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)&&(E1::rank_value==R2)> = 0 >
auto operator+(const ExpressionR<A,E1,NT1,D1,R1>& x1, const ExpressionR<B,E2,NT2,D2,R2>& x2) {
  typedef typename AddType<NT1,NT2>::Type NT3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int D3 = D1;
  typedef typename NumberTrait<Element,NT3>::ReplacedElementType E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<ExpressionR<A,E1,NT1,D1,R1>,
		     ExpressionR<B,E2,NT2,D2,R2>,
		     E1,E2,E3,NT1,NT2,NT3,D1,D2,D3,R1,R2,R3,
		     FUNCTOR_add<Element,Element,E3,NT1,NT2,NT3> >(x1,x2); 
}


// element-wise addition: x1 + x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int D1, int D2, int R1, int R2,
	  EnableIf<(D1+1==D2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)&&(E2::rank_value==R1)> = 0 >
auto operator+(const ExpressionR<A,E1,NT1,D1,R1>& x1, const ExpressionR<B,E2,NT2,D2,R2>& x2) {
  typedef typename AddType<NT1,NT2>::Type NT3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int D3 = D2;
  typedef typename NumberTrait<Element,NT3>::ReplacedElementType E3;  
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<ExpressionR<A,E1,NT1,D1,R1>,
		     ExpressionR<B,E2,NT2,D2,R2>,
		     E1,E2,E3,NT1,NT2,NT3,D1,D2,D3,R1,R2,R3,
		     FUNCTOR_add<Element,Element,E3,NT1,NT2,NT3> >(x1,x2); 
}

    
// MultiArray<NT1,rank,depth> + MultiArray<NT2,rank,1>
// Depending on rank and dimensions, this may be top-level or element wise addition
// Note: D2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class NT1, class NT2, int D1, int D2, int rank,
	  EnableIf<(D1>=2)&&(D2==1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)> = 0  >
auto operator+(const ExpressionR<A,E1,NT1,D1,rank>& x1, const ExpressionR<B,NT2,NT2,D2,rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef ExpressionR<B,NT2,NT2,D2,rank> E2;  

  typedef typename AddType<NT1,NT2>::Type NT3;
  typedef typename NumberTrait<E1,NT3>::ReplacedElementType E3;   // see TODO note above
  constexpr int D3 = D1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<ExpressionR<A,E1,NT1,D1,rank>,
		     ExpressionR<B,NT2,NT2,D2,rank>,
		     E1,NT2,E3,NT1,NT2,NT3,D1,D2,D3,rank,rank,rank,
		     FUNCTOR_add<E1,E2,E3,NT1,NT2,NT3> >(x1,x2); 
}

// MultiArray<NT1,rank,1> + MultiArray<NT2,rank,depth>
// Depending on rank and dimensions, this may be top-level or element wise addition
// Note: D1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int D1, int D2, int rank,
	  EnableIf<(D1==1)&&(D2>=2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)> = 0  >
auto operator+(const ExpressionR<A,NT1,NT1,D1,rank>& x1, const ExpressionR<B,E2,NT2,D2,rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef ExpressionR<A,NT1,NT1,D1,rank> E1;  
  typedef typename AddType<NT1,NT2>::Type NT3;
  typedef typename NumberTrait<E2,NT3>::ReplacedElementType E3;   // see TODO note above
  constexpr int D3 = D2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<ExpressionR<A,NT1,NT1,D1,rank>,
		     ExpressionR<B,E2,NT2,D2,rank>,
		     NT1,E2,E3,NT1,NT2,NT3,D1,D2,D3,rank,rank,rank,
		     FUNCTOR_add<E1,E2,E3,NT1,NT2,NT3> >(x1,x2); 
}



