


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
  mdtitle0("Calculating a Taylor series and plotting the results in Mathematica");
  mathq_preamble();

  GMD_HEADER2("Taylor Series for the Bessel Function J<sub>0</sub>(r)");
  OUTPUT("We can easily calculate a [Taylor Series](http://mathworld.wolfram.com/TaylorSeries.html) in mathq. As an example, let's calculate the Taylor series for the [Bessel Function of the first kind](http://mathworld.wolfram.com/BesselFunctionoftheFirstKind.html) of order 0, J<sub>0</sub>(r). ");

  OUTPUT("The first 20 (n=0,1,...19) coefficients for  J<sub>0</sub>(r), are:\n");


  {  
    set_mathematica_var_format();
  Vector<double> J0Coeffs =  Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.});

    GMD_CODE_START("C++");
    DISP(J0Coeffs);
    GMD_CODE_END();
  
  }
  OUTPUT("These were determined using the following `Mathematica` command");
  CR();

  GMD_CODE_START("Mathematica");
  OUTPUT("N[Table[SeriesCoefficient[BesselJ[0,r],{r,0,n}],{n,0,19}]]");
  CR();
  GMD_CODE_END();
  
  {
    CR();
    CR();
    OUTPUT("Set up the output format so that we can copy and paste into Mathematica");
    GMD_CODE_START("C++");
    ECHO_CODE( using namespace display  );
    ECHO_CODE( FormatDataVector::string_opening =  "{\n    "  );
    ECHO_CODE( FormatDataVector::string_delimeter = ", "  );
    ECHO_CODE( FormatDataVector::max_elements_per_line = 5  );
    ECHO_CODE( FormatDataVector::string_endofline = "\n    "  );
    ECHO_CODE( FormatDataVector::string_closing =   "\n}"  );
    ECHO_CODE( setFormatString<double>("% 10.8e")  );
    ECHO_CODE(  FormatData<double>::tens = true );
    GMD_CODE_END();
    CR();

   

    OUTPUT("Define the Vector of coefficients: ");
    CR();

    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> J0Coeffs =  Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.})  );
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `r` as 101 points over the interval [0,10]: ");
    CR();
    
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> r = linspace<double>(0,10,101)  );
    GMD_CODE_END();
    CR();

    OUTPUT("Calculate the Taylor series and store the results in vector `y`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> y = taylor(J0Coeffs, r, 19)  );
    GMD_CODE_END();
    CR();

    
    OUTPUT("The results `r` and `y` are:");
    CR();
    GMD_CODE_START("Mathematica");
    DISP(r);
    DISP(y);
    GMD_CODE_END();

    OUTPUT("Cut and paste the above data for r and y into Mathematica as well as the following commands");
    CR();
    GMD_CODE_START("Mathematica");
    OUTPUT("p1=ListPlot[Partition[Riffle[r,y],2],PlotStyle->Red];");
    OUTPUT("p2=Plot[BesselJ[0,r],{r,0,10}];");
    OUTPUT("Show[p1,p2]");
    GMD_CODE_END();

    OUTPUT("This yields the following plot comparing the Taylor series [red dots] to the exact function [solid blue].");

    OUTPUT("![Taylor Series for Jo(r)](BesselTaylorSeries.png)");

  }

  
  GMD_HEADER2("Maclaurin Series for the Bessel Function J<sub>0</sub>(x)");

  OUTPUT("To acheive better accuracy, we can calculate the [Maclaurin Series](http://mathworld.wolfram.com/MaclaurinSeries.html) at the point `r=5`, which is the center of our interval of interest.");
  OUTPUT("The first 20 (n=0,1,...19) coefficients for the Maclaurin Series (r<sub>0</sub>=5) for the function J<sub>0</sub>(r), are:\n");


  {  
    set_mathematica_var_format();
    Vector<double> J0Coeffs =  Vector<double>({-0.177597,0.327579,0.0560405,-0.0561487,-0.00170739,0.00252021,0.0000112022,-0.000053795,2.1333e-7,6.7811e-7,-4.88572e-9,-5.6642e-9,4.80096e-11,3.37094e-11,-2.99711e-13,-1.50298e-13,1.33856e-15,5.20979e-16,-4.54744e-18,-1.44449e-18});

    GMD_CODE_START("C++");
    DISP(J0Coeffs);
    GMD_CODE_END();
  
  }
  OUTPUT("These were determined using the following `Mathematica` command");
  CR();

  GMD_CODE_START("Mathematica");
  OUTPUT("N[Table[SeriesCoefficient[BesselJ[0,r],{r,5,n}],{n,0,19}]]");
  CR();
  GMD_CODE_END();
  
  {
    CR();
    CR();
    OUTPUT("Set up the output format so that we can copy and paste into Mathematica, this time using the function `set_mathematica_var_format`");
    GMD_CODE_START("C++");
    ECHO_CODE( set_mathematica_var_format()  );
    GMD_CODE_END();
    CR();

   

    OUTPUT("Define the Vector of coefficients: ");
    CR();

    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> J0Coeffs =  Vector<double>( {-0.177597,0.327579,0.0560405,-0.0561487,-0.00170739,0.00252021,0.0000112022,-0.000053795,2.1333e-7,6.7811e-7,-4.88572e-9,-5.6642e-9,4.80096e-11,3.37094e-11,-2.99711e-13,-1.50298e-13,1.33856e-15,5.20979e-16,-4.54744e-18,-1.44449e-18})  );
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `r` as 101 points over the interval [0,10]: ");
    CR();
    
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> r = linspace<double>(0,10,101)  );
    GMD_CODE_END();
    CR();

    OUTPUT("Calculate the Maclaurin series and store the results in vector `y`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO_CODE( Vector<double> y = maclaurin(J0Coeffs, r, 19, 5.)  );
    GMD_CODE_END();
    CR();

    
    OUTPUT("The results `r` and `y` are:");
    CR();
    GMD_CODE_START("Mathematica");
    DISP(r);
    DISP(y);
    GMD_CODE_END();

    OUTPUT("Cut and paste the above data for r and y into Mathematica as well as the following commands");
    CR();
    GMD_CODE_START("Mathematica");
    OUTPUT("p1=ListPlot[Partition[Riffle[r,y],2],PlotStyle->Red];");
    OUTPUT("p2=Plot[BesselJ[0,r],{r,0,10}];");
    OUTPUT("Show[p1,p2]");
    GMD_CODE_END();

    OUTPUT("This yields the following plot comparing the Maclaurin series [red dots] to the exact function [solid blue].");

    OUTPUT("![Maclaurin Series for Jo(x)](BesselMaclaurinSeries.png)");

  }
  mathq_toc();
  
  return 0;
}
