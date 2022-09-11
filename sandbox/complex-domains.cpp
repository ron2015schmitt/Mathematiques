#include "mathq.h"


namespace mathq {


};


void title(const std::string& s) {
  using namespace std;
  using namespace mathq;
  using namespace display;

  Style mystyle1 = CREATESTYLE(BOLD + BLUE);
  CR();
  CR();
  MOUT <<  mystyle1.apply(s) << std::endl;
  CR();
}


void subtitle(const std::string& s) {
  using namespace std;
  using namespace mathq;
  using namespace display;

  Style mystyle1 = CREATESTYLE(BLUE);
  CR();
  MOUT <<  mystyle1.apply(s) << std::endl;
  CR();
}


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;
  using namespace display;


  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;



  {
    title("ComplexRegion");
  }

  {
    title("CurvilinearField - Complex 1D");
    ECHO(ComplexRectangle<double> rect);
    ETV(rect);
  }
  {
    title("CurvilinearField - Complex 1D");
    ComplexRectangle<double> rect(
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 5)
    );
    ETV(rect);
    ETV(rect.dims());
    ETV(rect.grid_complex());
    ETV(rect.grid_real());
    ETV(rect.grid_imag());


    ComplexCoords<double, false> coords(rect);
    ETV(coords);
    ETV(coords.grid_dims());
    ETV(IsComplexCoords<decltype(coords)>);
    ETV(coords.x());
    ETV(coords.y());
    ETV(coords.z());

    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(auto& z = coords.z());
    ECHO(field0() = -3*x + 5*Imaginary<double>(1)*x);
    ETV(field0);
    ETV(real(field0));
    ETV(imag(field0));
    ETV(pd(field0, 0));
    ETV(IsMultiArray<decltype(field0)>);
    ETV(IsMultiArray<decltype(field0())>);
    ETV(IsComplex<typename NumberTrait<decltype(field0)>::Type>::value);
    ETV(dz(field0));
    ECHO(field0() = -3*x + 5*Imaginary<double>(1)*y);
    ETV(dz_star(field0));
  }


  {
    title("CurvilinearField - Complex 1D with time");
    ComplexRectangle<double> rect(
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 3)
    );

    ComplexCoords<double, true> coords(rect, Interval<double>::interval(0, 1, 2));
    ETV(coords.z());
    ETV(coords.t());

    // ETV(coords);
    // ETV(coords.grid_dims());
    // ETV(coords[0]);
    // ETV(coords[1]);

    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& z = coords.z());
    ECHO(auto& t = coords.t());
    ECHO(field0() = exp(2*z) + 5*t);
    ETV(field0);
    ETV(pd(field0, 2));

    // ETV(x);

    // ETV(IsGridlike<decltype(x)>);
    // ETV(IsMultiArray<decltype(x)>);
    // ETV(IsWritableExpressionOrArray<decltype(x)>);
    // ETV(x.isNotExpression);
  }


  return 0;
}
