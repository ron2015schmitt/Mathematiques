#ifndef MCOMPLEXOPS_H
#define MCOMPLEXOPS_H



namespace mathq {



  /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // complexmatrix + realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_AddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_AddCR<D> >(a,b);
  }
  // realmatrix + complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_AddRC<D> > 
  operator+(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_AddRC<D> >(a,b);
  }

  // complexmatrix - realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_SubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_SubtractCR<D> >(a,b);
  }
  // realmatrix - complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_SubtractRC<D> > 
  operator-(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_SubtractRC<D> >(a,b);
  }
  // complexmatrix * realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_MultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_MultiplyCR<D> >(a,b);
  }
  // realmatrix * complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_MultiplyRC<D> > 
  operator*(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_MultiplyRC<D> >(a,b);
  }

  // complexmatrix / realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_DivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,Fun_DivideCR<D> >(a,b);
  }
  // realmatrix / complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_DivideRC<D> > 
  operator/(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,Fun_DivideRC<D> >(a,b);
  }




  // *** functions that return a complex matrix from 2 real matrixs ***

  // mpolar(r,phi)

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,Fun_Polar<D> > 
  mpolar(const MorE<D,A>& r, const MorE<D,B>& phi)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,Fun_Polar<D> >(r,phi);
  }


  // mcomplex(x,y)

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,Fun_Complex<D> > 
  mcomplex(const MorE<D,A>& x, const MorE<D,B>& y)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,Fun_Complex<D> >(x,y);
  }




  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */

  //elementwise powers
  // pow_el(complexmatrix,realscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_PowCR<D> > 
  pow_el(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  CMatOpScal<D,MorE<std::complex<D>,A>,Fun_PowCR<D> >(a,b);
  }

  // pow_el(complexmatrix,intscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_PowCR<D> > 
  pow_el(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  CMatOpScal<D,MorE<std::complex<D>,A>,Fun_PowCR<D> >(a,static_cast<D>(b));
  }

  // pow_el(realscalar,complexmatrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_PowRC<D> > 
  pow_el(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  CScalOpMat<D,MorE<std::complex<D>,B>,Fun_PowRC<D> >(a,b);
  }

  // pow_el(intscalar,complexmatrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_PowRC<D> > 
  pow_el(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  CScalOpMat<D,MorE<std::complex<D>,B>,Fun_PowRC<D> >(static_cast<D>(a),b);
  }


 

  // mcomplex(matrix,realscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<D,A>,Fun_Complex<D > > 
  mcomplex(const MorE<D,A>& a, const D b)
  {
    return  CMatOpScal<D,MorE<D,A>,Fun_Complex<D > >(a,b);
  }
  // mcomplex(matrix,intscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<D,A>,Fun_Complex<D > > 
  mcomplex(const MorE<D,A>& a, const int b)
  {
    return  CMatOpScal<D,MorE<D,A>,Fun_Complex<D > >(a,static_cast<D>(b));
  }

  // mcomplex(realscalar,matrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<D,B>,Fun_Complex<D > > 
  mcomplex(const D a, const MorE<D,B>& b)
  {
    return  CScalOpMat<D,MorE<D,B>,Fun_Complex<D > >(a,b);
  }
  // mcomplex(intscalar,matrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<D,B>,Fun_Complex<D > > 
  mcomplex(const int a, const MorE<D,B>& b)
  {
    return  CScalOpMat<D,MorE<D,B>,Fun_Complex<D > >(static_cast<D>(a),b);
  }




  




  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */

  // realmatrix + complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,Fun_AddRC<D> > 
  operator+(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,Fun_AddRC<D> >( a,b );
  }

  // complexscalar +  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,Fun_AddCR<D> > 
  operator+(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,Fun_AddCR<D> >( a, b );
  }
  // complexmatrix + realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_AddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_AddCR<D> >(a,b);  
  }
  // complexmatrix + intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_AddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_AddCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar + complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_AddRC<D> > 
  operator+(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_AddRC<D> >(a,b);  
  }
  // intscalar + complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_AddRC<D> > 
  operator+(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_AddRC<D > >(static_cast<D>(a),b);  
  }



  // realmatrix - complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,Fun_SubtractRC<D> > 
  operator-(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,Fun_SubtractRC<D> >( a,b );
  }

  // complexscalar -  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,Fun_SubtractCR<D> > 
  operator-(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,Fun_SubtractCR<D> >( a, b );
  }
  // complexmatrix - realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_SubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_SubtractCR<D> >(a,b);  
  }
  // complexmatrix - intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_SubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_SubtractCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar - complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_SubtractRC<D> > 
  operator-(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_SubtractRC<D> >(a,b);  
  }
  // intscalar - complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_SubtractRC<D> > 
  operator-(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_SubtractRC<D > >(static_cast<D>(a),b);  
  }


  // realmatrix * complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,Fun_MultiplyRC<D> > 
  operator*(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,Fun_MultiplyRC<D> >( a,b );
  }

  // complexscalar *  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,Fun_MultiplyCR<D> > 
  operator*(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,Fun_MultiplyCR<D> >( a, b );
  }
  // complexmatrix * realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_MultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_MultiplyCR<D> >(a,b);  
  }
  // complexmatrix * intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_MultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_MultiplyCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar * complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_MultiplyRC<D> > 
  operator*(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_MultiplyRC<D> >(a,b);  
  }
  // intscalar * complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_MultiplyRC<D> > 
  operator*(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_MultiplyRC<D > >(static_cast<D>(a),b);  
  }


  // division

  // realmatrix / complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>, MorE<D,A>,Fun_DivideRC<D> > 
  operator/(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D> ,MorE<D,A>,Fun_DivideRC<D> >( a,b );
  }

  // complexscalar /  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,Fun_DivideCR<D> > 
  operator/(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,Fun_DivideCR<D> >( a, b );
  }
  // complexmatrix / realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_DivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_DivideCR<D> >(a,b);  
  }
  // complexmatrix / intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,Fun_DivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,Fun_DivideCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar / complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_DivideRC<D> > 
  operator/(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_DivideRC<D> >(a,b);  
  }
  // intscalar / complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,Fun_DivideRC<D> > 
  operator/(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,Fun_DivideRC<D > >(static_cast<D>(a),b);  
  }



  









  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */

  // *** functions that return a complex matrix from a complex matrix ***

  // conj(complex matrix)

  template <class D, class A> 
  inline MFuncOp<std::complex<D>,MorE<std::complex<D>,A>,Fun_Conj<D> > 
  conj(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<std::complex<D>,MorE<std::complex<D>,A>,Fun_Conj<D> >(a);
  }



  // *** functions that return a real matrix from a complex matrix ***

  // abs(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,Fun_CAbs<D> > 
  abs(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,Fun_CAbs<D> >(a);
  }


  // arg(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,Fun_Arg<D> > 
  arg(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,Fun_Arg<D> >(a);
  }




  // real(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,Fun_Real<D> > 
  real(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,Fun_Real<D> >(a);
  }

  // imag(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,Fun_Imag<D> > 
  imag(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,Fun_Imag<D> >(a);
  }



  /****************************************************************************
   * Binary Functions/Operators that return complex matrices
   ****************************************************************************
   */



  // dotproduct operator (areal|bcomplex)

  template <class D, class A, class B> 
  inline  Matrix<std::complex<D> >  operator|( const MorE<D,A>& a, const  MorE<std::complex<D>,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type NC = b.Ncols();
    const size_type M = a.Ncols();
    const size_type C1 = NR*M;

    Matrix<std::complex<D> > y(NR,NC);

    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M) 
      for(register index_type c=0; c < NC; c++,i++) {
	index_type j = n;
	index_type k = c;
	const index_type C2 = n+M-1;
	// using a local variable for the accumation saves a lot of CPU Time!!
	std::complex<D> result = a(j) * b(k);
	while (j<C2){
	  result += a((j+=1)) * b((k+=NC));
	} 
	y(i) = result;   
      }
    return  y;
  }

  template <class D, class A, class B> 
  inline  Matrix<std::complex<D> >  operator|( const MorE<std::complex<D>,A>& a, const  MorE<D,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type NC = b.Ncols();
    const size_type M = a.Ncols();
    const size_type C1 = NR*M;

    Matrix<std::complex<D> > y(NR,NC);


    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M) 
      for(register index_type c=0; c < NC; c++,i++) {
	index_type j = n;
	index_type k = c;
	const index_type C2 = n+M-1;
	// using a local variable for the accumation saves a lot of CPU Time!!
	std::complex<D> result = a(j) * b(k);
	while (j<C2){
	  result += a((j+=1)) * b((k+=NC));
	} 
	y(i) = result;   
      }
    return  y;
  }





  /****************************************************************************
   * Unary Functions/Operators that return matrices
   ****************************************************************************
   */
  // adjoint adj(a)=conjugate(transpose(A))

  template <class D, class A>
  inline Matrix<std::complex<D> >
  adj(const MorE<std::complex<D>,A>& a)
  {
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    const size_type NN = a.size();
    const size_type C1 = NN-NC;


    Matrix<std::complex<D> > y(NC,NR);

    register index_type i = 0;
    for(register index_type c = 0; c < NC; c++, i++) {
      register index_type k = c;
      y(i) = conj(a(k));
      do {
        y((i+=1)) = conj(a((k+=NC)));
      } while (k<C1);
    }
    return  y;
  }



  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */







};

#endif 
