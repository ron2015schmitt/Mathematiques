#include "mathq.h"

template<size_t N, size_t... ints>
constexpr std::array<size_t  , N> compile_time_fill_array() {
  return std::array<size_t  , N>{ (static_cast<size_t>(ints))... };
}




int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  cout << "IsMultiArrayOrExpression" << std::endl;
  cout << "double: " << IsMultiArrayOrExpression<double>::value << "\n";
  cout << "Vector: " << IsMultiArrayOrExpression<Vector<double>>::value << "\n";
  cout << "ExpressionR: " << IsMultiArrayOrExpression<ExpressionR<Vector<double>, double, double, 1, 1>>::value << "\n";
  cout << "ExpressionRW: " << IsMultiArrayOrExpression<ExpressionRW<Vector<double>, double, double, 1, 1>>::value << "\n";
  cout << std::endl;

  cout << "IsMultiArray" << std::endl;
  cout << "double: " << IsMultiArray<double>::value << "\n";
  cout << "Vector: " << IsMultiArray<Vector<double>>::value << "\n";
  cout << "ExpressionR: " << IsMultiArray<ExpressionR<Vector<double>, double, double, 1, 1>>::value << "\n";
  cout << std::endl;

  cout << "IsMultiArrayExp" << std::endl;
  cout << "double: " << IsMultiArrayExp<double>::value << "\n";
  cout << "Vector: " << IsMultiArrayExp<Vector<double>>::value << "\n";
  cout << "ExpressionR: " << IsMultiArrayExp<ExpressionR<Vector<double>, double, double, 1, 1>>::value << "\n";
  cout << "ExpressionRW: " << IsMultiArrayExp<ExpressionRW<Vector<double>, double, double, 1, 1>>::value << "\n";
  cout << std::endl;

  cout << "IsMultiArrayExpRW" << std::endl;
  cout << "double: " << IsMultiArrayExpRW<double>::value << "\n";
  cout << "Vector: " << IsMultiArrayExpRW<Vector<double>>::value << "\n";
  cout << "ExpressionR: " << IsMultiArrayExpRW<ExpressionR<Vector<double>, double, double, 1, 1>>::value << "\n";
  cout << "ExpressionRW: " << IsMultiArrayExpRW<ExpressionRW<Vector<double>, double, double, 1, 1>>::value << "\n";
  cout << std::endl;


  cout << "NumberTrait" << std::endl;
  // TRDISP(NumberTrait<NullType>::Type());    // causes compile error
  TRDISP(NumberTrait<int>::Type());
  TRDISP(NumberTrait<double>::Type());
  TRDISP(NumberTrait<std::complex<double>>::Type());
  // TRDISP(NumberTrait<std::complex<Vector<bool>>>::Type());
  typename NumberTrait<Vector<double>>::Type x;
  TRDISP(ReplacedNumberTrait<Vector<double, 1>, double>::Type());
  TRDISP(NumberTrait<Vector<std::complex<double>>>::Type());
  TRDISP(NumberTrait<ExpressionR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::Type());
  TRDISP(NumberTrait<ExpressionRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::Type());
  cout << std::endl;

  cout << "NumberTrait" << std::endl;
  // TRDISP(NumberTrait<NullType>::depth());    // causes compile error
  DISP(NumberTrait<int>::depth());
  DISP(NumberTrait<double>::depth());
  DISP(NumberTrait<std::complex<double>>::depth());
  // DISP(NumberTrait<std::complex<Vector<bool>>>::depth());
  DISP(NumberTrait<Vector<double>>::depth());
  DISP(NumberTrait<Vector<std::complex<double>>>::depth());
  DISP(NumberTrait<ExpressionR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::depth());
  DISP(NumberTrait<ExpressionRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::depth());
  cout << std::endl;


  cout << "SimpleNumberTrait" << std::endl;
  // TRDISP(SimpleNumberTrait<NullType>::Type());    // causes compile error
  TRDISP(SimpleNumberTrait<int>::Type());
  TRDISP(SimpleNumberTrait<double>::Type());
  TRDISP(SimpleNumberTrait<std::complex<double>>::Type());
  TRDISP(SimpleNumberTrait<std::complex<Vector<bool>>>::Type());
  TRDISP(SimpleNumberTrait<Vector<double>>::Type());
  TRDISP(SimpleNumberTrait<Vector<std::complex<double>>>::Type());
  TRDISP(SimpleNumberTrait<ExpressionR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::Type());
  TRDISP(SimpleNumberTrait<ExpressionRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::Type());
  cout << std::endl;

  cout << "SimpleNumberTrait" << std::endl;
  // TRDISP(SimpleNumberTrait<NullType>::depth());    // causes compile error
  DISP(SimpleNumberTrait<int>::depth());
  DISP(SimpleNumberTrait<double>::depth());
  DISP(SimpleNumberTrait<std::complex<double>>::depth());
  DISP(SimpleNumberTrait<std::complex<Vector<bool>>>::depth());
  DISP(SimpleNumberTrait<Vector<double>>::depth());
  DISP(SimpleNumberTrait<Vector<std::complex<double>>>::depth());
  DISP(SimpleNumberTrait<ExpressionR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::depth());
  DISP(SimpleNumberTrait<ExpressionRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::depth());
  cout << std::endl;

  std::array<size_t  , 7> ron{ 1, 5};

  TRDISP(ron);


  return 0;
}
