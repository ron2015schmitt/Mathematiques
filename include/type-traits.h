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
    using OrderedNumberType = void;
  };

  template <typename SimpleNumber>
  class IsComplex<std::complex<SimpleNumber>> {
  public:
    constexpr static bool value = true;
    using OrderedNumberType = SimpleNumber;
  };


  // ***************************************************************************
  //  IsImaginary<T>
  // ***************************************************************************

  template <typename T>
  class IsImaginary {
  public:
    constexpr static bool value = false;
    using OrderedNumberType = void;
  };

  template <typename SimpleNumber>
  class IsImaginary<mathq::Imaginary<SimpleNumber>> {
  public:
    constexpr static bool value = true;
    using OrderedNumberType = SimpleNumber;
  };

  // ***************************************************************************
  //  IsQuaternion<T>
  // ***************************************************************************


  template <typename T>
  class IsQuaternion {
  public:
    constexpr static bool value = false;
    using OrderedNumberType = void;
  };

  template <typename SimpleNumber>
  class IsQuaternion<mathq::Quaternion<SimpleNumber>> {
  public:
    constexpr static bool value = true;
    using OrderedNumberType = SimpleNumber;
  };





  // ***************************************************************************
  //  SimpleNumber<X>
  //
  // bool, integers, floating point
  // ***************************************************************************

  template <typename T>
  concept SimpleNumber = std::is_integral_v<T> || std::is_floating_point_v<T>;


  // ***************************************************************************
  //  AdvancedNumber<X>
  //
  // complex, Imaginary, Quaternion
  // ***************************************************************************

  template <typename T>
  concept AdvancedNumber = IsComplex<T>::value || IsImaginary<T>::value || IsQuaternion<T>::value;



  // ***************************************************************************
  //  Number<X>
  //
  // bool, integers, floating point
  // complex, Imaginary, Quaternion
  // ***************************************************************************

  template <typename T>
  concept Number = SimpleNumber<T> || AdvancedNumber<T>;



  // ***************************************************************************
  //  ReadableExpression<X>
  //
  // MultiArrays and their Expressions
  // ***************************************************************************


  template <class X, class Element, typename Number, size_t depth, size_t rank>
  bool readable_expression_test(const ExpressionR<X, Element, Number, depth, rank>& x) {
    return true;
  }

  template <class X>
  concept ReadableExpression = requires(X x) {
    readable_expression_test(x);
  };


  // ***************************************************************************
  //  WritableExpression<X>
  //
  // MultiArrays and their Expressions
  // ***************************************************************************

  template <class X, class Element, typename Number, size_t depth, size_t rank>
  bool writable_expression_test(const ExpressionRW<X, Element, Number, depth, rank>& x) {
    return true;
  }


  template <class X>
  concept WritableExpression = requires(X x) {
    writable_expression_test(x);
  };


  // ***************************************************************************
  //  IsMultiArrayOrExpression<T>
  //
  // MultiArrays and their Expressions
  // ***************************************************************************

  template <typename T>
  class IsMultiArrayOrExpression {
  public:
    constexpr static bool value = false;
  };

  template <typename Element, size_t rank, size_t... ints>
  class IsMultiArrayOrExpression<MultiArray<Element, rank, ints...>> {
  public:
    constexpr static bool value = true;
  };

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank>
  class IsMultiArrayOrExpression<ExpressionR<Derived, Element, Number, depth, rank>> {
  public:
    constexpr static bool value = true;
  };

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank>
  class IsMultiArrayOrExpression<ExpressionRW<Derived, Element, Number, depth, rank>> {
  public:
    constexpr static bool value = true;
  };



  // ***************************************************************************
  //  IsMultiArray<T>
  //
  // MultiArrays and their Expressions
  // ***************************************************************************

  template <typename T>
  class IsMultiArray {
  public:
    constexpr static bool value = false;
  };

  template <typename Element, size_t rank, size_t... ints>
  class IsMultiArray<MultiArray<Element, rank, ints...>> {
  public:
    constexpr static bool value = true;
  };


  // ***************************************************************************
  //  IsMultiArrayExp<T>
  // ***************************************************************************

  template <typename T>
  class IsMultiArrayExp {
  public:
    constexpr static bool value = false;
  };

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank>
  class IsMultiArrayExp<ExpressionR<Derived, Element, Number, depth, rank>> {
  public:
    constexpr static bool value = true;
  };

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank>
  class IsMultiArrayExp<ExpressionRW<Derived, Element, Number, depth, rank>> {
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

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank>
  class IsMultiArrayExpRW<ExpressionRW<Derived, Element, Number, depth, rank>> {
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

  template <ReadableExpression X>
  class MultiArrayTypeTrait {
  public:
    using Type = MultiArray<typename X::ElementType, X::rank_value>;
  };

  template <ReadableExpression X> requires (HasStaticSizes<X>)
    class MultiArrayTypeTrait<X> {
    public:
      using Type = MultiArrayHelper<typename X::ElementType, X::static_dims_array>;
  };

  template <ReadableExpression X> requires (ReadableExpression<typename X::ElementType>)
    class MultiArrayTypeTrait<X> {
    public:
      using Type = MultiArray< typename MultiArrayTypeTrait<typename X::ElementType>::Type, X::rank_value >;
  };
  template <ReadableExpression X> requires (HasStaticSizes<X>&& ReadableExpression<typename X::ElementType>)
    class MultiArrayTypeTrait<X> {
    public:
      using Type = MultiArrayHelper< typename MultiArrayTypeTrait<typename X::ElementType>::Type, X::static_dims_array >;
  };

  template <ReadableExpression X>
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


  // built in ordered number types: bool, int, double etc
  template <typename Number> requires (std::is_arithmetic<Number>::value)
    class
    NumberTrait<Number> {
    public:
      using InputType = Number;
      using Type = Number;

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

  // complex number enclosing an ordered number
  template <typename Number> requires (std::is_arithmetic<Number>::value)
    class
    NumberTrait<std::complex<Number>> {
    public:
      using InputType = std::complex<Number>;
      using Type = std::complex<Number>;

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


  // imaginary number enclosing an ordered number
  template <typename Number> requires (std::is_arithmetic<Number>::value)
    class
    NumberTrait<Imaginary<Number>> {
    public:
      using InputType = Imaginary<Number>;
      using Type = Imaginary<Number>;

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

  // quaternion number enclosing an ordered number
  template <typename Number>
  class
    NumberTrait<Quaternion<Number>> {
  public:
    using InputType = Quaternion<Number>;
    using Type = Quaternion<Number>;

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


  //  ReadableExpression

  template <ReadableExpression T>
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

    inline static size_t size(const InputType& x) {
      return x.size();
    }
    inline static size_t total_size(const InputType& x) {
      return x.total_size();
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

  template <typename NewNumber>
  class ReplacedNumberTrait<NullType, NewNumber> {
  public:
    using Type = NewNumber;
  };


  // built in ordered number types: bool, int, double etc
  template <typename Number, typename NewNumber>  requires (std::is_arithmetic<Number>::value)
    class
    ReplacedNumberTrait<Number, NewNumber> {
    public:
      using Type = NewNumber;
  };

  // complex number enclosing an ordered number
  template <typename Number, typename NewNumber>  requires (std::is_arithmetic<Number>::value)
    class
    ReplacedNumberTrait<std::complex<Number>, NewNumber> {
    public:
      using Type = NewNumber;
  };


  // imaginary number enclosing an ordered number
  template <typename Number, typename NewNumber>  requires (std::is_arithmetic<Number>::value)
    class
    ReplacedNumberTrait<Imaginary<Number>, NewNumber> {
    public:
      using Type = NewNumber;
  };

  // quaternion number enclosing an ordered number
  template <typename Number, typename NewNumber> requires (std::is_arithmetic<Number>::value)
    class
    ReplacedNumberTrait<Quaternion<Number>, NewNumber> {
    public:
      using Type = NewNumber;
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

  template <typename NewNumber, class Derived, typename Element, typename Number, size_t depth_in, size_t rank>
  class
    ReplacedNumberTrait<ExpressionR<Derived, Element, Number, depth_in, rank>, NewNumber> {
  public:
    using ElementType = typename ReplacedNumberTrait<Element, NewNumber>::Type;
    using Type = typename ReplacedNumberTrait<Derived, NewNumber>::Type;
    using DerivedType = Type;
    using ExpressionType = ExpressionR<DerivedType, ElementType, NewNumber, depth_in, rank>;
  };


  //  ExpressionRW

  template <typename NewNumber, class Derived, typename Element, typename Number, size_t depth_in, size_t rank>
  class
    ReplacedNumberTrait<ExpressionRW<Derived, Element, Number, depth_in, rank>, NewNumber> {
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


  template <typename Element, template <typename> class T>
  class SimpleNumberTrait<T<Element>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
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


  // I tried making a general specialization for all subclasses of ExpressionRW but haven't succeeded:

    // template < template <typename, auto...> class T, typename Element, auto... Rest>  
    // requires ( std::is_base_of_v< 
    //   ExpressionRW<
    //     T<Element, Rest...>, 
    //     Element, 
    //     typename T<Element, Rest...>::NumberType, 
    //     T<Element, Rest...>::depth_value, 
    //     T<Element, Rest...>::rank_value>, 
    //   T<Element, Rest...> 
    // >)

    // class SimpleNumberTrait<T<Element, Rest...>> 
    // {
    // public:
    //   using Type = typename SimpleNumberTrait<Element>::Type;
    //   constexpr static size_t depth() {
    //     return 1 + SimpleNumberTrait<Element>::depth();
    //   }
    // };
  template <class Derived, typename Element, typename Number, size_t depth_, size_t rank>
  class SimpleNumberTrait<ExpressionR<Derived, Element, Number, depth_, rank>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };

  template <class Derived, typename Element, typename Number, size_t depth_, size_t rank>
  class SimpleNumberTrait<ExpressionRW<Derived, Element, Number, depth_, rank>> {
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

  template <typename Number, class C = NullType>
  class InversionType;


  // the template specializations for numbers just return the number type, which terminates ends the recursion

  // TODO: should ad check is_arithmetic
  template <typename Number, class C>
  class InversionType {
  public:
    using Type = C;
  };
  template <typename Number, class C>
  class InversionType<std::complex<Number>, C> {
  public:
    using Type = C;
  };
  template <typename Number, class C>
  class InversionType<Imaginary<Number>, C> {
  public:
    using Type = C;
  };

  template <typename Number, class C>
  class InversionType<Quaternion<Number>, C> {
  public:
    using Type = C;
  };




  //  MultiArray<Element>
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









  template <typename Number, size_t NDIMS, size_t rank, typename G>
  class GridTraits {
    constexpr static bool isMultiArrayOfGrids = false;
    constexpr static bool isGridOfMultiArrays = false;
  };

  // template <typename Number, size_t NDIMS, size_t rank>
  // class GridTraits<Number, NDIMS, rank, MultiGrid_A<Number, NDIMS, rank>> {
  //   constexpr static bool isMultiArrayOfGrids = true;
  //   constexpr static bool isGridOfMultiArrays = false;
  // };

  // template <typename Number, size_t NDIMS, size_t rank>
  // class GridTraits<Number, NDIMS, rank, MultiGrid_B<Number, NDIMS, rank>> {
  //   constexpr static bool isMultiArrayOfGrids = false;
  //   constexpr static bool isGridOfMultiArrays = true;
  // };



  // ***************************************************************************
  // ***************************************************************************
  // * Nabla
  // ***************************************************************************
  template <class T = void>
  class Nabla;

  // * RealSet 
  // ***************************************************************************

  template <typename Number>
  class RealSet;














}; // namespace mathq



#endif
