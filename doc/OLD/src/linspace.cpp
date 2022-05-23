
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
  GMD_TITLE("The `linspace` functions");
  mathq_preamble();

  GMD_HEADER2("The `linspace` function: numerical interval [a,b]");
  OUTPUT("* The function `linspace<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a` to `b`, spaced by `(b-a)/(N-1)`");
  OUTPUT("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  GMD_CODE_START("C++");
  DISP(linspace<double>(100,400,4));
  DISP(linspace<unsigned int>(1,2,2));
  DISP(linspace<double>(0,1,11));
  DISP(linspace<double>(1,0,11));
  GMD_CODE_END();


  GMD_HEADER2("The `linspace_a` function: numerical interval (a,b]");
  OUTPUT("* The function `linspace_a<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a+delta` to `b`, where `delta=(b-a)/(N)` is the spacing between consecutive points.");
  OUTPUT("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  GMD_CODE_START("C++");
  DISP(linspace_a<double>(0,1,10));
  DISP(linspace_a<double>(1,0,10));
  GMD_CODE_END();


  GMD_HEADER2("The `linspace_b` function: numerical interval [a,b)");
  OUTPUT("* The function `linspace_b<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a` to `b-delta`, where `delta=(b-a)/(N)` is the spacing between consecutive points.");
  OUTPUT("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  GMD_CODE_START("C++");
  DISP(linspace_b<double>(0,1,10));
  DISP(linspace_b<double>(1,0,10));
  GMD_CODE_END();

  OUTPUT("* This function is very useful for dealing the domain of trig functions, since typicallywe want to use the **interval [0,2*pi)**, ie we dont want to include the point 2*pi");


  GMD_HEADER2("The `linspace_ab` function: numerical interval (a,b)");
  OUTPUT("* The function `linspace_ab<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a+delta` to `b-delta`, where `delta=(b-a)/(N+1)` is the spacing between consecutive points.");
  OUTPUT("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  GMD_CODE_START("C++");
  DISP(linspace_ab<double>(0,1,9));
  DISP(linspace_ab<double>(1,0,9));
  GMD_CODE_END();

  
  mathq_toc();

  return 0;
}
