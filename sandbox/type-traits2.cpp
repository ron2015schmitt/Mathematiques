#include "mathq.h"


namespace mathq {


  template <typename T>
  class MyTrait {
  public:
    constexpr static int value = 0;
  };

  template <IsAdvancedNumber T>
  class MyTrait<T> {
  public:
    constexpr static int value = 1;
  };

  template <typename Num>
  class MyTrait<std::complex<Num>> {
  public:
    constexpr static int value = 20;
  };
  template <typename Num>
  class MyTrait<Imaginary<Num>> {
  public:
    constexpr static int value = 21;
  };



  // template <class Derived, typename Element, typename Num, size_t depth, size_t rank>
  // class MyTrait< ExpressionR<Derived, Element, Num, depth, rank> > {
  // public:
  //   constexpr static int value = 100;
  // };

  //  MultiArray<Element>
  // template <typename Element, size_t rank, size_t... ints>
  // class MyTrait<MultiArray<Element, rank, ints...>> {
  // public:
  //   constexpr static int value = 200;
  // };


};


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;


  CurvilinearCoords<double, 2, false, NullType> tcoords;

  ETV(SimpleNumberTrait< CurvilinearCoords<double, 2, false, NullType> >::Type());

  ETV(SimpleNumberTrait< Vector<double> >::Type());
  ETV(SimpleNumberTrait< MultiArray<double, 3, 2, 3, 4> >::Type());
  ETV(SimpleNumberTrait< MultiArray<std::complex<double>, 3, 2, 3, 4> >::Type());

  ETV(SimpleNumberTrait< MultiArray_RepeatVector<double, 3, 2, 3, 4> >::Type());


  ETV(IsReadableExpressionOrArray<Vector<double> >);
  ETV(IsReadableExpressionOrArray<Vector<int> >);
  ETV(IsReadableExpressionOrArray<MultiArray_RepeatVector<double, 3, 2, 3, 4> >);
  ETV(IsReadableExpressionOrArray<std::vector<double> >);
  ETV(IsReadableExpressionOrArray< CurvilinearCoords<double, 2, false, NullType> >);
  ECHO(Vector<double> v);
  ETV(IsReadableExpressionOrArray<decltype(v)>);
  ETV(IsWritableExpressionOrArray<decltype(v)>);
  ETV(IsReadableExpressionOrArray<decltype(+v)>);
  ETV(IsWritableExpressionOrArray<decltype(+v)>);

  // std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{}


  // don't need isNumber once we have a concept!

  ETV(IsNumber<std::string>);
  ETV(IsNumber<double>);
  ETV(IsNumber<int>);
  ETV(IsNumber<bool>);
  ETV(IsNumber<std::complex<double>>);
  ETV(IsNumber<Imaginary<double>>);
  ETV(IsNumber<Quaternion<double>>);


  ETV(IsNumber<string>);
  ETV(IsNumber<double>);
  ETV(IsNumber<MultiArray<double, 2, 3, 4>>);

  ETV(HasStaticSizes<double>);
  ETV(HasStaticSizes<Vector<double>>);

  constexpr std::array<size_t, 3> myarray = { 1,4,2 };


  constexpr std::array<size_t, 2> sizes2 = { 4,2 };
  MultiArrayHelper<float, sizes2> B;
  ETV(B);

  ECHO(MultiArrayType<MultiArray<double, 2, 3, 4>> mystery);
  ETV(mystery);


  ETV(is_all_zeros(myarray));

  constexpr std::array<size_t, 3> zeroarray = { 0,0,0 };
  ETV(is_all_zeros(zeroarray));

  ECHO(MultiArrayType<MultiArray<double, 2>> mystery2);
  ETV(mystery2);

  ECHO(MultiArrayType<MultiArray<double, 3>> mystery3);
  ETV(mystery3);

  ECHO(MultiArrayType<Vector_Constant<double, 3>> mystery4);
  ETV(mystery4);

  ECHO(MultiArrayType<MultiArray_RepeatVector<double, 3, 4, 6, 7>> mystery5);
  ETV(mystery5);


  ECHO(MultiArrayType<CurvilinearCoords<double, 2, false, NullType>> mystery6);
  ETV(mystery6);

  // test expressions

  // note that we lose the static dims in expressions
  ECHO(MultiArrayType<decltype(+mystery)> mysteryb);
  ETV(mysteryb);


  ECHO(MultiArrayType<decltype(-mystery2)> mystery2b);
  ETV(mystery2b);

  ETV(MyTrait< double >::value);
  ETV(MyTrait< std::complex<double> >::value);
  ETV(MyTrait< Imaginary<double> >::value);
  ETV(MyTrait< Quaternion<double> >::value);
  ETV(MyTrait< Vector<double> >::value);



  return 0;
}
