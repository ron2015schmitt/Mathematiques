#include <string>
#include <complex>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>


int main(int argc, char* argv[]) {


  using namespace std;
  using namespace std::complex_literals;


  cout << 1.3 + 2 << endl;


  cout << (complex<double>(1.3, -10.5) - complex<double>(1, -10)) << endl;
  cout << 1.3 - 10.5i - (1. + 10i) << endl;


  // ALL  THESE FAIL TO COMPILE}
//   cout << float(100) + complex<double>(1.3, -10.5) << endl;

  // cout << complex<double>(1.3, -10.5) - complex<float>(1.2, 5) << endl;
  // cout << 5 + complex<double>(1.3, -10.5) << endl;
  // cout << int(100) + complex<double>(1.3, -10.5) << endl;
  // cout << (complex<double>(1.3, -10.5) + complex<int>(1, -10)) << endl;
  // cout << 1.3 - 10.5i - (1 + 10i) << endl;


  return 0;
}
