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

  template <typename T> struct Functions {
  public:
    using SimpleNumberType = typename SimpleNumberTrait<T>::Type;
    constexpr static decltype(Functions<SimpleNumberType>::tolerance) tolerance = Functions<SimpleNumberType>::tolerance;
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

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num roundzero(const Num& x, const Num tolerance = Functions<Num>::tolerance) {
    return (std::abs(x) < std::abs(tolerance) ? 0 : x);
  }


  // zero


  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num zero() {
    return Num(0);
  }

  // one

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num one() {
    return Num(1);
  }


  // complex functions defined for real values

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value> > Num
    conj(const Num& x) {
    return x;
  }

  // complex conjugate OPERTOR ~
  // ~ is defined for ints nad can;t be defined for reals

  // template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value> >
  // Num operator~(Num& x) {
  //   return x;
  // }

  // real

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value> > Num
    real(const Num& x) {
    return x;
  }

  // imag

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num imag(const Num& x) {
    return 0;
  }


  // sqr(x)

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num sqr(const Num& x) {
    return x*x;
  }

  // normsqr(x)

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num normsqr(const Num& x) {
    return x*x;
  }


  // cube(x)

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num cube(const Num& x) {
    return x*x*x;
  }


  // logN(x, N)

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value>>
  Num logN(const Num& x, unsigned int N) {
    return std::log(x)/std::log(N);
  }

  // approx

  // TODO: use std::frexp() instead ?

  template <typename NT1, typename NT2> requires (IsSimpleNumber<NT1>&& IsSimpleNumber<NT2>)
    bool approx(const NT1& x, const NT2& y, const decltype(Functions<typename AddType<NT1, NT2>::Type>::tolerance)& tol = Functions<typename AddType<NT1, NT2>::Type>::tolerance) {
    typename AddType<NT1, NT2>::Type d = std::max(x, y);
    decltype(Functions<typename AddType<NT1, NT2>::Type>::tolerance) tolerance = d * tol;
    return (roundzero(std::abs(x-y), tolerance) == 0);
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
