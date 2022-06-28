#ifndef MATHQ__MATH_REAL_H
#define MATHQ__MATH_REAL_H


namespace mathq {


  // ***************************************************************************
  // *                   REAL MATH LIBRARY
  // ***************************************************************************



    // maximum subcript size for vectors and matrices (since we allow negative indexing)
  const size_t maxsize = std::numeric_limits<size_t>::max();
  const size_t badsize = std::numeric_limits<size_t>::max();


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




  // TODO: C++17 has its own gcd gcf

  // GCD
  inline int gcd(int a, int b) {
    int r;
    do {
      r = a % b;
      a = b;
      b = r;
    } while (r != 0);

    return a;
  }


  // roundzero

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number roundzero(const Number& x, const Number tolerance = Functions<Number>::tolerance) {
    return (std::abs(x) < std::abs(tolerance) ? 0 : x);
  }


  // zero

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number zero(const Number& x) {
    return Number(0);
  }

  // one

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
  Number one(const Number& x) {
    return Number(1);
  }

  // conj
  // complex conjugate: real numbers
  //                    note this is different from std::conj,
  //                    which returns a complex number

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value> > Number
    conj(const Number& x) {
    return x;
  }

  // complex conjugate OPERTOR ~

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value> > Number
    operator~(Number& x) {
    return x;
  }


  // imag

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

  template <typename D1, typename D2>
  bool approx(const D1& x, const D2& y, typename AddType<D1, D2>::Type tol = Functions<typename AddType<D1, D2>::Type>::tolerance) {
    typename AddType<D1, D2>::Type d = std::max(x, y);
    tol *= d;
    return (roundzero(std::abs(x-y), tol) == 0);
  }

  // numbercast

  template <typename D2, typename D1,
    typename = std::enable_if_t<std::is_arithmetic<D1>::value>,
    typename = std::enable_if_t<std::is_arithmetic<D2>::value> >
    D2 numbercast(const D1 x) {
    return static_cast<D2>(x);
  }



  //***********************************************************************
  //       sgn(x) function
  //***********************************************************************

#define SGN_MACRO(Number)  inline Number sgn(const Number x) {if (x>0) return static_cast<Number>(1); else if (x<0) return static_cast<Number>(-1); else return static_cast<Number>(0);}
#define SGN_MACRO_US(Number)  inline Number sgn(const Number x) {if (x>0) return static_cast<Number>(1);else return static_cast<Number>(0);}

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
