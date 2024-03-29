
#include <fstream>

#define MATHQ_DEBUG 0
#include "mathq.h"



int main(int argc, char* argv[]) {

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
    // Scalar<double> s = 1.1;
    Scalar<double> s(1.1);
    TLDISP(s);
    TLDISP(s());
    TLDISP(s.dims());
    TLDISP(s.size());
    Scalar<double> s2;
    s2 = -s;
    TLDISP(s2);
    Scalar<double> s3(s);
    TLDISP(s3);
    Scalar<double> s4 = s;
    TLDISP(s4);
    s4 = 4.5;
    TLDISP(s4);
    Scalar<double> s5 = 4.4;
    TLDISP(s5);
    Scalar<double> s6 = { 4.4 };
    TLDISP(s6);
    Scalar<double> s7{ 4.4 };
    TLDISP(s7);
    Scalar<double> s8({ 4.4 });
    TLDISP(s8);
  }


  CR();
  CR();
  MOUT << bold.apply("Vector") << endl;
  {
    CR();
    Vector<double> v{ 1.1, 2.2 };
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
    Vector<double, 2> v{ 1, 2 };
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

    Matrix<double> m{ {1, 2}, {3, 4} };
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
    Matrix<double, 2, 2> m{ {1.1, 2.2}, {3.3, 4.4} };
    TLDISP(m);
    Matrix<double, 2, 2> m2;
    m2 = -m;
    TLDISP(m2);
  }


  CR();
  CR();
  MOUT << bold.apply("MultiArray -- Initializer lists") << endl;
  {
    CR();
    std::initializer_list<double> x1{ 1, 2 };
    TLDISP(x1);

    std::initializer_list<std::initializer_list<double>> x2{ {1, 2}, {3, 4} };
    TLDISP(x2);

    // NestedInitializerList<double, 1> y1{1, 2};
    // TLDISP(y1);

    // NestedInitializerList<double, 2> y2{{1, 2}, {3, 4}};
    // TLDISP(y2);
  }

  CR();
  CR();
  MOUT << bold.apply("MultiArray") << endl;
  {
    CR();
    MultiArray<double, 3> t0;
    TLDISP(t0.dims());
    TLDISP(t0.element_dims());
    TLDISP(t0);
    MultiArray<double, 3> t1;
    TLDISP(t1.dims());
    TLDISP(t1.recursive_dims());
    TLDISP(t1.total_size());
    TLDISP(t1.depth());
    TLDISP(t1);
    Dimensions dims({ 3, 2, 5 });
    MultiArray<double, 3> t2(dims);
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

    MultiArray<double, 1> t3{ 1, 2, 3 };
    TLDISP(t3.dims());
    TLDISP(t3.element_dims());
    TLDISP(t3);


    MultiArray<double, 2> t4{ {1.1, 2.2}, {3.3, 4.4} };
    TLDISP(t4.dims());
    TLDISP(t4);

    MultiArray<double, 3> t5{
        {{0, 1, 2, 3, 4}, {10, 11, 12, 13, 14}},
        {{100, 101, 102, 103, 104}, {110, 111, 112, 113, 114}},
        {{200, 201, 202, 203, 204}, {210, 211, 212, 213, 214}} };

    TLDISP(t5.dims());
    TLDISP(t5(2, 1, 3));
    TLDISP(t5);
  }


  CR();
  {
    MultiArray<double, 2> t{ {1.1, 2.2}, {3.3, 4.4} };
    TLDISP(t);
    MultiArray<double, 2> t2;
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
    ECHO(Scalar<Scalar<double>> s{ {1.1} });
    TLDISP(s);
    TLDISP(s());
    TLDISP(s()());
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s.recursive_dims());
    Scalar<Scalar<double>> s2;
    s2 = -s;
    TLDISP(s2);
  }

  {
    CR();
    ECHO(Scalar<Vector<double>> s{ {1., 2., 3.} });
    TLDISP(s);
    TLDISP(s());
    TLDISP(s[0]);
    TLDISP(s()(2));
    TLDISP(s.dat(2));
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s.recursive_dims());
    Scalar<Vector<double>> s2;
    OUTPUT("HERE");
    ECHO(s2 = s);
    OUTPUT("HERE2");
    TLDISP(s2);
    OUTPUT("HERE3");
  }

  {
    CR();
    ECHO(Scalar<Matrix<double>> s{ {{1, 2}, {3, 4}} });
    TLDISP(s);
    TLDISP(s()(0, 1));
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s.recursive_dims());

    Scalar<Matrix<double>> s2;
    s2 = -s;
    TLDISP(s2);
  }

  {
    CR();
    ECHO(Scalar<MultiArray<double, 2>> s{ {{1, 2}, {3, 4}} });
    TLDISP(s);
    TLDISP(s());
    TLDISP(s()(0, 1));
    TLDISP(s.dims());
    TLDISP(s.size());
    TLDISP(s().dims());
    TLDISP(s.depth());
    TLDISP(s.recursive_dims());

    Scalar<MultiArray<double, 2>> s2;
    s2 = -s;
    TLDISP(s2);
  }


  CR();
  CR();
  MOUT << bold.apply("Two-Level Vector tests") << endl;
  {
    CR();
    ECHO(Vector<Scalar<double>> v{ {1.}, {2.} });
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(0)());
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.recursive_dims());
    Vector<Scalar<double>> v2;
    v2 = -v;
    TLDISP(v2);
  }

  {
    CR();
    ECHO(Vector<Vector<double>> v{ {1., 2., 3.}, {4., 5., 6.} });
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(0)(2));
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.recursive_dims());
    Vector<Vector<double>> v2;
    MOUT << "v2 = -v;" << endl;
    v2 = -v;
    TLDISP(v2);
  }
  {
    CR();
    ECHO(Vector<Matrix<double>> v{ {{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}} });
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(1)(0, 1));
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.recursive_dims());
    Vector<Matrix<double>> v2;
    MOUT << "v2 = -v;" << endl;
    v2 = -v;
    TLDISP(v2);
  }
  {
    CR();
    ECHO(Vector<MultiArray<double, 2>> v{ {{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}} });
    TLDISP(v);
    TLDISP(v(0));
    TLDISP(v(2)(1, 1));
    TLDISP(v.dims());
    TLDISP(v.size());
    TLDISP(v.recursive_dims());
    Vector<MultiArray<double, 2>> v2;
    MOUT << "v2 = -v;" << endl;
    v2 = -v;
    TLDISP(v2);
  }


  CR();
  CR();
  MOUT << bold.apply("Two-Level Matrix tests") << endl;
  {
    CR();
    ECHO(Matrix<Scalar<double>> m{ {{1}, {2}}, {{3}, {4}} });
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)());
    TLDISP(m.Nrows());
    TLDISP(m.Ncols());
    TLDISP(m.dims());
    TLDISP(m.recursive_dims());
    Matrix<Scalar<double>> m2;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    ECHO(Matrix<Vector<double>> m{ {{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}} });
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)(1));
    TLDISP(m.Nrows());
    TLDISP(m.Ncols());
    TLDISP(m.dims());
    TLDISP(m.recursive_dims());
    Matrix<Vector<double>> m2;
    MOUT << "m2 = -m;" << endl;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    ECHO(Matrix<Matrix<double>> m{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}} });
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)(1, 1));
    TLDISP(m.dims());
    TLDISP(m.size());
    TLDISP(m.recursive_dims());
    Matrix<Matrix<double>> m2;
    MOUT << "m2 = -m;" << endl;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    ECHO(Matrix<MultiArray<double, 3>, 2, 2> m1);
    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.recursive_dims());
    Dimensions template_dims({ 2, 3, 2 });

    for (int i = 0; i < m1.dims()[0]; i++) {
      for (int j = 0; j < m1.dims()[1]; j++) {
        m1(i, j).resize(template_dims);
        for (int k = 0; k < template_dims[0]; k++) {
          for (int l = 0; l < template_dims[1]; l++) {
            for (int m = 0; m < template_dims[2]; m++) {
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
    TLDISP(m1.recursive_dims());


    ECHO(Matrix<MultiArray<double, 3>> m2);
    MOUT << "m2 = -m1;" << endl;
    m2 = -m1;
    TLDISP(m2);
  }

  {
    CR();
    ECHO(Matrix<MultiArray<double, 3>, 2, 2> m1{ {{{{-0, -1},
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
                                          {-11120, -11121}}}} });

    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.recursive_dims());
  }


  /////////////////////////////////////////////////////////////////



  CR();
  CR();
  MOUT << bold.apply("Two-Level MultiArray tests") << endl;
  {
    CR();
    ECHO(MultiArray<Scalar<double>, 2> t);
    TLDISP(t);
    TLDISP(t.dims());
    TLDISP(t.recursive_dims());
    Dimensions template_dims({ 2, 2 });
    t.resize(template_dims);
    t(0, 0) = 1;
    t(0, 1) = 2;
    t(1, 0) = 3;
    t(1, 1) = 4;
    TLDISP(t);
    TLDISP(t.dims());
    TLDISP(t.recursive_dims());
    TLDISP(t.element_dims());
  }
  {

    CR();
    ECHO(MultiArray<Scalar<double>, 2> t{ {{1}, {2}}, {{3}, {4}} });
    TLDISP(t);
    TLDISP(t(1, 0));
    TLDISP(t(1, 0)());
    TLDISP(t.dims());
    TLDISP(t.recursive_dims());
    TLDISP(t.element_dims());
    decltype(t) xx;
    TLDISP(xx);
    typename decltype(t)::NumberType d;
    TLDISP(d);
    typename decltype(t)::ElementType e;
    TLDISP(e);

    MultiArray<Scalar<double>, 2> t2;
    typename MultiArray<Scalar<double>, 2>::NumberType d2a;
    TLDISP(d2a);
    typename MultiArray<Scalar<double>, 2>::ElementType e2a;
    TLDISP(e2a);
    typename decltype(t2)::NumberType d2b;
    TLDISP(d2b);
    typename decltype(t2)::ElementType e2b;
    TLDISP(e2b);
    t2 = -t;
    TLDISP(t2);
  }

  {
    CR();
    ECHO(MultiArray<Vector<double>, 2> t{ {{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}} });
    TLDISP(t);
    TLDISP(t(0, 0));
    TLDISP(t(0, 0)(1));
    TLDISP(t.dims());
    TLDISP(t.recursive_dims());
    MultiArray<Vector<double>, 2> t2;
    MOUT << "t2 = -t;" << endl;
    t2 = -t;
    TLDISP(t2);
  }

  {
    CR();
    ECHO(MultiArray<Matrix<double, 2, 2>, 2> m{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}} });
    TLDISP(m);
    TLDISP(m(0, 0));
    TLDISP(m(0, 0)(1, 1));
    TLDISP(m.dims());
    TLDISP(m.size());
    TLDISP(m.recursive_dims());
    MultiArray<Matrix<double, 2, 2>, 2> m2;
    MOUT << "m2 = -m;" << endl;
    m2 = -m;
    TLDISP(m2);
  }

  {
    CR();
    ECHO(MultiArray<MultiArray<double, 3>, 2> m1);
    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.recursive_dims());
    Dimensions tdims1({ 2, 2 });
    m1.resize(tdims1);
    Dimensions tdims2({ 2, 3, 2 });

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
    TLDISP(m1.recursive_dims());


    MultiArray<MultiArray<double, 3>, 2> m2;
    MOUT << "m2 = -m1;" << endl;
    m2 = -m1;
    TLDISP(m2);
  }

  {
    CR();
    ECHO(MultiArray<MultiArray<double, 3>, 2> m1{ {{{{-0, -1},
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
                                       {-11120, -11121}}}} });

    TLDISP(m1);
    TLDISP(m1.dims());
    TLDISP(m1.size());
    TLDISP(m1.recursive_dims());
  }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
