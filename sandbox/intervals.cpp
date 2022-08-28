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

  Style mystyle1 = CREATESTYLE(BOLD + BLUE);

  {
    title("Interval - real uniform");
    ECHO_CODE(Interval<double> dom1 = Interval<double>::interval(0, 10, 11));
    TRDISP(dom1);
    TRDISP(dom1.grid());
    ECHO_CODE(Domain<double>&dom2 = dom1);
    TRDISP(dom2.grid());
  }

  {
    title("PointSequence");
    ECHO_CODE(PointSequence<double> dom1 = PointSequence<double>({ 0,1,3,4.5,5 }));
    TRDISP(dom1);
    TRDISP(dom1.grid());
    ECHO_CODE(Domain<double>&dom2 = dom1);
    TRDISP(dom2.grid());
  }


  {

    title("2D CartesianCoords from Intervals");
    ECHO_CODE(CartesianCoords<double, 2, false> coords({
        Interval<double>::interval(-1,1,3),
        Interval<double>::interval(2,3,3),
      }));

    TRDISP(coords);
    TRDISP(coords.grid_dims());
    TRDISP(coords[0]);
    TRDISP(coords[1]);
  }


  // {

  //   title("2D CartesianCoords from PointeSequence and Interval");
  //   ECHO_CODE(CartesianCoords<double, 2, false> coords({
  //       Interval<double>::interval(-1,1,3),
  //        PointSequence<double>({ 0,1,3,10 }),
  //     }));

  //   TRDISP(coords);
  //   TRDISP(coords.grid_dims());
  //   TRDISP(coords[0]);
  //   TRDISP(coords[1]);


  // }

  return 0;
}
