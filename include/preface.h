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

  typedef long double extended;


  template <typename D>
  class Imaginary;

  template <typename D>
  class Quaternion;

  template <typename T, typename NUM = double, typename H = void>
  class NumberTrait;


  // Element = element type (int, double, complex<double>, bool, Scalar<double>, Vector<double>, Matrix<double>, etc)
  // D = underlying ordered field (orderable-number) type (int, double, complex<double>, bool, etc)

  template <class X, class Element, typename D, int M, int R>
  class MArrayExpR;
  template <class X, class Element, typename D, int M, int R>
  class MArrayExpRW;





  // *********************************************************************
  // * Concrete MultiArrays
  // ********************************************************************



  template <class Element, typename D = typename NumberTrait<Element>::Type, int M = 1 + NumberTrait<Element>::depth()>
  class Scalar;

  template <class Element, int NE = 0>
  class Vector;

  template <class Element, int NR = 0, int NC = 0>
  class Matrix;

  template <class Element, int R = 0, typename D = typename NumberTrait<Element>::Type, int M = 1 + NumberTrait<Element>::depth()>
  class MultiArray;

  // , typename D = typename NumberTrait<Element>::Type, int M = 1 + NumberTrait<Element>::depth()>
  template <class Element, int rank, size_t... sizes>
  class MultiArrayNEW {
  public:
    typedef typename NumberTrait<Element>::Type Number;
    static constexpr int Depth = 1 + NumberTrait<Element>::depth();
  };


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



  template <class X, class Element, class D, int M, int R, class FUNC>
  class
    TER_Unary;

  template <class A, class B, class E1, class E2, class E3, class D1, class D2, class D3, int M1, int M2, int M3, int R1, int R2, int R3, class OP>
  class
    TER_Binary;

  template <class A, class B, class C, class E1, class E2, class E3, class E4, class D1, class D2, class D3, class D4, int M1, int M2, int M3, int M4, int R1, int R2, int R3, int R4, class OP>
  class
    TER_Ternary;

  template <class A, class X, class Element, class D, int M, int R>
  class TER_Series;

  template <class A, class B, class X, class D, class OP1, class OP2>
  class TER_Series2;

  template <class X, class Element, class D, int M, int R, class FUNC>
  class TER_Transpose;

  template <class A, class D>
  class TER_Rep;

  template <class X, class Y, class Element, class D, int M>
  class TER_Join;


  template <class D>
  class TERW_Subset;

  template <class D>
  class TERW_Submask;

  template <class X, class Y, class Element, class D, int M>
  class TERW_Join;

  // *********************************************************************
  // * Class type querying/manipulation
  // ********************************************************************

  // ***************************************************************************
  // Materialize - this returns a concrete tensor of type specified by paramters
  // ***************************************************************************

  template <class Element, class D, int M, int R, int N1 = 0, int N2 = 0>
  class Materialize {
  public:
    typedef MultiArray<Element, R, D, M> TEN;
    typedef Matrix<Element, 0, 0> MAT;
    typedef Vector<Element, 0> VEC;
    typedef Scalar<Element, D, M> SCA;
    typedef typename std::conditional<R == 0, SCA, std::conditional<R == 1, VEC, std::conditional<R == 2, MAT, TEN>>>::type Type;
  };

  template <class Element, class D, int M>
  class Materialize<Element, D, M, 0> {
  public:
    typedef Scalar<Element, D, M> Type;
  };

  template <class Element, class D, int M, int N1>
  class Materialize<Element, D, M, 1, N1> {
  public:
    typedef Vector<Element, N1> Type;
  };

  template <class Element, class D, int M, int N1, int N2>
  class Materialize<Element, D, M, 2, N1, N2> {
  public:
    typedef Matrix<Element, N1, N2> Type;
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
  template <typename X, typename Element, typename D, int M, int R>
  class
    ContainedType<MArrayExpR<X, Element, D, M, R>> {
  public:
    typedef Element Type;
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


  template <class X, class Element, typename D, int M, int R>
  class
    IsMathqContainer<MArrayExpR<X, Element, D, M, R>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <class X, class Element, typename D, int M, int R>
  class
    IsMathqContainer<MArrayExpRW<X, Element, D, M, R>> {
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
  template <class X, class Element, typename D, int M, int R>
  class
    IsMArrayExpRW<MArrayExpRW<X, Element, D, M, R>> {
  public:
    constexpr static bool value = true;
    typedef D RealType;
  };
  template <class X, class Element, typename D, int M, int R>
  class
    IsMArrayExpRW<MArrayExpR<X, Element, D, M, R>> {
  public:
    constexpr static bool value = IsMArrayExpRW<X>::value;
    typedef D RealType;
  };


  // ***************************************************************************
  // OrderedNumberTrait - this operates recursively to find the primitive arithmetic type
  //                   eg int, float, double, ...
  //    NOTE: THis only works for concrete tensors (and for expresssions)
  //          C++ template paramters and specialization does not find subclasses
  // ***************************************************************************

  template <typename T>
  class
    OrderedNumberTrait {
  public:
    typedef T Type;
    constexpr static int depth() {
      return 0;
    }
  };

  template <class Element, template <typename> class T>
  class
    OrderedNumberTrait<T<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };
  template <class Element>
  class
    OrderedNumberTrait<std::complex<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  template <class Element>
  class
    OrderedNumberTrait<Imaginary<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  template <class Element>
  class
    OrderedNumberTrait<Quaternion<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };



  //  Scalar<Element>
  template <class Element>
  class
    OrderedNumberTrait<Scalar<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  //  Vector<Element>
  template <class Element>
  class
    OrderedNumberTrait<Vector<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };
  //  Vector<Element,NE>
  template <class Element, int NE>
  class
    OrderedNumberTrait<Vector<Element, NE>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  //  Matrix<Element>

  template <class Element>
  class
    OrderedNumberTrait<Matrix<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  //  Matrix<Element,NR>

  template <class Element, int NR>
  class
    OrderedNumberTrait<Matrix<Element, NR>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  //  Matrix<Element,NR,NC>

  template <class Element, int NR, int NC>
  class
    OrderedNumberTrait<Matrix<Element, NR, NC>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  //  MultiArray<Element>
  template <class Element>
  class
    OrderedNumberTrait<MultiArray<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  //  MultiArray<Element,R>
  template <class Element, int R>
  class
    OrderedNumberTrait<MultiArray<Element, R>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int depth() {
      return 1 + OrderedNumberTrait<Element>::depth();
    }
  };

  //  MArrayExpR<X,Element,D,M,R>

  template <class X, class Element, class D, int M, int R>
  class
    OrderedNumberTrait<MArrayExpR<X, Element, D, M, R>> {
  public:
    typedef typename OrderedNumberTrait<D>::Type Type;
    constexpr static int depth() {
      return M;
    }
  };



  // ***************************************************************************
  // NumberTrait - this operates recursively to find the base number type
  //              eg. complex<double>, Imaginary<float>, Quaternion<float>, int, double, etc
  //
  //    NOTE: THis only works for concrete tensors (and for expresssions)
  //          C++ template paramters and specialization does not find subclasses
  // ***************************************************************************

  template <typename NewD>
  class
    NumberTrait<Null, NewD> {
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
    NumberTrait<T, NewD, typename std::enable_if<std::is_arithmetic<T>::value>::type> {
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
    NumberTrait<std::complex<D>, NewD> {
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
  class NumberTrait<Imaginary<D>, NewD> {
  public:
    typedef Imaginary<D> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this (use OrderedNumberTrait to change
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
  class NumberTrait<Quaternion<D>, NewD> {
  public:
    typedef Quaternion<D> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this (use OrderedNumberTrait to change
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



  //  Scalar<Element>

  template <class Element, typename NewD>
  class
    NumberTrait<Scalar<Element>, NewD> {
  public:
    typedef Scalar<Element> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef Scalar<typename NumberTrait<Element, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef Scalar<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Vector<Element>

  template <class Element, typename NewD>
  class
    NumberTrait<Vector<Element>, NewD> {
  public:
    typedef Vector<Element> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef Vector<typename NumberTrait<Element, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef Vector<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  Vector<Element,NE>

  template <class Element, typename NewD, int NE>
  class
    NumberTrait<Vector<Element, NE>, NewD> {
  public:
    typedef Vector<Element, NE> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef Vector<typename NumberTrait<Element, NewD>::ReplaceTypeD, NE> ReplaceTypeD;
    typedef Vector<NewD, NE> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Matrix<Element>

  template <class Element, typename NewD>
  class
    NumberTrait<Matrix<Element>, NewD> {
  public:
    typedef Matrix<Element> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef Matrix<typename NumberTrait<Element, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef Matrix<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  Matrix<Element,NR>

  template <class Element, typename NewD, int NR>
  class
    NumberTrait<Matrix<Element, NR>, NewD> {
  public:
    typedef Matrix<Element, NR> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef Matrix<typename NumberTrait<Element, NewD>::ReplaceTypeD, NR> ReplaceTypeD;
    typedef Matrix<NewD, NR> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Matrix<Element,NR,NC>

  template <class Element, typename NewD, int NR, int NC>
  class
    NumberTrait<Matrix<Element, NR, NC>, NewD> {
  public:
    typedef Matrix<Element, NR, NC> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef Matrix<typename NumberTrait<Element, NewD>::ReplaceTypeD, NR, NC> ReplaceTypeD;
    typedef Matrix<NewD, NR, NC> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };



  //  MultiArray<Element>

  template <class Element, typename NewD>
  class
    NumberTrait<MultiArray<Element>, NewD> {
  public:
    typedef MultiArray<Element> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef MultiArray<typename NumberTrait<Element, NewD>::ReplaceTypeD> ReplaceTypeD;
    typedef MultiArray<NewD> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  MultiArray<Element,R>

  template <class Element, typename NewD, int R>
  class
    NumberTrait<MultiArray<Element, R>, NewD> {
  public:
    typedef MultiArray<Element, R> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef MultiArray<typename NumberTrait<Element, NewD>::ReplaceTypeD, R> ReplaceTypeD;
    typedef MultiArray<NewD, R> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int depth() {
      return 1 + NumberTrait<Element, NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };



  //  MArrayExpR<X,Element,D,M,R>

  template <class X, class Element, class D, int M, int R, typename NewD>
  class
    NumberTrait<MArrayExpR<X, Element, D, M, R>, NewD> {
  public:
    typedef MArrayExpR<X, Element, D, M, R> InputType;
    typedef D Type;
    typedef typename NumberTrait<Element, NewD>::ReplaceTypeD NewE;
    typedef typename NumberTrait<X, NewD>::ReplaceTypeD NewX;
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

  //  MArrayExpRW<X,Element,D,M,R>

  template <class X, class Element, class D, int M, int R, typename NewD>
  class
    NumberTrait<MArrayExpRW<X, Element, D, M, R>, NewD> {
  public:
    typedef MArrayExpRW<X, Element, D, M, R> InputType;
    typedef D Type;
    typedef typename NumberTrait<Element, NewD>::ReplaceTypeD NewE;
    typedef typename NumberTrait<X, NewD>::ReplaceTypeD NewX;
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
    typedef typename std::conditional<NumberTrait<T1>::depth() >= NumberTrait<T2>::depth(), T1, T2>::type Type;
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



  //  Scalar<Element>

  template <class Element, class C>
  class
    InversionType<Scalar<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef Scalar<D> MultiArrayD;
    typedef Scalar<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Vector<Element>

  template <class Element, class C>
  class
    InversionType<Vector<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef Vector<D> MultiArrayD;
    typedef Vector<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Vector<Element,NE>
  template <class Element, int NE, class C>
  class
    InversionType<Vector<Element, NE>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef Vector<D, NE> MultiArrayD;
    typedef Vector<C, NE> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<Element>

  template <class Element, class C>
  class
    InversionType<Matrix<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef Matrix<D> MultiArrayD;
    typedef Matrix<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<Element,NR>

  template <class Element, int NR, class C>
  class
    InversionType<Matrix<Element, NR>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef Matrix<D, NR> MultiArrayD;
    typedef Matrix<C, NR> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<Element,NR,NC>

  template <class Element, int NR, int NC, class C>
  class
    InversionType<Matrix<Element, NR, NC>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef Matrix<D, NR, NC> MultiArrayD;
    typedef Matrix<C, NR, NC> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  MultiArray<Element>
  template <class Element, class C>
  class
    InversionType<MultiArray<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef MultiArray<D> MultiArrayD;
    typedef MultiArray<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  MultiArray<Element,R>
  template <class Element, int R, class C>
  class
    InversionType<MultiArray<Element, R>, C> {
  public:
    typedef typename NumberTrait<Element>::Type D;
    typedef MultiArray<D, R> MultiArrayD;
    typedef MultiArray<C, R> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };


  // Can't define InversionType for MArrayExpR nor MArrayExpRW nor any expresssions


  // ***************************************************************************
  // At(x,n) -  for primitives, return x
  //            for container of any type, return x[n]
  // ***************************************************************************

  template <class D>
  inline D&& At(D&& x, size_t n) {
    return x;
  }
  template <class D>
  inline const D&& At(const D&& x, size_t n) {
    return x;
  }
  template <template <class> class T, class D>
  inline D&& At(T<D>&& x, size_t n) {
    return x[n];
  }
  template <template <class> class T, class D>
  inline const D&& At(const T<D>&& x, size_t n) {
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
    typedef typename NumberTrait<DeeperType, NewD>::ReplaceTypeD MultiArrayType;
    constexpr static bool isprim = (NumberTrait<A>::depth() == 0) && (NumberTrait<B>::depth() == 0);
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




  constexpr bool is_all_zeros(std::initializer_list<size_t> list) {
    for (auto elem : list) {
      if (elem != 0) return false;
    }
    return true;
  }
  constexpr bool is_all_nonzero(std::initializer_list<size_t> list) {
    for (auto elem : list) {
      if (elem == 0) return false;
    }
    return true;
  }


  template <typename T, typename ...Ts>
  using areT = std::conjunction<std::is_same<T, Ts>...>;


  template<typename T, std::size_t N>
  constexpr T compile_time_summation(const std::array<T, N>& A) {
    T sum(T(0));
    for (int i = 0; i < N; ++i) {
      sum += A[i];
    }
    return sum;
  }

  template<typename T, std::size_t N>
  constexpr T compile_time_product(const std::array<T, N>& A) {
    T product(T(1));
    for (int i = 0; i < N; ++i) {
      product *= A[i];
    }
    return product;
  }

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
  // * GridScale enum
  // ***************************************************************************

  // put in a namespace so that the enums don't clash
  namespace GridScale {
    enum Type { LINEAR = false, LOG = true };
  };

  using GridScaleEnum = GridScale::Type;



  // ***************************************************************************
  // GridType 
  // ***************************************************************************

  template <class Element, class D, int M, int R>
  class GridType {
  public:
    typedef MultiArray<Element, R, D, M> Type;
  };

  template <class Element, class D, int M>
  class GridType<Element, D, M, 0> {
  public:
    typedef Scalar<Element, D, M> Type;
  };

  template <class Element, class D, int M>
  class GridType<Element, D, M, 1> {
  public:
    typedef Vector<Element, 0> Type;
  };

  template <class Element, class D, int M>
  class GridType<Element, D, M, 2> {
  public:
    typedef Matrix<Element, 0, 0> Type;
  };


  // ***************************************************************************
  // * Grid
  //
  //  multiarray of depth=1 and fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <class D, size_t NDIMS>
  using Grid = typename GridType<D, D, 1, NDIMS>::Type;




  // ***************************************************************************
  // * VectorOfGrids
  //
  // This is a nested structure with M=2:
  //   top level: A single vector of fixed size, Vector<D,NDIMS>
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <class D, size_t NDIMS>
  using VectorOfGrids = Vector<Grid<D, NDIMS>, NDIMS>;


  // ***************************************************************************
  // * GridOfVectors
  //
  // This is a nested structure with M=2:
  //   top level: a single multiarray of fixed rank=NDIMS but dynamic size
  //   second level: Vectors of fixed size, Vector<D,NDIMS>
  //
  // This type has the same total number of elements as VectorOfGrids.
  // The two types can be converted from one to another using the function 'insideout'.
  // ***************************************************************************
  template <class D, size_t NDIMS>
  using GridOfVectors = Grid<Vector<D, NDIMS>, NDIMS>;


  template <class D, size_t NDIMS, bool inv>
  class CG {
  public:
    typedef GridOfVectors<D, NDIMS> Type;
  };

  template <class D, size_t NDIMS>
  class CG<D, NDIMS, true> {
  public:
    typedef VectorOfGrids<D, NDIMS> Type;
  };

  template <class D, size_t NDIMS, bool inv>
  using CG0 = typename CG<D, NDIMS, inv>::Type;



  // ***************************************************************************
  // * MatrixOfGrids
  //
  // This is a nested structure with M=2:
  //   top level: A single square matrix of fixed size, Matrix<D,NDIMS,NDIMS>
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <class D, size_t NDIMS>
  using MatrixOfGrids = Matrix<Grid<D, NDIMS>, NDIMS, NDIMS>;


  // ***************************************************************************
  // * GridOfMatrixs
  //
  // This is a nested structure with M=2:
  //   top level: a single multiarray of fixed rank=NDIMS but dynamic size
  //   second level: A single square matrix of fixed size, Matrix<D,NDIMS,NDIMS>
  //
  // This type has the same total number of elements as MatrixOfGrids.
  // The two types can be converted from one to another using the function 'insideout'.
  // ***************************************************************************
  template <class D, size_t NDIMS>
  using GridOfMatrixs = typename Grid<Matrix<D, NDIMS, NDIMS>, NDIMS>::Type;



  template <class D, size_t NDIMS, size_t RANK>
  class TensorOfGrids {
  public:
    typedef MultiArray<Grid<D, NDIMS>, RANK> Type;   // need to specify dimensiosn dynamically
  };

  template <class D, size_t NDIMS>
  class TensorOfGrids<D, NDIMS, 0> {
  public:
    typedef Grid<D, NDIMS> Type;
  };

  template <class D, size_t NDIMS>
  class TensorOfGrids<D, NDIMS, 1> {
  public:
    typedef VectorOfGrids<D, NDIMS> Type;
  };

  template <class D, size_t NDIMS>
  class TensorOfGrids<D, NDIMS, 2> {
  public:
    typedef MatrixOfGrids<D, NDIMS> Type;
  };


  // ***************************************************************************
  // * RealSet 
  // ***************************************************************************

  template <class D>
  class RealSet;


  // ***************************************************************************
  // * RealMultiSet 
  // ***************************************************************************
  template <class D, size_t NDIMS = 0, class MULTIGRID = VectorOfGrids<D, NDIMS>>
  class RealMultiSet;


  // ***************************************************************************
  // * CurvilinearCoordinateSystem 
  // ***************************************************************************
  template <class D, size_t NDIMS, typename CHILD>
  class CurvilinearCoordinateSystem;


  template <class Element, size_t NDIMS, class CHILD> class CurvilinearCoords;
  template <class Element, size_t NDIMS> class CartCoords;
  template <class Element> class PolarCoords;




  // ***************************************************************************
  // * nabla object
  // ***************************************************************************

  template <class T = void>
  class Nabla {
  public:
    const unsigned int Nwindow;
  public:
    Nabla(const unsigned int Nwindow = 7) :
      Nwindow(Nwindow) {
    }
    ~Nabla() {
    }
  };



  ////////////////////////////////////////////////////////////
  // In functions_misc.h
  ////////////////////////////////////////////////////////////

  template <class X, class Element, class D, int M, int R>
  EnableMethodIf<std::is_same<D, bool>::value, Vector<size_t>&> findtrue(const MArrayExpR<X, Element, D, M, R>& v);




}; // namespace mathq






#endif
