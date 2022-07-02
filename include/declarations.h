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
  inline std::string bracketAndStyleTypename(const T& var);
  template <typename T>
  inline void dispval_strm(std::ostream& stream, const T& d);
}; // namespace display


namespace mathq {


  class NullType;



  //*******************************************************
  //          Trait classes
  //*******************************************************

  template <typename T, typename NewNumber = double, typename dummy = void>
  class NumberTrait;


  //*******************************************************
  //          number types
  //*******************************************************

  template <typename SimpleNumber>
  class Imaginary;

  template <typename SimpleNumber>
  class Quaternion;


  // ***************************************************************************
  // Dimensions classes
  // ***************************************************************************

  template<size_t Rank, class Derived>
  class Dimensions;

  template<size_t... dims>
  class FixedDims;

  template<size_t Rank>
  class DynamicDims;

  class NullDims;

  template<typename Dims, typename NextDims = NullDims>
  class NestedDims;


  // *********************************************************************
  // * MultiArray Expressions
  // ********************************************************************

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class MArrayExpR;
  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class MArrayExpRW;


  // *********************************************************************
  // * Concrete MultiArrays
  // ********************************************************************

  template <typename Element, size_t rank, size_t... dims>
  class MultiArray;

  // typenames for specializations

  template <typename Element>
  using Scalar = MultiArray<Element, 0>;

  template <typename Element, size_t NE = 0>
  using Vector = MultiArray<Element, 1, NE>;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  using Matrix = MultiArray<Element, 2, NR, NC>;

  template <typename Element, size_t N1 = 0, size_t N2 = 0, size_t N3 = 0>
  using MultiArray3 = MultiArray<Element, 3, N1, N2, N3>;

  template <typename Element, size_t N1 = 0, size_t N2 = 0, size_t N3 = 0, size_t N4 = 0>
  using MultiArray4 = MultiArray<Element, 4, N1, N2, N3, N4>;




  // *********************************************************************
  // * Special Matrices
  // ********************************************************************

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixZero;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixIdentity;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixExchange;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixConstDiag;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixDiagonal;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixRevDiag;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixRepCol;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixRepRow;

  template <typename Element>
  class MatrixRepRowAndCol;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixVandermonde;

  template <typename Element, size_t NR = 0, size_t NC = 0>
  class MatrixToeplitz;

  template <typename Element, size_t N = 0>
  class MatrixUpperTriangle;

  template <typename Element, size_t N = 0>
  class MatrixLowerTriangle;

  template <typename Element, size_t N = 0>
  class MatrixSymmetric;

  template <typename Element, size_t N = 0>
  class MatrixSkewSymmetric;

  template <typename Element, size_t N = 0>
  class MatrixHermitian;

  template <typename Element, size_t N = 0>
  class MatrixSkewHermitian;



  // *********************************************************************
  // * Expressions
  // ********************************************************************

  template <class A, typename Element, typename Number, size_t depth, size_t rank, class FUNC>
  class TER_Unary;

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t D1, size_t D2, size_t D3, size_t R1, size_t R2, size_t R3, class OP>
  class TER_Binary;

  template <class A, class B, class C, class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class D4, size_t D1, size_t D2, size_t D3, size_t M4, size_t R1, size_t R2, size_t R3, size_t R4, class OP>
  class TER_Ternary;

  template <class A, class X, typename Element, typename Number, size_t depth, size_t rank>
  class TER_Series;

  template <class A, class B, class X, typename Number, class OP1, class OP2>
  class TER_Series2;

  template <class A, typename Element, typename Number, size_t depth, size_t rank, class FUNC>
  class TER_Transpose;

  template <class A, typename Number>
  class TER_Rep;

  template <class X, class Y, typename Element, typename Number, size_t depth>
  class TER_Join;

  template <typename Number>
  class TERW_Subset;

  template <typename Number>
  class TERW_Submask;

  template <class X, class Y, typename Element, typename Number, size_t depth>
  class TERW_Join;




  template <typename Number, size_t NDIMS, size_t rank, typename G>
  class GridTraits;

  ////////////////////////////////////////////////////////////
  // In functions_misc.h
  ////////////////////////////////////////////////////////////

  // template <class Derived, typename Element, typename Number, size_t depth_, size_t rank, class DimensionsT>
  // EnableMethodIf<std::is_same<Number, bool>::value, Vector<size_t>&> findtrue(const MArrayExpR<Derived, Element, Number, depth_, rank, DimensionsT>& v);



}; // namespace mathq




#endif
