#ifndef MATHQ__MATH_CPLX_H
#define MATHQ__MATH_CPLX_H


namespace mathq {






  // ***************************************************************************
  // *                   COMPLEX MATH LIBRARY
  // ***************************************************************************

  //*******************************************************
  //          Typedefs
  //*******************************************************


  typedef std::complex<float> ComplexFloat;
  typedef std::complex<double> ComplexDouble;
  typedef std::complex<long double> ComplexLongDouble;
  typedef std::complex<char> ComplexChar;
  typedef std::complex<signed char> ComplexSignedChar;
  typedef std::complex<short> ComplexShort;
  typedef std::complex<int> ComplexInt;
  typedef std::complex<long> ComplexLong;
  typedef std::complex<long long> ComplexLongLong;
  typedef std::complex<unsigned char> ComplexUnsignedChar;
  typedef std::complex<unsigned short> ComplexUnsignedShort;
  typedef std::complex<unsigned int> ComplexUnsignedInt;
  typedef std::complex<unsigned long> ComplexUnsignedLong;
  typedef std::complex<unsigned long long> ComplexUnsignedLongLong;




  //*******************************************************
  //          Type-related functions and classes
  //*******************************************************



  // is_complex - text is an object is complex type (false)
  template<class T> struct is_complex : std::false_type {};

  // std::complex class (true)
  template<class D> struct is_complex<std::complex<D>> : std::true_type {};

  // T<std::complex> (true)  container holding complex
  template<template<typename> class T, class D> struct is_complex<T<std::complex<D> > > : std::true_type {};


  // template <typename T> class
  //   Complexify {
  // public:
  //   typedef typename FundamentalType<T>::Type FType;
  //   typedef std::complex<FType> CType;
  //   typedef typename NumberType<T,CType>::ReplaceTypeE Type;
  // };
  // template <typename E, typename A, typename D, int M, int R> class
  //   Complexify<TensorR<E,A,D,M,R> > {
  // public:
  //   typedef TensorR<typename Complexify<E>::Type,A,typename Complexify<D>::Type, M,R> Type;
  // };


  // template <typename T> class
  //   Realify {
  // public:
  //   typedef typename FundamentalType<T>::Type FType;
  //   typedef typename NumberType<T,FType>::ReplaceTypeE Type;
  // };
  // template <typename E, typename A, typename D, int M, int R> class
  //   Realify<TensorR<E,A,D,M,R> > {
  // public:
  //   typedef TensorR<typename Realify<E>::Type,A,typename Realify<D>::Type,M,R> Type;
  // };



  // template <typename T> class
  //   Imaginarify {
  // public:
  //   typedef typename FundamentalType<T>::Type FType;
  //   typedef Imaginary<FType> IType;
  //   typedef typename NumberType<T,IType>::ReplaceTypeE Type;
  // };
  // template <typename E, typename A, typename D, int M, int R> class
  //   Imaginarify<TensorR<E,A,D,M,R> > {
  // public:
  //   typedef TensorR<typename Imaginarify<E>::Type,A,typename Imaginarify<D>::Type, M,R> Type;
  // };




  // numbercast


  template <typename C2, typename F1> EnableMethodIf<IsComplex<C2>::value, C2>
  numbercast(const std::complex<F1>& x) {
    typedef typename IsComplex<C2>::RealType F2;
    F2 re = numbercast<F2>(real(x));
    F2 im = numbercast<F2>(imag(x));
    return std::complex<F2>(re, im);
  }


  //*******************************************************
  //          unary math functions
  //*******************************************************



  // complex conjugate: complex numbers

  template <typename D, typename = std::enable_if_t<std::is_arithmetic<D>::value> > std::complex<D>
  conj(const std::complex<D>& x) {
    return std::complex<D>(x.real(), -x.imag());
  }

  // complex conjugate OPERTOR ~

  template <typename D, typename = std::enable_if_t<std::is_arithmetic<D>::value> > std::complex<D>
  operator~(const std::complex<D>& x) {
    return std::complex<D>(x.real(), -x.imag());
  }

  // complex - normsqr
  template <typename D> D normsqr(const std::complex<D>& z) {
    return z.real()*z.real() + z.imag()*z.imag();
  }

  // complex - sqr
  template <typename D> std::complex<D> sqr(const std::complex<D>& z) {
    return z*z;
  }

  // cube(z)

  template <typename D> std::complex<D> cube(const std::complex<D>& z) {
    return z*z*z;
  }


  // complex rounding

  template <typename D> std::complex<D> round(const std::complex<D>& x) {
    return std::complex<D>(std::round(x.real()), std::round(x.imag()));
  }

  // complex - sgn
  template <typename D> std::complex<D> sgn(const std::complex<D>& z) {
    return std::complex<D>(sgn(real(z)), sgn(imag(z)));
  }


  // complex - floor
  template <typename D> std::complex<D> floor(const std::complex<D>& z) {
    using std::floor;
    return std::complex<D>(floor(real(z)), floor(imag(z)));
  }

  // complex - ceil
  template <typename D> std::complex<D> ceil(const std::complex<D>& z) {
    using std::ceil;
    return std::complex<D>(ceil(real(z)), ceil(imag(z)));
  }



  // complex - roundzero
  template <typename D> std::complex<D> roundzero(const std::complex<D>& x, const D tolerance = Functions<D>::tolerance) {
    return std::complex<D>(roundzero(x.real(), tolerance), roundzero(x.imag(), tolerance));
  }

  // approx - complex

  template <typename D1, typename D2>
  bool approx(const std::complex<D1>& x, const std::complex<D2>& y, const typename AddType<D1, D2>::Type tol = Functions<typename AddType<D1, D2>::Type>::tolerance) {
    return (mathq::approx(real(x), real(y), tol) && mathq::approx(imag(x), imag(y), tol));
  }

  // complex log2
  template <typename D> std::complex<D>
  log2(const std::complex<D>& x) {
    const D A0 = 1/log(D(2));
    return A0*log(x);
  }


  // Complex(D1,D2)

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value&& std::is_arithmetic<D2>::value>> auto
    Complex(const D1& xr, const D2& xi) {
    typedef typename AddType<D1, D2>::Type D3;
    return std::complex<D3>((D3)xr, (D3)xi);
  }


  // polar(D1,D2)

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value&& std::is_arithmetic<D2>::value>> auto
    polar(const D1& r, const D2& theta) {
    typedef typename AddType<D1, D2>::Type D3;
    return std::polar<D3>((D3)r, (D3)theta);
  }

  // ***************************************************************************
  // * Complex arithmetic: complex<D1> OP complex<D2>
  // ***************************************************************************

  // complex<D1> + complex<D2>

  template <typename D1, typename D2> inline
    std::complex<typename AddType<D1, D2>::Type>
    operator+(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)+real(x2);
    D3 yI = imag(x1)+imag(x2);
    T3 y(yR, yI);
    return y;
  }

  // complex<D1> - complex<D2>

  template <typename D1, typename D2> inline
    std::complex<typename SubType<D1, D2>::Type>
    operator-(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)-real(x2);
    D3 yI = imag(x1)-imag(x2);
    T3 y(yR, yI);
    return y;
  }

  // complex<D1> * complex<D2>

  template <typename D1, typename D2> inline
    std::complex<typename MultType<D1, D2>::Type>
    operator*(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)*real(x2)-imag(x1)*imag(x2);
    D3 yI = real(x1)*imag(x2)+imag(x1)*real(x2);
    T3 y(yR, yI);
    return y;
  }


  // complex<D1> / complex<D2>

  template <typename D1, typename D2> inline
    std::complex<typename DivType<D1, D2>::Type>
    operator/(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 topR = real(x1)*real(x2)+imag(x1)*imag(x2);
    D3 topI = -real(x1)*imag(x2)+imag(x1)*real(x2);
    D3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot, topI/bot);
  }


  // ***************************************************************************
  // * Complex arithmetic:  complex<D1> OP D2
  // *                              D1  OP complex<D2>
  // ***************************************************************************

  // complex<D1> + D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename AddType<D1, D2>::Type>
    operator+(const std::complex<D1>& x1, const D2& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)+x2;
    D3 yI = imag(x1);
    return T3(yR, yI);
  }

  // D1 + complex<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename AddType<D1, D2>::Type>
    operator+(const D1& x1, const std::complex<D2>& x2) {
    typedef typename AddType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1+real(x2);
    D3 yI = imag(x2);
    return T3(yR, yI);
  }


  // complex<D1> - D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename SubType<D1, D2>::Type>
    operator-(const std::complex<D1>& x1, const D2& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)-x2;
    D3 yI = imag(x1);
    return T3(yR, yI);
  }

  // D1 - complex<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename SubType<D1, D2>::Type>
    operator-(const D1& x1, const std::complex<D2>& x2) {
    typedef typename SubType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1-real(x2);
    D3 yI = -imag(x2);
    return T3(yR, yI);
  }


  // complex<D1> * D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename MultType<D1, D2>::Type>
    operator*(const std::complex<D1>& x1, const D2& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)*x2;
    D3 yI = imag(x1)*x2;
    return T3(yR, yI);
  }

  // D1 * complex<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename MultType<D1, D2>::Type>
    operator*(const D1& x1, const std::complex<D2>& x2) {
    typedef typename MultType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1*real(x2);
    D3 yI = x1*imag(x2);
    return T3(yR, yI);
  }


  // complex<D1> / D2

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename DivType<D1, D2>::Type>
    operator/(const std::complex<D1>& x1, const D2& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)/x2;
    D3 yI = imag(x1)/x2;
    return T3(yR, yI);
  }

  // D1 / complex<D2>

  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename DivType<D1, D2>::Type>
    operator/(const D1& x1, const std::complex<D2>& x2) {
    typedef typename DivType<D1, D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 topR = x1*real(x2);
    D3 topI = -x1*imag(x2);
    D3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot, topI/bot);
  }






};


#endif
