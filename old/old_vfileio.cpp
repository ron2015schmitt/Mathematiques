#define MATHQ_DEBUG 1


#include "mathq.h"
using namespace mathq;

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{

  int Nex = 1;
  
  CR();
  GMD_TITLE("Vector file i/o");
  mathq_preamble();


// // the load and save functions use the standard C++ file streams
  // // and are provided as a convenience

  // Vector<double> v1(5,"vec1");
  // Vector<double> v2("vec2");

  // DISP(v2);

  // "{1,2,3,4,5}" >> v1;
  // DISP(v1);

  // // save a vector to a file in default "braces" format
  // save(v1,"v1.temp");

  // // load a vector from a file in "braces" format
  // // ** NOTE THAT THE DESTINATION VECTOR IS CLEARED AND RESIZED TO MATCH
  // // ** THE DATA IN The FILE
  // load(v2,"v1.temp");

  // DISP(v2);


  // "{1.1,1.2,1.3,1.4,1.5}" >> v1;
  // DISP(v1);


  // // save a vector to a file in default "no braces" format
  // v1.textformat(text_nobraces);
  // save(v1,"v1b.temp");

  // // load a vector from a file in "no braces" format
  // v2.clear();
  // DISP(v2);
  // v2.textformat(text_nobraces);
  // load(v2,"v1b.temp");

  // DISP(v2);


  mathq_toc();

  return 0;
}
