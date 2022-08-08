#ifndef MATHQ__MATH_REAL
#define MATHQ__MATH_REAL


namespace mathq {


  // ***************************************************************************
  // *                   REAL MATH LIBRARY
  // ***************************************************************************


  using quad = long double;

  /****************************************************************************
    * tolerances
    ****************************************************************************
    */

  template <typename Number> struct Functions {
  public:
    static Number tolerance = Number(0);
  };
  template <> struct Functions<long double> {
  public:
    constexpr static long double tolerance = 1.5e-30;
  };
  template <> struct Functions<double> {
  public:
    constexpr static double tolerance = 1.5e-16;
  };
  template <> struct Functions<float> {
  public:
    constexpr static float tolerance = 3.5e-7;
  };

  template <> struct Functions<char> {
  public:
    constexpr static char tolerance = 0;
  };
  template <> struct Functions<short> {
  public:
    constexpr static short tolerance = 0;
  };
  template <> struct Functions<int> {
  public:
    constexpr static int tolerance = 0;
  };
  template <> struct Functions<long> {
  public:
    constexpr static long tolerance = 0;
  };
  template <> struct Functions<long long> {
  public:
    constexpr static long long tolerance = 0;
  };

  template <> struct Functions<unsigned char> {
  public:
    constexpr static unsigned char tolerance = 0;
  };
  template <> struct Functions<unsigned short> {
  public:
    constexpr static unsigned short tolerance = 0;
  };
  template <> struct Functions<unsigned int> {
  public:
    constexpr static unsigned int tolerance = 0;
  };
  template <> struct Functions<unsigned long> {
  public:
    constexpr static unsigned long tolerance = 0;
  };
  template <> struct Functions<unsigned long long> {
  public:
    constexpr static unsigned long long tolerance = 0;
  };


  //****************************************************************************
  // functions for ints and floats
  //****************************************************************************


  // roundzero

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number roundzero(const Number& x, const Number tolerance = Functions<Number>::tolerance) {
    return (std::abs(x) < std::abs(tolerance) ? 0 : x);
  }


  // zero


  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number zero() {
    return Number(0);
  }

  // one

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number one() {
    return Number(1);
  }


  // complex functions defined for real values

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value> > Number
    conj(const Number& x) {
    return x;
  }

  // complex conjugate OPERTOR ~
  // ~ is defined for ints nad can;t be defined for reals

  // template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value> >
  // Number operator~(Number& x) {
  //   return x;
  // }

  // real

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value> > Number
    real(const Number& x) {
    return x;
  }

  // imag

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number imag(const Number& x) {
    return 0;
  }


  // sqr(x)

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number sqr(const Number& x) {
    return x*x;
  }

  // normsqr(x)

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number normsqr(const Number& x) {
    return x*x;
  }


  // cube(x)

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number cube(const Number& x) {
    return x*x*x;
  }


  // logN(x, N)

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number logN(const Number& x, unsigned int N) {
    return std::log(x)/std::log(N);
  }

  // approx

  // TODO: use std::frexp() instead ?

  template <typename NT1, typename NT2>
  bool approx(const NT1& x, const NT2& y, typename AddType<NT1, NT2>::Type tol = Functions<typename AddType<NT1, NT2>::Type>::tolerance) {
    typename AddType<NT1, NT2>::Type d = std::max(x, y);
    tol *= d;
    return (roundzero(std::abs(x-y), tol) == 0);
  }

  // numbercast

  template <typename NT2, typename NT1,
    typename = std::enable_if_t<std::is_arithmetic<NT1>::value>,
    typename = std::enable_if_t<std::is_arithmetic<NT2>::value> >
    NT2 numbercast(const NT1 x) {
    return static_cast<NT2>(x);
  }



  //***********************************************************************
  //       sgn(x) function created via macros
  //***********************************************************************

#define SGN_MACRO(number)  inline number sgn(const number x) {if (x>0) return static_cast<number>(1); else if (x<0) return static_cast<number>(-1); else return static_cast<number>(0);}
#define SGN_MACRO_US(number)  inline number sgn(const number x) {if (x>0) return static_cast<number>(1);else return static_cast<number>(0);}

  SGN_MACRO(float);
  SGN_MACRO(double);
  SGN_MACRO(long double);
  SGN_MACRO(char);
  SGN_MACRO_US(unsigned char);
  SGN_MACRO(short);
  SGN_MACRO_US(unsigned short);
  SGN_MACRO(int);
  SGN_MACRO_US(unsigned int);
  SGN_MACRO(long);
  SGN_MACRO_US(unsigned long);
#if LONGLONG_EXISTS
  SGN_MACRO(long long);
  SGN_MACRO_US(unsigned long long);
#endif





};


#endif
