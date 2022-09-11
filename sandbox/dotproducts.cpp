#include "mathq.h"



int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;


  CR();
  ECHO(Scalar<double> a{ 3 });
  ETV(a);
  ECHO(Scalar<double> b(5));
  ETV(b);
  ETV(a | b);


  CR();
  ECHO(Vector<double> v = { 1, -1 });
  ETV(v);
  ECHO(Vector<double> w = { 2, 1, -2 });
  ETV(w);
  ECHO(Matrix<double> A = { {1, 2}, {3, 4}, {5, 6} });
  ETV(A);
  ECHO(Matrix<double, 2, 3> B = { {1, 2, 1}, {3, 4, 5} });
  ETV(B);
  ECHO(Matrix<double, 2, 2> C = { {1, 2}, {3, 4} });
  ETV(C);
  ETV(C.transpose());

  ETV(v | v);
  ETV(v+1);
  ETV(v | v+1);
  ETV(A | v);
  ETV(w | A);
  ETV(B | A);
  ETV(A | B);
  ETV(transpose(A));
  ETV(transpose(A) | A);
  ETV(A | transpose(A));


  ECHO(MultiArray<double, 3, 4, 3, 2> T1 = {
    { {1, 2}, {3, 4}, {5, 6} },
    { {7, 8}, {9, 10}, {11, 12} },
    { {13, 14}, {15, 16}, {17, 18} },
    { {19, 20}, {21, 22}, {23, 24} },
    });
  ETV(T1);
  ETV(T1.dims());
  ETV(T1.size());
  ETV(T1(3, 2, 1));

  ECHO(MultiArray<double, 3, 4, 3, 3> T2);
  ECHO(T2 = T1 | B);
  ETV(T2);

  // verified in matlab result shoudl be:
  // ☀ T2 ➜ MultiArray<double,rank=3,4⨯3⨯3> 
  // {
  //   {
  //     {7, 10, 11},
  //     {15, 22, 23},
  //     {23, 34, 35}
  //   },
  //   {
  //     {31, 46, 47},
  //     {39, 58, 59},
  //     {47, 70, 71}
  //   },
  //   {
  //     {55, 82, 83},
  //     {63, 94, 95},
  //     {71, 106, 107}
  //   },
  //   {
  //     {79, 118, 119},
  //     {87, 130, 131},
  //     {95, 142, 143}
  //   }
  // };

  return 0;
}
