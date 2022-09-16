#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>


#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  // using namespace mathq::unit_quaternion;
  // using namespace mathq::unit_imaginary;
  // using std::sqrt;

  OUTPUT("Mathématiques supports vectors, matrices and arbitrary rank multi-arrays.");


  GMD_HEADER3("Increasing Sequences");

  OUTPUT("* The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start, start+1, start+2, ..., (end)}`");
  CR();
  OUTPUT("Increasing sequences using `range`");
  GMD_CODE_START("C++");
  DISP(range<int>(1, 10));
  DISP(range<double>(-3, 3));
  GMD_CODE_END();

  GMD_HEADER3("Decreasing Sequences");
  OUTPUT("* Counting down is also supported");
  CR();
  OUTPUT("Decreasing sequence using `range`");
  GMD_CODE_START("C++");
  DISP(range<int>(10, 0));
  GMD_CODE_END();


  GMD_HEADER3("Non-integer Sequences");

  OUTPUT("* The start and end need not be integers ");
  CR();
  OUTPUT("Floating point sequences using `range`");
  GMD_CODE_START("C++");
  DISP(range<double>(1.5, 5.5));
  DISP(range<double>(5.5, 1.5));
  GMD_CODE_END();

  GMD_HEADER3("Arbitrary stride");


  OUTPUT("* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start, start+stride, start+2*stride, ..., (end)}`");

  CR();
  OUTPUT("Seqeunces of different strides using `range`");
  GMD_CODE_START("C++");
  DISP(range<int>(2, 10, 2));
  DISP(range<double>(0, 10, 0.5));
  GMD_CODE_END();

  GMD_HEADER3("The end point isn't always included");

  OUTPUT("* The end point is only included when ");
  OUTPUT("```C++");
  OUTPUT("end == start + n * stride");
  OUTPUT("```");
  OUTPUT("where `n` is an integer.\n");

  CR();
  OUTPUT("End point is not included in certain cases");
  GMD_CODE_START("C++");
  DISP(range<int>(0, 5, 2));
  DISP(range<double>(1, 3.5));
  GMD_CODE_END();


  GMD_HEADER3("Initializing `Vector`'s using `range`");

  {
    CR();
    CR();
    OUTPUT("Initialize `Vector`'s of various data types  using the *`range`* function");
    GMD_CODE_START("C++");
    ECHO(Vector<unsigned int> v1(range<unsigned int>(0, 3)));
    ECHO(Vector<int> v2(range<int>(0, 3)));
    ECHO(Vector<double> v3(range<double>(0, 3)));
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
    OUTPUT("Assigning a `Vector`'s to a *`range`*");
    GMD_CODE_START("C++");
    ECHO(const size_t N = 10);
    ECHO(Vector<double> v(N));
    ECHO(v = range<double>(0, N-1));
    GMD_CODE_END();
    CR();
  }

  // std::cout<<std::endl << "sort x1 in place, using sort(x1)" << std::endl;
  // sort(x1);
  // std::cout<<"x1=" << x1<< std::endl;


  // x1 = v1;
  // std::cout<<std::endl<<"x1=" << x1<< std::endl;
  // std::cout<< "sort x1 in place and store the indices" << std::endl;
  // Vector<unsigned int> ii(N);
  // ii = sortwind(x1);
  // std::cout<<"ii=sortwind(x1)=" << ii<< std::endl;
  // std::cout<<"x1=" << x1<< std::endl;


  // Vector<double> v1(4, "v1");

  // std::cout << "initialize v1" << std::endl;
  // v1 = range<double>(1, 4);
  // std::cout << v1 << std::endl<<std::endl;

  // std::cout << "test v1==1 and store in q1" << std::endl;
  // Vector<bool> q1(4, "q1");
  // q1 = (v1==1);
  // std::cout <<"q1="<< q1;
  // // the "boolalpha" flag allows display of boolean value as true/false
  // std::cout <<boolalpha;
  // // redisplay q1
  // std::cout <<"="<< q1 << std::endl<<std::endl;

  // std::cout << "test v1>=3 and store in q1" << std::endl;
  // q1 = (v1>=3);
  // std::cout <<"q1="<< q1<<std::endl<<std::endl;

  // std::cout << "initialize v2" << std::endl;
  // Vector<double> v2(4, "v2");
  // double data[4] = { -3.0, 0, 3.0, 10 };
  // v2 = vcast<double>(data, 4);
  // std::cout << v2 << std::endl<<std::endl;

  // std::cout << "test v1==v2 and store in q2" << std::endl;
  // Vector<bool> q2(4, "q2");
  // q2 = (v1==v2);
  // std::cout <<"q2="<< q2<<std::endl<<std::endl;

  // std::cout << "logical OR: q3 = q1 || q2" << std::endl;
  // Vector<bool> q3(4, "q3");
  // q3 = (q1||q2);
  // std::cout <<"q3="<< q3<<std::endl<<std::endl;

  // std::cout << "logical AND: q3 = q1 && q2" << std::endl;
  // q3 = (q1&&q2);
  // std::cout <<"q3="<< q3<<std::endl<<std::endl;

  // std::cout << "logical NOT: q3 = !q1" << std::endl;
  // q3 = !q1;
  // std::cout <<"q3="<< q3<<std::endl<<std::endl;


  // std::cout << "count the number of true results in a boolean vector: n=numtrue(q1)" << std::endl;
  // int n = numtrue(q3);
  // std::cout <<"n="<< n<<std::endl<<std::endl;

  // std::cout << "find the indices of the true results: j1=findtrue(q1)" << std::endl;
  // Vector<uint> j1 = findtrue(q1);
  // std::cout <<"j1="<< j1 <<std::endl<<std::endl;

  // std::cout << "determine if ANY values in a vector are zero: " << std::endl;
  // bool Q = anytrue(v1==0);
  // std::cout <<"Q=anytrue(v1==0) = "<< Q <<std::endl<<std::endl;
  // Q = anytrue(v2==0);
  // std::cout <<"Q=anytrue(v2==0) = "<< Q <<std::endl<<std::endl;

  // std::cout << "determine if ALL values in a vector are positive: " << std::endl;
  // Q = alltrue(v1>0);
  // std::cout <<"Q=alltrue(v1>0) = "<< Q <<std::endl<<std::endl;
  // Q = alltrue(v2>0);
  // std::cout <<"Q=alltrue(v2>0) = "<< Q <<std::endl<<std::endl;

  // std::cout << "collect all the negative values in a vector: " << std::endl;
  // Vector<double> v4(0);
  // v4.resize() = v1[v1<0];
  // std::cout <<"v4.resize() = v1[v1<0] = "<< v4 <<std::endl<<std::endl;
  // v4.resize() = v2[v2<0];
  // std::cout <<"v4.resize() = v2[v2<0] = "<< v4 <<std::endl<<std::endl;

  GMD_HEADER2("Relational operators");

  GMD_HEADER3("Relational operators between two Vectors");
  CR();
  OUTPUT("Vector relations operate element-wise, similar to arithmetic operators. Given two Vectors of the same size, a vector relational expression (eg `(v1>v2)` returns a vector of booleans of the same size");

  {
    CR();
    CR();
    OUTPUT("relational operators between two vectors`");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v1(range<double>(1, 3)));
    ECHO(Vector<double> v2(range<double>(3, 1)));
    GMD_CODE_END();
    CR();


    resultstart2("");
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v1 >  v2);
    resultmulti(v1 >= v2);
    resultmulti(v1 <  v2);
    resultmulti(v1 <= v2);
    resultmulti(v1 == v2);
    resultmulti(v1 != v2);
    resultend();
  }

  GMD_HEADER3("Relational operators between a Vector and scalar");
  {
    CR();
    CR();
    OUTPUT("relational operators between a vector and a scalar`");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(range<double>(1, 3)));
    GMD_CODE_END();
    CR();


    resultstart2("");
    resultmulti(v);
    resultmulti(v >  2);
    resultmulti(v >= 2);
    resultmulti(v <  2);
    resultmulti(v <= 2);
    resultmulti(v == 2);
    resultmulti(v != 2);
    resultend();
  }

  GMD_HEADER2("Logical operators");

  GMD_HEADER3("The element-wise logical operatora `&&`,`||`,`!`");
  {
    CR();
    CR();
    OUTPUT("The element-wise logical operators");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(range<double>(1, 5)));
    GMD_CODE_END();
    CR();

    resultstart2("");
    resultmulti(v);
    resultmulti((v > 2));
    resultmulti(!(v > 2));
    resultmulti((v >= 2) && (v <= 4));
    resultmulti((v <= 2) || (v >= 4));
    resultend();
  }


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
    GMD_CODE_END();
    CR();


    resultstart2("");
    resultmulti(v);
    resultmulti(v > 6);
    resultmulti(v[(v > 6)]);
    resultend();
    CR();

    OUTPUT("Now set all elements that are larger than 6 to 6 (clipping)");
    GMD_CODE_START("C++");
    ECHO(v[(v > 6)] = 6.);
    GMD_CODE_END();
    resultstart();
    resultmulti(v);
    resultend();
    CR();

    OUTPUT("Now set all negative elements to zero");
    GMD_CODE_START("C++");
    ECHO(v[(v < 0)] = 0.);
    GMD_CODE_END();
    resultstart();
    resultmulti(v);
    resultend();
    CR();


  }


  GMD_HEADER2("Logical functions");

  GMD_HEADER3("The functions `alltrue`, `anytrue`, `numtrue`, and `findtrue`");
  {
    CR();
    OUTPUT("* The function `alltrue(v)` returns a `bool`: true if every element of `v` is true, otherwise it returns false");
    CR();
    OUTPUT("* The function `anytrue(v)` returns a `bool`: true if any element of `v` is true, otherwise it returns false");
    CR();
    OUTPUT("* The function `numtrue(v)` returns a `size_t` equal to the number of elements of `v` that are true. ");
    CR();
    OUTPUT("* The function `findtrue(v)` returns a `Vector<size_t>` which contains the indices of the true elements of `v`. ");
    CR();
    CR();
    OUTPUT("The functions `alltrue`, `anytrue`, `numtrue`, and `findtrue`");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(range<double>(1, 3)));
    GMD_CODE_END();
    CR();


    resultstart2("");
    resultmulti(v);
    resultmulti((v > 2));
    resultmulti(alltrue(v > 2));
    resultmulti(alltrue(v > 0));
    resultmulti(anytrue(v > 2));
    resultmulti(numtrue(v > 2));
    // resultmulti(numtrue(!(v > 2)));
    resultmulti(numtrue(v > 0));
    resultmulti(findtrue(v > 2));
    resultmulti(findtrue(v > 0));
    resultend();
  }


  OUTPUT("python-like access: negative indices & slices");

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
    ECHO(Vector<double> v(range<double>(0, 10)));
    ECHO(const int N = v.size());
    GMD_CODE_END();
    CR();


    resultstart2("");
    resultmulti(v);
    resultmulti(N);
    resultmulti(v[0]);
    resultmulti(v[1]);
    resultmulti(v[N-1]);
    resultmulti(v[-1]);
    resultmulti(v[-2]);
    resultmulti(v[-N]);
    // resultmulti(v[{0, -1}]);
    // resultmulti(v[{2, 2, -2, -2}]);
    resultend();
  }


  {
    CR();
    CR();
    OUTPUT("Reverse a vector in place.");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(range<double>(0, 10)));
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(v);
    resultend();
    GMD_CODE_START("C++");
    ECHO(for (int i = 0; i < v.size()/2; i++) std::swap(v[i], v[-i-1]));
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(v);
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
    OUTPUT("slice `v[slc(start,end)]`");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(range<double>(0, 10)));
    GMD_CODE_END();
    CR();

    resultstart2("");
    resultmulti(v[slc(2, 6)]);
    resultmulti(v[slc(0, -1)]);
    resultmulti(v[slc(0, 1)]);
    resultmulti(v[slc(-2, -1)]);
    resultmulti(v[slc(1, 0)]);
    resultmulti(v[slc(-1, 0)]);
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
    OUTPUT("slice `v[slc(start,end,step)]`");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v0(0));
    ECHO(Vector<double> v1(1, 0.));
    ECHO(Vector<double> v2(range<double>(0, 1)));
    ECHO(Vector<double> v3(range<double>(0, 2)));
    ECHO(Vector<double> v4(range<double>(0, 3)));
    ECHO(Vector<double> v10(range<double>(0, 10)));
    GMD_CODE_END();
    CR();

    resultstart2(": reverse vectors of various lengths using the same slice");
    resultmulti(v0[slc(-1, 0, -1)]);
    resultmulti(v1[slc(-1, 0, -1)]);
    resultmulti(v2[slc(-1, 0, -1)]);
    resultmulti(v3[slc(-1, 0, -1)]);
    resultmulti(v4[slc(-1, 0, -1)]);
    resultmulti(v10[slc(-1, 0, -1)]);
    resultend();

    resultstart2(": get even-index elements of various vectors using the same slice");
    resultmulti(v0[slc(0, -1, 2)]);
    resultmulti(v1[slc(0, -1, 2)]);
    resultmulti(v2[slc(0, -1, 2)]);
    resultmulti(v3[slc(0, -1, 2)]);
    resultmulti(v4[slc(0, -1, 2)]);
    resultmulti(v10[slc(0, -1, 2)]);
    resultend();

    resultstart2(": get odd-index elements of various vectors using the same slice");
    resultmulti(v0[slc(1, -1, 2)]);
    resultmulti(v1[slc(1, -1, 2)]);
    resultmulti(v2[slc(1, -1, 2)]);
    resultmulti(v3[slc(1, -1, 2)]);
    resultmulti(v4[slc(1, -1, 2)]);
    resultmulti(v10[slc(1, -1, 2)]);
    resultend();
  }

  OUTPUT("Access subsets of Vector elements");

  OUTPUT("You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices");


  GMD_HEADER2("Access vector elements using a `Vector` of indices");

  GMD_HEADER3("Element access `Vector[Vector]`");
  CR();
  OUTPUT("* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!");
  OUTPUT("* The index Vector _can have repeated indices and indices can be in any order_!");
  {
    CR();
    CR();
    OUTPUT("Access via a Vector of indices");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(linspace<double>(0, 1, 11)));
    ECHO(Vector<size_t> veven(range<size_t>(0, 10, 2)));
    ECHO(Vector<size_t> vodd(range<size_t>(1, 10, 2)));
    ECHO(Vector<size_t> vconst(15, 1));
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(v);
    resultmulti(veven);
    resultmulti(v[veven]);
    resultmulti(v[veven[1]]);
    resultmulti(vodd);
    resultmulti(v[vodd]);
    resultmulti(v[vodd[1]]);
    // resultmulti(v[veven, vodd]);
    resultmulti(v[vodd[veven[1]]]);
    resultmulti(vconst);
    resultmulti(v[vconst]);
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
    OUTPUT("Access via a C++11 initializer_list");
    GMD_CODE_START("C++");
    ECHO(Vector<double> v(linspace<double>(0, 1, 11)));
    DISP(v);
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(v[{0, 4}]);
    resultmulti(v[{4, 0, 1, 4}]);
    resultmulti(v[{1, 0, 2}]);
    resultmulti(v[{4, 3, 2, 1, 0}]);
    resultmulti(v[{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}]);
    resultend();
  }


  GMD_VSPACE();
  return 0;
}
