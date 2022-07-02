#ifndef MATHQ__TYPETRAITS_H
#define MATHQ__TYPETRAITS_H



namespace mathq {

  //*******************************************************
  //          Typedefs
  //*******************************************************

  using extended = long double;

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
  // Materialize 
  //
  // This returns a concrete tensor of type specified by paramters.
  // Useful when working with multiarray expressions
  // ***************************************************************************

  template <typename Element, size_t rank, size_t... dims>
  class Materialize {
  public:
    using Type = typename MultiArray<Element, rank, dims...>::Type;
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

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class IsMultiArrayOrExpression<MArrayExpR<Derived, Element, Number, depth, rank, DimensionsT>> {
  public:
    constexpr static bool value = true;
  };

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class IsMultiArrayOrExpression<MArrayExpRW<Derived, Element, Number, depth, rank, DimensionsT>> {
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

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class IsMultiArrayExp<MArrayExpR<Derived, Element, Number, depth, rank, DimensionsT>> {
  public:
    constexpr static bool value = true;
  };

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class IsMultiArrayExp<MArrayExpRW<Derived, Element, Number, depth, rank, DimensionsT>> {
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

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class IsMultiArrayExpRW<MArrayExpRW<Derived, Element, Number, depth, rank, DimensionsT>> {
  public:
    constexpr static bool value = true;
  };


  // ************************************************************************************************
  // NumberTrait<InputType, NewNumber>
  //
  // This operates recursively to find the base number type
  //              eg. complex<double>, Imaginary<float>, Quaternion<float>, int, double, etc
  // Thsi can also be used to replace the number type
  //
  //  InputType:           Type that was passed in as first arg
  //  Type:                Depends on InputType
  //                         numbers: InputType
  //                         MultiArray: The number type at the bottom of the nested MultiArrays
  //                         MArrayR{,W}Exp: The number type of the Expression
  //  ReplacedNumberType:  Depends on InputType
  //                         numbers: NewNumber
  //                         MultiArray: The InputType with the number type (at the bottom) replaced by NewNumber
  //                         MArrayR{,W}Exp: The type of the MultiArray at the bottom of the nested expressions
  //                                         with the number type replaced by NewNumber
  //  ReplacedElementType: Depends on InputType
  //                         numbers: NewNumber
  //                         MultiArray: The InputType with the number type (at the bottom) replaced by NewNumber
  //                         MArrayR{,W}Exp: The expression with Element replaced? see TODO below
  //  depth():             Depth to the number type at the bottom
  // ************************************************************************************************

  template <typename NewNumber>
  class NumberTrait<NullType, NewNumber> {
  public:
    using InputType = NullType;
    using Type = NullType;
    using ReplacedNumberType = NewNumber;
    using ReplacedElementType = NewNumber;

    constexpr static bool value = true;
    constexpr static size_t depth() {
      return 0;
    }
    inline static size_t size(NullType x) {
      return 0;
    }
    inline static size_t deepsize(NullType x) {
      return 0;
    }
  };


  // built in ordered number types: bool, int, double etc
  template <typename Number, typename NewNumber>
  class
    NumberTrait<Number, NewNumber, typename std::enable_if<std::is_arithmetic<Number>::value>::type> {
  public:
    using InputType = Number;
    using Type = Number;
    using ReplacedNumberType = NewNumber;
    using ReplacedElementType = NewNumber; // this is correct, see comment above

    constexpr static bool value = true;
    constexpr static size_t depth() {
      return 0;
    }
    inline static size_t size(const Number x) {
      return 1;
    }
    inline static size_t deepsize(const Number& x) {
      return 1;
    }
  };

  // complex number enclosing an ordered number
  template <typename Number, typename NewNumber>
  class
    NumberTrait<std::complex<Number>, NewNumber, typename std::enable_if<std::is_arithmetic<Number>::value>::type> {
  public:
    using InputType = std::complex<Number>;
    using Type = std::complex<Number>;
    using ReplacedNumberType = NewNumber;
    using ReplacedElementType = NewNumber; // this is correct, see comment above

    constexpr static bool value = true;
    constexpr static size_t depth() {
      return 0;
    }
    inline static size_t size(const Number x) {
      return 1;
    }
    inline static size_t deepsize(const Number& x) {
      return 1;
    }
  };


  // imaginary number enclosing an ordered number
  template <typename Number, typename NewNumber>
  class
    NumberTrait<Imaginary<Number>, NewNumber, typename std::enable_if<std::is_arithmetic<Number>::value>::type> {
  public:
    using InputType = Imaginary<Number>;
    using Type = Imaginary<Number>;
    using ReplacedNumberType = NewNumber;
    using ReplacedElementType = NewNumber; // this is correct, see comment above

    constexpr static bool value = true;
    constexpr static size_t depth() {
      return 0;
    }
    inline static size_t size(const Number x) {
      return 1;
    }
    inline static size_t deepsize(const Number& x) {
      return 1;
    }
  };

  // quaternion number enclosing an ordered number
  template <typename Number, typename NewNumber>
  class
    NumberTrait<Quaternion<Number>, NewNumber, typename std::enable_if<std::is_arithmetic<Number>::value>::type> {
  public:
    using InputType = Quaternion<Number>;
    using Type = Quaternion<Number>;
    using ReplacedNumberType = NewNumber;
    using ReplacedElementType = NewNumber; // this is correct, see comment above

    constexpr static bool value = true;
    constexpr static size_t depth() {
      return 0;
    }
    inline static size_t size(const Number x) {
      return 1;
    }
    inline static size_t deepsize(const Number& x) {
      return 1;
    }
  };



  //  MultiArray<Element>

  template <typename Element, size_t rank, size_t... ints, typename NewNumber>
  class
    NumberTrait<MultiArray<Element, rank, ints...>, NewNumber> {
  public:
    using InputType = MultiArray<Element, rank, ints...>;
    using Type = typename NumberTrait<Element>::Type;
    using ReplacedNumberType = MultiArray<typename NumberTrait<Element, NewNumber>::ReplacedNumberType, rank, ints...>;
    using ReplacedElementType = MultiArray<NewNumber, rank, ints...>; // this is correct, see comment above

    constexpr static bool value = false;
    constexpr static size_t depth() {
      return 1 + NumberTrait<Element, NewNumber>::depth();
    }
    inline static size_t size(const InputType& x) {
      return x.size();
    }
    inline static size_t deepsize(const InputType& x) {
      return x.deepsize();
    }
  };

  //  MArrayExpR

  template <class Derived, typename Element, typename Number, typename NewNumber, size_t depth_in, size_t rank, class DimensionsT>
  class
    NumberTrait<MArrayExpR<Derived, Element, Number, depth_in, rank, DimensionsT>, NewNumber> {
  public:
    using InputType = MArrayExpR<Derived, Element, Number, depth_in, rank, DimensionsT>;
    using Type = Number;
    using ExpReplacedNumberType = MArrayExpR<Derived, typename NumberTrait<Element, NewNumber>::ReplacedNumberType, NewNumber, depth_in, rank, DimensionsT>;
    using DerivedReplacedNumberType = typename NumberTrait<Derived, NewNumber>::ReplacedNumberType;
    using ReplacedNumberType = DerivedReplacedNumberType;  // this is correct, see comment above
    using ReplacedElementType = MArrayExpR<Derived, NewNumber, Number, depth_in, rank, DimensionsT>;  // TODO: should first slot be DerivedReplacedNumberType? should third slot be NewNumber?  

    constexpr static bool value = false;
    constexpr static size_t depth() {
      return depth_in;
    }
    inline static size_t size(const InputType& x) {
      return x.size();
    }
    inline static size_t deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  MArrayExpRW

  template <class Derived, typename Element, typename Number, typename NewNumber, size_t depth_in, size_t rank, class DimensionsT>
  class
    NumberTrait<MArrayExpRW<Derived, Element, Number, depth_in, rank, DimensionsT>, NewNumber> {
  public:
    using InputType = MArrayExpRW<Derived, Element, Number, depth_in, rank, DimensionsT>;
    using Type = Number;
    using ExpReplacedNumberType = MArrayExpRW<Derived, typename NumberTrait<Element, NewNumber>::ReplacedNumberType, NewNumber, depth_in, rank, DimensionsT>;
    using DerivedReplacedNumberType = typename NumberTrait<Derived, NewNumber>::ReplacedNumberType;
    using ReplacedNumberType = DerivedReplacedNumberType;  // this is correct, see comment above
    using ReplacedElementType = MArrayExpRW<Derived, NewNumber, Number, depth_in, rank, DimensionsT>;  // TODO: should first slot be DerivedReplacedNumberType? should third slot be NewNumber?  

    constexpr static bool value = false;
    constexpr static size_t depth() {
      return depth_in;
    }
    inline static size_t size(const InputType& x) {
      return x.size();
    }
    inline static size_t deepsize(const InputType& x) {
      return x.deepsize();
    }
  };






  // *****************************************************************************************
  // SimpleNumberTrait<T>
  //
  // This operates recursively to find the simple number type for type T
  // We define simple number: as integers, rationals, reals, or subsets thereof.
  // ****************************************************************************************

  template <typename T, typename dummy = void>
  class SimpleNumberTrait {
  public:
    using Type = void;
    constexpr static size_t depth() {
      return 0;
    }
  };

  // for built-in number types (not classes)
  template <typename T>
  class
    SimpleNumberTrait<T, typename std::enable_if<std::is_arithmetic<T>::value>::type> {
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


  template <typename Element, size_t rank, size_t... ints>
  class SimpleNumberTrait<MultiArray<Element, rank, ints...>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };

  template <class Derived, typename Element, typename Number, size_t depth_, size_t rank, class DimensionsT>
  class SimpleNumberTrait<MArrayExpR<Derived, Element, Number, depth_, rank, DimensionsT>> {
  public:
    using Type = typename SimpleNumberTrait<Element>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<Element>::depth();
    }
  };

  template <class Derived, typename Element, typename Number, size_t depth_, size_t rank, class DimensionsT>
  class SimpleNumberTrait<MArrayExpRW<Derived, Element, Number, depth_, rank, DimensionsT>> {
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


  // ***************************************************************************
  // InversionType - turnt he type inside out
  //
  // Use C == NullType to call externally
  // TODO: make this the defualt
  //
  //    example:  Vector<Scalar<double>, NullType>   ->   Scalar<Vector<double>>
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
    using MultiArrayType = typename NumberTrait<MyDeeperType, NewNumber>::ReplacedNumberType;

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
class GridTraits {
  constexpr static bool isMultiArrayOfGrids = false;
  constexpr static bool isGridOfMultiArrays = false;
};

template <typename Number, size_t NDIMS, size_t rank> 
class GridTraits<Number, NDIMS, rank, MultiArrayOfGrids<Number, NDIMS, rank>> {
  constexpr static bool isMultiArrayOfGrids = true;
  constexpr static bool isGridOfMultiArrays = false;
};

template <typename Number, size_t NDIMS, size_t rank> 
class GridTraits<Number, NDIMS, rank, GridOfMultiArrays<Number, NDIMS, rank>> {
  constexpr static bool isMultiArrayOfGrids = false;
  constexpr static bool isGridOfMultiArrays = true;
};



  // ***************************************************************************
  // * RealSet 
  // ***************************************************************************

  template <typename Number>
  class RealSet;


  // ***************************************************************************
  // * RealMultiSet 
  // ***************************************************************************
  template <typename Number, size_t NDIMS = 0, class MULTIGRID = MultiArrayOfGrids<Number, NDIMS>>
  class RealMultiSet;


  // ***************************************************************************
  // * CurvilinearCoordinateSystem 
  // ***************************************************************************
  template <typename Number, size_t NDIMS, typename CHILD>
  class CurvilinearCoordinateSystem;


  // template <typename Element, size_t NDIMS, class CHILD> class CurvilinearCoords;
  // template <typename Element, size_t NDIMS> class CartCoords;
  // template <typename Element> class PolarCoords;

  template <class T = void>
  class Nabla;




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

  template<typename T, std::size_t N>
  constexpr T compile_time_summation(const std::array<T, N>& A) {
    T sum(T(0));
    for (size_t i = 0; i < N; ++i) {
      sum += A[i];
    }
    return sum;
  }

  // note this returns 1 for arrays of size == 0
  template<typename T, std::size_t N>
  constexpr T compile_time_product(const std::array<T, N>& A) {
    T product(T(1));
    for (size_t i = 0; i < N; ++i) {
      product *= A[i];
    }
    return product;
  }



}; // namespace mathq



#endif