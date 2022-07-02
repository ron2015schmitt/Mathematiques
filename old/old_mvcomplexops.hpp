#ifndef MVCOMPLEXOPS_H
#define MVCOMPLEXOPS_H 1



namespace mathq {




  // outer product: complexvector ^ realvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const MArrayExpR<std::complex<D>,A>& a, const MArrayExpR<D,B>& b)
  {
    const size_t NC = a.size();
    const size_t NR = b.size();
    Matrix<std::complex<D> > y(NR,NC);


    register size_t i=0;
    for(register size_t r=0; r < NR; r++) 
      for(register size_t c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }


  // outer product: realvector ^ complexvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const MArrayExpR<D,A>& a, const MArrayExpR<std::complex<D>,B>& b)
  {
    const size_t NC = a.size();
    const size_t NR = b.size();
    Matrix<std::complex<D> > y(NR,NC);


    register size_t i=0;
    for(register size_t r=0; r < NR; r++) 
      for(register size_t c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }









  // dotproduct operator (complex matrix|real vector)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const MorE<std::complex<D> ,A>& a, const  MArrayExpR<D,B>& b ) {
    const size_t NR = a.Nrows();
    const size_t M = a.Ncols();
    const size_t C1 = NR*M;
    const size_t C2 = M-1;

    Vector<std::complex<D> > y(NR);


    register size_t i = 0;
    for(register size_t n=0; n < C1; n+=M, i++) {
      size_t j = n;
      size_t k = 0;
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
  operator|( const MArrayExpR<D,A>& a, const  MorE<std::complex<D> ,B>& b ) {
    const size_t NC = b.Ncols();
    const size_t M = b.Nrows();

    Vector<std::complex<D> > y(NC);


    register size_t i = 0;
    for(register size_t c=0; c < NC; c++,i++) {
      size_t j = 0;
      size_t k = c;
      const size_t C2 = M-1;
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
  operator|( const MorE<D,A>& a, const  MArrayExpR<std::complex<D> ,B>& b ) {
    const size_t NR = a.Nrows();
    const size_t M = a.Ncols();
    const size_t C1 = NR*M;
    const size_t C2 = M-1;

    Vector<std::complex<D> > y(NR);


    register size_t i = 0;
    for(register size_t n=0; n < C1; n+=M, i++) {
      size_t j = n;
      size_t k = 0;
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
  operator|( const MArrayExpR<std::complex<D> ,A>& a, const  MorE<D,B>& b ) {
    const size_t NC = b.Ncols();
    const size_t M = b.Nrows();

    Vector<std::complex<D> > y(NC);


    register size_t i = 0;
    for(register size_t c=0; c < NC; c++,i++) {
      size_t j = 0;
      size_t k = c;
      const size_t C2 = M-1;
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
