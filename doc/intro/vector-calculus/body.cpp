#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();

  OUTPUT("Mathématiques provides classes and extensive functionality for curvilinear coordinate systems as well as scalar, vector, and rank >=2 functions using these coordinates.");


  GMD_VSPACE();
  GMD_HEADER2("Curvilinear Coordinates");

  CR();
  GMD_HEADER3("Cartesian Coordinates");
  {
    GMD_CODE_START("C++");
    ECHO(CartesianCoords<double, 2> coords({
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(2,3,3),
      }));
    ECHO(CurvilinearField<double, 0, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(field0 = -3*x + 2*y);
    ETV(field0);
    GMD_CODE_END();
  }
  CR();

  CR();
  GMD_HEADER3("Polar Coordinates");
  {
    GMD_CODE_START("C++");
    ECHO(PolarCoords<double> coords({
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(2,3,3),
      }));
    GMD_CODE_END();
  }
  CR();

  CR();
  GMD_HEADER3("Polar Coordinates");
  {
    GMD_CODE_START("C++");
    ECHO(PolarCoords<double, true> coords({
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(2,3,3),
    Interval<double>::interval(0,1,3),
      }));
    GMD_CODE_END();
  }
  CR();


  GMD_VSPACE();
  GMD_HEADER2("Vector fields");

  CR();
  GMD_HEADER3("TEST");
  {
    GMD_CODE_START("C++");
    ECHO(CartesianCoords<double, 2, false> coords({
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(2,3,3),
      }));
    ECHO(CurvilinearField<double, 0, decltype(coords)> v(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(v = -3*x + 2*y);
    ETV(v);
    GMD_CODE_END();
  }
  CR();


  GMD_VSPACE();
  GMD_HEADER2("Fields of any rank");

  CR();
  GMD_HEADER3("TEST");
  {
    GMD_CODE_START("C++");
    ECHO(CartesianCoords<double, 2, false> coords({
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(2,3,3),
      }));
    ECHO(CurvilinearField<double, 0, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(field0 = -3*x + 2*y);
    ETV(field0);
    GMD_CODE_END();
  }
  CR();


  GMD_VSPACE();
  GMD_HEADER2("Maxwell's Equations");

  CR();
  GMD_HEADER3("TEST");
  {
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    ECHO(CartesianCoords<double, 3, true> coords({
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(-1,1,5),
    Interval<double>::interval(0,1,5),
      }));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(auto& z = coords.z());
    ECHO(auto& t = coords.t());
    ECHO(CurvilinearField<double, 0, decltype(coords)> Phi(coords));
    ECHO(Phi = -3*x + 2*y);
    ECHO(CurvilinearField<double, 0, decltype(coords)> Phi2(coords));
    ECHO(Phi2 = -3*x + 2*y);
    ETV(alltrue(approx(Phi(), Phi2())));
    GMD_CODE_END();
  }
  CR();


  // template <typename GridElement, size_t Ndims, bool TimeCoord, typename TargetElement = GridElement>
  // using NumericalFunction = CurvilinearField<TargetElement, 0, CartesianCoords<GridElement, Ndims, TimeCoord>>;  {
  GMD_VSPACE();
  GMD_HEADER2("Raw code");


  {
    OUTPUT("CartesianCoords - default constructor");
    ECHO(CartesianCoords<double, 2, false> coords);
    // ETV(coords);
    ETV(HasTimeCoord<decltype(coords)>);
    ETV(HasNotTimeCoord<decltype(coords)>);
  }

  {
    OUTPUT("2D CartesianCoords & CurvilinearField");
    OUTPUT("2D CartesianCoords from Intervals");
    ECHO(CartesianCoords<double, 2, false> coords1({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(2,3,3),
      }));
    // ETV(coords1);
    // ETV(coords1.grid_dims());
    // ETV(coords1[0]);
    // ETV(coords1[1]);

    OUTPUT("2D CartesianCoords copy constructor");
    ECHO(CartesianCoords<double, 2, false> coords(coords1));
    ETV(coords);
    ETV(HasTimeCoord<decltype(coords)>);
    ETV(HasNotTimeCoord<decltype(coords)>);

    // ETV(coords[0]);
    // ETV(coords[1]);
    // ETV(coords.J());
    // ETV(coords.g());
    // ETV(coords.basis_vec(0));
    // ETV(coords.basis_vec(1));
    // ETV(coords.basis());
    // ETV(coords.at(0, 0));
    // ETV(coords.at(3, 2));
    // ETV(coords.at(0, 0)+coords.at(3, 2));
    // ETV(coords.x());
    // ETV(coords.y());

    // ETV(curvilinear_coords_test(coords));

    OUTPUT("CurvilinearField - Scalar 2D");
    ECHO(CurvilinearField<double, 0, decltype(coords)> field0(coords));
    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(field0 = -3*x + 2*y);
    ETV(field0);

    ETV(x);
    ETV(y);

    ETV(IsGridlike<decltype(x)>);
    ETV(IsMultiArray<decltype(x)>);
    ETV(IsWritableExpressionOrArray<decltype(x)>);
    ETV(x.isNotExpression);


    OUTPUT("partials of a 2D grid");
    ETV(coords.pd(x, 0));
    ETV(coords.pd(x, 1));

    OUTPUT("partials of a 2D Scalar CurvilinearField");
    ETV(pd(field0, 0));
    ETV(pd(field0, 1));


    OUTPUT("Gradient of a 2D grid");
    ETV(coords.grad(x));
    ETV(coords.grad(y));

    OUTPUT("Gradient of a 2D CurvilinearField");
    ETV(grad(field0));
    Nabla<> nabla;
    // ETV(nabla & field0);



    OUTPUT("Divergence of a 2D CurvilinearField - ex 1");
    // div
    ECHO(auto A = grad(field0));
    ETV(A);
    // ETV(coords.div(A));
    ETV(div(A));
    // ETV(nabla | A);


    OUTPUT("Divergence of a 2D CurvilinearField - ex 2");
    ECHO(field0 = sqrt(x*x+y*y));
    ETV(grad(field0));
    ETV(div(grad(field0)));

  }

  {
    OUTPUT("2+1D CartesianCoords & CurvilinearField");

    OUTPUT("2+1D CartesianCoords Properties");

    ECHO(CartesianCoords<double, 2, true> coords({
        Interval<double>::interval(-1,1,3),
        Interval<double>::interval(-1,1,3),
        Interval<double>::interval(0,2,3),
      }));
    ETV(coords);
    ETV(HasTimeCoord<decltype(coords)>);
    ETV(HasNotTimeCoord<decltype(coords)>);

    ETV(coords[0]);
    ETV(coords.x());
    ETV(coords[1]);
    ETV(coords.y());
    ETV(coords[2]);
    ETV(coords.t());

    ETV(coords.J());
    ETV(coords.g());
    ETV(coords.basis_vec(0));
    ETV(coords.basis_vec(1));
    ETV(coords.basis());
    ETV(coords.at(0, 0, 0));
    ETV(coords.at(1, 2, 2));
    ETV(coords.at(0, 0, 0)+coords.at(1, 2, 2));


    OUTPUT("2+1D Scalar CurvilinearField");
    ECHO(CurvilinearField<double, 0, decltype(coords)> field(coords));

    ECHO(auto& x = coords.x());
    ECHO(auto& y = coords.y());
    ECHO(field = -4*x + 5*y);
    ETV(field);


    OUTPUT("2+1D Partials of Scalar CurvilinearField");
    ETV(pd(field, 0));
    ETV(pd(field, 1));
    ETV(pd(field, 2));

    OUTPUT("2+1D Gradient of Scalar CurvilinearField");
    ETV(grad(field));

    OUTPUT("Divergence of a 2D+1 CurvilinearField - ex 1");
    // div
    ECHO(auto A = grad(field));
    ETV(A);
    // ETV(coords.div(A));
    ETV(div(A));
    // ETV(nabla | A);


    OUTPUT("Divergence of a 2D+1 CurvilinearField - ex 2");
    ECHO(field = sqrt(x*x+y*y));
    ETV(grad(field));
    ETV(div(grad(field)));


  }


  {
    OUTPUT("2D PolarCoords & CurvilinearField");

    OUTPUT("2D PolarCoords Properties");

    ECHO(PolarCoords<double, false> coords({
        Interval<double>::o_interval_c(0,1,3),
        Interval<double>::c_interval_o(0,2*3.14159265,5),
      }));
    ETV(coords);
    ETV(HasTimeCoord<decltype(coords)>);
    ETV(HasNotTimeCoord<decltype(coords)>);

    ETV(coords.r());
    ETV(coords.phi());
    ETV(coords.dims());

    ETV(coords.J());
    ETV(coords.g());
    ETV(coords.basis_vec(0));
    ETV(coords.basis_vec(1));
    ETV(coords.basis());
    ETV(coords.at(0, 0));
    ETV(coords.at(1, 2));
    ETV(coords.at(0, 0)+coords.at(1, 2));


    OUTPUT("2D PolarCoords Scalar CurvilinearField");
    ECHO(CurvilinearField<double, 0, decltype(coords)> field(coords));

    ECHO(auto& r = coords.r());
    ECHO(auto& phi = coords.phi());
    ECHO(field = -4*r + 5*phi);
    ETV(field);


    OUTPUT("2D  PolarCoords Partials of Scalar CurvilinearField");
    ETV(pd(field, 0));
    ETV(pd(field, 1));
    ETV(pd(field, 1)()/r);

    OUTPUT("2D PolarCoords Gradient of Scalar CurvilinearField");
    ETV(grad(field));

    OUTPUT("Divergence of a 2D PolarCoords CurvilinearField - ex 1");
    // div
    ECHO(auto A = grad(field));
    ETV(A);
    // ETV(coords.div(A));
    ETV(div(A));
    // ETV(nabla | A);


    OUTPUT("Divergence of a 2D+1 CurvilinearField - ex 2");
    ECHO(field = r*r);
    ETV(grad(field));
    ETV(div(grad(field)));
  }
  {
    OUTPUT("3D curl of a CurvilinearField - ex1: output is curlA = {0,1,0}");

    using namespace cross_product;
    CartesianCoords<double, 3, false> coords({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
      });
    ETV(coords);
    ECHO(CurvilinearField<double, 1, CartesianCoords<double, 3, false>> A(coords));
    A = 0.;
    ECHO(A[0] = coords.z());
    ECHO(auto B = curl(A));
    ETV(B);
    // OUTPUT("=========================");
    // Nabla<> nabla;
    // ECHO(B = nabla ^ A);
    // OUTPUT("=========================");
  }

  GMD_VSPACE();
  return 0;
}
