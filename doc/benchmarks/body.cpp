#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>


#include "mathq.h"

int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  GMD_PREAMBLE();

  CR();
  CR();

  OUTPUT("");
  CR();
  GMD_HEADER2("Memory Usage");
  CR();

  GMD_HEADER3("Vectors");

  OUTPUT("| Type | Size<sup>1,2</sup> | Min<sup>1,3</sup> | Max<sup>1,4</sup> |");
  OUTPUT("| :--- | :---: | :---: | :---: | ");
  // note: need to cast numeric_limits<char>::min() as an int so that it gets printed as a number and not an ASCII charcter
  OUTPUT("| `char` | " << CHAR_BIT*sizeof(char) << " bits | " << int(numeric_limits<char>::min()) << " | " << int(numeric_limits<char>::max()) << " | ");
  OUTPUT("| `short` | " << CHAR_BIT*sizeof(short) << " bits | " << numeric_limits<short>::min() << " | " << numeric_limits<short>::max() << " | ");
  OUTPUT("| `int` | " << CHAR_BIT*sizeof(int) << " bits | " << numeric_limits<int>::min() << " | " << numeric_limits<int>::max() << " | ");
  OUTPUT("| `long` | " << CHAR_BIT*sizeof(long) << " bits | " << numeric_limits<long>::min() << " | " << numeric_limits<long>::max() << " | ");
  OUTPUT("| `long long` | " << CHAR_BIT*sizeof(long long) << " bits | " << numeric_limits<long long>::min() << " | " << numeric_limits<long long>::max() << " | ");



  GMD_VSPACE();
  GMD_HEADER2("Speed");

  GMD_HEADER3("vector function");

  OUTPUT("$f(x) = 10 x + e^{i \\, [  \\, 2 \\pi  \\, +  \\, \\pi sin( \\, 2 \\pi x + \\pi / 6 \\, )  \\, ] }$");

  {
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    ECHO(const std::complex<double> i(0, 1));
    ECHO(constexpr size_t N = 500000);
    CR();
    ECHO(std::valarray<double> x(N));
    ECHO(std::valarray<std::complex<double>> f(N));
    CR();
    ECHO(Timer timer);
    ECHO(timer.start_timer_silent());
    CR();
    ECHO(for (size_t k = 0; k < N; k++) {
      x[k] = double(k) / double(N - 1);
    });
    ECHO(for (size_t k = 0; k < N; k++) {
      f[k] = 10 * x[k] + exp(i * (2 * pi + pi * sin(2 * pi * x[k] + pi / 6)));
    });
    CR();
    SRDISP(" sec", timer.stop_timer());
    // ETV(x);
    // ETV(f);
    GMD_CODE_END();
  }



  {
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    ECHO(const Imaginary<double> i{ 1 });
    ECHO(constexpr size_t N = 500000);
    CR();
    ECHO(Vector<double> x(N));
    ECHO(Vector<std::complex<double>> f(N));
    CR();
    ECHO(Timer timer);
    ECHO(timer.start_timer_silent());
    CR();
    ECHO(x = linspace<double>(0, 1, N));
    ECHO(f = 10 * x + exp(i * (2 * pi + pi * sin(2 * pi * x + pi / 6))));
    CR();
    SRDISP(" sec", timer.stop_timer());
    // ETV(x);
    // ETV(f);

    GMD_CODE_END();
  }




  return 0;
}
