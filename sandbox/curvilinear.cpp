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

  Style mystyle1 = CREATESTYLE(BOLD + BLUE);

  {
    title("Intervals");
    ECHO_CODE(Interval<double> dom1 = Interval<double>::interval(0, 10, 11));
    TRDISP(dom1);
    TRDISP(dom1.grid());
    ECHO_CODE(Domain<double>&dom2 = dom1);
    TRDISP(dom2.grid());
  }

  {
    title("Coords - NullType");
    ECHO_CODE(CurvilinearCoords<double, 2, false, NullType> coords);
    TRDISP(coords[0]);
    TRDISP(coords[1]);
  }

  {
    title("CartesianCoords - default constructor");
    ECHO_CODE(CartesianCoords<double, 2, false> coords);
    TRDISP(coords);
    TRDISP(HasTimeCoord<decltype(coords)>);
    TRDISP(HasNotTimeCoord<decltype(coords)>);
  }

  {
    title("2D CartesianCoords & CurvilinearField");
    subtitle("2D CartesianCoords from Intervals");
    ECHO_CODE(CartesianCoords<double, 2, false> coords1({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(2,3,3),
      }));
    // TRDISP(coords1);
    // TRDISP(coords1.grid_dims());
    // TRDISP(coords1[0]);
    // TRDISP(coords1[1]);

    subtitle("2D CartesianCoords copy constructor");
    ECHO_CODE(CartesianCoords<double, 2, false> coords(coords1));
    TRDISP(coords);
    TRDISP(HasTimeCoord<decltype(coords)>);
    TRDISP(HasNotTimeCoord<decltype(coords)>);

    // TRDISP(coords[0]);
    // TRDISP(coords[1]);
    // TRDISP(coords.J());
    // TRDISP(coords.g());
    // TRDISP(coords.basis_vec(0));
    // TRDISP(coords.basis_vec(1));
    // TRDISP(coords.basis());
    // TRDISP(coords.at(0, 0));
    // TRDISP(coords.at(3, 2));
    // TRDISP(coords.at(0, 0)+coords.at(3, 2));
    // TRDISP(coords.x());
    // TRDISP(coords.y());

    // TRDISP(curvilinear_coords_test(coords));

    subtitle("CurvilinearField - Scalar 2D");
    ECHO_CODE(CurvilinearField<double, 0, decltype(coords)> field0(coords));
    ECHO_CODE(auto& x = coords.x());
    ECHO_CODE(auto& y = coords.y());
    ECHO_CODE(field0() = -3*x + 2*y);
    TRDISP(field0);

    TRDISP(x);
    TRDISP(y);

    TRDISP(IsGridlike<decltype(x)>);
    TRDISP(IsMultiArray<decltype(x)>);
    TRDISP(IsWritableExpressionOrArray<decltype(x)>);
    TRDISP(x.isNotExpression);


    subtitle("partials of a 2D grid");
    TRDISP(coords.pd(x, 0));
    TRDISP(coords.pd(x, 1));

    subtitle("partials of a 2D Scalar CurvilinearField");
    TRDISP(pd(field0, 0));
    TRDISP(pd(field0, 1));


    subtitle("Gradient of a 2D grid");
    TRDISP(coords.grad(x));
    TRDISP(coords.grad(y));

    subtitle("Gradient of a 2D CurvilinearField");
    TRDISP(grad(field0));
    Nabla<> nabla;
    // TRDISP(nabla & field0);



    subtitle("Divergence of a 2D CurvilinearField - ex 1");
    // div
    ECHO_CODE(auto A = grad(field0));
    TRDISP(A);
    // TRDISP(coords.div(A));
    TRDISP(div(A));
    // TRDISP(nabla | A);


    subtitle("Divergence of a 2D CurvilinearField - ex 2");
    ECHO_CODE(field0() = sqrt(x*x+y*y));
    TRDISP(grad(field0));
    TRDISP(div(grad(field0)));

  }

  {
    title("2+1D CartesianCoords & CurvilinearField");

    subtitle("2+1D CartesianCoords Properties");

    ECHO_CODE(CartesianCoords<double, 2, true> coords({
        Interval<double>::interval(-1,1,3),
        Interval<double>::interval(-1,1,3),
        Interval<double>::interval(0,2,3),
      }));
    TRDISP(coords);
    TRDISP(HasTimeCoord<decltype(coords)>);
    TRDISP(HasNotTimeCoord<decltype(coords)>);

    TRDISP(coords[0]);
    TRDISP(coords.x());
    TRDISP(coords[1]);
    TRDISP(coords.y());
    TRDISP(coords[2]);
    TRDISP(coords.t());

    TRDISP(coords.J());
    TRDISP(coords.g());
    TRDISP(coords.basis_vec(0));
    TRDISP(coords.basis_vec(1));
    TRDISP(coords.basis());
    TRDISP(coords.at(0, 0, 0));
    TRDISP(coords.at(1, 2, 2));
    TRDISP(coords.at(0, 0, 0)+coords.at(1, 2, 2));


    subtitle("2+1D Scalar CurvilinearField");
    ECHO_CODE(CurvilinearField<double, 0, decltype(coords)> field(coords));

    ECHO_CODE(auto& x = coords.x());
    ECHO_CODE(auto& y = coords.y());
    ECHO_CODE(field() = -4*x + 5*y);
    TRDISP(field);


    subtitle("2+1D Partials of Scalar CurvilinearField");
    TRDISP(pd(field, 0));
    TRDISP(pd(field, 1));
    TRDISP(pd(field, 2));

    subtitle("2+1D Gradient of Scalar CurvilinearField");
    TRDISP(grad(field));

    subtitle("Divergence of a 2D+1 CurvilinearField - ex 1");
    // div
    ECHO_CODE(auto A = grad(field));
    TRDISP(A);
    // TRDISP(coords.div(A));
    TRDISP(div(A));
    // TRDISP(nabla | A);


    subtitle("Divergence of a 2D+1 CurvilinearField - ex 2");
    ECHO_CODE(field() = sqrt(x*x+y*y));
    TRDISP(grad(field));
    TRDISP(div(grad(field)));

  }


  {
    title("3D cross product of simple 3D vectors (not fields)");

    // cross product
    ECHO_CODE(Vector<double, 3> b{ 1,1,0 });
    ECHO_CODE(Vector<double, 3> c{ 0,0,1 });

    TRDISP(c);
    {
      using namespace cross_product;
      TRDISP(b^c);
    }
    TRDISP(cross(c, b));

  }

  {
    title("3D outer product of simple (non-field) 3D vectors");

    subtitle("concat of dimensions - needed for outer product");

    ECHO_CODE(Dimensions dims1{ 4,3,2 });
    TRDISP(dims1);
    ECHO_CODE(Dimensions dims2{ 7,5,6 });
    TRDISP(dims2);
    ECHO_CODE(Dimensions dims3);
    TRDISP(dims3);
    TRDISP(dims3 = Dimensions::concat(dims1, dims2));

    subtitle("outer product");
    ECHO_CODE(Vector<double, 3> b{ 1,1,0 });
    ECHO_CODE(Vector<double, 3> c{ 0,0,1 });
    TRDISP(tensor_product(c, b));


  }

  {
    title("Contraction of of simple (non-field) 3D vectors");

    using namespace mathq::TensorIndex;
    Vector<double, 3>::Tensor<COVARIANT> covec;
    covec = { 1,2,3 };
    // covec = 5.;
    TRDISP(covec);

    Vector<double, 3>::Tensor<CONTRAVARIANT> vec;
    vec = { 3,2,1 };
    TRDISP(vec);

    TRDISP(covec(vec));
    TRDISP(vec(covec));
    // TRDISP(vec(vec)); // should cause compile-time error
  }


  {
    title("3D curl of a MutliArray - output is curlA = {0,1,0}");

    using namespace cross_product;

    ECHO_CODE(CartesianCoords<double, 3, false> coords({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
      }));
    TRDISP(coords);

    TRDISP(coords.z());
    ECHO_CODE(Vector<MultiArray<double, 3>, 3> A);
    ECHO_CODE(RecursiveDimensions rdims = RecursiveDimensions{ Dimensions{3}, Dimensions{5,5,5} });
    TRDISP(A.recursive_dims());
    A.resize(rdims);
    TRDISP(A.recursive_dims());
    A = 0;
    A[0] = coords.z();
    TRDISP(roundzero(coords.curl(A), 1e-14));
  }

  {
    title("3D curl of a CurvilinearField - ex1: output is curlA = {0,1,0}");

    using namespace cross_product;
    CartesianCoords<double, 3, false> coords({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
      });
    TRDISP(coords);
    ECHO_CODE(CurvilinearField<double, 1, CartesianCoords<double, 3, false>> A(coords));
    A = 0.;
    ECHO_CODE(A[0] = coords.z());
    ECHO_CODE(auto B = curl(A));
    TRDISP(B);
    // OUTPUT("=========================");
    // Nabla<> nabla;
    // ECHO_CODE(B = nabla ^ A);
    // OUTPUT("=========================");
  }


  {
    title("3D curl of a complex-valued CurvilinearField - ex1: output is curlA = {0,2exp(i*2*z),0}");
    using namespace cross_product;
    using mathq::unit_imaginary::i;
    CartesianCoords<double, 3, false> coords({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
      });
    TRDISP(coords);
    CurvilinearField<std::complex<double>, 1, CartesianCoords<double, 3, false>> A(coords);
    ECHO_CODE(auto& z = coords.z());
    ECHO_CODE(A = 0);
    ECHO_CODE(A = { exp(i*2*z),  0*exp(i*2*z) ,  0*exp(i*2*z) });
    TRDISP(A);
    TRDISP(curl(A));
    TRDISP(roundzero(coords.curl(A), 1e-14));
    // B = nabla ^ A;
  }


  {
    title("3+1D curl of a complex-valued CurvilinearField - ex1");
    using namespace cross_product;
    using mathq::unit_imaginary::i;
    CartesianCoords<double, 3, true> coords({
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(-1,1,5),
        Interval<double>::interval(0,1,2),
      });
    TRDISP(coords);
    CurvilinearField<std::complex<double>, 1, CartesianCoords<double, 3, true>> A(coords);
    ECHO_CODE(auto& z = coords.z());
    ECHO_CODE(A = 0);
    ECHO_CODE(A = { exp(i*2*z),  0*exp(i*2*z) ,  0*exp(i*2*z) });
    TRDISP(A);
    TRDISP(curl(A));
    TRDISP(roundzero(coords.curl(A), 1e-14));
    // B = nabla ^ A;
    TRDISP(A.recursive_dims());
  }


  return 0;
}
