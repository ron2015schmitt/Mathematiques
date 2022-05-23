
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


  MOUT << bold.apply("join") << endl;
  CR();

  {
    Vector<int> Vi{11, 12, -100};
    Vector<double> Vd1{1, 2};
    Vector<double> Vd2{3, 4, 5};
    Vector<double> Vd3{6, 7, 8, 9};
    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    TLDISP(Vi);
    MOUT << "  ";
    TLDISP(Vd1);
    MOUT << "  ";
    TLDISP(Vd2);
    MOUT << "  ";
    TLDISP(Vd3);
    CR();

    MOUT << blue.apply("LHS tests--join") << endl;
    MOUT << "  ";
    TLDISP(join(Vd1, Vd1));
    MOUT << "  ";
    TLDISP(join(Vd1, Vd2));
    MOUT << blue.apply("LHS tests--comma") << endl;
    MOUT << "  ";
    TLDISP((Vd1, Vd2));
    MOUT << "  ";
    TLDISP((Vd1, Vd2, Vd3));
    MOUT << "  ";
    TLDISP(join((Vd1, Vd2), Vd3));


    MOUT << blue.apply("LHS tests") << endl;
    Vector<double> Vd4 = {11, 12, 13, 14, 15};
    Vector<double> Vd5 = {21, 22, 23, 24, 25, 26, 27, 28, 29};
    MOUT << "Initial values: " << endl;
    MOUT << " ";
    MDISP(Vd1, Vd2, Vd3);
    MOUT << blue.apply("(Vd1,Vd2) = Vd4") << endl;
    (Vd1, Vd2) = Vd4;
    MOUT << " ";
    DISP(Vd4);
    MOUT << " ";
    MDISP(Vd1, Vd2);
    MOUT << blue.apply("(Vd1,Vd2,Vd3) = Vd5") << endl;
    (Vd1, Vd2, Vd3) = Vd5;
    MOUT << " ";
    DISP(Vd5);
    MOUT << " ";
    MDISP(Vd1, Vd2, Vd3);

    TLDISP(IsTensorRW<mathq::TER_Join<mathq::TensorR<mathq::TensorRW<mathq::TERW_Subset<double>, double, double, 1, 1>, double, double, 1, 1>, mathq::TensorR<mathq::TensorRW<mathq::Vector<double>, double, double, 1, 1>, double, double, 1, 1>, double, double, 1>>::value);

    TLDISP(IsTensorRW<mathq::TensorR<mathq::TensorRW<mathq::TERW_Subset<double>, double, double, 1, 1>, double, double, 1, 1>>::value);

    TLDISP(IsTensorRW<mathq::TERW_Join<mathq::TensorRW<mathq::Vector<double>, double, double, 1, 1>, mathq::TensorRW<mathq::Vector<double>, double, double, 1, 1>, double, double, 1>>::value);
  }



  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
