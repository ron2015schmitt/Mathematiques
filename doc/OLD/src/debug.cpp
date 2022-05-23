


#include "mathq.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>



int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  int Nex = 1;
  
  mathq_toc();
  CR();CR();
  GMD_TITLE("Debugging");
  mathq_preamble();



  OUTPUT("The Mathématiques library provides extensive debugging operation, turned on using the flag `MATHQ_DEBUG`");

  OUTPUT("In this mode extensive error checking is performed to notify the programmer of");

  OUTPUT(" - out of bounds access for vectors or matrices (e.g. x[10] where x has size less than 9");
  OUTPUT(" - adding/subtracting/multiplying/dividing vector or matrices of unequal size");
  OUTPUT(" - invalid dot products of vector and/or matrices ");
  OUTPUT(" - other assorted errors and warnings");


  GMD_HEADER2("SETTING `MATHQ_DEBUG` MODE");

  OUTPUT("There are two methods to accomplish this.");

  OUTPUT("1. Use the provided sample makefile and specify `MATHQ_DEBUG=1` on the command line");

  OUTPUT("```make clean MATHQ_DEBUG=1 myprogram```");

  OUTPUT("The target `clean` is not needed, but is a recomended practice.");


  OUTPUT("1. Add a `` statement BEFORE each `mathq.h` include statement");


  GMD_CODE_START("C++");

  OUTPUT("");
  OUTPUT("#include \"mathq.h\"");
  GMD_CODE_END();

  GMD_HEADER2("DEBUG LEVELS");

  OUTPUT(" to be written...");

  GMD_HEADER2("RECOMMENDATIONS");

  OUTPUT("* While developing your code, use `MATHQ_DEBUG` mode.  When you are convinced that it is operating without errors or warnings, run normally.");
  
  OUTPUT("* Compile a `MATHQ_DEBUG` and a quick version of your code, giving the executables different names. This way if a segmentation fault occurs, or you otherwise suspect an error, you can quickly check the problem under careful mode.");
  
  mathq_toc();
  
  return 0;
}
