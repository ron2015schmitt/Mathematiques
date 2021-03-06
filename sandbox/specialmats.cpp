#define MATHQ_DEBUG 1
#include "mathq.h"



int main(int argc, char *argv[])
{


  
  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;
  using namespace std;
  
  Style bold = createStyle(BOLD);
  Style blue = createStyle(BOLD+BLUE2);

  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;
  print_mathq_info();
  
  cr();
  mout << blue.apply("MatrixZero") << std::endl;
  cr();
  {
    MatrixZero<double> a;
    tdisp(a);
    a.resize(2,2);
    tdisp(a);
  } 
  cr();
  {
    MatrixZero<double,3,2> a;
    tdisp(a);
    tdisp(exp(a));
  } 

  cr();
  mout << blue.apply("MatrixIdentity") << std::endl;
  cr();
  {
    MatrixIdentity<double> a;
    tdisp(a);
    a.resize(2,2);
    tdisp(a);
  } 
  cr();
  {
    MatrixIdentity<double,3,2> a;
    tdisp(a);
    tdisp(exp(a));
  } 

  cr();
  mout << blue.apply("MatrixExchange") << std::endl;
  cr();
  {
    MatrixExchange<double> a;
    tdisp(a);
    a.resize(2,2);
    tdisp(a);
  } 
  cr();
  {
    MatrixExchange<double,3,2> a;
    tdisp(a);
    tdisp(exp(a));
  } 

  cr();
  mout << blue.apply("MatrixConstDiag") << std::endl;
  cr();
  {
    MatrixConstDiag<double> a(2,2,8);
    tdisp(a);
    a.setValue(44);
    tdisp(a);
  } 
  cr();
  {
    MatrixConstDiag<double,3,2> a(8);
    tdisp(a);
    tdisp(pow(2,a));
  } 
    
  cr();
  mout << blue.apply("MatrixDiagonal") << std::endl;
  cr();
  {
    MatrixDiagonal<double> a(2,2,8);
    tdisp(a);
    a(0,0) = -2;
    a(1,1) = 2;
    a(1,0) = 3;
    tdisp(a);
  } 
  cr();
  {
    MatrixDiagonal<double,3,2> a(8);
    tdisp(a);
    tdisp(pow(2,a));
  } 


  cr();
  mout << blue.apply("MatrixRevDiag") << std::endl;
  cr();
  {
    MatrixRevDiag<double> a(2,2,8);
    tdisp(a);
    a(0,1) = -2;
    a(1,0) = 2;
    a(1,1) = 3;
    tdisp(a);
  } 
  cr();
  {
    MatrixRevDiag<double,3,2> a(8);
    tdisp(a);
    tdisp(pow(2,a));
  } 


  cr();
  mout << blue.apply("MatrixRepCol") << std::endl;
  cr();
  {
    Vector<double> v1 {1,2,3,4};
    MatrixRepCol<double> a(v1,2);
    tdisp(v1);
    tdisp(a);
    a(0,1) = -1;
    a(1,0) = -2;
    a(2,1) = -3;
    a(3,0) = -4;
    tdisp(a);
  } 
  cr();
  {
    MatrixRepCol<double,3,2> a(8);
    tdisp(a);
    tdisp(pow(2,a));
  } 
    

  cr();
  mout << blue.apply("MatrixRepRow") << std::endl;
  cr();
  {
    Vector<double> v1 {1,2,3,4};
    MatrixRepRow<double> a(v1,2);
    tdisp(v1);
    tdisp(a);
    a(0,1) = -1;
    a(1,0) = -2;
    a(2,1) = -3;
    a(3,0) = -4;
    tdisp(a);
  } 
  cr();
  {
    MatrixRepRow<double,3,2> a(8);
    tdisp(a);
    tdisp(pow(2,a));
  } 


  cr();
  mout << blue.apply("MatrixVandermonde") << std::endl;
  cr();
  {
    Vector<double> v1 {1,2,3,4};
    MatrixVandermonde<double> a(v1,3);
    tdisp(v1);
    tdisp(a);
    a(0,1) = -5;
    a(1,0) = -2;
    a(2,1) = -10;
    a(3,0) = -4;
    tdisp(a);
  } 
  cr();
  {
    MatrixVandermonde<double,3,4> a(3);
    tdisp(a);
    tdisp(pow(2,a));
  } 

    
  cr();
  mout << blue.apply("MatrixToeplitz") << std::endl;
  cr();
  {
    // vector size is Nrows + Ncols + 1
    Vector<double> v1 {1,2,3,4,5};
    MatrixToeplitz<double> a(v1,3,3);
    tdisp(v1);
    tdisp(a);
    a(0,1) = -5;
    a(1,0) = -2;
    a(2,1) = -10;
    a(2,0) = -4;
    tdisp(a);
  } 
  cr();
  {
    Vector<double> v1 {1,2,3,4};
    MatrixToeplitz<double,3,2> a(v1);
    tdisp(a);
    tdisp(pow(2,a));
  } 
  cr();
  {
    Vector<double> v1 {1,2,3,4};
    MatrixToeplitz<double,2,3> a(v1);
    tdisp(a);
    tdisp(2*a);
  } 


  cr();
  mout << blue.apply("MatrixUpperTriangle") << std::endl;
  cr();
  {
    MatrixUpperTriangle<double,3> a(9);
    tdisp(a);
    a(0,0) = 1;
    a(0,1) = 2;
    a(0,2) = 3;
    a(1,0) = -2;
    a(1,1) = 4;
    a(1,2) = 5;
    a(2,0) = -4;
    a(2,1) = -12;
    a(2,2) = 6;
    tdisp(a);
  } 
  cr();
  {
    Vector<double> v {1,2,3,4,5,6,7,8,9,10};
    MatrixUpperTriangle<double> a(v);
    tdisp(a);
    Matrix<double> b = transpose(a);
    tdisp(b);
  } 
  
  cr();
  mout << blue.apply("MatrixLowerTriangle") << std::endl;
  cr();
  cr();
  {
    MatrixLowerTriangle<double,3> a(9);
    tdisp(a);
    a(0,0) = 1;
    a(0,1) = -1;
    a(0,2) = -2;
    a(1,0) = 2;
    a(1,1) = 3;
    a(1,2) = -3;
    a(2,0) = 4;
    a(2,1) = 5;
    a(2,2) = 6;
    tdisp(a);
  } 
  cr();
  {
    Vector<double> v {1,2,3,4,5,6,7,8,9,10};
    MatrixLowerTriangle<double> a(v);
    tdisp(a);
    Matrix<double> b;
    b = transpose(a);
    tdisp(b);
  } 


  cr();
  mout << blue.apply("MatrixSymmetric") << std::endl;
  cr();
  cr();
  {
    MatrixSymmetric<double,3> a(9);
    tdisp(a);
    a(0,0) = 1;
    a(0,1) = 2;
    a(0,2) = 3;
    a(1,1) = 1;
    a(1,2) = 4;
    a(2,2) = 1;
    tdisp(a);
  } 
  cr();
  {
    Vector<double> v {1,2,3,4,5,6,7,8,9,10};
    MatrixSymmetric<double> a(v);
    tdisp(a);
    Matrix<double> b;
    b = transpose(a);
    tdisp(b);
  } 


  cr();
  mout << blue.apply("MatrixSkewSymmetric") << std::endl;
  cr();
  cr();
  {
    MatrixSkewSymmetric<double,3> a(9);
    tdisp(a);
    a(0,0) = -1;
    a(0,1) = 1;
    a(0,2) = 2;
    a(1,0) = -1;
    a(1,1) = -1;
    a(1,2) = 3;
    a(2,0) = -1;
    a(2,1) = -1;
    a(2,2) = -1;
    tdisp(a);
  } 
  cr();

  cr();
  mout << blue.apply("MatrixHermitian") << std::endl;
  cr();
  cr();
  {
    MatrixHermitian<double,3> a(9);
    tdisp(a);
    a(0,0) = 1;
    a(0,1) = 2;
    a(0,2) = 3;
    a(1,1) = 1;
    a(1,2) = 4;
    a(2,2) = 1;
    tdisp(a);
  } 
  cr();

  cr();
  cr();
  {
    MatrixHermitian<ComplexDouble,3> a(9);
    tdisp(a);
    a(0,0) = 1;
    a(0,1) = 2+20i;
    a(0,2) = 3+30i;
    a(1,1) = 1;
    a(1,2) = 4+40i;
    a(2,2) = 1;
    tdisp(a);
  } 
  cr();

  cr();
  mout << blue.apply("MatrixSkewHermitian") << std::endl;
  cr();
  cr();
  {
    MatrixSkewHermitian<double,3> a(9);
    tdisp(a);
    a(0,0) = 1;
    a(0,1) = 2;
    a(0,2) = 3;
    a(1,1) = 1;
    a(1,2) = 4;
    a(2,2) = 1;
    tdisp(a);
  } 
  cr();

  cr();
  cr();
  {
    MatrixSkewHermitian<ComplexDouble,3> a(9);
    tdisp(a);
    a(0,0) = 1;
    a(0,1) = 2+20i;
    a(0,2) = 3+30i;
    a(1,1) = 1;
    a(1,2) = 4+40i;
    a(2,2) = 1;
    tdisp(a);
  } 
  cr();

  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  return 0;
}
