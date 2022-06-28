#ifndef MATHQ__FUN_BINARY_OPS_AUTO_H
#define MATHQ__FUN_BINARY_OPS_AUTO_H 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT 'fun_binary_ops.py'

namespace mathq { 



//********************************************************************
//--------------------------------------------------------------------
//                           Functors
//--------------------------------------------------------------------
//********************************************************************


  
// ----------------------------------------------------------------
// FUNCTOR_add: template class for operator '+'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_add { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 + d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 + e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 + d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 + e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" + "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_add)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_subtract: template class for operator '-'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_subtract { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 - d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 - e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 - d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 - e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" - "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_subtract)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_multiply: template class for operator '*'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_multiply { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 * d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 * e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 * d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 * e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" * "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_multiply)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_divide: template class for operator '/'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_divide { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 / d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 / e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 / d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 / e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" / "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_divide)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};




//********************************************************************
//--------------------------------------------------------------------
//                           Functions
//--------------------------------------------------------------------
//********************************************************************




// ----------------------------------------------------------------
// Addition
// template function classes for operator '+'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Addition (+)
//----------------------------------------------

// (1) MultiArray<E1(D1)> + MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int Depth, int R> 
auto operator+(const MArrayExpR<A,E1,D1,Depth,R>& x1, const MArrayExpR<B,E2,D2,Depth,R>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A,E1,D1,Depth,R>,
		     MArrayExpR<B,E2,D2,Depth,R>,
		     E1,E2,E3,D1,D2,D3,Depth,Depth,Depth,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) MultiArray<Element(D1)> + D2

template <class A, class D2, class Element, class D1, int Depth, int R, typename = std::enable_if_t<NumberTrait<D2>::value>> 
auto operator+(const MArrayExpR<A,Element,D1,Depth,R>& x1, const D2& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<MArrayExpR<A,Element,D1,Depth,R>,
		     D2,
		     Element,Null,E3,D1,D2,D3,Depth,0,Depth,R,R,R,
		     FUNCTOR_add<Element,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 + MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int Depth, int R, typename = std::enable_if_t<NumberTrait<D1>::value>> 
auto operator+(const D1& x1, const MArrayExpR<B,Element,D2,Depth,R>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     MArrayExpR<B,Element,D2,Depth,R>,
		     Null,Element,E3,D1,D2,D3,0,Depth,Depth,R,R,R,
		     FUNCTOR_add<Null,Element,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Addition: x1[i] + x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator+(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Addition: x1 + x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator+(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;  
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) MultiArray<D1,R,Depth> + MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)> = 0  >
auto operator+(const MArrayExpR<A,E1,D1,M1,R>& x1, const MArrayExpR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B,D2,D2,M2,R> E2;  

  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R>,
		     MArrayExpR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) MultiArray<D1,R,1> + MultiArray<D2,R,Depth>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)> = 0  >
auto operator+(const MArrayExpR<A,D1,D1,M1,R>& x1, const MArrayExpR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A,D1,D1,M1,R> E1;  
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberTrait<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A,D1,D1,M1,R>,
		     MArrayExpR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Subtraction
// template function classes for operator '-'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Subtraction (-)
//----------------------------------------------

// (1) MultiArray<E1(D1)> - MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int Depth, int R> 
auto operator-(const MArrayExpR<A,E1,D1,Depth,R>& x1, const MArrayExpR<B,E2,D2,Depth,R>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A,E1,D1,Depth,R>,
		     MArrayExpR<B,E2,D2,Depth,R>,
		     E1,E2,E3,D1,D2,D3,Depth,Depth,Depth,R,R,R,
		     FUNCTOR_subtract<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) MultiArray<Element(D1)> - D2

template <class A, class D2, class Element, class D1, int Depth, int R, typename = std::enable_if_t<NumberTrait<D2>::value>> 
auto operator-(const MArrayExpR<A,Element,D1,Depth,R>& x1, const D2& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<MArrayExpR<A,Element,D1,Depth,R>,
		     D2,
		     Element,Null,E3,D1,D2,D3,Depth,0,Depth,R,R,R,
		     FUNCTOR_subtract<Element,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 - MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int Depth, int R, typename = std::enable_if_t<NumberTrait<D1>::value>> 
auto operator-(const D1& x1, const MArrayExpR<B,Element,D2,Depth,R>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     MArrayExpR<B,Element,D2,Depth,R>,
		     Null,Element,E3,D1,D2,D3,0,Depth,Depth,R,R,R,
		     FUNCTOR_subtract<Null,Element,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Subtraction: x1[i] - x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator-(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_subtract<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Subtraction: x1 - x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator-(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;  
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_subtract<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) MultiArray<D1,R,Depth> - MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)> = 0  >
auto operator-(const MArrayExpR<A,E1,D1,M1,R>& x1, const MArrayExpR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B,D2,D2,M2,R> E2;  

  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R>,
		     MArrayExpR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_subtract<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) MultiArray<D1,R,1> - MultiArray<D2,R,Depth>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)> = 0  >
auto operator-(const MArrayExpR<A,D1,D1,M1,R>& x1, const MArrayExpR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A,D1,D1,M1,R> E1;  
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberTrait<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A,D1,D1,M1,R>,
		     MArrayExpR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_subtract<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Multiplication
// template function classes for operator '*'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Multiplication (*)
//----------------------------------------------

// (1) MultiArray<E1(D1)> * MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int Depth, int R> 
auto operator*(const MArrayExpR<A,E1,D1,Depth,R>& x1, const MArrayExpR<B,E2,D2,Depth,R>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A,E1,D1,Depth,R>,
		     MArrayExpR<B,E2,D2,Depth,R>,
		     E1,E2,E3,D1,D2,D3,Depth,Depth,Depth,R,R,R,
		     FUNCTOR_multiply<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) MultiArray<Element(D1)> * D2

template <class A, class D2, class Element, class D1, int Depth, int R, typename = std::enable_if_t<NumberTrait<D2>::value>> 
auto operator*(const MArrayExpR<A,Element,D1,Depth,R>& x1, const D2& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<MArrayExpR<A,Element,D1,Depth,R>,
		     D2,
		     Element,Null,E3,D1,D2,D3,Depth,0,Depth,R,R,R,
		     FUNCTOR_multiply<Element,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 * MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int Depth, int R, typename = std::enable_if_t<NumberTrait<D1>::value>> 
auto operator*(const D1& x1, const MArrayExpR<B,Element,D2,Depth,R>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     MArrayExpR<B,Element,D2,Depth,R>,
		     Null,Element,E3,D1,D2,D3,0,Depth,Depth,R,R,R,
		     FUNCTOR_multiply<Null,Element,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Multiplication: x1[i] * x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator*(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_multiply<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Multiplication: x1 * x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator*(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;  
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_multiply<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) MultiArray<D1,R,Depth> * MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)> = 0  >
auto operator*(const MArrayExpR<A,E1,D1,M1,R>& x1, const MArrayExpR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B,D2,D2,M2,R> E2;  

  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R>,
		     MArrayExpR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_multiply<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) MultiArray<D1,R,1> * MultiArray<D2,R,Depth>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)> = 0  >
auto operator*(const MArrayExpR<A,D1,D1,M1,R>& x1, const MArrayExpR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A,D1,D1,M1,R> E1;  
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberTrait<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A,D1,D1,M1,R>,
		     MArrayExpR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_multiply<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Division
// template function classes for operator '/'
//
//    Note: generated from template file 'fun_binary_op_functor.h'
//          using Python script 'fun_binary_ops.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Division (/)
//----------------------------------------------

// (1) MultiArray<E1(D1)> / MultiArray<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int Depth, int R> 
auto operator/(const MArrayExpR<A,E1,D1,Depth,R>& x1, const MArrayExpR<B,E2,D2,Depth,R>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<MArrayExpR<A,E1,D1,Depth,R>,
		     MArrayExpR<B,E2,D2,Depth,R>,
		     E1,E2,E3,D1,D2,D3,Depth,Depth,Depth,R,R,R,
		     FUNCTOR_divide<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) MultiArray<Element(D1)> / D2

template <class A, class D2, class Element, class D1, int Depth, int R, typename = std::enable_if_t<NumberTrait<D2>::value>> 
auto operator/(const MArrayExpR<A,Element,D1,Depth,R>& x1, const D2& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<MArrayExpR<A,Element,D1,Depth,R>,
		     D2,
		     Element,Null,E3,D1,D2,D3,Depth,0,Depth,R,R,R,
		     FUNCTOR_divide<Element,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 / MultiArray<Element(D2)>

template <class D1, class B, class Element, class D2, int Depth, int R, typename = std::enable_if_t<NumberTrait<D1>::value>> 
auto operator/(const D1& x1, const MArrayExpR<B,Element,D2,Depth,R>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     MArrayExpR<B,Element,D2,Depth,R>,
		     Null,Element,E3,D1,D2,D3,0,Depth,Depth,R,R,R,
		     FUNCTOR_divide<Null,Element,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Division: x1[i] / x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator/(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef E1 Element;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;
  //    MOUT << "A" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_divide<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Division: x1 / x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator/(const MArrayExpR<A,E1,D1,M1,R1>& x1, const MArrayExpR<B,E2,D2,M2,R2>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef E2 Element;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberTrait<Element,D3>::ReplaceTypeE E3;  
  //    MOUT << "B" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R1>,
		     MArrayExpR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_divide<Element,Element,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) MultiArray<D1,R,Depth> / MultiArray<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<MultiArrayAbstract,E1>::value)> = 0  >
auto operator/(const MArrayExpR<A,E1,D1,M1,R>& x1, const MArrayExpR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef MArrayExpR<B,D2,D2,M2,R> E2;  

  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberTrait<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    MOUT << "C" <<std::endl;
  return  TER_Binary<MArrayExpR<A,E1,D1,M1,R>,
		     MArrayExpR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_divide<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) MultiArray<D1,R,1> / MultiArray<D2,R,Depth>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<MultiArrayAbstract,E2>::value)> = 0  >
auto operator/(const MArrayExpR<A,D1,D1,M1,R>& x1, const MArrayExpR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef MArrayExpR<A,D1,D1,M1,R> E1;  
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberTrait<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    MOUT << "Number" <<std::endl;
  return  TER_Binary<MArrayExpR<A,D1,D1,M1,R>,
		     MArrayExpR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_divide<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}



}; // namespace mathq 
#endif // MATHQ__FUN_BINARY_OPS_AUTO_H