#include <fstream>

#define MATHQ_DEBUG 0
#include "mathq.h"

using namespace mathq;


//  int Nindices = 0;
//  for(int i=0; i<ddims.size(); i++) {
//    Nindices += ddims[i].rank();
//  }


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
  MOUT << blue.apply("4- deep tests") << endl;

  {
    CR();
    MOUT << bold.apply("Scalar<Vector<Matrix<Tensor<double,3>,3,2>,4>>") << endl;
    Scalar<Vector<Matrix<Tensor<double, 3>, 3, 2>, 4>> x;
    TLDISP(x);
    TLDISP(x.dims());
    TLDISP(x.size());
    TLDISP(x.deepdims());
    Dimensions tdims(2, 1, 2);

    for (int h = 0; h < x().size(); h++) {
      const index_type NR = x()(h).Nrows();
      const index_type NC = x()(h).Ncols();
      for (int i = 0; i < NR; i++) {
        for (int j = 0; j < NC; j++) {
          x()(h)(i, j).resize(tdims);
          for (int k = 0; k < tdims[0]; k++) {
            for (int l = 0; l < tdims[1]; l++) {
              for (int m = 0; m < tdims[2]; m++) {
                x()(h)(i, j)(k, l, m) = double(100000 * h) + double(10000 * i) + double(1000 * j) + double(100 * k) + double(10 * l) + double(m);
              }
            }
          }
        }
      }
    }
    TLDISP(x);
    TLDISP(x.dims());
    TLDISP(x.size());
    TLDISP(x.deepdims());
  }

  {
    CR();
    CR();

    MOUT << "set via initializer_list" << endl;
    Scalar<Vector<Matrix<Tensor<double, 3>, 3, 2>, 4>> x{{{{{{{0, 1}},
                                                             {{100, 101}}},
                                                            {{{1000, 1001}},
                                                             {{1100, 1101}}}},
                                                           {{{{10000, 10001}},
                                                             {{10100, 10101}}},
                                                            {{{11000, 11001}},
                                                             {{11100, 11101}}}},
                                                           {{{{20000, 20001}},
                                                             {{20100, 20101}}},
                                                            {{{21000, 21001}},
                                                             {{21100, 21101}}}}},
                                                          {{{{{100000, 100001}},
                                                             {{100100, 100101}}},
                                                            {{{101000, 101001}},
                                                             {{101100, 101101}}}},
                                                           {{{{110000, 110001}},
                                                             {{110100, 110101}}},
                                                            {{{111000, 111001}},
                                                             {{111100, 111101}}}},
                                                           {{{{120000, 120001}},
                                                             {{120100, 120101}}},
                                                            {{{121000, 121001}},
                                                             {{121100, 121101}}}}},
                                                          {{{{{200000, 200001}},
                                                             {{200100, 200101}}},
                                                            {{{201000, 201001}},
                                                             {{201100, 201101}}}},
                                                           {{{{210000, 210001}},
                                                             {{210100, 210101}}},
                                                            {{{211000, 211001}},
                                                             {{211100, 211101}}}},
                                                           {{{{220000, 220001}},
                                                             {{220100, 220101}}},
                                                            {{{221000, 221001}},
                                                             {{221100, 221101}}}}},
                                                          {{{{{300000, 300001}},
                                                             {{300100, 300101}}},
                                                            {{{301000, 301001}},
                                                             {{301100, 301101}}}},
                                                           {{{{310000, 310001}},
                                                             {{310100, 310101}}},
                                                            {{{311000, 311001}},
                                                             {{311100, 311101}}}},
                                                           {{{{320000, 320001}},
                                                             {{320100, 320101}}},
                                                            {{{321000, 321001}},
                                                             {{321100, 321101}}}}}}};

    TLDISP(x);
    TLDISP(x.dims());
    TLDISP(x.size());
    TLDISP(x.deepdims());


    Vector<Matrix<Tensor<double, 3>, 3, 2>, 4> v;
    v = x();
    TLDISP(v);

    Matrix<Tensor<double, 3>, 3, 2> m;
    m = x()(1);
    TLDISP(m);

    Tensor<double, 3> t;
    t = x()(1)(2, 1);
    TLDISP(t);
    TLDISP(t.dims());
    TLDISP(t(1, 0, 0));

    TLDISP(x()(1)(2, 1)(1, 0, 0));

    Indices inds({1, 2, 1, 1, 0, 0});
    TLDISP(inds);
    double y = x.dat(inds);
    TLDISP(y);

    Vector<Scalar<double>, 4> g1;
    TLDISP(g1);
    Matrix<Vector<Scalar<double>, 4>, 3, 2> g2;
    TLDISP(g2);
    TLDISP(x.deepdims());


    Tensor<Matrix<Vector<Scalar<double>, 4>, 3, 2>, 3> g3;
    TLDISP(g3);
    g3 = insideout(x);
    TLDISP(g3.deepdims());
    //   TLDISP(g3);

    for (int h = 0; h < x().size(); h++) {
      const index_type NR = x()(h).Nrows();
      const index_type NC = x()(h).Ncols();
      for (int i = 0; i < NR; i++) {
        for (int j = 0; j < NC; j++) {
          Dimensions tdims = x()(h)(i, j).dims();
          for (int k = 0; k < tdims[0]; k++) {
            for (int l = 0; l < tdims[1]; l++) {
              for (int m = 0; m < tdims[2]; m++) {
                // MDISP(h,i,j,k,l,m, x()(h)(i,j)(k,l,m) );
                MDISP(h, i, j, k, l, m, x()(h)(i, j)(k, l, m), g3(k, l, m)(i, j)(h)());
              }
            }
          }
        }
      }
    }
  }


  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
