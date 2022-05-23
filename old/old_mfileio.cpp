
// flag for run-time bounds and size checking
#define MATHQ_DEBUG 1


#include "mathq.h"
using namespace mathq;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  
  // the load and save functions use the standard C++ file streams
  // and are provided as a convenience

  Matrix<double> M1(2,3,"M1");
  Matrix<double> M2("M2");


  "{{1,2,3},{4,5,6}}" >> M1;
  DISP(M1);
  DISP(M2);

  // save a matrix to a file in default "braces" format
  save(M1,"Matrix1.temp");

  // load a matrix from a file in "braces" format
  // ** NOTE THAT THE DESTINATION MATRIX IS CLEARED AND RESIZED TO MATCH
  // ** THE DATA IN The FILE
  load(M2,"Matrix1.temp");

  DISP(M2);


    "{{0,12,-3},{3.14159265,5.1,6.122}}" >> M1;
  DISP(M1);


  // save a matrix to a file in default "no braces" format
  M1.textformat(text_nobraces);
  save(M1,"Matrix2.temp");

  // load a matrix from a file in "no braces" format
  M2.clear();
  DISP(M2);
  M2.textformat(text_nobraces);
  load(M2,"Matrix2.temp");

  DISP(M2);



  // you can control the precision of the output numbers 
  // here the precision is set to 2 digits
  save(M1,"Matrix3.temp",2);

  
  // you can control other format paramters too, using flags
  ios_base::fmtflags flags = ios_base::right | ios_base::showpos;
  save(M1,"Matrix4.temp",flags);  //use default precision

  // Here's one last example
  M1.width(13);  //sets output width for each element
  flags = ios_base::right | ios_base::showpoint | ios_base::scientific;
  save(M1,"Matrix5.temp",5,flags);

  return 0;
}
