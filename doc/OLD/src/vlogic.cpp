
// flag for run-time bounds and size checking



#include "mathq.h"

#include <iostream>





int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  Vector<double> v1(4,"v1");

  std::cout << "initialize v1" << std::endl;
  v1 = range<double>(1,4);
  std::cout << v1 << std::endl<<std::endl;

  std::cout << "test v1==1 and store in q1" << std::endl;
  Vector<bool> q1(4,"q1");
  q1 = (v1==1);
  std::cout <<"q1="<< q1;
  // the "boolalpha" flag allows display of boolean value as true/false
  std::cout <<boolalpha;
  // redisplay q1
  std::cout <<"="<< q1 << std::endl<<std::endl;

  std::cout << "test v1>=3 and store in q1" << std::endl;
  q1 = (v1>=3);
  std::cout <<"q1="<< q1<<std::endl<<std::endl;

  std::cout << "initialize v2" << std::endl;
  Vector<double> v2(4,"v2");
  double data[4] = {-3.0, 0, 3.0, 10};
  v2 = vcast<double>(data,4);
  std::cout << v2 << std::endl<<std::endl;

  std::cout << "test v1==v2 and store in q2" << std::endl;
  Vector<bool> q2(4,"q2");
  q2 = (v1==v2);
  std::cout <<"q2="<< q2<<std::endl<<std::endl;

  std::cout << "logical OR: q3 = q1 || q2" << std::endl;
  Vector<bool> q3(4,"q3");
  q3 = (q1||q2);
  std::cout <<"q3="<< q3<<std::endl<<std::endl;

  std::cout << "logical AND: q3 = q1 && q2" << std::endl;
  q3 = (q1&&q2);
  std::cout <<"q3="<< q3<<std::endl<<std::endl;

  std::cout << "logical NOT: q3 = !q1" << std::endl;
  q3 = !q1;
  std::cout <<"q3="<< q3<<std::endl<<std::endl;


  std::cout << "count the number of true results in a boolean vector: n=numtrue(q1)" << std::endl;
  int n = numtrue(q3);
  std::cout <<"n="<< n<<std::endl<<std::endl;

  std::cout << "find the indices of the true results: j1=findtrue(q1)" << std::endl;
  Vector<uint> j1 = findtrue(q1);
  std::cout <<"j1="<< j1 <<std::endl<<std::endl;

  std::cout << "determine if ANY values in a vector are zero: " << std::endl;
  bool Q = anytrue(v1==0);
  std::cout <<"Q=anytrue(v1==0) = "<< Q <<std::endl<<std::endl;
  Q = anytrue(v2==0);
  std::cout <<"Q=anytrue(v2==0) = "<< Q <<std::endl<<std::endl;

  std::cout << "determine if ALL values in a vector are positive: " << std::endl;
  Q = alltrue(v1>0);
  std::cout <<"Q=alltrue(v1>0) = "<< Q <<std::endl<<std::endl;
  Q = alltrue(v2>0);
  std::cout <<"Q=alltrue(v2>0) = "<< Q <<std::endl<<std::endl;

  std::cout << "collect all the negative values in a vector: " << std::endl;
  Vector<double> v4(0);
  v4.resize() = v1[v1<0];
  std::cout <<"v4.resize() = v1[v1<0] = "<< v4 <<std::endl<<std::endl;
  v4.resize() = v2[v2<0];
  std::cout <<"v4.resize() = v2[v2<0] = "<< v4 <<std::endl<<std::endl;


  return 0;
}
