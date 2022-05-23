## EXAMPLE CODE FILE: `example.cpp`

_Return to the [Code examples](README.md)_


This example creates a ramp vector and a sine wave vector and then calculates the
1. sum
1. dot product
1. mean
1. standard deviation

```C++

#include "mathq.h"


int main(int argc, char *argv[])
{
  const double pi = M_PI;
  std::string myname = argv[0];
  
  using namespace mathq;
  using namespace display;

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " <<CREATESTYLE(BOLD).apply(myname) << std::endl;

  
  MOUT<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  print_mathq_info();
  
  Vector<double> v1( linspace<double>(-1,1,21) );
  Vector<double> v2;
  v2 = 10*sin(pi/2*v1) + 10;

  DISP(v1);
  DISP(v2);
  DISP(v1+v2);

  // dot product
  DISP(v1|v2);

  const double N = double(v2.size());
  // mean
  double mu2 = sum(v2)/N;
  DISP(mu2);

  // std deviation
  double sigma2 = norm(v2-mu2)/sqrt(N-1);
  DISP(sigma2);

  CR();
  MOUT << "done: " << CREATESTYLE(BOLD).apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  
  return 0;
}
```

Compile the code and run the code using
```bash
g++ -I ~/mathq/include example.cpp -o example -L ~/mathq/lib -lmathq
./example
```


_Return to the [Code examples](README.md)_
