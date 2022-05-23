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

  CR();
  CR();
  MOUT << bold.apply("Scalar") << endl;
  {
    CR();
    Scalar<double> s = 1.1;
    TLDISP(s);
    TLDISP((-s)[0]);
  }


  CR();
  CR();
  MOUT << bold.apply("Vector") << endl;
  {
    CR();
    Vector<double> v{1.1, 2.2};
    TLDISP(v);
    TLDISP((-v)[1]);
  }

  CR();
  CR();
  MOUT << bold.apply("Matrix") << endl;
  {
    Matrix<double> m{{1, 2}, {3, 4}};
    TLDISP(m);
    TLDISP((-m)[2]);
  }



  CR();
  CR();
  MOUT << bold.apply("Tensor") << endl;
  {
    CR();
    Tensor<double, 3> t{
        {{0, 1, 2, 3, 4}, {10, 11, 12, 13, 14}},
        {{100, 101, 102, 103, 104}, {110, 111, 112, 113, 114}},
        {{200, 201, 202, 203, 204}, {210, 211, 212, 213, 214}}};

    TLDISP(t);
    TLDISP((-t)[5]);
  }



  CR();
  CR();
  CR();
  CR();


  MOUT << blue.apply("Two-level tests") << endl;


  // -------------------------------------------------
  // two level tests
  // -------------------------------------------------

  CR();
  CR();
  MOUT << bold.apply("Two-Level Scalar tests") << endl;

  {
    CR();
    Scalar<Scalar<double>> s{{1.1}};
    TLDISP(s);
    TLDISP((-s)[0]);
  }
  {
    CR();
    Scalar<Vector<double>> s{{1., 2., 3.}};
    TLDISP(s);
    TLDISP((-s)[0]);
  }
  {
    CR();
    Scalar<Matrix<double>> s{{{1, 2}, {3, 4}}};
    TLDISP(s);
    TLDISP((-s)[0]);
  }

  {
    CR();
    Scalar<Tensor<double, 2>> s{{{1, 2}, {3, 4}}};
    TLDISP(s);
    TLDISP((-s)[0]);
  }

  CR();
  CR();
  MOUT << bold.apply("Two-Level Vector tests") << endl;
  {
    CR();
    Vector<Scalar<double>> v{{1.}, {2.}};
    TLDISP(v);
    TLDISP((-v)[1]);
  }

  {
    CR();
    Vector<Vector<double>> v{{1., 2., 3.}, {4., 5., 6.}};
    TLDISP(v);
    TLDISP((-v)[1]);
  }
  {
    CR();
    Vector<Matrix<double>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    TLDISP(v);
    TLDISP((-v)[1]);
  }
  {
    CR();
    Vector<Tensor<double, 2>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    TLDISP(v);
    TLDISP((-v)[1]);
  }


  CR();
  CR();
  MOUT << bold.apply("Two-Level Matrix tests") << endl;
  {
    CR();
    Matrix<Scalar<double>> m{{{1}, {2}}, {{3}, {4}}};
    ;
    TLDISP(m);
    TLDISP((-m)[2]);
  }

  {
    CR();
    Matrix<Vector<double>> m{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    TLDISP(m);
    TLDISP((-m)[2]);
  }

  {
    CR();
    Matrix<Matrix<double>> m{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    TLDISP(m);
    TLDISP((-m)[2]);
  }

  {
    CR();
    Matrix<Tensor<double, 3>, 2, 2> m{{{{{-0, -1},
                                         {-10, -11},
                                         {-20, -21}},
                                        {{-100, -101},
                                         {-110, -111},
                                         {-120, -121}}},
                                       {{{-1000, -1001},
                                         {-1010, -1011},
                                         {-1020, -1021}},
                                        {{-1100, -1101},
                                         {-1110, -1111},
                                         {-1120, -1121}}}},
                                      {{{{-10000, -10001},
                                         {-10010, -10011},
                                         {-10020, -10021}},
                                        {{-10100, -10101},
                                         {-10110, -10111},
                                         {-10120, -10121}}},
                                       {{{-11000, -11001},
                                         {-11010, -11011},
                                         {-11020, -11021}},
                                        {{-11100, -11101},
                                         {-11110, -11111},
                                         {-11120, -11121}}}}};

    TLDISP(m);
    TLDISP((-m)[1]);
  }

  /////////////////////////////////////////////////////////////////



  CR();
  CR();
  MOUT << bold.apply("Two-Level Tensor tests") << endl;
  {
    CR();
    Tensor<Scalar<double>, 2> t{{{1}, {2}}, {{3}, {4}}};
    TLDISP(t);
    TLDISP((-t)[1]);
  }
  {
    CR();
    Tensor<Vector<double>, 2> t{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    TLDISP(t);
    TLDISP((-t)[1]);
  }

  {
    CR();
    Tensor<Matrix<double, 2, 2>, 2> t{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    TLDISP(t);
    TLDISP((-t)[1]);
  }


  {
    CR();
    Tensor<Tensor<double, 3>, 2> t{{{{{0, 1},
                                      {10, 11},
                                      {20, 21}},
                                     {{100, 101},
                                      {110, 111},
                                      {120, 121}}},
                                    {{{1000, 1001},
                                      {1010, 1011},
                                      {1020, 1021}},
                                     {{1100, 1101},
                                      {1110, 1111},
                                      {1120, 1121}}}},
                                   {{{{10000, 10001},
                                      {10010, 10011},
                                      {10020, 10021}},
                                     {{10100, 10101},
                                      {10110, 10111},
                                      {10120, 10121}}},
                                    {{{11000, 11001},
                                      {11010, 11011},
                                      {11020, 11021}},
                                     {{11100, 11101},
                                      {11110, 11111},
                                      {11120, 11121}}}}};

    TLDISP(t);
    TLDISP((-t)[1]);
  }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
