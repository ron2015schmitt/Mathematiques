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

  template <class Element, class A, typename Number, int depth> 
    inline auto operator+(const MArrayExpR<Element,A,Number,depth>& a)
  {
    return  TER_Unary< MArrayExpR<Element,A,Number,depth>, Fun_Plus<Number> >(a);
  }


  // -(MultiArray)

  template <typename Number, class A> 
    inline auto operator-(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Minus<Number> >(a);
  }


  
  //----------------------------------------------
  // Addition (+)
  //----------------------------------------------

  // MultiArray<NT1> + MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator+(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Add<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> + NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator+(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Add<NT1,NT2>>(a,b);
    }

  
  // NT1 + MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator+(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Add<NT1,NT2>>(a,b);
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


  // MultiArray<NT1> - MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator-(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Subtract<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> - NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator-(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Subtract<NT1,NT2>>(a,b);
    }

  
  // NT1 - MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator-(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Subtract<NT1,NT2>>(a,b);
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

  // MultiArray<NT1> * MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator*(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Multiply<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> * NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator*(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Multiply<NT1,NT2>>(a,b);
    }

  
  // NT1 * MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator*(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Multiply<NT1,NT2>>(a,b);
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

  // MultiArray<NT1> / MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator/(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Divide<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> / NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator/(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Divide<NT1,NT2>>(a,b);
    }

  
  // NT1 / MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator/(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Divide<NT1,NT2>>(a,b);
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
  // numbercast: cast data from NT1 to NT2
  //**************************************************************************

  template <class NT2, class NT1, class A> 
    inline auto numbercast(const MArrayExpR<NT1,A>& a)
  {
    return  TER_Unary<NT2,MArrayExpR<NT1,A>,Fun_Cast<NT2,NT1> >(a);
  }



  /****************************************************************************
   *  products: Scalar Scalar
   ****************************************************************************
   */

  // --------------------  dot (inner) product --------------------------------
  
  // (a|b)

  // TODO: rewrite for only floating point base types
  template <typename Number> inline
    Number operator|( const Scalar<Number>& a, const  Scalar<Number>& b ) {
    return a()*b();
  }


  // dot(a,b)

  template <typename Number> inline
    Number dot( const Scalar<Number>& a, const  Scalar<Number>& b ) {
    return (a|b);
  }


  // --------------------  tensor (outer) product --------------------------------
  
  // (a&b)
  // TODO: rewrite for only floating point base types

  template <typename Number> inline
    Number operator&( const Scalar<Number>& a, const  Scalar<Number>& b ) {
    return a()*b();
  }


  // tprod(a,b)

  template <typename Number> inline
    Number tprod( const Scalar<Number>& a, const  Scalar<Number>& b ) {
    return (a&b);
  }


  // -------------------- antisymmetric (wedge)  product -----------------------
  
  // (a^b)
  // TODO: rewrite for only floating point base types

  template <typename Number> inline
    Number operator^( const Scalar<Number>& a, const  Scalar<Number>& b ) {
    return 0;
  }


  // wprod(a,b)

  template <typename Number> inline
    Number wprod( const Scalar<Number>& a, const  Scalar<Number>& b ) {
    return (a^b);
  }

  
  /****************************************************************************
   *  products: Vector Vector
   ****************************************************************************
   */


  // --------------------  dot (inner) product --------------------------------

  // (a|b)
  // TODO: rewrite for only floating point base types

  template <typename Number> inline
    Number operator|( const Vector<Number>& a, const  Vector<Number>& b ) {

    Number result = Number(0);
    for (size_t i = a.deepsize(); i--;) {
      result += a[i]*b[i];
    }
    return result;
  }

  // dot(a,b)

  template <typename Number> inline
    Number dot( const Vector<Number>& a, const  Vector<Number>& b ) {
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

  template <typename Number, class A, class B> inline
    Number operator|( const MArrayExpR<Number,A>& a, const  MArrayExpR<Number,B>& b ) {

    // (Scalar|Scalar)
    if ((a.rank() == 0) && (b.rank() == 0)) {
      return a[0]*b[0];
    }

    // (Vector|Vector)
    if ((a.rank() == 1) && (b.rank() == 1)) {
      Number result = Number(0);
      for (size_t i = a.deepsize(); i--;) {
	result += a[i]*b[i];
      }
      return result;
    }
  }

  // dot(a,b)

  template <typename Number, class A, class B> inline
    Number dot( const MArrayExpR<Number,A>& a, const  MArrayExpR<Number,B>& b ) {
    return (a|b);
  }

  // --------------------  tensor (outer) product --------------------------------

  // (a&b)

  template <typename Number, class A, class B> inline
    Number operator&( const MArrayExpR<Number,A>& a, const  MArrayExpR<Number,B>& b ) {

    // (Scalar&Scalar)
    if ((a.rank() == 0) && (b.rank() == 0)) {
      return a[0]*b[0];
    }

  }

  // tprod(a,b)

  template <typename Number, class A, class B> inline
    Number tprod( const MArrayExpR<Number,A>& a, const  MArrayExpR<Number,B>& b ) {
    return (a&b);
  }

  // -------------------- antisymmetric (wedge)  product -----------------------

  // (a^b)

  template <typename Number, class A, class B> inline
    Number operator^( const MArrayExpR<Number,A>& a, const  MArrayExpR<Number,B>& b ) {

    // (Scalar^Scalar)
    if ((a.rank() == 0) && (b.rank() == 0)) {
      return a[0]*b[0];
    }

  }

  // wprod(a,b)

  template <typename Number, class A, class B> inline
    Number wprod( const MArrayExpR<Number,A>& a, const  MArrayExpR<Number,B>& b ) {
    return (a^b);
  }
  
  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************


  // pow(MultiArray<NT1>,MultiArray<NT2>)

  template <class NT1, class NT2, class A, class B> 
    inline auto pow(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Pow<NT1,NT2>>(a,b);
  }
  
  
  // pow(MultiArray<NT1> , NT2)
  
  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto pow(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Pow<NT1,NT2>>(a,b);
    }
  
  
  // pow(NT1 , MultiArray<NT2>)
  
  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto pow(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Pow<NT1,NT2>>(a,b);
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

  template <typename Number, class A> 
    inline auto sqr(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Sqr<Number> >(a);
  }

  // cube(MultiArray)

  template <typename Number, class A> 
    inline auto cube(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Cube<Number> >(a);
  }

  // sqrt(MultiArray)

  template <typename Number, class A> 
    inline auto sqrt(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Sqrt<Number> >(a);
  }

  // exp(MultiArray)

  template <typename Number, class A> 
    inline auto exp(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Exp<Number> >(a);
  }



  // log(MultiArray)

  template <typename Number, class A> 
    inline auto log(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Log<Number> >(a);
  }


  // log10(MultiArray)

  template <typename Number, class A> 
    inline auto log10(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Log10<Number> >(a);
  }


  // log2(MultiArray)

  template <typename Number, class A> 
    inline auto log2(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Log2<Number> >(a);
  }






  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************

  // sin(MultiArray)

  template <typename Number, class A> 
    inline auto sin(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Sin<Number> >(a);
  }


  // cos(MultiArray)

  template <typename Number, class A> 
    inline auto cos(const MArrayExpR<Number,A>& a)
  {
    return TER_Unary<Number,MArrayExpR<Number,A>,Fun_Cos<Number> >(a);
  }



  // tan(MultiArray)

  template <typename Number, class A> 
    inline auto tan(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Tan<Number> >(a);
  }


  // asin(MultiArray)

  template <typename Number, class A> 
    inline auto asin(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Asin<Number> >(a);
  }


  // acos(MultiArray)

  template <typename Number, class A> 
    inline auto acos(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Acos<Number> >(a);
  }


  // atan(MultiArray)

  template <typename Number, class A> 
    inline auto atan(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Atan<Number> >(a);
  }


  // atan2(MultiArray,MultiArray)

  // MultiArray<NT1> + MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto atan2(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Atan2<NT1,NT2>>(a,b);
  }
  


  // sinh(MultiArray)

  template <typename Number, class A> 
    inline auto sinh(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Sinh<Number> >(a);
  }


  // cosh(MultiArray)

  template <typename Number, class A> 
    inline auto cosh(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Cosh<Number> >(a);
  }


  // tanh(MultiArray)

  template <typename Number, class A> 
    inline auto tanh(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Tanh<Number> >(a);
  }


  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  // abs(MultiArray)

  template <typename Number, class A> 
    inline auto abs(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Abs<Number> >(a);
  }


  // sgn(MultiArray)

  template <typename Number, class A> 
    inline auto sgn(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Sgn<Number> >(a);
  }



  // ceil(MultiArray)

  template <typename Number, class A> 
    inline auto ceil(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Ceil<Number> >(a);
  }


  // floor(MultiArray)

  template <typename Number, class A> 
    inline auto floor(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Floor<Number> >(a);
  }


  // round(MultiArray)

  template <typename Number, class A> 
    inline auto round(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number,MArrayExpR<Number,A>,Fun_Round<Number> >(a);
  }



  // roundzero(MultiArray)

  template <class NT1, class A>
     auto roundzero(const MArrayExpR<NT1,A>& a, const typename SimpleNumberTrait<NT1>::Type tolerance = MatricksHelper< typename SimpleNumberTrait<NT1>::Type >::tolerance)
    {
      typedef typename SimpleNumberTrait<NT1>::Type TOL;
      return  TER_Binary< MArrayExpR<NT1,A>,TOL, NT1,TOL, Fun_Roundzero<NT1,TOL> >(a, tolerance);
    }
  

  

  // ************************************************************************
  // *              User Defined
  // ************************************************************************


  // user-defined functions
  template <typename Number, typename FunctionTypes<Number>::unary_func F, class A> 
    inline auto op1(const MArrayExpR<Number,A>& a)
  {
    return  TER_Unary<Number, MArrayExpR<Number,A>, Fun_UnaryUser<Number,F> >(a);
  }

  template <typename Number, typename FunctionTypes<Number>::binary_func F, class A, class B> 
    inline auto op2(const MArrayExpR<Number,A>& a, const MArrayExpR<Number,B>& b)
  {
    return  TER_Binary<MArrayExpR<Number,A>,MArrayExpR<Number,B>, Number,Number, Fun_BinaryUser<Number,Number,F>>(a,b);
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
  
  // MultiArray<NT1> && MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator&&(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_And<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> && bool

  template <class NT1, class A> 
    inline auto operator&&(const MArrayExpR<NT1,A>& a, const bool& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,bool,NT1,bool,Fun_And<NT1,bool>>(a,b);
    }

  
  // bool && MultiArray<NT2>

  template <class NT2, class B>
    inline auto operator&&(const bool& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<bool,MArrayExpR<NT2,B>,bool,NT2,Fun_And<bool,NT2>>(a,b);
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
    
  
  // MultiArray<NT1> || MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator||(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Or<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> || bool

  template <class NT1, class A> 
    inline auto operator||(const MArrayExpR<NT1,A>& a, const bool& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,bool,NT1,bool,Fun_Or<NT1,bool>>(a,b);
    }

  
  // bool || MultiArray<NT2>

  template <class NT2, class B>
    inline auto operator||(const bool& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<bool,MArrayExpR<NT2,B>,bool,NT2,Fun_Or<bool,NT2>>(a,b);
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
  // *              Relational ops (return a bool MultiArray from two Number MultiArrays)
  // ************************************************************************


  //----------------------------------------------
  // equal (==)
  //----------------------------------------------

  // MultiArray<NT1> == MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator==(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Equal<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> == NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator==(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Equal<NT1,NT2>>(a,b);
    }

  
  // NT1 == MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator==(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Equal<NT1,NT2>>(a,b);
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

  // MultiArray<NT1> != MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator!=(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_NotEqual<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> != NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator!=(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_NotEqual<NT1,NT2>>(a,b);
    }

  
  // NT1 != MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator!=(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_NotEqual<NT1,NT2>>(a,b);
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

  // MultiArray<NT1> <= MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator<=(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_LessOrEqual<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> <= NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator<=(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_LessOrEqual<NT1,NT2>>(a,b);
    }

  
  // NT1 <= MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator<=(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_LessOrEqual<NT1,NT2>>(a,b);
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

  // MultiArray<NT1> >= MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator>=(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_GreaterOrEqual<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> >= NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator>=(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_GreaterOrEqual<NT1,NT2>>(a,b);
    }

  
  // NT1 >= MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator>=(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_GreaterOrEqual<NT1,NT2>>(a,b);
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

  // MultiArray<NT1> < MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator<(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Less<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> < NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator<(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Less<NT1,NT2>>(a,b);
    }

  
  // NT1 < MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator<(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Less<NT1,NT2>>(a,b);
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

  // MultiArray<NT1> > MultiArray<NT2>

  template <class NT1, class NT2, class A, class B> 
    inline auto operator>(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b)
  {
    return  TER_Binary<MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT1,NT2,Fun_Greater<NT1,NT2>>(a,b);
  }


  // MultiArray<NT1> > NT2

  template <class NT1, class NT2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT2>::value> > 
    inline auto operator>(const MArrayExpR<NT1,A>& a, const NT2& b)
    {
      return  TER_Binary<MArrayExpR<NT1,A>,NT2,NT1,NT2,Fun_Greater<NT1,NT2>>(a,b);
    }

  
  // NT1 > MultiArray<NT2>

  template <class NT1, class NT2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,NT1>::value> > 
    inline auto operator>(const NT1& a, const MArrayExpR<NT2,B>& b)
    {
      return  TER_Binary<NT1,MArrayExpR<NT2,B>,NT1,NT2,Fun_Greater<NT1,NT2>>(a,b);
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
  
  template <class NT1, class NT2, class NT3, class A, class B> 
    inline auto approxel(const MArrayExpR<NT1,A>& a, const MArrayExpR<NT2,B>& b, const NT3 tol = MatricksHelper<NT3>::tolerance)
  {
    return  TER_Ternary< MArrayExpR<NT1,A>,MArrayExpR<NT2,B>,NT3, NT1,NT2,NT3, Fun_Approx<NT1,NT2,NT3> >(a,b,tol);
  }


  
  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <typename Number, class A, class B>
    inline bool equal(const MArrayExpR<Number,A>& tensor1, const MArrayExpR<Number,B>& tensor2) {
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
  template <typename Number, class A, class B>
    inline bool approx(const MArrayExpR<Number,A>& tensor1, const MArrayExpR<Number,B>& tensor2, typename SimpleNumberTrait<Number>::Type tolerance = MatricksHelper<typename SimpleNumberTrait<Number>::Type>::tolerance) {
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

  template <typename Number, class A> 
    Number sum( const MArrayExpR<Number,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    Number result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }



  
  // prod(a)

  template <typename Number, class A> 
    Number prod( const MArrayExpR<Number,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    Number result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result *= a[i];
    
    return result;
  }





  // norm(a)

  template <typename Number, class A> 
    Number norm( const MArrayExpR<Number,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    Number result = a[0]*a[0];

    for (size_t i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <typename Number, class A> 
    Number min( const MArrayExpR<Number,A>& a ) {
    
 
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    Number result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <typename Number, class A> 
    Number max( const MArrayExpR<Number,A>& a ) {
    
    const size_t N = a.deepsize();
    if (N==0)
      return 0;

    Number result = a[0];

    for (size_t i = 1; i < N ; i++ )
      result = std::max(result,a[i]);
    
    return result;
  }







  
  /****************************************************************************
   * Unary Functions/Operators that bools or size_t MultiArrays
   ****************************************************************************
   */


  
  // alltrue(a)

  template <typename Number, class A> 
    inline bool alltrue( const MArrayExpR<Number,A>& a ) {
    bool result = true;
    
 
    for (size_t i = 0; i< a.deepsize(); i++)
      result = result && a.dat(i);
    
    return result;
  }


  // anytrue(a)

  template <typename Number, class A> 
    inline bool anytrue( const MArrayExpR<Number,A>& a ) {
    bool result = false;
    
 
    for (size_t i = 0; i< a.deepsize(); i++)
      result = result || a.dat(i);
    
    return result;
  }


  // numtrue(a)

  template <typename Number, class A> 
    inline size_t numtrue( const MArrayExpR<Number,A>& a ) {
    size_t result = 0;
    
 
    for (size_t i = 0; i< a.deepsize(); i++)
      result += static_cast<size_t>(a.dat(i));
    
    return result;
  }


  


  // findtrue(a)

  // NOTE: declaration in declarations.h
  
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

  template <typename Number, class A> 
    inline auto real(const MArrayExpR<Number,A>& a)
  {
    return TER_Unary<typename Realify<Number>::Type, MArrayExpR<Number,A>, Fun_Real<Number> >(a);
  }

  // imag(MultiArray)

  template <typename Number, class A> 
    inline auto imag(const MArrayExpR<Number,A>& a)
  {
    return TER_Unary<typename Realify<Number>::Type, MArrayExpR<Number,A>, Fun_Imag<Number> >(a);
  }


  // conj(MultiArray)

  template <typename Number, class A> 
    inline auto conj(const MArrayExpR<Number,A>& a)
  {
    return TER_Unary<typename Complexify<Number>::Type, MArrayExpR<Number,A>, Fun_Conj<Number> >(a);
  }


  
  // transpose(A) 

  template <typename Number, class A> 
    inline auto transpose(MArrayExpRW<Number,A>& a)
  {
    return TERW_Transpose<Number,MArrayExpRW<Number,A>,Fun_Plus<Number> >(a);
  }

  // adjoint(A) - conjugate transpose 

  template <typename Number, class A> 
    inline auto adjoint(const MArrayExpR<Number,A>& a)
  {
    return  TER_Transpose<Number,MArrayExpR<Number,A>,Fun_Conj<Number> >(a);
  }

  
  // ~A conjugate transpose operator

  template <typename Number, class A> 
    inline auto operator~(const MArrayExpR<Number,A>& a)
  {
    return  TER_Transpose<Number,MArrayExpR<Number,A>,Fun_Conj<Number> >(a);
  }










  // operator, (join)


  template <typename Number> 
    inline auto operator,(Vector<Number>& a, Vector<Number>& b)
    {
    
      PRINTF2("  VERW_Join operator,(Vector<Number>& a, Vector<Number>& b)\n");
      return  VERW_Join<Number,Vector<Number>,Vector<Number> >(a,b);
    }

  //--------------------------------------------
  // Need the const for compiler to find this
  // then we cast away the const
  template <typename Number, class A> 
    inline auto operator,(const MArrayExpRW<Number,A>& a, const Vector<Number>& b)
    {
      PRINTF2("  VERW_Join operator,(const MArrayExpRW<Number,A>& a, const Vector<Number>& b)\n");
      MArrayExpRW<Number,A>& a_ = const_cast<MArrayExpRW<Number,A>& >(a);
      Vector<Number>& b_ = const_cast<Vector<Number>& >(b);
      return  VERW_Join<Number, MArrayExpRW<Number,A>,Vector<Number> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  // then we cast away the const
  template <typename Number, class B> 
    inline auto operator,(const Vector<Number>& a, const MArrayExpRW<Number,B>& b)
    {
      PRINTF2("  VERW_Join operator,(const Vector<Number>& a, const MArrayExpRW<Number,B>& b)\n");
      Vector<Number>& a_ = const_cast<Vector<Number>& >(a);
      MArrayExpRW<Number,B>& b_ = const_cast<MArrayExpRW<Number,B>& >(b);
      return VERW_Join<Number, Vector<Number>,MArrayExpRW<Number,B> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  template <typename Number, class A, class B> 
    inline auto operator,(const MArrayExpRW<Number,A>& a, const MArrayExpRW<Number,B>& b)
    {
      PRINTF2("  VERW_Join operator,(const MArrayExpRW<Number,A>& a, const MArrayExpRW<Number,B>& b)\n");
      MArrayExpRW<Number,A>& a_ = const_cast<MArrayExpRW<Number,A>& >(a);
      MArrayExpRW<Number,B>& b_ = const_cast<MArrayExpRW<Number,B>& >(b);
      return  VERW_Join<Number, MArrayExpRW<Number,A>,MArrayExpRW<Number,B> >(a_,b_);
    }
  //--------------------------------------------


  
  ///---------
  
  template <typename Number> 
    inline const auto operator,(const Vector<Number>& a, const Vector<Number>& b)
    {
      PRINTF2("  VER_Join operator,(const Vector<Number>& a, const Vector<Number>& b)\n");
      return  VER_Join<Number,Vector<Number>,Vector<Number> >(a,b);
    }

  template <typename Number, class B> 
    inline const auto operator,(const Vector<Number>& a, const MArrayExpR<Number,B>& b)
    {
      PRINTF2("  VER_Join operator,(const Vector<Number>& a, const MArrayExpR<Number,B>& b)\n");
      return  VER_Join<Number,Vector<Number>,MArrayExpR<Number,B>  >(a,b);
    }

  template <typename Number, class A> 
    inline const auto operator,(const MArrayExpR<Number,A>& a, const Vector<Number>& b)
    {
      PRINTF2("  VER_Join operator,(const MArrayExpR<Number,A>& a, const Vector<Number>& b)\n");
      return  VER_Join<Number,MArrayExpR<Number,A>,Vector<Number> >(a,b);
    }
 
  template <typename Number, class A, class B> 
    inline const auto operator,(const MArrayExpR<Number,A>& a, const MArrayExpR<Number,B>& b)
    {
      PRINTF2("  VER_Join operator,(const MArrayExpR<Number,A>& a, const MArrayExpR<Number,B>& b)\n");
      return  VER_Join<Number, MArrayExpR<Number,A>,MArrayExpR<Number,B> >(a,b);
    }






  // rep(v,m)

  template <typename Number, class A> 
    inline auto rep(const MArrayExpR<Number,A>& a, const size_t m) {
    return VER_Rep<Number,MArrayExpR<Number,A> >(a,m);
  }

  
 

  


  /****************************************************************
   * functions that convert vectors into other objects
   *****************************************************************
   */


  // toCarray(v)

  template <class NT2, class NT1, class A> 
    inline NT2* toCarray(const MArrayExpR<NT1,A>& v) {
    const size_t N = v.size();
    NT2* dptr = new NT2[N];
    for(size_t i = 0; i<N; i++) 
      dptr[i] = static_cast<NT2>(v[i]);
    return  dptr;
  }

  

  // tostdvector(v)

  template <class NT2, class NT1, class A> 
    inline std::vector<NT2>
    tostdvector(const MArrayExpR<NT1,A>& v) {
    const size_t N = v.size();
    std::vector<NT2> y(N);
    for(size_t i = 0; i<N; i++) 
      y[i] = static_cast<NT2>(v[i]);
    return y;
  }



  // tovalarray(v)

  template <class NT2, class NT1, class A> 
    inline std::valarray<NT2>
    tovalarray(const MArrayExpR<NT1,A>& v) {
    const size_t N = v.size();
    std::valarray<NT2> y(N);
    for(size_t i = 0; i<N; i++) 
      y[i] = static_cast<NT2>(v[i]);
    return y;
  }



  

};

#endif 
