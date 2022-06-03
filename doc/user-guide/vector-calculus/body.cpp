#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>
#include <variant>
#include <cmath>
#include "mathq.h"

inline double fradius2(double x, double y) { return  std::sqrt(x*x + y*y); }
inline double fradius3d_2(double x, double y, double z) { return  std::sqrt(x*x + y*y + z*z); }








int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


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

  // TargetSet<std::complex<double>> u(1, 0);
  // TRDISP(u);

  // ECHO_CODE(GridSet<double> gs);
  // TRDISP(gs);

  // ECHO_CODE(Interval<double> x_interval(-1, 1, 5));
  // TRDISP(x_interval);

  CR();
  ECHO_CODE(RealSet<double>  rs(-2, +2, 5));
  TRDISP(rs);
  TRDISP(rs.makeGrid());
  TRDISP(rs.hasInflatedGrid());

  CR();
  ECHO_CODE(RealSet<double>  rs1(-2, +3, 5, GridScale::LINEAR, true, false));
  TRDISP(rs1);
  TRDISP(rs1.makeGrid());
  TRDISP(rs1.hasInflatedGrid());


  CR();
  ECHO_CODE(RealSet<double>  rs2 = RealSet<double>::realLine());
  TRDISP(rs2);

  CR();
  ECHO_CODE(RealSet<double>  rs3(10, 1e5, 10, GridScale::LOG));
  TRDISP(rs3);
  TRDISP(rs3.makeGrid());
  TRDISP(mathq::log10(rs3.makeGrid()));
  TRDISP(rs3.hasInflatedGrid());


  CR();
  ECHO_CODE(auto rs4 = RealSet<double>::point(2.5));
  TRDISP(rs4);
  TRDISP(rs4.makeGrid());
  TRDISP(rs4.hasInflatedGrid());


  CR();
  ECHO_CODE(RealSet<double> rx(-2, +2, 5));
  TRDISP(rx);

  CR();
  ECHO_CODE(RealSet<double> ry(1, 100, 3, GridScale::LOG));
  TRDISP(ry);
  TRDISP(ry.makeGrid());

  // CR();
  // auto setXY = std::make_tuple(rx, ry);
  // TRDISP(std::get<0>(setXY));
  // TRDISP(std::get<1>(setXY));

  CR();
  ECHO_CODE(RealSetN<double> setXY({rx, ry}));
  TRDISP(setXY);
  TRDISP(setXY[0]);
  TRDISP(setXY[1]);



  // ECHO_CODE(Coordinate2<double, Interval> x_coord2("x", x_interval));
  // TRDISP(x_coord2.gridSet);
  // TRDISP(x_coord);
  // ECHO_CODE(Coordinate<double> y_coord("y"));
  // TRDISP(y_coord);

  // ECHO_CODE(Coordinates<double> xy_coords("xy",{x_coord, y_coord}) );
  // TRDISP(xy_coords);

  // ECHO_CODE(Coordinates<double> xy_coords2("xy",{"x","y"}) );
  // TRDISP(xy_coords2);




  // ECHO_CODE(Interval<double> y_interval("y", 0, 3, 4));
  // TRDISP(y_interval);


  // ECHO_CODE(auto gridX0 = x_interval.makeGrid());
  // TRDISP(x_interval);
  // TRDISP(gridX0);

  // Vector<double, 5> g;
  // for (size_type i = 0; i<5; i++) {
  //   g(i) = x_interval.get(i);
  // }
  // TRDISP(g);

  // auto gridX = grid(x_interval);
  // TRDISP(gridX);


  // ECHO_CODE(Region<double> xy_region("Cartesian-2D", { x_interval, y_interval }));
  // TRDISP(xy_region);
  // TRDISP(xy_region[0]);
  // TRDISP(xy_region["x"]);

  // ECHO_CODE(Region<double> domXY2({ Interval<double>(-10, 10, 5), Interval<double>(0, 7, 4) }));
  // TRDISP(domXY2);
  // Region<double> domXY3(domXY2);
  // TRDISP(domXY3);
  // // Region<double> domXY4(domXY2.domains);
  // // TRDISP(domXY4);


  // Interval<double> rz(10, 11, 2);
  // TRDISP(rz);


  // auto divX = grad(grid(x_interval), x_interval);
  // TRDISP(divX);
  // Interval<double> rx2(-10, 10, 21);
  // auto gridX2 = grid(rx2);
  // TRDISP(gridX2);
  // auto gradX2 = grad(gridX2, rx2);
  // TRDISP(gradX2);
  // auto gradX2_2 = nabla_old & pair(gridX2, rx2);
  // TRDISP(gradX2_2);

  // TRDISP(sqr(gridX + 2));
  // std::function<double(double)> func = [](double d) {  return mathq::sqr(d+2); };
  // TRDISP(func(-3));
  // TRDISP(fgrid(func, gridX));
  // double (*func2)(double) = &std::exp;
  // TRDISP(func2(1));
  // TRDISP(fgrid(func2, gridX));  // doesnt work
  // TRDISP(static_cast<double (*)(double)>(&std::exp)(1));
  // std::function<double(double)> func3 = static_cast<double (*)(double)>(&std::exp);
  // TRDISP(func3(1));
  // TRDISP(fgrid(func3, gridX));
  // std::function<double(double)> func4 = [](double d) {  return std::exp(d); };
  // TRDISP(func4(-3));
  // TRDISP(fgrid(func4, gridX));
  // CR();
  // TRDISP(y_interval);
  // TRDISP(grid(y_interval));
  // TRDISP(rz);
  // TRDISP(grid(rz));
  // auto gridXY = grid(x_interval, y_interval);
  // TRDISP(gridXY(0));
  // TRDISP(gridXY(1));


  // std::function<double(double, double)> fradius = [](double x, double y) {  return std::sqrt(x*x + y*y); };
  // auto R = fgrid(fradius, gridXY);
  // TRDISP(R);
  // auto R2 = fgrid(fradius2, gridXY);
  // TRDISP(R2);

  // auto gradXY = grad(R, x_interval, y_interval);
  // TRDISP(gradXY(0));
  // TRDISP(gradXY(1));
  // gradXY = nabla_old & std::make_tuple(R, x_interval, y_interval);
  // TRDISP(gradXY(0));
  // TRDISP(gradXY(1));


  // CR();
  // auto gridXYZ = grid(x_interval, y_interval, rz);
  // TRDISP(gridXYZ(0));
  // TRDISP(gridXYZ(1));
  // TRDISP(gridXYZ(2));
  // std::function<double(double, double, double)> fradius3d = [](double x, double y, double z) {  return std::sqrt(x*x + y*y + z*z); };
  // auto R3D = fgrid(fradius3d, gridXYZ);
  // TRDISP(R3D);
  // auto R3D_2 = fgrid(fradius3d_2, gridXYZ);
  // TRDISP(R3D_2);


  GMD_CODE_END();



  return 0;
}
