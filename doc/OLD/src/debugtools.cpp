
// flag for run-time bounds and size checking



#include "mathq.h"

#include <iostream>



int main()
{
  using namespace mathq;
  
  using namespace std;

  CR();
  printcr("When running in DEBUG mode, all Vector and Matrix objects are assigned");
  printcr("a unique name and ID#. The name and ID can be accessed using the");
  printcr("name() and objectID() member functions respectively.");

  printcrcr("Here is an example");
  Vector<double> x(5);
  x=linspace<double>(100,500,5);
  print("\t");
  DISP(x.name());
  print("\t");
  DISP(x.objectID());


  printcrcr("The run-time name is used in all mathq errors and warnings.");
  printcr("Run-time names are only available when the library is run in DEBUG mode.");

  printcrcr("Here is an example of an error\n x[8] =11.0;");
  x[8] = 11.0;
  

  printcrcr("To make debugging easier, you can specify a name explicitly during instantiation");
  printcrcr("Here is an example");
  Vector<double> y(3,"y");
  "{31,32,33}">>y;
  print("\t");
  DISP(y.name());
  print("\t");
  DISP(y.objectID());


  printcrcr("You can also change the name at any time");
  printcrcr("Here is an example");
  y.name("joe");
  print("\t");
  DISP(y.name());
  print("\t");
  DISP(y.objectID());

  printcrcr("You can query a vector's size");
  DISP(x.size());

  printcrcr("You can display the classname of any mathq object (container name only)");
  DISP(x.classname());

  printcrcr("You can display the full classname of any mathq object");
  DISP(x.fullclassname());

  printcrcr("You can display the datatype contained in any mathq object");
  DISP(x.datatype());

  printcrcr("You can also display a summary of information about any mathq object");
  mathqinfo(x);

  Matrix<double> A(2,3,"me");
  CR();
  mathqinfo(A);



  return 0;
}
