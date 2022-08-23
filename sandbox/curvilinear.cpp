#include "mathq.h"


namespace mathq {


};


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;


  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;



  Domain<double> dom1 = Domain<double>::interval(0, 10, 11);
  TRDISP(dom1);
  TRDISP(dom1.coord());

  CurvilinearCoords<double, 2, NullType> tcoords;
  TRDISP(tcoords[0]);
  TRDISP(tcoords[1]);

  CartesianCoords<double, 2> cart_coords2a;
  TRDISP(cart_coords2a);

  CartesianCoords<double, 2> cart_coords2b({
      Domain<double>::interval(-1,1,5),
      Domain<double>::interval(2,3,3),
    });
  TRDISP(cart_coords2b);
  TRDISP(cart_coords2b.grid_dims());
  TRDISP(cart_coords2b[0]);
  TRDISP(cart_coords2b[1]);

  ECHO_CODE(CartesianCoords<double, 2> cart_coords2c(cart_coords2b));
  TRDISP(cart_coords2c);

  TRDISP(cart_coords2c[0]);
  TRDISP(cart_coords2c[1]);
  TRDISP(cart_coords2c.J());
  TRDISP(cart_coords2c.g());
  TRDISP(cart_coords2c.basis_vec(0));
  TRDISP(cart_coords2c.basis_vec(1));
  TRDISP(cart_coords2c.basis());
  TRDISP(cart_coords2c.at(0, 0));
  TRDISP(cart_coords2c.at(3, 2));
  TRDISP(cart_coords2c.at(0, 0)+cart_coords2c.at(3, 2));
  TRDISP(cart_coords2c.x());
  TRDISP(cart_coords2c.y());

  TRDISP(curvilinear_coords_test(cart_coords2c));
  CurvilinearField<double, 0, CartesianCoords<double, 2>> field0(cart_coords2c);
  // CurvilinearField<double, 0> field0(cart_coords2c);
  auto& x = cart_coords2c.x();
  auto& y = cart_coords2c.y();
  field0() = sqrt(x*x+y*y);
  // field0 = { abs(x) };
  TRDISP(field0);
  TRDISP(field0());

  TRDISP(x);
  TRDISP(y);
  TRDISP(cart_coords2c.grad(x));
  TRDISP(cart_coords2c.grad(y));
  TRDISP(cart_coords2c.grad(field0()));

  TRDISP(typename std::remove_cvref<decltype(field0())>::type::ElementType());

  TRDISP(typename std::remove_cvref<decltype(field0)>::type::NumberType());
  TRDISP(std::is_convertible_v<decltype(field0)::NumberType, std::complex<double>>);

  // TRDISP(2*field0 + 3);

  TRDISP(grad(field0));

  Nabla<> nabla;
  TRDISP(nabla & field0);

  TRDISP(pd(field0, 0));
  TRDISP(pd(field0, 1));

  // div
  ECHO_CODE(auto A = grad(field0));
  TRDISP(A);
  TRDISP(cart_coords2c.div(A));
  TRDISP(div(A));
  TRDISP(nabla | A);
  ECHO_CODE(Vector<double, 3> b{ 1,1,0 });
  ECHO_CODE(Vector<double, 3> c{ 0,0,1 });

  TRDISP(c);
  {
    using namespace cross_product;
    TRDISP(b^c);
  }
  TRDISP(cross(c, b));
  TRDISP(tensor_product(c, b));

  ECHO_CODE(Dimensions dims1{ 4,3,2 });
  TRDISP(dims1);
  ECHO_CODE(Dimensions dims2{ 7,5,6 });
  TRDISP(dims2);
  ECHO_CODE(Dimensions dims3);
  TRDISP(dims3);
  dims3 = Dimensions::concat(dims1, dims2);
  TRDISP(dims3);

  {
    using namespace cross_product;

    CartesianCoords<double, 3> cart_coords3({
        Domain<double>::interval(-1,1,5),
        Domain<double>::interval(-1,1,5),
        Domain<double>::interval(-1,1,5),
      });
    TRDISP(cart_coords3);

    TRDISP(cart_coords3.z());
    Vector<MultiArray<double, 3>, 3> A;
    RecursiveDimensions rdims = RecursiveDimensions{ Dimensions{3}, Dimensions{5,5,5} };
    TRDISP(A.recursive_dims());
    A.resize(rdims);
    TRDISP(A.recursive_dims());
    A = 0;
    A[0] = cart_coords3.z();
    TRDISP(roundzero(cart_coords3.curl(A), 1e-14));
  }

  {
    using namespace cross_product;
    CartesianCoords<double, 3> cart_coords3({
        Domain<double>::interval(-1,1,5),
        Domain<double>::interval(-1,1,5),
        Domain<double>::interval(-1,1,5),
      });
    TRDISP(cart_coords3);
    ECHO_CODE(CurvilinearField<double, 1, CartesianCoords<double, 3>> A(cart_coords3));
    A = 0.;
    ECHO_CODE(A[0] = cart_coords3.z());
    ECHO_CODE(auto B = curl(A));
    TRDISP(B);
    OUTPUT("=========================");
    ECHO_CODE(B = nabla ^ A);
    OUTPUT("=========================");
  }


  {
    using namespace cross_product;
    using mathq::unit_imaginary::i;
    CartesianCoords<double, 3> cart_coords3({
        Domain<double>::interval(-1,1,5),
        Domain<double>::interval(-1,1,5),
        Domain<double>::interval(-1,1,5),
      });
    TRDISP(cart_coords3);
    CurvilinearField<std::complex<double>, 1, CartesianCoords<double, 3>> A(cart_coords3);
    ECHO_CODE(auto& z = cart_coords3.z());
    ECHO_CODE(A = 0);
    ECHO_CODE(A = { exp(i*2*z),  0*exp(i*2*z) ,  0*exp(i*2*z) });
    TRDISP(A);
    auto B = curl(A);
    // TRDISP(B);
    // B = nabla ^ A;
  }


  return 0;
}
