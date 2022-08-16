#ifndef MATHQ__TYPETRAITS
#define MATHQ__TYPETRAITS



namespace mathq {




  // ***************************************************************************
  // * compile time functions
  // ***************************************************************************



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


  template<typename T, T val, size_t N>
  constexpr auto array_of_one_value() {
    std::array<T, N> A;
    for (size_t i = 0; i < N; ++i) {
      A[i] = val;
    }
    return A;
  }



  template<typename T, size_t N>
  constexpr T compile_time_summation(const std::array<T, N>& A) {
    T sum{ T(0) };
    for (size_t i = 0; i < N; ++i) {
      sum += A[i];
    }
    return sum;
  }

  template<typename T, size_t N>
  constexpr bool is_all_zeros(const std::array<T, N>& A) {
    return (compile_time_summation(A) == 0);
  }


  // note this returns 1 for arrays of size == 0
  template<typename T, size_t N>
  constexpr T compile_time_product(const std::array<T, N>& A) {
    T product{ T(1) };
    for (size_t i = 0; i < N; ++i) {
      product *= A[i];
    }
    return product;
  }


  template<size_t rank, size_t... ints>
  constexpr bool check_dynamic() {
    constexpr size_t N = sizeof...(ints);
    if constexpr (N < rank) {
      return true;
    }
    constexpr std::array<size_t, N> A = { (static_cast<size_t>(ints))... };
    for (size_t i = 0; i < N; ++i) {
      if (A[i] == 0) return true;
    }
    return false;
  }


  template<size_t rank, size_t... ints>
  constexpr size_t calc_size() {
    constexpr size_t N = sizeof...(ints);
    if constexpr (N < rank) {
      return 0;
    }
    constexpr std::array<size_t, N> A = { (static_cast<size_t>(ints))... };
    return compile_time_product<size_t, N>(A);
  }



  template<typename U> requires (std::is_integral<U>::value)
    size_t signed_index_to_unsigned_index(const U& index, const size_t& N) {
    U temp = index;
    while (temp < U(0)) {
      temp += U(N);
    }
    return size_t(temp);
  }

  //*******************************************************
  //          extended
  //*******************************************************

  using extended = long double;

  //*******************************************************
  //          NullType
  //*******************************************************

  class NullType {
  public:
    static std::string Classname() {
      using namespace display;
      std::string s = "NullType";
      return s;
    }

    inline std::string classname() const {
      return Classname();
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const NullType& var) {
      using namespace display;
      stream << "∅";
      return stream;
    }

  };



  // ***************************************************************************
  //  IsComplex<T>
  // ***************************************************************************


  template <typename T>
  class IsComplex {
  public:
    constexpr static bool value = false;
    using SimpleNumberType = void;
  };

  template <typename SimpleNum>
  class IsComplex<std::complex<SimpleNum>> {
  public:
    constexpr static bool value = true;
    using SimpleNumberType = SimpleNum;
  };


  // ***************************************************************************
  //  IsImaginary<T>
  // ***************************************************************************

  template <typename T>
  class IsImaginary {
  public:
    constexpr static bool value = false;
    using SimpleNumberType = void;
  };

  template <typename SimpleNum>
  class IsImaginary<mathq::Imaginary<SimpleNum>> {
  public:
    constexpr static bool value = true;
    using SimpleNumberType = SimpleNum;
  };

  // ***************************************************************************
  //  IsQuaternion<T>
  // ***************************************************************************


  template <typename T>
  class IsQuaternion {
  public:
    constexpr static bool value = false;
    using SimpleNumberType = void;
  };

  template <typename SimpleNum>
  class IsQuaternion<mathq::Quaternion<SimpleNum>> {
  public:
    constexpr static bool value = true;
    using SimpleNumberType = SimpleNum;
  };





  // ***************************************************************************
  //  concept IsSimpleNumber<X>
  //
  // bool, integers, floating point
  // ***************************************************************************

  template <typename T>
  concept IsSimpleNumber = std::is_integral_v<T> || std::is_floating_point_v<T>;


  // ***************************************************************************
  //  concept IsAdvancedNumber<X>
  //
  // complex, Imaginary, Quaternion
  // ***************************************************************************

  template <typename T>
  concept IsAdvancedNumber = IsComplex<T>::value || IsImaginary<T>::value || IsQuaternion<T>::value;



  // ***************************************************************************
  // concept IsNumber<X>
  //
  // bool, integers, floating point
  // complex, Imaginary, Quaternion
  // ***************************************************************************

  template <typename T>
  concept IsNumber = IsSimpleNumber<T> || IsAdvancedNumber<T>;



  // ***************************************************************************
  //  IsReadableExpressionOrArray<X>
  //
  // MultiArrays and their Expressions
  // ***************************************************************************

  template <class X, class Element, typename Num, size_t depth, size_t rank>
  bool readable_expression_test(const ExpressionR<X, Element, Num, depth, rank>& x) {
    return true;
  }
  template <class X, class Element, typename Num, size_t depth, size_t rank>
  Element readable_expression_element(const ExpressionR<X, Element, Num, depth, rank>& x) {
    return Element();
  }



  template <class X>
  concept IsReadableExpressionOrArray = requires(X x) {
    readable_expression_test(x);
  };


  // ***************************************************************************
  //  IsWritableExpressionOrArray<X>
  //
  // MultiArrays and their Expressions
  // ***************************************************************************

  template <class X, class Element, typename Num, size_t depth, size_t rank>
  bool writable_expression_test(const ExpressionRW<X, Element, Num, depth, rank>& x) {
    return true;
  }


  template <class X>
  concept IsWritableExpressionOrArray = requires(X x) {
    writable_expression_test(x);
  };



  // ***************************************************************************
  //  IsMultiArray<T>
  //
  // MultiArrays and their Expressions
  // ***************************************************************************

  template <class T>
  concept IsMultiArray = requires(T x) {
    T::isNotExpression;
      requires std::is_same_v<bool const, decltype(T::isNotExpression)>;
      requires (T::isNotExpression == true);
  };



  // ***************************************************************************
  //  IsMultiArrayExp<T>
  // ***************************************************************************

  template <typename T>
  class IsMultiArrayExp {
  public:
    constexpr static bool value = false;
  };

  template <class Derived, typename Element, typename Num, size_t depth, size_t rank>
  class IsMultiArrayExp<ExpressionR<Derived, Element, Num, depth, rank>> {
  public:
    constexpr static bool value = true;
  };

  template <class Derived, typename Element, typename Num, size_t depth, size_t rank>
  class IsMultiArrayExp<ExpressionRW<Derived, Element, Num, depth, rank>> {
  public:
    constexpr static bool value = true;
  };


  // ***************************************************************************
  //  IsMultiArrayExpRW<T>
  // ***************************************************************************

  template <typename T>
  class IsMultiArrayExpRW {
  public:
    constexpr static bool value = false;
  };

  template <class Derived, typename Element, typename Num, size_t depth, size_t rank>
  class IsMultiArrayExpRW<ExpressionRW<Derived, Element, Num, depth, rank>> {
  public:
    constexpr static bool value = true;
  };



  // ***************************************************************************
  //  MultiArrayHelper<Element, std:array>
  //
  // ***************************************************************************


  // MultiArrayHelperTrait 
  //
  // Used by MultiArrayHelper


  template <
    typename Element,
    auto arr,
    typename IS = decltype(std::make_index_sequence<arr.size()>())
  >
  struct MultiArrayHelperTrait;


  template <
    typename Element,
    auto arr,
    std::size_t... I
  > requires (is_all_zeros(arr))
    struct MultiArrayHelperTrait<Element, arr, std::index_sequence<I...>> {
    using Type = MultiArray<Element, sizeof...(I)>;
  };

  template <
    typename Element,
    auto arr,
    std::size_t... I
  > requires (!is_all_zeros(arr))
    struct MultiArrayHelperTrait<Element, arr, std::index_sequence<I...>> {
    using Type = MultiArray<Element, sizeof...(I), arr[I]...>;
  };


  // MultiArrayHelper
  //
  // This allows creation of a MultiArray rank and sizes from a constexpr std::array

  template <typename Element, auto arr>
  using MultiArrayHelper = MultiArrayHelperTrait<Element, arr>::Type;



  // ***************************************************************************
  //  HasStaticSizes<X>
  //
  // ***************************************************************************


  template <class X>
  concept HasStaticSizes = requires(X x) {
    X::static_dims_array;
  };


  // ************************************************************************************
  // MultiArrayType 
  //
  // This returns a concrete[1] and general[1] MultiArray of for the given MultiArray or Expression
  // The operation is performed on all nested MultiArrays contained in the Element
  //
  // 1. By concrete, we meean a MultiArray and not an Expression
  // 2. By general we mean a MultiArray and not a specialization like MultiArray_Constant
  // ************************************************************************************

  template <IsReadableExpressionOrArray X>
  class MultiArrayTypeTrait {
  public:
    using Type = MultiArray<typename X::ElementType, X::rank_value>;
  };

  template <IsReadableExpressionOrArray X> requires (HasStaticSizes<X>)
    class MultiArrayTypeTrait<X> {
    public:
      using Type = MultiArrayHelper<typename X::ElementType, X::static_dims_array>;
  };

  template <IsReadableExpressionOrArray X> requires (IsReadableExpressionOrArray<typename X::ElementType>)
    class MultiArrayTypeTrait<X> {
    public:
      using Type = MultiArray< typename MultiArrayTypeTrait<typename X::ElementType>::Type, X::rank_value >;
  };
  template <IsReadableExpressionOrArray X> requires (HasStaticSizes<X>&& IsReadableExpressionOrArray<typename X::ElementType>)
    class MultiArrayTypeTrait<X> {
    public:
      using Type = MultiArrayHelper< typename MultiArrayTypeTrait<typename X::ElementType>::Type, X::static_dims_array >;
  };

  template <IsReadableExpressionOrArray X>
  using MultiArrayType = MultiArrayTypeTrait<X>::Type;

  // ************************************************************************************************
  // NumberTrait<InputType, NewNumber>
  //
  // This operates recursively to find the base number type
  //              eg. complex<double>, Imaginary<float>, Quaternion<float>, int, double, etc

  //  InputType:           Type that was passed in as first arg
  //  Type:                Depends on InputType
  //                         numbers: InputType
  //                         MultiArray: The number type of the Element (or contained in the element)
  //                         MArrayR{,W}Exp: The number type of the Expression
  //  depth():             Depth to the number type at the bottom
  //  value                True if unput type is a number
  // ************************************************************************************************

  template <typename T>
  class NumberTrait {
  public:
    using InputType = T;
    using Type = NullType;

    constexpr static bool value = false;
    constexpr static size_t depth() {
      return 0;
    }
    constexpr static const size_t sum_of_ranks() {
      return 0;
    }
    template <size_t Nin = 0>
    constexpr static const std::array<size_t, sum_of_ranks()+Nin> get_rank_array(const std::array<size_t, Nin>& rank_array = std::array<size_t, Nin>{}) {
      return rank_array;
    }
  };


  template <IsNumber T>
  class
    NumberTrait<T> {
  public:
    using InputType = T;
    using Type = T;

    constexpr static bool value = true;
    constexpr static size_t depth() {
      return 0;
    }
    constexpr static const size_t sum_of_ranks() {
      return 0;
    }
    template <size_t Nin = 0>
    constexpr static const std::array<size_t, sum_of_ranks()+Nin> get_rank_array(const std::array<size_t, Nin>& rank_array = std::array<size_t, Nin>{}) {
      return rank_array;
    }
  };


  //  IsReadableExpressionOrArray

  template <IsReadableExpressionOrArray T>
  class
    NumberTrait<T> {
  public:
    using InputType = T;
    using ElementType = typename T::ElementType;
    using Type = typename NumberTrait<ElementType>::Type;

    constexpr static bool value = false;

    constexpr static size_t depth() {
      return 1 + NumberTrait<ElementType>::depth();
    }

    constexpr static size_t rank = T::rank_value;

    constexpr static const size_t sum_of_ranks() {
      return rank + NumberTrait<ElementType>::sum_of_ranks();
    }

    template <size_t Nin = 0>
    constexpr static const std::array<size_t, Nin+depth()> get_rank_array(const std::array<size_t, Nin>& rank_array = std::array<size_t, Nin>{}) {
      std::array<size_t, Nin+1> new_array{};
      for (size_t ii = 0; ii < rank_array.size(); ii++) {
        new_array[ii] = rank_array[ii];
      }
      new_array[Nin] = rank;
      auto x = NumberTrait<ElementType>::get_rank_array(new_array);
      return x;
    }

  };






  // ************************************************************************************************
  // ReplacedNumberTrait<InputType, NewNumber>
  //
  // This operates recursively to find the base number type
  //              eg. complex<double>, Imaginary<float>, Quaternion<float>, int, double, etc

  //  Type:  Depends on InputType
  //                         numbers: NewNumber
  //                         MultiArray: The InputType with the number type replaced by NewNumber
  //                         ExpressionR{,W}: Derived type with the number type replaced in all contained expressions and MultiArrays 
  // ************************************************************************************************

  template <typename T, typename NewNumber>
  class ReplacedNumberTrait {
  public:
    using Type = T;
  };

  // template <typename NewNumber>
  // class ReplacedNumberTrait<NullType, NewNumber> {
  // public:
  //   using Type = NewNumber;
  // };


  // built in ordered number types: bool, int, double etc
  template <IsNumber Num, IsNumber NewNum>
  class
    ReplacedNumberTrait<Num, NewNum> {
  public:
    using Type = NewNum;
  };



  //  IsReadableExpressionOrArray

  template <IsReadableExpressionOrArray T, typename NewNumber>
  class
    ReplacedNumberTrait<T, NewNumber> {
  public:
    using OldElementType = typename T::ElementType;
    using ElementType = typename ReplacedNumberTrait<OldElementType, NewNumber>::Type;
    using Type = MultiArray<ElementType, T::rank_value>;
  };

  //  MultiArray<Element>

  template <typename NewNumber, typename Element, size_t rank, size_t... ints>
  class
    ReplacedNumberTrait<MultiArray<Element, rank, ints...>, NewNumber> {
  public:
    using ElementType = typename ReplacedNumberTrait<Element, NewNumber>::Type;
    using Type = MultiArray<ElementType, rank, ints...>;
  };

  //  ExpressionR

  template <typename NewNumber, class Derived, typename Element, typename Num, size_t depth_in, size_t rank>
  class
    ReplacedNumberTrait<ExpressionR<Derived, Element, Num, depth_in, rank>, NewNumber> {
  public:
    using ElementType = typename ReplacedNumberTrait<Element, NewNumber>::Type;
    using Type = typename ReplacedNumberTrait<Derived, NewNumber>::Type;
    using DerivedType = Type;
    using ExpressionType = ExpressionR<DerivedType, ElementType, NewNumber, depth_in, rank>;
  };


  //  ExpressionRW

  template <typename NewNumber, class Derived, typename Element, typename Num, size_t depth_in, size_t rank>
  class
    ReplacedNumberTrait<ExpressionRW<Derived, Element, Num, depth_in, rank>, NewNumber> {
  public:
    using ElementType = typename ReplacedNumberTrait<Element, NewNumber>::Type;
    using Type = typename ReplacedNumberTrait<Derived, NewNumber>::Type;
    using DerivedType = Type;
    using ExpressionType = ExpressionRW<DerivedType, ElementType, NewNumber, depth_in, rank>;
  };






  // *****************************************************************************************
  // SimpleNumberTrait<T>
  //
  // This operates recursively to find the simple number type for type T
  // We define simple number: as integers, rationals, reals, or subsets thereof.
  // ****************************************************************************************

  template <typename T>
  class SimpleNumberTrait {
  public:
    using Type = NullType;
    constexpr static size_t depth() {
      return 0;
    }
  };

  // for built-in number types (not classes)
  template <typename T>  requires (std::is_arithmetic<T>::value)
    class
    SimpleNumberTrait<T> {
    public:
      using Type = T;
      constexpr static size_t depth() {
        return 0;
      }
  };


  template <typename Element>
  class SimpleNumberTrait<std::complex<Element>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };

  template <typename Element>
  class SimpleNumberTrait<Imaginary<Element>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };

  template <typename Element>
  class SimpleNumberTrait<Quaternion<Element>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };


  template <class Derived, typename Element, typename Num, size_t depth_, size_t rank>
  class SimpleNumberTrait<ExpressionR<Derived, Element, Num, depth_, rank>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };

  template <class Derived, typename Element, typename Num, size_t depth_, size_t rank>
  class SimpleNumberTrait<ExpressionRW<Derived, Element, Num, depth_, rank>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };


  template <typename Element, size_t rank, size_t... ints>
  class SimpleNumberTrait<MultiArray<Element, rank, ints...>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };




  // ***************************************************************************
  // DeeperType
  //
  //  This returns the NumberTrait::Type for the deeper structure
  //
  // ***************************************************************************

  template <typename T1, typename T2>
  class DeeperType {
  public:
    using Type = typename std::conditional< NumberTrait<T1>::depth() >= NumberTrait<T2>::depth(), T1, T2>::type;
  };


  // *****************************************************************************************
  // DimensionsTrait
  //
  // This operates recursively to find the simple number type for type T
  // We define simple number: as integers, rationals, reals, or subsets thereof.
  // ****************************************************************************************

  template <typename T, size_t level = 0>
  class DimensionsTrait {
  public:
    using Type = NullDimensions;
    constexpr static size_t depth() {
      return 0;
    }

  };


  //  DimensionsTrait<Element>
  template <typename Element, size_t level, size_t rank, size_t... ints>
  class DimensionsTrait<MultiArray<Element, rank, ints...>, level> {
  public:
    constexpr static size_t level_value = level;
    using InputType = MultiArray<Element, rank, ints...>;
    using DimensionsType = typename MultiArray<Element, rank, ints...>::DimensionsType;
    using Type = typename std::conditional< level == 0, DimensionsType, DimensionsTrait<Element, level-1> >::type;

  };




  // ************************************************************************************************
  //  MakeInitializer
  // 
  // ************************************************************************************************

  template <typename T, size_t depth>
  class MakeInitializer {
  public:
    using Type = std::initializer_list< typename MakeInitializer<T, (depth-1)>::Type >;
  };
  template <typename T>
  class MakeInitializer<T, 0> {
  public:
    using Type = T;
  };


  // ************************************************************************************************
  //  InitializerTrait
  // ************************************************************************************************

  template <typename T>
  class InitializerTrait {
  public:
    using Type = T;
    using ElementType = NullType;
    using BottomType = T;

    constexpr static bool is_initializer_list = false;
    constexpr static size_t depth() {
      return 0;
    }
    constexpr static size_t size() {
      return 0;
    }

    template <size_t Nin = 0>
    constexpr static const std::array<size_t, Nin> get_size_array(const Type& mylist, const std::array<size_t, Nin>& size_array = std::array<size_t, Nin>{}) {
      return size_array;
    }

  };

  //  std::initializer_list<Element>

  template <typename Element>
  class
    InitializerTrait<std::initializer_list<Element>> {
  public:
    using Type = std::initializer_list<Element>;
    using ElementType = Element;
    using BottomType = typename InitializerTrait<Element>::BottomType;

    constexpr static bool is_initializer_list = true;
    constexpr static size_t depth() {
      return 1 + InitializerTrait<Element>::depth();
    }

    template <size_t Nin = 0>
    constexpr static const std::array<size_t, Nin+depth()> get_size_array(const Type& mylist, const std::array<size_t, Nin>& size_array = std::array<size_t, Nin>{}) {
      std::array<size_t, Nin+1> new_array{};
      for (size_t ii = 0; ii < size_array.size(); ii++) {
        new_array[ii] = size_array[ii];
      }
      new_array[Nin] = mylist.size();
      auto x = InitializerTrait<Element>::get_size_array(*(mylist.begin()), new_array);
      return x;
    }

  };





  // ***************************************************************************
  // InversionType - turnt he type inside out
  //
 //
  //    example:  InversionType< Vector<Scalar<double>> >::Type   ->   Scalar<Vector<double>>
  //
  //    NOTE: This only works for MultiArrays not expressions (at this time)
  //          It does not turn complex, Imaginary, or Quarternion numbers etc inside out
  // ***************************************************************************

  template <typename Num, class C = NullType>
  class InversionType;


  // the template specializations for numbers just return the number type, which terminates ends the recursion

  // TODO: should ad check is_arithmetic
  template <typename Num, class C>
  class InversionType {
  public:
    using Type = C;
  };
  template <typename Num, class C>
  class InversionType<std::complex<Num>, C> {
  public:
    using Type = C;
  };
  template <typename Num, class C>
  class InversionType<Imaginary<Num>, C> {
  public:
    using Type = C;
  };

  template <typename Num, class C>
  class InversionType<Quaternion<Num>, C> {
  public:
    using Type = C;
  };




  //  MultiArray<Element>
  // template <IsReadableExpressionOrArray T, typename C>
  // class InversionType<T, C> {
  // public:
  //   using ElementType = typename T::ElementType;
  //   using NumberType = typename NumberTrait<ElementType>::Type;
  //   using T_as_MultiArray = MultiArrayType<T>;
  //   using MultiArray_NumberType = typename ReplacedNumberTrait< T_as_MultiArray, NumberType >::Type; // top level array becomes bottom level array
  //   using MultiArray_C = typename ReplacedNumberTrait< T_as_MultiArray, C >::Type;  // this is for the intermediate arrays
  //   using Type = typename std::conditional<  std::is_same<C, NullType>::value, typename InversionType<ElementType, MultiArray_NumberType>::Type, typename InversionType<ElementType, MultiArray_C>::Type  >::type;
  // };


  template <typename Element, size_t rank, size_t... ints, typename C>
  class InversionType<MultiArray<Element, rank, ints...>, C> {
  public:
    using NumberType = typename NumberTrait<Element>::Type;
    using MultiArrayD = MultiArray<NumberType, rank, ints...>; // top level array becomes bottom level array
    using MultiArrayC = MultiArray<C, rank, ints...>;  // this is for the intermediate arrays
    using Type = typename std::conditional<  std::is_same<C, NullType>::value, typename InversionType<Element, MultiArrayD>::Type, typename InversionType<Element, MultiArrayC>::Type  >::type;
  };



  // ***************************************************************************
  // At(x,n) -  for primitives, return x
  //            for container of any type, return x[n]
  // ***************************************************************************

  template <typename Num>
  inline Num&& At(Num&& x, size_t n) {
    return x;
  }
  template <typename Num>
  inline const Num&& At(const Num&& x, size_t n) {
    return x;
  }
  template <template <class> class T, typename Num>
  inline Num&& At(T<Num>&& x, size_t n) {
    return x[n];
  }
  template <template <class> class T, typename Num>
  inline const Num&& At(const T<Num>&& x, size_t n) {
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
    using Type = decltype(x1 + x2);

    static inline std::string name() {
      return typeid(Type).name();
    }
  };

  template <typename T1, typename T2>
  class SubType {
  public:
    T1 x1;
    T2 x2;
    using Type = decltype(x1 - x2);

    static inline std::string name() {
      return typeid(Type).name();
    }
  };

  template <typename T1, typename T2>
  class MultType {
  public:
    T1 x1;
    T2 x2;
    using Type = decltype(x1* x2);

    static inline std::string name() {
      return typeid(Type).name();
    }
  };

  template <typename T1, typename T2>
  class DivType {
  public:
    T1 x1;
    T2 x2;
    using Type = decltype(x1 / x2);

    static inline std::string name() {
      return typeid(Type).name();
    }
  };

  template <typename T1, typename T2>
  class RelType {
  public:
    T1 x1;
    T2 x2;
    using Type = bool;

    static inline std::string name() {
      return typeid(Type).name();
    }
  };

  template <typename T1, typename T2>
  class AndType {
  public:
    T1 x1;
    T2 x2;
    using Type = decltype(x1&& x2);

    static inline std::string name() {
      return typeid(Type).name();
    }
  };

  template <typename T1, typename T2>
  class OrType {
  public:
    T1 x1;
    T2 x2;
    using Type = decltype(x1 || x2);

    static inline std::string name() {
      return typeid(Type).name();
    }
  };

  template <typename T1, typename T2>
  class ComplexType {
  public:
    T1 x1;
    T2 x2;
    using TType = decltype(x1 + x2);
    using Type = std::complex<TType>;

    static inline std::string name() {
      return typeid(Type).name();
    }
  };


  // ************************************************************************
  // * ReturnType: Class that determines return type of two MultiArrays of different depths
  // ***************************************************************************


  template <typename A, typename B, typename NewNumber>
  class ResultType {
  public:
    using MyDeeperType = typename DeeperType<A, B>::Type;
    using MultiArrayType = typename ReplacedNumberTrait<MyDeeperType, NewNumber>::Type;

    constexpr static bool isprim = (NumberTrait<A>::depth() == 0) && (NumberTrait<B>::depth() == 0);
    using Type = typename std::conditional<isprim, NewNumber, MultiArrayType>::type;
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

  template <typename T, typename ...Ts>
  using are_same = std::conjunction<std::is_same<T, Ts>...>;



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
  // Basic Function types for computation
  //
  // from https://en.cppreference.com/w/cpp/language/type_alias, the following are equivalent
  // typedef void (*func)(int, int);
  // using func = void (*) (int, int);
  //
  //  the following also compiles under g++10.3-c++17. not sure if it's the same
  //  using func = void (&) (int, int);
  //
  // DOUT: return type
  // Type: the function type
  //************************************************************************


  template <typename RetType>
  class FunctionType0 {
  public:
    typedef RetType(Type)();
    // using Type = RetType (&)();
  };

  template <typename NT1, typename RetType>
  class FunctionType1 {
  public:
    typedef RetType(Type)(NT1);
    // using type = RetType (&)(NT1);
  };

  template <typename NT1, typename NT2, typename RetType>
  class FunctionType2 {
  public:
    typedef RetType(Type)(NT1, NT2);
    // using type = RetType (&)(NT1, NT2);
  };

  template <typename NT1, typename NT2, typename NT3, typename RetType>
  class FunctionType3 {
  public:
    typedef RetType(Type)(NT1, NT2, NT3);
    // using type = RetType (&)(NT1, NT2, NT3);
  };









  template <typename Num, size_t NDIMS, size_t rank, typename G>
  class GridTraits {
    constexpr static bool isMultiArrayOfGrids = false;
    constexpr static bool isGridOfMultiArrays = false;
  };

  // template <typename Num, size_t NDIMS, size_t rank>
  // class GridTraits<Num, NDIMS, rank, MultiGrid_A<Num, NDIMS, rank>> {
  //   constexpr static bool isMultiArrayOfGrids = true;
  //   constexpr static bool isGridOfMultiArrays = false;
  // };

  // template <typename Num, size_t NDIMS, size_t rank>
  // class GridTraits<Num, NDIMS, rank, MultiGrid_B<Num, NDIMS, rank>> {
  //   constexpr static bool isMultiArrayOfGrids = false;
  //   constexpr static bool isGridOfMultiArrays = true;
  // };



  // ***************************************************************************
  // ***************************************************************************
  // * Nabla
  // ***************************************************************************
  template <class T = void>
  class Nabla;

  // * Domain 
  // ***************************************************************************

  template <typename Num>
  class Domain;














}; // namespace mathq



#endif
