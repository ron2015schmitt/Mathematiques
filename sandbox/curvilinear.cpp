#include "mathq.h"


namespace mathq {


};


int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;



  Domain<double> dom1 = Domain<double>::interval_CC(0, 10, 11);
  TRDISP(dom1);
  TRDISP(dom1.getGrid());

  CurvilinearCoords<double, 2, NullType> tcoords;
  TRDISP(tcoords[0]);
  TRDISP(tcoords[1]);

  // CartesianCoords<double, 2> cart_coords2a;
  // TRDISP(cart_coords2a);

  // CartesianCoords<double, 2> cart_coords2b(
  //   {
  //     Domain<double>::interval_CC(-1,1,10),
  //     Domain<double>::interval_CC(0,1,5),
  //   });
  // TRDISP(cart_coords2b);


  return 0;
}
