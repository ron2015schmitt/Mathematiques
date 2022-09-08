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
    TRDISP(rect);
  }
  {
    title("CurvilinearField - Complex 1D");
    ComplexRectangle<double> rect(
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 5)
    );
    TRDISP(rect);
    TRDISP(rect.dims());
    TRDISP(rect.grid_complex());
    TRDISP(rect.grid_real());
    TRDISP(rect.grid_imag());


    ComplexCoords<double, false> coords(rect);
    TRDISP(coords);
    TRDISP(coords.grid_dims());
    TRDISP(IsComplexCoords<decltype(coords)>);
    TRDISP(coords.x());
    TRDISP(coords.y());
    TRDISP(coords.z());

    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(auto& z = coords.z());
    ECHO(field0() = -3*x + 5*Imaginary<double>(1)*x);
    TRDISP(field0);
    TRDISP(real(field0));
    TRDISP(imag(field0));
    TRDISP(pd(field0, 0));
    TRDISP(IsMultiArray<decltype(field0)>);
    TRDISP(IsMultiArray<decltype(field0())>);
    TRDISP(IsComplex<typename NumberTrait<decltype(field0)>::Type>::value);
    TRDISP(dz(field0));
    ECHO(field0() = -3*x + 5*Imaginary<double>(1)*y);
    TRDISP(dz_star(field0));
  }


  {
    title("CurvilinearField - Complex 1D with time");
    ComplexRectangle<double> rect(
      Interval<double>::interval(-1, 1, 5),
      Interval<double>::interval(-2, 2, 3)
    );

    ComplexCoords<double, true> coords(rect, Interval<double>::interval(0, 1, 2));
    TRDISP(coords.z());
    TRDISP(coords.t());

    // TRDISP(coords);
    // TRDISP(coords.grid_dims());
    // TRDISP(coords[0]);
    // TRDISP(coords[1]);

    ECHO(ComplexMathFunction<std::complex<double>, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& z = coords.z());
    ECHO(auto& t = coords.t());
    ECHO(field0() = exp(2*z) + 5*t);
    TRDISP(field0);
    TRDISP(pd(field0, 2));

    // TRDISP(x);

    // TRDISP(IsGridlike<decltype(x)>);
    // TRDISP(IsMultiArray<decltype(x)>);
    // TRDISP(IsWritableExpressionOrArray<decltype(x)>);
    // TRDISP(x.isNotExpression);
  }


  return 0;
}
