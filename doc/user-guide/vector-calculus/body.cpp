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



const double pi = 3.141592653589793238462643383;






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
  ECHO_CODE(Domain<double>  rs(-2, +2, 5));
  TRDISP(rs);
  TRDISP(rs.coord());

  CR();
  ECHO_CODE(Domain<double>  rs1(-2, +3, 5, GridScale::LINEAR, true, false));
  TRDISP(rs1);
  TRDISP(rs1.coord());


  CR();
  ECHO_CODE(Domain<double>  rs2 = Domain<double>::realLine());
  TRDISP(rs2);

  CR();
  ECHO_CODE(Domain<double>  rs3(10, 1e5, 10, GridScale::LOG));
  TRDISP(rs3);
  TRDISP(rs3.coord());
  TRDISP(mathq::log10(rs3.coord()));


  CR();
  ECHO_CODE(auto rs4 = Domain<double>::point(2.5));
  TRDISP(rs4);
  TRDISP(rs4.coord());


  CR();
  ECHO_CODE(Domain<double> rx(-10, +10, 3));
  TRDISP(rx);
  TRDISP(rx.coord());

  CR();
  ECHO_CODE(Domain<double> ry(-20, 20, 5, GridScale::LINEAR));
  TRDISP(ry);
  TRDISP(ry.coord());

  ECHO_CODE(Domain<double> rz(30, 33, 4, GridScale::LINEAR));
  TRDISP(rz);
  TRDISP(rz.coord());

  // CR();
  // auto setXY = std::make_tuple(rx, ry);
  // TRDISP(std::get<0>(setXY));
  // TRDISP(std::get<1>(setXY));

  // CR();
  // ECHO_CODE(RealMultiSet<double, 2> setXY({ rx, ry }));
  // TRDISP(setXY);
  // TRDISP(setXY.coord()[0]);
  // TRDISP(setXY.coord()[1]);
  // // TRDISP(insideout(setXY.coord()));

  // CR();
  // ECHO_CODE(RealMultiSet<double, 3> setXYZ({ rx, ry, rz }));
  // TRDISP(setXYZ);
  // auto XYZ = setXYZ.coord();
  // // TRDISP(setXYZ);
  // auto X = XYZ[0];
  // TRDISP(X);
  // auto Y = XYZ[1];
  // TRDISP(Y);
  // auto Z = XYZ[2];
  // TRDISP(Z);



  // PolarCoordSystem<double>::Coords v1(10, pi/3);
  // TRDISP(v1);
  // PolarCoordSystem<double>::Coords v2(2, pi/4);
  // TRDISP(v2);

  // TRDISP(dot(v1, v2));

  // TRDISP(v1.basis_vec(0));


  // PolarCoords<double> u1(10, pi/3);
  // TRDISP(u1);
  // PolarCoords<double> u2(2, pi/4);
  // TRDISP(u2);
  // TRDISP(dot(u1, u2));

  // TRDISP(u1.pos());
  // TRDISP(u2.pos());
  // TRDISP(u1.pos()|u2.pos());


  // TRDISP(u1.J());
  // TRDISP(u1.g());

  // ECHO_CODE(PolarCoords<double> w = PolarCoords<double>::fromCartesian(sqrt(2), sqrt(2)));
  // TRDISP(w);


  // ECHO_CODE(CartCoords<double, 3> p1({ 1,2,3 }));
  // TRDISP(p1);
  // TRDISP(p1.basis_vec(0));
  // TRDISP(p1.basis_vec(1));
  // TRDISP(p1.basis_vec(2));
  // TRDISP(p1.g());

  // TRDISP(p1.ron());
  // TRDISP(decltype(p1)::ron());
  // TRDISP(CartCoords<double, 2>::ron());

  // TRDISP(zeros<Vector<double, 2>>());
  // TRDISP(ones<Vector<double, 2>>());
  // DISP(sizeof(PolarCoords<double>)/sizeof(double));

  // MultiArrayOfGrids<double, 2> vgA;
  // GridOfMultiArrays<double, 2> vgB;
  // TRDISP(vgA);
  // TRDISP(vgB);
  // CG<double,2,false>::Type cgA;
  // CG<double,2,true>::Type cgB;
  // TRDISP(cgA);
  // TRDISP(cgB);

  // CG0<double,2,false> cgA2;
  // TRDISP(cgA2);

  // CR();
  // PolarCoordSystem<double> polar;

  // TRDISP(polar);
  // // double phi = std::acos(0.5);
  // double phi = pi/3;
  // TRDISP(phi/pi);
  // TRDISP(polar.x(10, phi));
  // TRDISP(polar.y(10, phi));
  // TRDISP(polar.J(10, phi));
  // TRDISP(polar.g(10, phi));



  // TRDISP(polar.r(5, 8.66025));
  // TRDISP(polar.phi(5, 8.66025)/pi);
  // TRDISP(polar.r_vec_cart(1,0)); 
  // TRDISP(polar.r_vec_cart(1,1)); 
  // TRDISP(polar.r_vec_cart(0,1)); 
  // TRDISP(polar.r_vec_cart(-1,0)); 



   // TRDISP(polar.xOfq[0](1.5, 0.5));
  // TRDISP(polar.funcs_uvecsOfq[0](0.5, 0.5));



  // TRDISP(insideout(setXYZ.coord()));

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


  // ECHO_CODE(auto gridX0 = x_interval.coord());
  // TRDISP(x_interval);
  // TRDISP(gridX0);

  // Vector<double, 5> g;
  // for (size_t i = 0; i<5; i++) {
  //   g(i) = x_interval.get(i);
  // }
  // TRDISP(g);

  // auto gridX = coord(x_interval);
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


  // auto divX = grad(coord(x_interval), x_interval);
  // TRDISP(divX);
  // Interval<double> rx2(-10, 10, 21);
  // auto gridX2 = coord(rx2);
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
  // TRDISP(coord(y_interval));
  // TRDISP(rz);
  // TRDISP(coord(rz));
  // auto gridXY = coord(x_interval, y_interval);
  // TRDISP(gridXY(0));
  // TRDISP(gridXY(1));


  // std::function<double(double, double)> fradius = [](double x, double y) {  return std::sqrt(x*x + y*y); };
  // auto rank = fgrid(fradius, gridXY);
  // TRDISP(rank);
  // auto R2 = fgrid(fradius2, gridXY);
  // TRDISP(R2);

  // auto gradXY = grad(rank, x_interval, y_interval);
  // TRDISP(gradXY(0));
  // TRDISP(gradXY(1));
  // gradXY = nabla_old & std::make_tuple(rank, x_interval, y_interval);
  // TRDISP(gradXY(0));
  // TRDISP(gradXY(1));


  // CR();
  // auto gridXYZ = coord(x_interval, y_interval, rz);
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
