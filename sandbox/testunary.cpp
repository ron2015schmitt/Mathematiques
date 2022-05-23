
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
    TLDISP(s());
    TLDISP(s.dims());
    TLDISP(s.size());
    Scalar<double> s2;
    s2 = -s;
    TLDISP(s2);
  }

  CR();
  CR();
  MOUT << bold.apply("Vector") << endl;
  {
    CR();
    Vector<double> v{1.1, 2.2};
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v.dims());
    TLDISP(v.size());
    Vector<double> v2;
    v2 = -v;
    TLDISP(v2);
  }

  {
    CR();
    Vector<double, 2> v{1, 2};
    TLDISP(v);
    Vector<double, 2> v2;
    v2 = -v;
    TLDISP(v2);
  }

  CR();
  CR();
  MOUT << bold.apply("Matrix") << endl;
  {
    CR();
    Matrix<double> m0;
    TLDISP(m0);

    Matrix<double> m{{1, 2}, {3, 4}};
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m.Nrows());
    TLDISP(m.Ncols());
    TLDISP(m.dims());
    Matrix<double> m2;
    TLDISP(m2);
    m2 = -m;
    TLDISP(m2);
  }
  CR();
  {
    Matrix<double, 2, 2> m{{1.1, 2.2}, {3.3, 4.4}};
    TLDISP(m);
    Matrix<double, 2, 2> m2;
    m2 = -m;
    TLDISP(m2);
  }


  CR();
  CR();
  MOUT << bold.apply("Tensor -- Initializer lists") << endl;
  {
    CR();
    std::initializer_list<double> x1{1, 2};
    TLDISP(x1);

    std::initializer_list<std::initializer_list<double>> x2{{1, 2}, {3, 4}};
    TLDISP(x2);

    NestedInitializerList<double, 1> y1{1, 2};
    TLDISP(y1);

    NestedInitializerList<double, 2> y2{{1, 2}, {3, 4}};
    TLDISP(y2);
  }

  CR();
  CR();
  MOUT << bold.apply("Tensor") << endl;
  {
    CR();
    Tensor<double> t0;
    TLDISP(t0.dims());
    TLDISP(t0.eldims());
    TLDISP(t0);
    Tensor<double, 3> t1;
    TLDISP(t1.dims());
    TLDISP(t1.deepdims());
    TLDISP(t1.deepsize());
    TLDISP(t1.depth());
    TLDISP(t1);
    Dimensions dims(3, 2, 5);
    Tensor<double, 3> t2(dims);
    TLDISP(t2.dims());
    TLDISP(t2);
    for (int i = 0; i < t2.size(); i++) {
      t2[i] = double(i);
    }
    TLDISP(t2);
    for (int i = 0; i < t2.dims()[0]; i++) {
      for (int j = 0; j < t2.dims()[1]; j++) {
        for (int k = 0; k < t2.dims()[2]; k++) {
          t2(i, j, k) = double(100 * i) + double(10 * j) + double(k);
          // MDISP(i,j,k,t2(i,j,k));
        }
      }
    }
    TLDISP(t2);

    Tensor<double, 1> t3{1, 2, 3};
    TLDISP(t3.dims());
    TLDISP(t3.eldims());
    TLDISP(t3);


    Tensor<double, 2> t4{{1.1, 2.2}, {3.3, 4.4}};
    TLDISP(t4.dims());
    TLDISP(t4);

    Tensor<double, 3> t5{
        {{0, 1, 2, 3, 4}, {10, 11, 12, 13, 14}},
        {{100, 101, 102, 103, 104}, {110, 111, 112, 113, 114}},
        {{200, 201, 202, 203, 204}, {210, 211, 212, 213, 214}}};

    TLDISP(t5.dims());
    TLDISP(t5(2, 1, 3));
    TLDISP(t5);
  }


  CR();
  {
    Tensor<double, 2> t{{1.1, 2.2}, {3.3, 4.4}};
    TLDISP(t);
    Tensor<double, 2> t2;
    t2 = -t;
    TLDISP(t2);
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
    TLDISP(s());
    TLDISP(s()());
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s.deepdims());
    Scalar<Scalar<double>> s2;
    s2 = -s;
    TLDISP(s2);
  }

  {
    CR();
    Scalar<Vector<double>> s{{1., 2., 3.}};
    TLDISP(s);
    TLDISP(s()(2));
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s.deepdims());
    Scalar<Vector<double>> s2;
    s2 = -s;
    TLDISP(s2);
  }

  {
    CR();
    Scalar<Matrix<double>> s{{{1, 2}, {3, 4}}};
    TLDISP(s);
    TLDISP(s()(0, 1));
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s.deepdims());

    Scalar<Matrix<double>> s2;
    s2 = -s;
    TLDISP(s2);
  }

  {
    CR();
    Scalar<Tensor<double, 2>> s{{{1, 2}, {3, 4}}};
    TLDISP(s);
    TLDISP(s());
    TLDISP(s()(0, 1));
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s().dims());
    TLDISP(s.depth());
    TLDISP(s.deepdims());

    Scalar<Tensor<double, 2>> s2;
    s2 = -s;
    TLDISP(s2);
  }

  CR();
  CR();
  MOUT << bold.apply("Two-Level Vector tests") << endl;
  {
    CR();
    Vector<Scalar<double>> v{{1.}, {2.}};
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(0)());
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.deepdims());
    Vector<Scalar<double>> v2;
    v2 = -v;
    TLDISP(v2);
  }

  {
    CR();
    Vector<Vector<double>> v{{1., 2., 3.}, {4., 5., 6.}};
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(0)(2));
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.deepdims());
    Vector<Vector<double>> v2;
    MOUT << "v2 = -v;" << endl;
    v2 = -v;
    TLDISP(v2);
  }
  {
    CR();
    Vector<Matrix<double>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(1)(0, 1));
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.deepdims());
    Vector<Matrix<double>> v2;
    MOUT << "v2 = -v;" << endl;
    v2 = -v;
    TLDISP(v2);
  }
  {
    CR();
    Vector<Tensor<double, 2>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(2)(1, 1));
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.deepdims());
    Vector<Tensor<double, 2>> v2;
    MOUT << "v2 = -v;" << endl;
    v2 = -v;
    TLDISP(v2);
  }


  CR();
  CR();
  MOUT << bold.apply("Two-Level Matrix tests") << endl;
  {
    CR();
    Matrix<Scalar<double>> m{{{1}, {2}}, {{3}, {4}}};
    ;
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)());
    TLDISP(m.Nrows());
    TLDISP(m.Ncols());
    TLDISP(m.dims());
    TLDISP(m.deepdims());
    Matrix<Scalar<double>> m2;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    Matrix<Vector<double>> m{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)(1));
    TLDISP(m.Nrows());
    TLDISP(m.Ncols());
    TLDISP(m.dims());
    TLDISP(m.deepdims());
    Matrix<Vector<double>> m2;
    MOUT << "m2 = -m;" << endl;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    Matrix<Matrix<double>> m{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)(1, 1));
    TLDISP(m.dims());
    TLDISP(m.size());
    TLDISP(m.deepdims());
    Matrix<Matrix<double>> m2;
    MOUT << "m2 = -m;" << endl;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    Matrix<Tensor<double, 3>, 2, 2> m1;
    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.deepdims());
    Dimensions tdims(2, 3, 2);

    for (int i = 0; i < m1.dims()[0]; i++) {
      for (int j = 0; j < m1.dims()[1]; j++) {
        m1(i, j).resize(tdims);
        for (int k = 0; k < tdims[0]; k++) {
          for (int l = 0; l < tdims[1]; l++) {
            for (int m = 0; m < tdims[2]; m++) {
              m1(i, j)(k, l, m) = double(10000 * i) + double(1000 * j) + double(100 * k) + double(10 * l) + double(m);
            }
          }
        }
      }
    }
    TLDISP(m1);
    TLDISP(m1(0, 1));
    TLDISP(m1(1, 0)(1, 2, 0));
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.deepdims());


    Matrix<Tensor<double, 3>> m2;
    MOUT << "m2 = -m1;" << endl;
    m2 = -m1;
    TLDISP(m2);
  }

  {
    CR();
    Matrix<Tensor<double, 3>, 2, 2> m1{{{{{-0, -1},
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

    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.deepdims());
  }


  /////////////////////////////////////////////////////////////////



  CR();
  CR();
  MOUT << bold.apply("Two-Level Tensor tests") << endl;
  {
    CR();
    Tensor<Scalar<double>, 2> t;
    TLDISP(t);
    TLDISP(t.dims());
    TLDISP(t.deepdims());
    Dimensions tdims(2, 2);
    t.resize(tdims);
    t(0, 0) = 1;
    t(0, 1) = 2;
    t(1, 0) = 3;
    t(1, 1) = 4;
    TLDISP(t);
    TLDISP(t.dims());
    TLDISP(t.deepdims());
    TLDISP(t.eldims());
  }
  {

    CR();
    Tensor<Scalar<double>, 2> t{{{1}, {2}}, {{3}, {4}}};
    TLDISP(t);
    TLDISP(t(1, 0));
    TLDISP(t(1, 0)());
    TLDISP(t.dims());
    TLDISP(t.deepdims());
    TLDISP(t.eldims());
    decltype(t) xx;
    TLDISP(xx);
    typename decltype(t)::DType d;
    TLDISP(d);
    typename decltype(t)::EType e;
    TLDISP(e);

    Tensor<Scalar<double>, 2> t2;
    typename Tensor<Scalar<double>, 2>::DType d2a;
    TLDISP(d2a);
    typename Tensor<Scalar<double>, 2>::EType e2a;
    TLDISP(e2a);
    typename decltype(t2)::DType d2b;
    TLDISP(d2b);
    typename decltype(t2)::EType e2b;
    TLDISP(e2b);
    t2 = -t;
    TLDISP(t2);
  }

  {
    CR();
    Tensor<Vector<double>, 2> t{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    TLDISP(t);
    TLDISP(t(0, 0));
    TLDISP(t(0, 0)(1));
    TLDISP(t.dims());
    TLDISP(t.deepdims());
    Tensor<Vector<double>, 2> t2;
    MOUT << "t2 = -t;" << endl;
    t2 = -t;
    TLDISP(t2);
  }

  {
    CR();
    Tensor<Matrix<double, 2, 2>, 2> m{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)(1, 1));
    TLDISP(m.dims());
    TLDISP(m.size());
    TLDISP(m.deepdims());
    Tensor<Matrix<double, 2, 2>, 2> m2;
    MOUT << "m2 = -m;" << endl;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    Tensor<Tensor<double, 3>, 2> m1;
    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.deepdims());
    Dimensions tdims1(2, 2);
    m1.resize(tdims1);
    Dimensions tdims2(2, 3, 2);

    for (int i = 0; i < m1.dims()[0]; i++) {
      for (int j = 0; j < m1.dims()[1]; j++) {
        m1(i, j).resize(tdims2);
        for (int k = 0; k < tdims2[0]; k++) {
          for (int l = 0; l < tdims2[1]; l++) {
            for (int m = 0; m < tdims2[2]; m++) {
              m1(i, j)(k, l, m) = double(10000 * i) + double(1000 * j) + double(100 * k) + double(10 * l) + double(m);
            }
          }
        }
      }
    }
    TLDISP(m1);
    TLDISP(m1(0, 1));
    TLDISP(m1(1, 0)(1, 2, 0));
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.deepdims());


    Tensor<Tensor<double, 3>, 2> m2;
    MOUT << "m2 = -m1;" << endl;
    m2 = -m1;
    TLDISP(m2);
  }

  {
    CR();
    Tensor<Tensor<double, 3>, 2> m1{{{{{-0, -1},
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

    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.deepdims());
  }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
