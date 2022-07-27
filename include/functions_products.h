#ifndef MATHQ__FUNCTIONS_PRODUCTS
#define MATHQ__FUNCTIONS_PRODUCTS 1

namespace mathq
{



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

   // dot(a,b) <==> (a|b)
   // TODO: rewrite so that (a|b) is defined only floating point base types so that bitwise operators can be used


  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth1, size_t depth2, size_t rank1, size_t rank2> 
  auto operator|(const ExpressionR<A, E1, NT1, depth1, rank1>& x1, const ExpressionR<B, E2, NT2, depth2, rank2>& x2) {
    OUTPUT("operator|");
    return dot(x1, x2);
  }

   // dot(a,b)

  template <class E1, class E2>
  auto dot(const Scalar<E1>& a, const Scalar<E2>& b) {
    return a() * b();
  }

   // TODO: realtime check (in debug mode) that deep dimensions of E1 and E2 are compatible


   // (1A: T • T) MultiArray<E1(NT1)> | MultiArray<E2(NT2)>

    // TODO:" finish this"
  //  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank1, size_t rank2>
  //  auto dot(const ExpressionR<A, E1, NT1, depth, rank1> &x1, const ExpressionR<B, E2, NT2, depth, 2> &x2)
  //  {
  //    typedef typename AddType<NT1, NT2>::Type NT3;
  //    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3; // see TODO note above
  //     const size_t dims1 = x1.dims();
  //     const size_t dims2 = x2.dims();
  //     const size_t rank3 = rank1 + rank2 - 2;

  //     DISP(dims1);

  //     // const size_t M1 = dims1[rank1-1];
  //     // const size_t M2 = dims2[0];
  //     // const size_t& M = M1;
  //     // Dimensions dims3 = Dimensions::reduce(dims1, dims2);
  //     // MultiArray<E3,rank3>& result = *(new MultiArray<E3,rank3>(dims3));

  //     // result = 0;
  //     // Indices inds1(rank);
  //     // inds1.clear();
  //     // Indices inds2(rank);
  //     // inds2.clear();
  //     // for (size_t ii = 0; ii < N1; ii++) {
  //     //   inds1[rank-1] = ii;
  //     //   inds2[0] = ii;
  //     //   *result += v1[ii] * v2[ii];
  //     // }
  //     // return result;
  //     return 0;
  //  }



   // (1B: V • V) Vector<E1(NT1)> | Vector<E2(NT2)>

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 1>& v1, const ExpressionR<B, E2, NT2, depth, 1>& v2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3; // see TODO note above
    E3* result = new E3;
    *result = 0;
    for (size_t i = 0; i < v1.size(); i++) {
      *result += v1[i] * v2[i];
    }
    return *result;
  }

  // (1C: depth • V) Matrix<E1(NT1)> | Vector<E2(NT2)>
  //             Matrix -> rank = 2
  //             Vector -> rank = 1

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 2>& m1, const ExpressionR<B, E2, NT2, depth, 1>& v2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3; // see TODO note above

    DISP(m1);
    size_t Nrows = m1.dims()[0];
    size_t Ncols = m1.dims()[1];
    size_t i = 0;
    Vector<E3> vout(Nrows);
    E3* temp = new E3;
    // row major
    for (size_t r = 0; r < Nrows; r++) {
      *temp = 0;
      for (size_t c = 0; c < Ncols; c++) {
        *temp += m1[i++] * v2[c];
      }
      vout[r] = *temp;
    }
    return vout;
  }

  // (1D: V • depth) Vector<E1(NT1)> | Matrix<E2(NT2)>
  //             Vector -> rank = 1
  //             Matrix -> rank = 2
  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 1>& v1, const ExpressionR<B, E2, NT2, depth, 2>& m2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3; // see TODO note above

    size_t Nrows = m2.dims()[0];
    size_t Ncols = m2.dims()[1];
    size_t i = 0;
    Vector<E3> vout(Ncols);
    E3* temp = new E3;
    // row major
    for (size_t c = 0; c < Ncols; c++) {
      *temp = 0;
      i = c;
      for (size_t r = 0; r < Nrows; r++) {
        *temp += v1[r] * m2[i];
        i += Ncols;
      }
      vout[c] = *temp;
    }
    return vout;
  }

  // (1E: depth • depth) Matrix<E1(NT1)> | Matrix<E2(NT2)>
  //             Matrix -> rank = 2

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 2>& m1, const ExpressionR<B, E2, NT2, depth, 2>& m2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3; // see TODO note above

    size_t Nrows = m1.dims()[0];
    size_t Nsum = m1.dims()[1];
    size_t Ncols = m2.dims()[1];
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    Matrix<E3> m3(Dimensions({Nrows, Ncols}));
    E3* temp = new E3;
    // row major
    for (size_t r = 0; r < Nrows; r++) {
      for (size_t c = 0; c < Ncols; c++) {
        *temp = 0;
        i = Nsum * r;
        j = c;
        for (size_t n = 0; n < Nsum; n++) {
          *temp += m1[i++] * m2[j];
          j += Ncols;
        }
        m3[k++] = *temp;
      }
    }
    return m3;
  }

  // (4A) MultiArray<NT1,rank,depth> + MultiArray<NT2,rank,1>

  // Depending on rank and dimensions, this may be top-level or element wise Addition
  // Note: D2==1 -> E2==NT2

  // TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
  // TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

  // TODO: implement
  // template <class A, class B, class E1, class NT1, class NT2, size_t D1, size_t D2, size_t rank,
  //           EnableIf<(D1 >= 2) && (D2 == 1) && (IsMultiArrayOrExpression< E1>::value)> = 0>
  // auto dot(const ExpressionR<A, E1, NT1, D1, rank> &x1, const ExpressionR<B, NT2, NT2, D2, rank> &x2)
  // {

  //   // NOT SURE WHICH OF THE THREE IS BEST
  //   //    typedef typename B::ConcreteType E2;
  //   //    typedef B E2;
  //   typedef ExpressionR<B, NT2, NT2, D2, rank> E2;

  //   typedef typename AddType<NT1, NT2>::Type NT3;
  //   typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3; // see TODO note above
  //   constexpr size_t D3 = D1;
  //   //    MOUT << "C" <<std::endl;
  //   return ExpressionR_Binary<ExpressionR<A, E1, NT1, D1, rank>,
  //                     ExpressionR<B, NT2, NT2, D2, rank>,
  //                     E1, NT2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
  //                     FUNCTOR_add<E1, E2, E3, NT1, NT2, NT3>>(x1, x2);
  // }

  // (4B) MultiArray<NT1,rank,1> + MultiArray<NT2,rank,depth>

  // Depending on rank and dimensions, this may be top-level or element wise Addition
  // Note: D1==1 -> E1==NT1

  // TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
  // TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

  // TODO: implement

  // template <class A, class B, class E2, class NT1, class NT2, size_t D1, size_t D2, size_t rank,
  //           EnableIf<(D1 == 1) && (D2 >= 2) && (IsMultiArrayOrExpression< E2>::value)> = 0>
  // auto dot(const ExpressionR<A, NT1, NT1, D1, rank> &x1, const ExpressionR<B, E2, NT2, D2, rank> &x2)
  // {
  //   // NOT SURE WHICH OF THE THREE IS BEST
  //   //    typedef typename A::ConcreteType E1;
  //   //    typedef A E1;
  //   typedef ExpressionR<A, NT1, NT1, D1, rank> E1;
  //   typedef typename AddType<NT1, NT2>::Type NT3;
  //   typedef typename NumberTrait<E2, NT3>::ReplacedNumberType E3; // see TODO note above
  //   constexpr size_t D3 = D2;
  //   //    MOUT << "Number" <<std::endl;
  //   return ExpressionR_Binary<ExpressionR<A, NT1, NT1, D1, rank>,
  //                     ExpressionR<B, E2, NT2, D2, rank>,
  //                     NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
  //                     FUNCTOR_add<E1, E2, E3, NT1, NT2, NT3>>(x1, x2);
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
     *  product: ExpressionR ExpressionR
     ****************************************************************************
     */
     // --------------------  dot (inner) product --------------------------------

     //   // (a|b)

     // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
     // auto dot(const ExpressionR<A,E1,NT1,depth,rank>& a, const ExpressionR<B,E2,NT2,depth,rank>& b) {
     //   typedef typename MultType<NT1,NT2>::Type NT3;
     //   typedef typename NumberTrait<E1,NT3>::ReplacedNumberType E3;   // see TODO note above

     //     // (Scalar|Scalar)
     //     if ((a.rank() == 0) && (b.rank() == 0)) {
     //       return a[0]*b[0];
     //     }

     //     // (Vector|Vector)
     //     if ((a.rank() == 1) && (b.rank() == 1)) {
     //       Number result = Number(0);
     //       for (size_t i = a.total_size(); i--;) {
     // 	result += a[i]*b[i];
     //       }
     //       return result;
     //     }
     //   }

     //   // dot(a,b)

     // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
     // auto dot(const ExpressionR<A,E1,NT1,depth,rank>& a, const ExpressionR<B,E2,NT2,depth,rank>& b) {
     //     return (a|b);
     //   }

     //   // --------------------  tensor (outer) product --------------------------------

     //   // (a&b)

     // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
     // auto operator&(const ExpressionR<A,E1,NT1,depth,rank>& a, const ExpressionR<B,E2,NT2,depth,rank>& b) {
     //   typedef typename MultType<NT1,NT2>::Type NT3;
     //   typedef typename NumberTrait<E1,NT3>::ReplacedNumberType E3;   // see TODO note above

     //     // (Scalar&Scalar)
     //     if ((a.rank() == 0) && (b.rank() == 0)) {
     //       return a[0]*b[0];
     //     }

     //   }

     //   // prodt(a,b)

     // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
     // auto prodt(const ExpressionR<A,E1,NT1,depth,rank>& a, const ExpressionR<B,E2,NT2,depth,rank>& b) {
     //     return (a&b);
     //   }

     //   // -------------------- antisymmetric (wedge)  product -----------------------

     //   // (a^b)

     // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
     // auto operator^(const ExpressionR<A,E1,NT1,depth,rank>& a, const ExpressionR<B,E2,NT2,depth,rank>& b) {
     //   typedef typename MultType<NT1,NT2>::Type NT3;
     //   typedef typename NumberTrait<E1,NT3>::ReplacedNumberType E3;   // see TODO note above

     //     // (Scalar^Scalar)
     //     if ((a.rank() == 0) && (b.rank() == 0)) {
     //       return a[0]*b[0];
     //     }

     //   }

     //   // prodw(a,b)

     // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
     // auto prodw(const ExpressionR<A,E1,NT1,depth,rank>& a, const ExpressionR<B,E2,NT2,depth,rank>& b) {
     //     return (a^b);
     //   }
};

#endif
