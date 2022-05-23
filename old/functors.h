#ifndef MATRICKS__FUNCTORS_H
#define MATRICKS__FUNCTORS_H


//  functor in C++ sense: a class that wraps a function
//
// TODO: add bitwise functors for unsigned types
// TOOD: switch from "apply" to "operator()"?  not sure if that would help. maybe it's good to explcittly show these are functors with ".apply"


namespace matricks {


  extern display::Style functor_namestyle;
  extern display::Style functor_style;
  extern display::Style userfunctor_style;




  
  // ************************************************************************
  // *              Arithmetic
  // ************************************************************************

  // unary+ operator

  template <class D> class Fun_Plus {
    Fun_Plus() {}
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      return a;
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("+")+"("+ sa + ")";
      return sout;
    }

    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif
        
  };
    

  
  
  // unary-

  template <class D> class Fun_Minus {
    Fun_Minus() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      return (-a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("-")+"("+ sa + ")";
      return sout;
    }

    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Minus")+display::getBracketedTypeName(d);
    }
#endif

  };


  // cast - from D1 to D2

  template <class D2, class D1> class Fun_Cast {
    Fun_Cast() { }
  public:
    typedef typename NumberType<D1>::Type TypeIn;
    typedef typename NumberType<D2>::Type Type;
    typedef typename FundamentalType<D1>::Type FTypeIn;
    typedef typename FundamentalType<D2>::Type FType;

    static inline Type apply(const TypeIn a) { 
      return numbercast<FType,FTypeIn>(a); 
    }
    

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      using namespace display;
      D2 d2;
      std::string sout = functor_style.apply("numbercast")+"<" + getTypeName(d2) + ">(" + sa + ")";
      return sout;
    }

    static std::string classname() {
      using namespace display;
      D1 d1;
      D2 d2;
      std::string s = functor_namestyle.apply("Fun_Cast");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
#endif
    
  };



  // y = a + b

  template <class A, class B> class Fun_Add {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename AddType<NA,NB>::Type Type;
      
    Fun_Add() { }
  
    static inline auto apply(const NA& a, const NB& b) {
      return a+b;
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("+") + sb + ")";
      return sout;
    }
    
#endif

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Add");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    
  };




  
  // y = a - b

  template <class A, class B> class Fun_Subtract {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename SubType<NA,NB>::Type Type;
      
    Fun_Subtract() { }
  
    static inline auto apply(const NA& a, const NB& b) {
      return a-b;
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("-") + sb + ")";
      return sout;
    }
    
#endif

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Subtract");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    
  };


  // y = a * b

  template <class A, class B> class Fun_Multiply {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename MultType<NA,NB>::Type Type;
      
    Fun_Multiply() { }
  
    static inline auto apply(const NA& a, const NB& b) {
      return a*b;
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("*") + sb + ")";
      return sout;
    }
    
#endif

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Multiply");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    
  };


  // y = a / b

  template <class A, class B> class Fun_Divide {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename DivType<NA,NB>::Type Type;
      
    Fun_Divide() { }
  
    static inline auto apply(const NA& a, const NB& b) {
      return a/b;
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("/") + sb + ")";
      return sout;
    }
    
#endif

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Divide");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    
  };



  

  
  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  // y = pow(a,b)

  template <class A, class B> class Fun_Pow {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename MultType<NA,NB>::Type Type;
      
    Fun_Pow() { }
  
    static inline auto apply(const NA& a, const NB& b) {
      using std::pow;
      return pow(a,b);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "pow(" + sa  + functor_style.apply(",") + sb + ")";
      return sout;
    }
    
#endif

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Pow");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    
  };

  
  // sqr(a)

  template <class D> class Fun_Sqr {
    Fun_Sqr() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      return (a*a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sqr")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sqr")+display::getBracketedTypeName(d);
    }
#endif

  };


  // cube(a)

  template <class D> class Fun_Cube {
    Fun_Cube() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      return (a*a*a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("cube")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Cube")+display::getBracketedTypeName(d);
    }
#endif

  };


  // sqrt(a)

  template <class D> class Fun_Sqrt {
    Fun_Sqrt() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::sqrt;
      return sqrt(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sqrt")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sqrt")+display::getBracketedTypeName(d);
    }
#endif

  };


  // exp(a)
  template <class D> class Fun_Exp {
    Fun_Exp() { }
    
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::exp;
      return exp(a);
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("exp")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Exp")+display::getBracketedTypeName(d);
    }
#endif

  };

 
  // log(a)

  template <class D> class Fun_Log {
    Fun_Log() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::log;
      return log(a);
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("log")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Log")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // log2(a)

  template <class D> class Fun_Log2 {
    Fun_Log2() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::log2;
      using matricks::log2;
      return log2(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("log2")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Log2")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // log10(a)
 
  template <class D> class Fun_Log10 {
    Fun_Log10() {
    }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::log10;
      return log10(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("log10")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Log10")+display::getBracketedTypeName(d);
    }
#endif

  };



    
  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************


  // sin(a)

  template <class D> class Fun_Sin {
    Fun_Sin() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::sin;
      return sin(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sin")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sin")+display::getBracketedTypeName(d);
    }
#endif

  };


  // cos(a)

  template <class D> class Fun_Cos {
    Fun_Cos() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::cos;
      return cos(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("cos")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Cos")+display::getBracketedTypeName(d);
    }
#endif

  };




  // tan(a)

  template <class D> class Fun_Tan {
    Fun_Tan() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::tan;
      return tan(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("tan")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Tan")+display::getBracketedTypeName(d);
    }
#endif

  };


  // asin(a)

  template <class D> class Fun_Asin                       {
    Fun_Asin() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::asin;
      return asin(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("asin")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Asin")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // acos(a)

  template <class D> class Fun_Acos                       {
    Fun_Acos() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::acos;
      return acos(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("acos")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Acos")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // atan(a)

  template <class D> class Fun_Atan {
    Fun_Atan() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::atan;
      return atan(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("atan")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Atan")+display::getBracketedTypeName(d);
    }
#endif

  };




  // y = atan2(a,b)  

  template <class A, class B> class Fun_Atan2 {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename MultType<NA,NB>::Type Type;
      
    Fun_Atan2() { }
  
    static inline auto apply(const NA& a, const NB& b) {
      using std::atan2;
      return atan2(a,b);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "atan2(" + sa  + functor_style.apply(",") + sb + ")";
      return sout;
    }
    
#endif

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Atan2");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    
  };


  // sinh(a)

  template <class D> class Fun_Sinh {
    Fun_Sinh() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::sinh;
      return sinh(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sinh")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sinh")+display::getBracketedTypeName(d);
    }
#endif

  };



  // cosh(a)

  template <class D> class Fun_Cosh {
    Fun_Cosh() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::cosh;
      return cosh(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("cosh")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Cosh")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // tanh(a)

  template <class D> class Fun_Tanh {
    Fun_Tanh() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::tanh;
      return tanh(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("tanh")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Tanh")+display::getBracketedTypeName(d);

    }
#endif

  };



  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  // abs(a)

  template <class D> class Fun_Abs {
    Fun_Abs() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::abs;
      return abs(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("abs")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Abs")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // sgn(a)

  template <class D> class Fun_Sgn {
    Fun_Sgn() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      return matricks::sgn(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sgn")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sgn")+display::getBracketedTypeName(d);
    }
#endif

  };


  
 
  
  // ceil(a)

  template <class D> class Fun_Ceil {
    Fun_Ceil() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::ceil;
      using matricks::ceil; // for complex nums
      return ceil(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("ceil")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Ceil")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // floor(a)

  template <class D> class Fun_Floor {
    Fun_Floor() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::floor;
      using matricks::floor;  // for complex nums
      return floor(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("floor")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Floor")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // round(a)

  template <class D> class Fun_Round {
    Fun_Round() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::round;
      using matricks::round;
      return round(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("round")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Round")+display::getBracketedTypeName(d);
    }
#endif

  };

  
  // roundzero(a,tol)

  template <class A, class B> class Fun_Roundzero {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename AddType<NA,NB>::Type Type;

    Fun_Roundzero() { }

    static inline Type apply(const NA& a, const NB tolerance) {
      return matricks::roundzero(a, tolerance);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("roundzero") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Roundzero");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
#endif

  };


  
  // approx(a,b,tol)

  template <class A, class B, typename TOL> class Fun_Approx {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef bool Type;

    Fun_Approx() { }
  
    static inline auto apply(const NA& a, const NB& b, const TOL& tolerance) {
      return matricks::approx(a, b, tolerance);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
      std::string sout =  functor_style.apply("approx")+ "(" + sa  + "," + sb + "," + sc + ")";
      return sout;
    }
    

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      TOL d3;
      std::string s = functor_namestyle.apply("Fun_Approx");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(COMMA).get() + getTypeName(d3);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
#endif
    
  };


  // ************************************************************************
  // *              User Defined
  // ************************************************************************



  // y = op1<D,userfunc>(a)

  template <class D, typename matricks::FunctionTypes<D>::unary_func F> class Fun_UnaryUser {
    Fun_UnaryUser() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename NumberType<D>::Type Type;

    static inline Type apply(const TypeIn a) { 
      return F(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = userfunctor_style.apply("userfunc") +  "(" + sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_UnaryUser")+display::getBracketedTypeName(d);
    }
#endif
	
    
  };


  
  // y = op2<D,userfunc>(a,b)

  template <class A, class B, typename FunctionTypes<typename NumberType<A>::Type>::binary_func F> class Fun_BinaryUser {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename MultType<NA,NB>::Type Type;
      
    Fun_BinaryUser() { }
  
    static inline auto apply(const NA& a, const NB& b) {
      return F(a,b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "userfunc(" + sa  + functor_style.apply(",") + sb + ")";
      return sout;
    }
    
#endif

    static inline std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_BinaryUser");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
    
  };


  

  // ***********************************************************************
  // *              Logic
  // ***********************************************************************


  // !(a)

  class Fun_Not {
    Fun_Not() { }

  public:
    typedef bool TypeIn;
    typedef  bool Type;

    static inline Type apply(const TypeIn a) { 
      return !(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("!")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_Not");
    }
#endif

  };

  
  // y = a && b

  template <class A, class B> class Fun_And {
  public:
    typedef bool Type;
    typedef typename DeeperType<A,B>::Type DeeperType_;
    typedef typename NumberType<DeeperType_,Type>::Type TensorType;

    Fun_And() { }
  
    static inline Type apply(const bool a, const bool b) { 
      return a && b; 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("&&")  + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      bool d1;
      bool d2;
      std::string s = functor_namestyle.apply("Fun_And");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };


  // y = a || b

  template <class A, class B> class Fun_Or {
  public:
    typedef bool Type;
    typedef typename DeeperType<A,B>::Type DeeperType_;
    typedef typename NumberType<DeeperType_,Type>::Type TensorType;

    Fun_Or() { }
  
    static inline bool apply(const bool a, const bool b) { 
      return (a || b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("||") +  sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      bool d1;
      bool d2;
      std::string s = functor_namestyle.apply("Fun_Or");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };




  // ************************************************************************
  // *              Relational ops (return a bool from two Ds)
  // ************************************************************************

  // y = (a == b)

  template <class A, class B> class Fun_Equal {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef bool Type;

    Fun_Equal() { }

    static inline Type apply(const NA& a, const NB& b) { 
      return (a == b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + functor_style.apply("==") + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Equal");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };

 



  // y = (a != b)

  template <class A, class B> class Fun_NotEqual {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef bool Type;

    Fun_NotEqual() { }

    static inline Type apply(const NA& a, const NB& b) { 
      return (a != b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("!=") + "(" + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_NotEqual");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };

 



  // y = (a <= b)

  
  template <class A, class B> class Fun_LessOrEqual {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef bool Type;

    Fun_LessOrEqual() { }

    static inline Type apply(const NA& a, const NB& b) { 
      return (a <= b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("<=")  + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_LessOrEqual");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };



  // y = (a >= b)

  template <class A, class B> class Fun_GreaterOrEqual {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef bool Type;

    Fun_GreaterOrEqual() { }

    static inline Type apply(const NA& a, const NB& b) { 
      return (a >= b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply(">=")  + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_GreaterOrEqual");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };


  // y = (a < b)

  template <class A, class B> class Fun_Less {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef bool Type;
    
    Fun_Less() { }

    static inline Type apply(const NA& a, const NB& b) { 
      return (a < b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa  + functor_style.apply("<")  + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Less");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };


  // y = (a > b)

  template <class A, class B> class Fun_Greater {
  public: 
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef bool Type;

    Fun_Greater() { }

    static inline Type apply(const NA& a, const NB& b) { 
      return (a > b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + functor_style.apply(">") + sb + ")";
      return sout;
    }
    
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Greater");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };



  // ************************************************************************
  // *              complex numbers
  // ************************************************************************



  // polar(r,phi)

  template <class A, class B> class Fun_Polar {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename AddType<NA,NB>::Type RType;
    typedef typename std::complex<RType> Type;
    
    Fun_Polar() { }

    static inline Type apply(const NA& r, const NB& phi) { 
      using std::polar;
      return polar((RType)r,(RType)phi); 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("polar") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    

    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Polar");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };

 

  // complexify(x,y)

  template <class A, class B> class Fun_Complex {
  public:
    typedef typename NumberType<A>::Type NA;
    typedef typename NumberType<B>::Type NB;
    typedef typename AddType<NA,NB>::Type RType;
    typedef typename std::complex<RType> Type;

    Fun_Complex() { }

    static inline Type apply(const NA& x, const NB& y) { 
      return Type((RType)x,(RType)y); 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("complex") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    static std::string classname() {
      using namespace display;
      NA d1;
      NB d2;
      std::string s = functor_namestyle.apply("Fun_Complex");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#endif

  };





  // arg(a)

  template <class D> class Fun_Arg {
    Fun_Arg() { }
  public:
    typedef std::complex<D> TypeIn;
    typedef D Type;

    static inline Type apply(const TypeIn a) { 

      using std::arg;
      return arg(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("arg")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      TypeIn d;
      return functor_namestyle.apply("Fun_Arg")+display::getBracketedTypeName(d);
    }
#endif

  };




  // conj(a)

  template <class D > class Fun_Conj {
    Fun_Conj() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename Complexify<TypeIn>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::conj;
      return conj(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("conj")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Conj")+display::getBracketedTypeName(d);
    }
#endif

  };


  // real(a)

  template <class D> class Fun_Real {
    Fun_Real() { }
  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename Realify<TypeIn>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::real;
      return real(a); 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("real")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Real")+display::getBracketedTypeName(d);
    }
#endif

  };


  // imag(a)

  template <class D> class Fun_Imag {
    Fun_Imag() { }

  public:
    typedef typename NumberType<D>::Type TypeIn;
    typedef typename Realify<TypeIn>::Type Type;

    static inline Type apply(const TypeIn a) { 
      using std::imag;
      return imag(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("imag")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Imag")+display::getBracketedTypeName(d);
    }
#endif

  };





};

#endif

