#include "mathq.h"



int main(int argc, char *argv[])
{
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;

  

  Vector<double> v1 = {1,2,3,4};
  TRDISP(v1);


  // now that Vectors are type aliases these are the same type

  cout << "construct MultiArray from Vector" << endl;
  auto ma = MultiArray<double,1,4>(v1);
  TRDISP(ma);

  cout << "cast Vector to MultiArray" << endl;
  auto ma3 = static_cast<MultiArray<double,1>>(v1);
  TRDISP(ma3);


  //------------------------------------------------------
  
  cout << std::endl;
  cout << "done: " << myname << std::endl;
  cout << std::endl;
  cout << std::endl;

  
  return 0;
}
