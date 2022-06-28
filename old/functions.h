#ifndef MATRICKS__FUNCTIONS_H
#define MATRICKS__FUNCTIONS_H 1


namespace matricks {





  /************************************************************
   *          Functions that apply to all tensors
   ************************************************************
   */


  // ************************************************************************
  // *              Arithmetic
  // ************************************************************************


  // +(MultiArray)

  template <class E, class A, class D, int M> 
    inline auto operator+(const MArrayExpR<E,A,D,M>& a)
  {
    return  TER_Unary< MArrayExpR<E,A,D,M>, Fun_Plus<D> >(a);
  }


  // -(MultiArray)

  template <class D, class A> 
    inline auto operator-(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Minus<D> >(a);
  }


  
  //----------------------------------------------
  // Addition (+)
  //----------------------------------------------

  // MultiArray<D1> + MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator+(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Add<D1,D2>>(a,b);
  }


  // MultiArray<D1> + D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator+(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Add<D1,D2>>(a,b);
    }

  
  // D1 + MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator+(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Add<D1,D2>>(a,b);
    }

    
  // MultiArray<T> + T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator+(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Add<T,T>>(a,b);
    }
    

  // T + MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator+(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Add<T,T>>(a,b);
    }



  //----------------------------------------------
  // Subtraction (-)
  //----------------------------------------------


  // MultiArray<D1> - MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator-(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Subtract<D1,D2>>(a,b);
  }


  // MultiArray<D1> - D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator-(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Subtract<D1,D2>>(a,b);
    }

  
  // D1 - MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator-(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Subtract<D1,D2>>(a,b);
    }

    
  // MultiArray<T> - T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator-(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Subtract<T,T>>(a,b);
    }
    

  // T - MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator-(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Subtract<T,T>>(a,b);
    }
    





  //----------------------------------------------
  // Multiplication (*)
  //----------------------------------------------

  // MultiArray<D1> * MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator*(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Multiply<D1,D2>>(a,b);
  }


  // MultiArray<D1> * D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator*(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Multiply<D1,D2>>(a,b);
    }

  
  // D1 * MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator*(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Multiply<D1,D2>>(a,b);
    }

    
  // MultiArray<T> * T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator*(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Multiply<T,T>>(a,b);
    }
    

  // T * MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator*(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Multiply<T,T>>(a,b);
    }


  //----------------------------------------------
  // Division (/)
  //----------------------------------------------

  // MultiArray<D1> / MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator/(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Divide<D1,D2>>(a,b);
  }


  // MultiArray<D1> / D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator/(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Divide<D1,D2>>(a,b);
    }

  
  // D1 / MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator/(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Divide<D1,D2>>(a,b);
    }

    
  // MultiArray<T> / T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator/(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Divide<T,T>>(a,b);
    }
    

  // T / MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator/(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Divide<T,T>>(a,b);
    }
  




  //**************************************************************************
  // numbercast: cast data from D1 to D2
  //**************************************************************************

  template <class D2, class D1, class A> 
    inline auto numbercast(const MArrayExpR<D1,A>& a)
  {
    return  TER_Unary<D2,MArrayExpR<D1,A>,Fun_Cast<D2,D1> >(a);
  }



  /****************************************************************************
   *  products: Scalar Scalar
   ****************************************************************************
   */

  // --------------------  dot (inner) product --------------------------------
  
  // (a|b)

  // TODO: rewrite for only floating point base types
  template <class D> inline
    D operator|( const Scalar<D>& a, const  Scalar<D>& b ) {
    return a()*b();
  }


  // dot(a,b)

  template <class D> inline
    D dot( const Scalar<D>& a, const  Scalar<D>& b ) {
    return (a|b);
  }


  // --------------------  tensor (outer) product --------------------------------
  
  // (a&b)
  // TODO: rewrite for only floating point base types

  template <class D> inline
    D operator&( const Scalar<D>& a, const  Scalar<D>& b ) {
    return a()*b();
  }


  // tprod(a,b)

  template <class D> inline
    D tprod( const Scalar<D>& a, const  Scalar<D>& b ) {
    return (a&b);
  }


  // -------------------- antisymmetric (wedge)  product -----------------------
  
  // (a^b)
  // TODO: rewrite for only floating point base types

  template <class D> inline
    D operator^( const Scalar<D>& a, const  Scalar<D>& b ) {
    return 0;
  }


  // wprod(a,b)

  template <class D> inline
    D wprod( const Scalar<D>& a, const  Scalar<D>& b ) {
    return (a^b);
  }

  
  /****************************************************************************
   *  products: Vector Vector
   ****************************************************************************
   */


  // --------------------  dot (inner) product --------------------------------

  // (a|b)
  // TODO: rewrite for only floating point base types

  template <class D> inline
    D operator|( const Vector<D>& a, const  Vector<D>& b ) {

    D result = D(0);
    for (size_t i = a.deepsize(); i--;) {
      result += a[i]*b[i];
    }
    return result;
  }

  // dot(a,b)

  template <class D> inline
    D dot( const Vector<D>& a, const  Vector<D>& b ) {
    return (a|b);
  }

  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------

  /****************************************************************************
   *  product: Matrix Matrix
   ****************************************************************************
   */

  // --------------------  dot (inner) product --------------------------------
  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------

  
  /****************************************************************************
   *  product: Matrix Vector
   ****************************************************************************
   */
  // --------------------  dot (inner) product --------------------------------
  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------


  /****************************************************************************
   *  product: MArrayExpR MArrayExpR
   ****************************************************************************
   */
  // --------------------  dot (inner) product --------------------------------


  // (a|b)

  template <class D, class A, class B> inline
    D operator|( const MArrayExpR<D,A>& a, const  MArrayExpR<D,B>& b ) {

    // (Scalar|Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

    // (Vector|Vector)
    if ((a.ndims() == 1) && (b.ndims() == 1)) {
      D result = D(0);
      for (size_t i = a.deepsize(); i--;) {
	result += a[i]*b[i];
      }
      return result;
    }
  }

  // dot(a,b)

  template <class D, class A, class B> inline
    D dot( const MArrayExpR<D,A>& a, const  MArrayExpR<D,B>& b ) {
    return (a|b);
  }

  // --------------------  tensor (outer) product --------------------------------

  // (a&b)

  template <class D, class A, class B> inline
    D operator&( const MArrayExpR<D,A>& a, const  MArrayExpR<D,B>& b ) {

    // (Scalar&Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // tprod(a,b)

  template <class D, class A, class B> inline
    D tprod( const MArrayExpR<D,A>& a, const  MArrayExpR<D,B>& b ) {
    return (a&b);
  }

  // -------------------- antisymmetric (wedge)  product -----------------------

  // (a^b)

  template <class D, class A, class B> inline
    D operator^( const MArrayExpR<D,A>& a, const  MArrayExpR<D,B>& b ) {

    // (Scalar^Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // wprod(a,b)

  template <class D, class A, class B> inline
    D wprod( const MArrayExpR<D,A>& a, const  MArrayExpR<D,B>& b ) {
    return (a^b);
  }
  
  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************


  // pow(MultiArray<D1>,MultiArray<D2>)

  template <class D1, class D2, class A, class B> 
    inline auto pow(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Pow<D1,D2>>(a,b);
  }
  
  
  // pow(MultiArray<D1> , D2)
  
  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto pow(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Pow<D1,D2>>(a,b);
    }
  
  
  // pow(D1 , MultiArray<D2>)
  
  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto pow(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Pow<D1,D2>>(a,b);
    }
  
  
  // pow(MultiArray<T> , T)
  
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto pow(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Pow<T,T>>(a,b);
    }
  
  
  // pow(T , MultiArray<T>)
  
  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto pow(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Pow<T,T>>(a,b);
    }
  

    

  // sqr(MultiArray)

  template <class D, class A> 
    inline auto sqr(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Sqr<D> >(a);
  }

  // cube(MultiArray)

  template <class D, class A> 
    inline auto cube(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Cube<D> >(a);
  }

  // sqrt(MultiArray)

  template <class D, class A> 
    inline auto sqrt(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Sqrt<D> >(a);
  }

  // exp(MultiArray)

  template <class D, class A> 
    inline auto exp(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Exp<D> >(a);
  }



  // log(MultiArray)

  template <class D, class A> 
    inline auto log(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Log<D> >(a);
  }


  // log10(MultiArray)

  template <class D, class A> 
    inline auto log10(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Log10<D> >(a);
  }


  // log2(MultiArray)

  template <class D, class A> 
    inline auto log2(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Log2<D> >(a);
  }






  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************

  // sin(MultiArray)

  template <class D, class A> 
    inline auto sin(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Sin<D> >(a);
  }


  // cos(MultiArray)

  template <class D, class A> 
    inline auto cos(const MArrayExpR<D,A>& a)
  {
    return TER_Unary<D,MArrayExpR<D,A>,Fun_Cos<D> >(a);
  }



  // tan(MultiArray)

  template <class D, class A> 
    inline auto tan(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Tan<D> >(a);
  }


  // asin(MultiArray)

  template <class D, class A> 
    inline auto asin(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Asin<D> >(a);
  }


  // acos(MultiArray)

  template <class D, class A> 
    inline auto acos(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Acos<D> >(a);
  }


  // atan(MultiArray)

  template <class D, class A> 
    inline auto atan(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Atan<D> >(a);
  }


  // atan2(MultiArray,MultiArray)

  // MultiArray<D1> + MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto atan2(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Atan2<D1,D2>>(a,b);
  }
  


  // sinh(MultiArray)

  template <class D, class A> 
    inline auto sinh(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Sinh<D> >(a);
  }


  // cosh(MultiArray)

  template <class D, class A> 
    inline auto cosh(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Cosh<D> >(a);
  }


  // tanh(MultiArray)

  template <class D, class A> 
    inline auto tanh(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Tanh<D> >(a);
  }


  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  // abs(MultiArray)

  template <class D, class A> 
    inline auto abs(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Abs<D> >(a);
  }


  // sgn(MultiArray)

  template <class D, class A> 
    inline auto sgn(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Sgn<D> >(a);
  }



  // ceil(MultiArray)

  template <class D, class A> 
    inline auto ceil(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Ceil<D> >(a);
  }


  // floor(MultiArray)

  template <class D, class A> 
    inline auto floor(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Floor<D> >(a);
  }


  // round(MultiArray)

  template <class D, class A> 
    inline auto round(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D,MArrayExpR<D,A>,Fun_Round<D> >(a);
  }



  // roundzero(MultiArray)

  template <class D1, class A>
     auto roundzero(const MArrayExpR<D1,A>& a, const typename OrderedNumberTrait<D1>::Type tolerance = MatricksHelper< typename OrderedNumberTrait<D1>::Type >::tolerance)
    {
      typedef typename OrderedNumberTrait<D1>::Type TOL;
      return  TER_Binary< MArrayExpR<D1,A>,TOL, D1,TOL, Fun_Roundzero<D1,TOL> >(a, tolerance);
    }
  

  

  // ************************************************************************
  // *              User Defined
  // ************************************************************************


  // user-defined functions
  template <class D, typename FunctionTypes<D>::unary_func F, class A> 
    inline auto op1(const MArrayExpR<D,A>& a)
  {
    return  TER_Unary<D, MArrayExpR<D,A>, Fun_UnaryUser<D,F> >(a);
  }

  template <class D, typename FunctionTypes<D>::binary_func F, class A, class B> 
    inline auto op2(const MArrayExpR<D,A>& a, const MArrayExpR<D,B>& b)
  {
    return  TER_Binary<MArrayExpR<D,A>,MArrayExpR<D,B>, D,D, Fun_BinaryUser<D,D,F>>(a,b);
  }


  


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************

  //----------------------------------------------
  // logical NOT (!)
  //----------------------------------------------
   

  // !(MultiArray)

  template <class A> 
    inline auto operator!(const MArrayExpR<bool,A>& a)
    {
      return  TER_Unary<bool,MArrayExpR<bool,A>,Fun_Not >(a);
    }
  


  //----------------------------------------------
  // logical AND (&&)
  //----------------------------------------------
  
  // MultiArray<D1> && MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator&&(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_And<D1,D2>>(a,b);
  }


  // MultiArray<D1> && bool

  template <class D1, class A> 
    inline auto operator&&(const MArrayExpR<D1,A>& a, const bool& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,bool,D1,bool,Fun_And<D1,bool>>(a,b);
    }

  
  // bool && MultiArray<D2>

  template <class D2, class B>
    inline auto operator&&(const bool& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<bool,MArrayExpR<D2,B>,bool,D2,Fun_And<bool,D2>>(a,b);
    }

    
  // MultiArray<T> && T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator&&(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_And<T,T>>(a,b);
    }
    

  // T && MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator&&(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_And<T,T>>(a,b);
    }




    
  //----------------------------------------------
  // logical OR (||)
  //----------------------------------------------
    
  
  // MultiArray<D1> || MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator||(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Or<D1,D2>>(a,b);
  }


  // MultiArray<D1> || bool

  template <class D1, class A> 
    inline auto operator||(const MArrayExpR<D1,A>& a, const bool& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,bool,D1,bool,Fun_Or<D1,bool>>(a,b);
    }

  
  // bool || MultiArray<D2>

  template <class D2, class B>
    inline auto operator||(const bool& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<bool,MArrayExpR<D2,B>,bool,D2,Fun_Or<bool,D2>>(a,b);
    }

    
  // MultiArray<T> || T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator||(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Or<T,T>>(a,b);
    }
    

  // T || MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator||(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Or<T,T>>(a,b);
    }

  
  
  // ************************************************************************
  // *              Relational ops (return a bool MultiArray from two D MultiArrays)
  // ************************************************************************


  //----------------------------------------------
  // equal (==)
  //----------------------------------------------

  // MultiArray<D1> == MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator==(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Equal<D1,D2>>(a,b);
  }


  // MultiArray<D1> == D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator==(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Equal<D1,D2>>(a,b);
    }

  
  // D1 == MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator==(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Equal<D1,D2>>(a,b);
    }

    
  // MultiArray<T> == T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator==(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Equal<T,T>>(a,b);
    }
    

  // T == MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator==(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Equal<T,T>>(a,b);
    }

  //----------------------------------------------
  // not equal (!=)
  //----------------------------------------------

  // MultiArray<D1> != MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator!=(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_NotEqual<D1,D2>>(a,b);
  }


  // MultiArray<D1> != D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator!=(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_NotEqual<D1,D2>>(a,b);
    }

  
  // D1 != MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator!=(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_NotEqual<D1,D2>>(a,b);
    }

    
  // MultiArray<T> != T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator!=(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_NotEqual<T,T>>(a,b);
    }
    

  // T != MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator!=(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_NotEqual<T,T>>(a,b);
    }


  //----------------------------------------------
  // less than or equal (<=)
  //----------------------------------------------

  // MultiArray<D1> <= MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator<=(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_LessOrEqual<D1,D2>>(a,b);
  }


  // MultiArray<D1> <= D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator<=(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_LessOrEqual<D1,D2>>(a,b);
    }

  
  // D1 <= MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator<=(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_LessOrEqual<D1,D2>>(a,b);
    }

    
  // MultiArray<T> <= T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator<=(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_LessOrEqual<T,T>>(a,b);
    }
    

  // T <= MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator<=(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_LessOrEqual<T,T>>(a,b);
    }
    

  //----------------------------------------------
  // less than or equal (>=)
  //----------------------------------------------

  // MultiArray<D1> >= MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator>=(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_GreaterOrEqual<D1,D2>>(a,b);
  }


  // MultiArray<D1> >= D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator>=(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_GreaterOrEqual<D1,D2>>(a,b);
    }

  
  // D1 >= MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator>=(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_GreaterOrEqual<D1,D2>>(a,b);
    }

    
  // MultiArray<T> >= T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator>=(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_GreaterOrEqual<T,T>>(a,b);
    }
    

  // T >= MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator>=(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_GreaterOrEqual<T,T>>(a,b);
    }


  //----------------------------------------------
  // less than (<)
  //----------------------------------------------

  // MultiArray<D1> < MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator<(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Less<D1,D2>>(a,b);
  }


  // MultiArray<D1> < D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator<(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Less<D1,D2>>(a,b);
    }

  
  // D1 < MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator<(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Less<D1,D2>>(a,b);
    }

    
  // MultiArray<T> < T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator<(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Less<T,T>>(a,b);
    }
    

  // T < MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator<(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Less<T,T>>(a,b);
    }
    
  //----------------------------------------------
  // greater than (>)
  //----------------------------------------------

  // MultiArray<D1> > MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator>(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  {
    return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_Greater<D1,D2>>(a,b);
  }


  // MultiArray<D1> > D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline auto operator>(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<MArrayExpR<D1,A>,D2,D1,D2,Fun_Greater<D1,D2>>(a,b);
    }

  
  // D1 > MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline auto operator>(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_Binary<D1,MArrayExpR<D2,B>,D1,D2,Fun_Greater<D1,D2>>(a,b);
    }

    
  // MultiArray<T> > T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator>(const MArrayExpR<T,A>& a, const T& b)
    {
      return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_Greater<T,T>>(a,b);
    }
    

  // T > MultiArray<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
    inline auto operator>(const T& a, const MArrayExpR<T,B>& b)
    {
      return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_Greater<T,T>>(a,b);
    }

    
  // ************************************************************************
  // *           Other functions related to equality
  // ************************************************************************

    

  // approxel(a,b,tol) - element wise
  
  template <class D1, class D2, class D3, class A, class B> 
    inline auto approxel(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b, const D3 tol = MatricksHelper<D3>::tolerance)
  {
    return  TER_Ternary< MArrayExpR<D1,A>,MArrayExpR<D2,B>,D3, D1,D2,D3, Fun_Approx<D1,D2,D3> >(a,b,tol);
  }


  
  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <class D, class A, class B>
    inline bool equal(const MArrayExpR<D,A>& tensor1, const MArrayExpR<D,B>& tensor2) {
    if (!dimequiv(tensor1,tensor2)) {
      return false;
    }
    for (int ii = 0; ii < tensor1.deepsize(); ii++) {
      if (tensor1[ii] != tensor2[ii]) {
	return false;
      }
    }
    return true;
  }


  // -------------------------------------------------------------------
  // approx - if two tensors are approximately equal, returns a single bool
  //          checks dimensions first
  // -------------------------------------------------------------------
  template <class D, class A, class B>
    inline bool approx(const MArrayExpR<D,A>& tensor1, const MArrayExpR<D,B>& tensor2, typename OrderedNumberTrait<D>::Type tolerance = MatricksHelper<typename OrderedNumberTrait<D>::Type>::tolerance) {
    if (!dimequiv(tensor1,tensor2)) {
      return false;
    }
    for (int ii = 0; ii < tensor1.deepsize(); ii++) {
      if (!approx(tensor1[ii], tensor2[ii], tolerance)) {
	return false;
      }
    }
    return true;
  }




  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
    D sum( const MArrayExpR<D,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }



  
  // prod(a)

  template <class D, class A> 
    D prod( const MArrayExpR<D,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result *= a[i];
    
    return result;
  }





  // norm(a)

  template <class D, class A> 
    D norm( const MArrayExpR<D,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0]*a[0];

    for (size_t i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <class D, class A> 
    D min( const MArrayExpR<D,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <class D, class A> 
    D max( const MArrayExpR<D,A>& a ) {
    
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result = std::max(result,a[i]);
    
    return result;
  }







  
  /****************************************************************************
   * Unary Functions/Operators that bools or size_t MultiArrays
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class D, class A> 
    inline bool alltrue( const MArrayExpR<D,A>& a ) {
    bool result = true;
    
 
    for (size_t i = 0; i< a.deepsize(); i++)
      result = result && a.dat(i);
    
    return result;
  }


  // anytrue(a)

  template <class D, class A> 
    inline bool anytrue( const MArrayExpR<D,A>& a ) {
    bool result = false;
    
 
    for (size_t i = 0; i< a.deepsize(); i++)
      result = result || a.dat(i);
    
    return result;
  }


  // numtrue(a)

  template <class D, class A> 
    inline size_t numtrue( const MArrayExpR<D,A>& a ) {
    size_t result = 0;
    
 
    for (size_t i = 0; i< a.deepsize(); i++)
      result += static_cast<size_t>(a.dat(i));
    
    return result;
  }


  


  // findtrue(a)

  // NOTE: declaration in preface.h
  
  template <class A> 
    inline Vector<size_t>& findtrue( const MArrayExpR<bool,A>& a ) {
    int N = 0;
    TLDISP(a);

    for (size_t i = 0; i< a.size(); i++)
      N += int(a[i]);
 
    Vector<size_t> *y = new Vector<size_t>(N);

    size_t j =0;
    for (size_t i = 0; i< a.size(); i++)
      if (a[i])
	(*y)[j++] = i;
    
    return *y;
  }

    
  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************


  // real(MultiArray)

  template <class D, class A> 
    inline auto real(const MArrayExpR<D,A>& a)
  {
    return TER_Unary<typename Realify<D>::Type, MArrayExpR<D,A>, Fun_Real<D> >(a);
  }

  // imag(MultiArray)

  template <class D, class A> 
    inline auto imag(const MArrayExpR<D,A>& a)
  {
    return TER_Unary<typename Realify<D>::Type, MArrayExpR<D,A>, Fun_Imag<D> >(a);
  }


  // conj(MultiArray)

  template <class D, class A> 
    inline auto conj(const MArrayExpR<D,A>& a)
  {
    return TER_Unary<typename Complexify<D>::Type, MArrayExpR<D,A>, Fun_Conj<D> >(a);
  }


  
  // transpose(A) 

  template <class D, class A> 
    inline auto transpose(MArrayExpRW<D,A>& a)
  {
    return TERW_Transpose<D,MArrayExpRW<D,A>,Fun_Plus<D> >(a);
  }

  // adjoint(A) - conjugate transpose 

  template <class D, class A> 
    inline auto adjoint(const MArrayExpR<D,A>& a)
  {
    return  TER_Transpose<D,MArrayExpR<D,A>,Fun_Conj<D> >(a);
  }

  
  // ~A conjugate transpose operator

  template <class D, class A> 
    inline auto operator~(const MArrayExpR<D,A>& a)
  {
    return  TER_Transpose<D,MArrayExpR<D,A>,Fun_Conj<D> >(a);
  }










  // operator, (join)


  template <class D> 
    inline auto operator,(Vector<D>& a, Vector<D>& b)
    {
    
      PRINTF2("  VERW_Join operator,(Vector<D>& a, Vector<D>& b)\n");
      return  VERW_Join<D,Vector<D>,Vector<D> >(a,b);
    }

  //--------------------------------------------
  // Need the const for compiler to find this
  // then we cast away the const
  template <class D, class A> 
    inline auto operator,(const MArrayExpRW<D,A>& a, const Vector<D>& b)
    {
      PRINTF2("  VERW_Join operator,(const MArrayExpRW<D,A>& a, const Vector<D>& b)\n");
      MArrayExpRW<D,A>& a_ = const_cast<MArrayExpRW<D,A>& >(a);
      Vector<D>& b_ = const_cast<Vector<D>& >(b);
      return  VERW_Join<D, MArrayExpRW<D,A>,Vector<D> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  // then we cast away the const
  template <class D, class B> 
    inline auto operator,(const Vector<D>& a, const MArrayExpRW<D,B>& b)
    {
      PRINTF2("  VERW_Join operator,(const Vector<D>& a, const MArrayExpRW<D,B>& b)\n");
      Vector<D>& a_ = const_cast<Vector<D>& >(a);
      MArrayExpRW<D,B>& b_ = const_cast<MArrayExpRW<D,B>& >(b);
      return VERW_Join<D, Vector<D>,MArrayExpRW<D,B> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  template <class D, class A, class B> 
    inline auto operator,(const MArrayExpRW<D,A>& a, const MArrayExpRW<D,B>& b)
    {
      PRINTF2("  VERW_Join operator,(const MArrayExpRW<D,A>& a, const MArrayExpRW<D,B>& b)\n");
      MArrayExpRW<D,A>& a_ = const_cast<MArrayExpRW<D,A>& >(a);
      MArrayExpRW<D,B>& b_ = const_cast<MArrayExpRW<D,B>& >(b);
      return  VERW_Join<D, MArrayExpRW<D,A>,MArrayExpRW<D,B> >(a_,b_);
    }
  //--------------------------------------------


  
  ///---------
  
  template <class D> 
    inline const auto operator,(const Vector<D>& a, const Vector<D>& b)
    {
      PRINTF2("  VER_Join operator,(const Vector<D>& a, const Vector<D>& b)\n");
      return  VER_Join<D,Vector<D>,Vector<D> >(a,b);
    }

  template <class D, class B> 
    inline const auto operator,(const Vector<D>& a, const MArrayExpR<D,B>& b)
    {
      PRINTF2("  VER_Join operator,(const Vector<D>& a, const MArrayExpR<D,B>& b)\n");
      return  VER_Join<D,Vector<D>,MArrayExpR<D,B>  >(a,b);
    }

  template <class D, class A> 
    inline const auto operator,(const MArrayExpR<D,A>& a, const Vector<D>& b)
    {
      PRINTF2("  VER_Join operator,(const MArrayExpR<D,A>& a, const Vector<D>& b)\n");
      return  VER_Join<D,MArrayExpR<D,A>,Vector<D> >(a,b);
    }
 
  template <class D, class A, class B> 
    inline const auto operator,(const MArrayExpR<D,A>& a, const MArrayExpR<D,B>& b)
    {
      PRINTF2("  VER_Join operator,(const MArrayExpR<D,A>& a, const MArrayExpR<D,B>& b)\n");
      return  VER_Join<D, MArrayExpR<D,A>,MArrayExpR<D,B> >(a,b);
    }






  // rep(v,m)

  template <class D, class A> 
    inline auto rep(const MArrayExpR<D,A>& a, const size_t m) {
    return VER_Rep<D,MArrayExpR<D,A> >(a,m);
  }

  
 

  


  /****************************************************************
   * functions that convert vectors into other objects
   *****************************************************************
   */


  // toCarray(v)

  template <class D2, class D1, class A> 
    inline D2* toCarray(const MArrayExpR<D1,A>& v) {
    const size_t N = v.size();
    D2* dptr = new D2[N];
    for(size_t i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(v[i]);
    return  dptr;
  }

  

  // tostdvector(v)

  template <class D2, class D1, class A> 
    inline std::vector<D2>
    tostdvector(const MArrayExpR<D1,A>& v) {
    const size_t N = v.size();
    std::vector<D2> y(N);
    for(size_t i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  // tovalarray(v)

  template <class D2, class D1, class A> 
    inline std::valarray<D2>
    tovalarray(const MArrayExpR<D1,A>& v) {
    const size_t N = v.size();
    std::valarray<D2> y(N);
    for(size_t i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  

};

#endif 
