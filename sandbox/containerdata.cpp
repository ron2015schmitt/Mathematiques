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
  TRDISP(v1.dataobj());
  TRDISP(v1.data());

  Vector<double,4> v2 = {1,2,3,4};
  TRDISP(v2);
  TRDISP(v2.dataobj());
  TRDISP(v2.data());


  //------------------------------------------------------
  
  cout << std::endl;
  cout << "done: " << myname << std::endl;
  cout << std::endl;
  cout << std::endl;

  
  return 0;
}
