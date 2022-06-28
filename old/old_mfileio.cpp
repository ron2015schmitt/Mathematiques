
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

  Matrix<double> D1(2,3,"D1");
  Matrix<double> D2("D2");


  "{{1,2,3},{4,5,6}}" >> D1;
  DISP(D1);
  DISP(D2);

  // save a matrix to a file in default "braces" format
  save(D1,"Matrix1.temp");

  // load a matrix from a file in "braces" format
  // ** NOTE THAT THE DESTINATION MATRIX IS CLEARED AND RESIZED TO MATCH
  // ** THE DATA IN The FILE
  load(D2,"Matrix1.temp");

  DISP(D2);


    "{{0,12,-3},{3.14159265,5.1,6.122}}" >> D1;
  DISP(D1);


  // save a matrix to a file in default "no braces" format
  D1.textformat(text_nobraces);
  save(D1,"Matrix2.temp");

  // load a matrix from a file in "no braces" format
  D2.clear();
  DISP(D2);
  D2.textformat(text_nobraces);
  load(D2,"Matrix2.temp");

  DISP(D2);



  // you can control the precision of the output numbers 
  // here the precision is set to 2 digits
  save(D1,"Matrix3.temp",2);

  
  // you can control other format paramters too, using flags
  ios_base::fmtflags flags = ios_base::right | ios_base::showpos;
  save(D1,"Matrix4.temp",flags);  //use default precision

  // Here's one last example
  D1.width(13);  //sets output width for each element
  flags = ios_base::right | ios_base::showpoint | ios_base::scientific;
  save(D1,"Matrix5.temp",5,flags);

  return 0;
}
