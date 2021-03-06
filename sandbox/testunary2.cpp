
//#define MATHQ_DEBUG

#include "mathq.h" 

#include <fstream>





int main(int argc, char *argv[])
{

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = createStyle(BOLD);
  Style blue = createStyle(BOLD+BLUE2);
  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;

  
  mout<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  
  print_mathq_info();



  
 


  cr();
  mout << StyledString::get(HORLINE);cr();
  //------------------------------------------------------

  cr();
  cr();
  mout << bold.apply("Scalar") << endl;
  {
    cr();
    Scalar<double> s = 1.1;
    tdisp(s);
    tdisp((-s)[0]);
  }

  
  cr();
  cr();
  mout << bold.apply("Vector") << endl;
  {
    cr();
    Vector<double> v {1.1,2.2};
    tdisp(v);
    tdisp((-v)[1]);
  }

  cr();
  cr();
  mout << bold.apply("Matrix") << endl;
  {
    Matrix<double> m {{1,2},{3,4}};
    tdisp(m);
    tdisp((-m)[2]);
  }



  cr();
  cr();
  mout << bold.apply("Tensor") << endl;
  {
    cr();
    Tensor<double,3> t {
      {{0, 1, 2, 3, 4},{10, 11, 12, 13, 14}},
    	{{100, 101, 102, 103, 104},{110, 111, 112, 113, 114}},
    	  {{200, 201, 202, 203, 204},{210, 211, 212, 213, 214}  } };
    
    tdisp(t);
    tdisp((-t)[5]);
  }



  cr();
  cr();
  cr();
  cr();


  mout << blue.apply("Two-level tests") << endl;
  

  // -------------------------------------------------
  // two level tests
  // -------------------------------------------------

  cr();
  cr();
  mout << bold.apply("Two-Level Scalar tests") << endl;

  {
    cr();
    Scalar<Scalar<double>> s {{1.1}};
    tdisp(s);
    tdisp((-s)[0]);
  }
  {
    cr();
    Scalar<Vector<double>> s {{1.,2.,3.}};
    tdisp(s);
    tdisp((-s)[0]);  
  }
  {   
    cr();
    Scalar<Matrix<double>> s {{{1,2},{3,4}}};
    tdisp(s);
    tdisp((-s)[0]);  

  }

  {   
    cr();
    Scalar<Tensor<double,2>> s {{{1,2},{3,4}}};
    tdisp(s);
    tdisp((-s)[0]);  
  }

  cr();
  cr();
  mout << bold.apply("Two-Level Vector tests") << endl;
  {
    cr();
    Vector<Scalar<double>> v {{1.},{2.}};
    tdisp(v);
    tdisp((-v)[1]);
  }

  {
    cr();
    Vector<Vector<double>> v {{1.,2.,3.},{4.,5.,6.}};
    tdisp(v);
    tdisp((-v)[1]);
  }
  {
    cr();
    Vector<Matrix<double>> v { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
    tdisp(v);
    tdisp((-v)[1]);
  }
  {
    cr();
    Vector<Tensor<double,2>> v { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
    tdisp(v);
    tdisp((-v)[1]);
  }


  cr();
  cr();
  mout << bold.apply("Two-Level Matrix tests") << endl;
  {
    cr();
    Matrix<Scalar<double>> m {{{1},{2}},{{3},{4}}};;
    tdisp(m);
    tdisp((-m)[2]);
  }

  {
    cr();
    Matrix<Vector<double>> m {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    tdisp(m);
    tdisp((-m)[2]);
  }

  {
    cr();
    Matrix<Matrix<double>> m  {
      { {{1,2},{3,4}}, {{5,6},{7,8}} },
	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
    };
    tdisp(m);
    tdisp((-m)[2]);
  }

  {
    cr();
    Matrix<Tensor<double,3>,2,2> m { {
	{
	  {
	    {-0, -1},
	      {-10, -11},
		{-20, -21}
	  },
	    {
	      {-100, -101},
		{-110, -111},
		  {-120, -121}
	    }
	}, 
	  {
	    {
	      {-1000, -1001},
		{-1010, -1011},
		  {-1020, -1021}
	    },
	      {
		{-1100, -1101},
		  {-1110, -1111},
		    {-1120, -1121}
	      }
	  }}, {
	{
	  {
	    {-10000, -10001},
	      {-10010, -10011},
		{-10020, -10021}
	  },
	    {
	      {-10100, -10101},
		{-10110, -10111},
		  {-10120, -10121}
	    }
	}, 
	  {
	    {
	      {-11000, -11001},
		{-11010, -11011},
		  {-11020, -11021}
	    },
	      {
		{-11100, -11101},
		  {-11110, -11111},
		    {-11120, -11121}
	      }
	  }} };

    tdisp(m);
    tdisp((-m)[1]);
    
  }

  /////////////////////////////////////////////////////////////////


  
  cr();
  cr();
  mout << bold.apply("Two-Level Tensor tests") << endl;
  {    
    cr();
    Tensor<Scalar<double>,2> t {{{1},{2}},{{3},{4}}};
    tdisp(t);
    tdisp((-t)[1]);
  }
  {
    cr();
    Tensor<Vector<double>,2> t {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    tdisp(t);
    tdisp((-t)[1]);
  }

  {
    cr();
    Tensor<Matrix<double,2,2>,2> t  {
      { {{1,2},{3,4}}, {{5,6},{7,8}} },
  	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
    };
    tdisp(t);
    tdisp((-t)[1]);
  }


  {
    cr();
    Tensor<Tensor<double,3>,2> t { {
  	{
  	  {
  	    {0, 1},
  	      {10, 11},
  		{20, 21}
  	  },
  	    {
  	      {100, 101},
  		{110, 111},
  		  {120, 121}
  	    }
  	}, 
  	  {
  	    {
  	      {1000, 1001},
  		{1010, 1011},
  		  {1020, 1021}
  	    },
  	      {
  		{1100, 1101},
  		  {1110, 1111},
  		    {1120, 1121}
  	      }
  	  }}, {
  	{
  	  {
  	    {10000, 10001},
  	      {10010, 10011},
  		{10020, 10021}
  	  },
  	    {
  	      {10100, 10101},
  		{10110, 10111},
  		  {10120, 10121}
  	    }
  	}, 
  	  {
  	    {
  	      {11000, 11001},
  		{11010, 11011},
  		  {11020, 11021}
  	    },
  	      {
  		{11100, 11101},
  		  {11110, 11111},
  		    {11120, 11121}
  	      }
  	  }} };

    tdisp(t);
    tdisp((-t)[1]);
    
  }

  


  
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
