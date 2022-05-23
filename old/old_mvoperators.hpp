#ifndef MVOPERATORS_H
#define MVOPERATORS_H


namespace mathq {




  // outer product: vector ^ vector

  template <class D, class A, class B> 
  inline Matrix<D>
  operator^(const TensorR<D,A>& a, const TensorR<D,B>& b)
  {
    const size_type NC = a.size();
    const size_type NR = b.size();
    Matrix<D> y(NR,NC);


    register index_type i=0;
    for(register index_type r=0; r < NR; r++) 
      for(register index_type c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }



  // vector = diagonal(Matrix)

  template <class D, class A> 
  inline Vector<D>
  diag(const MorE<D,A>& a)
  {
    size_type Nmin;
    if (a.Nrows() < a.Ncols())
      Nmin=a.Nrows();
    else
      Nmin=a.Ncols();
    const size_type N=Nmin;
    Vector<D> v(N);


    for (register index_type i = 0; i < N ; i++ )
      v[i] = a(i,i);
    return v;
  }





  // diagmat(vector)

  template <class D, class A> 
  inline Matrix<D>
  diagmat(const TensorR<D,A>& a)
  {
    const size_type N = a.size();
    Matrix<D> y(N,N);


    for(register index_type i=0; i < N; i++) 
      y(i,i) = a[i];   

    return  y;
  }

   


  // dotproduct operator (matrix|vector)

  template <class D, class A, class B> 
  inline Vector<D>
  operator|( const MorE<D,A>& a, const  TensorR<D,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type M = a.Ncols();
    const index_type C1 = NR*M;
    const index_type C2 = M-1;

    Vector<D> y(NR);


    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M, i++) {
      index_type j = n;
      index_type k = 0;
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
  operator|( const TensorR<D,A>& a, const  MorE<D,B>& b ) {
    const size_type NC = b.Ncols();
    const size_type M = b.Nrows();

    Vector<D> y(NC);


    register index_type i = 0;
    for(register index_type c=0; c < NC; c++,i++) {
      index_type j = 0;
      index_type k = c;
      const index_type C2 = M-1;
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
