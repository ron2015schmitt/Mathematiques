
// flag for run-time bounds and size checking



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
  GMD_TITLE("under the hood—`Vector` definition");
  mathq_preamble();
  OUTPUT("* _This information is mostly irrelavent to usage but is provided for rare cases when you may want to access the underlying data type_.");

  GMD_HEADER3("The Vector class is a wrapper");
  OUTPUT("* The `mathq::Vector` wraps a `std::valarray`");
  OUTPUT("* In the example below");
  OUTPUT("  * `valias` is referenced to the valarray inside `vec`.");

  {
    CR();
    EXAMPLE(Nex++, "Getting the `valarray` wrapped by a `Vector`.");
    CR();
    GMD_CODE_START("C++");
    ECHO_CODE(using namespace std);
    codemultiNoteC11Array( Vector<double> vec({0,1,2,3}) );
    ECHO_CODE( valarray<double>& valias = vec.getValArray() );
    ECHO_CODE( vec[1] = -1 );
    ECHO_CODE( valias[2] = -2 );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(vec);
    resultmulti(valias);
    resultend();

  }


  GMD_HEADER3("Getting the wrapped `valarray`/`array`");
  OUTPUT("* In the example below");
  OUTPUT("  * `vec` is constructed");
  OUTPUT("  * `valias` is referenced to the valarray inside `vec`.");

  {
    CR();
    EXAMPLE(Nex++, "Setting and getting the wrapped `valarray`");
    CR();
    GMD_CODE_START("C++");
    ECHO_CODE(using namespace std);
    ECHO_CODE( Vector<double> vec(2) );
    ECHO_CODE( valarray<double>& valias = vec.getValArray() );
    ECHO_CODE( vec[1] = 1 );
    ECHO_CODE( valias[2] = 2 );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(vec);
    resultmulti(valias);
    resultend();

  }


  
  mathq_toc();
  
  return 0;
}
