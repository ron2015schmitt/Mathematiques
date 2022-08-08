#include "mathq.h"



int main(int argc, char* argv[]) {
  using namespace std;
  using namespace mathq;

  std::string myname = argv[0];

  cout << std::endl;
  cout << "running: " <<myname << std::endl;
  cout << std::endl;


  CR();
  ECHO_CODE( Scalar<double> a{3} );
  TRDISP(a);
  ECHO_CODE( Scalar<double> b(5) );
  TRDISP(b);
  TRDISP(a | b);


  CR();
  ECHO_CODE( Vector<double> v = { 1, -1 } );
  TRDISP(v);
  ECHO_CODE( Vector<double> w = { 2, 1, -2 } );
  TRDISP(w);
  ECHO_CODE( Matrix<double> A = { {1, 2}, {3, 4}, {5, 6} } );
  TRDISP(A);
  ECHO_CODE( Matrix<double,2,3> B = { {1, 2, 1}, {3, 4, 5} } );
  TRDISP(B);
  ECHO_CODE( Matrix<double,2,2> C = { {1, 2}, {3, 4} } );
  TRDISP(C);
  TRDISP(C.transpose());

  TRDISP(v | v);
  TRDISP(v+1);
  TRDISP(v | v+1);
  TRDISP(A | v);
  TRDISP(w | A);
  TRDISP(B | A);
  TRDISP(A | B);
  TRDISP(transpose(A));
  TRDISP(transpose(A) | A);
  TRDISP(A | transpose(A));


  ECHO_CODE( MultiArray<double,3, 4,3,2> T1 = { 
    { {1, 2}, {3, 4}, {5, 6} },
    { {7, 8}, {9, 10}, {11, 12} },
    { {13, 14}, {15, 16}, {17, 18} },
    { {19, 20}, {21, 22}, {23, 24} },
  } );
  TRDISP(T1);
  TRDISP(T1.dims());
  TRDISP(T1.size());
  TRDISP(T1(3,2,1));

  ECHO_CODE( MultiArray<double,3, 4,3,3> T2 );
  ECHO_CODE(T2 = T1 | B);
  TRDISP(T2);

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
