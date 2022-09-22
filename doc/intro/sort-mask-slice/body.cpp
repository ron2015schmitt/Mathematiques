#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();


  GMD_HEADER2("Sequences");


  OUTPUT("The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start, start+1, start+2, ..., (end)}`");
  OUTPUT("* The sequence can be increasing (stride = +1) or decreasing (stride = -1)");
  OUTPUT("* The start and end need not be integers ");

  CR();
  GMD_CODE_START("C++");
  ETV(range<int>(1, 10));
  ETV(range<double>(-3, 3));
  ETV(range<int>(10, 0));
  ETV(range<int>(1.5, 3.5));
  GMD_CODE_END();


  GMD_HEADER3("Arbitrary stride");


  OUTPUT("* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start, start+stride, start+2*stride, ..., (end)}`");

  CR();
  OUTPUT("Seqeunces of different strides using `range`");
  GMD_CODE_START("C++");
  ETV(range<int>(2, 10, 2));
  ETV(range<double>(0, 5, 0.5));
  GMD_CODE_END();


  GMD_HEADER3("Initializing and Assigning a `Vector` using `range`");
  {
    CR();
    CR();
    OUTPUT("Initialize `Vector`'s of various data types  using the *`range`* function");
    GMD_CODE_START("C++");
    ECHO(Vector<unsigned int> v{ range<unsigned int>(0, 3)) };
    ETV(v);
    ECHO(v = range<unsigned int>(1, 4));
    ETV(v);
    GMD_CODE_END();
    CR();

  }

  GMD_VSPACE();
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
    OUTPUT("Positive and negative indices");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v{ 0,1,2,3 });
    ECHO(const int N = v.size());
    CR();
    ETV(v);
    ETV(N);
    ETV(v[0]);
    ETV(v[1]);
    ETV(v[2]);
    ETV(v[3]);
    ETV(v[-1]);
    ETV(v[-2]);
    ETV(v[-3]);
    ETV(v[-4]);

    CR();
    ECHO(Matrix<double> A{ {1,2,3,4},{5,6,7,8} });
    ETV(A);
    ETV(A(0, 1));
    ETV(A(0, -1));
    ETV(A(-1, 0));
    GMD_CODE_END();
  }



  GMD_HEADER3("Lists of indices");

  CR();
  OUTPUT("* The list can be smaller than or greater than or equal to the length to the data Vector.");
  OUTPUT("* The list can have repeated indices and indices can be in any order!");
  {
    CR();
    CR();
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(linspace<double>(0, 1, 11)));
    ETV(v);
    CR();
    ETV(v[{0, 4}]);
    ETV(v[{4, 0, 1, 4}]);
    ETV(v[{1, 0, 2}]);
    ETV(v[{4, 3, 2, 1, 0}]);
    ETV(v[{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}]);
    GMD_CODE_END();
  }

  OUTPUT("🚧 This functionality is currently only available for vectors.");




  GMD_VSPACE();
  GMD_HEADER2("Vector mask access");
  OUTPUT("* A subset of a vector can be extracted using a boolean-valued vector of the same size.");
  OUTPUT("* For example `v[v>0]` will return a vector containing only the positive values of v.");
  OUTPUT("* Vector mask access can be used on the left hand side of assigment, allowing you to set values via masks.");
  {
    CR();
    CR();
    OUTPUT("Using vector masks");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(range<double>(-10, 10)));
    CR();
    ETV(v);
    ETV(v > 6);
    ETV(v[(v > 6)]);
    GMD_CODE_END();
    CR();

    OUTPUT("Now set all elements that are larger than 6 to 6 (clipping)");
    GMD_CODE_START("C++");
    ECHO(v[(v > 6)] = 6.);
    CR();
    ETV(v);
    GMD_CODE_END();
    CR();

    OUTPUT("Now set all negative elements to zero");
    GMD_CODE_START("C++");
    ECHO(v[(v < 0)] = 0.);
    CR();
    ETV(v);
    GMD_CODE_END();
    CR();

  }

  OUTPUT("🚧 This functionality is currently only available for vectors.");


  GMD_VSPACE();
  GMD_HEADER2("Slices via the `slc` function");
  OUTPUT("Slicing is very useful for numerical code and is a part of Fortran, python, and matlab.");
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
    OUTPUT("slice `v[slc(start,end)]`");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(range<double>(0, 10)));
    CR();

    ETV(v[slc(2, 6)]);
    ETV(v[slc(0, -1)]);
    ETV(v[slc(0, 1)]);
    ETV(v[slc(-2, -1)]);
    ETV(v[slc(1, 0)]);
    ETV(v[slc(-1, 0)]);
    GMD_CODE_END();
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
    OUTPUT("slice `v[slc(start,end,step)]`");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v0(0));
    ECHO(Vector<double> v4{ 0, 1, 2, 3 });
    ECHO(Vector<double> v5{ 0, 1, 2, 3, 4 });
    GMD_CODE_END();
    CR();

    OUTPUT("Reverse vectors of various lengths using the same slice");
    GMD_CODE_START("C++");
    ETV(v0[slc(-1, 0, -1)]);
    ETV(v4[slc(-1, 0, -1)]);
    ETV(v5[slc(-1, 0, -1)]);
    GMD_CODE_END();
    CR();

    OUTPUT("Get even-index elements of various vectors using the same slice");
    GMD_CODE_START("C++");
    ETV(v0[slc(0, -1, 2)]);
    ETV(v4[slc(0, -1, 2)]);
    ETV(v5[slc(0, -1, 2)]);
    GMD_CODE_END();
    CR();

    OUTPUT("Get odd-index elements of various vectors using the same slice");
    GMD_CODE_START("C++");
    ETV(v0[slc(1, -1, 2)]);
    ETV(v4[slc(1, -1, 2)]);
    ETV(v5[slc(1, -1, 2)]);
    GMD_CODE_END();
    CR();
  }

  GMD_VSPACE();
  GMD_HEADER2("Sorting");
  GMD_HEADER3("The `sort` method sorts the vector in-place returns a vector with the indices.");
  {
    CR();
    CR();
    GMD_CODE_START("C++");
    ECHO(Vector<double> v{ 22, -1, 3, 1, 200, 3, 17, 0 });
    ETV(v.sort());
    ETV(v);
    GMD_CODE_END();
    CR();
  }

  GMD_HEADER3("the `uniq` function");
  OUTPUT("* Examples\n");
  {
    CR();
    CR();
    GMD_CODE_START("C++");
    ECHO(Vector<double> v{ 22, -1, 3, 1, 200, 3, 17, 0 });
    ETV(v.uniq());
    ETV(v);
    GMD_CODE_END();
    CR();
  }



  GMD_VSPACE();
  return 0;
}
