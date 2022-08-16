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


  CurvilinearCoords<NullType, double, 2> tcoords;

  TRDISP(SimpleNumberTrait< CurvilinearCoords<NullType, double, 2> >::depth());

  TRDISP(SimpleNumberTrait< Vector<double> >::depth());
  TRDISP(SimpleNumberTrait< MultiArray<double, 3, 2, 3, 4> >::depth());
  TRDISP(SimpleNumberTrait< MultiArray<std::complex<double>, 3, 2, 3, 4> >::depth());

  TRDISP(SimpleNumberTrait< MultiArray_RepeatVector<double, 3, 2, 3, 4> >::depth());


  TRDISP(IsReadableExpression<Vector<double> >);
  TRDISP(IsReadableExpression<Vector<int> >);
  TRDISP(IsReadableExpression<MultiArray_RepeatVector<double, 3, 2, 3, 4> >);
  TRDISP(IsReadableExpression<std::vector<double> >);
  TRDISP(IsReadableExpression< CurvilinearCoords<NullType, double, 2> >);
  ECHO_CODE(Vector<double> v);
  TRDISP(IsReadableExpression<decltype(v)>);
  TRDISP(IsWritableExpression<decltype(v)>);
  TRDISP(IsReadableExpression<decltype(+v)>);
  TRDISP(IsWritableExpression<decltype(+v)>);

  // std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{}


  // don't need isNumber once we have a concept!

  TRDISP(IsNumber<std::string>);
  TRDISP(IsNumber<double>);
  TRDISP(IsNumber<int>);
  TRDISP(IsNumber<bool>);
  TRDISP(IsNumber<std::complex<double>>);
  TRDISP(IsNumber<Imaginary<double>>);
  TRDISP(IsNumber<Quaternion<double>>);


  TRDISP(IsNumber<string>);
  TRDISP(IsNumber<double>);
  TRDISP(IsNumber<MultiArray<double, 2, 3, 4>>);

  TRDISP(HasStaticSizes<double>);
  TRDISP(HasStaticSizes<Vector<double>>);

  constexpr std::array<size_t, 3> myarray = { 1,4,2 };


  constexpr std::array<size_t, 2> sizes2 = { 4,2 };
  MultiArrayHelper<float, sizes2> B;
  TRDISP(B);

  ECHO_CODE(MultiArrayType<MultiArray<double, 2, 3, 4>> mystery);
  TRDISP(mystery);


  TRDISP(is_all_zeros(myarray));

  constexpr std::array<size_t, 3> zeroarray = { 0,0,0 };
  TRDISP(is_all_zeros(zeroarray));

  ECHO_CODE(MultiArrayType<MultiArray<double, 2>> mystery2);
  TRDISP(mystery2);

  ECHO_CODE(MultiArrayType<MultiArray<double, 3>> mystery3);
  TRDISP(mystery3);


  // test expressions

  // note that we lose the static dims in expressions
  ECHO_CODE(MultiArrayType<decltype(+mystery)> mysteryb);
  TRDISP(mysteryb);


  ECHO_CODE(MultiArrayType<decltype(-mystery2)> mystery2b);
  TRDISP(mystery2b);

  TRDISP(MyTrait< double >::value);
  TRDISP(MyTrait< std::complex<double> >::value);
  TRDISP(MyTrait< Imaginary<double> >::value);
  TRDISP(MyTrait< Quaternion<double> >::value);
  TRDISP(MyTrait< Vector<double> >::value);


  return 0;
}
