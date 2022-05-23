


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
  GMD_TITLE("python-like access: negative indices & slices");
  mathq_preamble();

  GMD_HEADER2("Element access");

  GMD_HEADER3("Positive and negative indices");
  OUTPUT("Similar to python, Mathématiques allows negative indices");
  CR();
  OUTPUT("`v[-1] == v[N-1]` == end element\n");
  OUTPUT("`v[-2] == v[N-2]` == penultimate element\n");
  OUTPUT("`v[-N] == v[0]`   == first element\n");
  {
    CR();
    CR();
    EXAMPLE(Nex++,"Positive and negative indices");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v( range<double>(0,10) ) );
    ECHO_CODE( const int N = v.size() );
    GMD_CODE_END();
    CR();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti( N );
    resultmulti( v[0] );
    resultmulti( v[1] );
    resultmulti( v[N-1] );
    resultmulti( v[-1] );
    resultmulti( v[-2] );
    resultmulti( v[-N] );
    resultmulti( v[{0,-1}] );
    resultmulti( v[{2,2,-2,-2}] );
    resultend();
  }


  {
    CR();
    CR();
    EXAMPLE(Nex++,"Reverse a vector in place.");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v( range<double>(0,10) ) );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti( v );
    resultend();
    GMD_CODE_START("C++");
    ECHO_CODE( for (int i = 0; i < v.size()/2; i++) std::swap(v[i],v[-i-1]) );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti( v );
    resultend();
  }




  
  GMD_HEADER2("Slices via the `slc` function");

  GMD_HEADER3("The `(start,end)` slice");
  OUTPUT("* The form `v[slc(start,end)]` returns a `Vector` with every element from index=start to index=end, stepping by +1.\n");
  OUTPUT("* Negative indices are permitted.\n");
  OUTPUT("* Examples\n");
  OUTPUT("  * `v[slc(0,-1)]` returns the entire vector\n");
  OUTPUT("  * `v[slc(0,1)]` returns the first two elements\n");
  OUTPUT("  * `v[slc(-2,-1)]` returns the last two elements\n");
  OUTPUT("  *  if you can't count from the starting element to the ending element by +1, then an empty vector is returned.\n");
  {
    CR();
    CR();
    EXAMPLE(Nex++,"slice `v[slc(start,end)]`");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v( range<double>(0,10) ) );
    GMD_CODE_END();
    CR();

    resultstart2("");
    resultmulti( v[slc(2,6)]);
    resultmulti( v[slc(0,-1)]);
    resultmulti( v[slc(0,1)]);
    resultmulti( v[slc(-2,-1)]);
    resultmulti( v[slc(1,0)]);
    resultmulti( v[slc(-1,0)]);
    resultend();
  }


  GMD_HEADER3("The `(start,end,step)` slice");
  OUTPUT("* The form `v[slc(start,end,step)]` returns a `Vector` with every element from index=start to index=end, stepping by step.\n");
  OUTPUT("* Negative indices are permitted.\n");
  OUTPUT("* Examples\n");
  OUTPUT("  * `v[slc(-1,0,-1)]` returns the entire vector in reverse\n");
  OUTPUT("  * `v[slc(0,-1,2)]` returns the even-index elements\n");
  OUTPUT("  * `v[slc(1,-1,2)]` returns the odd-index elements\n");
  OUTPUT("  *  if you can't count from the starting element to the ending element by step, then an empty vector is returned.\n");
  {
    CR();
    CR();
    EXAMPLE(Nex++,"slice `v[slc(start,end,step)]`");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v0(0) );
    ECHO_CODE( Vector<double> v1(1,0. ));
    ECHO_CODE( Vector<double> v2( range<double>(0,1) ) );
    ECHO_CODE( Vector<double> v3( range<double>(0,2) ) );
    ECHO_CODE( Vector<double> v4( range<double>(0,3) ) );
    ECHO_CODE( Vector<double> v10( range<double>(0,10) ) );
    GMD_CODE_END();
    CR();
    
    resultstart2(": reverse vectors of various lengths using the same slice");
    resultmulti( v0[slc(-1,0,-1)]);
    resultmulti( v1[slc(-1,0,-1)]);
    resultmulti( v2[slc(-1,0,-1)]);
    resultmulti( v3[slc(-1,0,-1)]);
    resultmulti( v4[slc(-1,0,-1)]);
    resultmulti( v10[slc(-1,0,-1)]);
    resultend();

    resultstart2(": get even-index elements of various vectors using the same slice");
    resultmulti( v0[slc(0,-1,2)]);
    resultmulti( v1[slc(0,-1,2)]);
    resultmulti( v2[slc(0,-1,2)]);
    resultmulti( v3[slc(0,-1,2)]);
    resultmulti( v4[slc(0,-1,2)]);
    resultmulti( v10[slc(0,-1,2)]);
    resultend();

    resultstart2(": get odd-index elements of various vectors using the same slice");
    resultmulti( v0[slc(1,-1,2)]);
    resultmulti( v1[slc(1,-1,2)]);
    resultmulti( v2[slc(1,-1,2)]);
    resultmulti( v3[slc(1,-1,2)]);
    resultmulti( v4[slc(1,-1,2)]);
    resultmulti( v10[slc(1,-1,2)]);
    resultend();
  }

  mathq_toc();
  return 0;

}
