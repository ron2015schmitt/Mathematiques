#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>


#include "mathq.h"

inline double fradius2(double x, double y) { return  std::sqrt(x*x + y*y); }
inline double fradius3d_2(double x, double y, double z) { return  std::sqrt(x*x + y*y + z*z); }



int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;
  using namespace mathq;


  CR();
  CR();

  using namespace mathq::unit_quaternion;
  using namespace mathq::unit_imaginary;

  using std::sqrt;

  GMD_HEADER2("Introduction");





  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER3("Grids, Functions, and Vector Calculus");

  CR();
  CR();


  // TODO: give in terms of the size of the data
  GMD_CODE_START("C++");
  CR();

  Nabla d1;
  TRDISP(d1);

  TargetSet<std::complex<double>> u(1, 0);
  TRDISP(u);


  ECHO_CODE(Domain<double> domX(-1, 1, 5));
  TRDISP(domX);

  ECHO_CODE(auto gridX0 = domX.getGrid());
  TRDISP(domX);
  TRDISP(gridX0);

  Vector<double, 5> g;
  for (size_type i = 0; i<5; i++) {
    g(i) = domX.get(i);
  }
  TRDISP(g);

  auto gridX = grid(domX);
  TRDISP(gridX);

  Domain<double> ry(0, 3, 4);
  TRDISP(ry);


  DISP({ 1,2 });
  TRDISP({ 1,2 });
  ECHO_CODE(MultiDomain<double> domXY({ domX, ry }));
  TRDISP(domXY);
  ECHO_CODE(MultiDomain<double> domXY2({ Domain<double>(-1, 1, 5), Domain<double>(0, 3, 4) }));
  TRDISP(domXY2);
  MultiDomain<double> domXY3(domXY2);
  TRDISP(domXY3);
  // MultiDomain<double> domXY4(domXY2.domains);
  // TRDISP(domXY4);


  Domain<double> rz(10, 11, 2);
  TRDISP(rz);


  auto divX = grad(grid(domX), domX);
  TRDISP(divX);
  Domain<double> rx2(-10, 10, 21);
  auto gridX2 = grid(rx2);
  TRDISP(gridX2);
  auto gradX2 = grad(gridX2, rx2);
  TRDISP(gradX2);
  auto gradX2_2 = nabla_old & pair(gridX2, rx2);
  TRDISP(gradX2_2);

  TRDISP(sqr(gridX + 2));
  std::function<double(double)> func = [](double d) {  return mathq::sqr(d+2); };
  TRDISP(func(-3));
  TRDISP(fgrid(func, gridX));
  double (*func2)(double) = &std::exp;
  TRDISP(func2(1));
  TRDISP(fgrid(func2, gridX));  // doesnt work
  TRDISP(static_cast<double (*)(double)>(&std::exp)(1));
  std::function<double(double)> func3 = static_cast<double (*)(double)>(&std::exp);
  TRDISP(func3(1));
  TRDISP(fgrid(func3, gridX));
  std::function<double(double)> func4 = [](double d) {  return std::exp(d); };
  TRDISP(func4(-3));
  TRDISP(fgrid(func4, gridX));
  CR();
  TRDISP(ry);
  TRDISP(grid(ry));
  TRDISP(rz);
  TRDISP(grid(rz));
  auto gridXY = grid(domX, ry);
  TRDISP(gridXY(0));
  TRDISP(gridXY(1));


  std::function<double(double, double)> fradius = [](double x, double y) {  return std::sqrt(x*x + y*y); };
  auto R = fgrid(fradius, gridXY);
  TRDISP(R);
  auto R2 = fgrid(fradius2, gridXY);
  TRDISP(R2);

  auto gradXY = grad(R, domX, ry);
  TRDISP(gradXY(0));
  TRDISP(gradXY(1));
  gradXY = nabla_old & std::make_tuple(R, domX, ry);
  TRDISP(gradXY(0));
  TRDISP(gradXY(1));



  CR();
  auto gridXYZ = grid(domX, ry, rz);
  TRDISP(gridXYZ(0));
  TRDISP(gridXYZ(1));
  TRDISP(gridXYZ(2));
  std::function<double(double, double, double)> fradius3d = [](double x, double y, double z) {  return std::sqrt(x*x + y*y + z*z); };
  auto R3D = fgrid(fradius3d, gridXYZ);
  TRDISP(R3D);
  auto R3D_2 = fgrid(fradius3d_2, gridXYZ);
  TRDISP(R3D_2);
  GMD_CODE_END();



  return 0;
}
