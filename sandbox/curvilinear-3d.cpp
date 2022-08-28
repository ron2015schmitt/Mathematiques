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
