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


  template <typename Number>
  class Imaginary;

  template <typename Number>
  class Quaternion;

  template <typename T, typename NUM = double, typename H = void>
  class NumberTrait;


  // Element = element type (int, double, complex<double>, bool, Scalar<double>, Vector<double>, Matrix<double>, etc)
  // Number = underlying ordered field (orderable-number) type (int, double, complex<double>, bool, etc)

  template <class X, class Element, typename Number, int depth, int rank>
  class MArrayExpR;
  template <class X, class Element, typename Number, int depth, int rank>
  class MArrayExpRW;





  // *********************************************************************
  // * Concrete MultiArrays
  // ********************************************************************



  template <class Element, typename Number = typename NumberTrait<Element>::Type, int depth = 1 + NumberTrait<Element>::getDepth()>
  class Scalar;

  template <class Element, int NE = 0>
  class Vector;

  template <class Element, int NR = 0, int NC = 0>
  class Matrix;

  template <class Element, int rank = 0, typename Number = typename NumberTrait<Element>::Type, int depth = 1 + NumberTrait<Element>::getDepth()>
  class MultiArray;

  // , typename Number = typename NumberTrait<Element>::Type, int depth = 1 + NumberTrait<Element>::getDepth()>
  template <class Element, int rank, size_t... sizes>
  class MultiArrayNEW {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    static constexpr int depth = 1 + NumberTrait<Element>::getDepth();
  };


  // *********************************************************************
  // * Special Matrices
  // ********************************************************************


  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixZero;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixIdentity;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixExchange;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixConstDiag;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixDiagonal;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixRevDiag;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixRepCol;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixRepRow;


  template <typename Number>
  class
    MatrixRep;

  // put in a namespace so that the enums don't clash
  namespace MatrixRepTypes {
    enum Type { REPEAT_ROW, REPEAT_COLUMN };
  };

  using MatrixRepEnum = MatrixRepTypes::Type;


  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixVandermonde;

  template <typename Number, int NR = 0, int NC = 0>
  class
    MatrixToeplitz;

  template <typename Number, int N = 0>
  class
    MatrixUpperTriangle;

  template <typename Number, int N = 0>
  class
    MatrixLowerTriangle;

  template <typename Number, int N = 0>
  class
    MatrixSymmetric;

  template <typename Number, int N = 0>
  class
    MatrixSkewSymmetric;

  template <typename Number, int N = 0>
  class
    MatrixHermitian;

  template <typename Number, int N = 0>
  class
    MatrixSkewHermitian;

  // *********************************************************************
  // * Expressions
  // ********************************************************************



  template <class X, class Element, typename Number, int depth, int rank, class FUNC>
  class
    TER_Unary;

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class D3, int M1, int M2, int M3, int R1, int R2, int R3, class OP>
  class
    TER_Binary;

  template <class A, class B, class C, class E1, class E2, class E3, class E4, class NT1, class NT2, class D3, class D4, int M1, int M2, int M3, int M4, int R1, int R2, int R3, int R4, class OP>
  class
    TER_Ternary;

  template <class A, class X, class Element, typename Number, int depth, int rank>
  class TER_Series;

  template <class A, class B, class X, typename Number, class OP1, class OP2>
  class TER_Series2;

  template <class X, class Element, typename Number, int depth, int rank, class FUNC>
  class TER_Transpose;

  template <class A, typename Number>
  class TER_Rep;

  template <class X, class Y, class Element, typename Number, int depth>
  class TER_Join;


  template <typename Number>
  class TERW_Subset;

  template <typename Number>
  class TERW_Submask;

  template <class X, class Y, class Element, typename Number, int depth>
  class TERW_Join;

  // *********************************************************************
  // * Class type querying/manipulation
  // ********************************************************************

  // ***************************************************************************
  // Materialize - this returns a concrete tensor of type specified by paramters
  // ***************************************************************************

  template <class Element, typename Number, int depth, int rank, int N1 = 0, int N2 = 0>
  class Materialize {
  public:
    typedef MultiArray<Element, rank, Number, depth> TEN;
    typedef Matrix<Element, 0, 0> MAT;
    typedef Vector<Element, 0> VEC;
    typedef Scalar<Element, Number, depth> SCA;
    typedef typename std::conditional<rank == 0, SCA, std::conditional<rank == 1, VEC, std::conditional<rank == 2, MAT, TEN>>>::type Type;
  };

  template <class Element, typename Number, int depth>
  class Materialize<Element, Number, depth, 0> {
  public:
    typedef Scalar<Element, Number, depth> Type;
  };

  template <class Element, typename Number, int depth, int N1>
  class Materialize<Element, Number, depth, 1, N1> {
  public:
    typedef Vector<Element, N1> Type;
  };

  template <class Element, typename Number, int depth, int N1, int N2>
  class Materialize<Element, Number, depth, 2, N1, N2> {
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
  template <typename Number>
  class
    ContainedType<std::complex<Number>> {
  public:
    typedef Number Type;
  };

  template <typename Number>
  class
    ContainedType<Imaginary<Number>> {
  public:
    typedef Number Type;
  };

  template <typename Number>
  class
    ContainedType<Quaternion<Number>> {
  public:
    typedef Number Type;
  };

  template <template <typename> class T, typename Number>
  class
    ContainedType<T<Number>> {
  public:
    typedef Number Type;
  };
  template <typename X, typename Element, typename Number, int depth, int rank>
  class
    ContainedType<MArrayExpR<X, Element, Number, depth, rank>> {
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
  template <typename Number>
  class
    IsComplex<std::complex<Number>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
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
  template <typename Number>
  class
    IsImaginary<mathq::Imaginary<Number>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
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
  template <typename Number>
  class
    IsQuaternion<mathq::Quaternion<Number>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
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

  template <typename Number>
  class
    IsMathqContainer<Scalar<Number>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };

  template <typename Number>
  class
    IsMathqContainer<Vector<Number>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };
  template <typename Number, int NE>
  class
    IsMathqContainer<Vector<Number, NE>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };

  template <typename Number>
  class
    IsMathqContainer<Matrix<Number>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };
  template <typename Number, int NR>
  class
    IsMathqContainer<Matrix<Number, NR>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };
  template <typename Number, int NR, int NC>
  class
    IsMathqContainer<Matrix<Number, NR, NC>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };

  template <typename Number>
  class
    IsMathqContainer<MultiArray<Number>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };
  template <typename Number, int rank>
  class
    IsMathqContainer<MultiArray<Number, rank>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };


  template <class X, class Element, typename Number, int depth, int rank>
  class
    IsMathqContainer<MArrayExpR<X, Element, Number, depth, rank>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };
  template <class X, class Element, typename Number, int depth, int rank>
  class
    IsMathqContainer<MArrayExpRW<X, Element, Number, depth, rank>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
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
  template <class X, class Element, typename Number, int depth, int rank>
  class
    IsMArrayExpRW<MArrayExpRW<X, Element, Number, depth, rank>> {
  public:
    constexpr static bool value = true;
    typedef Number RealType;
  };
  template <class X, class Element, typename Number, int depth, int rank>
  class
    IsMArrayExpRW<MArrayExpR<X, Element, Number, depth, rank>> {
  public:
    constexpr static bool value = IsMArrayExpRW<X>::value;
    typedef Number RealType;
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
    constexpr static int getDepth() {
      return 0;
    }
  };

  template <class Element, template <typename> class T>
  class
    OrderedNumberTrait<T<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };
  template <class Element>
  class
    OrderedNumberTrait<std::complex<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  template <class Element>
  class
    OrderedNumberTrait<Imaginary<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  template <class Element>
  class
    OrderedNumberTrait<Quaternion<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };



  //  Scalar<Element>
  template <class Element>
  class
    OrderedNumberTrait<Scalar<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  //  Vector<Element>
  template <class Element>
  class
    OrderedNumberTrait<Vector<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };
  //  Vector<Element,NE>
  template <class Element, int NE>
  class
    OrderedNumberTrait<Vector<Element, NE>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  //  Matrix<Element>

  template <class Element>
  class
    OrderedNumberTrait<Matrix<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  //  Matrix<Element,NR>

  template <class Element, int NR>
  class
    OrderedNumberTrait<Matrix<Element, NR>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  //  Matrix<Element,NR,NC>

  template <class Element, int NR, int NC>
  class
    OrderedNumberTrait<Matrix<Element, NR, NC>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  //  MultiArray<Element>
  template <class Element>
  class
    OrderedNumberTrait<MultiArray<Element>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  //  MultiArray<Element,rank>
  template <class Element, int rank>
  class
    OrderedNumberTrait<MultiArray<Element, rank>> {
  public:
    typedef typename OrderedNumberTrait<Element>::Type Type;
    constexpr static int getDepth() {
      return 1 + OrderedNumberTrait<Element>::getDepth();
    }
  };

  //  MArrayExpR<X,Element,Number,depth,rank>

  template <class X, class Element, typename Number, int depth, int rank>
  class
    OrderedNumberTrait<MArrayExpR<X, Element, Number, depth, rank>> {
  public:
    typedef typename OrderedNumberTrait<Number>::Type Type;
    constexpr static int getDepth() {
      return depth;
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
    constexpr static int getDepth() {
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
    constexpr static int getDepth() {
      return 0;
    }
    inline static int size(const T x) {
      return 1;
    }
    inline static int deepsize(const T& x) {
      return 1;
    }
  };

  template <typename Number, typename NewD>
  class
    NumberTrait<std::complex<Number>, NewD> {
  public:
    typedef std::complex<Number> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this
    constexpr static bool value = true;
    constexpr static int getDepth() {
      return 0;
    }
    inline static int size(const std::complex<Number> x) {
      return 1;
    }
    inline static int deepsize(const std::complex<Number> x) {
      return 1;
    }
  };

  template <typename Number, typename NewD>
  class NumberTrait<Imaginary<Number>, NewD> {
  public:
    typedef Imaginary<Number> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this (use OrderedNumberTrait to change
    constexpr static bool value = true;
    constexpr static int getDepth() {
      return 0;
    }
    inline static int size(const Imaginary<Number> x) {
      return 1;
    }
    inline static int deepsize(const Imaginary<Number> x) {
      return 1;
    }
  };

  template <typename Number, typename NewD>
  class NumberTrait<Quaternion<Number>, NewD> {
  public:
    typedef Quaternion<Number> Type;
    typedef NewD ReplaceTypeD;
    typedef NewD ReplaceTypeE; // DONT modify this (use OrderedNumberTrait to change
    constexpr static bool value = true;
    constexpr static int getDepth() {
      return 0;
    }
    inline static int size(const Quaternion<Number> x) {
      return 1;
    }
    inline static int deepsize(const Quaternion<Number> x) {
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
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
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
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
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
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
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
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
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
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
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
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
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
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  MultiArray<Element,rank>

  template <class Element, typename NewD, int rank>
  class
    NumberTrait<MultiArray<Element, rank>, NewD> {
  public:
    typedef MultiArray<Element, rank> InputType;
    typedef typename NumberTrait<Element>::Type Type;
    typedef MultiArray<typename NumberTrait<Element, NewD>::ReplaceTypeD, rank> ReplaceTypeD;
    typedef MultiArray<NewD, rank> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int getDepth() {
      return 1 + NumberTrait<Element, NewD>::getDepth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };



  //  MArrayExpR<X,Element,Number,depth,rank>

  template <class X, class Element, typename Number, int depth, int rank, typename NewD>
  class
    NumberTrait<MArrayExpR<X, Element, Number, depth, rank>, NewD> {
  public:
    typedef MArrayExpR<X, Element, Number, depth, rank> InputType;
    typedef Number Type;
    typedef typename NumberTrait<Element, NewD>::ReplaceTypeD NewE;
    typedef typename NumberTrait<X, NewD>::ReplaceTypeD NewX;
    typedef NewX ReplaceTypeD;
    typedef MArrayExpR<X, NewD, Number, depth, rank> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int getDepth() {
      return depth;
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  MArrayExpRW<X,Element,Number,depth,rank>

  template <class X, class Element, typename Number, int depth, int rank, typename NewD>
  class
    NumberTrait<MArrayExpRW<X, Element, Number, depth, rank>, NewD> {
  public:
    typedef MArrayExpRW<X, Element, Number, depth, rank> InputType;
    typedef Number Type;
    typedef typename NumberTrait<Element, NewD>::ReplaceTypeD NewE;
    typedef typename NumberTrait<X, NewD>::ReplaceTypeD NewX;
    typedef NewX ReplaceTypeD;
    typedef MArrayExpRW<X, NewD, Number, depth, rank> ReplaceTypeE;
    constexpr static bool value = false;
    constexpr static int getDepth() {
      return depth;
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
    typedef typename std::conditional<NumberTrait<T1>::getDepth() >= NumberTrait<T2>::getDepth(), T1, T2>::type Type;
  };


  // ***************************************************************************
  // InversionType - turnt he type inside out
  //    example:  Vector<Scalar<double>>   ->   Scalar<Vector<double>>
  //
  //    NOTE: THis only works for concrete tensors (and for expresssions)
  // ***************************************************************************


  template <typename Number, class C>
  class
    InversionType {
  public:
    typedef C Type;
  };
  template <typename Number, class C>
  class
    InversionType<std::complex<Number>, C> {
  public:
    typedef C Type;
  };
  template <typename Number, class C>
  class
    InversionType<Imaginary<Number>, C> {
  public:
    typedef C Type;
  };

  template <typename Number, class C>
  class
    InversionType<Quaternion<Number>, C> {
  public:
    typedef C Type;
  };



  //  Scalar<Element>

  template <class Element, class C>
  class
    InversionType<Scalar<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef Scalar<NumberType> MultiArrayD;
    typedef Scalar<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Vector<Element>

  template <class Element, class C>
  class
    InversionType<Vector<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef Vector<NumberType> MultiArrayD;
    typedef Vector<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Vector<Element,NE>
  template <class Element, int NE, class C>
  class
    InversionType<Vector<Element, NE>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef Vector<NumberType, NE> MultiArrayD;
    typedef Vector<C, NE> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<Element>

  template <class Element, class C>
  class
    InversionType<Matrix<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef Matrix<NumberType> MultiArrayD;
    typedef Matrix<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<Element,NR>

  template <class Element, int NR, class C>
  class
    InversionType<Matrix<Element, NR>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef Matrix<NumberType, NR> MultiArrayD;
    typedef Matrix<C, NR> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  Matrix<Element,NR,NC>

  template <class Element, int NR, int NC, class C>
  class
    InversionType<Matrix<Element, NR, NC>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef Matrix<NumberType, NR, NC> MultiArrayD;
    typedef Matrix<C, NR, NC> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  MultiArray<Element>
  template <class Element, class C>
  class
    InversionType<MultiArray<Element>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef MultiArray<NumberType> MultiArrayD;
    typedef MultiArray<C> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };

  //  MultiArray<Element,rank>
  template <class Element, int rank, class C>
  class
    InversionType<MultiArray<Element, rank>, C> {
  public:
    typedef typename NumberTrait<Element>::Type NumberType;
    typedef MultiArray<NumberType, rank> MultiArrayD;
    typedef MultiArray<C, rank> MultiArrayC;
    typedef typename std::conditional<std::is_same<C, Null>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type>::type Type;
  };


  // Can't define InversionType for MArrayExpR nor MArrayExpRW nor any expresssions


  // ***************************************************************************
  // At(x,n) -  for primitives, return x
  //            for container of any type, return x[n]
  // ***************************************************************************

  template <typename Number>
  inline Number&& At(Number&& x, size_t n) {
    return x;
  }
  template <typename Number>
  inline const Number&& At(const Number&& x, size_t n) {
    return x;
  }
  template <template <class> class T, typename Number>
  inline Number&& At(T<Number>&& x, size_t n) {
    return x[n];
  }
  template <template <class> class T, typename Number>
  inline const Number&& At(const T<Number>&& x, size_t n) {
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
    constexpr static bool isprim = (NumberTrait<A>::getDepth() == 0) && (NumberTrait<B>::getDepth() == 0);
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
  template <typename NT1, typename DOUT>
  class FunctionType1 {
  public:
    typedef DOUT(type)(NT1);
  };
  template <typename NT1, typename NT2, typename DOUT>
  class FunctionType2 {
  public:
    typedef DOUT(type)(NT1, NT2);
  };
  template <typename NT1, typename NT2, typename D3, typename DOUT>
  class FunctionType3 {
  public:
    typedef DOUT(type)(NT1, NT2, D3);
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

  template <class Element, typename Number, int depth, int rank>
  class GridType {
  public:
    typedef MultiArray<Element, rank, Number, depth> Type;
  };

  template <class Element, typename Number, int depth>
  class GridType<Element, Number, depth, 0> {
  public:
    typedef Scalar<Element, Number, depth> Type;
  };

  template <class Element, typename Number, int depth>
  class GridType<Element, Number, depth, 1> {
  public:
    typedef Vector<Element, 0> Type;
  };

  template <class Element, typename Number, int depth>
  class GridType<Element, Number, depth, 2> {
  public:
    typedef Matrix<Element, 0, 0> Type;
  };


  // ***************************************************************************
  // * Grid
  //
  //  multiarray of depth=1 and fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <typename Number, size_t NDIMS>
  using Grid = typename GridType<Number, Number, 1, NDIMS>::Type;




  // ***************************************************************************
  // * VectorOfGrids
  //
  // This is a nested structure with depth=2:
  //   top level: A single vector of fixed size, Vector<Number,NDIMS>
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <typename Number, size_t NDIMS>
  using VectorOfGrids = Vector<Grid<Number, NDIMS>, NDIMS>;


  // ***************************************************************************
  // * GridOfVectors
  //
  // This is a nested structure with depth=2:
  //   top level: a single multiarray of fixed rank=NDIMS but dynamic size
  //   second level: Vectors of fixed size, Vector<Number,NDIMS>
  //
  // This type has the same total number of elements as VectorOfGrids.
  // The two types can be converted from one to another using the function 'insideout'.
  // ***************************************************************************
  template <typename Number, size_t NDIMS>
  using GridOfVectors = Grid<Vector<Number, NDIMS>, NDIMS>;


  template <typename Number, size_t NDIMS, bool inv>
  class CG {
  public:
    typedef GridOfVectors<Number, NDIMS> Type;
  };

  template <typename Number, size_t NDIMS>
  class CG<Number, NDIMS, true> {
  public:
    typedef VectorOfGrids<Number, NDIMS> Type;
  };

  template <typename Number, size_t NDIMS, bool inv>
  using CG0 = typename CG<Number, NDIMS, inv>::Type;



  // ***************************************************************************
  // * MatrixOfGrids
  //
  // This is a nested structure with depth=2:
  //   top level: A single square matrix of fixed size, Matrix<Number,NDIMS,NDIMS>
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <typename Number, size_t NDIMS>
  using MatrixOfGrids = Matrix<Grid<Number, NDIMS>, NDIMS, NDIMS>;


  // ***************************************************************************
  // * GridOfMatrixs
  //
  // This is a nested structure with depth=2:
  //   top level: a single multiarray of fixed rank=NDIMS but dynamic size
  //   second level: A single square matrix of fixed size, Matrix<Number,NDIMS,NDIMS>
  //
  // This type has the same total number of elements as MatrixOfGrids.
  // The two types can be converted from one to another using the function 'insideout'.
  // ***************************************************************************
  template <typename Number, size_t NDIMS>
  using GridOfMatrixs = typename Grid<Matrix<Number, NDIMS, NDIMS>, NDIMS>::Type;



  template <typename Number, size_t NDIMS, size_t RANK>
  class TensorOfGrids {
  public:
    typedef MultiArray<Grid<Number, NDIMS>, RANK> Type;   // need to specify dimensiosn dynamically
  };

  template <typename Number, size_t NDIMS>
  class TensorOfGrids<Number, NDIMS, 0> {
  public:
    typedef Grid<Number, NDIMS> Type;
  };

  template <typename Number, size_t NDIMS>
  class TensorOfGrids<Number, NDIMS, 1> {
  public:
    typedef VectorOfGrids<Number, NDIMS> Type;
  };

  template <typename Number, size_t NDIMS>
  class TensorOfGrids<Number, NDIMS, 2> {
  public:
    typedef MatrixOfGrids<Number, NDIMS> Type;
  };


  // ***************************************************************************
  // * RealSet 
  // ***************************************************************************

  template <typename Number>
  class RealSet;


  // ***************************************************************************
  // * RealMultiSet 
  // ***************************************************************************
  template <typename Number, size_t NDIMS = 0, class MULTIGRID = VectorOfGrids<Number, NDIMS>>
  class RealMultiSet;


  // ***************************************************************************
  // * CurvilinearCoordinateSystem 
  // ***************************************************************************
  template <typename Number, size_t NDIMS, typename CHILD>
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

  template <class X, class Element, typename Number, int depth, int rank>
  EnableMethodIf<std::is_same<Number, bool>::value, Vector<size_t>&> findtrue(const MArrayExpR<X, Element, Number, depth, rank>& v);




}; // namespace mathq






#endif
