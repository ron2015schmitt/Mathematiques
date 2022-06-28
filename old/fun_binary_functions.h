  
//----------------------------------------------
// Addition (+)
//----------------------------------------------

// MultiArray<E1(NT1)> + MultiArray<E2(NT2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank> 
auto operator+(const MArrayExpR<A,E1,NT1,depth,rank>& x1, const MArrayExpR<B,E2,NT2,depth,rank>& x2) {
  typedef typename AddType<NT1,NT2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A,E1,NT1,depth,rank>,
		     MArrayExpR<B,E2,NT2,depth,rank>,
		     E1,E2,E3,NT1,NT2,D3,depth,depth,depth,rank,rank,rank,
		     FUNCTOR_add<E1,E2,E3,NT1,NT2,D3> >(x1,x2); 
}


  

// MultiArray<Element(NT1)> + NT2

template <class A, class NT2, class Element, class NT1, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT2>::value>> 
auto operator+(const MArrayExpR<A,Element,NT1,depth,rank>& x1, const NT2& x2) {
  typedef typename AddType<NT1,NT2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<MArrayExpR<A,Element,NT1,depth,rank>,
		     NT2,
		     Element,Null,E3,NT1,NT2,D3,depth,0,depth,rank,rank,rank,
		     FUNCTOR_add<Element,Null,E3,NT1,NT2,D3> >(x1,x2); 
}


  
// NT1 + MultiArray<Element(NT2)>

template <class NT1, class B, class Element, class NT2, int depth, int rank, typename = std::enable_if_t<NumberTrait<NT1>::value>> 
auto operator+(const NT1& x1, const MArrayExpR<B,Element,NT2,depth,rank>& x2) {
  typedef typename AddType<NT1,NT2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<NT1,
		     MArrayExpR<B,Element,NT2,depth,rank>,
		     Null,Element,E3,NT1,NT2,D3,0,depth,depth,rank,rank,rank,
		     FUNCTOR_add<Null,Element,E3,NT1,NT2,D3> >(x1,x2); 
}


  
// element-wise addition: x1[i] + x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class NT1, class NT2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)&&(E1::rank_value==R2)> = 0 >
auto operator+(const MArrayExpR<A,E1,NT1,M1,R1>& x1, const MArrayExpR<B,E2,NT2,M2,R2>& x2) {
  typedef typename AddType<NT1,NT2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,NT1,M1,R1>,
		     MArrayExpR<B,E2,NT2,M2,R2>,
		     E1,E2,E3,NT1,NT2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<Element,Element,E3,NT1,NT2,D3> >(x1,x2); 
}


// element-wise addition: x1 + x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class NT1, class NT2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)&&(E2::rank_value==R1)> = 0 >
auto operator+(const MArrayExpR<A,E1,NT1,M1,R1>& x1, const MArrayExpR<B,E2,NT2,M2,R2>& x2) {
  typedef typename AddType<NT1,NT2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;  
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,NT1,M1,R1>,
		     MArrayExpR<B,E2,NT2,M2,R2>,
		     E1,E2,E3,NT1,NT2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<Element,Element,E3,NT1,NT2,D3> >(x1,x2); 
}

    
// MultiArray<NT1,rank,depth> + MultiArray<NT2,rank,1>
// Depending on rank and dimensions, this may be top-level or element wise addition
// Note: M2==1 -> E2==NT2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class NT1, class NT2, int M1, int M2, int rank,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)> = 0  >
auto operator+(const MArrayExpR<A,E1,NT1,M1,rank>& x1, const MArrayExpR<B,NT2,NT2,M2,rank>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::ConcreteType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B,NT2,NT2,M2,rank> E2;  

  typedef typename AddType<NT1,NT2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,NT1,M1,rank>,
		     MArrayExpR<B,NT2,NT2,M2,rank>,
		     E1,NT2,E3,NT1,NT2,D3,M1,M2,M3,rank,rank,rank,
		     FUNCTOR_add<E1,E2,E3,NT1,NT2,D3> >(x1,x2); 
}

// MultiArray<NT1,rank,1> + MultiArray<NT2,rank,depth>
// Depending on rank and dimensions, this may be top-level or element wise addition
// Note: M1==1 -> E1==NT1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class NT1, class NT2, int M1, int M2, int rank,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)> = 0  >
auto operator+(const MArrayExpR<A,NT1,NT1,M1,rank>& x1, const MArrayExpR<B,E2,NT2,M2,rank>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::ConcreteType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A,NT1,NT1,M1,rank> E1;  
  typedef typename AddType<NT1,NT2>::Type D3;
  typedef typename NumberTrait<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A,NT1,NT1,M1,rank>,
		     MArrayExpR<B,E2,NT2,M2,rank>,
		     NT1,E2,E3,NT1,NT2,D3,M1,M2,M3,rank,rank,rank,
		     FUNCTOR_add<E1,E2,E3,NT1,NT2,D3> >(x1,x2); 
}



