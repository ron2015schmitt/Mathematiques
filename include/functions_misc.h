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
    typedef DIN NumberType;
    typedef DOUT DoutType;
    typedef Element ElementType;
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
      sout = functor_style.apply("numbercast")+display::bracketAndStyleTypename(d)+"("+ sa + ")";
      return sout;
    }
    static std::string classname() {
      using namespace display;
      Element e;
      return functor_namestyle.apply("FUNCTOR_numbercast")+display::bracketAndStyleTypename(e);
    }
  };


  //----------------------------------------------
  // numbercast 
  //----------------------------------------------

  template <class NT2, class X, class Element, typename Number, size_t depth, size_t rank>
  auto numbercast(const ExpressionR<X, Element, Number, depth, rank>& x) {
    typedef typename NumberTrait<Element, NT2>::ReplacedNumberType EOUT;
    return  ExpressionR_Unary<ExpressionR<X, Element, Number, depth, rank>, EOUT, NT2, depth, rank, FUNCTOR_numbercast<Element, EOUT, Number, NT2>>(x);
  }


  /****************************************************************************
 * Equality related
 ****************************************************************************
 */


 // ----------------------------------------------------------------
 // FUNCTOR_roundzero
 // ----------------------------------------------------------------


  template <class Element, typename Number> class FUNCTOR_roundzero {
  public:
    typedef typename SimpleNumberTrait<Number>::Type DTOL;
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
  template <class X, class Element, typename Number, size_t depth, size_t rank>
  auto roundzero(const ExpressionR<X, Element, Number, depth, rank>& x, const typename SimpleNumberTrait<Number>::Type& tol = Functions<typename SimpleNumberTrait<Number>::Type>::tolerance) {

    typedef typename SimpleNumberTrait<Number>::Type DTOL;
    return  ExpressionR_Binary<ExpressionR<X, Element, Number, depth, rank>,
      DTOL,
      Element, DTOL, Element, Number, DTOL, Number, depth, 0, depth, rank, 0, rank,
      FUNCTOR_roundzero<Element, Number>>(x, tol);
  }




  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
  bool equal(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2) {
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


  template <class E1, class E2, class E3, class NT1, class NT2, class NT3> class FUNCTOR_approx {
  public:
    typedef typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type DTOL;

    static NT3 apply(const NT1 d1, const NT2 d2, const DTOL tol) {
      return mathq::approx(d1, d2, tol);
    }
    template <class T1 = E1, class T2 = E2>
    static typename std::enable_if<!std::is_same<T1, NT1>::value&&!std::is_same<T2, NT2>::value, E3& >::type
      apply(const E1& e1, const E2& e2, const DTOL tol) {
      E3* e3 = new E3();
      *e3 = mathq::approx(e1, e2, tol);
      return *e3;
    }
    template <class T1 = E1>
    static typename std::enable_if<!std::is_same<T1, NT1>::value, E3& >::type
      apply(const E1& e1, const NT2 d2, const DTOL tol) {
      E3* e3 = new E3();
      *e3 = mathq::approx(e1, d2, tol);
      return *e3;
    }
    template <class T2 = E2>
    static typename std::enable_if<!std::is_same<T2, NT2>::value, E3& >::type
      apply(const NT1 d1, const E2& e2, const DTOL tol) {
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
      NT1 d1;
      NT2 d2;
      NT3 d3;
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



  // (11) MultiArray<E1(NT1)> , MultiArray<E2(NT2)> 

  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
  auto approx(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type& tol = Functions<typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type>::tolerance) {

    typedef typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type DTOL;
    typedef bool NT3;
    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3;
    return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
      ExpressionR<B, E2, NT2, depth, rank>,
      DTOL,
      E1, E2, DTOL, E3, NT1, NT2, DTOL, NT3, depth, depth, 0, depth, rank, rank, 0, rank,
      FUNCTOR_approx<E1, E2, E3, NT1, NT2, NT3> >(x1, x2, tol);
  }

  // (10) MultiArray<E1(NT1)> , NT2 

  template <class A, class E1, class NT1, class NT2, size_t depth, size_t rank>
  auto approx(const ExpressionR<A, E1, NT1, depth, rank>& x1, const NT2& x2, const typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type& tol = Functions<typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type>::tolerance) {

    typedef typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type DTOL;
    typedef bool NT3;
    typedef typename NumberTrait<E1, NT3>::ReplacedNumberType E3;
    return  ExpressionR_Ternary<ExpressionR<A, E1, NT1, depth, rank>,
      NT2,
      DTOL,
      E1, NT2, DTOL, E3, NT1, NT2, DTOL, NT3, depth, 0, 0, depth, rank, 0, 0, rank,
      FUNCTOR_approx<E1, NT2, E3, NT1, NT2, NT3> >(x1, x2, tol);
  }



  // (01) NT1, MultiArray<E2(NT2)> 

  template <class B, class E2, class NT1, class NT2, size_t depth, size_t rank>
  auto approx(NT1& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type& tol = Functions<typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type>::tolerance) {

    typedef typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type DTOL;
    typedef bool NT3;
    typedef typename NumberTrait<E2, NT3>::ReplacedNumberType E3;
    return  ExpressionR_Ternary<NT1,
      ExpressionR<B, E2, NT2, depth, rank>,
      DTOL,
      NT1, E2, DTOL, E3, NT1, NT2, DTOL, NT3, 0, depth, 0, depth, 0, rank, 0, rank,
      FUNCTOR_approx<NT1, E2, E3, NT1, NT2, NT3> >(x1, x2, tol);
  }



  // -------------------------------------------------------------------
  // equal_approx - if two tensors are approximately equal, returns a single bool
  //          checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class NT1, class NT2, size_t depth, size_t rank>
  bool equal_approx(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2, const  typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type tol = Functions< typename SimpleNumberTrait<typename AddType<NT1, NT2>::Type>::Type>::tolerance) {

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

  template <class X, class Element, typename Number, size_t depth, size_t rank, typename = EnableIf<std::is_same<Number, bool>::value> >
  bool alltrue(const ExpressionR<X, Element, Number, depth, rank>& x) {

    for (size_t i = 0; i< x.total_size(); i++) {
      if (!x.dat(i)) {
        return false;
      }
    }

    return true;
  }


  // anytrue(a)

  template <class X, class Element, typename Number, size_t depth, size_t rank, typename = EnableIf<std::is_same<Number, bool>::value> >
  bool anytrue(const ExpressionR<X, Element, Number, depth, rank>& x) {

    for (size_t i = 0; i< x.total_size(); i++) {
      if (x.dat(i)) {
        return true;
      }
    }

    return false;
  }


  // numtrue(a)

  template <class X, class Element, typename Number, size_t depth, size_t rank, typename = EnableIf<std::is_same<Number, bool>::value> >
  size_t numtrue(const ExpressionR<X, Element, Number, depth, rank>& x) {

    size_t result = 0;

    for (size_t i = 0; i< x.total_size(); i++) {
      result += static_cast<size_t>(x.dat(i));
    }

    return result;
  }





  // findtrue(a) - deep indexing

  // NOTE: declaration in declarations.h

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<std::is_same<Number, bool>::value, Vector<size_t>&>
    findtrue(const ExpressionR<X, Element, Number, depth, rank>& x) {
    size_t N = numtrue(x);
    Vector<size_t>* y = new Vector<size_t>(N);

    size_t j = 0;
    for (size_t i = 0; i< x.total_size(); i++)
      if (x.dat(i))
        (*y)[j++] = i;

    return *y;
  }


  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

   // sum(a)

  template <class X, class Element, typename Number, size_t depth, size_t rank >
  Element sum(const ExpressionR<X, Element, Number, depth, rank>& v) {


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

  template <class X, class Element, typename Number, size_t depth, size_t rank >
  Element prod(const ExpressionR<X, Element, Number, depth, rank>& v) {


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

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  Number min(const ExpressionR<X, Element, Number, depth, rank>& v) {

    const size_t N = v.total_size();
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

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  Number max(const ExpressionR<X, Element, Number, depth, rank>& v) {

    const size_t N = v.total_size();
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

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  Number sumofsqrs(const ExpressionR<X, Element, Number, depth, rank>& v) {
    Number result = Number();
    for (size_t i = 0; i < v.size(); i++) {
      result += normsqr(v[i]);
    }
    return result;
  }

  // norm(a)  - L2 norm

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  Number norm(const ExpressionR<X, Element, Number, depth, rank>& v) {
    return std::sqrt(sumofsqrs(v));
  }



  // *********************************************************
  // *          Functions that create vectors
  // *********************************************************

  // The Interval generating function (with step given)

  template <typename Number>
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

  template <typename Number>
  Vector<Number>& range(Number start, Number end) {
    if (end >= start)
      return range<Number>(start, end, static_cast<Number>(1));
    else
      return range<Number>(start, end, static_cast<Number>(-1));
  }





  // linspace function [a,b]

  template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
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

  template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  Vector<Number>& linspace_a(Number start, Number end, size_t N) {
    Vector<Number>* y = new Vector<Number>(N);


    const Number step = (end-start)/static_cast<Number>(N);
    return linspace(start+step, end, N);
  }


  // linspace_b function [a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a to b-delta

  template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  Vector<Number>& linspace_b(Number start, Number end, size_t N) {
    Vector<Number>* y = new Vector<Number>(N);


    const Number step = (end-start)/static_cast<Number>(N);
    return linspace(start, end-step, N);
  }

  // linspace_ab function (a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b-delta

  template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
  Vector<Number>& linspace_ab(Number start, Number end, size_t N) {
    Vector<Number>* y = new Vector<Number>(N);


    const Number step = (end-start)/static_cast<Number>(N+1);
    return linspace(start+step, end-step, N);
  }


  // *********************************************************
  // *          Functions that return a vector from a vector
  // *********************************************************


  // reverse

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> reverse(const ExpressionR<X, Element, Number, depth, rank>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->reverse();
    return *g;
  }


  // cumsum() -- cumulative sum

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> cumsum(const ExpressionR<X, Element, Number, depth, rank>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumsum();
    return *g;
  }

  // cumprod()  --  cumulative product

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> cumprod(const ExpressionR<X, Element, Number, depth, rank>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumprod();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> cumtrapz(const ExpressionR<X, Element, Number, depth, rank>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumtrapz();
    return *g;
  }

  // integrate_a2x(order)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> integrate_a2x(const ExpressionR<X, Element, Number, depth, rank>& f, const Number a, const Number b, const size_t order = 1) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->integrate_a2x(a, b, order);
    return *g;
  }


  // cumsumrev() -- cumulative sum -- from last to first

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> cumsum_rev(const ExpressionR<X, Element, Number, depth, rank>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumsum_rev();
    return *g;
  }

  // cumprodrev()  --  cumulative product  -- from last to first

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> cumprod_rev(const ExpressionR<X, Element, Number, depth, rank>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumprod_rev();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation -- from last to first

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> cumtrapz_rev(const ExpressionR<X, Element, Number, depth, rank>& f) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->cumtrapz_rev();
    return *g;
  }



  // integrate_x2b
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&> integrate_x2b(const ExpressionR<X, Element, Number, depth, rank>& f, const Number a, const Number b, const size_t order = 1) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->integrate_x2b(a, b, order);
    return *g;
  }



  // diff   (v[n] = v[n] - v[n-1])
  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&>  diff(const ExpressionR<X, Element, Number, depth, rank>& f, const bool periodic = false) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->diff(periodic);
    return *g;
  }

  // diff_rev   (v[n] = v[n+1] - v[n])
  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&>  diff_rev(const ExpressionR<X, Element, Number, depth, rank>& f, const bool periodic = false) {
    Vector<Element>* g = new Vector<Element>(f.size());
    *g = f;
    g->diff_rev(periodic);
    return *g;
  }


  // derivative
  // any change in the default parameters must be likewise made in Vector.deriv(...)

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<rank==1, Vector<Element>&>  deriv(const ExpressionR<X, Element, Number, depth, rank>& f, const Number a, const Number b, const size_t n = 1, size_t Dpts = 7, const bool periodic = false) {
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

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  EnableMethodIf<(depth==1)&&(rank==1), Number> integrate_a2b(const ExpressionR<X, Element, Number, depth, rank>& v, const Number a, const Number b, const size_t order = 1) {


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

  template <class A, class X, class Element, typename Number, size_t D1, size_t D2, size_t R1, size_t R2, typename = EnableIf<(D1==1)&&(R1==1)>>
  auto maclaurin(const ExpressionR<A, Number, Number, D1, R1>& a, const ExpressionR<X, Element, Number, D2, R2>& x, const size_t N, const Number x0) {
    return ExpressionR_Series<ExpressionR<A, Number, Number, D1, R1>, ExpressionR<X, Element, Number, D2, R2>, Element, Number, D2, R2>(a, x, N, x0);
  }

  // // taylor(vector coefs, vector vals, max N)

  template <class A, class X, class Element, typename Number, size_t D1, size_t D2, size_t R1, size_t R2, typename = EnableIf<(D1==1)&&(R1==1)>>
  auto taylor(const ExpressionR<A, Number, Number, D1, R1>& a, const ExpressionR<X, Element, Number, D2, R2>& x, const size_t N) {
    return ExpressionR_Series<ExpressionR<A, Number, Number, D1, R1>, ExpressionR<X, Element, Number, D2, R2>, Element, Number, D2, R2>(a, x, N);
  }

  // // ifourier(vector cos coefs, vector sin coefs, vector vals, max N, k1=2pi/wavelength or 2pi/period)
  // // sin coefs must include a coef for n=0 even though its irrelevant

  template <class A, class B, class X, typename Number, size_t depth, size_t rank, typename = EnableIf<(depth==1)&&(rank==1)> >
  auto ifourier(const ExpressionR<A, Number, Number, depth, rank>& Acos, const ExpressionR<B, Number, Number, depth, rank>& Bsin, const ExpressionR<X, Number, Number, depth, rank>& x, const size_t N, const Number k1) {
    return  ExpressionR_Series2<ExpressionR<A, Number, Number, depth, rank>, ExpressionR<B, Number, Number, depth, rank>, ExpressionR<X, Number, Number, depth, rank>, Number, FUNCTOR_cos<Number, Number, Number, Number>, FUNCTOR_sin<Number, Number, Number, Number> >(Acos, Bsin, x, N, k1);
  }





};

#endif 
