#ifndef MATHQ__PREFACE
#define MATHQ__PREFACE

// see the following for C++20 features (C++20 has not yet been implemented in full)
// https://en.cppreference.com/w/cpp/utility/feature_test
// https://en.cppreference.com/w/cpp/feature_test
// __cplusplus doesn't go from 2017 to 2020 until g++ v11
// https://gcc.gnu.org/releases.html
// https://gcc.gnu.org/projects/cxx-status.html


#define CPP11 (__cplusplus >= 201100L)
#define CPP14 (__cplusplus >= 201400L)
#define CPP17 (__cplusplus >= 201700L)

#define _stringify(...) #__VA_ARGS__
#define stringify(...) _stringify(__VA_ARGS__)



#define DO_EXPAND(VAL) 99##VAL
#define EXPAND(VAL) DO_EXPAND(VAL)
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

  class Dimensions;
  class ScalarDimensions;
  class NullDimensions;
  class RecursiveDimensions;

  class Indices;
  class DeepIndices;
  template <typename T = size_t> class slc;

  inline bool equiv(const Indices& inds1, const Indices& inds2);

  class VectorofPtrs;
  template <class DAT> class Pair;

  //*******************************************************
  //          Trait classes
  //*******************************************************

  template <typename T>
  class NumberTrait;

  template <typename T, typename NewNumber>
  class ReplacedNumberTrait;

  template <typename T>
  class SimpleNumberTrait;



  //*******************************************************
  //          number types
  //*******************************************************

  template <typename SimpleNum>
  class Imaginary;

  template <typename SimpleNum>
  class Quaternion;




  // *********************************************************************
  // * MultiArray Expressions
  // ********************************************************************

  template <class Derived, typename Element, typename Num, size_t depth, size_t rank>
  class ExpressionR;
  template <class Derived, typename Element, typename Num, size_t depth, size_t rank>
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


  template<size_t rank, size_t... sizes>
  constexpr bool validate_multi_array() {
    constexpr size_t N = sizeof...(sizes);
    constexpr std::array<size_t, N> A = { (static_cast<size_t>(sizes))... };

    if constexpr (N == 0) {
      return true;
    }
    // if constexpr ((N == 1) && (A[0] == 0)) {
    //   return true;
    // }
    if constexpr (N != rank) {
      return false;
    }
    for (size_t i = 0; i < N; ++i) {
      if (A[i] == 0) return false;
    }
    return true;
  }


  template<size_t rank1, size_t rank2, size_t... ints>
  constexpr bool multi_array_compatibility() {

    constexpr size_t N = sizeof...(ints);
    constexpr std::array<size_t, N> A = { (static_cast<size_t>(ints))... };

    // what about for multiarrays that have dimensions of size one, ie reduced?
    if constexpr (rank1 != rank2) {
      return false;
    }

    constexpr size_t rank = rank1;
    if constexpr (N == 2*rank) {
      // both arrays are fixed-dimensions
      for (size_t i = 0; i < rank; ++i) {
        if (A[i] != A[i+rank]) return false;
      }
      return true;
    }
    else if constexpr ((N == rank)) {
      // one array is fixed-dimensions. the other array is dynamic
      return true;
    }
    else if constexpr (N == 0) {
      // both arrays are dynamic-dimensions
      return true;
    }
    return false;
  }



  // *********************************************************************
  // * MultiArrays
  // ********************************************************************

  template <typename Element, size_t rank, size_t... sizes > requires (validate_multi_array<rank, sizes...>())
    class MultiArray;

  // typenames for specializations

  template <typename Element>
  using Scalar = MultiArray<Element, 0>;

  template <typename Element, size_t... sizes>
  using Vector = MultiArray<Element, 1, sizes...>;

  template <typename Element, size_t... sizes>
  using Matrix = MultiArray<Element, 2, sizes...>;

  template <typename Element, size_t... sizes>
  using Array3D = MultiArray<Element, 3, sizes...>;

  template <typename Element, size_t... sizes>
  using Array4D = MultiArray<Element, 4, sizes...>;




  // Constant

  template <typename Element, size_t rank, size_t... sizes > requires (validate_multi_array<rank, sizes...>())
    class MultiArray_Constant;

  template <typename Element, size_t... sizes>
  using Vector_Constant = MultiArray_Constant<Element, 1, sizes...>;

  template <typename Element, size_t... sizes>
  using Matrix_Constant = MultiArray_Constant<Element, 2, sizes...>;


  // RepeatVector

  template <typename Element, size_t rank, size_t... sizes > requires (validate_multi_array<rank, sizes...>())
    class MultiArray_RepeatVector;




  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixZero;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixIdentity;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixExchange;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixConstDiag;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixDiagonal;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixRevDiag;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixRepCol;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixRepRow;

  // template <typename Element>
  // class MatrixRepRowAndCol;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixVandermonde;

  // template <typename Element, size_t NR = 0, size_t NC = 0>
  // class MatrixToeplitz;

  // template <typename Element, size_t N = 0>
  // class MatrixUpperTriangle;

  // template <typename Element, size_t N = 0>
  // class MatrixLowerTriangle;

  // template <typename Element, size_t N = 0>
  // class MatrixSymmetric;

  // template <typename Element, size_t N = 0>
  // class MatrixSkewSymmetric;

  // template <typename Element, size_t N = 0>
  // class MatrixHermitian;

  // template <typename Element, size_t N = 0>
  // class MatrixSkewHermitian;



  // *********************************************************************
  // * Expressions
  // ********************************************************************


  template <class A, typename Element, typename Num, size_t depth, size_t rank, class FUNC>
  class ExpressionR_Unary;

  template <class A, class B, class E1, class E2, class E3, class NT1, class NT2, class NT3, size_t D1, size_t D2, size_t D3, size_t R1, size_t R2, size_t R3, class OP>
  class ExpressionR_Binary;

  template <class A, class B, class C, class E1, class E2, class E3, class E4, class NT1, class NT2, class NT3, class D4, size_t D1, size_t D2, size_t D3, size_t M4, size_t R1, size_t R2, size_t R3, size_t R4, class OP>
  class ExpressionR_Ternary;

  template <class A, class X, typename Element, typename Num, size_t depth, size_t rank>
  class ExpressionR_Series;

  template <class A, class B, class X, typename Num, class OP1, class OP2>
  class ExpressionR_Series2;

  template <class A, typename Element, typename Num, size_t depth, size_t rank, class FUNC>
  class ExpressionR_Transpose;

  template <class A, typename Num>
  class ExpressionR_Rep;

  template <class X, class Y, typename Element, typename Num, size_t depth>
  class ExpressionR_Join;

  template <typename Num>
  class ExpressionRW_Subset;

  template <typename Num>
  class ExpressionRW_Submask;

  template <class X, class Y, typename Element, typename Num, size_t depth>
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
  // * MultiGrid_A - for coordinates 
  //
  // This is a nested structure with depth=2:
  //   top level: a Vector of size NDIMS
  //   second level: multiarrays of fixed rank=NDIMS but dynamic size
  //
  // A[i] -> gives the grid (a MultiArray of rank NDIMS) for the i-th coordinate
  // ***************************************************************************

  // template <typename Num, size_t NDIMS, size_t... ints>
  // using MultiGrid_A = std::tuple< MultiArray_RepeatVector<Num, NDIMS, ints>...>;


  // ***************************************************************************
  // * MultiGrid_B - for coordinates
  //
  // This is a nested structure with depth=2:
  //   top level: a single multiarray of fixed rank=NDIMS but dynamic size
  //   second level: Vectors of size NDIMS
  //
  // This type has the same total number of elements as MultiGrid_A.
  // The two types can be converted from one to another using the function 'evert'.
  //
  // B[j] -> gives the coordinate vector (technically an ordered set) for grid point j
  // ***************************************************************************

  // template <typename Num, size_t NDIMS>
  // using MultiGrid_B = MultiArray_RepeatVector< Vector<Num, NDIMS>, NDIMS>;



  // template <typename Num, size_t NDIMS, size_t rank, typename G>
  // class GridTraits;



  template <typename T, typename B = void> T zero();
  template <typename T, typename B = void> T one();


  template <class Element>
  inline auto& zeros();

  template <class Element>
  inline auto& ones();

  template <class X, class Element, typename Num, size_t depth, size_t rank> requires (std::is_same<Num, bool>::value)
    Vector<size_t>& findtrue(const ExpressionR<X, Element, Num, depth, rank>& x);


}; // namespace mathq




#endif
