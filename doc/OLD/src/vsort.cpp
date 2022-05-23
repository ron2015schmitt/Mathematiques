


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
  
  CR();
  GMD_TITLE("Methods `Vector.sort()`, `Vector.uniq()`, `Vector.quniq()`  ");
  mathq_preamble();
  GMD_HEADER2("Sorting");
  OUTPUT("* sorting is performed _in place_ via the `.sort()` method");
  CR();
  OUTPUT("* the indices for the sort are returned in a `Vector<index_type>`");
  CR();
  
  {
    CR();
    CR();
    EXAMPLE(Nex++," `Vector.sort()`");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> t( {23,-1,100,7}) );
    ECHO_CODE( Vector<double> y( {30,10,20,40} ) );
    ECHO_CODE( Vector<index_type> vindex );
    ECHO_CODE( vindex = t.sort() );
    ECHO_CODE( y = y[vindex] );
    GMD_CODE_END();
    CR();

    resultstart();
    resultmulti(t);
    resultmulti(vindex);
    resultmulti(y);
    resultend();
  }

  GMD_HEADER2("Removing duplicate elements");
  GMD_HEADER3("The `.uniq()` method");
  OUTPUT("* The `.uniq()` method operates _in place_, removing all duplicate values.");
  CR();
  OUTPUT("* The indices for the unique elements are returned in a `Vector<index_type>`");
  CR();
  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"The `.uniq()` method");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> t( {23,-1,23,4,4,4,-1,3,3}) );
    ECHO_CODE( Vector<index_type> vindex );
    ECHO_CODE( vindex = t.uniq() );
    GMD_CODE_END();
    CR();

    resultstart();
    resultmulti(t);
    resultmulti(vindex);
    resultend();
  }

  GMD_HEADER3("The `.quniq()` method");
  OUTPUT("* The `.quniq()` method operates _in place_, removing all _adjacent_ duplicate values.");
  CR();
  OUTPUT("* The indices for the unique elements are returned in a `Vector<index_type>`");
  CR();
  
  {
    CR();
    CR();
    EXAMPLE(Nex++,"The `.quniq()` method");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> t( {23,-1,23,4,4,4,-1,3,3}) );
    ECHO_CODE( Vector<index_type> vindex );
    ECHO_CODE( vindex = t.quniq() );
    GMD_CODE_END();
    CR();

    resultstart();
    resultmulti(t);
    resultmulti(vindex);
    resultend();
  }

  
  mathq_toc();


  return 0;
}
