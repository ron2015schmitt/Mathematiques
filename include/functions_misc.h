#ifndef MATHQ__FUNCTIONS_MISC_H
#define MATHQ__FUNCTIONS_MISC_H 1


namespace mathq {

  /****************************************************************************
   * casting
   ****************************************************************************
   */

   // ----------------------------------------------------------------
   // FUNCTOR_numbercast
   // ----------------------------------------------------------------

  template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_numbercast {
  public:
    typedef DIN DType;
    typedef DOUT DoutType;
    typedef E EType;
    typedef EOUT EoutType;
    static DOUT apply(const DIN d) {
      return numbercast<DOUT>(d);
    }
    template <class T = E>
    static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
      apply(const E& e) {
      EOUT* e2 = new EOUT();
      *e2 = numbercast<DOUT>(e);
      return *e2;
    }
    static std::string expression(const std::string& sa) {
      using namespace display;
      std::string sout = "";
      DOUT d;
      sout = functor_style.apply("numbercast")+display::getBracketedTypeName(d)+"("+ sa + ")";
      return sout;
    }
    static std::string classname() {
      using namespace display;
      E e;
      return functor_namestyle.apply("FUNCTOR_numbercast")+display::getBracketedTypeName(e);
    }
  };


  //----------------------------------------------
  // numbercast 
  //----------------------------------------------

  template <class D2, class X, class E, class D, int M, int R>
  auto numbercast(const MArrayExpR<X, E, D, M, R>& x) {
    typedef typename NumberType<E, D2>::ReplaceTypeD EOUT;
    return  TER_Unary<MArrayExpR<X, E, D, M, R>, EOUT, D2, M, R, FUNCTOR_numbercast<E, EOUT, D, D2>>(x);
  }


  /****************************************************************************
 * Equality related
 ****************************************************************************
 */


 // ----------------------------------------------------------------
 // FUNCTOR_roundzero
 // ----------------------------------------------------------------


  template <class E, class D> class FUNCTOR_roundzero {
  public:
    typedef typename FundamentalType<D>::Type DTOL;
    static D apply(const D d, const DTOL tol) {
      return mathq::roundzero(d, tol);
    }
    template <class T = E>
    static typename std::enable_if<!std::is_same<T, D>::value, E& >::type
      apply(const E& e, const DTOL tol) {
      E* e2 = new E();
      *e2 = roundzero(e, tol);
      return *e2;
    }
    static std::string expression(const std::string& sa, const std::string& sb) {
      using namespace display;
      std::string sout = "";
      sout = sa +" + "+ sb;
      return sout;
    }
    static std::string classname() {
      using namespace display;
      E e;
      D d;
      std::string comma = StyledString::get(COMMA).get();
      std::string s = functor_namestyle.apply(stringify(FUNCTOR_roundzero));
      s += StyledString::get(BRACKET1).get();
      s += getTypeName(e);
      s += comma + getTypeName(d);
      s += StyledString::get(BRACKET2).get();
      return s;
    }
  };

  // -------------------------------------------------------------------
  // roundzero 
  //         
  // -------------------------------------------------------------------
  template <class X, class E, class D, int M, int R>
  auto roundzero(const MArrayExpR<X, E, D, M, R>& x, const typename FundamentalType<D>::Type& tol = Functions<typename FundamentalType<D>::Type>::tolerance) {

    typedef typename FundamentalType<D>::Type DTOL;
    return  TER_Binary<MArrayExpR<X, E, D, M, R>,
      DTOL,
      E, DTOL, E, D, DTOL, D, M, 0, M, R, 0, R,
      FUNCTOR_roundzero<E, D>>(x, tol);
  }




  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
  bool equal(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2) {
    if (!dimequiv(x1, x2)) {
      return false;
    }
    return alltrue(x1==x2);
  }


  // ----------------------------------------------------------------
// FUNCTOR_approx: template class for function 'mathq::approx'
//
//    Note: generated from template file 'fun_ternary_functor.h'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------


  template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_approx {
  public:
    typedef typename FundamentalType<typename AddType<D1, D2>::Type>::Type DTOL;

    static D3 apply(const D1 d1, const D2 d2, const DTOL tol) {
      return mathq::approx(d1, d2, tol);
    }
    template <class T1 = E1, class T2 = E2>
    static typename std::enable_if<!std::is_same<T1, D1>::value&&!std::is_same<T2, D2>::value, E3& >::type
      apply(const E1& e1, const E2& e2, const DTOL tol) {
      E3* e3 = new E3();
      *e3 = mathq::approx(e1, e2, tol);
      return *e3;
    }
    template <class T1 = E1>
    static typename std::enable_if<!std::is_same<T1, D1>::value, E3& >::type
      apply(const E1& e1, const D2 d2, const DTOL tol) {
      E3* e3 = new E3();
      *e3 = mathq::approx(e1, d2, tol);
      return *e3;
    }
    template <class T2 = E2>
    static typename std::enable_if<!std::is_same<T2, D2>::value, E3& >::type
      apply(const D1 d1, const E2& e2, const DTOL tol) {
      E3* e3 = new E3();
      *e3 = mathq::approx(d1, e2, tol);
      return *e3;
    }

    static std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
      using namespace display;
      std::string sout = "";
      sout = sa +" , "+ sb +" , "+ sc;
      return sout;
    }
    static std::string classname() {
      using namespace display;
      E1 e1;
      E2 e2;
      E3 e3;
      D1 d1;
      D2 d2;
      D3 d3;
      std::string comma = StyledString::get(COMMA).get();
      std::string s = functor_namestyle.apply(stringify(FUNCTOR_approx));
      s += StyledString::get(BRACKET1).get();
      s += getTypeName(e1);
      s += comma + getTypeName(e2);
      s += comma + getTypeName(e3);
      s += comma + getTypeName(d1);
      s += comma + getTypeName(d2);
      s += comma + getTypeName(d3);
      s += StyledString::get(BRACKET2).get();
      return s;
    }
  };

  // ----------------------------------------------------------------
  // approx
  // template functions for 'approx'
  //
  // ----------------------------------------------------------------


  // TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same



  // (11) MultiArray<E1(D1)> , MultiArray<E2(D2)> 

  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
  auto approx(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2, const typename FundamentalType<typename AddType<D1, D2>::Type>::Type& tol = Functions<typename FundamentalType<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    typedef typename FundamentalType<typename AddType<D1, D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberType<E1, D3>::ReplaceTypeD E3;
    return  TER_Ternary<MArrayExpR<A, E1, D1, M, R>,
      MArrayExpR<B, E2, D2, M, R>,
      DTOL,
      E1, E2, DTOL, E3, D1, D2, DTOL, D3, M, M, 0, M, R, R, 0, R,
      FUNCTOR_approx<E1, E2, E3, D1, D2, D3> >(x1, x2, tol);
  }

  // (10) MultiArray<E1(D1)> , D2 

  template <class A, class E1, class D1, class D2, int M, int R>
  auto approx(const MArrayExpR<A, E1, D1, M, R>& x1, const D2& x2, const typename FundamentalType<typename AddType<D1, D2>::Type>::Type& tol = Functions<typename FundamentalType<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    typedef typename FundamentalType<typename AddType<D1, D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberType<E1, D3>::ReplaceTypeD E3;
    return  TER_Ternary<MArrayExpR<A, E1, D1, M, R>,
      D2,
      DTOL,
      E1, D2, DTOL, E3, D1, D2, DTOL, D3, M, 0, 0, M, R, 0, 0, R,
      FUNCTOR_approx<E1, D2, E3, D1, D2, D3> >(x1, x2, tol);
  }



  // (01) D1, MultiArray<E2(D2)> 

  template <class B, class E2, class D1, class D2, int M, int R>
  auto approx(D1& x1, const MArrayExpR<B, E2, D2, M, R>& x2, const typename FundamentalType<typename AddType<D1, D2>::Type>::Type& tol = Functions<typename FundamentalType<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    typedef typename FundamentalType<typename AddType<D1, D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberType<E2, D3>::ReplaceTypeD E3;
    return  TER_Ternary<D1,
      MArrayExpR<B, E2, D2, M, R>,
      DTOL,
      D1, E2, DTOL, E3, D1, D2, DTOL, D3, 0, M, 0, M, 0, R, 0, R,
      FUNCTOR_approx<D1, E2, E3, D1, D2, D3> >(x1, x2, tol);
  }



  // -------------------------------------------------------------------
  // equal_approx - if two tensors are approximately equal, returns a single bool
  //          checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
  bool equal_approx(const MArrayExpR<A, E1, D1, M, R>& x1, const MArrayExpR<B, E2, D2, M, R>& x2, const  typename FundamentalType<typename AddType<D1, D2>::Type>::Type tol = Functions< typename FundamentalType<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    if (!dimequiv(x1, x2)) {
      return false;
    }
    return alltrue(approx(x1, x2, tol));
  }



  /****************************************************************************
   * Unary Functions/Operators that bools or index_type MultiArrays
   ****************************************************************************
   */



   // alltrue(a)

  template <class X, class E, class D, int M, int R, typename = EnableIf<std::is_same<D, bool>::value> >
  bool alltrue(const MArrayExpR<X, E, D, M, R>& x) {

    for (index_type i = 0; i< x.deepsize(); i++) {
      if (!x.dat(i)) {
        return false;
      }
    }

    return true;
  }


  // anytrue(a)

  template <class X, class E, class D, int M, int R, typename = EnableIf<std::is_same<D, bool>::value> >
  bool anytrue(const MArrayExpR<X, E, D, M, R>& x) {

    for (index_type i = 0; i< x.deepsize(); i++) {
      if (x.dat(i)) {
        return true;
      }
    }

    return false;
  }


  // numtrue(a)

  template <class X, class E, class D, int M, int R, typename = EnableIf<std::is_same<D, bool>::value> >
  index_type numtrue(const MArrayExpR<X, E, D, M, R>& x) {

    index_type result = 0;

    for (index_type i = 0; i< x.deepsize(); i++) {
      result += static_cast<index_type>(x.dat(i));
    }

    return result;
  }





  // findtrue(a) - deep indexing

  // NOTE: declaration in preface.h

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<std::is_same<D, bool>::value, Vector<index_type>&>
    findtrue(const MArrayExpR<X, E, D, M, R>& x) {
    index_type N = numtrue(x);
    Vector<index_type>* y = new Vector<index_type>(N);

    index_type j = 0;
    for (index_type i = 0; i< x.deepsize(); i++)
      if (x.dat(i))
        (*y)[j++] = i;

    return *y;
  }


  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

   // sum(a)

  template <class X, class E, class D, int M, int R >
  E sum(const MArrayExpR<X, E, D, M, R>& v) {


    const size_type N = v.size();
    if (N==0)
      return 0;

    E result = v[0];

    for (index_type i = 1; i < N; i++) {
      result += v[i];
    }

    return result;
  }




  // prod(a)

  template <class X, class E, class D, int M, int R >
  E prod(const MArrayExpR<X, E, D, M, R>& v) {


    const size_type N = v.size();
    if (N==0)
      return 0;

    E result = v[0];

    for (index_type i = 1; i < N; i++) {
      result *= v[i];
    }

    return result;
  }









  // min(a)

  template <class X, class E, class D, int M, int R>
  D min(const MArrayExpR<X, E, D, M, R>& v) {

    const size_type N = v.deepsize();
    if (N==0) {
      return 0;
    }

    D result = v.dat(0);

    for (index_type i = 1; i < N; i++) {
      result = std::min(result, v.dat(i));
    }

    return result;
  }




  // max(a)

  template <class X, class E, class D, int M, int R>
  D max(const MArrayExpR<X, E, D, M, R>& v) {

    const size_type N = v.deepsize();
    if (N==0) {
      return 0;
    }

    D result = v.dat(0);

    for (index_type i = 1; i < N; i++) {
      result = std::max(result, v.dat(i));
    }

    return result;
  }

  // sumofsqrs(a)

  template <class X, class E, class D, int M, int R>
  D sumofsqrs(const MArrayExpR<X, E, D, M, R>& v) {
    D result = D();
    for (index_type i = 0; i < v.size(); i++) {
      result += normsqr(v[i]);
    }
    return result;
  }

  // norm(a)  - L2 norm

  template <class X, class E, class D, int M, int R>
  D norm(const MArrayExpR<X, E, D, M, R>& v) {
    return std::sqrt(sumofsqrs(v));
  }



  // *********************************************************
  // *          Functions that create vectors
  // *********************************************************

  // The Interval generating function (with step given)

  template <class D>
  Vector<D>& range(D start, D end, D step) {
    // determine size
    size_type N = 0;
    if (step > 0) {
      for (D x = start; x<=end; x += step)
        N += 1;
    }
    else {
      for (D x = start; x>=end; x += step)
        N += 1;
    }
    Vector<D>* y = new Vector<D>(N);

    (*y)[0] = start;
    for (size_type i = 1; i<N; i++)
      (*y)[i] = (*y)[i-1] + step;

    return *y;
  }


  // The Interval generating function (step by +/-1)

  template <class D>
  Vector<D>& range(D start, D end) {
    if (end >= start)
      return range<D>(start, end, static_cast<D>(1));
    else
      return range<D>(start, end, static_cast<D>(-1));
  }





  // linspace function [a,b]

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  Vector<D>& linspace(D start, D end, size_type N) {
    Vector<D>* y = new Vector<D>(N);


    const D step = (end-start)/static_cast<D>(N-1);

    (*y)[0] = start;
    for (size_type i = 1; i<(N-1); i++) {
      (*y)[i] = start + static_cast<D>(i)*step;
    }
    (*y)[N-1] = end;
    return *y;
  }



  // linspace_a function (a,b]
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  Vector<D>& linspace_a(D start, D end, size_type N) {
    Vector<D>* y = new Vector<D>(N);


    const D step = (end-start)/static_cast<D>(N);
    return linspace(start+step, end, N);
  }


  // linspace_b function [a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  Vector<D>& linspace_b(D start, D end, size_type N) {
    Vector<D>* y = new Vector<D>(N);


    const D step = (end-start)/static_cast<D>(N);
    return linspace(start, end-step, N);
  }

  // linspace_ab function (a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  Vector<D>& linspace_ab(D start, D end, size_type N) {
    Vector<D>* y = new Vector<D>(N);


    const D step = (end-start)/static_cast<D>(N+1);
    return linspace(start+step, end-step, N);
  }


  // *********************************************************
  // *          Functions that return a grid
  // *********************************************************


//
// RealSet<D>
//

  template <class D>
  class
    RealSet {
  public:
    size_t N;
    D a;
    D b;
    bool include_a;
    bool include_b;
    GridScaleEnum scale;

    // dependent variables
    // move to private
    D log_a;
    D log_b;
    size_t Neff;
    D start;
    D step;
    mathq::Vector<D> grid;

    RealSet() noexcept {
      include_a = true;
      a = -std::numeric_limits<D>::infinity();
      include_b = true;
      b = std::numeric_limits<D>::infinity();
      N = 0;
      this->init_();
    }
    RealSet(const D& a, const D& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) noexcept :
      a(a), b(b), N(N), scale(scale), include_a(include_a), include_b(include_b) {
      this->init_();
    }
    ~RealSet() {
    }

    void deflateGrid_() {
      grid.resize(0);
    }
    void inflateGrid_() {
      grid.resize(N);
    }
    bool hasInflatedGrid_() {
      return grid.size() > 0;
    }


    RealSet& init_() {
      Neff = N +  size_t(!include_a) + size_t(!include_b);
      if (scale == GridScale::LOG) {
        log_a = std::log10(a);
        log_b = std::log10(b);
        step = (log_b - log_a)/static_cast<D>(Neff-1);
        if (include_a) {
          start = log_a;
        }
        else {
          start = log_a + step;
        }
      }
      else {
        step = (b - a)/static_cast<D>(Neff-1);
        if (include_a) {
          start = a;
        }
        else {
          start = a + step;
        }
      }
      return *this;
    }


    const D getGridPoint(size_t c) const {
      if (scale == GridScale::LOG) {
        return getGridPoint_Log(c);
      }
      else {
        return getGridPoint_Linear(c);
      }
    }

    const D getGridPoint_Linear(size_t c) const {
      if (N == 0) return std::numeric_limits<D>::quiet_NaN();

      if (c == N-1) {
        if (include_b) {
          return b;
        }
        else {
          return b - step;
        }
      }
      return start + static_cast<D>(c)*step;
    }

    const D getGridPoint_Log(size_t c) const {
      if (N == 0) return std::numeric_limits<D>::quiet_NaN();

      if (c == N-1) {
        if (include_b) {
          return b;
        }
        else {
          return pow(10, log_b - step);
        }
      }
      return pow(10, log_a + static_cast<D>(c)*step);
    }


    mathq::Vector<D>& getGrid() {
      if (hasInflatedGrid_()) return grid;
      if (scale == GridScale::LOG) {
        return makeGrid_Log();
      }
      else {
        return makeGrid_Linear();
      }
    }


    mathq::Vector<D>& forceRegenGrid() {
      if (scale == GridScale::LOG) {
        return makeGrid_Log();
      }
      else {
        return makeGrid_Linear();
      }
    }



    mathq::Vector<D>& makeGrid_Linear() {
      inflateGrid_();
      init_();
      if (N == 0) return grid;

      for (size_t c = 0; c<(N-1); c++) {
        grid[c] = start + static_cast<D>(c)*step;
      }
      if (include_b) {
        grid[N-1] = b;
      }
      else {
        grid[N-1] = b - step;
      }
      return grid;
    }


    mathq::Vector<D>& makeGrid_Log() {
      inflateGrid_();
      init_();
      if (N == 0) return grid;

      for (size_t c = 0; c<(N-1); c++) {
        grid[c] = std::pow(10, start + static_cast<D>(c)*step);
      }
      if (include_b) {
        grid[N-1] = b;
      }
      else {
        grid[N-1] = std::pow(10, log_b - step);
      }
      return grid;
    }


    static RealSet<D> emptySet() {
      return RealSet<D>(0, 0, 0, GridScale::LINEAR, false, false);
    }

    static RealSet<D> point(const D& p) {
      return RealSet<D>(p, p, 1, GridScale::LINEAR, true, true);
    }

    // [a,b]
    static RealSet<D> interval_CC(const D& a, const D& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<D>(a, b, N, scale, true, true);
    }

    // (a,b]
    static RealSet<D> interval_OC(const D& a, const D& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<D>(a, b, N, scale, false, true);
    }

    // [a,b)
    static RealSet<D> interval_CO(const D& a, const D& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<D>(a, b, N, scale, true, false);
    }

    // (a,b)
    static RealSet<D> interval_OO(const D& a, const D& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<D>(a, b, N, scale, false, false);
    }



    static RealSet<D> realLine(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      D a;
      if (include_a) {
        a = -std::numeric_limits<D>::infinity();
      }
      else {
        a = std::numeric_limits<D>::lowest();
      }
      D b;
      if (include_b) {
        b = std::numeric_limits<D>::infinity();
      }
      else {
        b = std::numeric_limits<D>::max();
      }
      return RealSet<D>(a, b, 0, scale, include_a, include_b);
    }

    static RealSet<D> realLineNeg(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      D a;
      if (include_a) {
        a = -std::numeric_limits<D>::infinity();
      }
      else {
        a = std::numeric_limits<D>::lowest();
      }
      D b;
      if (include_b) {
        b = 0;
      }
      else {
        b = -std::numeric_limits<D>::min();
      }
      return RealSet<D>(a, b, 0, scale, include_a, include_b);
    }

    static RealSet<D> realLinePos(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      D a;
      if (include_a) {
        a = 0;
      }
      else {
        a = std::numeric_limits<D>::min();
      }
      D b;
      if (include_b) {
        b = std::numeric_limits<D>::infinity();
      }
      else {
        b = std::numeric_limits<D>::max();
      }
      return RealSet<D>(a, b, 0, include_a, include_b);
    }

  };



  //
  // RealSetN<D>
  //
  // Dimensions cannot be changed

  template <class D, size_t NDIMS>
  class
    RealSetN : public std::array<RealSet<D>, NDIMS> {
  public:
    typedef typename std::array<RealSet<D>, NDIMS> Parent;
    typedef typename Parent::iterator Iterator;
    typedef RealSet<D> ElementType;
    typedef D DataType;

    const size_t Ndims = NDIMS;

    // Rank of our multiarray grid is equal to number of dimensions
    // For low dimensions, this type will be Scalar, Vector or Matrix, etc for efficency
    // the dimensions of the multiarray are dynamic

    VectorofGrids<D, NDIMS> grid;

    RealSetN(const std::initializer_list<RealSet<D>>& mylist) {
      *this = mylist;
    }


    RealSetN& init_() {
      inflateGrids_();
      return *this;
    }

    RealSetN& deflateGrids_() {
      for (size_t g = 0; g < NDIMS; g++) {
        get(g).deflateGrid_();
        grid[g].resize(0);
      }
      return *this;
    }
    RealSetN& inflateGrids_() {
      const Dimensions gdims = gridDims();
      OUTPUT("inflategrids");
      TRDISP(gdims);
      for (size_t g = 0; g < NDIMS; g++) {
        RealSet<D>& set = get(g);
        set.inflateGrid_();
        grid[g].resize(gdims);
      }
      return *this;
    }
    bool hasInflatedGrids_() {
      if (NDIMS == 0) return false;
      for (size_t g = 0; g < NDIMS; g++) {
        if (!(get(g)).hasInflatedGrid_()) {
          return false;
        }
        if (grid[g].size() == 0) {
          return false;
        }
      }
      return true;
    }


    size_t ndims(void) const {
      return NDIMS;
    }

    Dimensions dims(void) const {
      Dimensions dimensions(NDIMS);
      return dimensions;
    }
    Dimensions tdims(void) const {
      Dimensions dimensions(NDIMS);
      return dimensions;
    }
    inline size_t depth(void) const {
      return 1;
    }

    inline size_t gridDepth(void) const {
      return 1;
    }

    Dimensions gridRank(void) const {
      return NDIMS;
    }

    Dimensions gridDims(void) {
      Dimensions dims;
      for (size_t g = 0; g < NDIMS; g++) {
        RealSet<D>& rs = get(g);
        dims.push_back(rs.N);
      }
      return dims;
    }

    RealSetN& operator=(const std::initializer_list<RealSet<D>>& mylist) {
      size_t i = 0;
      typename std::initializer_list<RealSet<D>>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }
      return *this;
    }


    RealSet<D>& get(size_t g) {
      return (*this)[g];
    }

    VectorofGrids<D, NDIMS>& getGrid() {
      TRDISP(hasInflatedGrids_());
      if (hasInflatedGrids_()) return grid;
      return forceRegenGrid();
    }


    VectorofGrids<D, NDIMS>& forceRegenGrid() {
      init_();

      if constexpr (NDIMS == 0) {
        // do something?
      }
      else if constexpr (NDIMS == 1) {
        grid = get(0).forceRegenGrid();
      }
      else if constexpr (NDIMS == 2) {
        Grid<D, 1>& xgrid = get(0).forceRegenGrid();
        Grid<D, 1>& ygrid = get(1).forceRegenGrid();
        Grid<D, NDIMS>& X = grid[0];
        Grid<D, NDIMS>& Y = grid[1];
        const size_t Nx = gridDims()[0];
        const size_t Ny = gridDims()[1];
        X.resize(Nx, Ny);
        Y.resize(Nx, Ny);
        for (size_type r = 0; r < Nx; r++) {
          for (size_type c = 0; c < Ny; c++) {
            X(r, c) = xgrid[r];
            Y(r, c) = ygrid[c];
          }
        }
      }
      else {
        for (size_t g = 0; g < NDIMS; g++) {
          get(g).forceRegenGrid();
        }
        Indices indices(NDIMS);  // all zeros
        // TRDISP(indices);
        setGrid_(0, indices);
        // DISP("DONE");
      }
      return grid;
    }

    void setGrid_(int coord, Indices& indices) {
      const size_t Npts = gridDims()[coord];  // grdi size of coord-th coordinate
      // MDISP("ENTRY for coord", coord, Npts);
      for (int p = 0; p < Npts; p++) {
        indices[coord] = p;
        if (coord < NDIMS-1) {
          // OUTPUT("GO TO NEXT coord");
          setGrid_(coord+1, indices);
        }
        else {
          // we are inside the last coordinate's loop, ie inside all the loops
          // MDISP(coord, p, indices);
          for (int g = 0; g < NDIMS; g++) {
            // this loop is for the NDIMS different grids (vectors of size N)
            // we set the grid value of each grid
            RealSet<D>& rs = get(g);
            // MDISP(g, indices[g]);
            grid[g](indices) = rs.getGrid()[indices[g]];
          }
        }
      }
      // OUTPUT("EXIT");
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "RealSetN";
      s += StyledString::get(ANGLE1).get();
      D d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "NDIMS=";
      s += num2string(NDIMS);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const RealSetN& var) {
      stream << "{ ";
      stream << "gridState=";
      display::dispval_strm(stream, (var.grid.size() == 0) ? "deflated" : "inflated");
      stream << ", {\n";
      for (size_t g = 0; g < var.size(); g++) {
        if (g > 0)
          stream << ", \n";
        stream << "  ";
        display::dispval_strm(stream, var[g]);
      }
      stream << "\n}}";
      return stream;
    }


  };





  // // complex and Quaternions are not ordered sets so they can't be used in a range

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto grid(const Interval<D>& rang) {
  //   return linspace(rang.a, rang.b, rang.N);
  // }

  // /// TODO: use reprow and repcol matrices

  // // uses same convetnion as meshgrid form matlab
  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto grid(const Interval<D>& r1, const Interval<D>& r2) {
  //   auto X = Matrix<D>(r2.N, r1.N);
  //   auto Y = Matrix<D>(r2.N, r1.N);
  //   auto* G = new Vector<Matrix<D>, 2>();

  //   for (size_type c = 0; c < r1.N; c++) {
  //     D temp;

  //     if (c == 0) {
  //       temp = r1.a;
  //     }
  //     else if (c == r1.N-1) {
  //       temp = r1.b;
  //     }
  //     else {
  //       temp = r1.a + static_cast<D>(c)*r1.step;
  //     }
  //     for (size_type r = 0; r < r2.N; r++) {
  //       X(r, c) = temp;
  //     }
  //   }

  //   for (size_type r = 0; r < r2.N; r++) {
  //     D temp;
  //     if (r == 0) {
  //       temp = r2.a;
  //     }
  //     else if (r == r2.N-1) {
  //       temp = r2.b;
  //     }
  //     else {
  //       temp = r2.a + static_cast<D>(r)*r2.step;
  //     }
  //     for (size_type c = 0; c < r1.N; c++) {
  //       Y(r, c) = temp;
  //     }
  //   }
  //   (*G)(0) = X;
  //   (*G)(1) = Y;
  //   return *G;
  // }

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto grid(const Interval<D>& r1, const Interval<D>& r2, const Interval<D>& r3) {
  //   auto dims = Dimensions(r2.N, r1.N, r3.N);
  //   auto X = MultiArray<D, 3>(dims);
  //   auto Y = MultiArray<D, 3>(dims);
  //   auto Z = MultiArray<D, 3>(dims);
  //   auto* G = new Vector<MultiArray<D>, 3>({ Dimensions(3),dims });
  //   // TRDISP(G->deepdims());
  //   // TRDISP((*G)(0));
  //   // X
  //   for (size_type c = 0; c < r1.N; c++) {
  //     D temp;

  //     if (c == 0) {
  //       temp = r1.a;
  //     }
  //     else if (c == r1.N-1) {
  //       temp = r1.b;
  //     }
  //     else {
  //       temp = r1.a + static_cast<D>(c)*r1.step;
  //     }
  //     for (size_type r = 0; r < r2.N; r++) {
  //       for (size_type k = 0; k < r3.N; k++) {
  //         X({ r, c, k }) = temp;
  //       }
  //     }
  //   }

  //   // Y 
  //   for (size_type r = 0; r < r2.N; r++) {
  //     D temp;
  //     if (r == 0) {
  //       temp = r2.a;
  //     }
  //     else if (r == r2.N-1) {
  //       temp = r2.b;
  //     }
  //     else {
  //       temp = r2.a + static_cast<D>(r)*r2.step;
  //     }
  //     for (size_type c = 0; c < r1.N; c++) {
  //       for (size_type k = 0; k < r3.N; k++) {
  //         Y({ r, c, k }) = temp;
  //       }
  //     }
  //   }
  //   // Z
  //   for (size_type k = 0; k < r3.N; k++) {
  //     D temp;
  //     if (k == 0) {
  //       temp = r3.a;
  //     }
  //     else if (k == r3.N-1) {
  //       temp = r3.b;
  //     }
  //     else {
  //       temp = r3.a + static_cast<D>(k)*r3.step;
  //     }
  //     for (size_type r = 0; r < r2.N; r++) {
  //       for (size_type c = 0; c < r1.N; c++) {
  //         Z({ r, c, k }) = temp;
  //       }
  //     }
  //   }
  //   // TRDISP((*G)(0));
  //   // TRDISP(X);
  //   (*G)(0) = X;
  //   (*G)(1) = Y;
  //   (*G)(2) = Z;
  //   return *G;
  // }


  // // fgrid 1D - apply function to 1D grid

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // Vector<D>& fgrid(std::function<D(D)> func, const Vector<D>& grid) {
  //   Vector<D>* y = new Vector<D>(grid.size());
  //   for (int k = 0; k < grid.size(); k++) {
  //     (*y)[k] = func(grid[k]);
  //   }
  //   return *y;
  // }

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // Vector<D>& fgrid(D(func)(D), const Vector<D>& grid) {
  //   // All 3 of these work
  //   // std::function<D(D)> func2 = func;  return fgrid( func2, grid );
  //   // return fgrid( std::function<D(D)>(std::forward<decltype(func)>(func)), grid );
  //   return fgrid(std::function<D(D)>(func), grid);
  // }


  // //
  // // fgrid 2D 
  // //

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto fgrid(std::function<D(D, D)> func, const Vector<Matrix<D>, 2>& grid) {
  //   const Matrix<D>& X = grid(0);
  //   const Matrix<D>& Y = grid(1);
  //   auto* y = new Matrix<D>(X.Nrows(), X.Ncols());
  //   for (int k = 0; k < X.size(); k++) {
  //     (*y)[k] = func(X[k], Y[k]);
  //   }
  //   return *y;
  // }

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto fgrid(D(func)(D, D), const Vector<Matrix<D>, 2>& grid) {
  //   // All 3 of these work
  //   // std::function<D(D,D)> func2 = func;  return fgrid( func2, grid );
  //   // return fgrid( std::function<D(D,D)>(std::forward<decltype(func)>(func)), grid );
  //   return fgrid(std::function<D(D, D)>(func), grid);
  // }


  // //
  // // fgrid 3D 
  // //

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto fgrid(std::function<D(D, D, D)> func, const Vector<MultiArray<D>, 3>& grid) {
  //   const MultiArray<D>& X = grid(0);
  //   const MultiArray<D>& Y = grid(1);
  //   const MultiArray<D>& Z = grid(2);
  //   auto* y = new MultiArray<D, 3>(X.dims());
  //   for (int k = 0; k < X.size(); k++) {
  //     (*y)[k] = func(X[k], Y[k], Z[k]);
  //   }
  //   return *y;
  // }

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto fgrid(D(func)(D, D, D), const Vector<MultiArray<D>, 3>& grid) {
  //   // All 3 of these work
  //   // std::function<D(D,D)> func2 = func;  return fgrid( func2, grid );
  //   // return fgrid( std::function<D(D,D)>(std::forward<decltype(func)>(func)), grid );
  //   return fgrid(std::function<D(D, D, D)>(func), grid);
  // }


  // // ***************************************************************************
  // // * nabla operator
  // // ***************************************************************************

  // template <class T>
  // class Nabla_old {
  // public:
  //   Nabla_old() {
  //   }
  //   ~Nabla_old() {
  //   }
  // };

  // const Nabla_old<void> nabla_old;





  // // ***************************************************************************
  // // * gradient of a scalar function in N dimensions
  // // ***************************************************************************

  // // gradient
  // // assumes a uniform linear grid spacing
  // // TODO: non-uniform grids

  // // 
  // // 1D
  // //

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto grad(const Vector<D>& gridfunc, const Interval<D>& range, const int Dpts = 7, const bool periodic = false) {
  //   const size_type N = gridfunc.size();
  //   Vector<D>* df = new Vector<D>(N);
  //   *df = gridfunc;
  //   df->deriv(range.a, range.b, 1, Dpts, periodic);
  //   return *df;
  // }

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto operator&(const Nabla_old<void> i, std::pair<Vector<D>, Interval<D>> funcANDrange) {
  //   return grad(funcANDrange.first, funcANDrange.second);
  // }

  // // 
  // // 2D
  // //

  // // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // // auto fgrid(std::function<D(D, D)> func, const Vector<Matrix<D>, 2>& grid) {
  // //   const Matrix<D>& X = grid(0);
  // //   const Matrix<D>& Y = grid(1);
  // //   auto* y = new Matrix<D>(X.Nrows(), X.Ncols());
  // //   for (int k = 0; k < X.size(); k++) {
  // //     (*y)[k] = func(X[k], Y[k]);
  // //   }
  // //   return *y;
  // // }

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto grad(const Matrix<D>& gridfunc, const Interval<D>& domX, const Interval<D>& domY, const int Dpts = 7, const bool periodic = false) {

  //   // TODO: rewrite with slices

  //   const size_type NR = gridfunc.Nrows();
  //   const size_type NC = gridfunc.Ncols();
  //   Vector<Matrix<D>, 2>* df = new Vector<Matrix<D>, 2>();
  //   // starts off with empty matrices
  //   // TRDISP(*df);

  //   // take d/dx
  //   Vector<D> vtemp = Vector<D>(NC);
  //   Matrix<D> mtemp = Matrix<D>(NR, NC);
  //   for (int r = 0; r < NR; r++) {
  //     for (int c = 0; c < NC; c++) {
  //       vtemp(c) = gridfunc(r, c);
  //     }
  //     vtemp.deriv(domX.a, domX.b, 1, Dpts, periodic);
  //     for (int c = 0; c < NC; c++) {
  //       mtemp(r, c) = vtemp(c);
  //     }
  //   }
  //   (*df)(0) = mtemp;

  //   // take d/dy
  //   vtemp.resize(NR);
  //   for (int c = 0; c < NC; c++) {
  //     for (int r = 0; r < NR; r++) {
  //       vtemp(r) = gridfunc(r, c);
  //     }
  //     vtemp.deriv(domY.a, domY.b, 1, Dpts, periodic);
  //     for (int r = 0; r < NR; r++) {
  //       mtemp(r, c) = vtemp(r);
  //     }
  //   }
  //   (*df)(1) = mtemp;

  //   // TRDISP(*df);
  //   return *df;
  // }

  // template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  // auto operator&(const Nabla_old<void> i, std::tuple<Matrix<D>, Interval<D>, Interval<D>> funcANDrange) {
  //   return grad(std::get<0>(funcANDrange), std::get<1>(funcANDrange), std::get<2>(funcANDrange));
  // }



  // *********************************************************
  // *          Functions that return a vector from a vector
  // *********************************************************


  // reverse

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> reverse(const MArrayExpR<X, E, D, M, R>& f) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->reverse();
    return *g;
  }


  // cumsum() -- cumulative sum

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> cumsum(const MArrayExpR<X, E, D, M, R>& f) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->cumsum();
    return *g;
  }

  // cumprod()  --  cumulative product

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> cumprod(const MArrayExpR<X, E, D, M, R>& f) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->cumprod();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> cumtrapz(const MArrayExpR<X, E, D, M, R>& f) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->cumtrapz();
    return *g;
  }

  // integrate_a2x(order)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> integrate_a2x(const MArrayExpR<X, E, D, M, R>& f, const D a, const D b, const int order = 1) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->integrate_a2x(a, b, order);
    return *g;
  }


  // cumsumrev() -- cumulative sum -- from last to first

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> cumsum_rev(const MArrayExpR<X, E, D, M, R>& f) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->cumsum_rev();
    return *g;
  }

  // cumprodrev()  --  cumulative product  -- from last to first

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> cumprod_rev(const MArrayExpR<X, E, D, M, R>& f) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->cumprod_rev();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation -- from last to first

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> cumtrapz_rev(const MArrayExpR<X, E, D, M, R>& f) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->cumtrapz_rev();
    return *g;
  }



  // integrate_x2b
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&> integrate_x2b(const MArrayExpR<X, E, D, M, R>& f, const D a, const D b, const int order = 1) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->integrate_x2b(a, b, order);
    return *g;
  }



  // diff   (v[n] = v[n] - v[n-1])
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&>  diff(const MArrayExpR<X, E, D, M, R>& f, const bool periodic = false) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->diff(periodic);
    return *g;
  }

  // diff_rev   (v[n] = v[n+1] - v[n])
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&>  diff_rev(const MArrayExpR<X, E, D, M, R>& f, const bool periodic = false) {
    Vector<E>* g = new Vector<E>(f.size());
    *g = f;
    g->diff_rev(periodic);
    return *g;
  }


  // derivative
  // any change in the default parameters must be likewise made in Vector.deriv(...)

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1, Vector<E>&>  deriv(const MArrayExpR<X, E, D, M, R>& f, const D a, const D b, const int n = 1, int Dpts = 7, const bool periodic = false) {
    //    MDISP(a,b,n,Dpts,periodic,f.size());
    Vector<E>* df = new Vector<E>(f.size());
    //    TLDISP(*df);
    *df = f;
    df->deriv(a, b, n, Dpts, periodic);
    return *df;
  }

  // integrate_a2b(a)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  //     2  simpson
  //     3  simpson 3/8
  //     4  Boole

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<(M==1)&&(R==1), D> integrate_a2b(const MArrayExpR<X, E, D, M, R>& v, const D a, const D b, const int order = 1) {


    const size_type N = v.size();
    if (N==0) {
      return 0;
    }
    if (a==b) {
      return 0;
    }

    D result = 0;

    switch (order) {
    case 0:
      for (index_type j = 0; j < N; j++) {
        result += v[j];
      }
      result = result * (b-a)/D(N);
      break;
    case 1:
      result += (v[0]+v[N-1])/2;
      for (index_type j = 1; j < N-1; j++) {
        result += v[j];
      }
      result = result * (b-a)/D(N-1);
      break;
    case 2:
      if (N%2==0) {
        MOUT << "integrate_a2b: Number of points must be odd N="<<N<<std::endl;
      }
      {
        D sodd = 0;
        D seven = 0;
        result += v[0]+v[N-1];
        for (index_type j = 1; j < N-1; j++) {
          if (j%2==1) {
            sodd += v[j];
          }
          else {
            seven += v[j];
          }
        }
        result += 4*sodd + 2*seven;
        result = result * (b-a)/(3*D(N-1));
      }
      break;
    case 3:
      if (N%3!=1) {
        MOUT << "integrate_a2b: N-1 must be divisible by 3, N="<<N<<std::endl;
      }
      {
        D s1 = 0;
        D s2 = 0;
        D s3 = 0;

        result += v[0]+v[N-1];
        for (index_type j = 1; j < N-1; j++) {
          if (j%3==1) {
            s1 += v[j];
          }
          else if (j%3==2) {
            s2 += v[j];
          }
          else {
            s3 += v[j];
          }
        }
        result += 3*s1 + 3*s2 + 2*s3;
        result = result * 3*(b-a)/(8*D(N-1));
      }
      break;
    case 4:
      if (N%4!=1) {
        MOUT << "integrate_a2b: N-1 must be divisible by 4, N="<<N<<std::endl;
      }
      {
        D s1 = 0;
        D s2 = 0;
        D s3 = 0;
        D s4 = 0;

        result += 7*(v[0]+v[N-1]);
        for (index_type j = 1; j < N-1; j++) {
          if (j%4==1) {
            s1 += v[j];
          }
          else if (j%4==2) {
            s2 += v[j];
          }
          else if (j%4==3) {
            s3 += v[j];
          }
          else {
            s4 += v[j];
          }
        }
        result += 32*s1 + 12*s2 + 32*s3 + 14*s4;
        result = result * 2*(b-a)/(45*D(N-1));
      }
      break;
    default:
#if MATHQ_DEBUG>0
      std::cerr << "integrate_a2b: bad order parameter order="<<order<<std::endl;
#endif
      break;
    }

    return result;
  }



  // *********************************************************
  // *          Series
  // *********************************************************


  // maclaurin(vector coefs, vector vals, max N, x0)

  template <class A, class X, class E, class D, int M1, int M2, int R1, int R2, typename = EnableIf<(M1==1)&&(R1==1)>>
  auto maclaurin(const MArrayExpR<A, D, D, M1, R1>& a, const MArrayExpR<X, E, D, M2, R2>& x, const int N, const D x0) {
    return TER_Series<MArrayExpR<A, D, D, M1, R1>, MArrayExpR<X, E, D, M2, R2>, E, D, M2, R2>(a, x, N, x0);
  }

  // // taylor(vector coefs, vector vals, max N)

  template <class A, class X, class E, class D, int M1, int M2, int R1, int R2, typename = EnableIf<(M1==1)&&(R1==1)>>
  auto taylor(const MArrayExpR<A, D, D, M1, R1>& a, const MArrayExpR<X, E, D, M2, R2>& x, const int N) {
    return TER_Series<MArrayExpR<A, D, D, M1, R1>, MArrayExpR<X, E, D, M2, R2>, E, D, M2, R2>(a, x, N);
  }

  // // ifourier(vector cos coefs, vector sin coefs, vector vals, max N, k1=2pi/wavelength or 2pi/period)
  // // sin coefs must include a coef for n=0 even though its irrelevant

  template <class A, class B, class X, class D, int M, int R, typename = EnableIf<(M==1)&&(R==1)> >
  auto ifourier(const MArrayExpR<A, D, D, M, R>& Acos, const MArrayExpR<B, D, D, M, R>& Bsin, const MArrayExpR<X, D, D, M, R>& x, const int N, const D k1) {
    return  TER_Series2<MArrayExpR<A, D, D, M, R>, MArrayExpR<B, D, D, M, R>, MArrayExpR<X, D, D, M, R>, D, FUNCTOR_cos<D, D, D, D>, FUNCTOR_sin<D, D, D, D> >(Acos, Bsin, x, N, k1);
  }





  };

#endif 
