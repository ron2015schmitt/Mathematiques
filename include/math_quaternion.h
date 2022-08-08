#ifndef MATHQ__MATH_QUATERNION
#define MATHQ__MATH_QUATERNION

#include <sstream>

namespace mathq {



  // ***************************************************************************
  // *                   Quaternion Number
  // ***************************************************************************
  template <typename Number>
  class Quaternion {
  private:
    Number r_;
    Number i_;
    Number j_;
    Number k_;

  public:
    Quaternion() : r_(1), i_(1), j_(1), k_(1) {
    }
    Quaternion(const Number r, const Number i, const Number j, const Number k) : r_(r), i_(i), j_(j), k_(k) {
    }

    Number real() const {
      return r_;
    }

    Number imag() const {
      return i_;
    }

    Number jmag() const {
      return j_;
    }

    Number kmag() const {
      return k_;
    }

    Number scalar() const {
      return r_;
    }

    Number normsqr() const {
      return r_ * r_ + i_ * i_ + j_ * j_ + k_ * k_;
    }

    Number abs() const {
      return std::sqrt(this->normsqr());
    }

    Quaternion<Number> normalized() const {
      Quaternion<Number> y = *this;
      return y / y.abs();
    }


    Number vnormsqr() const {
      return i_ * i_ + j_ * j_ + k_ * k_;
    }
    Number vabs() const {
      return std::sqrt(this->vnormsqr());
    }


    Number angle() const {
      return std::acos(r_ / this->abs());
    }



    Vector<Number, 3> vector() const {
      Vector<Number, 3>* vector = new Vector<Number, 3>({ i_, j_, k_ });
      return *vector;
    }
    Vector<Number, 3> unitvector() const {
      const Number vnorm = this->vabs();
      Vector<Number, 3>* vector = new Vector<Number, 3>({ i_ / vnorm, j_ / vnorm, k_ / vnorm });
      return *vector;
    }
    std::tuple<Number, Number, Vector<Number, 3>> polar() const {
      return std::make_tuple(this->abs(), this->angle(), this->unitvector());
    }

    Matrix<std::complex<Number>, 2, 2> matrix2by2() const {
      auto A = Matrix<std::complex<Number>, 2, 2>();
      A(0, 0) = std::complex<Number>(r_, i_);
      A(0, 1) = std::complex<Number>(j_, k_);
      A(1, 0) = std::complex<Number>(-j_, k_);
      A(1, 1) = std::complex<Number>(r_, -i_);
      return A;
    }


    // methods that modify *this!!

    Quaternion<Number>& invert() {
      Number k = 1 / this->normsqr();
      r_ = k * r_;
      i_ = -k * i_;
      j_ = -k * j_;
      k_ = -k * k_;
      return *this;
    }

    Quaternion<Number>& negate() {
      r_ = -r_;
      i_ = -i_;
      j_ = -j_;
      k_ = -k_;
      return *this;
    }

    Quaternion<Number>& conj() {
      r_ = r_;
      i_ = -i_;
      j_ = -j_;
      k_ = -k_;
      return *this;
    }


    Quaternion<Number>& operator=(const Quaternion<Number>& y) {
      r_ = y.r_;
      i_ = y.i_;
      j_ = y.j_;
      k_ = y.k_;
      return *this;
    }
    Quaternion<Number>& operator=(const Number& y) {
      r_ = y;
      i_ = 0;
      j_ = 0;
      k_ = 0;
      return *this;
    }
    Quaternion<Number>& operator=(const Imaginary<Number>& y) {
      r_ = 0;
      i_ = y.value();
      j_ = 0;
      k_ = 0;
      return *this;
    }
    Quaternion<Number>& operator=(const std::complex<Number>& y) {
      r_ = y.real();
      i_ = y.imag();
      j_ = 0;
      k_ = 0;
      return *this;
    }


    // arithmetic operators
    Quaternion<Number>& operator+=(const Quaternion<Number>& y) {
      *this = *this + y;
      return *this;
    }
    Quaternion<Number>& operator+=(const Number& y) {
      r_ += y;
      return *this;
    }
    Quaternion<Number>& operator+=(const Imaginary<Number>& y) {
      i_ += y.value();
      return *this;
    }
    Quaternion<Number>& operator+=(const std::complex<Number>& y) {
      *this = *this + y;
      return *this;
    }

    Quaternion<Number>& operator-=(const Quaternion<Number>& y) {
      *this = *this - y;
      return *this;
    }
    Quaternion<Number>& operator-=(const Number& y) {
      r_ -= y;
      return *this;
    }
    Quaternion<Number>& operator-=(const Imaginary<Number>& y) {
      i_ -= y.value();
      return *this;
    }
    Quaternion<Number>& operator-=(const std::complex<Number>& y) {
      *this = *this - y;
      return *this;
    }


    Quaternion<Number>& operator*=(const Quaternion<Number>& y) {
      *this = *this * y;
      return *this;
    }
    Quaternion<Number>& operator*=(const Number& y) {
      r_ *= y;
      i_ *= y;
      j_ *= y;
      k_ *= y;
      return *this;
    }
    Quaternion<Number>& operator*=(const Imaginary<Number>& y) {
      *this = *this * y;
      return *this;
    }
    Quaternion<Number>& operator*=(const std::complex<Number>& y) {
      *this = *this * y;
      return *this;
    }

    Quaternion<Number>& operator/=(const Quaternion<Number>& y) {
      *this = *this / y;
      return *this;
    }
    Quaternion<Number>& operator/=(const Number& y) {
      r_ /= y;
      i_ /= y;
      j_ /= y;
      k_ /= y;
      return *this;
    }
    Quaternion<Number>& operator/=(const Imaginary<Number>& y) {
      *this = *this / y;
      return *this;
    }
    Quaternion<Number>& operator/=(const std::complex<Number>& y) {
      *this = *this / y;
      return *this;
    }


    inline static std::string classname() {
      Number d;
      return "Quaternion" + display::bracketAndStyleTypename(d);
    }



    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Quaternion<Number>& w) {

      /// TODO: create style for the i,j,k

      using namespace display;
      std::stringstream ss;

      if ((w.real() == 0) && (w.imag() == 0) && (w.jmag() == 0) && (w.kmag() == 0)) {
        stream << "0";
        return stream;
      }

      bool first = true;
      if (w.real() != 0) {
        first = false;
        dispval_strm(stream, w.real());
      }

      if (w.imag() != 0) {
        if (!first) {
          stream << " + ";
        }
        first = false;
        if (w.imag() != 1) {
          if (w.imag() == -1) {
            stream << "-";
          }
          else {
            dispval_strm(stream, w.imag());
            stream << "*";
          }
        }
        stream << "i";
      }

      if (w.jmag() != 0) {
        if (!first) {
          stream << " + ";
        }
        first = false;
        if (w.jmag() != 1) {
          if (w.jmag() == -1) {
            stream << "-";
          }
          else {
            dispval_strm(stream, w.jmag());
            stream << "*";
          }
        }
        stream << "j";
      }

      if (w.kmag() != 0) {
        if (!first) {
          stream << " + ";
        }
        first = false;
        if (w.kmag() != 1) {
          if (w.kmag() == -1) {
            stream << "-";
          }
          else {
            dispval_strm(stream, w.kmag());
            stream << "*";
          }
        }
        stream << "k";
      }

      return stream;
    }


    // template <typename Number>
    friend inline std::istream& operator>>(const std::string s, Quaternion<Number>& w) {
      std::istringstream st(s);
      return (st >> w);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream, Quaternion<Number>& w) {
      return stream;
    }
  };


  // ***************************************************************************
  // * j: the unit imaginary j
  // * k: the unit imaginary k
  // ***************************************************************************


  namespace unit_quaternion {
    const Quaternion<float> jF(0, 0, 1, 0);
    const Quaternion<double> j(0, 0, 1, 0);
    const Quaternion<long double> jL(0, 0, 1, 0);

    const Quaternion<float> kF(0, 0, 0, 1);
    const Quaternion<double> k(0, 0, 0, 1);
    const Quaternion<long double> kL(0, 0, 0, 1);
  }; // namespace unit_quaternion



  // ***************************************************************************
  // numbercast
  // ***************************************************************************


  template <typename I2, typename F1>
  EnableMethodIf<IsQuaternion<I2>::value, I2>
    numbercast(const Quaternion<F1>& y) {
    typedef typename IsQuaternion<I2>::OrderedNumberType F2;
    F2 _r = numbercast<F2>(y.real());
    F2 _i = numbercast<F2>(y.imag());
    F2 _j = numbercast<F2>(y.jmag());
    F2 _k = numbercast<F2>(y.kmag());
    return Quaternion<F2>(_r, _i, _j, _k);
  }



  // ***************************************************************************
  // * Quaternion arithmetic: Quaternion<Number>
  // ***************************************************************************

  // +Quaternion<Number>

  template <typename Number>
  inline auto
    operator+(const Quaternion<Number>& x) {
    return x;
  }

  // -Quaternion<Number>

  template <typename Number>
  inline auto
    operator-(const Quaternion<Number>& x) {
    Quaternion<Number> y = x;
    return y.negate();
  }


  // ***************************************************************************
  // * Quaternion arithmetic: Quaternion<NT1> OP Quaternion<NT2>
  // ***************************************************************************


  // Quaternion<NT1> + Quaternion<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator+(const Quaternion<NT1>& x1, const Quaternion<NT2>& x2) {
    typedef typename mathq::AddType<NT1, NT2>::Type NT3;
    return mathq::Quaternion<NT3>(
      x1.real() + x2.real(),
      x1.imag() + x2.imag(),
      x1.jmag() + x2.jmag(),
      x1.kmag() + x2.kmag());
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }

  // Quaternion<NT1> - Quaternion<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator-(const Quaternion<NT1>& x1, const Quaternion<NT2>& x2) {
    typedef typename mathq::AddType<NT1, NT2>::Type NT3;
    return mathq::Quaternion<NT3>(
      x1.real() - x2.real(),
      x1.imag() - x2.imag(),
      x1.jmag() - x2.jmag(),
      x1.kmag() - x2.kmag());
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }

  // Quaternion<NT1> * Quaternion<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator*(const Quaternion<NT1>& x1, const Quaternion<NT2>& x2) {
    typedef typename mathq::AddType<NT1, NT2>::Type NT3;
    return mathq::Quaternion<NT3>(
      x1.real() * x2.real() - x1.imag() * x2.imag() - x1.jmag() * x2.jmag() - x1.kmag() * x2.kmag(),
      x1.real() * x2.imag() + x1.imag() * x2.real() + x1.jmag() * x2.kmag() - x1.kmag() * x2.jmag(),
      x1.real() * x2.jmag() - x1.imag() * x2.kmag() + x1.jmag() * x2.real() + x1.kmag() * x2.imag(),
      x1.real() * x2.kmag() + x1.imag() * x2.jmag() - x1.jmag() * x2.imag() + x1.kmag() * x2.real());
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }


  // Quaternion<NT1> / Quaternion<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator/(const Quaternion<NT1>& x1, const Quaternion<NT2>& x2) {
    typedef typename mathq::AddType<NT1, NT2>::Type NT3;
    const NT3 k = 1 / normsqr(x2);
    return mathq::Quaternion<NT3>(
      k * (x1.real() * x2.real() + x1.imag() * x2.imag() + x1.jmag() * x2.jmag() + x1.kmag() * x2.kmag()),
      k * (-x1.real() * x2.imag() + x1.imag() * x2.real() - x1.jmag() * x2.kmag() + x1.kmag() * x2.jmag()),
      k * (-x1.real() * x2.jmag() + x1.imag() * x2.kmag() + x1.jmag() * x2.real() - x1.kmag() * x2.imag()),
      k * (-x1.real() * x2.kmag() - x1.imag() * x2.jmag() + x1.jmag() * x2.imag() + x1.kmag() * x2.real()));
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }






  // ***************************************************************************
  // * Quaternion-Real arithmetic:  Quaternion<NT1> OP R2
  // *                                  R1  OP Quaternion<NT2>
  // ***************************************************************************

  // Quaternion<NT1> + NT2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline auto
    operator+(const Quaternion<NT1>& x1, const NT2& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    return T3(
      x1.real() + x2,
      x1.imag(),
      x1.jmag(),
      x1.kmag());
  }

  // NT1 + Quaternion<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  inline auto
    operator+(const NT1& x1, const Quaternion<NT2>& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    return T3(
      x1 + x2.real(),
      x2.imag(),
      x2.jmag(),
      x2.kmag());
  }


  // Quaternion<NT1> - NT2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline auto
    operator-(const Quaternion<NT1>& x1, const NT2& x2) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    return T3(
      x1.real() - x2,
      x1.imag(),
      x1.jmag(),
      x1.kmag());
  }

  // NT1 - Quaternion<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  inline auto
    operator-(const NT1& x1, const Quaternion<NT2>& x2) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    return T3(
      x1 - x2.real(),
      -x2.imag(),
      -x2.jmag(),
      -x2.kmag());
  }


  // Quaternion<NT1> * NT2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline auto
    operator*(const Quaternion<NT1>& x1, const NT2& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    return T3(
      x1.real() * x2,
      x1.imag() * x2,
      x1.jmag() * x2,
      x1.kmag() * x2);
  }

  // NT1 * Quaternion<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  inline auto
    operator*(const NT1& x1, const Quaternion<NT2>& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    return T3(
      x1 * x2.real(),
      x1 * x2.imag(),
      x1 * x2.jmag(),
      x1 * x2.kmag());
  }

  // Quaternion<NT1> / NT2

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline auto
    operator/(const Quaternion<NT1>& x1, const NT2& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    NT2 k = 1 / x2;
    return x1 * k;
  }

  // NT1 / Quaternion<NT2>

  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  inline auto
    operator/(const NT1& x1, const Quaternion<NT2>& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef Quaternion<NT3> T3;
    return x1 * inv(x2);
  }





  // ***************************************************************************
  // * Quaternion-Imaginary arithmetic:  Quaternion<NT1> OP R2
  // *                                  R1  OP Quaternion<NT2>
  // ***************************************************************************

  // Quaternion<NT1> + Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator+(const Quaternion<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x1.real(),
      x1.imag() + x2.value(),
      x1.jmag(),
      x1.kmag());
  }


  // Imaginary<NT2> + Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator+(const Imaginary<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x2.real(),
      x1.value() + x2.imag(),
      x2.jmag(),
      x2.kmag());
  }


  // // Quaternion<NT1> - Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator-(const Quaternion<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x1.real(),
      x1.imag() - x2.value(),
      x1.jmag(),
      x1.kmag());
  }


  // Imaginary<NT2> - Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator-(const Imaginary<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      -x2.real(),
      x1.value() - x2.imag(),
      -x2.jmag(),
      -x2.kmag());
  }


  // Quaternion<NT1> * Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator*(const Quaternion<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      -x1.imag() * x2.value(),
      x1.real() * x2.value(),
      x1.kmag() * x2.value(),
      -x1.jmag() * x2.value());
  }


  // Imaginary<NT2> * Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator*(const Imaginary<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x1.value() * x2.imag(),
      -x1.value() * x2.real(),
      -x1.value() * x2.kmag(),
      x1.value() * x2.jmag());
  }


  // // Quaternion<NT1> / Imaginary<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator/(const Quaternion<NT1>& x1, const Imaginary<NT2>& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    const NT3 k = -1 / x2.value();
    return T3(
      -x1.imag() * k,
      x1.real() * k,
      x1.kmag() * k,
      -x1.jmag() * k);
  }


  // Imaginary<NT2> / Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator/(const Imaginary<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    const NT3 k = -1 / x1.value();
    return T3(
      k * x2.imag(),
      -k * x2.real(),
      -k * x2.kmag(),
      k * x2.jmag());
  }





  // ***************************************************************************
  // * Quaternion arithmetic:  Quaternion<NT1> OP complex<NT2>
  // *                          complex<NT1> OP Quaternion<NT2>
  // ***************************************************************************

  // Quaternion<NT1> + std::complex<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator+(const Quaternion<NT1>& x1, const std::complex<NT2>& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x1.real() + x2.real(),
      x1.imag() + x2.imag(),
      x1.jmag(),
      x1.kmag());
  }


  // std::complex<NT2> + Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator+(const std::complex<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x1.real() + x2.real(),
      x1.imag() + x2.imag(),
      x2.jmag(),
      x2.kmag());
  }


  // // Quaternion<NT1> - std::complex<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator-(const Quaternion<NT1>& x1, const std::complex<NT2>& x2) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x1.real() - x2.real(),
      x1.imag() - x2.imag(),
      x1.jmag(),
      x1.kmag());
  }


  // std::complex<NT2> - Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator-(const std::complex<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return T3(
      x1.real() - x2.real(),
      x1.imag() - x2.imag(),
      -x2.jmag(),
      -x2.kmag());
  }


  // Quaternion<NT1> * std::complex<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator*(const Quaternion<NT1>& x1, const std::complex<NT2>& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return x1 * x2.real() + x1 * Imaginary<NT2>(x2.imag());
  }


  // std::complex<NT2> * Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator*(const std::complex<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return x1.real() * x2 + Imaginary<NT2>(x1.imag()) * x2;
  }


  // // Quaternion<NT1> / std::complex<NT2>

  template <typename NT1, typename NT2>
  inline auto
    operator/(const Quaternion<NT1>& x1, const std::complex<NT2>& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return x1 / x2.real() + x1 / Imaginary<NT2>(x2.imag());
  }


  // std::complex<NT2> / Quaternion<NT1>

  template <typename NT1, typename NT2>
  inline auto
    operator/(const std::complex<NT2>& x1, const Quaternion<NT1>& x2) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename mathq::Quaternion<NT3> T3;
    return x1.real() / x2 + Imaginary<NT2>(x1.imag()) / x2;
  }



  // //*******************************************************
  // //          Typedefs
  // //*******************************************************


  // typedef Quaternion<float> ImFloat;
  // typedef Quaternion<double> ImDouble;
  // typedef Quaternion<long double> ImLongDouble;
  // typedef Quaternion<char> ImChar;
  // typedef Quaternion<signed char> ImSignedChar;
  // typedef Quaternion<short> ImShort;
  // typedef Quaternion<int> ImInt;
  // typedef Quaternion<long> ImLong;
  // typedef Quaternion<long long> ImLongLong;
  // typedef Quaternion<unsigned char> ImUnsignedChar;
  // typedef Quaternion<unsigned short> ImUnsignedShort;
  // typedef Quaternion<unsigned int> ImUnsignedInt;
  // typedef Quaternion<unsigned long> ImUnsignedLong;
  // typedef Quaternion<unsigned long long> ImUnsignedLongLong;



  //*******************************************************
  //          unary funcs
  //*******************************************************

  // real(z)

  template <typename Number>
  inline Number real(const Quaternion<Number>& z) {
    return z.real();
  }

  // imag(z)

  template <typename Number>
  inline Number imag(const Quaternion<Number>& z) {
    return z.imag();
  }

  // jmag(z)

  template <typename Number>
  inline Number jmag(const Quaternion<Number>& z) {
    return z.jmag();
  }

  // kmag(z)

  template <typename Number>
  inline Number kmag(const Quaternion<Number>& z) {
    return z.kmag();
  }



  // abs(z)

  template <typename Number>
  inline Number abs(const Quaternion<Number>& z) {
    return z.abs();
  }

  // normsqr(z) -

  template <typename Number>
  inline Number normsqr(const Quaternion<Number>& z) {
    return z.normsqr();
  }


  // conj(z)  - we go against C++  convention

  template <typename Number>
  inline auto conj(const Quaternion<Number>& z) {
    Quaternion<Number> y = z;
    return y.conj();
  }


  // inv(z)

  template <typename Number>
  inline auto inv(const Quaternion<Number>& z) {
    Quaternion<Number> y = z;
    return y.invert();
  }

  // neg(z)

  template <typename Number>
  inline Quaternion<Number> neg(const Quaternion<Number>& z) {
    Quaternion<Number> y = z;
    return y.negate();
  }


  // complex conjugate OPERTOR ~

  template <typename Number, typename = std::enable_if_t<std::is_floating_point<Number>::value>>
  inline auto operator~(const Quaternion<Number>& z) {
    return conj(z);
  }




  // exp(q)

  template <typename Number>
  inline Quaternion<Number>
    exp(const Quaternion<Number>& q) {
    using std::cos;
    using std::exp;
    using std::sin;
    const Number k = exp(q.scalar());
    const Number vabs = q.vabs();
    return Quaternion<Number>(
      k * cos(vabs),
      k * sin(vabs) * q.imag() / vabs,
      k * sin(vabs) * q.jmag() / vabs,
      k * sin(vabs) * q.kmag() / vabs);
  }

  // log(q)
  //
  //  note that similar to log of a complex number, log of a quaternion is a multivalued function
  //  This function returns the principal value.  Notice that you will get unexpected results for
  //  real values (ie v=0): the vector part is NaN
  //
  // exp(log(q)) = q always provided v != 0
  // log(exp(q)) = q sometimes
  //
  // We could improve the answer for the v=0 case via
  // https://math.stackexchange.com/questions/2527630/logarithm-and-exponent-of-real-quaternions

  template <typename Number>
  inline Quaternion<Number>
    log(const Quaternion<Number>& q) {
    // using std::acos;
    using std::log, std::acos;
    const Number a = q.scalar();
    const Number abs = q.abs();
    const Number vabs = q.vabs();
    const Number k = acos(a / abs) / vabs;
    return Quaternion<Number>(
      log(abs),
      k * q.imag(),
      k * q.jmag(),
      k * q.kmag());
  }


  // // log10
  // template <typename Number>
  // std::complex<Number>
  // log10(const Quaternion<Number> &z) {
  //   using std::log;
  //   const Number A0 = 1 / log(Number(10));
  //   return A0 * log(z);
  // }


  // // log2
  // template <typename Number>
  // std::complex<Number>
  // log2(const Quaternion<Number> &z) {
  //   using std::log;
  //   const Number A0 = 1 / log(Number(2));
  //   return A0 * log(z);
  // }


  // // pow(I1,I2)
  // template <typename NT1, typename NT2>
  // inline std::complex<typename MultType<NT1, NT2>::Type>
  // pow(const Quaternion<NT1> &x1, const Quaternion<NT2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<NT1, NT2>::Type NT3;
  //   return pow(
  //       Complex(numbercast<Quaternion<NT3>>(x1)),
  //       Complex(numbercast<Quaternion<NT3>>(x2)));
  // }


  // pow(Q1,R2)
  template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT2>::value>>
  inline auto
    pow(const Quaternion<NT1>& q, const NT2& x) {
    using std::cos;
    using std::pow;
    using std::sin;
    typedef typename MultType<NT1, NT2>::Type NT3;
    const NT3 k = pow(q.abs(), x);
    const NT3 c = 1 / q.vabs();
    const NT3 nx = c * q.imag();
    const NT3 ny = c * q.jmag();
    const NT3 nz = c * q.kmag();
    const NT3 phi = q.angle();
    return Quaternion<NT1>(
      k * cos(x * phi),
      k * sin(x * phi) * nx,
      k * sin(x * phi) * ny,
      k * sin(x * phi) * nz);
  }

  // // pow(R1,I2)
  // template <typename NT1, typename NT2, typename = std::enable_if_t<std::is_arithmetic<NT1>::value>>
  // inline std::complex<typename MultType<NT1, NT2>::Type>
  // pow(const NT1 &x1, const Quaternion<NT2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<NT1, NT2>::Type NT3;
  //   return pow(
  //       numbercast<NT3>(x1),
  //       Complex(numbercast<Quaternion<NT3>>(x2)));
  // }


  // // pow(I1,C2)
  // template <typename NT1, typename NT2>
  // inline std::complex<typename MultType<NT1, NT2>::Type>
  // pow(const Quaternion<NT1> &x1, const std::complex<NT2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<NT1, NT2>::Type NT3;
  //   return pow(
  //       Complex(numbercast<Quaternion<NT3>>(x1)),
  //       numbercast<std::complex<NT3>>(x2));
  // }

  // // pow(C1,I2)
  // template <typename NT1, typename NT2>
  // inline std::complex<typename MultType<NT1, NT2>::Type>
  // pow(const std::complex<NT1> &x1, const Quaternion<NT2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<NT1, NT2>::Type NT3;
  //   return pow(
  //       numbercast<std::complex<NT3>>(x1),
  //       Complex(numbercast<Quaternion<NT3>>(x2)));
  // }


  // // sqrt
  // template <typename Number>
  // std::complex<Number>
  // sqrt(const Quaternion<Number> &z) {
  //   using std::sqrt;
  //   const Number A0 = sqrt(z.value() / 2);
  //   return A0 * std::complex<Number>(1, 1);
  // }


  // // sqr
  // template <typename Number>
  // Number sqr(const Quaternion<Number> &z) {
  //   return -z.value() * z.value();
  // }

  // // cube
  // template <typename Number>
  // Quaternion<Number> cube(const Quaternion<Number> &z) {
  //   return Quaternion<Number>(-z.value() * z.value() * z.value());
  // }




  // // sin
  // template <typename Number>
  // Quaternion<Number>
  // sin(const Quaternion<Number> &z) {
  //   using std::sin;
  //   return Quaternion<Number>(sin(z.value()));
  // }

  // // cos
  // template <typename Number>
  // Number cos(const Quaternion<Number> &z) {
  //   using std::cos;
  //   return cos(z.value());
  // }

  // // tan
  // template <typename Number>
  // Quaternion<Number>
  // tan(const Quaternion<Number> &z) {
  //   using std::tan;
  //   return Quaternion<Number>(tan(z.value()));
  // }

  // // asin
  // template <typename Number>
  // Quaternion<Number>
  // asin(const Quaternion<Number> &z) {
  //   using std::asin;
  //   return Quaternion<Number>(asin(z.value()));
  // }

  // // acos
  // template <typename Number>
  // std::complex<Number>
  // acos(const Quaternion<Number> &z) {
  //   using std::acos;
  //   return acos(Complex(z));
  // }

  // // atan
  // template <typename Number>
  // std::complex<Number>
  // atan(const Quaternion<Number> &z) {
  //   using std::atan;
  //   return atan(Complex(z));
  // }

  // // atan2
  // template <typename Number>
  // std::complex<Number>
  // atan2(const Quaternion<Number> &z) {
  //   using std::atan2;
  //   return atan2(z.value(), 0);
  // }



  // // sinh
  // template <typename Number>
  // Quaternion<Number>
  // sinh(const Quaternion<Number> &z) {
  //   using std::sinh;
  //   return Quaternion<Number>(sinh(z.value()));
  // }

  // // cosh
  // template <typename Number>
  // Number cosh(const Quaternion<Number> &z) {
  //   using std::cosh;
  //   return cosh(z.value());
  // }

  // // tanh
  // template <typename Number>
  // Quaternion<Number>
  // tanh(const Quaternion<Number> &z) {
  //   using std::tanh;
  //   return Quaternion<Number>(tanh(z.value()));
  // }


  // // asinh
  // template <typename Number>
  // std::complex<Number>
  // asinh(const Quaternion<Number> &z) {
  //   using std::asinh;
  //   return asinh(Complex(z));
  // }

  // // acosh
  // template <typename Number>
  // std::complex<Number>
  // acosh(const Quaternion<Number> &z) {
  //   using std::acosh;
  //   return acosh(Complex(z));
  // }

  // // atanh
  // template <typename Number>
  // std::complex<Number>
  // atanh(const Quaternion<Number> &z) {
  //   using std::atanh;
  //   return atanh(Complex(z));
  // }




  // // imaginary rounding

  // template <typename Number>
  // Quaternion<Number> round(const Quaternion<Number> &x) {
  //   using std::round;
  //   return Quaternion<Number>(round(x.value()));
  // }

  // // Quaternion - sgn
  // template <typename Number>
  // Quaternion<Number> sgn(const Quaternion<Number> &z) {
  //   return Quaternion<Number>(sgn(z.value()));
  // }

  // // Quaternion - floor
  // template <typename Number>
  // Quaternion<Number> floor(const Quaternion<Number> &z) {
  //   using std::floor;
  //   return Quaternion<Number>(floor(z.value()));
  // }

  // // Quaternion - ceil
  // template <typename Number>
  // Quaternion<Number> ceil(const Quaternion<Number> &z) {
  //   using std::ceil;
  //   return Quaternion<Number>(ceil(z.value()));
  // }



  // // Quaternion - roundzero
  // template <typename Number>
  // Quaternion<Number> roundzero(const Quaternion<Number> &z, const Number tolerance = Functions<Number>::tolerance) {
  //   return Quaternion<Number>(roundzero(z.value(), tolerance));
  // }

  // // Quaternion - approx

  // template <typename NT1, typename NT2>
  // bool approx(const Quaternion<NT1> &x, const Quaternion<NT2> &y, const typename AddType<NT1, NT2>::Type tol = Functions<typename AddType<NT1, NT2>::Type>::tolerance) {
  //   return mathq::approx(x.value(), y.value(), tol);
  // }



}; // namespace mathq


#endif
