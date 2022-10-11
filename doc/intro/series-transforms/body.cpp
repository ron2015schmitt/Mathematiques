#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  OUTPUT("Mathématiques currently supports Taylor Series, Maclaurin Series, and Fourier Series.");
  CR();

  GMD_HEADER2("Taylor Series for the Bessel Function J<sub>0</sub>(r)");
  OUTPUT("We can easily calculate a [Taylor Series](http://mathworld.wolfram.com/TaylorSeries.html) in mathq. As an example, let's calculate the Taylor series for the [Bessel Function of the first kind](http://mathworld.wolfram.com/BesselFunctionoftheFirstKind.html) of order 0, J<sub>0</sub>(r). ");

  OUTPUT("The first 20 (n=0,1,...19) coefficients for  J<sub>0</sub>(r), are:\n");


  {
    set_mathematica_var_format();
    Vector<double> J0Coeffs = Vector<double>({ 1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0. });

    GMD_CODE_START("C++");
    EV(J0Coeffs);
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
    ECHO(using namespace display);
    ECHO(set_mathematica_var_format(););
    GMD_CODE_END();
    CR();



    OUTPUT("Define the Vector of coefficients: ");
    CR();

    GMD_CODE_START("C++");
    ECHO(Vector<double> J0Coeffs = Vector<double>({ 1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0. }));
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `r` as 101 points over the interval [0,10]: ");
    CR();

    GMD_CODE_START("C++");
    ECHO(Vector<double> r = linspace<double>(0, 10, 101));
    GMD_CODE_END();
    CR();

    OUTPUT("Calculate the Taylor series and store the results in vector `y`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO(Vector<double> y = taylor(J0Coeffs, r, 19));
    GMD_CODE_END();
    CR();


    OUTPUT("The results `r` and `y` are:");
    CR();
    GMD_CODE_START("Mathematica");
    EV(r);
    EV(y);
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
    Vector<double> J0Coeffs = Vector<double>({ -0.177597,0.327579,0.0560405,-0.0561487,-0.00170739,0.00252021,0.0000112022,-0.000053795,2.1333e-7,6.7811e-7,-4.88572e-9,-5.6642e-9,4.80096e-11,3.37094e-11,-2.99711e-13,-1.50298e-13,1.33856e-15,5.20979e-16,-4.54744e-18,-1.44449e-18 });

    GMD_CODE_START("C++");
    EV(J0Coeffs);
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
    ECHO(set_mathematica_var_format());
    GMD_CODE_END();
    CR();



    OUTPUT("Define the Vector of coefficients: ");
    CR();

    GMD_CODE_START("C++");
    ECHO(Vector<double> J0Coeffs = Vector<double>({ -0.177597,0.327579,0.0560405,-0.0561487,-0.00170739,0.00252021,0.0000112022,-0.000053795,2.1333e-7,6.7811e-7,-4.88572e-9,-5.6642e-9,4.80096e-11,3.37094e-11,-2.99711e-13,-1.50298e-13,1.33856e-15,5.20979e-16,-4.54744e-18,-1.44449e-18 }));
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `r` as 101 points over the interval [0,10]: ");
    CR();

    GMD_CODE_START("C++");
    ECHO(Vector<double> r = linspace<double>(0, 10, 101));
    GMD_CODE_END();
    CR();

    OUTPUT("Calculate the Maclaurin series and store the results in vector `y`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO(Vector<double> y = maclaurin(J0Coeffs, r, 19, 5.));
    GMD_CODE_END();
    CR();


    OUTPUT("The results `r` and `y` are:");
    CR();
    GMD_CODE_START("Mathematica");
    EV(r);
    EV(y);
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


  OUTPUT("Calculating a function via Fourier series and plotting the results in Matlab");

  GMD_HEADER2("Fourier Series for the Clausen Functions");
  OUTPUT("As our example, we'll use the [Clausen functions](http://mathworld.wolfram.com/ClausenFunction.html). The Clausen function of order _n_ has Fourier series: ");
  CR();
  OUTPUT("$${\\text{Cl}}\\_n (x) \\equiv \\left\\\\{ \\begin{array}{ll}   S_n(x) = \\Sigma_{k=1}^{\\infty} {\\frac{\\sin(k x)}{k^n} }   & n \\enspace \\text{even} \\\\\\\\  C_n(x) = \\Sigma_{k=1}^{\\infty} \\frac{\\cos(k x)}{k^n}  & n \\enspace \\text{odd} \\end{array} \\right.$$");
  CR();


  GMD_HEADER3("Clausen function of order _n=1_");

  {
    CR();
    CR();
    OUTPUT("Set up the output format so that we can copy and paste into Matlab");
    GMD_CODE_START("C++");
    ECHO(using namespace display);
    ECHO(set_matlab_var_format());
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coefficient vectors: ");
    CR();


    GMD_CODE_START("C++");
    ECHO(const size_t N = 20);
    ECHO(Vector<double> k = range<double>(0, N-1));
    ECHO(Vector<double> An = 1/k);
    ECHO(An[0] = 0.);
    ECHO(Vector<double> Bn = Vector<double>(N, 0.));
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: ");
    CR();

    GMD_CODE_START("C++");
    ECHO(const double pi = M_PI);
    ECHO(Vector<double> t = linspace<double>(0, 2*pi, 51));
    GMD_CODE_END();
    CR();


    OUTPUT("Calculate the Fourier series and store the results in vector `CL1`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO(const double T = 2*pi);
    ECHO(const double omega = 2*pi/T);
    ECHO(Vector<double> CL1 = ifourier(An, Bn, t, An.size(), omega));
    GMD_CODE_END();
    CR();


    OUTPUT("The results `t` and `CL1` are:");
    CR();
    GMD_CODE_START("Matlab");
    EV(t);
    EV(CL1);
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
    OUTPUT("$$\\text{Cl}_1(x) = -\\ln \\left| 2 \\sin \\left(\\frac{1}{2} x\\right) \\right| $$");
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
    ECHO(set_matlab_var_format());
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coefficient vectors: ");
    CR();


    GMD_CODE_START("C++");
    ECHO(const size_t N = 20);
    ECHO(Vector<double> k = range<double>(0, N-1));
    ECHO(Vector<double> An = Vector<double>(N, 0.));
    ECHO(Vector<double> Bn = 1./sqr(k));
    ECHO(Bn[0] = 0.);
    GMD_CODE_END();
    CR();


    OUTPUT("Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: ");
    CR();

    GMD_CODE_START("C++");
    ECHO(const double pi = M_PI);
    ECHO(Vector<double> t = linspace<double>(0, 2*pi, 51));
    GMD_CODE_END();
    CR();


    OUTPUT("Calculate the Fourier series and store the results in vector `CL2`: ");
    CR();
    GMD_CODE_START("C++");
    ECHO(const double T = 2*pi);
    ECHO(const double omega = 2*pi/T);
    ECHO(Vector<double> CL2 = ifourier(An, Bn, t, An.size(), omega));
    GMD_CODE_END();
    CR();


    OUTPUT("The results `t` and `CL2` are:");
    CR();
    GMD_CODE_START("Matlab");
    EV(t);
    EV(CL2);
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
    OUTPUT("$${\\text{Cl}}\\_2 \\left(x\\right) = -\\int_{0}^{x} {\\ln \\left| 2 \\sin \\left(\\frac{1}{2} x\\right) \\right|} dt$$");
    CR();
    CR();

    OUTPUT("We exclude the end points, 0 and pi, because the integrand is infinite at these points.");
    OUTPUT("This yields the following plot comparing the Fourier series [red dots] to the exact function [solid blue].");


    OUTPUT("![Fourier Series for CL2(t)](ClausenFourierSeries_n2.png)");

  }


  return 0;
}
