#ifndef MATHQ__FUNCTIONS_PRODUCTS
#define MATHQ__FUNCTIONS_PRODUCTS 1

namespace mathq
{


  /****************************************************************************
   * dot(a,b)
   *
   * dot product (inner product)
   *
   * for non-integer Numbers can also use (a|b) notation
   ****************************************************************************
   */


   // OPERATOR |
   // TODO: rewrite so that (a|b) is defined only floating point base types so that bitwise operators can be used

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth1, size_t depth2, size_t rank1, size_t rank2>
  auto operator|(const ExpressionR<A, E1, NT1, depth1, rank1>& x1, const ExpressionR<B, E2, NT2, depth2, rank2>& x2) {
    // OUTPUT("operator|");
    return dot(x1, x2);
  }


  // ----------------------------------------------------
  //                 Equal Depth
  // ----------------------------------------------------


   // TODO: realtime check (in debug mode) that deep dimensions of E1 and E2 are compatible

   // (1: T • T) MultiArray<E1(NT1)> | MultiArray<E2(NT2)>

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank1, size_t rank2> class DotHelper;

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank1, size_t rank2>
  auto dot(const ExpressionR<A, E1, NT1, depth, rank1>& x1, const ExpressionR<B, E2, NT2, depth, rank2>& x2) {
    DotHelper x3 = DotHelper(x1, x2);
    return x3.result();
  }

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank1, size_t rank2>
  class DotHelper {
  public:
    constexpr static size_t rank3 = rank1 + rank2 - 2;

    using T1 = ExpressionR<A, E1, NT1, depth, rank1>;
    using T2 = ExpressionR<B, E2, NT2, depth, rank2>;
    using NT3 = typename AddType<NT1, NT2>::Type;
    using E3 = typename ReplaceNumberTrait<E1, NT3>::Type; // see TODO note above
    using T3 = MultiArray<E3, rank3>;

    const Dimensions dims1;
    const Dimensions dims2;
    const Dimensions dims3;
    const size_t Nsum;

    const T1& x1;
    const T2& x2;
    T3& x3;
    Indices inds1 = Indices(rank1);
    Indices inds2 = Indices(rank2);
    Indices inds3 = Indices(rank3);
    E3 temp;

    DotHelper(const T1& x1, const T2& x2) :
      dims1(x1.dims()),
      dims2(x2.dims()),
      dims3(Dimensions::reduce(dims1, dims2)),
      Nsum(dims2[0]),
      x1(x1),
      x2(x2),
      x3(*(new T3(dims3))) {
    }

    T3& result() {
      calc(0);
      return x3;
    }
    void calc(const size_t index_num) {
      if (index_num < rank3) {
        for (size_t k = 0; k < dims3[index_num]; k++) {
          inds3[index_num] = k;
          if (index_num < rank1 - 1) {
            inds1[index_num] = k;
          }
          else {
            inds2[index_num + 2 - rank1] = k;
          }
          calc(index_num + 1);
        }
      }
      else {
        temp = 0;
        //   inds1[rank1 - 1] = 99;inds2[0] = 99; MDISP(inds3,inds1,inds2);   // <-- useful for testing
        for (size_t n = 0; n < Nsum; n++) {
          inds1[rank1 - 1] = n;
          inds2[0] = n;
          temp += x1[inds1.index(dims1)] * x2[inds2.index(dims2)];
        }
        x3[inds3] = temp;
      }
    }

  };


  // (1A: S • S) Scalar<E1(NT1)> | Scalar<E2(NT2)>

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 0>& a, const ExpressionR<B, E2, NT2, depth, 0>& b) {
    return a[0] * b[0];
  }


  // (1B: V • V) Vector<E1(NT1)> | Vector<E2(NT2)>

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 1>& v1, const ExpressionR<B, E2, NT2, depth, 1>& v2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename ReplaceNumberTrait<E1, NT3>::Type E3; // see TODO note above
    E3* result = new E3;
    *result = 0;
    for (size_t i = 0; i < v1.size(); i++) {
      *result += v1[i] * v2[i];
    }
    return *result;
  }

  // (1C: M • V) Matrix<E1(NT1)> | Vector<E2(NT2)>
  //             Matrix -> rank = 2
  //             Vector -> rank = 1

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 2>& m1, const ExpressionR<B, E2, NT2, depth, 1>& v2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename ReplaceNumberTrait<E1, NT3>::Type E3; // see TODO note above

    // DISP(m1);
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

  // (1D: V • M) Vector<E1(NT1)> | Matrix<E2(NT2)>
  //             Vector -> rank = 1
  //             Matrix -> rank = 2
  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 1>& v1, const ExpressionR<B, E2, NT2, depth, 2>& m2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename ReplaceNumberTrait<E1, NT3>::Type E3; // see TODO note above

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

  // (1E: M • M) Matrix<E1(NT1)> | Matrix<E2(NT2)>
  //             Matrix -> rank = 2

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth>
  auto dot(const ExpressionR<A, E1, NT1, depth, 2>& m1, const ExpressionR<B, E2, NT2, depth, 2>& m2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename ReplaceNumberTrait<E1, NT3>::Type E3; // see TODO note above

    size_t Nrows = m1.dims()[0];
    size_t Nsum = m1.dims()[1];
    size_t Ncols = m2.dims()[1];
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    Matrix<E3> m3(Dimensions({ Nrows, Ncols }));
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

  // ----------------------------------------------------
  //                 Different Depths
  // ----------------------------------------------------

  // (4A) MultiArray<NT1,rank,depth> + MultiArray<NT2,rank,1>

  // Depending on rank and dimensions, this may be top-level or element wise Addition
  // Note: D2==1 -> E2==NT2

  // TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
  // TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2

  // TODO: implement
  // template <class A, class B, class E1, class NT1, class NT2, size_t D1, size_t D2, size_t rank,
  //           EnableIf<(D1 >= 2) && (D2 == 1) && (IsReadableExpressionOrArray<E1>::value)> = 0>
  // auto dot(const ExpressionR<A, E1, NT1, D1, rank> &x1, const ExpressionR<B, NT2, NT2, D2, rank> &x2)
  // {

  //   // NOT SURE WHICH OF THE THREE IS BEST
  //   //    typedef typename B::ConcreteType E2;
  //   //    typedef B E2;
  //   typedef ExpressionR<B, NT2, NT2, D2, rank> E2;

  //   typedef typename AddType<NT1, NT2>::Type NT3;
  //   typedef typename NumberTrait<E1, NT3>::Type E3; // see TODO note above
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
  //           EnableIf<(D1 == 1) && (D2 >= 2) && (IsReadableExpressionOrArray<E2>::value)> = 0>
  // auto dot(const ExpressionR<A, NT1, NT1, D1, rank> &x1, const ExpressionR<B, E2, NT2, D2, rank> &x2)
  // {
  //   // NOT SURE WHICH OF THE THREE IS BEST
  //   //    typedef typename A::ConcreteType E1;
  //   //    typedef A E1;
  //   typedef ExpressionR<A, NT1, NT1, D1, rank> E1;
  //   typedef typename AddType<NT1, NT2>::Type NT3;
  //   typedef typename NumberTrait<E2, NT3>::Type E3; // see TODO note above
  //   constexpr size_t D3 = D2;
  //   //    MOUT << "Num" <<std::endl;
  //   return ExpressionR_Binary<ExpressionR<A, NT1, NT1, D1, rank>,
  //                     ExpressionR<B, E2, NT2, D2, rank>,
  //                     NT1, E2, E3, NT1, NT2, NT3, D1, D2, D3, rank, rank, rank,
  //                     FUNCTOR_add<E1, E2, E3, NT1, NT2, NT3>>(x1, x2);
  // }




  /****************************************************************************
   * tensor_product(a,b)
   *
   * tensor product (outer product)
   *
   * for non-integer Numbers can also use (a&b) notation
   ****************************************************************************
   */

   // OPERATOR &
   // TODO: rewrite so that (a&b) is defined only floating point base types so that bitwise operators can be used

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth1, size_t depth2, size_t rank1, size_t rank2>
  auto& operator&(const ExpressionR<A, E1, NT1, depth1, rank1>& x1, const ExpressionR<B, E2, NT2, depth2, rank2>& x2) {
    // OUTPUT("operator|");
    return tensor_product(x1, x2);
  }

  // scalar scalar


  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth1, size_t depth2, size_t rank1, size_t rank2>
  auto& tensor_product(const ExpressionR<A, E1, NT1, depth1, rank1>& x1, const ExpressionR<B, E2, NT2, depth2, rank2>& x2) {
    using NT3 = typename MultType<NT1, NT2>::Type;
    using E3 = typename ReplaceNumberTrait<E1, NT3>::Type;
    using T3 = MultiArray<E3, rank1 + rank2>;
    T3& x3 = *(new T3);
    // concat dims, then resize x3
    const Dimensions dims1 = x1.dims();
    const Dimensions dims2 = x2.dims();
    const Dimensions dims3 = Dimensions::concat(dims1, dims2);
    x3.resize(dims3);
    // TRDISP(dims1);
    // TRDISP(dims2);
    // TRDISP(dims3);
    const size_t N1 = dims1.num_elements();
    const size_t N2 = dims2.num_elements();
    const size_t N3 = dims3.num_elements();
    // TRDISP(N1);
    // TRDISP(N2);
    // TRDISP(N3);
    Indices inds1(dims1.rank()), inds2(dims2.rank()), inds3(dims3.rank());
    for (size_t i = 0; i < N1; i++) {
      for (size_t j = 0; j < N2; j++) {
        // MDISP(inds1, inds2, inds3);
        // TRDISP(x1[inds1]);
        // TRDISP(x2[inds2]);
        x3[inds3] = x1[inds1] * x2[inds2];
        inds2.increment(dims2);
        inds3.increment(dims3);
      }
      inds1.increment(dims1);
    }
    return x3;
  }



  /****************************************************************************
  * prodw(a,b)
  *
  * antisymmetric tensor product (wedge product)
  *
  * for non-integer Numbers can also use (a^b) notation
  ****************************************************************************
  */

  // OPERATOR &
  // TODO: rewrite so that (a&b) is defined only floating point base types so that bitwise operators can be used

    // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth1, size_t depth2, size_t rank1, size_t rank2> 
    // auto operator^(const ExpressionR<A, E1, NT1, depth1, rank1>& x1, const ExpressionR<B, E2, NT2, depth2, rank2>& x2) {
    //   // OUTPUT("operator|");
    //   return prodw(x1, x2);
    // }

    // // prodw(a,b)

    // template <class E1, class E2>
    // auto prodw(const Scalar<E1>& a, const Scalar<E2>& b) {
    //   return 0;
    // }



    //   // (a^b)

    // template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
    // auto operator^(const ExpressionR<A,E1,NT1,depth,rank>& a, const ExpressionR<B,E2,NT2,depth,rank>& b) {
    //   typedef typename MultType<NT1,NT2>::Type NT3;
    //   typedef typename NumberTrait<E1,NT3>::Type E3;   // see TODO note above

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


  /****************************************************************************
  * tensor_product(a,b)
  *
  * vector cross product
  *
  * for non-integer Numbers can also use (a^b) notation
  ****************************************************************************
  */

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth1, size_t depth2>
  auto& operator^(const ExpressionR<A, E1, NT1, depth1, 1>& a, const ExpressionR<B, E2, NT2, depth2, 1>& b) {
    return cross(a, b);
  }

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth1, size_t depth2>
  auto& cross(const ExpressionR<A, E1, NT1, depth1, 1>& a, const ExpressionR<B, E2, NT2, depth2, 1>& b) {
    // TODO: check that x1, x2 have size=3
    using NT3 = typename AddType<NT1, NT2>::Type;
    using E3 = typename ReplaceNumberTrait<E1, NT3>::Type;
    using T3 = Vector<E3, 3>;
    T3& x3 = *(new T3);
    x3[0] = a[1]*b[2] - a[2]*b[1];
    x3[1] = a[2]*b[0] - a[0]*b[2];
    x3[2] = a[0]*b[1] - a[1]*b[0];
    return x3;
  }


};

#endif
