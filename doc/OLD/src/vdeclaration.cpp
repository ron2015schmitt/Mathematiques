
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
  GMD_TITLE("Vector declaration");
  mathq_preamble();

 
  {
    EXAMPLE(Nex++, "Declare vector `v` (initialize to zeros).");
    GMD_CODE_START("C++");
    ECHO_CODE( const size_type N = 4 );
    ECHO_CODE( Vector<double> v(N) );
    GMD_CODE_END();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v` and initialize to a constant" );
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v(4, -1 ) );
    GMD_CODE_END();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v` and initialize to a **C-style array** of values" );
    CR();
    OUTPUT("In debug mode, this produces a warning, as shown below");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v( 4, (const double[]) {10, 20, 30, 40} )  );
    GMD_CODE_END();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v` and initialize directly from a list (**__C++11__**)" );
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v({10, 20, 30, 40})  );
    GMD_CODE_END();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v2` and initialize to values of `v1`" );
    OUTPUT("* Note that this is a _copy_ constructor.");
    OUTPUT("* In fact _all_ of the `Vector` constructors are _copy_ constructors.");
    GMD_CODE_START("C++");
    codemultiNoteC11Array( Vector<double> v1( {10,11,12,13} ) );
    ECHO_CODE( Vector<double> v2(v1) );
    ECHO_CODE( v1[0] = -1 );
    ECHO_CODE( v2[0] = -2 );
    GMD_CODE_END();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }

  {
    EXAMPLE(Nex++, "Declare `v2` and initialize to an expression" );
    OUTPUT("* The expression is computed without creating any intermediate objects.");  
    GMD_CODE_START("C++");
    codemultiNoteC11Array( Vector<double> v1({10,11,12,13} ) );
    ECHO_CODE( Vector<double> v2(10*v1+1) );
    GMD_CODE_END();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }


  mathq_toc();
  
  return 0;
}
