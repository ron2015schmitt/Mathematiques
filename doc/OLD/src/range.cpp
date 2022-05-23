
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
  GMD_TITLE("The `range` function");
  mathq_preamble();

  GMD_HEADER3("Increasing Sequences");

  OUTPUT("* The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start, start+1, start+2, ..., (end)}`");
  CR();
  EXAMPLE(Nex++, "Increasing sequences using `range`");
  GMD_CODE_START("C++");
  DISP(range<int>(1,10));
  DISP(range<double>(-3,3));
  GMD_CODE_END();

  GMD_HEADER3("Decreasing Sequences");
  OUTPUT("* Counting down is also supported");
  CR();
  EXAMPLE(Nex++, "Decreasing sequence using `range`");
  GMD_CODE_START("C++");
  DISP(range<int>(10,0));
  GMD_CODE_END();


  GMD_HEADER3("Non-integer Sequences");

  OUTPUT("* The start and end need not be integers ");
  CR();
  EXAMPLE(Nex++, "Floating point sequences using `range`");
  GMD_CODE_START("C++");
  DISP(range<double>(1.5,5.5));
  DISP(range<double>(5.5,1.5));
  GMD_CODE_END();

  GMD_HEADER3("Arbitrary stride");

  
  OUTPUT("* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start, start+stride, start+2*stride, ..., (end)}`");

  CR();
  EXAMPLE(Nex++, "Seqeunces of different strides using `range`");
  GMD_CODE_START("C++");
  DISP(range<int>(2,10,2));
  DISP(range<double>(0,10,0.5));
  GMD_CODE_END();

  GMD_HEADER3("The end point isn't always included");

  OUTPUT("* The end point is only included when ");
  OUTPUT("```C++");
  OUTPUT("end == start + n * stride");
  OUTPUT("```");
  OUTPUT("where `n` is an integer.\n");

  CR();
  EXAMPLE(Nex++, "End point is not included in certain cases");
  GMD_CODE_START("C++");
  DISP(range<int>(0,5,2));
  DISP(range<double>(1,3.5));
  GMD_CODE_END();


  GMD_HEADER3("Initializing `Vector`'s using `range`");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"Initialize `Vector`'s of various data types  using the *`range`* function");
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<unsigned int> v1 ( range<unsigned int>(0,3) ) );
    ECHO_CODE( Vector<int> v2 ( range<int>(0,3) ) );
    ECHO_CODE( Vector<double> v3 ( range<double>(0,3)) );
    GMD_CODE_END();
    CR();

    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultend();
  }


  GMD_HEADER3("Assigning `Vector`'s using `range`");

  {
    CR();
    CR();
    EXAMPLE(Nex++,"Assigning a `Vector`'s to a *`range`*");
    GMD_CODE_START("C++");
    ECHO_CODE( const size_t N = 10);
    ECHO_CODE( Vector<double> v (N));
    ECHO_CODE( v = range<double>(0,N-1));
    GMD_CODE_END();
    CR();

    resultstart();
    resultmulti(v);
    resultend();
  }




  mathq_toc();

  return 0;
}
