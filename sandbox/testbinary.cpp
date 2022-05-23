#include <fstream>

#define MATHQ_DEBUG 0
#include "mathq.h"


int main(int argc, char *argv[]) {

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = CREATESTYLE(BOLD);
  Style blue = CREATESTYLE(BOLD + BLUE2);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  FormatData<bool>::string_for_true = "true";
  FormatData<bool>::string_for_false = "false";


  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();


  CR();
  MOUT << StyledString::get(HORLINE);
  CR();
  //------------------------------------------------------


  MOUT << bold.apply("Addition tests") << endl;
  CR();

  {
    int s = -10;
    unsigned int u = 5;

    TLDISP(s);
    TLDISP(u);
    TLDISP(s + u);
    CR();
  }
  MOUT << blue.apply("Vector-Vector tests") << endl;
  {
    using namespace mathq::unit_imaginary;
    CR();
    Vector<short> Vshort{-11, -12, 13};
    Vector<int> Vint1{11, 12, -13};
    Vector<int> Vint2{11, 12, -100};
    Vector<long> vLong{1000, 2000, -3000};
    Vector<unsigned> Vunsigned{70, 80, 90};
    Vector<double> Vdouble1{10, 20, 30};
    Vector<double> Vdouble2{1, 2, 3};
    Vector<float> Vfloat{0.1, .2, .3};
    Vector<long double> Vextended{0.01, .02, .03};
    Vector<Imaginary<double>> vImagDouble{1 * i, 2 * i, 3 * i};
    Vector<Imaginary<long double>> vImagExtended{10 * iL, 20 * iL, 30 * iL};
    Vector<complex<double>> VcomplexDouble{complex<double>(0.1, 0.001), complex<double>(0.2, 0.002), complex<double>(0.3, 0.003)};
    Vector<complex<int>> VcomplexInt{complex<int>(1, -2), complex<int>(1, 0), complex<int>(0, 1)};
    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    TLDISP(Vshort);
    MOUT << "  ";
    TLDISP(Vint1);
    MOUT << "  ";
    TLDISP(Vint2);
    MOUT << "  ";
    TLDISP(vLong);
    MOUT << "  ";
    TLDISP(Vunsigned);
    MOUT << "  ";
    TLDISP(Vdouble1);
    MOUT << "  ";
    TLDISP(Vdouble2);
    MOUT << "  ";
    TLDISP(Vfloat);
    MOUT << "  ";
    TLDISP(Vextended);
    MOUT << "  ";
    TLDISP(vImagDouble);
    MOUT << "  ";
    TLDISP(vImagExtended);
    MOUT << "  ";
    TLDISP(VcomplexDouble);
    MOUT << "  ";
    TLDISP(VcomplexInt);
    CR();
    MOUT << blue.apply("Vector+Vector Addition:") << endl;
    MOUT << "  ";
    TLDISP(Vshort + Vshort);
    MOUT << "  ";
    TLDISP(Vint1 + Vshort);
    MOUT << "  ";
    TLDISP(Vint1 + vLong);
    MOUT << "  ";
    TLDISP(vLong + Vshort);
    MOUT << "  ";
    TLDISP(Vint1 + Vunsigned);
    MOUT << "  ";
    TLDISP(Vint2 + Vunsigned);
    MOUT << "  ";
    TLDISP(Vdouble1 + Vdouble2);
    MOUT << "  ";
    TLDISP(Vint1 + Vdouble2);
    MOUT << "  ";
    TLDISP(Vdouble1 + Vunsigned);
    MOUT << "  ";
    TLDISP(vLong + Vdouble2);
    MOUT << "  ";
    TLDISP(Vfloat + Vint1);
    MOUT << "  ";
    TLDISP(Vextended + Vfloat);
    MOUT << "  ";
    TLDISP(Vint1 + Vextended);
    MOUT << "  ";
    TLDISP(vImagDouble + vImagExtended);
    MOUT << "  ";
    TLDISP(Vint1 + vImagDouble);
    MOUT << "  ";
    TLDISP(vImagDouble + Vdouble2);
    MOUT << "  ";
    TLDISP(Vfloat + vImagDouble);
    MOUT << "  ";
    TLDISP(vLong + vImagDouble);
    MOUT << "  ";
    TLDISP(Vdouble1 + VcomplexDouble);
    MOUT << "  ";
    TLDISP(Vint1 + VcomplexInt);
    MOUT << "  ";
    TLDISP(VcomplexDouble + vImagExtended);
    MOUT << "  ";
    TLDISP(VcomplexInt + vImagDouble);

    CR();

    short sh = 2;
    int n = 10;
    long longo = 1000;
    unsigned u = 5;
    double dub = 0.5;
    float f = 0.001;
    long double e = 3.14;
    Imaginary<double> imag_d = 5 * i;
    Imaginary<long double> imag_e = 30 * iL;
    complex<double> c_dub = complex<double>(-10.1, -10.2);
    complex<int> c_int = complex<int>(1, -2);

    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    TLDISP(sh);
    MOUT << "  ";
    TLDISP(n);
    MOUT << "  ";
    TLDISP(longo);
    MOUT << "  ";
    TLDISP(u);
    MOUT << "  ";
    TLDISP(dub);
    MOUT << "  ";
    TLDISP(f);
    MOUT << "  ";
    TLDISP(e);
    MOUT << "  ";
    TLDISP(imag_d);
    MOUT << "  ";
    TLDISP(imag_e);
    MOUT << "  ";
    TLDISP(c_dub);
    MOUT << "  ";
    TLDISP(c_int);

    CR();
    MOUT << blue.apply("Vector+scalar Addition:") << endl;
    MOUT << "  ";
    TLDISP(Vshort + sh);
    MOUT << "  ";
    TLDISP(Vint1 + sh);
    MOUT << "  ";
    TLDISP(n + vLong);
    MOUT << "  ";
    TLDISP(vLong + longo);
    MOUT << "  ";
    TLDISP(Vint1 + u);
    MOUT << "  ";
    TLDISP(u + Vint2);
    MOUT << "  ";
    TLDISP(dub + Vdouble2);
    MOUT << "  ";
    TLDISP(f + Vint1);
    MOUT << "  ";
    TLDISP(e + Vdouble2);
    MOUT << "  ";
    TLDISP(Vfloat + n);
    MOUT << "  ";
    TLDISP(Vextended + f);
    MOUT << "  ";
    TLDISP(vImagDouble + imag_e);
    MOUT << "  ";
    TLDISP(Vint1 + imag_d);
    MOUT << "  ";
    TLDISP(vImagDouble + dub);
    MOUT << "  ";
    TLDISP(f + vImagDouble);
    MOUT << "  ";
    TLDISP(longo + vImagDouble);
    MOUT << "  ";
    TLDISP(VcomplexDouble + dub);
    MOUT << "  ";
    TLDISP(sh + VcomplexInt);
    MOUT << "  ";
    TLDISP(VcomplexDouble + imag_e);
    MOUT << "  ";
    TLDISP(VcomplexInt + imag_d);
    MOUT << "  ";
    TLDISP(VcomplexInt + c_int);
    MOUT << "  ";
    TLDISP(c_dub + VcomplexInt);
  }



  CR();
  CR();
  MOUT << bold.apply("Two-Level Vector tests") << endl;



  CR();
  CR();

  {
    CR();
    Matrix<Vector<double>> m1{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    Vector<double> v0{100, 200, 300};
    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    TLDISP(m1);
    MOUT << "  ";
    TLDISP(v0);
    CR();

    MOUT << "element-wise addition is chosen, since the elements are Vectors" << endl;
    MOUT << "  ";
    TLDISP(m1 + v0);
    MOUT << "  ";
    TLDISP(v0 + m1);

    CR();
    MOUT << "Element-access:" << endl;
    MOUT << "  ";
    TLDISP(m1[0]);
    MOUT << "  ";
    TLDISP((m1 + v0)[0]);
    MOUT << "  ";
    TLDISP((v0 + m1)[0]);
  }


  {
    CR();
    Vector<Matrix<double>> v1{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    Vector<double> v0{100, 200, 300};

    TRDISP(IsMathqContainer<double>::value);
    TRDISP(IsMathqContainer<Vector<double>>::value);
    TRDISP(IsMathqContainer<Vector<Matrix<double>>>::value);

    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    TLDISP(v1);
    MOUT << "  ";
    TLDISP(v0);

    CR();
    MOUT << "Top-level addition is chosen, since the top-level is a vector" << endl;
    MOUT << "  ";
    TLDISP(v1 + v0);
    MOUT << "  ";
    TLDISP(v0 + v1);

    CR();
    MOUT << "Element-access:" << endl;
    MOUT << "  ";
    TLDISP(v1[1]);
    MOUT << "  ";
    TLDISP((v1 + v0)[1]);
    MOUT << "  ";
    TLDISP((v0 + v1)[1]);
  }



  {
    CR();
    CR();

    Vector<Vector<double>> v1{{1, 2, 3}, {4, 5, 6}};
    Vector<double> v0{10, 20, 30};
    string s;
    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    TLDISP(v1);
    MOUT << "  ";
    TLDISP(v0);
    CR();
    MOUT << "By analysing the dimensions element-wise addition is chosen" << endl;
    MOUT << "  ";
    TLDISP(v1 + v0);
    MOUT << "  ";
    TLDISP(v0 + v1);

    CR();
    MOUT << "Element-access:" << endl;
    MOUT << "  ";
    TLDISP(v1[1]);
    MOUT << "  ";
    TLDISP((v1 + v0)[1]);
    MOUT << "  ";
    TLDISP((v0 + v1)[1]);

    CR();
    CR();
    Vector<double> v00{100, 200};
    MOUT << blue.apply("Given:") << endl;

    MOUT << "  ";
    TLDISP(v1);
    MOUT << "  ";
    TLDISP(v00);
    CR();
    MOUT << "By analysing the dimensions top-level addition is chosen" << endl;
    MOUT << "  ";
    TLDISP(v1 + v00);
    MOUT << "  ";
    TLDISP(v00 + v1);

    CR();
    MOUT << "Element-access:" << endl;
    MOUT << "  ";
    TLDISP(v1[1]);
    MOUT << "  ";
    TLDISP((v1 + v00)[1]);
    MOUT << "  ";
    TLDISP((v00 + v1)[1]);
  }


  CR();
  CR();
  MOUT << bold.apply("When dimensions and rank are the same, the result depends on order, ie non-commutative") << endl;
  {
    CR();
    Vector<Vector<double>> v1{{1, 2}, {4, 5}};
    MOUT << "  ";
    TLDISP(v1);
    Vector<double> v0{10, 20};
    MOUT << "  ";
    TLDISP(v0);
    CR();
    MOUT << "Adding from the right yields element-wise: each element of v1 is added with v0" << endl;
    MOUT << "  ";
    TLDISP(v1 + v0);
    CR();
    MOUT << "Adding from the left yields Top-level: add v0[0] to vector v1[0], add v0[1] to vector v1[1]" << endl;
    MOUT << "  ";
    TLDISP(v0 + v1);

    CR();
    MOUT << "Element-access:" << endl;
    MOUT << "  ";
    TLDISP(v1[1]);
    MOUT << "  ";
    TLDISP((v1 + v0)[1]);
    MOUT << "  ";
    TLDISP((v0 + v1)[1]);
    CR();
  }




  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
