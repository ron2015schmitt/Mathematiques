  
//----------------------------------------------
// Addition (+)
//----------------------------------------------

// Tensor<E1(D1)> + Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator+(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// Tensor<E(D1)> + D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator+(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_add<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// D1 + Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator+(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_add<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// element-wise addition: x1[i] + x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator+(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// element-wise addition: x1 + x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator+(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// Tensor<D1,R,M> + Tensor<D2,R,1>
// Depending on rank and dimensions, this may be top-level or element wise addition
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator+(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// Tensor<D1,R,1> + Tensor<D2,R,M>
// Depending on rank and dimensions, this may be top-level or element wise addition
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator+(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}



