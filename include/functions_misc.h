#ifndef MATHQ__FUNCTIONS_MISC_H
#define MATHQ__FUNCTIONS_MISC_H 1


namespace mathq {




  //----------------------------------------------
  // zeros
  //----------------------------------------------

  template <class Element>
  inline auto& zeros() {
    Element& e = *(new Element());
    e = 0 * e;
    return e;
  }


  //----------------------------------------------
  // ones
  //----------------------------------------------

  template <class Element>
  inline auto& ones() {
    Element& e = *(new Element());
    e = 0 * e + 1;
    return e;
  }





  /****************************************************************************
   * casting
   ****************************************************************************
   */

   // ----------------------------------------------------------------
   // FUNCTOR_numbercast
   // ----------------------------------------------------------------

  template <class Element, class EOUT, class DIN, class DOUT> class FUNCTOR_numbercast {
  public:
    typedef DIN DType;
    typedef DOUT DoutType;
    typedef Element EType;
    typedef EOUT EoutType;
    static DOUT apply(const DIN d) {
      return numbercast<DOUT>(d);
    }
    template <class T = Element>
    static  typename std::enable_if<!std::is_same<T, DIN>::value, EOUT& >::type
      apply(const Element& e) {
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
      Element e;
      return functor_namestyle.apply("FUNCTOR_numbercast")+display::getBracketedTypeName(e);
    }
  };


  //----------------------------------------------
  // numbercast 
  //----------------------------------------------

  template <class D2, class X, class Element, class Number, int Depth, int R>
  auto numbercast(const MArrayExpR<X, Element, Number, Depth, R>& x) {
    typedef typename NumberTrait<Element, D2>::ReplaceTypeD EOUT;
    return  TER_Unary<MArrayExpR<X, Element, Number, Depth, R>, EOUT, D2, Depth, R, FUNCTOR_numbercast<Element, EOUT, Number, D2>>(x);
  }


  /****************************************************************************
 * Equality related
 ****************************************************************************
 */


 // ----------------------------------------------------------------
 // FUNCTOR_roundzero
 // ----------------------------------------------------------------


  template <class Element, class Number> class FUNCTOR_roundzero {
  public:
    typedef typename OrderedNumberTrait<Number>::Type DTOL;
    static Number apply(const Number d, const DTOL tol) {
      return mathq::roundzero(d, tol);
    }
    template <class T = Element>
    static typename std::enable_if<!std::is_same<T, Number>::value, Element& >::type
      apply(const Element& e, const DTOL tol) {
      Element* e2 = new Element();
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
      Element e;
      Number d;
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
  template <class X, class Element, class Number, int Depth, int R>
  auto roundzero(const MArrayExpR<X, Element, Number, Depth, R>& x, const typename OrderedNumberTrait<Number>::Type& tol = Functions<typename OrderedNumberTrait<Number>::Type>::tolerance) {

    typedef typename OrderedNumberTrait<Number>::Type DTOL;
    return  TER_Binary<MArrayExpR<X, Element, Number, Depth, R>,
      DTOL,
      Element, DTOL, Element, Number, DTOL, Number, Depth, 0, Depth, R, 0, R,
      FUNCTOR_roundzero<Element, Number>>(x, tol);
  }




  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class D1, class D2, int Depth, int R>
  bool equal(const MArrayExpR<A, E1, D1, Depth, R>& x1, const MArrayExpR<B, E2, D2, Depth, R>& x2) {
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
    typedef typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type DTOL;

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

  template <class A, class B, class E1, class E2, class D1, class D2, int Depth, int R>
  auto approx(const MArrayExpR<A, E1, D1, Depth, R>& x1, const MArrayExpR<B, E2, D2, Depth, R>& x2, const typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type& tol = Functions<typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    typedef typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;
    return  TER_Ternary<MArrayExpR<A, E1, D1, Depth, R>,
      MArrayExpR<B, E2, D2, Depth, R>,
      DTOL,
      E1, E2, DTOL, E3, D1, D2, DTOL, D3, Depth, Depth, 0, Depth, R, R, 0, R,
      FUNCTOR_approx<E1, E2, E3, D1, D2, D3> >(x1, x2, tol);
  }

  // (10) MultiArray<E1(D1)> , D2 

  template <class A, class E1, class D1, class D2, int Depth, int R>
  auto approx(const MArrayExpR<A, E1, D1, Depth, R>& x1, const D2& x2, const typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type& tol = Functions<typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    typedef typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberTrait<E1, D3>::ReplaceTypeD E3;
    return  TER_Ternary<MArrayExpR<A, E1, D1, Depth, R>,
      D2,
      DTOL,
      E1, D2, DTOL, E3, D1, D2, DTOL, D3, Depth, 0, 0, Depth, R, 0, 0, R,
      FUNCTOR_approx<E1, D2, E3, D1, D2, D3> >(x1, x2, tol);
  }



  // (01) D1, MultiArray<E2(D2)> 

  template <class B, class E2, class D1, class D2, int Depth, int R>
  auto approx(D1& x1, const MArrayExpR<B, E2, D2, Depth, R>& x2, const typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type& tol = Functions<typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    typedef typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberTrait<E2, D3>::ReplaceTypeD E3;
    return  TER_Ternary<D1,
      MArrayExpR<B, E2, D2, Depth, R>,
      DTOL,
      D1, E2, DTOL, E3, D1, D2, DTOL, D3, 0, Depth, 0, Depth, 0, R, 0, R,
      FUNCTOR_approx<D1, E2, E3, D1, D2, D3> >(x1, x2, tol);
  }



  // -------------------------------------------------------------------
  // equal_approx - if two tensors are approximately equal, returns a single bool
  //          checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class D1, class D2, int Depth, int R>
  bool equal_approx(const MArrayExpR<A, E1, D1, Depth, R>& x1, const MArrayExpR<B, E2, D2, Depth, R>& x2, const  typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type tol = Functions< typename OrderedNumberTrait<typename AddType<D1, D2>::Type>::Type>::tolerance) {

    if (!dimequiv(x1, x2)) {
      return false;
    }
    return alltrue(approx(x1, x2, tol));
  }



  /****************************************************************************
   * Unary Functions/Operators that bools or size_t MultiArrays
   ****************************************************************************
   */



   // alltrue(a)

  template <class X, class Element, class Number, int Depth, int R, typename = EnableIf<std::is_same<Number, bool>::value> >
  bool alltrue(const MArrayExpR<X, Element, Number, Depth, R>& x) {

    for (size_t i = 0; i< x.deepsize(); i++) {
      if (!x.dat(i)) {
        return false;
      }
    }

    return true;
  }


  // anytrue(a)

  template <class X, class Element, class Number, int Depth, int R, typename = EnableIf<std::is_same<Number, bool>::value> >
  bool anytrue(const MArrayExpR<X, Element, Number, Depth, R>& x) {

    for (size_t i = 0; i< x.deepsize(); i++) {
      if (x.dat(i)) {
        return true;
      }
    }

    return false;
  }


  // numtrue(a)

  template <class X, class Element, class Number, int Depth, int R, typename = EnableIf<std::is_same<Number, bool>::value> >
  size_t numtrue(const MArrayExpR<X, Element, Number, Depth, R>& x) {

    size_t result = 0;

    for (size_t i = 0; i< x.deepsize(); i++) {
      result += static_cast<size_t>(x.dat(i));
    }

    return result;
  }





  // findtrue(a) - deep indexing

  // NOTE: declaration in preface.h

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<std::is_same<Number, bool>::value, Vector<size_t>&>
    findtrue(const MArrayExpR<X, Element, Number, Depth, R>& x) {
    size_t N = numtrue(x);
    Vector<size_t>* y = new Vector<size_t>(N);

    size_t j = 0;
    for (size_t i = 0; i< x.deepsize(); i++)
      if (x.dat(i))
        (*y)[j++] = i;

    return *y;
  }


  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

   // sum(a)

  template <class X, class Element, class Number, int Depth, int R >
  Element sum(const MArrayExpR<X, Element, Number, Depth, R>& v) {


    const size_t N = v.size();
    if (N==0)
      return 0;

    Element result = v[0];

    for (size_t i = 1; i < N; i++) {
      result += v[i];
    }

    return result;
  }




  // prod(a)

  template <class X, class Element, class Number, int Depth, int R >
  Element prod(const MArrayExpR<X, Element, Number, Depth, R>& v) {


    const size_t N = v.size();
    if (N==0)
      return 0;

    Element result = v[0];

    for (size_t i = 1; i < N; i++) {
      result *= v[i];
    }

    return result;
  }









  // min(a)

  template <class X, class Element, class Number, int Depth, int R>
  Number min(const MArrayExpR<X, Element, Number, Depth, R>& v) {

    const size_t N = v.deepsize();
    if (N==0) {
      return 0;
    }

    Number result = v.dat(0);

    for (size_t i = 1; i < N; i++) {
      result = std::min(result, v.dat(i));
    }

    return result;
  }




  // max(a)

  template <class X, class Element, class Number, int Depth, int R>
  Number max(const MArrayExpR<X, Element, Number, Depth, R>& v) {

    const size_t N = v.deepsize();
    if (N==0) {
      return 0;
    }

    Number result = v.dat(0);

    for (size_t i = 1; i < N; i++) {
      result = std::max(result, v.dat(i));
    }

    return result;
  }

  // sumofsqrs(a)

  template <class X, class Element, class Number, int Depth, int R>
  Number sumofsqrs(const MArrayExpR<X, Element, Number, Depth, R>& v) {
    Number result = Number();
    for (size_t i = 0; i < v.size(); i++) {
      result += normsqr(v[i]);
    }
    return result;
  }

  // norm(a)  - L2 norm

  template <class X, class Element, class Number, int Depth, int R>
  Number norm(const MArrayExpR<X, Element, Number, Depth, R>& v) {
    return std::sqrt(sumofsqrs(v));
  }



  // *********************************************************
  // *          Functions that create vectors
  // *********************************************************

  // The Interval generating function (with step given)

  template <class Number>
  Vector<Number>& range(Number start, Number end, Number step) {
    // determine size
    size_t N = 0;
    if (step > 0) {
      for (Number x = start; x<=end; x += step)
        N += 1;
    }
    else {
      for (Number x = start; x>=end; x += step)
        N += 1;
    }
    Vector<Number>* y = new Vector<Number>(N);

    (*y)[0] = start;
    for (size_t i = 1; i<N; i++)
      (*y)[i] = (*y)[i-1] + step;

    return *y;
  }


  // The Interval generating function (step by +/-1)

  template <class Number>
  Vector<Number>& range(Number start, Number end) {
    if (end >= start)
      return range<Number>(start, end, static_cast<Number>(1));
    else
      return range<Number>(start, end, static_cast<Number>(-1));
  }





  // linspace function [a,b]

  template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  Vector<Number>& linspace(Number start, Number end, size_t N) {
    Vector<Number>* y = new Vector<Number>(N);


    const Number step = (end-start)/static_cast<Number>(N-1);

    (*y)[0] = start;
    for (size_t i = 1; i<(N-1); i++) {
      (*y)[i] = start + static_cast<Number>(i)*step;
    }
    (*y)[N-1] = end;
    return *y;
  }



  // linspace_a function (a,b]
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b

  template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  Vector<Number>& linspace_a(Number start, Number end, size_t N) {
    Vector<Number>* y = new Vector<Number>(N);


    const Number step = (end-start)/static_cast<Number>(N);
    return linspace(start+step, end, N);
  }


  // linspace_b function [a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a to b-delta

  template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  Vector<Number>& linspace_b(Number start, Number end, size_t N) {
    Vector<Number>* y = new Vector<Number>(N);


    const Number step = (end-start)/static_cast<Number>(N);
    return linspace(start, end-step, N);
  }

  // linspace_ab function (a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b-delta

  template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  Vector<Number>& linspace_ab(Number start, Number end, size_t N) {
    Vector<Number>* y = new Vector<Number>(N);


    const Number step = (end-start)/static_cast<Number>(N+1);
    return linspace(start+step, end-step, N);
  }


  // *********************************************************
  // *          
  // *********************************************************


//
// RealSet<Number>
//

  template <class Number>
  class
    RealSet {
  public:
    size_t N;
    Number a;
    Number b;
    bool include_a;
    bool include_b;
    GridScaleEnum scale;

    // dependent variables
    // move to private
    Number log_a;
    Number log_b;
    size_t Neff;
    Number start;
    Number step;
    mathq::Vector<Number> grid;

    RealSet() noexcept {
      include_a = true;
      a = -std::numeric_limits<Number>::infinity();
      include_b = true;
      b = std::numeric_limits<Number>::infinity();
      N = 0;
      this->init_();
    }
    RealSet(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) noexcept :
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
        step = (log_b - log_a)/static_cast<Number>(Neff-1);
        if (include_a) {
          start = log_a;
        }
        else {
          start = log_a + step;
        }
      }
      else {
        step = (b - a)/static_cast<Number>(Neff-1);
        if (include_a) {
          start = a;
        }
        else {
          start = a + step;
        }
      }
      return *this;
    }


    const Number getGridPoint(size_t c) const {
      if (scale == GridScale::LOG) {
        return getGridPoint_Log(c);
      }
      else {
        return getGridPoint_Linear(c);
      }
    }

    const Number getGridPoint_Linear(size_t c) const {
      if (N == 0) return std::numeric_limits<Number>::quiet_NaN();

      if (c == N-1) {
        if (include_b) {
          return b;
        }
        else {
          return b - step;
        }
      }
      return start + static_cast<Number>(c)*step;
    }

    const Number getGridPoint_Log(size_t c) const {
      if (N == 0) return std::numeric_limits<Number>::quiet_NaN();

      if (c == N-1) {
        if (include_b) {
          return b;
        }
        else {
          return pow(10, log_b - step);
        }
      }
      return pow(10, log_a + static_cast<Number>(c)*step);
    }


    mathq::Vector<Number>& getGrid() {
      if (hasInflatedGrid_()) return grid;
      if (scale == GridScale::LOG) {
        return makeGrid_Log();
      }
      else {
        return makeGrid_Linear();
      }
    }


    mathq::Vector<Number>& forceRegenGrid() {
      if (scale == GridScale::LOG) {
        return makeGrid_Log();
      }
      else {
        return makeGrid_Linear();
      }
    }



    mathq::Vector<Number>& makeGrid_Linear() {
      inflateGrid_();
      init_();
      if (N == 0) return grid;

      for (size_t c = 0; c<(N-1); c++) {
        grid[c] = start + static_cast<Number>(c)*step;
      }
      if (include_b) {
        grid[N-1] = b;
      }
      else {
        grid[N-1] = b - step;
      }
      return grid;
    }


    mathq::Vector<Number>& makeGrid_Log() {
      inflateGrid_();
      init_();
      if (N == 0) return grid;

      for (size_t c = 0; c<(N-1); c++) {
        grid[c] = std::pow(10, start + static_cast<Number>(c)*step);
      }
      if (include_b) {
        grid[N-1] = b;
      }
      else {
        grid[N-1] = std::pow(10, log_b - step);
      }
      return grid;
    }


    static RealSet<Number> emptySet() {
      return RealSet<Number>(0, 0, 0, GridScale::LINEAR, false, false);
    }

    static RealSet<Number> point(const Number& p) {
      return RealSet<Number>(p, p, 1, GridScale::LINEAR, true, true);
    }

    // [a,b]
    static RealSet<Number> interval_CC(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, true, true);
    }

    // (a,b]
    static RealSet<Number> interval_OC(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, false, true);
    }

    // [a,b)
    static RealSet<Number> interval_CO(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, true, false);
    }

    // (a,b)
    static RealSet<Number> interval_OO(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, false, false);
    }



    static RealSet<Number> realLine(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      Number a;
      if (include_a) {
        a = -std::numeric_limits<Number>::infinity();
      }
      else {
        a = std::numeric_limits<Number>::lowest();
      }
      Number b;
      if (include_b) {
        b = std::numeric_limits<Number>::infinity();
      }
      else {
        b = std::numeric_limits<Number>::max();
      }
      return RealSet<Number>(a, b, 0, scale, include_a, include_b);
    }

    static RealSet<Number> realLineNeg(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      Number a;
      if (include_a) {
        a = -std::numeric_limits<Number>::infinity();
      }
      else {
        a = std::numeric_limits<Number>::lowest();
      }
      Number b;
      if (include_b) {
        b = 0;
      }
      else {
        b = -std::numeric_limits<Number>::min();
      }
      return RealSet<Number>(a, b, 0, scale, include_a, include_b);
    }

    static RealSet<Number> realLinePos(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      Number a;
      if (include_a) {
        a = 0;
      }
      else {
        a = std::numeric_limits<Number>::min();
      }
      Number b;
      if (include_b) {
        b = std::numeric_limits<Number>::infinity();
      }
      else {
        b = std::numeric_limits<Number>::max();
      }
      return RealSet<Number>(a, b, 0, include_a, include_b);
    }

  };



  //
  // RealMultiSet<Number>
  //
  // Dimensions cannot be changed

  // template <typename Number, template <typename> typename C>
  // inline Style getTypeStyle(const C<const Number>& var) {

  template <class Number, size_t NDIMS, class MULTIGRID>
  class
    RealMultiSet : public std::array<RealSet<Number>, NDIMS> {
  public:
    typedef typename std::array<RealSet<Number>, NDIMS> Parent;
    typedef typename Parent::iterator Iterator;
    typedef RealSet<Number> ElementType;
    typedef Number DataType;

    const size_t Ndims = NDIMS;

    // Rank of our multiarray grid is equal to number of dimensions
    // For low dimensions, this type will be Scalar, Vector or Matrix, etc for efficency
    // the dimensions of the multiarray are dynamic

    MULTIGRID grid;

    RealMultiSet(const std::initializer_list<RealSet<Number>>& mylist) {
      *this = mylist;
    }


    RealMultiSet& init_() {
      inflateGrids_();
      return *this;
    }

    RealMultiSet& deflateGrids_() {
      for (size_t g = 0; g < NDIMS; g++) {
        get(g).deflateGrid_();
        grid[g].resize(0);
      }
      return *this;
    }
    RealMultiSet& inflateGrids_() {
      const Dimensions gdims = gridDims();
      OUTPUT("inflategrids");
      TRDISP(gdims);
      for (size_t g = 0; g < NDIMS; g++) {
        RealSet<Number>& set = get(g);
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
    inline size_t getDepth(void) const {
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
        RealSet<Number>& rs = get(g);
        dims.push_back(rs.N);
      }
      return dims;
    }

    RealMultiSet& operator=(const std::initializer_list<RealSet<Number>>& mylist) {
      size_t i = 0;
      typename std::initializer_list<RealSet<Number>>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }
      return *this;
    }


    RealSet<Number>& get(size_t g) {
      return (*this)[g];
    }

    MULTIGRID& getGrid() {
      TRDISP(hasInflatedGrids_());
      if (hasInflatedGrids_()) return grid;
      return forceRegenGrid();
    }


    MULTIGRID& forceRegenGrid() {
      init_();

      if constexpr (NDIMS == 0) {
        // do something?
      }
      else if constexpr (NDIMS == 1) {
        grid = get(0).forceRegenGrid();
      }
      else if constexpr (NDIMS == 2) {
        Grid<Number, 1>& xgrid = get(0).forceRegenGrid();
        Grid<Number, 1>& ygrid = get(1).forceRegenGrid();
        Grid<Number, NDIMS>& X = grid[0];
        Grid<Number, NDIMS>& Y = grid[1];
        const size_t Nx = gridDims()[0];
        const size_t Ny = gridDims()[1];
        X.resize(Nx, Ny);
        Y.resize(Nx, Ny);
        for (size_t r = 0; r < Nx; r++) {
          for (size_t c = 0; c < Ny; c++) {
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
            RealSet<Number>& rs = get(g);
            // MDISP(g, indices[g]);
            grid[g](indices) = rs.getGrid()[indices[g]];
          }
        }
      }
      // OUTPUT("EXIT");
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "RealMultiSet";
      s += StyledString::get(ANGLE1).get();
      Number d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "NDIMS=";
      s += num2string(NDIMS);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const RealMultiSet& var) {
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


  // ***************************************************************************
  // * CurvilinearCoords<Number, NDIMS>
  // ***************************************************************************

  template <class Element, size_t NDIMS, class CHILD>
  class CurvilinearCoords : public Vector<Element, NDIMS> {
  public:
    typedef CurvilinearCoords<Element, NDIMS, CHILD> CLASS;
    typedef Vector<Element, NDIMS> PARENT;

    CHILD& child() {
      return static_cast<CHILD&>(*this);
    }
    const  CHILD& child() const {
      return static_cast<const CHILD&>(*this);
    }


    // Jacobian 
    Element J() const {
      return child().J();
    }

    // metric tensor g^{ij} 
    Matrix<Element, NDIMS, NDIMS> g() const {
      return child().g();
    }
    CartCoords<Element, NDIMS>& pos() const {
      return child().pos();
    }
    CartCoords<Element, NDIMS>& toCartesian() const {
      return child().toCartesian();
    }
    Vector<Element, NDIMS>& basis_vec(size_t n) const {
      return child().basis_vec();
    }



    std::array<std::string, NDIMS>& names() const {
      return child().names();
    }

    const std::string& name(size_t n) const {
      return child().name(n);
    }

    inline std::string classname() const {
      return child().classname();
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CLASS& var) {
      return stream << var.child();
    }


  };


  // ***************************************************************************
  // * CartCoords<Number, NDIMS>
  // ***************************************************************************

  template <class Element, size_t NDIMS>
  class CartCoords : public CurvilinearCoords<Element, NDIMS, CartCoords<Element, NDIMS>> {
  public:
    typedef CartCoords<Element, NDIMS> CLASS;
    typedef CurvilinearCoords<Element, NDIMS, CLASS> PARENT;
    typedef typename PARENT::PARENT BASE;
    static int ron() {
      return NDIMS;
    }

    template<size_t TEMP = NDIMS>
    static EnableMethodIf<TEMP==2, CartCoords<Element, NDIMS>> fromPolar(const Element& r, const Element& phi) {
      Element x = r * std::cos(phi);
      Element y = r * std::sin(phi);
      return CartCoords<Element, NDIMS>(x, y);
    }
    template<size_t TEMP = NDIMS>
    EnableMethodIf<TEMP==2, PolarCoords<Element>> toPolar() {
      return PolarCoords<Element>(*this);
    }


    explicit CartCoords(const std::initializer_list<Element>& mylist) {
      BASE& me = *this;
      me = mylist;
    }

    explicit CartCoords(const CartCoords<Element, NDIMS>& v2) {
      BASE& me = *this;
      me = v2;
    }

    std::array<std::string, NDIMS>& names() const {
      std::array<std::string, NDIMS> names;
      for (size_t c = 0; c < NDIMS; c++) {
        names[c] = name(c);
      }
      return names;
    }

    const std::string& name(size_t n) const {
      std::string* s = new std::string("x");
      *s += std::to_string(n+1);
      return *s;
    }


    // Jacobian 
    Element& J() const {
      Element* jacob = new Element();
      *jacob = 1;
      return *jacob;
    }

    // metric tensor g^{ij} 
    Matrix<Element, NDIMS, NDIMS> g() const {
      Matrix<Element, NDIMS, NDIMS> metric;
      for (size_t r = 0; r < NDIMS; r++) {
        for (size_t c = 0; c < NDIMS; c++) {
          metric(r, c) = (r==c) ? 1 : 0;
        }
      }
      return metric;
    }

    CartCoords<Element, NDIMS>& pos() const {
      return toCartesian();
    }
    CartCoords<Element, NDIMS>& toCartesian() const {
      return *(new CartCoords<Element, NDIMS>(*this));
    }

    Vector<Element, NDIMS>& basis_vec(size_t n) const {
      Vector<Element, NDIMS>* vec = new Vector<Element, NDIMS>(0);
      (*vec)[n] = 1;
      return *vec;
    }


    inline std::string classname() const {
      using namespace display;
      std::string s = "CartCoords";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += std::to_string(NDIMS);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CartCoords<Element, NDIMS>& var) {
      stream << "(";
      for (size_t c = 0; c < NDIMS; c++) {
        if (c>0) stream << ", ";
        stream << var.name(c);
        stream << "=";
        stream << var[c];
      }
      stream << ")";
      return stream;
    }



    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=1)> = 0>
    Element& x1() const {
      return (*this)[0];
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=1)> = 0>
    CartCoords<Element, NDIMS>& x1(const Element& x1) const {
      (*this)[0] = x1;
      return *this;
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=1)> = 0>
    Element& x() const {
      return (*this)[0];
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=1)> = 0>
    CartCoords<Element, NDIMS>& x(const Element& x) const {
      (*this)[0] = x;
      return *this;
    }

    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=2)> = 0>
    Element& x2() const {
      return (*this)[1];
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=2)> = 0>
    CartCoords<Element, NDIMS>& x2(const Element& x2) const {
      (*this)[1] = x2;
      return *this;
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=2)> = 0>
    Element& y() const {
      return (*this)[1];
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=2)> = 0>
    CartCoords<Element, NDIMS>& y(const Element& y) const {
      (*this)[1] = y;
      return *this;
    }

    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=3)> = 0>
    Element& x3() const {
      return (*this)[2];
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=3)> = 0>
    CartCoords<Element, NDIMS>& x3(const Element& x3) const {
      (*this)[2] = x3;
      return *this;
    }

    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=3)> = 0>
    Element& z() const {
      return (*this)[2];
    }
    template<size_t TEMP = NDIMS, EnableIf<(TEMP>=3)> = 0>
    CartCoords<Element, NDIMS>& z(const Element& z) const {
      (*this)[2] = z;
      return *this;
    }

    template<size_t TEMP = NDIMS, EnableIf<(TEMP==2)> = 0>
    explicit CartCoords<Element, NDIMS>(const PolarCoords<Element>& v2) {
      (*this)[0] = v2.r() * std::cos(v2.phi());
      (*this)[1] = v2.r() * std::sin(v2.phi());
    }

  };



  template <class Element, size_t NDIMS>
  auto dot(const CartCoords<Element, NDIMS>& v1, const CartCoords<Element, NDIMS>& v2) {
    return v1 | v2;
  }




  // ***************************************************************************
  // * PolarCoords<Number>(r, phi)
  // ***************************************************************************

  template <class Element>
  class PolarCoords : public CurvilinearCoords<Element, 2, PolarCoords<Element>> {
  public:
    typedef PolarCoords<Element> CLASS;
    typedef CurvilinearCoords<Element, 2, CLASS> PARENT;
    typedef typename PARENT::PARENT BASE;

    static PolarCoords<Element> fromCartesian(Element x, Element y) {
      return PolarCoords<Element>(std::sqrt(x*x + y*y), std::atan2(y, x));
    }

    PolarCoords(const Element r, const Element phi) {
      (*this)[0] = r;
      (*this)[1] = phi;
    }
    PolarCoords(const std::initializer_list<Element>& mylist) {
      BASE& me = *this;
      me = mylist;
    }

    PolarCoords(const PolarCoords<Element>& v2) {
      BASE& me = *this;
      me = v2;
    }

    PolarCoords(const CartCoords<Element, 2>& v2) {
      (*this)[0] = std::sqrt(x*x + y*y);
      (*this)[1] = std::atan2(y, x);
    }


    // const std::vector<bool> periodic = { false, true };

    std::vector<std::string>& names() const {
      std::vector<std::string> names = { "r","𝜑" };
      return names;
    }
    const std::string& name(size_t n) const {
      if (n == 0) {
        return std::string("r");
      }
      else {
        return std::string("phi");
      }
    }


    Element& r() const {
      return (*this)[0];
    }
    Element& phi() const {
      return (*this)[1];
    }

    PolarCoords<Element>& r(const Element& r) const {
      (*this)[0] = r;
      return *this;
    }
    PolarCoords<Element>& phi(const Element& phi) const {
      (*this)[1] = phi;
      return *this;
    }


    Element x() const {
      const Element& r = (*this)[0];
      const Element& phi = (*this)[1];
      return r * std::cos(phi);
    }
    Element x1() const {
      return x();
    }

    Element y() const {
      const Element& r = (*this)[0];
      const Element& phi = (*this)[1];
      return r * std::sin(phi);
    }
    Element x2() const {
      return y();
    }


    CartCoords<Element, 2>& pos() const {
      return toCartesian();
    }
    CartCoords<Element, 2>& toCartesian() const {
      return *(new CartCoords<Element, 2>({ x(), y() }));
    }


    // unit vectors
    Vector<Element, 2>& basis_r() const {
      const Element& r = (*this)[0];
      const Element& phi = (*this)[1];
      return *(new Vector<Element, 2>{ std::cos(phi), std::sin(phi) });
    }
    Vector<Element, 2>& basis_phi() const {
      const Element& r = (*this)[0];
      const Element& phi = (*this)[1];
      return *(new Vector<Element, 2>{ -std::sin(phi), std::cos(phi) });
    }

    Vector<Element, 2>& basis_vec(size_t n) const {
      if (n == 0) {
        return basis_r();
      }
      else {
        return basis_phi();
      }
    }


    // Jacobian 
    Element J() const {
      const Element& r = (*this)[0];
      const Element& phi = (*this)[1];
      return r;
    }

    // metric tensor g^{ij} 
    Matrix<Element, 2, 2> g() const {
      const Element& r = (*this)[0];
      const Element& phi = (*this)[1];
      Matrix<Element, 2, 2> metric;
      metric = { ones<Element>(), zeros<Element>(), zeros<Element>(), r*r };
      return metric;
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "PolarCoords";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const PolarCoords<Element>& var) {
      const Element& r = var[0];
      const Element& phi = var[1];
      stream << "(r=";
      stream << r;
      stream << ", φ=";
      stream << phi;
      stream << ")";
      return stream;
    }


  };


  template <class Element>
  auto dot(const PolarCoords<Element>& v1, const PolarCoords<Element>& v2) {
    return v1[0] * v2[0] * std::cos(v1[1] - v2[1]);
  }

  // template <class Element>
  // auto& addpts(const PolarCoords<Element>& v1, const PolarCoords<Element>& v2) {
  //   const Vector<Element, 2> p = v1.toCartesian() + v2.toCartesian();
  //   return p.toPolar();
  // }

  // TODO: pmult for scalar * PolarCoords


  // ***************************************************************************
  // * PolarField<Number,RANK>
  //
  // physics field object: scalar field, vector field, tensor field 
  // uses curvilinear coordinates
  // ***************************************************************************
  template <class Number, size_t RANK> class PolarField : public TensorOfGrids<Number, 2, RANK> {
  public:
    using Coords = PolarCoords<Number>;
    // need a grid
    // dot, grad, div
// Map a function to cartesian coordinates (pull-back)
// Map a function from cartesian coordinates (push-forward)

    PolarField() {

    }

    // operators[n] and (r,phi)

    inline std::string classname() const {
      using namespace display;
      std::string s = "PolarField";
      s += StyledString::get(ANGLE1).get();
      Number d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "RANK=";
      s += num2string(RANK);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const PolarField<Number, RANK>& var) {
      stream << "{ ";
      stream << "\n  coords=(";
      for (size_t n = 0; n < 2; n++) {
        if (n>0) {
          stream << ", ";
        }
        stream << var.names[n];
        if (var.periodic[n]) {
          stream << ": periodic";
        }
      }
      stream << ")";
      stream << "\n}";
      return stream;
    }

  };


  //
  // CurvilinearCoordinateSystem<Number>
  //

  //   template <typename... U>
    // typename std::enable_if<(std::is_same<U, Number>::value && ...), const Number>::type operator()(const U... args) 
    // https://en.cppreference.com/w/cpp/language/parameter_pack
    // https://en.cppreference.com/w/cpp/concepts

    // https://stackoverflow.com/questions/25885893/how-to-create-a-variadic-generic-lambda
    // https://stackoverflow.com/questions/24661902/fixed-length-variadic-parameter-packs-in-c11
    // https://stackoverflow.com/questions/63563252/c-template-concept-that-requires-specific-parameter-pack-size
    //https://stackoverflow.com/questions/70881511/is-there-a-way-to-make-a-concept-that-can-represent-a-template-parameter-pack
    // https://stackoverflow.com/questions/24912900/status-of-fixed-size-parameter-packs
    // https://stackoverflow.com/questions/63563252/c-template-concept-that-requires-specific-parameter-pack-size
    // https://stackoverflow.com/questions/30346652/enforce-variadic-template-of-certain-type
    // https://stackoverflow.com/questions/69302003/how-to-use-c20-concepts-to-compile-time-enforce-match-of-number-of-args-for-gi
    // 

  template <class Number, size_t NDIMS, typename CHILD>
  class
    CurvilinearCoordinateSystem {
  public:

    CHILD& derived() {
      return static_cast<CHILD&>(*this);
    }
    const CHILD& derived() const {
      return static_cast<const CHILD&>(*this);
    }


    CurvilinearCoordinateSystem(
    ) {
    }


    inline std::string classname() const {
      using namespace display;
      std::string s = "CurvilinearCoordinateSystem";
      s += StyledString::get(ANGLE1).get();
      Number d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "NDIMS=";
      s += num2string(NDIMS);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CurvilinearCoordinateSystem& var) {
      stream << "{}";
      return stream;
    }


  };


  template <class Number>
  class
    PolarCoordSystem : public CurvilinearCoordinateSystem<Number, 2, PolarCoordSystem<Number>> {
  public:
    using Func = std::function<Number(Number, Number)>;
    using VecFunc = std::function<Vector<Number, 2>(Number, Number)>;
    using Coords = PolarCoords<Number>;


    PolarCoordSystem() {
    }


    inline std::string classname() const {
      using namespace display;
      std::string s = "PolarCoordSystem";
      s += StyledString::get(ANGLE1).get();
      Number d;
      s += getTypeName(d);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const PolarCoordSystem& var) {
      stream << "{ ";
      stream << "\n  coords=(";
      for (size_t n = 0; n < 2; n++) {
        if (n>0) {
          stream << ", ";
        }
        stream << var.names[n];
        if (var.periodic[n]) {
          stream << ": periodic";
        }
      }
      stream << ")";
      stream << "\n}";
      return stream;
    }

  };


  // template <class Number>
  // using PolarCoords = typename PolarCoordSystem<Number>::Coords;

  // template <class Number = double>
  // auto dot(const typename PolarCoordSystem<Number>::Coords& v1, const typename PolarCoordSystem<Number>::Coords& v2) {
  //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
  // }


  // template <class Number, template <typename> class T>
  // auto dot(const typename T<Number>::Coords& v1, const typename T<Number>::Coords& v2) {
  //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
  // }

  // template <class Number>
  // auto dot(const typename PolarCoordSystem<Number>::Coords& v1, const typename PolarCoordSystem<Number>::Coords& v2) {
  //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
  // }







  // // ***************************************************************************
  // // * gradient of a scalar function in N dimensions
  // // ***************************************************************************

  // // gradient
  // // assumes a uniform linear grid spacing
  // // TODO: non-uniform grids

  // // 
  // // 1D
  // //

  // template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  // auto grad(const Vector<Number>& gridfunc, const Interval<Number>& range, const int Dpts = 7, const bool periodic = false) {
  //   const size_t N = gridfunc.size();
  //   Vector<Number>* df = new Vector<Number>(N);
  //   *df = gridfunc;
  //   df->deriv(range.a, range.b, 1, Dpts, periodic);
  //   return *df;
  // }

  // template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  // auto operator&(const Nabla_old<void> i, std::pair<Vector<Number>, Interval<Number>> funcANDrange) {
  //   return grad(funcANDrange.first, funcANDrange.second);
  // }

  // // 
  // // 2D
  // //

  // // template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  // // auto fgrid(std::function<Number(Number, Number)> func, const Vector<Matrix<Number>, 2>& grid) {
  // //   const Matrix<Number>& X = grid(0);
  // //   const Matrix<Number>& Y = grid(1);
  // //   auto* y = new Matrix<Number>(X.Nrows(), X.Ncols());
  // //   for (int k = 0; k < X.size(); k++) {
  // //     (*y)[k] = func(X[k], Y[k]);
  // //   }
  // //   return *y;
  // // }

  // template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  // auto grad(const Matrix<Number>& gridfunc, const Interval<Number>& domX, const Interval<Number>& domY, const int Dpts = 7, const bool periodic = false) {

  //   // TODO: rewrite with slices

  //   const size_t NR = gridfunc.Nrows();
  //   const size_t NC = gridfunc.Ncols();
  //   Vector<Matrix<Number>, 2>* df = new Vector<Matrix<Number>, 2>();
  //   // starts off with empty matrices
  //   // TRDISP(*df);

  //   // take d/dx
  //   Vector<Number> vtemp = Vector<Number>(NC);
  //   Matrix<Number> mtemp = Matrix<Number>(NR, NC);
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

  // template <class Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  // auto operator&(const Nabla_old<void> i, std::tuple<Matrix<Number>, Interval<Number>, Interval<Number>> funcANDrange) {
  //   return grad(std::get<0>(funcANDrange), std::get<1>(funcANDrange), std::get<2>(funcANDrange));
  // }



  // *********************************************************
  // *          Functions that return a vector from a vector
  // *********************************************************


  // reverse

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> reverse(const MArrayExpR<X, Element, Number, Depth, R>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->reverse();
    return *g;
  }


  // cumsum() -- cumulative sum

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> cumsum(const MArrayExpR<X, Element, Number, Depth, R>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumsum();
    return *g;
  }

  // cumprod()  --  cumulative product

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> cumprod(const MArrayExpR<X, Element, Number, Depth, R>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumprod();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> cumtrapz(const MArrayExpR<X, Element, Number, Depth, R>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumtrapz();
    return *g;
  }

  // integrate_a2x(order)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> integrate_a2x(const MArrayExpR<X, Element, Number, Depth, R>& f, const Number a, const Number b, const int order = 1) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->integrate_a2x(a, b, order);
    return *g;
  }


  // cumsumrev() -- cumulative sum -- from last to first

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> cumsum_rev(const MArrayExpR<X, Element, Number, Depth, R>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumsum_rev();
    return *g;
  }

  // cumprodrev()  --  cumulative product  -- from last to first

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> cumprod_rev(const MArrayExpR<X, Element, Number, Depth, R>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumprod_rev();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation -- from last to first

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> cumtrapz_rev(const MArrayExpR<X, Element, Number, Depth, R>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumtrapz_rev();
    return *g;
  }



  // integrate_x2b
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&> integrate_x2b(const MArrayExpR<X, Element, Number, Depth, R>& f, const Number a, const Number b, const int order = 1) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->integrate_x2b(a, b, order);
    return *g;
  }



  // diff   (v[n] = v[n] - v[n-1])
  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&>  diff(const MArrayExpR<X, Element, Number, Depth, R>& f, const bool periodic = false) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->diff(periodic);
    return *g;
  }

  // diff_rev   (v[n] = v[n+1] - v[n])
  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&>  diff_rev(const MArrayExpR<X, Element, Number, Depth, R>& f, const bool periodic = false) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->diff_rev(periodic);
    return *g;
  }


  // derivative
  // any change in the default parameters must be likewise made in Vector.deriv(...)

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<R==1, Vector<Element>&>  deriv(const MArrayExpR<X, Element, Number, Depth, R>& f, const Number a, const Number b, const int n = 1, int Dpts = 7, const bool periodic = false) {
    //    MDISP(a,b,n,Dpts,periodic,f.size());
    Vector<Element>* df = new Vector<Element>(f.size());
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

  template <class X, class Element, class Number, int Depth, int R>
  EnableMethodIf<(Depth==1)&&(R==1), Number> integrate_a2b(const MArrayExpR<X, Element, Number, Depth, R>& v, const Number a, const Number b, const int order = 1) {


    const size_t N = v.size();
    if (N==0) {
      return 0;
    }
    if (a==b) {
      return 0;
    }

    Number result = 0;

    switch (order) {
    case 0:
      for (size_t j = 0; j < N; j++) {
        result += v[j];
      }
      result = result * (b-a)/Number(N);
      break;
    case 1:
      result += (v[0]+v[N-1])/2;
      for (size_t j = 1; j < N-1; j++) {
        result += v[j];
      }
      result = result * (b-a)/Number(N-1);
      break;
    case 2:
      if (N%2==0) {
        MOUT << "integrate_a2b: Number of points must be odd N="<<N<<std::endl;
      }
      {
        Number sodd = 0;
        Number seven = 0;
        result += v[0]+v[N-1];
        for (size_t j = 1; j < N-1; j++) {
          if (j%2==1) {
            sodd += v[j];
          }
          else {
            seven += v[j];
          }
        }
        result += 4*sodd + 2*seven;
        result = result * (b-a)/(3*Number(N-1));
      }
      break;
    case 3:
      if (N%3!=1) {
        MOUT << "integrate_a2b: N-1 must be divisible by 3, N="<<N<<std::endl;
      }
      {
        Number s1 = 0;
        Number s2 = 0;
        Number s3 = 0;

        result += v[0]+v[N-1];
        for (size_t j = 1; j < N-1; j++) {
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
        result = result * 3*(b-a)/(8*Number(N-1));
      }
      break;
    case 4:
      if (N%4!=1) {
        MOUT << "integrate_a2b: N-1 must be divisible by 4, N="<<N<<std::endl;
    }
      {
        Number s1 = 0;
        Number s2 = 0;
        Number s3 = 0;
        Number s4 = 0;

        result += 7*(v[0]+v[N-1]);
        for (size_t j = 1; j < N-1; j++) {
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
        result = result * 2*(b-a)/(45*Number(N-1));
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

  template <class A, class X, class Element, class Number, int M1, int M2, int R1, int R2, typename = EnableIf<(M1==1)&&(R1==1)>>
  auto maclaurin(const MArrayExpR<A, Number, Number, M1, R1>& a, const MArrayExpR<X, Element, Number, M2, R2>& x, const int N, const Number x0) {
    return TER_Series<MArrayExpR<A, Number, Number, M1, R1>, MArrayExpR<X, Element, Number, M2, R2>, Element, Number, M2, R2>(a, x, N, x0);
  }

  // // taylor(vector coefs, vector vals, max N)

  template <class A, class X, class Element, class Number, int M1, int M2, int R1, int R2, typename = EnableIf<(M1==1)&&(R1==1)>>
  auto taylor(const MArrayExpR<A, Number, Number, M1, R1>& a, const MArrayExpR<X, Element, Number, M2, R2>& x, const int N) {
    return TER_Series<MArrayExpR<A, Number, Number, M1, R1>, MArrayExpR<X, Element, Number, M2, R2>, Element, Number, M2, R2>(a, x, N);
  }

  // // ifourier(vector cos coefs, vector sin coefs, vector vals, max N, k1=2pi/wavelength or 2pi/period)
  // // sin coefs must include a coef for n=0 even though its irrelevant

  template <class A, class B, class X, class Number, int Depth, int R, typename = EnableIf<(Depth==1)&&(R==1)> >
  auto ifourier(const MArrayExpR<A, Number, Number, Depth, R>& Acos, const MArrayExpR<B, Number, Number, Depth, R>& Bsin, const MArrayExpR<X, Number, Number, Depth, R>& x, const int N, const Number k1) {
    return  TER_Series2<MArrayExpR<A, Number, Number, Depth, R>, MArrayExpR<B, Number, Number, Depth, R>, MArrayExpR<X, Number, Number, Depth, R>, Number, FUNCTOR_cos<Number, Number, Number, Number>, FUNCTOR_sin<Number, Number, Number, Number> >(Acos, Bsin, x, N, k1);
  }





};

#endif 
