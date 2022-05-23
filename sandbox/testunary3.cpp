
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

  CR();
  CR();
  MOUT << bold.apply("scalar") << endl;
  {
    CR();
    double x = 0.25;
    TLDISP(x);
    TLDISP(+x);
    TLDISP(+(x));
    TLDISP(-x);
    TLDISP(mathq::real(x));
    TLDISP(mathq::imag(x));
    TLDISP(mathq::conj(x));
    TLDISP(mathq::zero(x));
    TLDISP(std::abs(x));
    TLDISP(std::arg(x));
    TLDISP(std::proj(x));

    Imaginary<double> y(2);
    TLDISP(y);
    TLDISP(mathq::real(y));
    TLDISP(mathq::imag(y));
    TLDISP(mathq::conj(y));


    std::complex<double> z(1, 2);
    TLDISP(z);
    TLDISP(std::real(z));
    TLDISP(std::imag(z));
    TLDISP(std::conj(z));
    TLDISP(mathq::conj(z));

    TLDISP(std::proj(z));
    TLDISP(std::proj(ComplexDouble(5.0, 0)));
    TLDISP(std::proj(ComplexDouble(0.2, 0)));
    TLDISP(std::proj(ComplexDouble(0, 5.0)));
    TLDISP(std::proj(ComplexDouble(0, 0.2)));
  }


  CR();
  CR();
  MOUT << bold.apply("Scalar") << endl;
  {

    CR();
    MOUT << blue.apply("Boolean Scalar") << endl;

    CR();
    Scalar<bool> sb = true;
    TLDISP(sb);
    TLDISP(!sb);
    TLDISP(operator!(sb));
    TLDISP(!(!sb));




    CR();
    MOUT << blue.apply("Real Scalar") << endl;

    Scalar<double> sr = 0.25;
    TLDISP(sr);
    TLDISP(-sr);
    TLDISP(conj(sr));
    TLDISP(real(sr));
    TLDISP(imag(sr));
    TLDISP(abs(sr));
    TLDISP(arg(sr));
    TLDISP(proj(sr));

    TLDISP(exp(sr));
    TLDISP(log(sr));
    TLDISP(log10(sr));
    TLDISP(sqrt(sr));

    TLDISP(sin(sr));
    TLDISP(cos(sr));
    TLDISP(tan(sr));

    TLDISP(asin(sr));
    TLDISP(acos(sr));
    TLDISP(atan(sr));

    TLDISP(sinh(sr));
    TLDISP(cosh(sr));
    TLDISP(tanh(sr));

    TLDISP(asinh(sr));
    TLDISP(acosh(sr));
    TLDISP(atanh(sr));


    CR();
    MOUT << blue.apply("Imag Scalar") << endl;
    Scalar<Imaginary<double>> si;
    si() = Imaginary<double>(0.25);

    TLDISP(si);
    TLDISP(-si);
    TLDISP(conj(si));
    TLDISP(real(si));
    TLDISP(imag(si));
    TLDISP(abs(si));
    TLDISP(arg(si));
    TLDISP(proj(si));

    TLDISP(exp(si));
    TLDISP(exp(ComplexDouble(0, 0.25)));
    TLDISP(log(si));
    TLDISP(log10(si));
    TLDISP(sqrt(si));

    TLDISP(sin(si));
    TLDISP(cos(si));
    TLDISP(tan(si));

    TLDISP(asin(si));
    TLDISP(acos(si));
    TLDISP(atan(si));

    TLDISP(sinh(si));
    TLDISP(cosh(si));
    TLDISP(tanh(si));

    TLDISP(asinh(si));
    TLDISP(acosh(si));
    TLDISP(atanh(si));


    CR();
    MOUT << blue.apply("Complex Scalar") << endl;
    Scalar<ComplexDouble> sc{ComplexDouble(0.25, 0.5)};
    TLDISP(sc);
    TLDISP(-sc);
    TLDISP(conj(sc));
    TLDISP(real(sc));
    TLDISP(imag(sc));
    TLDISP(abs(sc));
    TLDISP(arg(sc));
    TLDISP(proj(sc));

    TLDISP(exp(sc));
    TLDISP(log(sc));
    TLDISP(log10(sc));
    TLDISP(sqrt(sc));

    TLDISP(sin(sc));
    TLDISP(cos(sc));
    TLDISP(tan(sc));

    TLDISP(asin(sc));
    TLDISP(acos(sc));
    TLDISP(atan(sc));

    TLDISP(sinh(sc));
    TLDISP(cosh(sc));
    TLDISP(tanh(sc));

    TLDISP(asinh(sc));
    TLDISP(acosh(sc));
    TLDISP(atanh(sc));

    CR();
    CR();
    // typename Realify<Scalar<double>>::Type qr;
    // TLDISP(qr);

    // typename Realify<Scalar<Imaginary<double>> >::Type qi;
    // TLDISP(qi);

    // typename Realify<Scalar<std::complex<double>> >::Type qc;
    // TLDISP(qc);
  }


  CR();
  CR();
  MOUT << bold.apply("Vector") << endl;
  {
    CR();
    MOUT << bold.apply("Vector") << " - " << blue.apply("Real Scalar") << endl;
    CR();
    Vector<double> vr{1.1, 2.2};
    TLDISP(vr);
    TLDISP(-vr);
    TLDISP(conj(vr));
    TLDISP(real(vr));
    TLDISP(imag(vr));
    TLDISP(abs(vr));
    TLDISP(arg(vr));
    TLDISP(proj(vr));

    TLDISP(exp(vr));
    TLDISP(log(vr));
    TLDISP(log10(vr));
    TLDISP(sqrt(vr));

    TLDISP(sin(vr));
    TLDISP(cos(vr));
    TLDISP(tan(vr));

    TLDISP(asin(vr));
    TLDISP(acos(vr));
    TLDISP(atan(vr));

    TLDISP(sinh(vr));
    TLDISP(cosh(vr));
    TLDISP(tanh(vr));

    TLDISP(asinh(vr));
    TLDISP(acosh(vr));
    TLDISP(atanh(vr));
  }

  CR();
  CR();
  MOUT << bold.apply("Matrix") << endl;
  {
    CR();
    MOUT << bold.apply("Matrix") << " - " << blue.apply("Real Scalar") << endl;
    Matrix<double> mr{{1, 2}, {3, 4}};
    TLDISP(mr);
    TLDISP(-mr);
    TLDISP(conj(mr));
    TLDISP(real(mr));
    TLDISP(imag(mr));
    TLDISP(abs(mr));
    TLDISP(arg(mr));
    TLDISP(proj(mr));

    TLDISP(exp(mr));
    TLDISP(log(mr));
    TLDISP(log10(mr));
    TLDISP(sqrt(mr));

    TLDISP(sin(mr));
    TLDISP(cos(mr));
    TLDISP(tan(mr));

    TLDISP(asin(mr));
    TLDISP(acos(mr));
    TLDISP(atan(mr));

    TLDISP(sinh(mr));
    TLDISP(cosh(mr));
    TLDISP(tanh(mr));

    TLDISP(asinh(mr));
    TLDISP(acosh(mr));
    TLDISP(atanh(mr));
  }


  CR();
  CR();
  MOUT << bold.apply("Tensor") << endl;
  {
    CR();
    MOUT << bold.apply("Tensor") << " - " << blue.apply("Real Scalar") << endl;
    CR();
    Tensor<double, 3> tr{
        {{0, 1, 2, 3, 4}, {10, 11, 12, 13, 14}},
        {{100, 101, 102, 103, 104}, {110, 111, 112, 113, 114}},
        {{200, 201, 202, 203, 204}, {210, 211, 212, 213, 214}}};

    TLDISP(tr);
    TLDISP(-tr);
    TLDISP(conj(tr));
    TLDISP(real(tr));
    TLDISP(imag(tr));
    TLDISP(abs(tr));
    TLDISP(arg(tr));
    TLDISP(proj(tr));

    TLDISP(exp(tr));
    TLDISP(log(tr));
    TLDISP(log10(tr));
    TLDISP(sqrt(tr));

    TLDISP(sin(tr));
    TLDISP(cos(tr));
    TLDISP(tan(tr));
  }



  CR();
  CR();
  CR();
  CR();


  MOUT << blue.apply("Two-level tests") << endl;

  // // -------------------------------------------------
  // // two level tests
  // // -------------------------------------------------

  CR();
  CR();
  MOUT << bold.apply("Two-Level Scalar tests") << endl;

  CR();
  CR();
  MOUT << bold.apply("Scalar") << endl;
  {
    CR();

    CR();
    MOUT << blue.apply("Boolean Scalar") << endl;
    Scalar<Scalar<bool>> sb = true;
    TLDISP(sb);
    TLDISP(!sb);

    CR();
    MOUT << blue.apply("Real Scalar Scalar") << endl;
    Scalar<Scalar<double>> sr = {{1.1}};
    TLDISP(sr);
    TLDISP(-sr);
    TLDISP(sin(sr));
    TLDISP(exp(sr));
    TLDISP(conj(sr));


    CR();
    MOUT << blue.apply("Imaginary Scalar Scalar") << endl;
    Scalar<Scalar<Imaginary<double>>> si;
    si()() = Imaginary<double>(3);
    TLDISP(si);
    TLDISP(-si);
    TLDISP(conj(si));
    TLDISP(real(si));
    TLDISP(imag(si));
    TLDISP(sin(si));
    TLDISP(exp(si));

    CR();
    MOUT << blue.apply("Complex Scalar") << endl;
    Scalar<Scalar<ComplexDouble>> sc{{ComplexDouble(1, 2)}};
    TLDISP(sc);
    TLDISP(-sc);
    TLDISP(conj(sc));
    TLDISP(real(sc));
    TLDISP(imag(sc));
    TLDISP(sin(sc));
    TLDISP(exp(sc));

    CR();
    CR();

    // typename Realify<Scalar<Scalar<double>>>::Type qr;
    // TLDISP(qr);

    // typename Realify<Scalar<Scalar<Imaginary<double>>>>::Type qi;
    // TLDISP(qi);

    // typename Realify<Scalar<Scalar<std::complex<double>>>>::Type qc;
    // TLDISP(qc);
  }


  {
    CR();
    Scalar<Scalar<double>> s{{1.1}};
    TLDISP(s);
    TLDISP(sin(s));
    TLDISP(exp(s));
  }
  {
    CR();
    Scalar<Vector<double>> s{{1., 2., 3.}};
    TLDISP(s);
    TLDISP(sin(s));
    TLDISP(exp(s));
  }
  {
    CR();
    Scalar<Matrix<double>> s{{{1, 2}, {3, 4}}};
    TLDISP(s);
    TLDISP(sin(s));
    TLDISP(exp(s));
  }

  {
    CR();
    Scalar<Tensor<double, 2>> s{{{1, 2}, {3, 4}}};
    TLDISP(s);
    TLDISP(sin(s));
    TLDISP(exp(s));
  }

  CR();
  CR();
  MOUT << bold.apply("Two-Level Vector tests") << endl;
  {
    CR();
    Vector<Scalar<double>> v{{1.}, {2.}};
    TLDISP(v);
    TLDISP(sin(v));
    TLDISP(exp(v));
  }

  {
    CR();
    Vector<Vector<double>> v{{1., 2., 3.}, {4., 5., 6.}};
    TLDISP(v);
    TLDISP(sin(v));
    TLDISP(exp(v));
  }
  {
    CR();
    Vector<Matrix<double>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    TLDISP(v);
    TLDISP(sin(v));
    TLDISP(exp(v));
  }
  {
    CR();
    Vector<Tensor<double, 2>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    TLDISP(v);
    TLDISP(sin(v));
    TLDISP(exp(v));
  }


  CR();
  CR();
  MOUT << bold.apply("Two-Level Matrix tests") << endl;
  {
    CR();
    Matrix<Scalar<double>> m{{{1}, {2}}, {{3}, {4}}};
    ;
    TLDISP(m);
    TLDISP(sin(m));
    TLDISP(exp(m));
  }

  {
    CR();
    Matrix<Vector<double>> m{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    TLDISP(m);
    TLDISP(sin(m));
    TLDISP(exp(m));
  }

  {
    CR();
    Matrix<Matrix<double>> m{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    TLDISP(m);
    TLDISP(sin(m));
    TLDISP(exp(m));
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
    TLDISP(sin(m));
    TLDISP(exp(m));
  }

  // /////////////////////////////////////////////////////////////////



  // CR();
  // CR();
  // MOUT << bold.apply("Two-Level Tensor tests") << endl;
  // {
  //   CR();
  //   Tensor<Scalar<double>,2> t {{{1},{2}},{{3},{4}}};
  //   TLDISP(t);
  //   TLDISP(sin(t));
  //   TLDISP(beta(t));
  //   TLDISP(exp(t));
  //   TLDISP(cyl_bessel_j(t));
  // }
  // {
  //   CR();
  //   Tensor<Vector<double>,2> t {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
  //   TLDISP(t);
  //   TLDISP(sin(t));
  //   TLDISP(beta(t));
  //   TLDISP(exp(t));
  //   TLDISP(cyl_bessel_j(t));
  // }

  // {
  //   CR();
  //   Tensor<Matrix<double,2,2>,2> t  {
  //     { {{1,2},{3,4}}, {{5,6},{7,8}} },
  // 	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
  //   };
  //   TLDISP(t);
  //   TLDISP(sin(t));
  //   TLDISP(beta(t));
  //   TLDISP(exp(t));
  //   TLDISP(cyl_bessel_j(t));
  // }


  // {
  //   CR();
  //   Tensor<Tensor<double,3>,2> t { {
  // 	{
  // 	  {
  // 	    {0, 1},
  // 	      {10, 11},
  // 		{20, 21}
  // 	  },
  // 	    {
  // 	      {100, 101},
  // 		{110, 111},
  // 		  {120, 121}
  // 	    }
  // 	},
  // 	  {
  // 	    {
  // 	      {1000, 1001},
  // 		{1010, 1011},
  // 		  {1020, 1021}
  // 	    },
  // 	      {
  // 		{1100, 1101},
  // 		  {1110, 1111},
  // 		    {1120, 1121}
  // 	      }
  // 	  }}, {
  // 	{
  // 	  {
  // 	    {10000, 10001},
  // 	      {10010, 10011},
  // 		{10020, 10021}
  // 	  },
  // 	    {
  // 	      {10100, 10101},
  // 		{10110, 10111},
  // 		  {10120, 10121}
  // 	    }
  // 	},
  // 	  {
  // 	    {
  // 	      {11000, 11001},
  // 		{11010, 11011},
  // 		  {11020, 11021}
  // 	    },
  // 	      {
  // 		{11100, 11101},
  // 		  {11110, 11111},
  // 		    {11120, 11121}
  // 	      }
  // 	  }} };

  //   TLDISP(t);
  //   TLDISP(sin(t));
  //   TLDISP(beta(t));
  //   TLDISP(exp(t));
  //   TLDISP(cyl_bessel_j(t));

  // }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
