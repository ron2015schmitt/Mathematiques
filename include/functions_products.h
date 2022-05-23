#ifndef MATHQ__FUNCTIONS_PRODUCTS_H
#define MATHQ__FUNCTIONS_PRODUCTS_H 1

namespace mathq
{

  /****************************************************************************
   *  products: Scalar Scalar
   ****************************************************************************
   */

   // --------------------  dot (inner) product --------------------------------

   // dot(a,b)

  template <class E1, class E2>
  auto dot(const Scalar<E1>& a, const Scalar<E2>& b) {
    return a() * b();
  }

  // (a|b)

  // TODO: rewrite for only floating point base types
  template <class E1, class E2>
  auto operator|(const Scalar<E1>& a, const Scalar<E2>& b) {
    return dot(a, b);
  }

  // --------------------  tensor (outer) product --------------------------------

  // prodt(a,b)

  template <class E1, class E2>
  auto prodt(const Scalar<E1>& a, const Scalar<E2>& b) {
    return a() * b();
  }

  // (a&b)
  // TODO: rewrite for only floating point base types

  template <class E1, class E2>
  auto operator&(const Scalar<E1>& a, const Scalar<E2>& b) {
    return prodt(a, b);
  }

  // -------------------- antisymmetric (wedge)  product -----------------------

  // prodw(a,b)

  template <class E1, class E2>
  auto prodw(const Scalar<E1>& a, const Scalar<E2>& b) {
    return 0;
  }

  // (a^b)
  // TODO: rewrite for only floating point base types

  template <class E1, class E2>
  auto operator^(const Scalar<E1>& a, const Scalar<E2>& b) {
    return prodw(a, b);
  }

  /****************************************************************************
   *  products: Vector Vector
   ****************************************************************************
   */

   // --------------------  dot (inner) product --------------------------------

   // (a|b)
   // TODO: rewrite for only floating point base types

   // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
   // EnableMethodIf<R == 1, typename MultType<D1, D2>::Type &> dot(const TensorR<A, E1, D1, M, R> &a, const TensorR<B, E2, D2, M, R> &b)
   // {

   //   // TensorRW<Matrix<E,NR,NC,D,M>,E,D,M,2> x;

   //   typedef typename MultType<D1, D2>::Type D3;
   //   typedef typename NumberType<E1, D3>::ReplaceTypeD E3; // see TODO note above

   //   E3 *result = new E3;
   //   *result = 0;
   //   for (index_type i = 0; i < a.deepsize(); i++)
   //   {
   //     *result += a[i] * b[i];
   //   }
   //   return *result;
   // }

   // // dot(a,b)

   // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
   // EnableMethodIf<R == 1, typename MultType<D1, D2>::Type &> operator|(const TensorR<A, E1, D1, M, R> &a, const TensorR<B, E2, D2, M, R> &b)
   // {
   //   return dot(a, b);
   // }

   // TODO: realtime check (in debug mode) that deep dimensions of E1 and E2 are compatible

   // (1A: T • T) Tensor<E1(D1)> | Tensor<E2(D2)>
   // TODO: implement this

   // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
   // auto operator|(const TensorR<A, E1, D1, M, R> &x1, const TensorR<B, E2, D2, M, R> &x2)
   // {
   //   typedef typename AddType<D1, D2>::Type D3;
   //   typedef typename NumberType<E1, D3>::ReplaceTypeD E3; // see TODO note above
   //   return TER_Binary<TensorR<A, E1, D1, M, R>,
   //                     TensorR<B, E2, D2, M, R>,
   //                     E1, E2, E3, D1, D2, D3, M, M, M, R, R, R,
   //                     FUNCTOR_add<E1, E2, E3, D1, D2, D3>>(x1, x2);
   // }

   // (1B: V • V) Vector<E1(D1)> | Vector<E2(D2)>

  template <class A, class B, class E1, class E2, class D1, class D2, int M>
  auto operator|(const TensorR<A, E1, D1, M, 1>& v1, const TensorR<B, E2, D2, M, 1>& v2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename NumberType<E1, D3>::ReplaceTypeD E3; // see TODO note above
    E3* result = new E3;
    *result = 0;
    for (index_type i = 0; i < v1.deepsize(); i++) {
      *result += v1[i] * v2[i];
    }
    return *result;
  }

  // (1C: M • V) Matrix<E1(D1)> | Vector<E2(D2)>
  //             Matrix -> R = 2
  //             Vector -> R = 1

  template <class A, class B, class E1, class E2, class D1, class D2, int M>
  auto operator|(const TensorR<A, E1, D1, M, 2>& m1, const TensorR<B, E2, D2, M, 1>& v2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename NumberType<E1, D3>::ReplaceTypeD E3; // see TODO note above

    index_type Nrows = m1.dims()[0];
    index_type Ncols = m1.dims()[1];
    index_type i = 0;
    Vector<E3> vout(Nrows);
    E3* temp = new E3;
    // row major
    for (index_type r = 0; r < Nrows; r++) {
      *temp = 0;
      for (index_type c = 0; c < Ncols; c++) {
        *temp += m1[i++] * v2[c];
      }
      vout[r] = *temp;
    }
    return vout;
  }

  // (1D: V • M) Vector<E1(D1)> | Matrix<E2(D2)>
  //             Vector -> R = 1
  //             Matrix -> R = 2

  template <class A, class B, class E1, class E2, class D1, class D2, int M>
  auto operator|(const TensorR<A, E1, D1, M, 1>& v1, const TensorR<B, E2, D2, M, 2>& m2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename NumberType<E1, D3>::ReplaceTypeD E3; // see TODO note above

    index_type Nrows = m2.dims()[0];
    index_type Ncols = m2.dims()[1];
    index_type i = 0;
    Vector<E3> vout(Ncols);
    E3* temp = new E3;
    // row major
    for (index_type c = 0; c < Ncols; c++) {
      *temp = 0;
      i = c;
      for (index_type r = 0; r < Nrows; r++) {
        *temp += v1[r] * m2[i];
        i += Ncols;
      }
      vout[c] = *temp;
    }
    return vout;
  }

  // (1E: M • M) Vector<E1(D1)> | Matrix<E2(D2)>
  //             Matrix -> R = 2

  template <class A, class B, class E1, class E2, class D1, class D2, int M>
  auto operator|(const TensorR<A, E1, D1, M, 2>& m1, const TensorR<B, E2, D2, M, 2>& m2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename NumberType<E1, D3>::ReplaceTypeD E3; // see TODO note above

    index_type Nrows = m1.dims()[0];
    index_type Nsum = m1.dims()[1];
    index_type Ncols = m2.dims()[1];
    index_type i = 0;
    index_type j = 0;
    index_type k = 0;
    Matrix<E3> m3(Nrows, Ncols);
    E3* temp = new E3;
    // row major
    for (index_type r = 0; r < Nrows; r++) {
      for (index_type c = 0; c < Ncols; c++) {
        *temp = 0;
        i = Nsum * r;
        j = c;
        for (index_type n = 0; n < Nsum; n++) {
          *temp += m1[i++] * m2[j];
          j += Ncols;
        }
        m3[k++] = *temp;
      }
    }
    return m3;
  }

  // (4A) Tensor<D1,R,M> + Tensor<D2,R,1>

  // Depending on rank and dimensions, this may be top-level or element wise Addition
  // Note: M2==1 -> E2==D2

  // TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
  // TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

  // TODO: implement
  // template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
  //           EnableIf<(M1 >= 2) && (M2 == 1) && (IsMathqContainer< E1>::value)> = 0>
  // auto operator|(const TensorR<A, E1, D1, M1, R> &x1, const TensorR<B, D2, D2, M2, R> &x2)
  // {

  //   // NOT SURE WHICH OF THE THREE IS BEST
  //   //    typedef typename B::XType E2;
  //   //    typedef B E2;
  //   typedef TensorR<B, D2, D2, M2, R> E2;

  //   typedef typename AddType<D1, D2>::Type D3;
  //   typedef typename NumberType<E1, D3>::ReplaceTypeD E3; // see TODO note above
  //   constexpr int M3 = M1;
  //   //    MOUT << "C" <<std::endl;
  //   return TER_Binary<TensorR<A, E1, D1, M1, R>,
  //                     TensorR<B, D2, D2, M2, R>,
  //                     E1, D2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
  //                     FUNCTOR_add<E1, E2, E3, D1, D2, D3>>(x1, x2);
  // }

  // (4B) Tensor<D1,R,1> + Tensor<D2,R,M>

  // Depending on rank and dimensions, this may be top-level or element wise Addition
  // Note: M1==1 -> E1==D1

  // TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
  // TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

  // TODO: implement

  // template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
  //           EnableIf<(M1 == 1) && (M2 >= 2) && (IsMathqContainer< E2>::value)> = 0>
  // auto operator|(const TensorR<A, D1, D1, M1, R> &x1, const TensorR<B, E2, D2, M2, R> &x2)
  // {
  //   // NOT SURE WHICH OF THE THREE IS BEST
  //   //    typedef typename A::XType E1;
  //   //    typedef A E1;
  //   typedef TensorR<A, D1, D1, M1, R> E1;
  //   typedef typename AddType<D1, D2>::Type D3;
  //   typedef typename NumberType<E2, D3>::ReplaceTypeD E3; // see TODO note above
  //   constexpr int M3 = M2;
  //   //    MOUT << "D" <<std::endl;
  //   return TER_Binary<TensorR<A, D1, D1, M1, R>,
  //                     TensorR<B, E2, D2, M2, R>,
  //                     D1, E2, E3, D1, D2, D3, M1, M2, M3, R, R, R,
  //                     FUNCTOR_add<E1, E2, E3, D1, D2, D3>>(x1, x2);
  // }

  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------

  // -------------------- cross  product -----------------------

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

     //   // (a|b)

     // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
     // auto operator|(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
     //   typedef typename MultType<D1,D2>::Type D3;
     //   typedef typename NumberType<E1,D3>::ReplaceTypeD E3;   // see TODO note above

     //     // (Scalar|Scalar)
     //     if ((a.ndims() == 0) && (b.ndims() == 0)) {
     //       return a[0]*b[0];
     //     }

     //     // (Vector|Vector)
     //     if ((a.ndims() == 1) && (b.ndims() == 1)) {
     //       D result = D(0);
     //       for (index_type i = a.deepsize(); i--;) {
     // 	result += a[i]*b[i];
     //       }
     //       return result;
     //     }
     //   }

     //   // dot(a,b)

     // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
     // auto dot(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
     //     return (a|b);
     //   }

     //   // --------------------  tensor (outer) product --------------------------------

     //   // (a&b)

     // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
     // auto operator&(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
     //   typedef typename MultType<D1,D2>::Type D3;
     //   typedef typename NumberType<E1,D3>::ReplaceTypeD E3;   // see TODO note above

     //     // (Scalar&Scalar)
     //     if ((a.ndims() == 0) && (b.ndims() == 0)) {
     //       return a[0]*b[0];
     //     }

     //   }

     //   // prodt(a,b)

     // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
     // auto prodt(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
     //     return (a&b);
     //   }

     //   // -------------------- antisymmetric (wedge)  product -----------------------

     //   // (a^b)

     // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
     // auto operator^(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
     //   typedef typename MultType<D1,D2>::Type D3;
     //   typedef typename NumberType<E1,D3>::ReplaceTypeD E3;   // see TODO note above

     //     // (Scalar^Scalar)
     //     if ((a.ndims() == 0) && (b.ndims() == 0)) {
     //       return a[0]*b[0];
     //     }

     //   }

     //   // prodw(a,b)

     // template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
     // auto prodw(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
     //     return (a^b);
     //   }
};

#endif
