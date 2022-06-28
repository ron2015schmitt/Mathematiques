#ifndef MVOPERATORS_H
#define MVOPERATORS_H


namespace mathq {




  // outer product: vector ^ vector

  template <class D, class A, class B> 
  inline Matrix<D>
  operator^(const MArrayExpR<D,A>& a, const MArrayExpR<D,B>& b)
  {
    const size_t NC = a.size();
    const size_t NR = b.size();
    Matrix<D> y(NR,NC);


    register size_t i=0;
    for(register size_t r=0; r < NR; r++) 
      for(register size_t c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }



  // vector = diagonal(Matrix)

  template <class D, class A> 
  inline Vector<D>
  diag(const MorE<D,A>& a)
  {
    size_t Nmin;
    if (a.Nrows() < a.Ncols())
      Nmin=a.Nrows();
    else
      Nmin=a.Ncols();
    const size_t N=Nmin;
    Vector<D> v(N);


    for (register size_t i = 0; i < N ; i++ )
      v[i] = a(i,i);
    return v;
  }





  // diagmat(vector)

  template <class D, class A> 
  inline Matrix<D>
  diagmat(const MArrayExpR<D,A>& a)
  {
    const size_t N = a.size();
    Matrix<D> y(N,N);


    for(register size_t i=0; i < N; i++) 
      y(i,i) = a[i];   

    return  y;
  }

   


  // dotproduct operator (matrix|vector)

  template <class D, class A, class B> 
  inline Vector<D>
  operator|( const MorE<D,A>& a, const  MArrayExpR<D,B>& b ) {
    const size_t NR = a.Nrows();
    const size_t M = a.Ncols();
    const size_t C1 = NR*M;
    const size_t C2 = M-1;

    Vector<D> y(NR);


    register size_t i = 0;
    for(register size_t n=0; n < C1; n+=M, i++) {
      size_t j = n;
      size_t k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      D result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (vector|matrix)

  template <class D, class A, class B> 
  inline Vector<D>
  operator|( const MArrayExpR<D,A>& a, const  MorE<D,B>& b ) {
    const size_t NC = b.Ncols();
    const size_t M = b.Nrows();

    Vector<D> y(NC);


    register size_t i = 0;
    for(register size_t c=0; c < NC; c++,i++) {
      size_t j = 0;
      size_t k = c;
      const size_t C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      D result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }




};

#endif 
