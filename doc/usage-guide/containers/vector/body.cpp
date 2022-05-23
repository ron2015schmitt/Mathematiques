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


  CR();
  CR();

  using namespace mathq::unit_quaternion;
  using namespace mathq::unit_imaginary;

  using std::sqrt;

  GMD_HEADER2("Introduction");

  OUTPUT("Mathématiques vector variables have type `Vector<E>`, which is a template class that holds a number of elements of type `E`.");
  OUTPUT("The element type `E` can be either a scalar type, such as a real or complex type, or another container type.");
  OUTPUT("The most common case is where `E=double`, ie `Vector<double>`.");
  OUTPUT("Vectors can be defined as fixed-size or dynamically-sized.");
  OUTPUT("This class can be used to create linear algebra vectors, as well as physical vectors such velocity.");

  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER2("Declaring and initializing Vector Variables in Mathématiques.");

  OUTPUT("Vectors can be defined as fixed-size or dynamically-sized.");

  GMD_HEADER3("Fixed size vectors");

  OUTPUT("To declare a fixed-size vector, the size must be a complie-time constant, making it suitable for 2D, 3D, and 3+1D physical vectors, such as velocity, position, force, electric field, etc.  ");
  OUTPUT("The syntax for a fixed-size vector is `Vector<double,NE>`, where `NE` is a positive integer.");
  OUTPUT("Vectors can be declared and initialized in a variety of ways:");


  CR();
  CR();
  GMD_CODE_START("C++");
  {
    ECHO_CODE(using namespace mathq);
    CR();
    ECHO_CODE(auto velocity2D = Vector<double, 2>(0));
    ECHO_CODE(auto velocity3D = Vector<double, 3>(0));
    ECHO_CODE(auto vector = Vector<double, 11>(0));
    TRDISP(velocity2D);
    TRDISP(velocity3D);
    TRDISP(vector);
  }
  {
    CR();
    ECHO_CODE(Vector<double, 2> velocity2D(0));
    ECHO_CODE(Vector<double, 3> velocity3D(1));
    TRDISP(velocity2D);
    TRDISP(velocity3D);
  }
  {
    CR();
    ECHO_CODE(Vector<double, 2> velocity2D);
    ECHO_CODE(velocity2D = 4);
    ECHO_CODE(Vector<double, 3> velocity3D);
    ECHO_CODE(velocity3D = -0.55);
    TRDISP(velocity2D);
    TRDISP(velocity3D);
  }
  {
    CR();
    ECHO_CODE(Vector<double, 2> velocity2D({ 70.5, -30 }));
    ECHO_CODE(Vector<double, 3> velocity3D({ 10, 0, -15 }));
    TRDISP(velocity2D);
    ECHO_CODE(Vector<double> v3(3));
    TRDISP(velocity3D);
  }
  {
    CR();
    ECHO_CODE(Vector<double, 2> velocity2D = Vector<double, 2>({ 70.5, -30 }));
    ECHO_CODE(Vector<double, 3> velocity3D = Vector<double, 3>({ 70.5, -30 }));
    TRDISP(velocity2D);
    TRDISP(velocity3D);
  }
  GMD_CODE_END();


  //  * Vector<E>    -- variable size vector (valarray)
  //  *                 E  = type for elements
  //  * Vector<E,NE> -- fixed size vector (array)
  //  *                 NE = size = number of elements [OPTIONAL]


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
  Domain<double> rx(-1, 1, 3);
  Domain<double> ry(0, 3, 4);
  Domain<double> rz(10, 11, 2);
  TRDISP(rx);
  auto gridX = grid(rx);
  TRDISP(gridX);
  auto divX = grad(grid(rx),rx);
  TRDISP(divX);
  Domain<double> rx2(-10, 10, 21);
  auto gridX2 = grid(rx2);
  TRDISP(gridX2);
  auto gradX2 = grad(gridX2,rx2);
  TRDISP(gradX2);
  auto gradX2_2 = nabla_old & pair(gridX2,rx2);
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
  auto gridXY = grid(rx, ry);
  TRDISP(gridXY(0));
  TRDISP(gridXY(1));


  std::function<double(double, double)> fradius = [](double x, double y) {  return std::sqrt(x*x + y*y); };
  auto R = fgrid(fradius, gridXY);
  TRDISP(R);
  auto R2 = fgrid(fradius2, gridXY);
  TRDISP(R2);

  auto gradXY = grad(R, rx, ry);
  TRDISP(gradXY(0));
  TRDISP(gradXY(1));
  gradXY = nabla_old & std::make_tuple(R, rx, ry);
  TRDISP(gradXY(0));
  TRDISP(gradXY(1));



  CR();
  auto gridXYZ = grid(rx, ry, rz);
  TRDISP(gridXYZ(0));
  TRDISP(gridXYZ(1));
  TRDISP(gridXYZ(2));
  std::function<double(double, double, double)> fradius3d = [](double x, double y, double z) {  return std::sqrt(x*x + y*y + z*z); };
  auto R3D = fgrid(fradius3d, gridXYZ);
  TRDISP(R3D);
  auto R3D_2 = fgrid(fradius3d_2, gridXYZ);
  TRDISP(R3D_2);



  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER3("Runtime-sized and Dynamically-sized vectors");





  CR();
  CR();


  CR();
  DISP(sizeof(array<double, 2>)/sizeof(double));
  DISP(sizeof(Vector<double, 2>)/sizeof(double));

  CR();
  DISP(sizeof(array<double, 100>)/sizeof(double));
  DISP(sizeof(Vector<double, 100>)/sizeof(double));
  CR();
  DISP(sizeof(array<array<double, 2>, 100>)/sizeof(double));
  DISP(sizeof(Vector<Vector<double, 2>, 100>)/sizeof(double));

  GMD_CODE_END();


  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of Vectors");

  // OUTPUT("The size of a vector is 64bits plus the vector size times the size of the underlying arithmetic type:");

  // CR();
  // CR();
  // GMD_CODE_START("C++");
  // CR();
  // SRDISP(" bytes", sizeof(int));
  // SRDISP(" bytes", sizeof(Vector<int, 10>));
  // CR();
  // SRDISP(" bytes", sizeof(double));
  // SRDISP(" bytes", sizeof(Vector<double, 10>));
  // SRDISP(" bytes", sizeof(std::array<double, 10>));
  // CR();
  // SRDISP(" bytes", sizeof(long double));
  // SRDISP(" bytes", sizeof(Vector<long double, 10>));
  // CR();
  // GMD_CODE_END();




  OUTPUT("\n<br>\n");
  GMD_HEADER2("Arithmetic Operators");

  OUTPUT("The 4 fundamental arithmetic operators can be used with quaternions.");

  OUTPUT("Mathématiques supports the four arithmetic operators for quaternions:");
  CR();
  GMD_CODE_START("C++");
  // TRDISP(q1+q2);
  // TRDISP(q1-q2);
  // TRDISP(q1*q2);
  // TRDISP(q2/q1);
  GMD_CODE_END();


  GMD_HEADER2("Methods");

  OUTPUT("Assume `q`  is of type `Quaternion<D>` with \n");
  OUTPUT("> _q_ = _a_ + _b_ **i** + _c_ **j** + _d_ **k** \n");
  OUTPUT("The scalar+vector form of q is \n");
  OUTPUT(">  _q_ = _a_ + **v**. \n");
  OUTPUT("The polar form of q is: \n");
  OUTPUT("> _q_ = ||_q_|| ( cos _φ_ + **n\u0302** sin _φ_ ). \n");
  OUTPUT("where  \n");
  OUTPUT("> _φ_ ≐  cos<sup-1></sup>( _a_/||_q_|| ). \n");
  OUTPUT("and  \n");
  OUTPUT("> **n\u0302** ≐ **v**/||**v**||\n");
  OUTPUT("Note that for complex numbers **n\u0302** = +i or -i.  \n");


  OUTPUT("| syntax | modifies q? | description | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `Quaternion<D> invert()` | yes | q := 1/q, returns `q` | ");
  OUTPUT("| `Quaternion<D> negate()` | yes | q := -q, returns `q` | ");
  OUTPUT("| `Quaternion<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | ");
  OUTPUT("| `D real()` | no | returns the real part of `q` | ");
  OUTPUT("| `D imag()` | no | returns the i-component part of `q` | ");
  OUTPUT("| `D jmag()` | no | returns the j-component part of `q` | ");
  OUTPUT("| `D kmag()` | no | returns the k-component of `q` | ");
  OUTPUT("| `D abs()` | no | returns \\|\\|_q_\\|\\|, the magnitude of `q` | ");
  OUTPUT("| `D normsqr()` | no | returns the magnitude-squared of `q` | ");
  OUTPUT("| `D scalar()` | no | same as real() | ");
  OUTPUT("| `Quaternion<D> normalized()` | no | returns _q_/\\|\\|_q_\\|\\| | ");
  OUTPUT("| `Vector<D,3> vector()` | no | returns **v**, the vector part of `q` | ");
  OUTPUT("| `Vector<D,3> unitvector()` | no | returns **n\u0302**, the vector part of `q` normalized to 1 | ");
  OUTPUT("| `D vabs()` | no | returns, _v_=\\|\\|**v**\\|\\| the magnitude of `q.vector()` | ");
  OUTPUT("| `D vnormsqr()` | no | returns \\|\\|**v**\\|\\|<sup>2</sup> | ");
  OUTPUT("| `D angle()` | no | returns φ as defined above | ");
  OUTPUT("| `std::tuple<D, D, Vector<D, 3>> polar()` | no | returns { \\|\\|_q_\\|\\|, φ, **n\u0302** } as a tuple | ");
  OUTPUT("| `Matrix<std::complex<D>, 2, 2> matrix2by2()` | no | returns **Q**, the 2x2 matrix form<sup>1</sup> of _q_ | ");

  CR();
  OUTPUT("1. **Q** = [  _a_ + **i** _b_,  _c_ + **i** _d_; ");
  OUTPUT("             -_c_ + **i** _d_,  _a_ - **i** _b_  ]");
  CR();


  OUTPUT("A few examples are shown below.");

  CR();
  GMD_CODE_START("C++");
  // TRDISP(q1);
  // TRDISP(q1.real());
  // TRDISP(q1.imag());
  // TRDISP(q1.jmag());
  // TRDISP(q1.kmag());
  // TRDISP(q1.abs());
  // TRDISP(q1.scalar());
  // TRDISP(q1.vector());
  // TRDISP(q1.vabs());
  // TRDISP(q1.unitvector());
  // TRDISP(q1.angle());
  // TRDISP(q1.polar());
  // TRDISP(q1.matrix2by2());
  // GMD_CODE_END();

  // // MOUT << "sizeof tuple = " << display::tuple_size_v<std::tuple<double, double, Vector<double, 3>>> << endl;

  // MOUT << "typename = "  << getTypeName(q1.polar()) << endl;


  GMD_HEADER2("Functions");
  CR();
  OUTPUT("Mathématiques supports several quaternion functions.  These are listed in detail in the section on functions.");
  OUTPUT("Below are a few examples.\n");
  CR();


  CR();
  GMD_CODE_START("C++");
  // TRDISP(q);
  // TRDISP(exp(q));
  // TRDISP(log(q));
  // TRDISP(pow(q, 2));
  // TRDISP(pow(q, 0.5));
  // TRDISP(inv(q));
  // TRDISP(conj(q));
  GMD_CODE_END();


  GMD_HEADER2("Containers of Quaternions");
  CR();
  OUTPUT("Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have quaternions as their underlying type.");
  OUTPUT("Below are examples of container math with quaternions.  Mixed math is allowed.\n");
  CR();



  // FormatDataVector::string_opening = "{\n";
  // FormatDataVector::max_elements_per_line = 1;
  // FormatDataVector::string_endofline = "\n";
  // GMD_CODE_START("C++");
  // ECHO_CODE(auto v = Vector<Quaternion<double>>({ 16 + 2*i + 3*j + 13*k,
  //                                                5 + 11*i + 10*j + 8*k,
  //                                                9 + 7*i + 6*j + 12*k,
  //                                                4 + 14*i + 15*j + 1*k }));
  // GMD_CODE_END();


  GMD_CODE_START("C++");
  // TRDISP(q);
  // CR();
  // TRDISP(v);
  // CR();
  // TRDISP(v + q);
  // CR();
  // TRDISP(exp(v));
  // CR();
  // TRDISP(exp(v) + v);
  // TRDISP(exp(v) + 1);
  // TRDISP(exp(v) + 2.3);
  // TRDISP(exp(v) + complex(1,2));
  // TRDISP(exp(v) + Imaginary<double>(2));
  // TRDISP(exp(v) + Quaternion<double>(1, 2, -1, -3));
  GMD_CODE_END();

  return 0;
}
