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
  template<class Number> struct is_complex<std::complex<Number>> : std::true_type {};

  // T<std::complex> (true)  container holding complex
  template<template<typename> class T, class Number> struct is_complex<T<std::complex<Number> > > : std::true_type {};


  // template <typename T> class
  //   Complexify {
  // public:
  //   typedef typename OrderedNumberTrait<T>::Type FType;
  //   typedef std::complex<FType> CType;
  //   typedef typename NumberTrait<T,CType>::ReplaceTypeE Type;
  // };
  // template <typename Element, typename A, typename Number, int Depth, int R> class
  //   Complexify<MArrayExpR<Element,A,Number,Depth,R> > {
  // public:
  //   typedef MArrayExpR<typename Complexify<Element>::Type,A,typename Complexify<Number>::Type, Depth,R> Type;
  // };


  // template <typename T> class
  //   Realify {
  // public:
  //   typedef typename OrderedNumberTrait<T>::Type FType;
  //   typedef typename NumberTrait<T,FType>::ReplaceTypeE Type;
  // };
  // template <typename Element, typename A, typename Number, int Depth, int R> class
  //   Realify<MArrayExpR<Element,A,Number,Depth,R> > {
  // public:
  //   typedef MArrayExpR<typename Realify<Element>::Type,A,typename Realify<Number>::Type,Depth,R> Type;
  // };



  // template <typename T> class
  //   Imaginarify {
  // public:
  //   typedef typename OrderedNumberTrait<T>::Type FType;
  //   typedef Imaginary<FType> IType;
  //   typedef typename NumberTrait<T,IType>::ReplaceTypeE Type;
  // };
  // template <typename Element, typename A, typename Number, int Depth, int R> class
  //   Imaginarify<MArrayExpR<Element,A,Number,Depth,R> > {
  // public:
  //   typedef MArrayExpR<typename Imaginarify<Element>::Type,A,typename Imaginarify<Number>::Type, Depth,R> Type;
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

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value> > std::complex<Number>
  conj(const std::complex<Number>& x) {
    return std::complex<Number>(x.real(), -x.imag());
  }

  // complex conjugate OPERTOR ~

  template <typename Number, typename = std::enable_if_t<std::is_arithmetic<Number>::value> > std::complex<Number>
  operator~(const std::complex<Number>& x) {
    return std::complex<Number>(x.real(), -x.imag());
  }

  // complex - normsqr
  template <typename Number> Number normsqr(const std::complex<Number>& z) {
    return z.real()*z.real() + z.imag()*z.imag();
  }

  // complex - sqr
  template <typename Number> std::complex<Number> sqr(const std::complex<Number>& z) {
    return z*z;
  }

  // cube(z)

  template <typename Number> std::complex<Number> cube(const std::complex<Number>& z) {
    return z*z*z;
  }


  // complex rounding

  template <typename Number> std::complex<Number> round(const std::complex<Number>& x) {
    return std::complex<Number>(std::round(x.real()), std::round(x.imag()));
  }

  // complex - sgn
  template <typename Number> std::complex<Number> sgn(const std::complex<Number>& z) {
    return std::complex<Number>(sgn(real(z)), sgn(imag(z)));
  }


  // complex - floor
  template <typename Number> std::complex<Number> floor(const std::complex<Number>& z) {
    using std::floor;
    return std::complex<Number>(floor(real(z)), floor(imag(z)));
  }

  // complex - ceil
  template <typename Number> std::complex<Number> ceil(const std::complex<Number>& z) {
    using std::ceil;
    return std::complex<Number>(ceil(real(z)), ceil(imag(z)));
  }



  // complex - roundzero
  template <typename Number> std::complex<Number> roundzero(const std::complex<Number>& x, const Number tolerance = Functions<Number>::tolerance) {
    return std::complex<Number>(roundzero(x.real(), tolerance), roundzero(x.imag(), tolerance));
  }

  // approx - complex

  template <typename D1, typename D2>
  bool approx(const std::complex<D1>& x, const std::complex<D2>& y, const typename AddType<D1, D2>::Type tol = Functions<typename AddType<D1, D2>::Type>::tolerance) {
    return (mathq::approx(real(x), real(y), tol) && mathq::approx(imag(x), imag(y), tol));
  }

  // complex log2
  template <typename Number> std::complex<Number>
  log2(const std::complex<Number>& x) {
    const Number A0 = 1/log(Number(2));
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
