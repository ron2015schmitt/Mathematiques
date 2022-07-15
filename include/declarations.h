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

  using signed_t = typename std::make_signed<size_t>::type;


  // TODO: need to figure out how to handle this. need a signed type
  // maximum subcript size for vectors and matrices (since we allow negative indexing)
  const size_t maxsize = std::numeric_limits<size_t>::max();
  const size_t badsize = std::numeric_limits<size_t>::max();


  // ***************************************************************************
  // Dimensions classes
  // ***************************************************************************

  template <size_t rank_ = 0>
  class Dimensions;
  class ScalarDimensions;
  class NullDimensions;


  template<size_t depth_ = 0>
  class RecursiveDimensions;

  template<typename Element, int L>
  class NestedInitializerListDef;


  class VectorofPtrs;

  template <class DAT> class Pair;

  class Indices;



  class Indices;

  inline bool equiv(const Indices& inds1, const Indices& inds2);

  template <typename RecursiveDimensions>
  class DeepIndices;

  template<typename Element, int L>
  class NestedInitializerListDef;

  //*******************************************************
  //          Trait classes
  //*******************************************************

  template <typename T, typename NewNumber = T, typename dummy = void>
  class NumberTrait;




  template <typename T, typename B = void> T zero();
  template <typename T, typename B = void> T one();


  //*******************************************************
  //          number types
  //*******************************************************

  template <typename SimpleNumber>
  class Imaginary;

  template <typename SimpleNumber>
  class Quaternion;




  // *********************************************************************
  // * MultiArray Expressions
  // ********************************************************************

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank>
  class ExpressionR;
  template <class Derived, typename Element, typename Number, size_t depth, size_t rank>
  class ExpressionRW;


  // *********************************************************************
  // * Concrete MultiArrays
  // ********************************************************************

  //   constexpr bool is_all_zeros(std::initializer_list<size_t> list) {
  //   for (auto elem : list) {
  //     if (elem != 0) return false;
  //   }
  //   return true;
  // }


  template<size_t rank, size_t... ints>
  constexpr bool validate_multi_array() {
    constexpr size_t N = sizeof...(ints);
    constexpr std::array<size_t, N> A = { (static_cast<size_t>(ints))... };

    if constexpr ((N == 1) && (A[0] == 0)) {
      return true;
    }
    if constexpr (N != rank) {
      return false;
    }
    for (size_t i = 0; i < N; ++i) {
      if (A[i] == 0) return false;
    }
    return true;
  }


  template <typename Element, size_t rank, size_t... dim_ints > requires (validate_multi_array<rank, dim_ints...>())
  class MultiArray;



  // typenames for specializations


  template <typename Element>
  using Scalar = MultiArray<Element, 0>;


  template <typename Element, size_t N1 = 0>
  using Vector = MultiArray<Element, 1, N1>;

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
  class ExpressionR_Unary;

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t D1, size_t D2, size_t D3, size_t R1, size_t R2, size_t R3, class OP>
  class ExpressionR_Binary;

  template <class A, class B, class C, class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class D4, size_t D1, size_t D2, size_t D3, size_t M4, size_t R1, size_t R2, size_t R3, size_t R4, class OP>
  class ExpressionR_Ternary;

  template <class A, class X, typename Element, typename Number, size_t depth, size_t rank>
  class ExpressionR_Series;

  template <class A, class B, class X, typename Number, class OP1, class OP2>
  class ExpressionR_Series2;

  template <class A, typename Element, typename Number, size_t depth, size_t rank, class FUNC>
  class ExpressionR_Transpose;

  template <class A, typename Number>
  class ExpressionR_Rep;

  template <class X, class Y, typename Element, typename Number, size_t depth>
  class ExpressionR_Join;

  template <typename Number>
  class ExpressionRW_Subset;

  template <typename Number>
  class ExpressionRW_Submask;

  template <class X, class Y, typename Element, typename Number, size_t depth>
  class ExpressionRW_Join;


  // ***************************************************************************
  // * GridScale enum
  // ***************************************************************************

  // put in a namespace so that the enums don't clash
  namespace GridScale {
    enum Type { LINEAR = false, LOG = true };
  };

  using GridScaleEnum = GridScale::Type;





  // ***************************************************************************
  // * Grid
  //
  //  multiarray of depth=1 and fixed rank=NDIMS but dynamic size
  // ***************************************************************************

  template <typename Number, size_t NDIMS>
  using Grid = MultiArray<Number, NDIMS>;




  // ***************************************************************************
  // * MultiArrayOfGrids
  //
  // This is a nested structure with depth=2:
  //   top level: A single MultiArray of fixed rank: MultiArray<Number,rank>
  //              default rank = 1 => vector
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  //
  // TODO: use OuterProductMultiArray for 2nd level to save on space
  // ***************************************************************************

  template <typename Number, size_t NDIMS, size_t rank = 1>
  using MultiArrayOfGrids = MultiArray< Grid<Number, NDIMS>, rank >;


  // ***************************************************************************
  // * GridOfMultiArrays
  //
  // This is a nested structure with depth=2:
  //   top level: a single multiarray of fixed rank=NDIMS but dynamic size
  //   second level: multiarrays of fixed rank: MultiArray<Number,rank>
  //                 default rank = 1 => vector
  //
  // This type has the same total number of elements as MultiArrayOfGrids.
  // The two types can be converted from one to another using the function 'insideout'.
  //
  // TODO: use OuterProductMultiArray for 1st level to save on space
  // ***************************************************************************

  template <typename Number, size_t NDIMS, size_t rank = 1>
  using GridOfMultiArrays = Grid< MultiArray<Number, rank>, NDIMS>;




  template <typename Number, size_t NDIMS, size_t rank, typename G>
  class GridTraits;

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  Vector<size_t>& findtrue(const ExpressionR<X, Element, Number, depth, rank>& x);

}; // namespace mathq




#endif
