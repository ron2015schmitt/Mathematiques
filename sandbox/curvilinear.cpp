#include "mathq.h"


 namespace mathq{ 
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
concept Container = requires(T& a)
{
    a.size();
    a[0];
    // a[(typename T::ElementType)(0)];
    // { a[0] } -> std::same_as<typename T::ElementType>;
    //  { 2.5 } -> std::same_as<double>;  // works
    //  { 2.5 } -> std::same_as<typename T::ElementType>;  // works
    { a[0u] } -> std::same_as<typename T::ElementType&>; // works, need reference
};




template <class X, class Element, typename Number, size_t depth, size_t rank>
bool readable_expression_test(const ExpressionR<X, Element, Number, depth, rank>& x) {
  return true;
}

template <class X, class Element, typename Number, size_t depth, size_t rank>
bool writable_expression_test(const ExpressionRW<X, Element, Number, depth, rank>& x) {
  return true;
}


template <class X>
concept ReadableExpression = requires(X x) 
{ 
  readable_expression_test(x);
};


template <class X>
concept WritableExpression = requires(X x) 
{ 
  writable_expression_test(x);
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

 };


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;


  CurvilinearCoords<NullType, double, 2> tcoords;

  TRDISP( SimpleNumberTrait< CurvilinearCoords<NullType, double, 2> >::depth());

  TRDISP( SimpleNumberTrait< Vector<double> >::depth());
  TRDISP( SimpleNumberTrait< MultiArray<double,3, 2,3,4> >::depth());
  TRDISP( SimpleNumberTrait< MultiArray<std::complex<double>,3, 2,3,4> >::depth());

  TRDISP( SimpleNumberTrait< MultiArray_RepeatVector<double,3, 2,3,4> >::depth());

  TRDISP(Container<Vector<double> >);
  TRDISP(Container<Vector<int> >);
  TRDISP(Container<MultiArray_RepeatVector<double,3, 2,3,4> >);
  TRDISP(Container<std::vector<double> >);
  TRDISP(Container< CurvilinearCoords<NullType, double, 2> >);


  TRDISP(ReadableExpression<Vector<double> >);
  TRDISP(ReadableExpression<Vector<int> >);
  TRDISP(ReadableExpression<MultiArray_RepeatVector<double,3, 2,3,4> >);
  TRDISP(ReadableExpression<std::vector<double> >);
  TRDISP(ReadableExpression< CurvilinearCoords<NullType, double, 2> >);
  ECHO_CODE(Vector<double> v);
  TRDISP(ReadableExpression<decltype(v)>);
  TRDISP(WritableExpression<decltype(v)>);
  TRDISP(ReadableExpression<decltype(+v)>);
  TRDISP(WritableExpression<decltype(+v)>);

  // TRDISP(std::is_base_of_v< ExpressionRW<Vector<double>, double, double, 1, 1>, Vector<double> >);
  // using X = typename SimpleNumberTrait< MultiArray<std::complex<double>,3, 2,3,4> >::Type;
  // using X = typename SimpleNumberTrait< MultiArray_RepeatVector<double,3, 2,3,4> >::Type;
  // X x;
  // TRDISP(x);

  
  return 0;
}
