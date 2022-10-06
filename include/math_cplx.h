#ifndef MATHQ__MATH_CPLX
#define MATHQ__MATH_CPLX


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
  template<typename Num> struct is_complex<std::complex<Num>> : std::true_type {};

  // T<std::complex> (true)  container holding complex
  template<template<typename> class T, typename Num> struct is_complex<T<std::complex<Num> > > : std::true_type {};


  // template <typename T> class
  //   Complexify {
  // public:
  //   typedef typename SimpleNumberTrait<T>::Type SimpleNumberType;
  //   typedef std::complex<SimpleNumberType> CType;
  //   typedef typename NumberTrait<T,CType>::ReplacedElementType Type;
  // };
  // template <typename Element, typename A, typename Num, int depth, int rank> class
  //   Complexify<ExpressionR<Element,A,Num,depth,rank> > {
  // public:
  //   typedef ExpressionR<typename Complexify<Element>::Type,A,typename Complexify<Num>::Type, depth,rank> Type;
  // };


  // template <typename T> class
  //   Realify {
  // public:
  //   typedef typename SimpleNumberTrait<T>::Type SimpleNumberType;
  //   typedef typename NumberTrait<T,SimpleNumberType>::ReplacedElementType Type;
  // };
  // template <typename Element, typename A, typename Num, int depth, int rank> class
  //   Realify<ExpressionR<Element,A,Num,depth,rank> > {
  // public:
  //   typedef ExpressionR<typename Realify<Element>::Type,A,typename Realify<Num>::Type,depth,rank> Type;
  // };



  // template <typename T> class
  //   Imaginarify {
  // public:
  //   typedef typename SimpleNumberTrait<T>::Type SimpleNumberType;
  //   typedef Imaginary<SimpleNumberType> IType;
  //   typedef typename NumberTrait<T,IType>::ReplacedElementType Type;
  // };
  // template <typename Element, typename A, typename Num, int depth, int rank> class
  //   Imaginarify<ExpressionR<Element,A,Num,depth,rank> > {
  // public:
  //   typedef ExpressionR<typename Imaginarify<Element>::Type,A,typename Imaginarify<Num>::Type, depth,rank> Type;
  // };




  // numbercast


  template <typename C2, typename F1> EnableMethodIf<IsComplex<C2>::value, C2>
  numbercast(const std::complex<F1>& x) {
    typedef typename IsComplex<C2>::SimpleNumberType F2;
    F2 re = numbercast<F2>(real(x));
    F2 im = numbercast<F2>(imag(x));
    return std::complex<F2>(re, im);
  }


  //*******************************************************
  //          unary math functions
  //*******************************************************



  // complex conjugate: complex numbers

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value> > std::complex<Num>
  conj(const std::complex<Num>& x) {
    return std::complex<Num>(x.real(), -x.imag());
  }

  // complex conjugate OPERTOR ~

  template <typename Num, typename = std::enable_if_t<std::is_arithmetic<Num>::value> > std::complex<Num>
  operator~(const std::complex<Num>& x) {
    return std::complex<Num>(x.real(), -x.imag());
  }

  // complex - normsqr
  template <typename Num> Num normsqr(const std::complex<Num>& z) {
    return z.real()*z.real() + z.imag()*z.imag();
  }

  // complex - sqr
  template <typename Num> std::complex<Num> sqr(const std::complex<Num>& z) {
    return z*z;
  }

  // cube(z)

  template <typename Num> std::complex<Num> cube(const std::complex<Num>& z) {
    return z*z*z;
  }


  // complex rounding

  template <typename Num> std::complex<Num> round(const std::complex<Num>& x) {
    return std::complex<Num>(std::round(x.real()), std::round(x.imag()));
  }

  // complex - sgn
  template <typename Num> std::complex<Num> sgn(const std::complex<Num>& z) {
    return std::complex<Num>(sgn(real(z)), sgn(imag(z)));
  }


  // complex - floor
  template <typename Num> std::complex<Num> floor(const std::complex<Num>& z) {
    using std::floor;
    return std::complex<Num>(floor(real(z)), floor(imag(z)));
  }

  // complex - ceil
  template <typename Num> std::complex<Num> ceil(const std::complex<Num>& z) {
    using std::ceil;
    return std::complex<Num>(ceil(real(z)), ceil(imag(z)));
  }



  // complex - roundzero
  template <typename Num> std::complex<Num> roundzero(const std::complex<Num>& x, const Num tolerance = Functions<Num>::tolerance) {
    return std::complex<Num>(roundzero(x.real(), tolerance), roundzero(x.imag(), tolerance));
  }

  // approx - complex

  template <typename NT1, typename NT2>
  bool approx(const std::complex<NT1>& x, const std::complex<NT2>& y, const typename AddType<NT1, NT2>::Type tol = Functions<typename AddType<NT1, NT2>::Type>::tolerance) {
    typename AddType<NT1, NT2>::Type d = std::max(std::abs(x), std::abs(y));
    decltype(Functions<typename AddType<NT1, NT2>::Type>::tolerance) tolerance = d * tol;
    return (roundzero(std::abs(x-y), tolerance) == 0);
    // return (mathq::approx(real(x), real(y), tolerance) && mathq::approx(imag(x), imag(y), tolerance));
  }

  // complex log2
  template <typename Num> std::complex<Num>
  log2(const std::complex<Num>& x) {
    const Num A0 = 1/log(Num(2));
    return A0*log(x);
  }


  // Complex(NT1,NT2)

  template <typename NT1, typename NT2> auto
    Complex(const NT1& xr, const NT2& xi) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    return std::complex<NT3>((NT3)xr, (NT3)xi);
  }


  // polar(NT1,NT2)

  template <typename NT1, typename NT2> auto
    polar(const NT1& r, const NT2& theta) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    return std::polar<NT3>((NT3)r, (NT3)theta);
  }

  // ***************************************************************************
  // * Complex arithmetic: complex<NT1> OP complex<NT2>
  // ***************************************************************************

  // complex<NT1> + complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename AddType<NT1, NT2>::Type>
    operator+(const std::complex<NT1>& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = real(x1)+real(x2);
    NT3 yI = imag(x1)+imag(x2);
    T3 y(yR, yI);
    return y;
  }

  // complex<NT1> - complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename SubType<NT1, NT2>::Type>
    operator-(const std::complex<NT1>& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = real(x1)-real(x2);
    NT3 yI = imag(x1)-imag(x2);
    T3 y(yR, yI);
    return y;
  }

  // complex<NT1> * complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename MultType<NT1, NT2>::Type>
    operator*(const std::complex<NT1>& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = real(x1)*real(x2)-imag(x1)*imag(x2);
    NT3 yI = real(x1)*imag(x2)+imag(x1)*real(x2);
    T3 y(yR, yI);
    return y;
  }


  // complex<NT1> / complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename DivType<NT1, NT2>::Type>
    operator/(const std::complex<NT1>& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 topR = real(x1)*real(x2)+imag(x1)*imag(x2);
    NT3 topI = -real(x1)*imag(x2)+imag(x1)*real(x2);
    NT3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot, topI/bot);
  }


  // ***************************************************************************
  // * Complex arithmetic:  complex<NT1> OP NT2
  // *                              NT1  OP complex<NT2>
  // ***************************************************************************

  // complex<NT1> + NT2

  template <typename NT1, typename NT2> inline
    std::complex<typename AddType<NT1, NT2>::Type>
    operator+(const std::complex<NT1>& x1, const NT2& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = real(x1)+x2;
    NT3 yI = imag(x1);
    return T3(yR, yI);
  }

  // NT1 + complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename AddType<NT1, NT2>::Type>
    operator+(const NT1& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename AddType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = x1+real(x2);
    NT3 yI = imag(x2);
    return T3(yR, yI);
  }


  // complex<NT1> - NT2

  template <typename NT1, typename NT2> inline
    std::complex<typename SubType<NT1, NT2>::Type>
    operator-(const std::complex<NT1>& x1, const NT2& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = real(x1)-x2;
    NT3 yI = imag(x1);
    return T3(yR, yI);
  }

  // NT1 - complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename SubType<NT1, NT2>::Type>
    operator-(const NT1& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename SubType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = x1-real(x2);
    NT3 yI = -imag(x2);
    return T3(yR, yI);
  }


  // complex<NT1> * NT2

  template <typename NT1, typename NT2 > inline
    std::complex<typename MultType<NT1, NT2>::Type>
    operator*(const std::complex<NT1>& x1, const NT2& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = real(x1)*x2;
    NT3 yI = imag(x1)*x2;
    return T3(yR, yI);
  }

  // NT1 * complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename MultType<NT1, NT2>::Type>
    operator*(const NT1& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename MultType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = x1*real(x2);
    NT3 yI = x1*imag(x2);
    return T3(yR, yI);
  }


  // complex<NT1> / NT2

  template <typename NT1, typename NT2> inline
    std::complex<typename DivType<NT1, NT2>::Type>
    operator/(const std::complex<NT1>& x1, const NT2& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 yR = real(x1)/x2;
    NT3 yI = imag(x1)/x2;
    return T3(yR, yI);
  }

  // NT1 / complex<NT2>

  template <typename NT1, typename NT2> inline
    std::complex<typename DivType<NT1, NT2>::Type>
    operator/(const NT1& x1, const std::complex<NT2>& x2) requires (std::is_arithmetic<NT1>::value&& std::is_arithmetic<NT2>::value) {
    typedef typename DivType<NT1, NT2>::Type NT3;
    typedef typename std::complex<NT3> T3;
    NT3 topR = x1*real(x2);
    NT3 topI = -x1*imag(x2);
    NT3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot, topI/bot);
  }






};


#endif
