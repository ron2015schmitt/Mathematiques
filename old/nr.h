
#ifndef MATHQ_NR_H
#def MATHQ_NR_H

#include <nr.h>
#include <nrutil.h>

// Interface to Numerical Recipes in C

// should develop a set of routines to convert easily and in-place
// between NRC matrices & vectors and C matrices and vectors.


namespace mathq_nr {


  //
  // Given a matrix A, compute the singular value decomposition
  //
  //   A = U.W.transp(V)
  //
  // where U and V are orthogonal, and W is a diagonal matrix of singular values.
  // The singular values are positive and sorted by decreasing size.
  //
  // The m by n matrix A is the input (m>n)
  //

  inline int svd(
		 Matrix<double>& A, 
		 Matrix<double>& U, Vector<double>& W, Matrix<double>& V )
  {
    const size_type M = A.Nrows();
    const size_type N = A.Ncols();       // Dimensions of matrix.

    /*
      assert(m >= n);
      assert(n == (int)W.size());
      assert(n == (int)V.Nrows() && n == (int)V.Ncols());
    */

    // Allocate NRC-style matrices and vectors.
    double **aandu = numrec::dmatrix(1,M,1,N);
    double **v = numrec::dmatrix(1,N,1,N);
    double *w = numrec::dvector(1,N);

    // Copy the input matrix.
    for (size_type i = 1; i <= M; ++i) {
      for (size_type j = 1; j <= N; ++j) {
	aandu[i][j] = A(i-1,j-1);
      }
    }


    numrec::svdcmp(aandu,M,N,w,v);
    numrec::svdsrt(aandu,M,N,w,v);


    // Copy the results
    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
	U(i-1,j-1) = aandu[i][j];
      }
    }
    for (int i = 1; i <= N; ++i) {
      W[i-1] = w[i];
      for (int j = 1; j <= N; ++j) {
	V(i-1,j-1) = v[i][j];
      }
    }


    return 0;
  }



};



#endif
