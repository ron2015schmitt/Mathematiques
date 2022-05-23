#ifndef MATHQ__MATH_QUATERNION_H
#define MATHQ__MATH_QUATERNION_H

#include <sstream>

namespace mathq {



  // ***************************************************************************
  // *                   Quaternion Number
  // ***************************************************************************
  template <typename D>
  class Quaternion {
  private:
    D r_;
    D i_;
    D j_;
    D k_;

  public:
    Quaternion() : r_(1), i_(1), j_(1), k_(1) {
    }
    Quaternion(const D r, const D i, const D j, const D k) : r_(r), i_(i), j_(j), k_(k) {
    }

    D real() const {
      return r_;
    }

    D imag() const {
      return i_;
    }

    D jmag() const {
      return j_;
    }

    D kmag() const {
      return k_;
    }

    D scalar() const {
      return r_;
    }

    D normsqr() const {
      return r_ * r_ + i_ * i_ + j_ * j_ + k_ * k_;
    }

    D abs() const {
      return std::sqrt(this->normsqr());
    }

    Quaternion<D> normalized() const {
      Quaternion<D> y = *this;
      return y / y.abs();
    }


    D vnormsqr() const {
      return i_ * i_ + j_ * j_ + k_ * k_;
    }
    D vabs() const {
      return std::sqrt(this->vnormsqr());
    }


    D angle() const {
      return std::acos(r_ / this->abs());
    }



    Vector<D, 3> vector() const {
      Vector<D, 3>* vector = new Vector<D, 3>({ i_, j_, k_ });
      return *vector;
    }
    Vector<D, 3> unitvector() const {
      const D vnorm = this->vabs();
      Vector<D, 3>* vector = new Vector<D, 3>({ i_ / vnorm, j_ / vnorm, k_ / vnorm });
      return *vector;
    }
    std::tuple<D, D, Vector<D, 3>> polar() const {
      return std::make_tuple(this->abs(), this->angle(), this->unitvector());
    }

    Matrix<std::complex<D>, 2, 2> matrix2by2() const {
      auto A = Matrix<std::complex<D>, 2, 2>();
      A(0, 0) = std::complex<D>(r_, i_);
      A(0, 1) = std::complex<D>(j_, k_);
      A(1, 0) = std::complex<D>(-j_, k_);
      A(1, 1) = std::complex<D>(r_, -i_);
      return A;
    }


    // methods that modify *this!!

    Quaternion<D>& invert() {
      D k = 1 / this->normsqr();
      r_ = k * r_;
      i_ = -k * i_;
      j_ = -k * j_;
      k_ = -k * k_;
      return *this;
    }

    Quaternion<D>& negate() {
      r_ = -r_;
      i_ = -i_;
      j_ = -j_;
      k_ = -k_;
      return *this;
    }

    Quaternion<D>& conj() {
      r_ = r_;
      i_ = -i_;
      j_ = -j_;
      k_ = -k_;
      return *this;
    }


    Quaternion<D>& operator=(const Quaternion<D>& y) {
      r_ = y.r_;
      i_ = y.i_;
      j_ = y.j_;
      k_ = y.k_;
      return *this;
    }
    Quaternion<D>& operator=(const D& y) {
      r_ = y;
      i_ = 0;
      j_ = 0;
      k_ = 0;
      return *this;
    }
    Quaternion<D>& operator=(const Imaginary<D>& y) {
      r_ = 0;
      i_ = y.value();
      j_ = 0;
      k_ = 0;
      return *this;
    }
    Quaternion<D>& operator=(const std::complex<D>& y) {
      r_ = y.real();
      i_ = y.imag();
      j_ = 0;
      k_ = 0;
      return *this;
    }


    // arithmetic operators
    Quaternion<D>& operator+=(const Quaternion<D>& y) {
      *this = *this + y;
      return *this;
    }
    Quaternion<D>& operator+=(const D& y) {
      r_ += y;
      return *this;
    }
    Quaternion<D>& operator+=(const Imaginary<D>& y) {
      i_ += y.value();
      return *this;
    }
    Quaternion<D>& operator+=(const std::complex<D>& y) {
      *this = *this + y;
      return *this;
    }

    Quaternion<D>& operator-=(const Quaternion<D>& y) {
      *this = *this - y;
      return *this;
    }
    Quaternion<D>& operator-=(const D& y) {
      r_ -= y;
      return *this;
    }
    Quaternion<D>& operator-=(const Imaginary<D>& y) {
      i_ -= y.value();
      return *this;
    }
    Quaternion<D>& operator-=(const std::complex<D>& y) {
      *this = *this - y;
      return *this;
    }


    Quaternion<D>& operator*=(const Quaternion<D>& y) {
      *this = *this * y;
      return *this;
    }
    Quaternion<D>& operator*=(const D& y) {
      r_ *= y;
      i_ *= y;
      j_ *= y;
      k_ *= y;
      return *this;
    }
    Quaternion<D>& operator*=(const Imaginary<D>& y) {
      *this = *this * y;
      return *this;
    }
    Quaternion<D>& operator*=(const std::complex<D>& y) {
      *this = *this * y;
      return *this;
    }

    Quaternion<D>& operator/=(const Quaternion<D>& y) {
      *this = *this / y;
      return *this;
    }
    Quaternion<D>& operator/=(const D& y) {
      r_ /= y;
      i_ /= y;
      j_ /= y;
      k_ /= y;
      return *this;
    }
    Quaternion<D>& operator/=(const Imaginary<D>& y) {
      *this = *this / y;
      return *this;
    }
    Quaternion<D>& operator/=(const std::complex<D>& y) {
      *this = *this / y;
      return *this;
    }


    inline static std::string classname() {
      D d;
      return "Quaternion" + display::getBracketedTypeName(d);
    }



    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Quaternion<D>& w) {

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


    // template <class D>
    friend inline std::istream& operator>>(const std::string s, Quaternion<D>& w) {
      std::istringstream st(s);
      return (st >> w);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream, Quaternion<D>& w) {
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
    typedef typename IsQuaternion<I2>::RealType F2;
    F2 _r = numbercast<F2>(y.real());
    F2 _i = numbercast<F2>(y.imag());
    F2 _j = numbercast<F2>(y.jmag());
    F2 _k = numbercast<F2>(y.kmag());
    return Quaternion<F2>(_r, _i, _j, _k);
  }



  // ***************************************************************************
  // * Quaternion arithmetic: Quaternion<D>
  // ***************************************************************************

  // +Quaternion<D>

  template <typename D>
  inline auto
    operator+(const Quaternion<D>& x) {
    return x;
  }

  // -Quaternion<D>

  template <typename D>
  inline auto
    operator-(const Quaternion<D>& x) {
    Quaternion<D> y = x;
    return y.negate();
  }


  // ***************************************************************************
  // * Quaternion arithmetic: Quaternion<D1> OP Quaternion<D2>
  // ***************************************************************************


  // Quaternion<D1> + Quaternion<D2>

  template <typename D1, typename D2>
  inline auto
    operator+(const Quaternion<D1>& x1, const Quaternion<D2>& x2) {
    typedef typename mathq::AddType<D1, D2>::Type D3;
    return mathq::Quaternion<D3>(
      x1.real() + x2.real(),
      x1.imag() + x2.imag(),
      x1.jmag() + x2.jmag(),
      x1.kmag() + x2.kmag());
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }

  // Quaternion<D1> - Quaternion<D2>

  template <typename D1, typename D2>
  inline auto
    operator-(const Quaternion<D1>& x1, const Quaternion<D2>& x2) {
    typedef typename mathq::AddType<D1, D2>::Type D3;
    return mathq::Quaternion<D3>(
      x1.real() - x2.real(),
      x1.imag() - x2.imag(),
      x1.jmag() - x2.jmag(),
      x1.kmag() - x2.kmag());
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }

  // Quaternion<D1> * Quaternion<D2>

  template <typename D1, typename D2>
  inline auto
    operator*(const Quaternion<D1>& x1, const Quaternion<D2>& x2) {
    typedef typename mathq::AddType<D1, D2>::Type D3;
    return mathq::Quaternion<D3>(
      x1.real() * x2.real() - x1.imag() * x2.imag() - x1.jmag() * x2.jmag() - x1.kmag() * x2.kmag(),
      x1.real() * x2.imag() + x1.imag() * x2.real() + x1.jmag() * x2.kmag() - x1.kmag() * x2.jmag(),
      x1.real() * x2.jmag() - x1.imag() * x2.kmag() + x1.jmag() * x2.real() + x1.kmag() * x2.imag(),
      x1.real() * x2.kmag() + x1.imag() * x2.jmag() - x1.jmag() * x2.imag() + x1.kmag() * x2.real());
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }


  // Quaternion<D1> / Quaternion<D2>

  template <typename D1, typename D2>
  inline auto
    operator/(const Quaternion<D1>& x1, const Quaternion<D2>& x2) {
    typedef typename mathq::AddType<D1, D2>::Type D3;
    const D3 k = 1 / normsqr(x2);
    return mathq::Quaternion<D3>(
      k * (x1.real() * x2.real() + x1.imag() * x2.imag() + x1.jmag() * x2.jmag() + x1.kmag() * x2.kmag()),
      k * (-x1.real() * x2.imag() + x1.imag() * x2.real() - x1.jmag() * x2.kmag() + x1.kmag() * x2.jmag()),
      k * (-x1.real() * x2.jmag() + x1.imag() * x2.kmag() + x1.jmag() * x2.real() - x1.kmag() * x2.imag()),
      k * (-x1.real() * x2.kmag() - x1.imag() * x2.jmag() + x1.jmag() * x2.imag() + x1.kmag() * x2.real()));
    /// CAVEAT: If you have a trailing ',' in the parm list you wil get a mysterious "error: expected primary-expression before ‘(’ token"
  }






  // ***************************************************************************
  // * Quaternion-Real arithmetic:  Quaternion<D1> OP R2
  // *                                  R1  OP Quaternion<D2>
  // ***************************************************************************

  // Quaternion<D1> + D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value>>
  inline auto
    operator+(const Quaternion<D1>& x1, const D2& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    return T3(
      x1.real() + x2,
      x1.imag(),
      x1.jmag(),
      x1.kmag());
  }

  // D1 + Quaternion<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value>>
  inline auto
    operator+(const D1& x1, const Quaternion<D2>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    return T3(
      x1 + x2.real(),
      x2.imag(),
      x2.jmag(),
      x2.kmag());
  }


  // Quaternion<D1> - D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value>>
  inline auto
    operator-(const Quaternion<D1>& x1, const D2& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    return T3(
      x1.real() - x2,
      x1.imag(),
      x1.jmag(),
      x1.kmag());
  }

  // D1 - Quaternion<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value>>
  inline auto
    operator-(const D1& x1, const Quaternion<D2>& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    return T3(
      x1 - x2.real(),
      -x2.imag(),
      -x2.jmag(),
      -x2.kmag());
  }


  // Quaternion<D1> * D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value>>
  inline auto
    operator*(const Quaternion<D1>& x1, const D2& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    return T3(
      x1.real() * x2,
      x1.imag() * x2,
      x1.jmag() * x2,
      x1.kmag() * x2);
  }

  // D1 * Quaternion<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value>>
  inline auto
    operator*(const D1& x1, const Quaternion<D2>& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    return T3(
      x1 * x2.real(),
      x1 * x2.imag(),
      x1 * x2.jmag(),
      x1 * x2.kmag());
  }

  // Quaternion<D1> / D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value>>
  inline auto
    operator/(const Quaternion<D1>& x1, const D2& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    D2 k = 1 / x2;
    return x1 * k;
  }

  // D1 / Quaternion<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value>>
  inline auto
    operator/(const D1& x1, const Quaternion<D2>& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef Quaternion<D3> T3;
    return x1 * inv(x2);
  }





  // ***************************************************************************
  // * Quaternion-Imaginary arithmetic:  Quaternion<D1> OP R2
  // *                                  R1  OP Quaternion<D2>
  // ***************************************************************************

  // Quaternion<D1> + Imaginary<D2>

  template <typename D1, typename D2>
  inline auto
    operator+(const Quaternion<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x1.real(),
      x1.imag() + x2.value(),
      x1.jmag(),
      x1.kmag());
  }


  // Imaginary<D2> + Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator+(const Imaginary<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x2.real(),
      x1.value() + x2.imag(),
      x2.jmag(),
      x2.kmag());
  }


  // // Quaternion<D1> - Imaginary<D2>

  template <typename D1, typename D2>
  inline auto
    operator-(const Quaternion<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x1.real(),
      x1.imag() - x2.value(),
      x1.jmag(),
      x1.kmag());
  }


  // Imaginary<D2> - Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator-(const Imaginary<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      -x2.real(),
      x1.value() - x2.imag(),
      -x2.jmag(),
      -x2.kmag());
  }


  // Quaternion<D1> * Imaginary<D2>

  template <typename D1, typename D2>
  inline auto
    operator*(const Quaternion<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      -x1.imag() * x2.value(),
      x1.real() * x2.value(),
      x1.kmag() * x2.value(),
      -x1.jmag() * x2.value());
  }


  // Imaginary<D2> * Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator*(const Imaginary<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x1.value() * x2.imag(),
      -x1.value() * x2.real(),
      -x1.value() * x2.kmag(),
      x1.value() * x2.jmag());
  }


  // // Quaternion<D1> / Imaginary<D2>

  template <typename D1, typename D2>
  inline auto
    operator/(const Quaternion<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    const D3 k = -1 / x2.value();
    return T3(
      -x1.imag() * k,
      x1.real() * k,
      x1.kmag() * k,
      -x1.jmag() * k);
  }


  // Imaginary<D2> / Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator/(const Imaginary<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    const D3 k = -1 / x1.value();
    return T3(
      k * x2.imag(),
      -k * x2.real(),
      -k * x2.kmag(),
      k * x2.jmag());
  }





  // ***************************************************************************
  // * Quaternion arithmetic:  Quaternion<D1> OP complex<D2>
  // *                          complex<D1> OP Quaternion<D2>
  // ***************************************************************************

  // Quaternion<D1> + std::complex<D2>

  template <typename D1, typename D2>
  inline auto
    operator+(const Quaternion<D1>& x1, const std::complex<D2>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x1.real() + x2.real(),
      x1.imag() + x2.imag(),
      x1.jmag(),
      x1.kmag());
  }


  // std::complex<D2> + Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator+(const std::complex<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x1.real() + x2.real(),
      x1.imag() + x2.imag(),
      x2.jmag(),
      x2.kmag());
  }


  // // Quaternion<D1> - std::complex<D2>

  template <typename D1, typename D2>
  inline auto
    operator-(const Quaternion<D1>& x1, const std::complex<D2>& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x1.real() - x2.real(),
      x1.imag() - x2.imag(),
      x1.jmag(),
      x1.kmag());
  }


  // std::complex<D2> - Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator-(const std::complex<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return T3(
      x1.real() - x2.real(),
      x1.imag() - x2.imag(),
      -x2.jmag(),
      -x2.kmag());
  }


  // Quaternion<D1> * std::complex<D2>

  template <typename D1, typename D2>
  inline auto
    operator*(const Quaternion<D1>& x1, const std::complex<D2>& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return x1 * x2.real() + x1 * Imaginary<D2>(x2.imag());
  }


  // std::complex<D2> * Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator*(const std::complex<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return x1.real() * x2 + Imaginary<D2>(x1.imag()) * x2;
  }


  // // Quaternion<D1> / std::complex<D2>

  template <typename D1, typename D2>
  inline auto
    operator/(const Quaternion<D1>& x1, const std::complex<D2>& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return x1 / x2.real() + x1 / Imaginary<D2>(x2.imag());
  }


  // std::complex<D2> / Quaternion<D1>

  template <typename D1, typename D2>
  inline auto
    operator/(const std::complex<D2>& x1, const Quaternion<D1>& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef typename mathq::Quaternion<D3> T3;
    return x1.real() / x2 + Imaginary<D2>(x1.imag()) / x2;
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

  template <typename D>
  inline D real(const Quaternion<D>& z) {
    return z.real();
  }

  // imag(z)

  template <typename D>
  inline D imag(const Quaternion<D>& z) {
    return z.imag();
  }

  // jmag(z)

  template <typename D>
  inline D jmag(const Quaternion<D>& z) {
    return z.jmag();
  }

  // kmag(z)

  template <typename D>
  inline D kmag(const Quaternion<D>& z) {
    return z.kmag();
  }



  // abs(z)

  template <typename D>
  inline D abs(const Quaternion<D>& z) {
    return z.abs();
  }

  // normsqr(z) -

  template <typename D>
  inline D normsqr(const Quaternion<D>& z) {
    return z.normsqr();
  }


  // conj(z)  - we go against C++  convention

  template <typename D>
  inline auto conj(const Quaternion<D>& z) {
    Quaternion<D> y = z;
    return y.conj();
  }


  // inv(z)

  template <typename D>
  inline auto inv(const Quaternion<D>& z) {
    Quaternion<D> y = z;
    return y.invert();
  }

  // neg(z)

  template <typename D>
  inline Quaternion<D> neg(const Quaternion<D>& z) {
    Quaternion<D> y = z;
    return y.negate();
  }


  // complex conjugate OPERTOR ~

  template <typename D, typename = std::enable_if_t<std::is_floating_point<D>::value>>
  inline auto operator~(const Quaternion<D>& z) {
    return conj(z);
  }




  // exp(q)

  template <typename D>
  inline Quaternion<D>
    exp(const Quaternion<D>& q) {
    using std::cos;
    using std::exp;
    using std::sin;
    const D k = exp(q.scalar());
    const D vabs = q.vabs();
    return Quaternion<D>(
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

  template <typename D>
  inline Quaternion<D>
    log(const Quaternion<D>& q) {
    // using std::acos;
    using std::log, std::acos;
    const D a = q.scalar();
    const D abs = q.abs();
    const D vabs = q.vabs();
    const D k = acos(a / abs) / vabs;
    return Quaternion<D>(
      log(abs),
      k * q.imag(),
      k * q.jmag(),
      k * q.kmag());
  }


  // // log10
  // template <typename D>
  // std::complex<D>
  // log10(const Quaternion<D> &z) {
  //   using std::log;
  //   const D A0 = 1 / log(D(10));
  //   return A0 * log(z);
  // }


  // // log2
  // template <typename D>
  // std::complex<D>
  // log2(const Quaternion<D> &z) {
  //   using std::log;
  //   const D A0 = 1 / log(D(2));
  //   return A0 * log(z);
  // }


  // // pow(I1,I2)
  // template <typename D1, typename D2>
  // inline std::complex<typename MultType<D1, D2>::Type>
  // pow(const Quaternion<D1> &x1, const Quaternion<D2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<D1, D2>::Type D3;
  //   return pow(
  //       Complex(numbercast<Quaternion<D3>>(x1)),
  //       Complex(numbercast<Quaternion<D3>>(x2)));
  // }


  // pow(Q1,R2)
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value>>
  inline auto
    pow(const Quaternion<D1>& q, const D2& x) {
    using std::cos;
    using std::pow;
    using std::sin;
    typedef typename MultType<D1, D2>::Type D3;
    const D3 k = pow(q.abs(), x);
    const D3 c = 1 / q.vabs();
    const D3 nx = c * q.imag();
    const D3 ny = c * q.jmag();
    const D3 nz = c * q.kmag();
    const D3 phi = q.angle();
    return Quaternion<D1>(
      k * cos(x * phi),
      k * sin(x * phi) * nx,
      k * sin(x * phi) * ny,
      k * sin(x * phi) * nz);
  }

  // // pow(R1,I2)
  // template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value>>
  // inline std::complex<typename MultType<D1, D2>::Type>
  // pow(const D1 &x1, const Quaternion<D2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<D1, D2>::Type D3;
  //   return pow(
  //       numbercast<D3>(x1),
  //       Complex(numbercast<Quaternion<D3>>(x2)));
  // }


  // // pow(I1,C2)
  // template <typename D1, typename D2>
  // inline std::complex<typename MultType<D1, D2>::Type>
  // pow(const Quaternion<D1> &x1, const std::complex<D2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<D1, D2>::Type D3;
  //   return pow(
  //       Complex(numbercast<Quaternion<D3>>(x1)),
  //       numbercast<std::complex<D3>>(x2));
  // }

  // // pow(C1,I2)
  // template <typename D1, typename D2>
  // inline std::complex<typename MultType<D1, D2>::Type>
  // pow(const std::complex<D1> &x1, const Quaternion<D2> &x2) {
  //   using std::pow;
  //   typedef typename MultType<D1, D2>::Type D3;
  //   return pow(
  //       numbercast<std::complex<D3>>(x1),
  //       Complex(numbercast<Quaternion<D3>>(x2)));
  // }


  // // sqrt
  // template <typename D>
  // std::complex<D>
  // sqrt(const Quaternion<D> &z) {
  //   using std::sqrt;
  //   const D A0 = sqrt(z.value() / 2);
  //   return A0 * std::complex<D>(1, 1);
  // }


  // // sqr
  // template <typename D>
  // D sqr(const Quaternion<D> &z) {
  //   return -z.value() * z.value();
  // }

  // // cube
  // template <typename D>
  // Quaternion<D> cube(const Quaternion<D> &z) {
  //   return Quaternion<D>(-z.value() * z.value() * z.value());
  // }




  // // sin
  // template <typename D>
  // Quaternion<D>
  // sin(const Quaternion<D> &z) {
  //   using std::sin;
  //   return Quaternion<D>(sin(z.value()));
  // }

  // // cos
  // template <typename D>
  // D cos(const Quaternion<D> &z) {
  //   using std::cos;
  //   return cos(z.value());
  // }

  // // tan
  // template <typename D>
  // Quaternion<D>
  // tan(const Quaternion<D> &z) {
  //   using std::tan;
  //   return Quaternion<D>(tan(z.value()));
  // }

  // // asin
  // template <typename D>
  // Quaternion<D>
  // asin(const Quaternion<D> &z) {
  //   using std::asin;
  //   return Quaternion<D>(asin(z.value()));
  // }

  // // acos
  // template <typename D>
  // std::complex<D>
  // acos(const Quaternion<D> &z) {
  //   using std::acos;
  //   return acos(Complex(z));
  // }

  // // atan
  // template <typename D>
  // std::complex<D>
  // atan(const Quaternion<D> &z) {
  //   using std::atan;
  //   return atan(Complex(z));
  // }

  // // atan2
  // template <typename D>
  // std::complex<D>
  // atan2(const Quaternion<D> &z) {
  //   using std::atan2;
  //   return atan2(z.value(), 0);
  // }



  // // sinh
  // template <typename D>
  // Quaternion<D>
  // sinh(const Quaternion<D> &z) {
  //   using std::sinh;
  //   return Quaternion<D>(sinh(z.value()));
  // }

  // // cosh
  // template <typename D>
  // D cosh(const Quaternion<D> &z) {
  //   using std::cosh;
  //   return cosh(z.value());
  // }

  // // tanh
  // template <typename D>
  // Quaternion<D>
  // tanh(const Quaternion<D> &z) {
  //   using std::tanh;
  //   return Quaternion<D>(tanh(z.value()));
  // }


  // // asinh
  // template <typename D>
  // std::complex<D>
  // asinh(const Quaternion<D> &z) {
  //   using std::asinh;
  //   return asinh(Complex(z));
  // }

  // // acosh
  // template <typename D>
  // std::complex<D>
  // acosh(const Quaternion<D> &z) {
  //   using std::acosh;
  //   return acosh(Complex(z));
  // }

  // // atanh
  // template <typename D>
  // std::complex<D>
  // atanh(const Quaternion<D> &z) {
  //   using std::atanh;
  //   return atanh(Complex(z));
  // }




  // // imaginary rounding

  // template <typename D>
  // Quaternion<D> round(const Quaternion<D> &x) {
  //   using std::round;
  //   return Quaternion<D>(round(x.value()));
  // }

  // // Quaternion - sgn
  // template <typename D>
  // Quaternion<D> sgn(const Quaternion<D> &z) {
  //   return Quaternion<D>(sgn(z.value()));
  // }

  // // Quaternion - floor
  // template <typename D>
  // Quaternion<D> floor(const Quaternion<D> &z) {
  //   using std::floor;
  //   return Quaternion<D>(floor(z.value()));
  // }

  // // Quaternion - ceil
  // template <typename D>
  // Quaternion<D> ceil(const Quaternion<D> &z) {
  //   using std::ceil;
  //   return Quaternion<D>(ceil(z.value()));
  // }



  // // Quaternion - roundzero
  // template <typename D>
  // Quaternion<D> roundzero(const Quaternion<D> &z, const D tolerance = Functions<D>::tolerance) {
  //   return Quaternion<D>(roundzero(z.value(), tolerance));
  // }

  // // Quaternion - approx

  // template <typename D1, typename D2>
  // bool approx(const Quaternion<D1> &x, const Quaternion<D2> &y, const typename AddType<D1, D2>::Type tol = Functions<typename AddType<D1, D2>::Type>::tolerance) {
  //   return mathq::approx(x.value(), y.value(), tol);
  // }



}; // namespace mathq


#endif
