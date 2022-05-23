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


  // +(Tensor)

  template <class E, class A, class D, int M> 
    inline auto operator+(const TensorR<E,A,D,M>& a)
  {
    return  TER_Unary< TensorR<E,A,D,M>, Fun_Plus<D> >(a);
  }


  // -(Tensor)

  template <class D, class A> 
    inline auto operator-(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Minus<D> >(a);
  }


  
  //----------------------------------------------
  // Addition (+)
  //----------------------------------------------

  // Tensor<D1> + Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator+(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Add<D1,D2>>(a,b);
  }


  // Tensor<D1> + D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator+(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Add<D1,D2>>(a,b);
    }

  
  // D1 + Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator+(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Add<D1,D2>>(a,b);
    }

    
  // Tensor<T> + T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator+(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Add<T,T>>(a,b);
    }
    

  // T + Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator+(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Add<T,T>>(a,b);
    }



  //----------------------------------------------
  // Subtraction (-)
  //----------------------------------------------


  // Tensor<D1> - Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator-(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Subtract<D1,D2>>(a,b);
  }


  // Tensor<D1> - D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator-(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Subtract<D1,D2>>(a,b);
    }

  
  // D1 - Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator-(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Subtract<D1,D2>>(a,b);
    }

    
  // Tensor<T> - T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator-(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Subtract<T,T>>(a,b);
    }
    

  // T - Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator-(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Subtract<T,T>>(a,b);
    }
    





  //----------------------------------------------
  // Multiplication (*)
  //----------------------------------------------

  // Tensor<D1> * Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator*(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Multiply<D1,D2>>(a,b);
  }


  // Tensor<D1> * D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator*(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Multiply<D1,D2>>(a,b);
    }

  
  // D1 * Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator*(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Multiply<D1,D2>>(a,b);
    }

    
  // Tensor<T> * T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator*(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Multiply<T,T>>(a,b);
    }
    

  // T * Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator*(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Multiply<T,T>>(a,b);
    }


  //----------------------------------------------
  // Division (/)
  //----------------------------------------------

  // Tensor<D1> / Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator/(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Divide<D1,D2>>(a,b);
  }


  // Tensor<D1> / D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator/(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Divide<D1,D2>>(a,b);
    }

  
  // D1 / Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator/(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Divide<D1,D2>>(a,b);
    }

    
  // Tensor<T> / T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator/(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Divide<T,T>>(a,b);
    }
    

  // T / Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator/(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Divide<T,T>>(a,b);
    }
  




  //**************************************************************************
  // numbercast: cast data from D1 to D2
  //**************************************************************************

  template <class D2, class D1, class A> 
    inline auto numbercast(const TensorR<D1,A>& a)
  {
    return  TER_Unary<D2,TensorR<D1,A>,Fun_Cast<D2,D1> >(a);
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
    for (index_type i = a.deepsize(); i--;) {
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
   *  product: TensorR TensorR
   ****************************************************************************
   */
  // --------------------  dot (inner) product --------------------------------


  // (a|b)

  template <class D, class A, class B> inline
    D operator|( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar|Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

    // (Vector|Vector)
    if ((a.ndims() == 1) && (b.ndims() == 1)) {
      D result = D(0);
      for (index_type i = a.deepsize(); i--;) {
	result += a[i]*b[i];
      }
      return result;
    }
  }

  // dot(a,b)

  template <class D, class A, class B> inline
    D dot( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return (a|b);
  }

  // --------------------  tensor (outer) product --------------------------------

  // (a&b)

  template <class D, class A, class B> inline
    D operator&( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar&Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // tprod(a,b)

  template <class D, class A, class B> inline
    D tprod( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return (a&b);
  }

  // -------------------- antisymmetric (wedge)  product -----------------------

  // (a^b)

  template <class D, class A, class B> inline
    D operator^( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar^Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // wprod(a,b)

  template <class D, class A, class B> inline
    D wprod( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return (a^b);
  }
  
  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************


  // pow(Tensor<D1>,Tensor<D2>)

  template <class D1, class D2, class A, class B> 
    inline auto pow(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Pow<D1,D2>>(a,b);
  }
  
  
  // pow(Tensor<D1> , D2)
  
  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto pow(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Pow<D1,D2>>(a,b);
    }
  
  
  // pow(D1 , Tensor<D2>)
  
  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto pow(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Pow<D1,D2>>(a,b);
    }
  
  
  // pow(Tensor<T> , T)
  
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto pow(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Pow<T,T>>(a,b);
    }
  
  
  // pow(T , Tensor<T>)
  
  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto pow(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Pow<T,T>>(a,b);
    }
  

    

  // sqr(Tensor)

  template <class D, class A> 
    inline auto sqr(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Sqr<D> >(a);
  }

  // cube(Tensor)

  template <class D, class A> 
    inline auto cube(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Cube<D> >(a);
  }

  // sqrt(Tensor)

  template <class D, class A> 
    inline auto sqrt(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Sqrt<D> >(a);
  }

  // exp(Tensor)

  template <class D, class A> 
    inline auto exp(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Exp<D> >(a);
  }



  // log(Tensor)

  template <class D, class A> 
    inline auto log(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Log<D> >(a);
  }


  // log10(Tensor)

  template <class D, class A> 
    inline auto log10(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Log10<D> >(a);
  }


  // log2(Tensor)

  template <class D, class A> 
    inline auto log2(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Log2<D> >(a);
  }






  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************

  // sin(Tensor)

  template <class D, class A> 
    inline auto sin(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Sin<D> >(a);
  }


  // cos(Tensor)

  template <class D, class A> 
    inline auto cos(const TensorR<D,A>& a)
  {
    return TER_Unary<D,TensorR<D,A>,Fun_Cos<D> >(a);
  }



  // tan(Tensor)

  template <class D, class A> 
    inline auto tan(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Tan<D> >(a);
  }


  // asin(Tensor)

  template <class D, class A> 
    inline auto asin(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Asin<D> >(a);
  }


  // acos(Tensor)

  template <class D, class A> 
    inline auto acos(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Acos<D> >(a);
  }


  // atan(Tensor)

  template <class D, class A> 
    inline auto atan(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Atan<D> >(a);
  }


  // atan2(Tensor,Tensor)

  // Tensor<D1> + Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto atan2(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Atan2<D1,D2>>(a,b);
  }
  


  // sinh(Tensor)

  template <class D, class A> 
    inline auto sinh(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Sinh<D> >(a);
  }


  // cosh(Tensor)

  template <class D, class A> 
    inline auto cosh(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Cosh<D> >(a);
  }


  // tanh(Tensor)

  template <class D, class A> 
    inline auto tanh(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Tanh<D> >(a);
  }


  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  // abs(Tensor)

  template <class D, class A> 
    inline auto abs(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Abs<D> >(a);
  }


  // sgn(Tensor)

  template <class D, class A> 
    inline auto sgn(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Sgn<D> >(a);
  }



  // ceil(Tensor)

  template <class D, class A> 
    inline auto ceil(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Ceil<D> >(a);
  }


  // floor(Tensor)

  template <class D, class A> 
    inline auto floor(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Floor<D> >(a);
  }


  // round(Tensor)

  template <class D, class A> 
    inline auto round(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Round<D> >(a);
  }



  // roundzero(Tensor)

  template <class D1, class A>
     auto roundzero(const TensorR<D1,A>& a, const typename FundamentalType<D1>::Type tolerance = MatricksHelper< typename FundamentalType<D1>::Type >::tolerance)
    {
      typedef typename FundamentalType<D1>::Type TOL;
      return  TER_Binary< TensorR<D1,A>,TOL, D1,TOL, Fun_Roundzero<D1,TOL> >(a, tolerance);
    }
  

  

  // ************************************************************************
  // *              User Defined
  // ************************************************************************


  // user-defined functions
  template <class D, typename FunctionTypes<D>::unary_func F, class A> 
    inline auto op1(const TensorR<D,A>& a)
  {
    return  TER_Unary<D, TensorR<D,A>, Fun_UnaryUser<D,F> >(a);
  }

  template <class D, typename FunctionTypes<D>::binary_func F, class A, class B> 
    inline auto op2(const TensorR<D,A>& a, const TensorR<D,B>& b)
  {
    return  TER_Binary<TensorR<D,A>,TensorR<D,B>, D,D, Fun_BinaryUser<D,D,F>>(a,b);
  }


  


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************

  //----------------------------------------------
  // logical NOT (!)
  //----------------------------------------------
   

  // !(Tensor)

  template <class A> 
    inline auto operator!(const TensorR<bool,A>& a)
    {
      return  TER_Unary<bool,TensorR<bool,A>,Fun_Not >(a);
    }
  


  //----------------------------------------------
  // logical AND (&&)
  //----------------------------------------------
  
  // Tensor<D1> && Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator&&(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_And<D1,D2>>(a,b);
  }


  // Tensor<D1> && bool

  template <class D1, class A> 
    inline auto operator&&(const TensorR<D1,A>& a, const bool& b)
    {
      return  TER_Binary<TensorR<D1,A>,bool,D1,bool,Fun_And<D1,bool>>(a,b);
    }

  
  // bool && Tensor<D2>

  template <class D2, class B>
    inline auto operator&&(const bool& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<bool,TensorR<D2,B>,bool,D2,Fun_And<bool,D2>>(a,b);
    }

    
  // Tensor<T> && T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator&&(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_And<T,T>>(a,b);
    }
    

  // T && Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator&&(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_And<T,T>>(a,b);
    }




    
  //----------------------------------------------
  // logical OR (||)
  //----------------------------------------------
    
  
  // Tensor<D1> || Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator||(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Or<D1,D2>>(a,b);
  }


  // Tensor<D1> || bool

  template <class D1, class A> 
    inline auto operator||(const TensorR<D1,A>& a, const bool& b)
    {
      return  TER_Binary<TensorR<D1,A>,bool,D1,bool,Fun_Or<D1,bool>>(a,b);
    }

  
  // bool || Tensor<D2>

  template <class D2, class B>
    inline auto operator||(const bool& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<bool,TensorR<D2,B>,bool,D2,Fun_Or<bool,D2>>(a,b);
    }

    
  // Tensor<T> || T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator||(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Or<T,T>>(a,b);
    }
    

  // T || Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator||(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Or<T,T>>(a,b);
    }

  
  
  // ************************************************************************
  // *              Relational ops (return a bool Tensor from two D Tensors)
  // ************************************************************************


  //----------------------------------------------
  // equal (==)
  //----------------------------------------------

  // Tensor<D1> == Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator==(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Equal<D1,D2>>(a,b);
  }


  // Tensor<D1> == D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator==(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Equal<D1,D2>>(a,b);
    }

  
  // D1 == Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator==(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Equal<D1,D2>>(a,b);
    }

    
  // Tensor<T> == T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator==(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Equal<T,T>>(a,b);
    }
    

  // T == Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator==(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Equal<T,T>>(a,b);
    }

  //----------------------------------------------
  // not equal (!=)
  //----------------------------------------------

  // Tensor<D1> != Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator!=(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_NotEqual<D1,D2>>(a,b);
  }


  // Tensor<D1> != D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator!=(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_NotEqual<D1,D2>>(a,b);
    }

  
  // D1 != Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator!=(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_NotEqual<D1,D2>>(a,b);
    }

    
  // Tensor<T> != T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator!=(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_NotEqual<T,T>>(a,b);
    }
    

  // T != Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator!=(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_NotEqual<T,T>>(a,b);
    }


  //----------------------------------------------
  // less than or equal (<=)
  //----------------------------------------------

  // Tensor<D1> <= Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator<=(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_LessOrEqual<D1,D2>>(a,b);
  }


  // Tensor<D1> <= D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator<=(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_LessOrEqual<D1,D2>>(a,b);
    }

  
  // D1 <= Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator<=(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_LessOrEqual<D1,D2>>(a,b);
    }

    
  // Tensor<T> <= T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator<=(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_LessOrEqual<T,T>>(a,b);
    }
    

  // T <= Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator<=(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_LessOrEqual<T,T>>(a,b);
    }
    

  //----------------------------------------------
  // less than or equal (>=)
  //----------------------------------------------

  // Tensor<D1> >= Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator>=(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_GreaterOrEqual<D1,D2>>(a,b);
  }


  // Tensor<D1> >= D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator>=(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_GreaterOrEqual<D1,D2>>(a,b);
    }

  
  // D1 >= Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator>=(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_GreaterOrEqual<D1,D2>>(a,b);
    }

    
  // Tensor<T> >= T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator>=(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_GreaterOrEqual<T,T>>(a,b);
    }
    

  // T >= Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator>=(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_GreaterOrEqual<T,T>>(a,b);
    }


  //----------------------------------------------
  // less than (<)
  //----------------------------------------------

  // Tensor<D1> < Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator<(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Less<D1,D2>>(a,b);
  }


  // Tensor<D1> < D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator<(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Less<D1,D2>>(a,b);
    }

  
  // D1 < Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator<(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Less<D1,D2>>(a,b);
    }

    
  // Tensor<T> < T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator<(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Less<T,T>>(a,b);
    }
    

  // T < Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator<(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Less<T,T>>(a,b);
    }
    
  //----------------------------------------------
  // greater than (>)
  //----------------------------------------------

  // Tensor<D1> > Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline auto operator>(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Greater<D1,D2>>(a,b);
  }


  // Tensor<D1> > D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto operator>(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Greater<D1,D2>>(a,b);
    }

  
  // D1 > Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto operator>(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Greater<D1,D2>>(a,b);
    }

    
  // Tensor<T> > T
    
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator>(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Greater<T,T>>(a,b);
    }
    

  // T > Tensor<T>

  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto operator>(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Greater<T,T>>(a,b);
    }

    
  // ************************************************************************
  // *           Other functions related to equality
  // ************************************************************************

    

  // approxel(a,b,tol) - element wise
  
  template <class D1, class D2, class D3, class A, class B> 
    inline auto approxel(const TensorR<D1,A>& a, const TensorR<D2,B>& b, const D3 tol = MatricksHelper<D3>::tolerance)
  {
    return  TER_Ternary< TensorR<D1,A>,TensorR<D2,B>,D3, D1,D2,D3, Fun_Approx<D1,D2,D3> >(a,b,tol);
  }


  
  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <class D, class A, class B>
    inline bool equal(const TensorR<D,A>& tensor1, const TensorR<D,B>& tensor2) {
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
    inline bool approx(const TensorR<D,A>& tensor1, const TensorR<D,B>& tensor2, typename FundamentalType<D>::Type tolerance = MatricksHelper<typename FundamentalType<D>::Type>::tolerance) {
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
    D sum( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (index_type i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }



  
  // prod(a)

  template <class D, class A> 
    D prod( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (index_type i = 1; i < N ; i++ )
      result *= a[i];
    
    return result;
  }





  // norm(a)

  template <class D, class A> 
    D norm( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0]*a[0];

    for (index_type i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <class D, class A> 
    D min( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (index_type i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <class D, class A> 
    D max( const TensorR<D,A>& a ) {
    
    const size_type N = a.deepsize();
    if (N==0)
      return 0;

    D result = a[0];

    for (index_type i = 1; i < N ; i++ )
      result = std::max(result,a[i]);
    
    return result;
  }







  
  /****************************************************************************
   * Unary Functions/Operators that bools or index_type Tensors
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class D, class A> 
    inline bool alltrue( const TensorR<D,A>& a ) {
    bool result = true;
    
 
    for (index_type i = 0; i< a.deepsize(); i++)
      result = result && a.dat(i);
    
    return result;
  }


  // anytrue(a)

  template <class D, class A> 
    inline bool anytrue( const TensorR<D,A>& a ) {
    bool result = false;
    
 
    for (index_type i = 0; i< a.deepsize(); i++)
      result = result || a.dat(i);
    
    return result;
  }


  // numtrue(a)

  template <class D, class A> 
    inline size_type numtrue( const TensorR<D,A>& a ) {
    size_type result = 0;
    
 
    for (index_type i = 0; i< a.deepsize(); i++)
      result += static_cast<index_type>(a.dat(i));
    
    return result;
  }


  


  // findtrue(a)

  // NOTE: declaration in preface.h
  
  template <class A> 
    inline Vector<index_type>& findtrue( const TensorR<bool,A>& a ) {
    int N = 0;
    TLDISP(a);

    for (index_type i = 0; i< a.size(); i++)
      N += int(a[i]);
 
    Vector<index_type> *y = new Vector<index_type>(N);

    index_type j =0;
    for (index_type i = 0; i< a.size(); i++)
      if (a[i])
	(*y)[j++] = i;
    
    return *y;
  }

    
  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************


  // real(Tensor)

  template <class D, class A> 
    inline auto real(const TensorR<D,A>& a)
  {
    return TER_Unary<typename Realify<D>::Type, TensorR<D,A>, Fun_Real<D> >(a);
  }

  // imag(Tensor)

  template <class D, class A> 
    inline auto imag(const TensorR<D,A>& a)
  {
    return TER_Unary<typename Realify<D>::Type, TensorR<D,A>, Fun_Imag<D> >(a);
  }


  // conj(Tensor)

  template <class D, class A> 
    inline auto conj(const TensorR<D,A>& a)
  {
    return TER_Unary<typename Complexify<D>::Type, TensorR<D,A>, Fun_Conj<D> >(a);
  }


  
  // transpose(A) 

  template <class D, class A> 
    inline auto transpose(TensorRW<D,A>& a)
  {
    return TERW_Transpose<D,TensorRW<D,A>,Fun_Plus<D> >(a);
  }

  // adjoint(A) - conjugate transpose 

  template <class D, class A> 
    inline auto adjoint(const TensorR<D,A>& a)
  {
    return  TER_Transpose<D,TensorR<D,A>,Fun_Conj<D> >(a);
  }

  
  // ~A conjugate transpose operator

  template <class D, class A> 
    inline auto operator~(const TensorR<D,A>& a)
  {
    return  TER_Transpose<D,TensorR<D,A>,Fun_Conj<D> >(a);
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
    inline auto operator,(const TensorRW<D,A>& a, const Vector<D>& b)
    {
      PRINTF2("  VERW_Join operator,(const TensorRW<D,A>& a, const Vector<D>& b)\n");
      TensorRW<D,A>& a_ = const_cast<TensorRW<D,A>& >(a);
      Vector<D>& b_ = const_cast<Vector<D>& >(b);
      return  VERW_Join<D, TensorRW<D,A>,Vector<D> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  // then we cast away the const
  template <class D, class B> 
    inline auto operator,(const Vector<D>& a, const TensorRW<D,B>& b)
    {
      PRINTF2("  VERW_Join operator,(const Vector<D>& a, const TensorRW<D,B>& b)\n");
      Vector<D>& a_ = const_cast<Vector<D>& >(a);
      TensorRW<D,B>& b_ = const_cast<TensorRW<D,B>& >(b);
      return VERW_Join<D, Vector<D>,TensorRW<D,B> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  template <class D, class A, class B> 
    inline auto operator,(const TensorRW<D,A>& a, const TensorRW<D,B>& b)
    {
      PRINTF2("  VERW_Join operator,(const TensorRW<D,A>& a, const TensorRW<D,B>& b)\n");
      TensorRW<D,A>& a_ = const_cast<TensorRW<D,A>& >(a);
      TensorRW<D,B>& b_ = const_cast<TensorRW<D,B>& >(b);
      return  VERW_Join<D, TensorRW<D,A>,TensorRW<D,B> >(a_,b_);
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
    inline const auto operator,(const Vector<D>& a, const TensorR<D,B>& b)
    {
      PRINTF2("  VER_Join operator,(const Vector<D>& a, const TensorR<D,B>& b)\n");
      return  VER_Join<D,Vector<D>,TensorR<D,B>  >(a,b);
    }

  template <class D, class A> 
    inline const auto operator,(const TensorR<D,A>& a, const Vector<D>& b)
    {
      PRINTF2("  VER_Join operator,(const TensorR<D,A>& a, const Vector<D>& b)\n");
      return  VER_Join<D,TensorR<D,A>,Vector<D> >(a,b);
    }
 
  template <class D, class A, class B> 
    inline const auto operator,(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      PRINTF2("  VER_Join operator,(const TensorR<D,A>& a, const TensorR<D,B>& b)\n");
      return  VER_Join<D, TensorR<D,A>,TensorR<D,B> >(a,b);
    }






  // rep(v,m)

  template <class D, class A> 
    inline auto rep(const TensorR<D,A>& a, const size_type m) {
    return VER_Rep<D,TensorR<D,A> >(a,m);
  }

  
 

  


  /****************************************************************
   * functions that convert vectors into other objects
   *****************************************************************
   */


  // toCarray(v)

  template <class D2, class D1, class A> 
    inline D2* toCarray(const TensorR<D1,A>& v) {
    const size_type N = v.size();
    D2* dptr = new D2[N];
    for(index_type i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(v[i]);
    return  dptr;
  }

  

  // tostdvector(v)

  template <class D2, class D1, class A> 
    inline std::vector<D2>
    tostdvector(const TensorR<D1,A>& v) {
    const size_type N = v.size();
    std::vector<D2> y(N);
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  // tovalarray(v)

  template <class D2, class D1, class A> 
    inline std::valarray<D2>
    tovalarray(const TensorR<D1,A>& v) {
    const size_type N = v.size();
    std::valarray<D2> y(N);
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  

};

#endif 
