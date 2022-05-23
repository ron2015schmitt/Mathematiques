

 
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
  GMD_TITLE("Vector join operator `(v1,v2)` and `rep` function");
  mathq_preamble();

  
  GMD_HEADER3("Vector join operator `,` ");
  OUTPUT("* The Vector operator `,` joins two vectors");
  OUTPUT("* This is an expression.  It does not create intermediate objects.");
  OUTPUT("* join can be used on the left hand side as well!");
 
  {
    CR();
    CR();
    EXAMPLE(Nex++,"Vector join operator `,`");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v1( range<double>(0,2) ) );
    ECHO_CODE( Vector<double> v2( range<double>(3,4) ) );
    GMD_CODE_END();
    CR();

    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti( (v1,v2) );
    resultmulti( (v1,v2,v1) );
    resultmulti( (v1,v2,v1,v2) );
    resultmulti( (10*v1,v2)  );
    resultmulti( (v1,10*v2)  );
    resultmulti( (10*v1,10*v2)  );
    resultend();

    CR();
    OUTPUT("The following are examples usign the join operator on the left hand side");
    CR();
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> va(2) );
    ECHO_CODE( Vector<double> vb(3) );
    ECHO_CODE( (va,vb) = range<double>(1,5) );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(va);
    resultmulti(vb);
    resultend();

    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> ua(2) );
    ECHO_CODE( Vector<double> ub(3) );
    ECHO_CODE( (ua[{1,0}],ub) = range<double>(1,5) );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(ua);
    resultmulti(ub);
    resultend();

    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> wa(2) );
    ECHO_CODE( Vector<double> wb(3) );
    ECHO_CODE( (wa,wb[{2,1,0}]) = range<double>(1,5) );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(wa);
    resultmulti(wb);
    resultend();

    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> za(2) );
    ECHO_CODE( Vector<double> zb(3) );
    ECHO_CODE( (za[{1,0}],zb[{2,1,0}]) = range<double>(1,5) );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(za);
    resultmulti(zb);
    resultend();
  }    
    

  GMD_HEADER3("Vector `rep` function");
  OUTPUT("* The Vector `rep(v,m)` function replicates the input vector `m` times.");
  OUTPUT("* `rep` cannot be used on the left hand side of assignment, since it doesn't provide utility to do so.");
  OUTPUT("* The Vector `rep(v,m)` function can be combined with the join operator.");

  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"Vector `rep` function");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> v1( range<double>(1,3) ) );
    ECHO_CODE( Vector<double> v2( range<double>(4,5) ) );
    ECHO_CODE( Vector<double> v3 );
    ECHO_CODE( v3 = rep(v1,3) );
    ECHO_CODE( Vector<double> v4 );
    ECHO_CODE( v4 = (rep(v1,2), rep(v2,3)) );
    ECHO_CODE( Vector<double> v5 );
    ECHO_CODE( v5 = rep((v1,v2),2) );
    GMD_CODE_END();
    CR();

   
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultmulti(v4);
    resultmulti(v5);
    resultend();
  }

  CR();
  CR();
  
  mathq_toc();


  return 0;
}
