#ifndef MATHQ__FUNCTIONS_STRUCTURE
#define MATHQ__FUNCTIONS_STRUCTURE 1


namespace mathq {


  // ***************************************************************************
  // * return slice
  //
  // TODO: convert to slice expression
  // ***************************************************************************
  template <typename T>
  auto& get_vector(const T& x_in, const size_t n, const Indices& inds_) {
    using ElementType = typename T::ElementType;
    // ETV(x_in);
    const size_t rank = T::rank_value;
    const Dimensions dims = x_in.dims();
    const size_t N = dims[n];
    Vector<ElementType>& v = *(new Vector<ElementType>);
    v.resize(N);

    Indices inds = inds_;
    for (size_t i = 0; i < N; i++) {
      inds[n] = i;
      // ETV(inds);
      // ETV(x[inds]);
      v[i] = x_in[inds];
    }
    return v;
  }


  // ***************************************************************************
  // * return slice
  //
  // TODO: convert to slice expression
  // ***************************************************************************
  template <typename T>
  auto& set_vector(T& x, const size_t n, const Indices& inds_, const Vector<typename T::ElementType>& v) {
    using ElementType = typename T::ElementType;
    const size_t rank = T::rank_value;
    const Dimensions dims = x.dims();
    const size_t N = dims[n];
    Indices inds = inds_;
    for (size_t i = 0; i < N; i++) {
      inds[n] = i;
      // ETV(inds);
      // ETV(x[inds]);
      x[inds] = v[i];
    }
    return v;
  }

  // -------------------------------------------------------------------
    //
    // evert / insideout - turn a nested set of tensors inside-out
    // -------------------------------------------------------------------

  template <class X, typename Element, typename Num, size_t depth, size_t rank>
  auto& insideout(const ExpressionRW<X, Element, Num, depth, rank>& t) {
    return evert(t);
  }


  template <class X, typename Element, typename Num, size_t depth, size_t rank>
  auto& evert(const ExpressionRW<X, Element, Num, depth, rank>& t) {

    typedef typename InversionType<X>::Type Type;
    Type& tout = *(new Type());
    const X& tin = t.derived();
    RecursiveDimensions ddims(t.recursive_dims());
    RecursiveDimensions rdims(ddims.getEverse());
    tout.resize(rdims);

    const size_t Ndeep = tout.total_size();
    DeepIndices dinds(ddims);
    for (size_t i = 0; i < Ndeep; i++) {
      // set equal
      // MDISP(i, dinds, tin.dat(i), tin.dat(dinds));  // LEAVE THIS HERE BUT COMMENTED OUT!!!
      DeepIndices rinds = dinds.getEverse();
      tout[rinds] = tin[dinds];
      dinds.increment(ddims);
    }
    return tout;
  }


  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************

  // transpose(A) 

  template <class X, typename Element, typename Num, size_t depth, size_t rank>
  auto transpose(const ExpressionR<X, Element, Num, depth, rank>& x) {
    return ExpressionR_Transpose<ExpressionR<X, Element, Num, depth, rank>, Element, Num, depth, rank, FUNCTOR_pos<Element, Element, Num, Num>>(x);
  }

  // adjoint(A) - conjugate transpose - real

  template <class X, typename Element, typename Num, size_t depth, size_t rank> requires (IsSimpleNumber<Num>)
    auto adjoint(const ExpressionR<X, Element, Num, depth, rank>& x) {
    return ExpressionR_Transpose<ExpressionR<X, Element, Num, depth, rank>, Element, Num, depth, rank, FUNCTOR_pos<Element, Element, Num, Num>>(x);
  }


  // adjoint(A) - conjugate transpose - complex

  template <class X, typename Element, typename Num, size_t depth, size_t rank>
  auto adjoint(const ExpressionR<X, Element, std::complex<Num>, depth, rank>& x) {
    return ExpressionR_Transpose<ExpressionR<X, Element, std::complex<Num>, depth, rank>, Element, std::complex<Num>, depth, rank, FUNCTOR_conj_complex<Element, Element, std::complex<Num>, std::complex<Num>>>(x);
  }



  // adjoint(A) - conjugate transpose - Imaginary

  template <class X, typename Element, typename Num, size_t depth, size_t rank>
  auto adjoint(const ExpressionR<X, Element, Imaginary<Num>, depth, rank>& x) {
    return ExpressionR_Transpose<ExpressionR<X, Element, Imaginary<Num>, depth, rank>, Element, Imaginary<Num>, depth, rank, FUNCTOR_conj_imag<Element, Element, Imaginary<Num>, Imaginary<Num>>>(x);
  }

  // ~A conjugate transpose operator

  template <class X, typename Element, typename Num, size_t depth, size_t rank>
  auto operator~(const ExpressionR<X, Element, Num, depth, rank>& x) {
    return adjoint(x);
  }


  // join - LHS

  // NOTE: Without the const qualifiers, the C++ compiler refuses to use this function
  //       in the case where one or both inputs are an expression, eg. join((V1,V2),V3)
  //       Only work-around I have come up with i sto use conts and then cast the const away

  template <class A, class B, typename Element, typename Num, size_t depth, size_t rank, typename = EnableIf<rank==1> >
  auto join(const ExpressionRW<A, Element, Num, depth, rank>& x1, const ExpressionRW<B, Element, Num, depth, rank>& x2) {
    ExpressionRW<A, Element, Num, depth, rank>& a1 = const_cast<ExpressionRW<A, Element, Num, depth, rank>&>(x1);
    ExpressionRW<B, Element, Num, depth, rank>& a2 = const_cast<ExpressionRW<B, Element, Num, depth, rank>&>(x2);
    return ExpressionRW_Join<ExpressionRW<A, Element, Num, depth, rank>, ExpressionRW<B, Element, Num, depth, rank>, Element, Num, depth>(a1, a2);
  }


  // operator, - LHS

  // Note above applies here as well.

  template <class A, class B, typename Element, typename Num, size_t depth, size_t rank, typename = EnableIf<rank==1> >
  auto operator,(const ExpressionRW<A, Element, Num, depth, rank>& x1, const ExpressionRW<B, Element, Num, depth, rank>& x2) {
    ExpressionRW<A, Element, Num, depth, rank>& a1 = const_cast<ExpressionRW<A, Element, Num, depth, rank>&>(x1);
    ExpressionRW<B, Element, Num, depth, rank>& a2 = const_cast<ExpressionRW<B, Element, Num, depth, rank>&>(x2);
    return join(a1, a2);
  }


  // join - RHS

  template <class A, class B, typename Element, typename Num, size_t depth, size_t rank, typename = EnableIf<(rank==1)>  >
  auto join(const ExpressionR<A, Element, Num, depth, rank>& x1, const ExpressionR<B, Element, Num, depth, rank>& x2) {
    return  ExpressionR_Join<ExpressionR<A, Element, Num, depth, rank>, ExpressionR<B, Element, Num, depth, rank>, Element, Num, depth>(x1, x2);
  }


  // operator, - RHS

  template <class A, class B, typename Element, typename Num, size_t depth, size_t rank, typename = EnableIf<(rank==1)>  >
  auto operator,(const ExpressionR<A, Element, Num, depth, rank>& x1, const ExpressionR<B, Element, Num, depth, rank>& x2) {
    return join(x1, x2);
  }



  // rep(v,m)

  template <class A, typename Num>
  auto rep(const ExpressionR<A, Num, Num, 1, 1>& a, const size_t m) {
    return ExpressionR_Rep<ExpressionR<A, Num, Num, 1, 1>, Num>(a, m);
  }




};

#endif 
