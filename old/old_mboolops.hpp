#ifndef MBOOLOPS_H
#define MBOOLOPS_H


namespace mathq {





  /************************************************************
   *               Templates for Binary Operators that return bool matrixs
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */


  // a==b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Equal<D> >  
  operator==( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Equal<D> >(a,b);
  }


  // a!=b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_NotEqual<D> >  
  operator!=( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_NotEqual<D> >(a,b);
  }



  // a<=b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_LessOrEqual<D> >  
  operator<=( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_LessOrEqual<D> >(a,b);
  }


  // a>=b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_GreaterOrEqual<D> >  
  operator>=( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_GreaterOrEqual<D> >(a,b);
  }


  // a<b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Less<D> >  
  operator<( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Less<D> >(a,b);
  }


  // a>b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Greater<D> >  
  operator>( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Greater<D> >(a,b);
  }


 /************************************************************
   *    Templates for matrix/scalar Operators that return Bool matrix
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */



  // matrix == scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_Equal<D> > 
  operator==(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_Equal<D> >(a,b);
  }

  // scalar == matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_Equal<D> > 
  operator==(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_Equal<D> >(a,b);
  }

  // matrix != scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_NotEqual<D> > 
  operator!=(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_NotEqual<D> >(a,b);
  }

  // scalar != matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_NotEqual<D> > 
  operator!=(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_NotEqual<D> >(a,b);
  }
  // matrix <= scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_LessOrEqual<D> > 
  operator<=(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_LessOrEqual<D> >(a,b);
  }

  // scalar <= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_LessOrEqual<D> > 
  operator<=(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_LessOrEqual<D> >(a,b);
  }
  // matrix >= scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_GreaterOrEqual<D> > 
  operator>=(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_GreaterOrEqual<D> >(a,b);
  }

  // scalar >= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_GreaterOrEqual<D> > 
  operator>=(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_GreaterOrEqual<D> >(a,b);
  }
  // matrix < scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_Less<D> > 
  operator<(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_Less<D> >(a,b);
  }

  // scalar < matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_Less<D> > 
  operator<(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_Less<D> >(a,b);
  }
  // matrix > scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_Greater<D> > 
  operator>(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_Greater<D> >(a,b);
  }

  // scalar > matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_Greater<D> > 
  operator>(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_Greater<D> >(a,b);
  }



  // the following are defined for convenience

  // matrix == int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_Equal<D> > 
  operator==(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_Equal<D> >(a,static_cast<D>(b));
  }

  // int scalar == matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_Equal<D> > 
  operator==(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_Equal<D> >(static_cast<D>(a),b);
  }

  // matrix != int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_NotEqual<D> > 
  operator!=(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_NotEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar != matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_NotEqual<D> > 
  operator!=(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_NotEqual<D> >(static_cast<D>(a),b);
  }
  // matrix <= int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_LessOrEqual<D> > 
  operator<=(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_LessOrEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar <= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_LessOrEqual<D> > 
  operator<=(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_LessOrEqual<D> >(static_cast<D>(a),b);
  }
  // matrix >= int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_GreaterOrEqual<D> > 
  operator>=(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_GreaterOrEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar >= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_GreaterOrEqual<D> > 
  operator>=(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_GreaterOrEqual<D> >(static_cast<D>(a),b);
  }
  // matrix < int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_Less<D> > 
  operator<(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_Less<D> >(a,static_cast<D>(b));
  }

  // int scalar < matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_Less<D> > 
  operator<(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_Less<D> >(static_cast<D>(a),b);
  }
  // matrix > int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,Fun_Greater<D> > 
  operator>(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,Fun_Greater<D> >(a,static_cast<D>(b));
  }

  // int scalar > matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,Fun_Greater<D> > 
  operator>(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,Fun_Greater<D> >(static_cast<D>(a),b);
  }




  /************************************************************
   *               Templates for Binary Operators
   *
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // matrix && matrix

  template <class A, class B> 
  inline MBinOp<bool,MorE<bool,A>,MorE<bool,B>,Fun_And > 
  operator&&(const MorE<bool,A>& a, const MorE<bool,B>& b)
  {
    return  MBinOp<bool,MorE<bool,A>,MorE<bool,B>,Fun_And >(a,b);
  }

  // matrix || matrix

  template <class A, class B> 
  inline MBinOp<bool,MorE<bool,A>,MorE<bool,B>,Fun_Or > 
  operator||(const MorE<bool,A>& a, const MorE<bool,B>& b)
  {
    return  MBinOp<bool,MorE<bool,A>,MorE<bool,B>,Fun_Or >(a,b);
  }










  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * A = either an Matrix or a Mexpr
   ************************************************************
   */


  // matrix && scalar

  template <class A> 
  inline MatOpScal<bool,MorE<bool,A>,Fun_And > 
  operator&&(const MorE<bool,A>& a, const bool b)
  {
    return  MatOpScal<bool,MorE<bool,A>,Fun_And >(a,b);
  }

  // scalar && matrix

  template <class B> 
  inline ScalOpMat<bool,MorE<bool,B>,Fun_And > 
  operator&&(const bool a, const MorE<bool,B>& b)
  {
    return  ScalOpMat<bool,MorE<bool,B>,Fun_And >(a,b);
  }

  
  // matrix || scalar

  template <class A> 
  inline MatOpScal<bool,MorE<bool,A>,Fun_Or > 
  operator||(const MorE<bool,A>& a, const bool b)
  {
    return  MatOpScal<bool,MorE<bool,A>,Fun_Or >(a,b);
  }

  // scalar || matrix

  template <class B> 
  inline ScalOpMat<bool,MorE<bool,B>,Fun_Or > 
  operator||(const bool a, const MorE<bool,B>& b)
  {
    return  ScalOpMat<bool,MorE<bool,B>,Fun_Or >(a,b);
  }



  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */


  
  // !(matrix)

  template <class A> 
  inline MFuncOp<bool,MorE<bool,A>,Fun_Not > 
  operator!(const MorE<bool,A>& a)
  {
    return  MFuncOp<bool,MorE<bool,A>,Fun_Not >(a);
  }
  




  










  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class A> 
  inline bool alltrue( const MorE<bool,A>& a ) {
    bool result = true;
    
 
    for (register size_type i = 0; i< a.size(); i++)
      result = result && a(i);
    
    return result;
  }


  // alltruebyrow(a)

  template <class A> 
  inline Vector<bool> alltruebyrow( const MorE<bool,A>& a ) {
    
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    Vector<bool> y(NR);

    size_type i = 0;
    for(size_type r = 0; r<NR; r++) {
      bool temp=true;
      for(size_type c = 0; c<NC; c++,i++) {
	temp = temp && a(i);
      }
      y[r] = temp;
    }
    return y;
  }

  // alltruebycol(a)
  template <class A> 
  inline Vector<bool> alltruebycol( const MorE<bool,A>& a ) {
    
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    Vector<bool> y(NC);

    for(size_type c = 0; c<NC; c++) {
      size_type LIMIT = NR*NC-NC+c+1;
      bool temp=true;
      for(size_type i = c; i<LIMIT; i+=NC) {
	temp = temp && a(i);
      }
      y[c] = temp;
    }
    return y;
  }









   // anytrue(a)

  template <class A> 
  inline bool anytrue( const MorE<bool,A>& a ) {
    bool result = false;
    
 
    for (register size_type i = 0; i< a.size(); i++)
      result = result || a(i);
    
    return result;
  }



  // anytruebyrow(a)

  template <class A> 
  inline Vector<bool> anytruebyrow( const MorE<bool,A>& a ) {
    
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    Vector<bool> y(NR);

    size_type i = 0;
    for(size_type r = 0; r<NR; r++) {
      bool temp=false;
      for(size_type c = 0; c<NC; c++,i++) {
	temp = temp || a(i);
      }
      y[r] = temp;
    }
    return y;
  }

  // anytruebycol(a)
  template <class A> 
  inline Vector<bool> anytruebycol( const MorE<bool,A>& a ) {
    
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    Vector<bool> y(NC);

    for(size_type c = 0; c<NC; c++) {
      size_type LIMIT = NR*NC-NC+c+1;
      bool temp=false;
      for(size_type i = c; i<LIMIT; i+=NC) {
	temp = temp || a(i);
      }
      y[c] = temp;
    }
    return y;
  }


  // numtrue(a)

  template <class A> 
  inline int numtrue( const MorE<bool,A>& a ) {
    size_type result = 0;
    
 
    for (register size_type i = 0; i< a.size(); i++)
      result += static_cast<int>(a(i));
    
    return result;
  }



  // numtruebyrow(a)

  template <class A> 
  inline Vector<index_type> numtruebyrow( const MorE<bool,A>& a ) {
    
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    Vector< size_type> y(NR);

    size_type i = 0;
    for(size_type r = 0; r<NR; r++) {
       size_type temp=0;
      for(size_type c = 0; c<NC; c++,i++) {
	temp  += static_cast<index_type>(a(i));
      }
      y[r] = temp;
    }
    return y;
  }

  // numtruebycol(a)
  template <class A> 
  inline Vector< size_type> numtruebycol( const MorE<bool,A>& a ) {
    
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    Vector< size_type> y(NC);

    for(size_type c = 0; c<NC; c++) {
      size_type LIMIT = NR*NC-NC+c+1;
      size_type temp=0;
      for(size_type i = c; i<LIMIT; i+=NC) {
	temp  += static_cast<index_type>(a(i));
      }
      y[c] = temp;
    }
    return y;
  }



  
  

  // findtrue(a)

  template <class A> 
  inline Matrix<index_type> findtrue( const MorE<bool,A>& a ) {
    size_type N = 0;
    
 
    for (register size_type i = 0; i< a.size(); i++)
      N += static_cast<index_type>(a(i));
 
    Matrix<index_type> y(N,2);

   size_type i = 0;
   size_type j = 0;
    for(size_type r = 0; r<a.Nrows(); r++) {
       for(size_type c = 0; c<a.Ncols(); c++,i++) {
	 if (a(i)) {
	   y(j,0) = r;
	   y(j,1) = c;
	   j++;
	 }
       }
    }
    return y;
  }





  // findtruesi(a) -- return in single index format

  template <class A> 
  inline Vector<index_type> findtruesi( const MorE<bool,A>& a ) {
    size_type N = 0;
    
 
    for (register size_type i = 0; i< a.size(); i++)
      N += static_cast<index_type>(a(i));
 
    Vector<index_type> y(N);

    size_type j = 0;
    for (register size_type i = 0; i< a.size(); i++) {
      if (a(i)) {
	y[j] = i;
	j++;
      }
    }
    
    return y;
  }

  

  // findtruebyrow(a)

  template <class A> 
  inline Vector<index_type> findtruebyrow( const MorE<bool,A>& a ) {
    size_type N = 0;
    
 
    for (register size_type i = 0; i< a.size(); i++)
      N += static_cast<index_type>(a(i));
 
    Vector<index_type> y(N,2);

   size_type i = 0;
   size_type j = 0;
    for(size_type r = 0; r<a.Nrows(); r++) {
       for(size_type c = 0; c<a.Ncols(); c++,i++) {
	 if (a(i)) {
	   y[r] = 1;
	 }
       }
    }
    return y;
  }

  



};

#endif 
