


#include "mathq.h"
#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>






int main()
{
 
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  int Nex = 1;
  
  mathq_toc();
  CR();CR();
  mdtitle0("Calculating a function via Fourier series and plotting the results in Matlab");
  mathq_preamble();

  GMD_HEADER2("Fourier Series for the Clausen Functions");
  OUTPUT("As our example, we'll use the [Clausen functions](http://mathworld.wolfram.com/ClausenFunction.html). The Clausen function of order _n_ has Fourier series: ");
  OUTPUT("![Clausen Functions](ClausenDefinition.png)");


  GMD_HEADER3("Clausen function of order _n=1_");

  {
    CR();
    CR();
    OUTPUT("Set up the output format so that we can copy and paste into Matlab");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace display  );
    ECHO_CODE( FormatDataVector::string_opening =  "[ ...\n    "  );
    ECHO_CODE( FormatDataVector::string_delimeter = ", "  );
    ECHO_CODE( FormatDataVector::max_elements_per_line = 5  );
    ECHO_CODE( FormatDataVector::string_endofline = " ...\n    "  );
    ECHO_CODE( FormatDataVector::string_closing =   " ...\n]"  );
    ECHO_CODE( setFormatString<double>("% 10.8e")  );
    ECHO_CODE(  FormatData<double>::tens = false );
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coefficient vectors: ");
    CR();

    
    GMD_CODE_START("C++");
    ECHO_CODE( const size_type N = 20 );
    ECHO_CODE( Vector<double> k = range<double>(0,N-1)  );
    ECHO_CODE( Vector<double> An = 1/k );
    ECHO_CODE( An[0] = 0. );
    ECHO_CODE( Vector<double> Bn = Vector<double>(N,0.) );
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: ");
    CR();
    
    GMD_CODE_START("C++");
    ECHO_CODE(   const double pi = M_PI  );
    ECHO_CODE(   Vector<double> t = linspace<double>(0,2*pi,51) );
    GMD_CODE_END();
    CR();


    OUTPUT("Calculate the Fourier series and store the results in vector `CL1`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO_CODE(     const double T = 2*pi );
    ECHO_CODE(     const double omega = 2*pi/T );
    ECHO_CODE(     Vector<double> CL1 = ifourier(An,Bn, t, An.size(), omega ) );
    GMD_CODE_END();
    CR();

    
    OUTPUT("The results `t` and `CL1` are:");
    CR();
    GMD_CODE_START("Matlab");
    DISP(t);
    DISP(CL1);
    GMD_CODE_END();

    OUTPUT("Cut and paste the above data for `t` and `CL1` into Matlab as well as the following commands");
    CR();
    GMD_CODE_START("Matlab");
    OUTPUT("N=10000;");
    OUTPUT("dt=2*pi/N;");
    OUTPUT("tt=linspace(dt,2*pi-dt,10000);");
    OUTPUT("y1=-log(2*abs(sin(tt/2)));");
    OUTPUT("plot(t,CL1,'r.',tt,y1)");
    GMD_CODE_END();

    OUTPUT("The above matlab code calculates the first Clausen function using the equation");
    CR();
    CR();
    OUTPUT("![Closed form for CL1(t)](ClausenFormula_n1.png)");
    CR();
    CR();
    
    OUTPUT("We exclude the end points, 0 and pi, because the function is infinite at these points.");

    OUTPUT("This yields the following plot comparing the Fourier series [red dots] to the exact function [solid blue].");

    OUTPUT("![Fourier Series for CL1</sub>(t)](ClausenFourierSeries_n1.png)");

  }

  GMD_HEADER3("Clausen function of order _n=2_");

  {
    CR();
    CR();
    OUTPUT("Set up the output format so that we can copy and paste into Matlab, this time using the function `set_matlab_var_format()`");
    GMD_CODE_START("C++");
    ECHO_CODE( set_matlab_var_format()  );
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coefficient vectors: ");
    CR();

    
    GMD_CODE_START("C++");
    ECHO_CODE( const size_type N = 20 );
    ECHO_CODE( Vector<double> k = range<double>(0,N-1)  );
    ECHO_CODE( Vector<double> An = Vector<double>(N,0.) );
    ECHO_CODE( Vector<double> Bn = 1./sqr(k) );
    ECHO_CODE( Bn[0] = 0. );
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: ");
    CR();
    
    GMD_CODE_START("C++");
    ECHO_CODE(   const double pi = M_PI  );
    ECHO_CODE(   Vector<double> t = linspace<double>(0,2*pi,51) );
    GMD_CODE_END();
    CR();


    OUTPUT("Calculate the Fourier series and store the results in vector `CL2`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO_CODE(     const double T = 2*pi );
    ECHO_CODE(     const double omega = 2*pi/T );
    ECHO_CODE(     Vector<double> CL2 = ifourier(An,Bn, t, An.size(), omega ) );
    GMD_CODE_END();
    CR();

    
    OUTPUT("The results `t` and `CL2` are:");
    CR();
    GMD_CODE_START("Matlab");
    DISP(t);
    DISP(CL2);
    GMD_CODE_END();

    OUTPUT("Cut and paste the above data for t and CL2 into Matlab as well as the following commands.");
    CR();
    GMD_CODE_START("Matlab");
    OUTPUT("N=10000;");
    OUTPUT("dt=2*pi/N;");
    OUTPUT("tt=linspace(dt,2*pi-dt,10000);");
    OUTPUT("y2=cumtrapz(-log(2*abs(sin(tt/2))))*dt;");
    OUTPUT("plot(t,CL2,'r.',tt,y2)");
    GMD_CODE_END();

    OUTPUT("The above matlab code calculates the second Clausen function using the following integral");
    CR();
    CR();
    OUTPUT("![Closed form for CL2(t)](ClausenFormula_n2.png)");
    CR();
    CR();

    OUTPUT("We exclude the end points, 0 and pi, because the integrand is infinite at these points.");
    OUTPUT("This yields the following plot comparing the Fourier series [red dots] to the exact function [solid blue].");

    OUTPUT("![Fourier Series for CL2(t)](ClausenFourierSeries_n2.png)");

  }

  mathq_toc();

  
  return 0;
}
