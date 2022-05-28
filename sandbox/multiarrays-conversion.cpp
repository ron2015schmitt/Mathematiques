#include <iostream>
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


  cout << "construct MultiArray from Vector" << endl;
  auto ma = MultiArray<double,1>(v1);
  TRDISP(ma);
  auto ma2 = MultiArray<double>(v1);
  TRDISP(ma2);

  cout << "cast Vector to MultiArray" << endl;
  auto ma3 = static_cast<MultiArray<double,1>>(v1);
  TRDISP(ma3);
  auto ma4 = static_cast<MultiArray<double>>(v1);
  TRDISP(ma4);


  //------------------------------------------------------
  
  cout << std::endl;
  cout << "done: " << myname << std::endl;
  cout << std::endl;
  cout << std::endl;

  
  return 0;
}
