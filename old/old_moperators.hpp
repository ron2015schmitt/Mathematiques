#ifndef MATRICKS__MOPERATORS_H
#define MATRICKS__MOPERATORS_H 


namespace mathq {



  /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // matrix + matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Add<D> > 
  operator+(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Add<D> >(a,b);
  }



  // matrix - matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Subtract<D> > 
  operator-(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Subtract<D> >(a,b);
  }


  // matrix * matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Multiply<D> > 
  operator*(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Multiply<D> >(a,b);
  }


  // matrix / matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Divide<D> > 
  operator/(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,Fun_Divide<D> >(a,b);
  }



  // dotproduct operator (a|b)

  template <class D, class A, class B> 
  inline Matrix<D>
  operator|( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    const size_t   NR = a.Nrows();
    const size_t   NC = b.Ncols();
    const size_t   M = a.Ncols();
    const size_t   C1 = NR*M;


    Matrix<D> y(NR,NC);

    register size_t   i = 0;
    for(register size_t   n=0; n < C1; n+=M) 
      for(register size_t   c=0; c < NC; c++,i++) {
	size_t j = n;
	size_t k = c;
	const size_t   C2 = n+M-1;
	// using a local variable for the accumation saves a lot of CPU Time!!
	D result = a(j) * b(k);
	while (j<C2){
	  result += a((j+=1)) * b((k+=NC));
	} 
	y(i) = result;   
      }
    return  y;
  }





  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */


  // matrix + scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Add<D> > 
  operator+(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Add<D> >(a,b);
  }

  // scalar + matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Add<D> > 
  operator+(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Add<D> > (a,b);
  }


  // matrix - scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Subtract<D> > 
  operator-(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Subtract<D> >(a,b);
  }

  // scalar - matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Subtract<D> > 
  operator-(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Subtract<D> > (a,b);
  }

  // matrix * scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Multiply<D> > 
  operator*(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Multiply<D> >(a,b);
  }

  // scalar * matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Multiply<D> > 
  operator*(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Multiply<D> > (a,b);
  }

  // matrix / scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Divide<D> > 
  operator/(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Divide<D> >(a,b);
  }

  // scalar / matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Divide<D> > 
  operator/(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Divide<D> > (a,b);
  }






  // the following are defined for convenience

  // matrix + (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Add<D> > 
  operator+(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Add<D> >(a,b);
  }

  // (int scalar) + matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Add<D> > 
  operator+(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Add<D> > (a,b);
  }


  // matrix - (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Subtract<D> > 
  operator-(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Subtract<D> >(a,b);
  }

  // (int scalar) - matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Subtract<D> > 
  operator-(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Subtract<D> > (a,b);
  }

  // matrix * (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Multiply<D> > 
  operator*(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Multiply<D> >(a,b);
  }

  // (int scalar) * matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Multiply<D> > 
  operator*(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Multiply<D> > (a,b);
  }

  // matrix / (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,Fun_Divide<D> > 
  operator/(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,Fun_Divide<D> >(a,b);
  }

  // (int scalar) / matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,Fun_Divide<D> > 
  operator/(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,Fun_Divide<D> > (a,b);
  }




  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */

  // +(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Plus<D> > 
  operator+(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Plus<D> >(a);
  }


  // -(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,Fun_Minus<D> > 
  operator-(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,Fun_Minus<D> >(a);
  }


  // mcast(matrix)

  template <class D2, class D1, class A> 
  inline MFuncOp<D2,MorE<D1,A>,Fun_Cast<D1,D2> > 
  mcast(const MorE<D1,A>& a)
  {
    return  MFuncOp<D2,MorE<D1,A>,Fun_Cast<D1,D2> >(a);
  }


  // mcast(matrix,nr,nc)

  template <class D2, class D1, class A> 
  inline MFuncReshape<D2,MorE<D1,A>,Fun_Cast<D1,D2> > 
  mcast(const MorE<D1,A>& a, const size_t   nr, const size_t   nc)
  {
    return  MFuncReshape<D2,MorE<D1,A>,Fun_Cast<D1,D2> >(a,nr,nc);
  }



  // mcast(vector)

  template <class D2, class D1, class A> 
  inline MFuncVec<D2,MArrayExpR<D1,A>,Fun_Cast<D1,D2> > 
  mcast(const MArrayExpR<D1,A>& a, const size_t   NR, const size_t   NC)
  {
    return  MFuncVec<D2,MArrayExpR<D1,A>,Fun_Cast<D1,D2> >(a,NR,NC);
  }


  // mcast(C-Array)

  template <class D2, class D1> 
  inline Matrix<D2> 
  mcast(const D1* dptr, const size_t   NR, const size_t   NC)
  {
    Matrix<D2> m(NR,NC);
    for(size_t i = 0; i<NR*NC; i++) 
      m(i) = static_cast<D2>(dptr[i]);
    return  m;
  }



  // mcast(FortranArray)

  template <class D2, class D1> 
  inline Matrix<D2> 
  mcastF(const D1* dptr, const size_t   NR, const size_t   NC)
  {
    Matrix<D2> y(NR,NC);
    const size_t   C1 = NR*NC-NR;
    register size_t   i = 0;
    for(register size_t   c = 0; c < NR; c++, i++) {
      register size_t   k = c;
      y(i) = static_cast<D2>(dptr[k]);
      while (k<C1) {
	y((i+=1)) = static_cast<D2>(dptr[k+=NR]);
      } 
    }
    return y;
  }




  
  // transpose ~(matrix)

  template <class D, class A> 
  inline Matrix<D>
  operator~(const MorE<D,A>& a)
  {
    // 0.75 secs
    const size_t   NR = a.Nrows();
    const size_t   NC = a.Ncols();
    const size_t   NN = a.size();
    const size_t   C1 = NN-NC;
    

    Matrix<D> y(NC,NR);



    register size_t   i = 0;
    for(register size_t   c = 0; c < NC; c++, i++) {
      register size_t   k = c;
      y(i) = a(k);
      while (k<C1) {
	y((i+=1)) = a((k+=NC));
      } 
    }
    return  y;
  }





  /****************************************************************
   * functions that convert matrices into other objects
   *****************************************************************
   */


  // toCarray(matrix)

  template <class D2, class D1, class A> 
  inline D2*
  toCarray(const MorE<D1,A>& m) {


    const size_t   N = m.size();
    D2* dptr = new D2[N];
    for(size_t i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(m(i));
    return  dptr;
  }


  // toFarray(matrix)

  template <class D2, class D1, class A> 
  inline D2*
  toFarray(const MorE<D1,A>& m) {


    const size_t   NR = m.Nrows();
    //    const size_t   NC = m.Ncols();
    const size_t   N = m.size();
    D2* dptr = new D2[N];
    const size_t   C1 = N-NR;
    register size_t   i = 0;
    for(register size_t   c = 0; c < NR; c++, i++) {
      register size_t   k = c;
      dptr[k] = static_cast<D2>(m(i));
      while (k<C1) {
	dptr[k+=NR] = static_cast<D2>(m(i+=1));
      } 
    }
    return  dptr;
  }



  template <class A> 
  Vector<size_t> sub2ind(const MorE<size_t,A>& subs, const size_t   NC) {
    const size_t   N = subs.Nrows();
    Vector<size_t> ii(N);
 

    for (size_t i = 0;  i <N; i++)
      ii[i] = NC*subs(i,0) + subs(i,1);

    return ii;
  }


  /****************************************************************************
   * Binary Functions/Operators that return scalars
   ****************************************************************************
   */












  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
  inline D sum( const MorE<D,A>& a ) {
    
 
    D result = a(0);

    for (register size_t   i = 1; i < a.size() ; i++ )
      result += a(i);
    
    return result;
  }



  // sumbyrow(a)
  template <class D, class A> 
  inline Vector<D> sumbyrow( const MorE<D,A>& a ) {
    
    const size_t   NR = a.Nrows();
    const size_t   NC = a.Ncols();
    Vector<D> y(NR);


    size_t   i = 0;
    for(size_t r = 0; r<NR; r++) {
      D temp=D();
      for(size_t c = 0; c<NC; c++,i++) {
	temp += a(i);
      }
      y[r] = temp;
    }
    
    return y;
  }


  // sumbycol(a)
  template <class D, class A> 
  inline Vector<D> sumbycol( const MorE<D,A>& a ) {
    
    const size_t   NR = a.Nrows();
    const size_t   NC = a.Ncols();
    Vector<D> y(NC);


    for(size_t c = 0; c<NC; c++) {
      size_t   LIMIT = NR*NC-NC+c+1;
      D temp=D();
      for(size_t i = c; i<LIMIT; i+=NC) {
	temp += a(i);
      }
      y[c] = temp;
    }
    return y;
  }





  // min(a)

  template <class D, class A> 
  inline D min( const MorE<D,A>& a ) {
    D result = a(0);
    for (register size_t   i = 1; i < a.size() ; i++ )
      result = std::min(result,a(i));
    return result;
  }



  // minbyrow(a)

  template <class D, class A> 
  inline Vector<D> minbyrow( const MorE<D,A>& a ) {
    
    const size_t   NR = a.Nrows();
    const size_t   NC = a.Ncols();
    Vector<D> y(NR);

    size_t   i = 0;
    for(size_t r = 0; r<NR; r++) {
      D temp = a(i); 
      i++;
      for(size_t c = 1; c<NC; c++,i++) {
	temp =  std::min(temp,a(i));
      }
      y[r] = temp;
    }
    return y;
  }



  // minbycol(a)

  template <class D, class A> 
  inline Vector<D> minbycol( const MorE<D,A>& a ) {
    
    const size_t   NR = a.Nrows();
    const size_t   NC = a.Ncols();
    Vector<D> y(NC);


    for(size_t c = 0; c<NC; c++) {
      size_t   LIMIT = NR*NC-NC+c+1;
      size_t   i = c;
      D temp=a(i);
      for(i+=NC; i<LIMIT; i+=NC) {
	temp = std::min(temp,a(i));
      }
      y[c] = temp;
    }
    return y;
  }



  // max(a)

  template <class D, class A> 
  inline D max( const MorE<D,A>& a ) {
    
 
    D result = a(0);

    for (register size_t   i = 1; i < a.size() ; i++ )
      result = std::max(result,a(i));
    
    return result;
  }






  // maxbyrow(a)

  template <class D, class A> 
  inline Vector<D> maxbyrow( const MorE<D,A>& a ) {
    
    const size_t   NR = a.Nrows();
    const size_t   NC = a.Ncols();
    Vector<D> y(NR);

    size_t   i = 0;
    for(size_t r = 0; r<NR; r++) {
      D temp = a(i); 
      i++;
      for(size_t c = 1; c<NC; c++,i++) {
	temp =  std::max(temp,a(i));
      }
      y[r] = temp;
    }
    return y;
  }



  // maxbycol(a)

  template <class D, class A> 
  inline Vector<D> maxbycol( const MorE<D,A>& a ) {
    
    const size_t   NR = a.Nrows();
    const size_t   NC = a.Ncols();
    Vector<D> y(NC);


    for(size_t c = 0; c<NC; c++) {
      size_t   LIMIT = NR*NC-NC+c+1;
      size_t   i = c;
      D temp=a(i);
      for(i+=NC; i<LIMIT; i+=NC) {
	temp = std::max(temp,a(i));
      }
      y[c] = temp;
    }
    return y;
  }






  // tr(a)  trace

  template <class D, class A> 
  inline D tr( const MorE<D,A>& a ) {
    
 
    D result = a(0);
    size_t   Nmin;
    if (a.Nrows() < a.Ncols())
      Nmin=a.Nrows();
    else
      Nmin=a.Ncols();
    
    const size_t   N=Nmin;

    for (register size_t   i = 1; i < N ; i++ )
      result += a(i,i);
    
    return result;
  }


};



#endif 
