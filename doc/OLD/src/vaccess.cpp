
// flag for run-time bounds and size checking



#include "mathq.h"

#include <iostream>





int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  


  const int N = 10;

  Vector<double> v1(N,"v1");

  std::cout << "initialize each element of v1" << std::endl;
  v1 = sqr(linspace<double>(1,19,N));
  std::cout << v1<< std::endl;




  std::cout << "access the last 3 elements of v1" << std::endl;
  Vector<double> v2(3,"v2");
  v2 = v1[seq(7,9)];
  std::cout << v2<< std::endl;
  

  std::cout << "set the last 3 elements of v1 to zero" << std::endl;
  v1[seq(7,9)] = 0;
  std::cout << v1<< std::endl;


  std::cout << "set the last 3 elements of v1 back to original values" << std::endl;
  v1[seq(7,9)] =  v2;
  std::cout << v1<< std::endl;

  std::cout << "Set the last 3 elements of v1 to the negation of elements 5,6,7" << std::endl;
  v1[seq(7,9)] =  -v1[seq(5,7)];
  std::cout << v1<< std::endl;

  


  std::cout << "v2 = elements 3,5,0 of v1, v2=v1[v3]" << std::endl;
  Vector<uint> v3(3,"v3");
  v3[0] = 3;
  v3[1] = 5;
  v3[2] = 0;
  std::cout <<"v3=" << v3<< std::endl;
  v2 = v1[v3];
  std::cout <<"v2="<< v2<< std::endl;
  

  std::cout << "v2 = elements 3,4,5 of v1, v2=v1[seq(3,5)]" << std::endl;
  v2 = v1[seq(3,5)];
  std::cout << v2<< std::endl;


  std::cout << "access negative elements of v1 using a mask" << std::endl;
  // Since, in general, one doesn't know how many elements meet conditions
  // and since the size of Vector objects is fixed,
  // we need to place into a vector via contructor
  Vector<bool> mask=(v1<0.0);
  mask.name("mask");
  std::cout <<"mask=(v1<0.0)="<<mask<< std::endl;    
  Vector<double> v4(v1[mask],"v4");
  std::cout<<"v4=v1[mask]=" << v4 << std::endl;
  

  std::cout << "access negative elements of v1 using v1[v1<0]" << std::endl;
  // Since, in general, one doesn't know how many elements meet conditions
  // and since the size of Vector objects is fixed,
  // we need to place into a vector via contructor
  Vector<double> v5 = v1[v1<0.0];  
  std::cout<<"v5=v1[v1<0.0]=" << v5<< std::endl;

  
  std::cout << "Set negative elements of v1 to zero, v1[v1<0.0] = 0" << std::endl;
  v1[v1<0.0] = 0;
  std::cout << v1<< std::endl;
  
  std::cout << "Negate every other element of v1" << std::endl;
  Vector<uint> ieven = range<uint>(0,N-1,2);
  v1[ieven] = -v1[ieven];
  std::cout << v1<< std::endl;
  

  Vector<double> x1(N,"x1");
  std::cout<<std::endl << "reinitialize v1 and x1" << std::endl;
  v1[7]=3;
  v1[8]=2;
  v1[9]=1;
  std::cout<<"v1=" << v1<< std::endl;
  x1=v1;
  std::cout<<"x1=" << x1<< std::endl;


  std::cout<<std::endl << "sort x1 in place, using sort(x1)" << std::endl;
  sort(x1);
  std::cout<<"x1=" << x1<< std::endl;


  x1=v1;
  std::cout<<std::endl<<"x1=" << x1<< std::endl;
  std::cout<< "sort x1 in place and store the indices" << std::endl;
  Vector<unsigned int> ii(N);
  ii = sortwind(x1);
  std::cout<<"ii=sortwind(x1)=" << ii<< std::endl;
  std::cout<<"x1=" << x1<< std::endl;

  return 0;
}
