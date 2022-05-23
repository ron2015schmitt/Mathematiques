#include <vector>
#include <string>

#define MATHQ_DEBUG 0
#include "mathq.h"


template <typename D, int M = 1 + mathq::NumberType<D>::depth()>
class Test : public mathq::TensorRW<Test<D>, D, typename mathq::NumberType<D>::Type, M, 1> {
public:
  typedef D Type;
  Test() {
  }
  constexpr mathq::size_type depth() const {
    return M;
  }
};



template <typename D>
class Test2 : public mathq::TensorRW<Test<D>, D, D, 1, 1> {
public:
  typedef D Type;
  D d_;
  Test2() {
  }
  Test2(D d) : d_(d) {
  }
  constexpr mathq::size_type depth() const {
    return mathq::NumberType<decltype(*this)>::depth();
  }
};


int main(int argc, char *argv[]) {


  typedef typename mathq::Vector<double> VectorDouble;

  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;
  using namespace std;

  Style bold = CREATESTYLE(BOLD);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();





  // {
  //   CR();
  //   MOUT << bold.apply("Complexify") << endl;
  //   Complexify<double>::Type double_;
  //   TLDISP(double_);
  //   Complexify<std::complex<double> >::Type complexdouble_;
  //   TLDISP(complexdouble_);
  //   // Complexify<Scalar<double> >::Type scalardouble_;
  //   // TLDISP(scalardouble_);
  //   // Complexify<Scalar<std::complex<double> > >::Type scalarcomplexdouble_;
  //   // TLDISP(scalarcomplexdouble_);
  // }

  //   {
  //   CR();
  //   MOUT << bold.apply("Realify") << endl;
  //   Realify<double>::Type double_;
  //   TLDISP(double_);
  //   Realify<std::complex<double> >::Type complexdouble_;
  //   TLDISP(complexdouble_);
  //   // Realify<Scalar<double> >::Type scalardouble_;
  //   // TLDISP(scalardouble_);
  //   // Realify<Scalar<std::complex<double> > >::Type scalarcomplexdouble_;
  //   // TLDISP(scalarcomplexdouble_);
  // }


  {
    CR();
    MOUT << bold.apply("conj(Scalar<D>)") << endl;
    Scalar<ComplexDouble> z = ComplexDouble(1, 2);
    Scalar<double> x = 6.5;
    TLDISP(z);
    TLDISP(x);
    TLDISP(conj(z));
    TLDISP(conj(x));
    TLDISP(real(z));
    TLDISP(imag(z));
    TLDISP(real(x));
    TLDISP(imag(x));
    TLDISP(z.conj());
    // TLDISP(x.conj());
  }


  {
    CR();
    MOUT << bold.apply("Vector<double> testing") << std::endl;
    TLDISP(NumberType<double>::depth());
    Vector<double> vd{1, 2, 3, 4};
    TLDISP(vd);

    TLDISP(FundamentalType<double>::depth());
    FundamentalType<double>::Type d1 = 0.1;
    TLDISP(d1);

    TLDISP(FundamentalType<ComplexDouble>::depth());
    FundamentalType<ComplexDouble>::Type d2 = 0.1;
    TLDISP(d2);

    TLDISP(FundamentalType<decltype(vd)>::depth());
    FundamentalType<decltype(vd)>::Type d3 = 0.1;
    TLDISP(d3);

    TLDISP(NumberType<decltype(vd)>::depth());
    NumberType<decltype(vd)>::Type d4 = 0.2;
    TLDISP(d4);
  }
  {
    CR();
    MOUT << bold.apply("Vector<ComplexDouble> testing") << std::endl;
    TLDISP(NumberType<ComplexDouble>::depth());
    Vector<ComplexDouble> vd{ComplexDouble(0.1, 1), ComplexDouble(0.2, 2), ComplexDouble(3, 0.3)};
    TLDISP(vd);
    TLDISP(FundamentalType<decltype(vd)>::depth());
    FundamentalType<decltype(vd)>::Type d = 3.14;
    TLDISP(d);
    TLDISP(NumberType<decltype(vd)>::depth());
    NumberType<decltype(vd)>::Type d2 = ComplexDouble(0.1, 0.2);
    TLDISP(d2);
  }
  {
    CR();
    MOUT << bold.apply("Vector<Vector<double> > testing") << std::endl;
    Vector<Vector<double>> vd{{1.1, 1.2}, {2.1, 2.2}, {3.1, 3.2}};
    TLDISP(vd);
    TLDISP(FundamentalType<decltype(vd)>::depth());
    FundamentalType<decltype(vd)>::Type d = 0.1;
    TLDISP(d);
    TLDISP(NumberType<decltype(vd)>::depth());
    NumberType<decltype(vd)>::Type d2 = 0.2;
    TLDISP(d2);
  }
  {
    using namespace std;
    // this work sbut DISP() doesn't work because it doesn't recurse formats
    CR();
    MOUT << bold.apply("complex<Vector<double>> testing") << std::endl;
    TLDISP(NumberType<complex<Vector<double>>>::depth());
    complex<Vector<double>> vd = complex<Vector<double>>({1.1, 1.2, 1.3}, {2.1, 2.2, 2.3});
    MOUT << vd << endl;
    TLDISP(FundamentalType<decltype(vd)>::depth());
    FundamentalType<decltype(vd)>::Type d = 43;
    TLDISP(d);
    TLDISP(NumberType<decltype(vd)>::depth());
    NumberType<decltype(vd)>::Type v2 = vd;
    MOUT << v2 << endl;

    //  TODO: need to define operator+=
    //    NumberType<decltype(vd)>::Type v3 = vd+v2;
    //    MOUT << v3 << endl;
  }

  // {
  //   CR();
  //   MOUT << bold.apply("Test class testing") << std::endl;
  //   Test<double> t0;
  //   TLDISP(NumberType<decltype(t0)>::depth());
  //   TLDISP(t0.depth());
  //   Test<Test<double>> t1;
  //   TLDISP(NumberType<decltype(t1)>::depth());
  //   TLDISP(t1.depth());
  //   Test<Test<Test<double>>> t2;
  //   TLDISP(NumberType<decltype(t2)>::depth());
  //   TLDISP(t2.depth());
  // }

  // {
  //   CR();
  //   MOUT << bold.apply("Test2 class testing") << std::endl;
  //   Test2<double> t0(0);
  //   TLDISP(NumberType<decltype(t0)>::depth());
  //   TLDISP(t0.depth());
  //   Test2<Test2<double>> t1 {1};
  //   TLDISP(NumberType<decltype(t1)>::depth());
  //   TLDISP(t1.depth());
  //   Test2<Test2<Test2<double>>> t2 {{2}};
  //   TLDISP(NumberType<decltype(t2)>::depth());
  //   TLDISP(t2.depth());
  // }


  {
    CR();
    MOUT << bold.apply("Scalar<double> class testing") << std::endl;
    Scalar<double> t1(1.1);
    TLDISP(t1);
    TLDISP(NumberType<decltype(t1)>::depth());
    TLDISP(t1.size());
    TLDISP(t1.depth());
    TLDISP(t1.elsize());
    TLDISP(t1.eldeepsize());
    TLDISP(t1.deepsize());

    CR();
    MOUT << bold.apply("Vector<double> class testing") << std::endl;
    Vector<double> v{1, 2, 3, 4};
    TLDISP(v);
    TLDISP(NumberType<decltype(v)>::depth());
    TLDISP(v.size());
    TLDISP(v.depth());
    TLDISP(v.elsize());
    TLDISP(v.eldeepsize());
    TLDISP(v.deepsize());

    MOUT << bold.apply("Scalar<Scalar<double>> class testing") << std::endl;
    Scalar<Scalar<double>> t2{{2.2}};
    TLDISP(t2);
    TLDISP(NumberType<decltype(t2)>::depth());
    TLDISP(t2.size());
    TLDISP(t2.depth());
    TLDISP(t2.elsize());
    TLDISP(t2.eldeepsize());
    TLDISP(t2.deepsize());

    MOUT << bold.apply("Scalar<Vector<double>> class testing") << std::endl;
    Scalar<Vector<double>> t3{{1, 2}};
    TLDISP(t3);
    TLDISP(NumberType<decltype(t3)>::depth());
    TLDISP(t3.size());
    TLDISP(t3.depth());
    TLDISP(t3.elsize());
    TLDISP(t3.eldeepsize());
    TLDISP(t3.deepsize());


    Vector<Scalar<double>> t4(0);
    TLDISP(t4);
    TLDISP(NumberType<decltype(t4)>::depth());
    TLDISP(t4.size());
    TLDISP(t4.depth());
    TLDISP(t4.elsize());
    TLDISP(t4.eldeepsize());
    TLDISP(t4.deepsize());

    Vector<Scalar<double>> t5(3);
    TLDISP(t5);
    TLDISP(t5[0]);
    TLDISP(t5[1]);
    TLDISP(t5[2]);
    t5[0] = 3.2;
    TLDISP(t5[0]);
    TLDISP(NumberType<decltype(t5)>::depth());
    TLDISP(t5.size());
    TLDISP(t5.depth());
    TLDISP(t5.elsize());
    TLDISP(t5.eldeepsize());
    TLDISP(t5.deepsize());

    Vector<Scalar<double>> t6{{1}, {2}};
    TLDISP(t6);
    TLDISP(NumberType<decltype(t6)>::depth());
    TLDISP(t6.size());
    TLDISP(t6.depth());
    TLDISP(t6.elsize());
    TLDISP(t6.eldeepsize());
    TLDISP(t6.deepsize());


    Vector<Vector<double>> t7{{1, 2, 3}, {4, 5, 6}};
    TLDISP(t7);
    TLDISP(NumberType<decltype(t7)>::depth());
    TLDISP(t7.size());
    TLDISP(t7.depth());
    TLDISP(t7.elsize());
    TLDISP(t7.eldeepsize());
    TLDISP(t7.deepsize());

    for (int n = 0; n < t7.deepsize(); n++) {
      TLDISP(t7.dat(n));
    }
    for (int n = 0; n < t7.size(); n++) {
      TLDISP(t7(n));
    }

    // MOUT << bold.apply("Vector<Vector<double>> class testing") << std::endl;
    // Vector<Vector<double>> t5 {{1,2},{3,4},{5,6}};
    // TLDISP(t5);
    // TLDISP(NumberType<decltype(t5)>::depth());
    // TLDISP(t5.size());
    // TLDISP(t5.depth());
    // TLDISP(t5.elsize());
    // TLDISP(t5.eldeepsize());
    // TLDISP(t5.deepsize());
  }

  {
    Vector<double> t1{4, 5, 6};
    TLDISP(t1);
    Vector<Vector<double>> t2{{1, 2, 3}, {4, 5, 6}};
    TLDISP(t2);

    typename DeeperType<decltype(t1), decltype(t2)>::Type x;
    TLDISP(x);
    typename DeeperType<decltype(t2), decltype(t1)>::Type y;
    TLDISP(y);
    typename DeeperType<double, decltype(t1)>::Type z;
    TLDISP(z);
    typename NumberType<decltype(t1), float>::ReplaceTypeD w;
    TLDISP(w);
  }

  //------------------------------------------------------

  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
