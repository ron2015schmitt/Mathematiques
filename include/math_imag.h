#ifndef MATHQ__MATH_IMAG
#define MATHQ__MATH_IMAG


namespace mathq {




  // ***************************************************************************
  // *                   Imaginary Num
  // ***************************************************************************
  template <typename Num>
  class Imaginary {
  private:
    Num d_;

  public:
    Imaginary() : d_(1) {
    }
    Imaginary(const Num d) : d_(d) {
    }
    ~Imaginary() {
    }

    Num value() const {
      return d_;
    }
    Num real() {
      return Num(0);
    }
    Num imag() {
      return d_;
    }
    Num abs() {
      return std::abs(d_);
    }
    Num normsqr() {
      return d_*d_;
    }


    Imaginary<Num>& negate() {
      d_ = -d_;
      return *this;
    }

    Imaginary<Num>& invert() {
      d_ = -1/d_;
      return *this;
    }

    Imaginary<Num>& conjugate() {
      d_ = -d_;
      return *this;
    }



    Num operator=(const Num& y) {
      return d_ = y.value();
    }

    inline static std::string classname() {
      Num d;
      return "Imaginary" + display::bracketAndStyleTypename(d);
    }




    // arithmetic operators
    Imaginary<Num>& operator+=(const Imaginary<Num>& y) {
      *this = *this + y;
      return *this;
    }

    Imaginary<Num>& operator-=(const Imaginary<Num>& y) {
      *this = *this - y;
      return *this;
    }


    Imaginary<Num>& operator*=(const Num& y) {
      *this = *this * y;
      return *this;
    }

    Imaginary<Num>& operator/=(const Num& y) {
      *this = *this / y;
      return *this;
    }




    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Imaginary<Num>& w) {
      using namespace display;
      const Num val = w.value();
      if (val != 1) {
        dispval_strm(stream, val);
      }
      // TODO: create style for the i
      stream << "i";
      return stream;
    }


    // template <typename Num>
    friend inline std::istream& operator>>(const std::string s, Imaginary<Num>& w) {
      std::istringstream st(s);
      return (st >> w);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream, Imaginary<Num>& w) {
      return stream;
    }
  };



  // ***************************************************************************
  // * i: the unit imaginary
  // ***************************************************************************


  namespace unit_imaginary {
    const Imaginary<float> iF(1);
    const Imaginary<double> i(1);
    const Imaginary<long double> iL(1);
  }; // namespace unit_imaginary



  // ***************************************************************************
  // numbercast
  // ***************************************************************************


  template <typename I2, typename F1>
  EnableMethodIf<IsImaginary<I2>::value, I2>
    numbercast(const Imaginary<F1>& y) {
    typedef typename IsImaginary<I2>::SimpleNumberType F2;
    F2 val = numbercast<F2>(y.value());
    return Imaginary<F2>(val);
  }


  // ***************************************************************************
  // Complex
  // ***************************************************************************


  template <typename Num>
  inline std::complex<Num>
    Complex(const Imaginary<Num>& x) {
    return std::complex<Num>(0, x.value());
  }


  // ***************************************************************************
  // * Imaginary arithmetic: Imaginary<Num>
  // ***************************************************************************

  // +Imaginary<Num>

  template <typename Num>
  inline Imaginary<Num>
    operator+(const Imaginary<Num>& x) {
    return x;
  }

  // -Imaginary<Num>

  template <typename Num>
  inline Imaginary<Num>
    operator-(const Imaginary<Num>& x) {
    Imaginary<Num> y = x;
    return y.negate();
  }


  // ***************************************************************************
  // * Imaginary arithmetic: Imaginary<NT1> OP Imaginary<NT2>
  // ***************************************************************************


  // Imaginary<NT1> + Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline Imaginary<typename AddType<NT1, NT2>::Type>
    operator+(const Imaginary<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    return Imaginary<NT3>(x1.value() + x2.value());
  }

  // Imaginary<NT1> - Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline Imaginary<typename SubType<NT1, NT2>::Type>
    operator-(const Imaginary<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    return Imaginary<NT3>(x1.value() - x2.value());
  }

  // Imaginary<NT1> * Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline
    typename MultType<NT1, NT2>::Type
    operator*(const Imaginary<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    return -NT3(x1.value() * x2.value());
  }


  // Imaginary<NT1> / Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline
    typename DivType<NT1, NT2>::Type
    operator/(const Imaginary<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    return NT3(x1.value() / x2.value());
  }






  // ***************************************************************************
  // * Imaginary-Real arithmetic:  Imaginary<NT1> OP R2
  // *                                  R1  OP Imaginary<NT2>
  // ***************************************************************************

  // Imaginary<NT1> + R2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline std::complex<typename AddType<NT1, NT2>::Type>
    operator+(const Imaginary<NT1>& xi, const NT2& xr) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(xr, xi.value());
  }

  // NT1 + Imaginary<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  inline std::complex<typename AddType<NT1, NT2>::Type>
    operator+(const NT1& xr, const Imaginary<NT2>& xi) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(xr, xi.value());
  }


  // Imaginary<NT1> - NT2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline std::complex<typename SubType<NT1, NT2>::Type>
    operator-(const Imaginary<NT1>& xi, const NT2& xr) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(-xr, xi.value());
  }

  // NT1 - Imaginary<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  inline std::complex<typename AddType<NT1, NT2>::Type>
    operator-(const NT1& xr, const Imaginary<NT2>& xi) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(xr, -xi.value());
  }


  // Imaginary<NT1> * NT2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline Imaginary<typename MultType<NT1, NT2>::Type>
    operator*(const Imaginary<NT1>& x1, const NT2& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef Imaginary<NT3> T3;
    return T3(x1.value() * x2);
  }

  // NT1 * Imaginary<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline Imaginary<typename MultType<NT1, NT2>::Type>
    operator*(const NT1& x1, const Imaginary<NT2>& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef Imaginary<NT3> T3;
    return T3(x1 * x2.value());
  }


  // Imaginary<NT1> / NT2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline Imaginary<typename DivType<NT1, NT2>::Type>
    operator/(const Imaginary<NT1>& x1, const NT2& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef Imaginary<NT3> T3;
    return T3(x1.value() / x2);
  }

  // NT1 / Imaginary<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline Imaginary<typename DivType<NT1, NT2>::Type>
    operator/(const NT1& x1, const Imaginary<NT2>& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef Imaginary<NT3> T3;
    return T3(-x1 / x2.value());
  }


  // ***************************************************************************
  // * Imaginary arithmetic:  Imaginary<NT1> OP complex<NT2>
  // *                          complex<NT1> OP Imaginary<NT2>
  // ***************************************************************************

  // Imaginary<NT1> + complex<NT2>

  template <typename NT1, typename NT2>
  inline std::complex<typename AddType<NT1, NT2>::Type>
    operator+(const Imaginary<NT1>& xi, const std::complex<NT2>& z) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(real(z), xi.value() + imag(z));
  }

  // complex<NT1> + Imaginary<NT2>
  template <typename NT1, typename NT2>
  inline std::complex<typename AddType<NT1, NT2>::Type>
    operator+(const std::complex<NT2>& z, const Imaginary<NT1>& xi) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(real(z), imag(z) + xi.value());
  }


  // Imaginary<NT1> - complex<NT2>

  template <typename NT1, typename NT2>
  inline std::complex<typename SubType<NT1, NT2>::Type>
    operator-(const Imaginary<NT1>& xi, const std::complex<NT2>& z) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(-real(z), xi.value() - imag(z));
  }

  // complex<NT1> - Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline std::complex<typename SubType<NT1, NT2>::Type>
    operator-(const std::complex<NT2>& z, const Imaginary<NT1>& xi) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(real(z), imag(z) - xi.value());
  }


  // Imaginary<NT1> * complex<NT2>

  template <typename NT1, typename NT2>
  inline std::complex<typename MultType<NT1, NT2>::Type>
    operator*(const Imaginary<NT1>& xi, const std::complex<NT2>& z) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(-xi.value() * imag(z), xi.value() * real(z));
  }


  // complex<NT2> * Imaginary<NT1>

  template <typename NT1, typename NT2>
  inline std::complex<typename MultType<NT1, NT2>::Type>
    operator*(const std::complex<NT2>& z, const Imaginary<NT1>& xi) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(-imag(z) * xi.value(), real(z) * xi.value());
  }


  // Imaginary<NT1> / complex<NT2>

  template <typename NT1, typename NT2>
  inline std::complex<typename DivType<NT1, NT2>::Type>
    operator/(const Imaginary<NT1>& xi, const std::complex<NT2>& z) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    return T3(-xi.value() * imag(z), xi.value() * real(z));
  }

  // complex<NT2> / Imaginary<NT1>

  template <typename NT1, typename NT2>
  inline std::complex<typename DivType<NT1, NT2>::Type>
    operator/(const std::complex<NT2>& z, const Imaginary<NT1>& xi) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 topR = xi.value() * imag(z);
    NT3 topI = xi.value() * real(z);
    NT3 bot = real(z) * real(z) + imag(z) * imag(z);
    return T3(topR / bot, topI / bot);
  }



  //*******************************************************
  //          Typedefs
  //*******************************************************


  typedef Imaginary<float> ImFloat;
  typedef Imaginary<double> ImDouble;
  typedef Imaginary<long double> ImLongDouble;
  typedef Imaginary<char> ImChar;
  typedef Imaginary<signed char> ImSignedChar;
  typedef Imaginary<short> ImShort;
  typedef Imaginary<int> ImInt;
  typedef Imaginary<long> ImLong;
  typedef Imaginary<long long> ImLongLong;
  typedef Imaginary<unsigned char> ImUnsignedChar;
  typedef Imaginary<unsigned short> ImUnsignedShort;
  typedef Imaginary<unsigned int> ImUnsignedInt;
  typedef Imaginary<unsigned long> ImUnsignedLong;
  typedef Imaginary<unsigned long long> ImUnsignedLongLong;



  //*******************************************************
  //          unary funcs
  //*******************************************************





  // zero

  template <typename Num, typename T >
  typename std::enable_if< std::is_same<T, Imaginary<Num>>::value, Imaginary<Num> >
    zero() {
    return Imaginary<Num>(0);
  }

  // one

  template <typename Num, typename T >
  typename std::enable_if<
    std::is_same<T, Imaginary<Num>>::value,
    Imaginary<Num>
  >
    one() {
    return Imaginary<Num>(1);
  }


  // real(z)

  template <typename Num>
  inline Num real(const Imaginary<Num>& z) {
    return 0;
  }

  // imag(z)

  template <typename Num>
  inline Num imag(const Imaginary<Num>& z) {
    return z.value();
  }

  // arg(z)  -  this is pi/2, but let the std library calculate
  //            since we don't know data type

  template <typename Num>
  inline Num arg(const Imaginary<Num>& z) {
    using std::arg;
    std::complex<Num> dummy(0, 1);
    return arg(dummy);
  }


  // proj(z)  -  the "projection of z onto the Riemann sphere"--NOT REALLY
  //
  //             For most z, std::proj(z)==z, but all complex infinities,
  //             even the numbers where one component is infinite and the
  //             other is NaN, become positive real infinity, (INFINITY, 0)
  //             or (INFINITY, -0). The sign of the imaginary (zero) component
  //             is the sign of std::imag(z).

  template <typename Num>
  inline std::complex<Num> proj(const Imaginary<Num>& z) {
    using std::proj;
    std::complex<Num> c(0, z.value());
    return proj(c);
  }


  // abs(z)

  template <typename Num>
  inline Num abs(const Imaginary<Num>& z) {
    using std::abs;
    return abs(z.value());
  }

  // normsqr(z) -

  template <typename Num>
  inline Num normsqr(const Imaginary<Num>& z) {
    return z.value() * z.value();
  }


  // conj(z)  - we go against C++  convention
  //            Note: C++ std lib returns complex number for conj(real)

  template <typename Num>
  inline Imaginary<Num>
    conj(const Imaginary<Num>& z) {
    return -z;
  }



  // complex conjugate OPERTOR ~

  template <typename Num, typename = std::enable_if_t<std::is_floating_point<Num>::value>>
  Imaginary<Num>
    operator~(const Imaginary<Num>& z) {
    return conj(z);
  }



  // polar(z)

  template <typename Num>
  inline std::complex<Num>
    polar(const Imaginary<Num>& z) {
    return std::complex(abs(z), arg(z));
  }

  // exp(z)

  template <typename Num>
  inline std::complex<Num>
    exp(const Imaginary<Num>& z) {
    const Num& val = z.value();
    return std::complex(cos(val), sin(val));
  }

  // log(z)

  template <typename Num>
  inline std::complex<Num>
    log(const Imaginary<Num>& z) {
    using std::arg;
    using std::log;
    const Num& val = z.value();
    return std::complex(log(val), arg(z));
  }


  // log10
  template <typename Num>
  std::complex<Num>
    log10(const Imaginary<Num>& z) {
    using std::log;
    const Num A0 = 1 / log(Num(10));
    return A0 * log(z);
  }


  // log2
  template <typename Num>
  std::complex<Num>
    log2(const Imaginary<Num>& z) {
    using std::log;
    const Num A0 = 1 / log(Num(2));
    return A0 * log(z);
  }


  // pow(I1,I2)
  template <typename NT1, typename NT2>
  inline std::complex<typename MultType<NT1, NT2>::Type>
    pow(const Imaginary<NT1>& x1, const Imaginary<NT2>& x2) {
    using std::pow;
    typedef typename MultType<NT1, NT2>::Type NT3;
    return pow(
      Complex(numbercast<Imaginary<NT3>>(x1)),
      Complex(numbercast<Imaginary<NT3>>(x2)));
  }


  // pow(I1,R2)
  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline std::complex<typename MultType<NT1, NT2>::Type>
    pow(const Imaginary<NT1>& x1, const NT2& x2) {
    using std::pow;
    typedef typename MultType<NT1, NT2>::Type NT3;
    return pow(
      Complex(numbercast<Imaginary<NT3>>(x1)),
      numbercast<NT3>(x2));
  }

  // pow(R1,I2)
  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  inline std::complex<typename MultType<NT1, NT2>::Type>
    pow(const NT1& x1, const Imaginary<NT2>& x2) {
    using std::pow;
    typedef typename MultType<NT1, NT2>::Type NT3;
    return pow(
      numbercast<NT3>(x1),
      Complex(numbercast<Imaginary<NT3>>(x2)));
  }


  // pow(I1,C2)
  template <typename NT1, typename NT2>
  inline std::complex<typename MultType<NT1, NT2>::Type>
    pow(const Imaginary<NT1>& x1, const std::complex<NT2>& x2) {
    using std::pow;
    typedef typename MultType<NT1, NT2>::Type NT3;
    return pow(
      Complex(numbercast<Imaginary<NT3>>(x1)),
      numbercast<std::complex<NT3>>(x2));
  }

  // pow(C1,I2)
  template <typename NT1, typename NT2>
  inline std::complex<typename MultType<NT1, NT2>::Type>
    pow(const std::complex<NT1>& x1, const Imaginary<NT2>& x2) {
    using std::pow;
    typedef typename MultType<NT1, NT2>::Type NT3;
    return pow(
      numbercast<std::complex<NT3>>(x1),
      Complex(numbercast<Imaginary<NT3>>(x2)));
  }


  // sqrt
  template <typename Num>
  std::complex<Num>
    sqrt(const Imaginary<Num>& z) {
    using std::sqrt;
    const Num A0 = sqrt(z.value() / 2);
    return A0 * std::complex<Num>(1, 1);
  }


  // sqr
  template <typename Num>
  Num sqr(const Imaginary<Num>& z) {
    return -z.value() * z.value();
  }

  // cube
  template <typename Num>
  Imaginary<Num> cube(const Imaginary<Num>& z) {
    return Imaginary<Num>(-z.value() * z.value() * z.value());
  }




  // sin
  template <typename Num>
  Imaginary<Num>
    sin(const Imaginary<Num>& z) {
    using std::sin;
    return Imaginary<Num>(sin(z.value()));
  }

  // cos
  template <typename Num>
  Num cos(const Imaginary<Num>& z) {
    using std::cos;
    return cos(z.value());
  }

  // tan
  template <typename Num>
  Imaginary<Num>
    tan(const Imaginary<Num>& z) {
    using std::tan;
    return Imaginary<Num>(tan(z.value()));
  }

  // asin
  template <typename Num>
  Imaginary<Num>
    asin(const Imaginary<Num>& z) {
    using std::asin;
    return Imaginary<Num>(asin(z.value()));
  }

  // acos
  template <typename Num>
  std::complex<Num>
    acos(const Imaginary<Num>& z) {
    using std::acos;
    return acos(Complex(z));
  }

  // atan
  template <typename Num>
  std::complex<Num>
    atan(const Imaginary<Num>& z) {
    using std::atan;
    return atan(Complex(z));
  }

  // atan2
  template <typename Num>
  std::complex<Num>
    atan2(const Imaginary<Num>& z) {
    using std::atan2;
    return atan2(z.value(), 0);
  }



  // sinh
  template <typename Num>
  Imaginary<Num>
    sinh(const Imaginary<Num>& z) {
    using std::sinh;
    return Imaginary<Num>(sinh(z.value()));
  }

  // cosh
  template <typename Num>
  Num cosh(const Imaginary<Num>& z) {
    using std::cosh;
    return cosh(z.value());
  }

  // tanh
  template <typename Num>
  Imaginary<Num>
    tanh(const Imaginary<Num>& z) {
    using std::tanh;
    return Imaginary<Num>(tanh(z.value()));
  }


  // asinh
  template <typename Num>
  std::complex<Num>
    asinh(const Imaginary<Num>& z) {
    using std::asinh;
    return asinh(Complex(z));
  }

  // acosh
  template <typename Num>
  std::complex<Num>
    acosh(const Imaginary<Num>& z) {
    using std::acosh;
    return acosh(Complex(z));
  }

  // atanh
  template <typename Num>
  std::complex<Num>
    atanh(const Imaginary<Num>& z) {
    using std::atanh;
    return atanh(Complex(z));
  }




  // imaginary rounding

  template <typename Num>
  Imaginary<Num> round(const Imaginary<Num>& x) {
    using std::round;
    return Imaginary<Num>(round(x.value()));
  }

  // Imaginary - sgn
  template <typename Num>
  Imaginary<Num> sgn(const Imaginary<Num>& z) {
    return Imaginary<Num>(sgn(z.value()));
  }

  // Imaginary - floor
  template <typename Num>
  Imaginary<Num> floor(const Imaginary<Num>& z) {
    using std::floor;
    return Imaginary<Num>(floor(z.value()));
  }

  // Imaginary - ceil
  template <typename Num>
  Imaginary<Num> ceil(const Imaginary<Num>& z) {
    using std::ceil;
    return Imaginary<Num>(ceil(z.value()));
  }



  // Imaginary - roundzero
  template <typename Num>
  Imaginary<Num> roundzero(const Imaginary<Num>& z, const Num tolerance = Functions<Num>::tolerance) {
    return Imaginary<Num>(roundzero(z.value(), tolerance));
  }

  // Imaginary - approx

  template <typename NT1, typename NT2>
  bool approx(const Imaginary<NT1>& x, const Imaginary<NT2>& y, const typename AddType<NT1, NT2>::Type tol = Functions<typename AddType<NT1, NT2>::Type>::tolerance) {
    return mathq::approx(x.value(), y.value(), tol);
  }



}; // namespace mathq


#endif
