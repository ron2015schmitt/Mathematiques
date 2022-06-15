#ifndef MATHQ__PREFACE_H
#define MATHQ__PREFACE_H


#define CPP11 (__cplusplus >= 201100L)
#define CPP14 (__cplusplus >= 201400L)
#define CPP17 (__cplusplus >= 201700L)

#define _stringify(...) #__VA_ARGS__
#define stringify(...) _stringify(__VA_ARGS__)



#define DO_EXPAND(VAL) 99##VAL
#define EXPAND(VAL) DO_EXPAND(VAL)


#ifdef MEBUG
#if (EXPAND(MEBUG) == 99)
// defined but no value: set to 1
#define MATHQ_DEBUG 1
#else
#define MATHQ_DEBUG EXPAND(MEBUG)
#endif
#endif


#ifndef MATHQ_DEBUG
// not defined: set to 0
#define MATHQ_DEBUG 0
#elif (EXPAND(MATHQ_DEBUG) == 99)
// defined but no value: set to 1
#undef MATHQ_DEBUG
#define MATHQ_DEBUG 1
#elif (MATHQ_DEBUG > 3)
// no modes defined above 3
#undef MATHQ_DEBUG
#define MATHQ_DEBUG 3
#endif


#ifdef MATHQ_COPTS
// it contains the $(OPTIMIZE) flag with all the compile optimization options
// it is appended to each cpp file during compilation, if MATHQ_COPTS is enabled
extern char COMPILER_OPT_STR[];
#endif


namespace display {

  template <typename T>
  inline std::string getBracketedTypeName(const T& var);
  template <typename T>
  inline void dispval_strm(std::ostream& stream, const T& d);
}; // namespace display

namespace mathq {


  class Null {};




  //*******************************************************
  //          Typedefs
  //*******************************************************

  typedef std::vector<double>::size_type size_type;
  typedef int index_type;
  typedef long double extended;


  template <typename D>
  class Imaginary;

  template <typename D>
  class Quaternion;

  template <typename T, typename NUM = double, typename H = void>
  class NumberType;


  // E = element type (int, double, complex<double>, bool, Scalar<double>, Vector<double>, Matrix<double>, etc)
  // D = number type (int, double, complex<double>, bool, etc)

  template <class X, class E, typename D, int M, int R>
  class MArrayExpR;
  template <class X, class E, typename D, int M, int R>
  class MArrayExpRW;


  // *********************************************************************
  // * Concrete MultiArrays
  // ********************************************************************



  template <class E, typename D = typename NumberType<E>::Type, int M = 1 + NumberType<E>::depth()>
  class
    Scalar;

  template <class E, int NE = 0, typename D = typename NumberType<E>::Type, int M = 1 + NumberType<E>::depth()>
  class
    Vector;

  template <class E, int NR = 0, int NC = 0, typename D = typename NumberType<E>::Type, int M = 1 + NumberType<E>::depth()>
  class
    Matrix;

  template <class E, int R = 0, typename D = typename NumberType<E>::Type, int M = 1 + NumberType<E>::depth()>
  class
    MultiArray;

  // *********************************************************************
  // * Special Matrices
  // ********************************************************************


  template <class D, int NR = 0, int NC = 0>
  class
    MatrixZero;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixIdentity;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixExchange;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixConstDiag;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixDiagonal;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixRevDiag;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixRepCol;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixRepRow;


  template <class D>
  class
    MatrixRep;

  // put in a namespace so that the enums don't clash
  namespace MatrixRepTypes {
    enum Type { REPEAT_ROW, REPEAT_COLUMN };
  };

  using MatrixRepEnum = MatrixRepTypes::Type;


  template <class D, int NR = 0, int NC = 0>
  class
    MatrixVandermonde;

  template <class D, int NR = 0, int NC = 0>
  class
    MatrixToeplitz;

  template <class D, int N = 0>
  class
    MatrixUpperTriangle;

  template <class D, int N = 0>
  class
    MatrixLowerTriangle;

  template <class D, int N = 0>
  class
    MatrixSymmetric;

  template <class D, int N = 0>
  class
    MatrixSkewSymmetric;

  template <class D, int N = 0>
  class
    MatrixHermitian;

  template <class D, int N = 0>
  class
    MatrixSkewHermitian;

  // *********************************************************************
  // * Expressions
  // ********************************************************************



  template <class X, class E, class D, int M, int R, class FUNC>
  class
    TER_Unary;

  template <class A, class B, class E1, class E2, class E3, class D1, class D2, class D3, int M1, int M2, int M3, int R1, int R2, int R3, class OP>
  class
    TER_Binary;

  template <class A, class B, class C, class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4, int M1, int M2, int M3, int M4, int R1, int R2, int R3, int R4, class OP>
  class
    TER_Ternary;

  template <class A, class X, class E, class D, int M, int R>
  class TER_Series;

  template <class A, class B, class X, class D, class OP1, class OP2>
  class TER_Series2;

  template <class X, class E, class D, int M, int R, class FUNC>
  class TER_Transpose;

  template <class A, class D>
  class TER_Rep;

  template <class X, class Y, class E, class D, int M>
  class TER_Join;


  template <class D>
  class TERW_Subset;

  template <class D>
  class TERW_Submask;

  template <class X, class Y, class E, class D, int M>
  class TERW_Join;

  // *********************************************************************
  // * Class type querying/manipulation
  // ********************************************************************

  // ***************************************************************************
  // Materialize - this returns a concrete tensor of type specified by paramters
  // ***************************************************************************

  template <class E, class D, int M, int R, int N1 = 0, int N2 = 0>
  class Materialize {
  public:
    typedef MultiArray<E, R, D, M> TEN;
    typedef Matrix<E, 0, 0, D, M> MAT;
    typedef Vector<E, 0, D, M> VEC;
    typedef Scalar<E, D, M> SCA;
    typedef typename std::conditional<R == 0, SCA, std::conditional<R == 1, VEC, std::conditional<R == 2, MAT, TEN>>>::type Type;
  };

  template <class E, class D, int M>
  class Materialize<E, D, M, 0> {
  public:
    typedef Scalar<E, D, M> Type;
  };

  template <class E, class D, int M, int N1>
  class Materialize<E, D, M, 1, N1> {
  public:
    typedef Vector<E, N1, D, M> Type;
  };

  template <class E, class D, int M, int N1, int N2>
  class Materialize<E, D, M, 2, N1, N2> {
  public:
    typedef Matrix<E, N1, N2, D, M> Type;
  };


  // ***************************************************************************
  // ContainedType - this returns the contained type of a complex number
  //                 this could certainly be specialized for other
  //                 container types
  //                 ** USE WITH GREAT CAUTION **
  //    NOTE: THis only works for concrete tensors (and for expresssions)
  //          C++ template paramters and specialization does not find subclasses
  // ***************************************************************************

  template <typename T>
  class
    ContainedType {
  public:
    typedef void Type;
  };
  template <typename D>
  class
    ContainedType<std::complex<D>> {
  public:
    typedef D Type;
  };

  template <typename D>
  class
    ContainedType<Imaginary<D>> {
  public:
    typedef D Type;
  };

  template <typename D>
  class
    ContainedType<Quaternion<D>> {
  public:
    typedef D Type;
  };

  template <template <typename> class T, typename D>
  class
    ContainedType<T<D>> {
  public:
    typedef D Type;
  };
  template <typename X, typename E, typename D, int M, int R>
  class
    ContainedType<MArrayExpR<X, E, D, M, R>> {
  public:
    typedef E Type;
  };


  // ***************************************************************************
  //  IsComplex<T>
  // ***************************************************************************


  template <typename T>
  class
    IsComplex {
  public:
    constexpr static bool value = false;
    typedef void RealType;
  };
  template <typename D>
  class
    IsComplex<std::complex<D>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };

  // ***************************************************************************
  //  IsImaginary<T>
  // ***************************************************************************


  template <typename T>
  class
    IsImaginary {
  public:
    constexpr static bool value = false;
    typedef void RealType;
  };
  template <typename D>
  class
    IsImaginary<mathq::Imaginary<D>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };

  // ***************************************************************************
  //  IsQuaternion<T>
  // ***************************************************************************


  template <typename T>
  class
    IsQuaternion {
  public:
    constexpr static bool value = false;
    typedef void RealType;
  };
  template <typename D>
  class
    IsQuaternion<mathq::Quaternion<D>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };


  // ***************************************************************************
  //  IsMathqContainer<T>
  // ***************************************************************************


  template <typename T>
  class
    IsMathqContainer {
  public:
    constexpr static bool value = false;
    typedef void RealType;
  };

  template <typename D>
  class
    IsMathqContainer<Scalar<D>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };

  template <typename D>
  class
    IsMathqContainer<Vector<D>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <typename D, int NE>
  class
    IsMathqContainer<Vector<D, NE>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };

  template <typename D>
  class
    IsMathqContainer<Matrix<D>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <typename D, int NR>
  class
    IsMathqContainer<Matrix<D, NR>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <typename D, int NR, int NC>
  class
    IsMathqContainer<Matrix<D, NR, NC>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };

  template <typename D>
  class
    IsMathqContainer<MultiArray<D>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <typename D, int R>
  class
    IsMathqContainer<MultiArray<D, R>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };


  template <class X, class E, typename D, int M, int R>
  class
    IsMathqContainer<MArrayExpR<X, E, D, M, R>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <class X, class E, typename D, int M, int R>
  class
    IsMathqContainer<MArrayExpRW<X, E, D, M, R>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };


  // ***************************************************************************
  //  IsMArrayExpRW<T>
  // ***************************************************************************


  template <typename T>
  class
    IsMArrayExpRW {
  public:
    constexpr static bool value = false;
    typedef void RealType;
  };
  template <class X, class E, typename D, int M, int R>
  class
    IsMArrayExpRW<MArrayExpRW<X, E, D, M, R>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <class X, class E, typename D, int M, int R>
  class
    IsMArrayExpRW<MArrayExpR<X, E, D, M, R>> {
  public:
    constexpr static bool value = IsMArrayExpRW<X>::value;
    typedef D RealType;
  };


  // ***************************************************************************
  // FundamentalType - this operates recursively to find the primitive arithmetic type
  //                   eg int, float, double, ...
  //    NOTE: THis only works for concrete tensors (and for expresssions)
  //          C++ template paramters and specialization does not find subclasses
  // ***************************************************************************

  template <typename T>
  class
    FundamentalType {
  public:
    typedef T Type;
    constexpr static int depth() {
      return 0;
    }
  };

  template <class E, template <typename> class T>
  class
    FundamentalType<T<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };
  template <class E>
  class
    FundamentalType<std::complex<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  template <class E>
  class
    FundamentalType<Imaginary<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  template <class E>
  class
    FundamentalType<Quaternion<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };



  //  Scalar<E>
  template <class E>
  class
    FundamentalType<Scalar<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  //  Vector<E>
  template <class E>
  class
    FundamentalType<Vector<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };
  //  Vector<E,NE>
  template <class E, int NE>
  class
    FundamentalType<Vector<E, NE>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  //  Matrix<E>

  template <class E>
  class
    FundamentalType<Matrix<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  //  Matrix<E,NR>

  template <class E, int NR>
  class
    FundamentalType<Matrix<E, NR>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  //  Matrix<E,NR,NC>

  template <class E, int NR, int NC>
  class
    FundamentalType<Matrix<E, NR, NC>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  //  MultiArray<E>
  template <class E>
  class
    FundamentalType<MultiArray<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  //  MultiArray<E,R>
  template <class E, int R>
  class
    FundamentalType<MultiArray<E, R>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1 + FundamentalType<E>::depth();
    }
  };

  //  MArrayExpR<X,E,D,M,R>

  template <class X, class E, class D, int M, int R>
  class
    FundamentalType<MArrayExpR<X, E, D, M, R>> {
  public:
    typedef typename FundamentalType<D>::Type Type;
    constexpr static int depth() {
      return M;
    }
  };



  // ***************************************************************************
  // NumberType - this operates recursively to find the base number type
  //              eg. complex<double>, Imaginary<float>, Quaternion<float>, int, double, etc
  //
  //    NOTE: THis only works for concrete tensors (and for expresssions)
  //          C++ template paramters and specialization does not find subclasses
  // ***************************************************************************

  template <typename NewD>
  class
    NumberType<Null, NewD> {
  public:
    typedef Null Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this
    constexpr static bool value = true;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(Null x) {
      return 0;
    }
    inline static int deepsize(Null x) {
      return 0;
    }
  };

  template <typename T, typename NewD>
  class
    NumberType<T, NewD, typename std::enable_if<std::is_arithmetic<T>::value>::type> {
  public:
    typedef T Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this
    constexpr static bool value = true;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(const T x) {
      return 1;
    }
    inline static int deepsize(const T& x) {
      return 1;
    }
  };

  template <class D, typename NewD>
  class
    NumberType<std::complex<D>, NewD> {
  public:
    typedef std::complex<D> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this
    constexpr static bool value = true;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(const std::complex<D> x) {
      return 1;
    }
    inline static int deepsize(const std::complex<D> x) {
      return 1;
    }
  };

  template <class D, typename NewD>
  class NumberType<Imaginary<D>, NewD> {
  public:
    typedef Imaginary<D> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this (use FundamentalType to change
    constexpr static bool value = true;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(const Imaginary<D> x) {
      return 1;
    }
    inline static int deepsize(const Imaginary<D> x) {
      return 1;
    }
  };

  template <class D, typename NewD>
  class NumberType<Quaternion<D>, NewD> {
  public:
    typedef Quaternion<D> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this (use FundamentalType to change
    constexpr static bool value = true;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(const Quaternion<D> x) {
      return 1;
    }
    inline static int deepsize(const Quaternion<D> x) {
      return 1;
    }
  };



  //  Scalar<E>

  template <class E, typename NewD>
  class
    NumberType<Scalar<E>, NewD> {
  public:
    typedef Scalar<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Scalar<typename NumberType<E, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef Scalar<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Vector<E>

  template <class E, typename NewD>
  class
    NumberType<Vector<E>, NewD> {
  public:
    typedef Vector<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Vector<typename NumberType<E, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef Vector<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  Vector<E,NE>

  template <class E, typename NewD, int NE>
  class
    NumberType<Vector<E, NE>, NewD> {
  public:
    typedef Vector<E, NE> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Vector<typename NumberType<E, NewD>::ReplaceTypeD, NE> ReplaceTypeD;
    typedef Vector<NewD, NE> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Matrix<E>

  template <class E, typename NewD>
  class
    NumberType<Matrix<E>, NewD> {
  public:
    typedef Matrix<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Matrix<typename NumberType<E, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef Matrix<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  Matrix<E,NR>

  template <class E, typename NewD, int NR>
  class
    NumberType<Matrix<E, NR>, NewD> {
  public:
    typedef Matrix<E, NR> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Matrix<typename NumberType<E, NewD>::ReplaceTypeD, NR> ReplaceTypeD;
    typedef Matrix<NewD, NR> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Matrix<E,NR,NC>

  template <class E, typename NewD, int NR, int NC>
  class
    NumberType<Matrix<E, NR, NC>, NewD> {
  public:
    typedef Matrix<E, NR, NC> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Matrix<typename NumberType<E, NewD>::ReplaceTypeD, NR, NC> ReplaceTypeD;
    typedef Matrix<NewD, NR, NC> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };



  //  MultiArray<E>

  template <class E, typename NewD>
  class
    NumberType<MultiArray<E>, NewD> {
  public:
    typedef MultiArray<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef MultiArray<typename NumberType<E, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef MultiArray<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  MultiArray<E,R>

  template <class E, typename NewD, int R>
  class
    NumberType<MultiArray<E, R>, NewD> {
  public:
    typedef MultiArray<E, R> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef MultiArray<typename NumberType<E, NewD>::ReplaceTypeD, R> ReplaceTypeD;
    typedef MultiArray<NewD, R> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberType<E, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };



  //  MArrayExpR<X,E,D,M,R>

  template <class X, class E, class D, int M, int R, typename NewD>
  class
    NumberType<MArrayExpR<X, E, D, M, R>, NewD> {
  public:
    typedef MArrayExpR<X, E, D, M, R> InputType;
    typedef D Type;
    typedef typename NumberType<E, NewD>::ReplaceTypeD NewE;
    typedef typename NumberType<X, NewD>::ReplaceTypeD NewX;
    typedef NewX ReplaceTypeD;
    typedef MArrayExpR<X, NewD, D, M, R> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return M;
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  MArrayExpRW<X,E,D,M,R>

  template <class X, class E, class D, int M, int R, typename NewD>
  class
    NumberType<MArrayExpRW<X, E, D, M, R>, NewD> {
  public:
    typedef MArrayExpRW<X, E, D, M, R> InputType;
    typedef D Type;
    typedef typename NumberType<E, NewD>::ReplaceTypeD NewE;
    typedef typename NumberType<X, NewD>::ReplaceTypeD NewX;
    typedef NewX ReplaceTypeD;
    typedef MArrayExpRW<X, NewD, D, M, R> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return M;
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };



  // ***************************************************************************
  // DeeperType - this operates recursively to find the primitive arithmetic type
  // ***************************************************************************

  template <typename T1, typename T2>
  class
    DeeperType {
  public:
    typedef typename std::conditional<NumberType<T1>::depth() >= NumberType<T2>::depth(), T1, T2>::type Type;
  };


  // ***************************************************************************
  // InversionType - turnt he type inside out
  //    example:  Vector<Scalar<double>>   ->   Scalar<Vector<double>>
  //
  //    NOTE: THis only works for concrete tensors (and for expresssions)
  // ***************************************************************************


  template <class D, class C>
  class
    InversionType {
  public:
    typedef C Type;
  };
  template <class D, class C>
  class
    InversionType<std::complex<D>, C> {
  public:
    typedef C Type;
  };
  template <class D, class C>
  class
    InversionType<Imaginary<D>, C> {
  public:
    typedef C Type;
  };

  template <class D, class C>
  class
    InversionType<Quaternion<D>, C> {
  public:
    typedef C Type;
  };



  //  Scalar<E>

  template <class E, class C>
  class
    InversionType<Scalar<E>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef Scalar<D> MultiArrayD;
    typedef Scalar<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };

  //  Vector<E>

  template <class E, class C>
  class
    InversionType<Vector<E>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef Vector<D> MultiArrayD;
    typedef Vector<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };

  //  Vector<E,NE>
  template <class E, int NE, class C>
  class
    InversionType<Vector<E, NE>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef Vector<D, NE> MultiArrayD;
    typedef Vector<C, NE> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<E>

  template <class E, class C>
  class
    InversionType<Matrix<E>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef Matrix<D> MultiArrayD;
    typedef Matrix<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<E,NR>

  template <class E, int NR, class C>
  class
    InversionType<Matrix<E, NR>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef Matrix<D, NR> MultiArrayD;
    typedef Matrix<C, NR> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<E,NR,NC>

  template <class E, int NR, int NC, class C>
  class
    InversionType<Matrix<E, NR, NC>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef Matrix<D, NR, NC> MultiArrayD;
    typedef Matrix<C, NR, NC> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };

  //  MultiArray<E>
  template <class E, class C>
  class
    InversionType<MultiArray<E>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef MultiArray<D> MultiArrayD;
    typedef MultiArray<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };

  //  MultiArray<E,R>
  template <class E, int R, class C>
  class
    InversionType<MultiArray<E, R>, C> {
  public:
    typedef typename NumberType<E>::Type D;
    typedef MultiArray<D, R> MultiArrayD;
    typedef MultiArray<C, R> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<E, MultiArrayD>::Type, typename InversionType<E, MultiArrayC>::Type>::type Type;
  };


  // Can't define InversionType for MArrayExpR nor MArrayExpRW nor any expresssions


  // ***************************************************************************
  // At(x,n) -  for primitives, return x
  //            for container of any type, return x[n]
  // ***************************************************************************

  template <class D>
  inline D&& At(D&& x, index_type n) {
    return x;
  }
  template <class D>
  inline const D&& At(const D&& x, index_type n) {
    return x;
  }
  template <template <class> class T, class D>
  inline D&& At(T<D>&& x, index_type n) {
    return x[n];
  }
  template <template <class> class T, class D>
  inline const D&& At(const T<D>&& x, index_type n) {
    return x[n];
  }



  // ***************************************************************************
  // * {Add,Sub,Mult,Div,Rel,etc}Type: Class that determines return type of an aritmetic
  // *                 operation between two types
  // ***************************************************************************

  template <typename T1, typename T2>
  class AddType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1 + x2) Type;
    static inline std::string name() {
      return typeid(Type).name();
    }
  };
  template <typename T1, typename T2>
  class SubType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1 - x2) Type;
  };
  template <typename T1, typename T2>
  class MultType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1* x2) Type;
  };
  template <typename T1, typename T2>
  class DivType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1 / x2) Type;
  };
  template <typename T1, typename T2>
  class RelType {
  public:
    T1 x1;
    T2 x2;
    typedef bool Type;
    static inline std::string name() {
      return typeid(Type).name();
    }
  };
  template <typename T1, typename T2>
  class AndType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1&& x2) Type;
    static inline std::string name() {
      return typeid(Type).name();
    }
  };
  template <typename T1, typename T2>
  class OrType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1 || x2) Type;
    static inline std::string name() {
      return typeid(Type).name();
    }
  };
  template <typename T1, typename T2>
  class ComplexType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1 + x2) TType;
    typedef std::complex<TType> Type;
    static inline std::string name() {
      return typeid(Type).name();
    }
  };


  // ************************************************************************
  // * ReturnType: Class that determines return type of two MultiArrays of different depths
  // ***************************************************************************


  template <typename A, typename B, typename NewD>
  class ResultType {
  public:
    typedef typename DeeperType<A, B>::Type DeeperType;
    typedef typename NumberType<DeeperType, NewD>::ReplaceTypeD MultiArrayType;
    constexpr static bool isprim = (NumberType<A>::depth() == 0) && (NumberType<B>::depth() == 0);
    typedef typename std::conditional<isprim, NewD, MultiArrayType>::type Type;
  };




  //***********************************************************************
  //     is_instance<FilledTemplateClassA or object, TemplateCLassB>
  //
  //   is_instance<Fun_Multiply<double>, Fun_Divide>{}       -> false
  //   is_instance<Fun_Multiply<double>, Fun_Multiply>{}     -> true
  //   is_instance<obj, Vector>{}     -
  //***********************************************************************


  template <class, template <class> class>
  struct is_instance : public std::false_type {};
  template <class T, template <class> class U>
  struct is_instance<U<T>, U> : public std::true_type {};

  //***********************************************************************
  //  EnableIf - used for enabling constructors or methods
  //***********************************************************************

  template <bool B>
  using EnableIf = typename std::enable_if<B, int>::type;

  //***********************************************************************
  //  EnableMethodIf - used for enabling methods via return type give as T
  //***********************************************************************
  template <bool B, class T>
  using EnableMethodIf = typename std::enable_if<B, T>::type;

  //************************************************************************
  //* Basic Function types for computation
  //************************************************************************
  template <typename DOUT>
  class FunctionType0 {
  public:
    typedef DOUT(type)();
  };
  template <typename D1, typename DOUT>
  class FunctionType1 {
  public:
    typedef DOUT(type)(D1);
  };
  template <typename D1, typename D2, typename DOUT>
  class FunctionType2 {
  public:
    typedef DOUT(type)(D1, D2);
  };
  template <typename D1, typename D2, typename D3, typename DOUT>
  class FunctionType3 {
  public:
    typedef DOUT(type)(D1, D2, D3);
  };



  // ***************************************************************************
  // GridType 
  // ***************************************************************************

  template <class E, class D, int M, int R>
  class GridType {
  public:
    typedef MultiArray<E, R, D, M> Type;
  };

  template <class E, class D, int M>
  class GridType<E, D, M, 0> {
  public:
    typedef Scalar<E, D, M> Type;
  };

  template <class E, class D, int M>
  class GridType<E, D, M, 1> {
  public:
    typedef Vector<E, 0, D, M> Type;
  };

  template <class E, class D, int M>
  class GridType<E, D, M, 2> {
  public:
    typedef Matrix<E, 0, 0, D, M> Type;
  };


  // ***************************************************************************
  // * Grid
  //
  // This is a nested structure with M=2:
  //   top level: A single vector of fixed size, Vector<D,NDIMS>
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <class D, size_t NDIMS>
  using Grid = typename GridType<D, D, 1, NDIMS>::Type;



  // ***************************************************************************
  // * GridScale enum
  // ***************************************************************************

  // put in a namespace so that the enums don't clash
  namespace GridScale {
    enum Type { LINEAR = false, LOG = true };
  };

  using GridScaleEnum = GridScale::Type;


  // ***************************************************************************
  // * VectorofGrids
  //
  // This is a nested structure with M=2:
  //   top level: A single vector of fixed size, Vector<D,NDIMS>
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <class D, size_t NDIMS>
  using VectorofGrids = Vector<Grid<D, NDIMS>, NDIMS>;


  // ***************************************************************************
  // * GridofVectors
  //
  // This is a nested structure with M=2:
  //   top level: a single multiarray of fixed rank=NDIMS but dynamic size
  //   second level: Vectors of fixed size, Vector<D,NDIMS>
  //
  // This type has the same total number of elements as VectorofGrids.
  // The two types can be converted from one to another using the function 'insideout'.
  // ***************************************************************************
  template <class D, size_t NDIMS>
  using GridofVectors = typename Grid<Vector<D, NDIMS>, NDIMS>::Type;



  // ***************************************************************************
  // * RealSet 
  // ***************************************************************************

  template <class D>
  class RealSet;


  // ***************************************************************************
  // * RealMultiSet 
  // ***************************************************************************
  template <class D, size_t NE = 0>
  class RealMultiSet;


  // ***************************************************************************
  // * CurvilinearCoordinateSystem 
  // ***************************************************************************
  template <class D, size_t NDIMS, typename CHILD>
  class CurvilinearCoordinateSystem;

  // ***************************************************************************
  // * nabla object
  // ***************************************************************************

  template <class T = void>
  class Nabla {
  public:
    const unsigned int Ndims;
    const unsigned int Nwindow;
    const bool periodic;
  public:
    Nabla(const unsigned int Ndims = 1, const unsigned int Nwindow = 7, const bool periodic = false) :
      Ndims(Ndims), Nwindow(Nwindow), periodic(periodic) {
    }
    ~Nabla() {
    }
  };



  ////////////////////////////////////////////////////////////
  // In functions_misc.h
  ////////////////////////////////////////////////////////////

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<std::is_same<D, bool>::value, Vector<index_type>&> findtrue(const MArrayExpR<X, E, D, M, R>& v);




}; // namespace mathq






#endif
