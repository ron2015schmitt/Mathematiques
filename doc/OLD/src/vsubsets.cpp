


#include "mathq.h"

#include <iostream>
#include <string>
#include <algorithm>

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
  GMD_TITLE("Access subsets of Vector elements");
  mathq_preamble();

  OUTPUT("You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices");

  
  GMD_HEADER2("Access vector elements using a `Vector` of indices");

  GMD_HEADER3("Element access `Vector[Vector]`");
  CR();
  OUTPUT("* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!");
  OUTPUT("* The index Vector _can have repeated indices and indices can be in any order_!");
  {
    CR();
    CR();
    EXAMPLE(Nex++,"Access via a Vector of indices");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v( linspace<double>(0,1,11) ) );
    ECHO_CODE( Vector<index_type> veven( range<index_type>(0,10,2) ) );
    ECHO_CODE( Vector<index_type> vodd( range<index_type>(1,10,2) ) );
    ECHO_CODE( Vector<index_type> vconst(15,1 ) );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti( v );
    resultmulti( veven );
    resultmulti( v[veven] );
    resultmulti( v[veven[1]] );
    resultmulti( vodd );
    resultmulti( v[vodd] );
    resultmulti( v[vodd[1]]);
    resultmulti( v[veven,vodd] );
    resultmulti( v[vodd[veven[1]]]);
    resultmulti( vconst );
    resultmulti( v[vconst] );
    resultend();
  }



  GMD_HEADER2("Access vector elements using an C++11 `initializer_list` of indices");
  GMD_HEADER3("Element access `Vector[initializer_list]`");

  CR();
  OUTPUT("* The list can be smaller than or greater than or equal to the length to the data Vector.");
  OUTPUT("* The list can have repeated indices and indices can be in any order!");
  {
    CR();
    CR();
    EXAMPLE(Nex++,"Access via a C++11 initializer_list");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v( linspace<double>(0,1,11) ) );
    DISP(v);
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti( v[{0,4}] );
    resultmulti( v[{4,0,1,4}] );
    resultmulti( v[{1,0,2}] );
    resultmulti( v[{4,3,2,1,0}] );
    resultmulti( v[{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}] );
    resultend();
  }


  mathq_toc();


  return 0;
}
