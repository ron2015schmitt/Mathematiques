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


  CurvilinearCoords<NullType, double, 2> tcoords;
  TRDISP(NumberTrait< CurvilinearCoords<NullType, double, 2> >::depth());
  TRDISP(SimpleNumberTrait< CurvilinearCoords<NullType, double, 2> >::depth());

  ECHO_CODE(MultiArrayType<CurvilinearCoords<NullType, double, 2>> mystery);
  TRDISP(mystery);


  return 0;
}
