#include "mathq.h"

template<size_t N, size_t... ints>
constexpr std::array<size_t, N> compile_time_fill_array() {
  return std::array<size_t, N>{ (static_cast<size_t>(ints))... };
}




int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  cout << "IsReadableExpressionOrArray" << std::endl;
  cout << "double: " << IsReadableExpressionOrArray<double> << "\n";
  cout << "Vector: " << IsReadableExpressionOrArray<Vector<double>> << "\n";
  cout << "Matrix: " << IsReadableExpressionOrArray<Matrix<double, 4, 2>> << "\n";
  cout << "MultiArray: " << IsReadableExpressionOrArray<MultiArray<double, 3, 2, 3, 4>> << "\n";
  cout << "Vector_Constant: " << IsReadableExpressionOrArray<Vector_Constant<double>> << "\n";
  cout << "ExpressionR: " << IsReadableExpressionOrArray<ExpressionR<Vector<double>, double, double, 1, 1>> << "\n";
  cout << "ExpressionRW: " << IsReadableExpressionOrArray<ExpressionRW<Vector<double>, double, double, 1, 1>> << "\n";
  cout << std::endl;

  cout << "IsWritableExpressionOrArray" << std::endl;
  cout << "double: " << IsWritableExpressionOrArray<double> << "\n";
  cout << "Vector: " << IsWritableExpressionOrArray<Vector<double>> << "\n";
  cout << "Matrix: " << IsWritableExpressionOrArray<Matrix<double, 4, 2>> << "\n";
  cout << "MultiArray: " << IsWritableExpressionOrArray<MultiArray<double, 3, 2, 3, 4>> << "\n";
  cout << "Vector_Constant: " << IsWritableExpressionOrArray<Vector_Constant<double>> << "\n";
  cout << "ExpressionR: " << IsWritableExpressionOrArray<ExpressionR<Vector<double>, double, double, 1, 1>> << "\n";
  cout << "ExpressionRW: " << IsWritableExpressionOrArray<ExpressionRW<Vector<double>, double, double, 1, 1>> << "\n";
  cout << std::endl;

  cout << "IsMultiArray" << std::endl;
  cout << "double: " << IsMultiArray<double> << "\n";
  cout << "Vector: " << IsMultiArray<Vector<double>> << "\n";
  cout << "Matrix: " << IsMultiArray<Matrix<double, 4, 2>> << "\n";
  cout << "MultiArray: " << IsMultiArray<MultiArray<double, 3, 2, 3, 4>> << "\n";
  cout << "Vector_Constant: " << IsMultiArray<Vector_Constant<double>> << "\n";
  cout << "ExpressionR: " << IsMultiArray<ExpressionR<Vector<double>, double, double, 1, 1>> << "\n";
  cout << std::endl;

  cout << "IsReadableExpression" << std::endl;
  cout << "double: " << IsReadableExpression<double> << "\n";
  cout << "Vector: " << IsReadableExpression<Vector<double>> << "\n";
  // cout << "Vector_Constant: " << IsReadableExpression<Vector_Constant<double>> << "\n";
  cout << "ExpressionR: " << IsReadableExpression<ExpressionR<Vector<double>, double, double, 1, 1>> << "\n";
  cout << "ExpressionRW: " << IsReadableExpression<ExpressionRW<Vector<double>, double, double, 1, 1>> << "\n";
  cout << std::endl;

  cout << "IsWritableExpression" << std::endl;
  cout << "double: " << IsWritableExpression<double> << "\n";
  cout << "Vector: " << IsWritableExpression<Vector<double>> << "\n";
  // cout << "Vector_Constant: " << IsWritableExpression<Vector_Constant<double>> << "\n";
  cout << "ExpressionR: " << IsWritableExpression<ExpressionR<Vector<double>, double, double, 1, 1>> << "\n";
  cout << "ExpressionRW: " << IsWritableExpression<ExpressionRW<Vector<double>, double, double, 1, 1>> << "\n";
  cout << std::endl;


  cout << "NumberTrait" << std::endl;
  // TRDISP(NumberTrait<NullType>::Type());    // causes compile error
  TRDISP(NumberTrait<int>::Type());
  TRDISP(NumberTrait<double>::Type());
  TRDISP(NumberTrait<std::complex<double>>::Type());
  // TRDISP(NumberTrait<std::complex<Vector<bool>>>::Type());
  typename NumberTrait<Vector<double>>::Type x;
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
  TRDISP(SimpleNumberTrait<NullType>::Type());    // causes compile error
  TRDISP(SimpleNumberTrait<int>::Type());
  TRDISP(SimpleNumberTrait<double>::Type());
  TRDISP(SimpleNumberTrait<std::complex<double>>::Type());
  TRDISP(SimpleNumberTrait<std::complex<Vector<bool>>>::Type());
  TRDISP(SimpleNumberTrait<Vector<double>>::Type());
  TRDISP(SimpleNumberTrait<Vector<std::complex<double>>>::Type());
  TRDISP(SimpleNumberTrait<ExpressionR<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::Type());
  TRDISP(SimpleNumberTrait<ExpressionRW<Vector<std::complex<double>>, std::complex<double>, double, 1, 1>>::Type());
  cout << std::endl;


  cout << "ReplaceElementTrait" << std::endl;
  TRDISP(ReplaceElementTrait<Vector<double, 1>, int>::Type());
  TRDISP(ReplaceElementTrait<Vector<std::complex<double>, 1>, float>::Type());
  TRDISP(ReplaceElementTrait<Matrix<Vector<std::complex<double>, 1>, 3, 4>, Quaternion<float> >::Type());
  TRDISP(ReplaceElementTrait< Matrix<Vector<std::complex<double>, 1>, 3, 4>, MultiArray<Quaternion<float>, 3, 1, 2, 3> >::Type());

  cout << "ReplaceNumberTrait" << std::endl;
  TRDISP(ReplaceNumberTrait<Vector<double, 1>, int>::Type());
  TRDISP(ReplaceNumberTrait<Vector<std::complex<double>, 1>, float>::Type());
  TRDISP(ReplaceNumberTrait<Matrix<Vector<std::complex<double>, 1>, 3, 4>, Quaternion<float> >::Type());


  cout << "ReplaceSimpleNumberTrait" << std::endl;
  TRDISP(ReplaceSimpleNumberTrait<Vector<double, 1>, int>::Type());
  TRDISP(ReplaceSimpleNumberTrait<Vector<std::complex<double>, 1>, float>::Type());
  TRDISP(ReplaceSimpleNumberTrait<Matrix<Vector<std::complex<double>, 1>, 3, 4>, float >::Type());



  return 0;
}
