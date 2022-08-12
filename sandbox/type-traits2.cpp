#include "mathq.h"


namespace mathq {
  // template<typename T>
  // concept Hashable = requires(T a)
  // {
  //     { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
  // };

  template <typename T>
  concept Test2 = requires(T v, int i) {
    { v.f(i) } -> std::same_as<int>;
  };

  template<typename T>
  concept Container = requires(T& a) {
    a.size();
    a[0];
    // a[(typename T::ElementType)(0)];
    // { a[0] } -> std::same_as<typename T::ElementType>;
    //  { 2.5 } -> std::same_as<double>;  // works
    //  { 2.5 } -> std::same_as<typename T::ElementType>;  // works
    { a[0u] } -> std::same_as<typename T::ElementType&>; // works, need reference
  };



  /// Structure which wants to consume the array via a parameter pack.
  template <typename StructuralType, StructuralType... s>
  struct ConsumerStruct {
    constexpr auto operator()() const { return std::array{ s... }; }
  };

  template <
    auto arr,
    template <typename X, X...> typename Consumer,
    typename IS = decltype(std::make_index_sequence<arr.size()>())
  >
  struct Generator;

  template <
    auto arr,
    template <typename X, X...> typename Consumer,
    std::size_t... I
  >
  struct Generator<arr, Consumer, std::index_sequence<I...>> {
    using type = Consumer<typename decltype(arr)::value_type, arr[I]...>;
  };

  /// Helper typename
  template <
    auto arr,
    template <typename T, T...> typename Consumer
  >
  using Generator_t = typename Generator<arr, Consumer>::type;






  template <
    auto arr,
    template <size_t...> typename Consumer,
    typename IS = decltype(std::make_index_sequence<arr.size()>())
  >
  struct Generator2;

  template <
    auto arr,
    template <size_t...> typename Consumer,
    std::size_t... I
  >
  struct Generator2<arr, Consumer, std::index_sequence<I...>> {
    using type = Consumer<arr[I]...>;
  };

  /// Helper typename
  template <
    auto arr,
    template <size_t...> typename Consumer
  >
  using Generator_t2 = typename Generator2<arr, Consumer>::type;




  template <
    auto arr,
    typename IS = decltype(std::make_index_sequence<arr.size()>())
  >
  struct Material;

  template <
    auto arr,
    std::size_t... I
  >
  struct Material<arr, std::index_sequence<I...>> {
    using Type = ConsumerStruct<size_t, arr[I]...>;
  };



  template <
    auto arr,
    typename IS = decltype(std::make_index_sequence<arr.size()>())
  >
  struct Material2;

  template <
    auto arr,
    std::size_t... I
  >
  struct Material2<arr, std::index_sequence<I...>> {
    using Type = MultiArray<double, 3, arr[I]...>;
  };














  template <Container T>
  class SimpleNumberTrait<T> {
  public:
    using ElementType = typename T::ElementType;
    using Type = typename SimpleNumberTrait<ElementType>::Type;
    constexpr static size_t depth() {
      return 1 + SimpleNumberTrait<ElementType>::depth();
    }
  };



  template <size_t... ints>
  class IntsOwner {
  public:
  };

  template <typename T, T... I>
  auto get_owner(std::integer_sequence<T, I...>) {
    return IntsOwner< T(I)... >();
  }


};


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;


  CurvilinearCoords<NullType, double, 2> tcoords;

  TRDISP(SimpleNumberTrait< CurvilinearCoords<NullType, double, 2> >::depth());

  TRDISP(SimpleNumberTrait< Vector<double> >::depth());
  TRDISP(SimpleNumberTrait< MultiArray<double, 3, 2, 3, 4> >::depth());
  TRDISP(SimpleNumberTrait< MultiArray<std::complex<double>, 3, 2, 3, 4> >::depth());

  TRDISP(SimpleNumberTrait< MultiArray_RepeatVector<double, 3, 2, 3, 4> >::depth());

  TRDISP(Container<Vector<double> >);
  TRDISP(Container<Vector<int> >);
  TRDISP(Container<MultiArray_RepeatVector<double, 3, 2, 3, 4> >);
  TRDISP(Container<std::vector<double> >);
  TRDISP(Container< CurvilinearCoords<NullType, double, 2> >);


  TRDISP(ReadableExpression<Vector<double> >);
  TRDISP(ReadableExpression<Vector<int> >);
  TRDISP(ReadableExpression<MultiArray_RepeatVector<double, 3, 2, 3, 4> >);
  TRDISP(ReadableExpression<std::vector<double> >);
  TRDISP(ReadableExpression< CurvilinearCoords<NullType, double, 2> >);
  ECHO_CODE(Vector<double> v);
  TRDISP(ReadableExpression<decltype(v)>);
  TRDISP(WritableExpression<decltype(v)>);
  TRDISP(ReadableExpression<decltype(+v)>);
  TRDISP(WritableExpression<decltype(+v)>);

  // std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{}


  ECHO_CODE(IntsOwner<1, 4, 2>{});

  constexpr std::array<size_t, 3> myarray = { 1,4,2 };
  constexpr Generator_t<myarray, ConsumerStruct> tt;
  TRDISP(tt());

  Generator_t2<myarray, IntsOwner> tt2;

  Material<myarray>::Type tt3;
  TRDISP(tt3());

  Material2<myarray>::Type A;
  TRDISP(A);

  constexpr std::array<size_t, 2> sizes2 = { 4,2 };
  MultiArrayHelper<float, sizes2> B;
  TRDISP(B);

  // MultiArray<double, 4> A2;
  // ECHO_CODE(MultiArrayType<decltype(A2)> mystery);
  // TRDISP(mystery);

  // ECHO_CODE( IntsOwner< std::make_index_sequence<3>()... >{} );

  TRDISP(IsNumber<std::string>::value);
  TRDISP(IsNumber<double>::value);
  TRDISP(IsNumber<int>::value);
  TRDISP(IsNumber<bool>::value);
  TRDISP(IsNumber<std::complex<double>>::value);
  TRDISP(IsNumber<Imaginary<double>>::value);
  TRDISP(IsNumber<Quaternion<double>>::value);


  return 0;
}
