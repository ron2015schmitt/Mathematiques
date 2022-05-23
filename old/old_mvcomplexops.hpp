#ifndef MVCOMPLEXOPS_H
#define MVCOMPLEXOPS_H 1



namespace mathq {




  // outer product: complexvector ^ realvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const TensorR<std::complex<D>,A>& a, const TensorR<D,B>& b)
  {
    const size_type NC = a.size();
    const size_type NR = b.size();
    Matrix<std::complex<D> > y(NR,NC);


    register index_type i=0;
    for(register index_type r=0; r < NR; r++) 
      for(register index_type c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }


  // outer product: realvector ^ complexvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const TensorR<D,A>& a, const TensorR<std::complex<D>,B>& b)
  {
    const size_type NC = a.size();
    const size_type NR = b.size();
    Matrix<std::complex<D> > y(NR,NC);


    register index_type i=0;
    for(register index_type r=0; r < NR; r++) 
      for(register index_type c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }









  // dotproduct operator (complex matrix|real vector)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const MorE<std::complex<D> ,A>& a, const  TensorR<D,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type M = a.Ncols();
    const index_type C1 = NR*M;
    const index_type C2 = M-1;

    Vector<std::complex<D> > y(NR);


    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M, i++) {
      index_type j = n;
      index_type k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (realvector|complexmatrix)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const TensorR<D,A>& a, const  MorE<std::complex<D> ,B>& b ) {
    const size_type NC = b.Ncols();
    const size_type M = b.Nrows();

    Vector<std::complex<D> > y(NC);


    register index_type i = 0;
    for(register index_type c=0; c < NC; c++,i++) {
      index_type j = 0;
      index_type k = c;
      const index_type C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }







  // dotproduct operator (realmatrix|complexvector)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const MorE<D,A>& a, const  TensorR<std::complex<D> ,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type M = a.Ncols();
    const index_type C1 = NR*M;
    const index_type C2 = M-1;

    Vector<std::complex<D> > y(NR);


    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M, i++) {
      index_type j = n;
      index_type k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (complexvector|realmatrix)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const TensorR<std::complex<D> ,A>& a, const  MorE<D,B>& b ) {
    const size_type NC = b.Ncols();
    const size_type M = b.Nrows();

    Vector<std::complex<D> > y(NC);


    register index_type i = 0;
    for(register index_type c=0; c < NC; c++,i++) {
      index_type j = 0;
      index_type k = c;
      const index_type C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }




};

#endif 
