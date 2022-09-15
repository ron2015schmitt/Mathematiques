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

  GMD_HEADER3("Complicated Mathematical function of a Vector");
  CR();

  OUTPUT("$f(x) = 10 x + e^{i  [   2 \\pi   +   \\pi sin(  2 \\pi x + \\pi / 6  )   ] }$");
  CR();

  OUTPUT("**Hand-coded C**");
  {

    GMD_CODE_START("C++");

    // code enclosed in ECHO_MULTI gets executed en bloc after the printing. ";'\n';" gets replaced with a carriage retunr
    ECHO_MULTI(;'\n';
    using namespace std::numbers;;'\n';
    const std::complex<double> i(0, 1);;'\n';
    constexpr size_t N = 500000;;'\n';
    std::valarray<double> x(N);;'\n';
    std::valarray<std::complex<double>> f(N);;'\n';
    Timer timer;;'\n';
    ;'\n';
    timer.start_timer_silent();;'\n';
    for (size_t k = 0; k < N; k++) {
      ;'\n';
      ;' ';x[k] = double(k) / double(N - 1);;'\n';
    };'\n';
    for (size_t k = 0; k < N; k++) {
      ;'\n';
      ;' ';f[k] = 10 * x[k] + exp(i * (2 * pi + pi * sin(2 * pi * x[k] + pi / 6)));;'\n';
    };'\n';
    double elapsed = timer.stop_timer();;'\n';
    );

    CR();
    SRDISP(" sec", elapsed);
    // ETV(x);
    // ETV(f);
    GMD_CODE_END();
  }

  CR();


  OUTPUT("**Mathématiques**");
  {

    GMD_CODE_START("C++");

    // code enclosed in ECHO_MULTI gets executed en bloc after the printing. ";'\n';" gets replaced with a carriage retunr
    ECHO_MULTI(;'\n';
    using namespace std::numbers;;'\n';
    const Imaginary<double> i{ 1 };;'\n';
    constexpr size_t N = 500000;;'\n';
    Vector<double> x(N);;'\n';
    Vector<std::complex<double>> f(N);;'\n';
    Timer timer;;'\n';
    ;'\n';
    timer.start_timer_silent();;'\n';
    x = linspace<double>(0, 1, N);;'\n';
    f = 10 * x + exp(i * (2 * pi + pi * sin(2 * pi * x + pi / 6)));;'\n';
    double elapsed = timer.stop_timer();;'\n';
    );

    CR();
    SRDISP(" sec", elapsed);
    // ETV(x);
    // ETV(f);
    GMD_CODE_END();
  }


  GMD_VSPACE();
  GMD_HEADER3("Matrix Multiply");
  CR();

  OUTPUT("$\\mathbf{y} = \\mathbf{A} \\cdot \\mathbf{x}$");
  CR();

  OUTPUT("**Hand-coded C**");
  {
    GMD_CODE_START("C++");

    // code enclosed in ECHO_MULTI gets executed en bloc after the printing. ";'\n';" gets replaced with a carriage retunrn
    ECHO_MULTI(;'\n';
    using namespace std::numbers;;'\n';
    const std::complex<double> i(0, 1);;'\n';
    constexpr size_t N = 1000;;'\n';
    std::valarray<double> x(N);;'\n';
    std::valarray<double> y(N);;'\n';
    std::valarray<double> A(N*N);;'\n';
    Timer timer;;'\n';
    ;'\n';
    timer.start_timer_silent();;'\n';
    for (size_t k = 0; k < N; k++) {
      ;'\n';
      ;' ';x[k] = double(k) / double(N - 1);;'\n';
    };'\n';
    for (size_t k = 0; k < N*N; k++) {
      ;'\n';
      ;' ';A[k] = sin(double(k)*pi/double(N*N));;'\n';
    };'\n';
    size_t step = 0;;'\n';
    for (size_t r = 0; r < N; r++) {
      ;'\n';
      ;' ';y[r] = 0;;'\n';
      ;' ';for (size_t c = 0; c < N; c++) {
        ;'\n';
        ;' ';;' ';y[r] += A[step++] * x[c];;'\n';
        ;' ';
      };'\n';
    };'\n';
    double elapsed = timer.stop_timer();;'\n';
    );

    CR();
    SRDISP(" sec", elapsed);
    // ETV(x);
    // ETV(A);
    // ETV(y);  
    GMD_CODE_END();
  }

  CR();

  OUTPUT("**Mathématiques**");
  {
    GMD_CODE_START("C++");

    // code enclosed in ECHO_MULTI gets executed en bloc after the printing. ";'\n';" gets replaced with a carriage retunr
    ECHO_MULTI(;'\n';
    using namespace std::numbers;;'\n';
    const Imaginary<double> i{ 1 };;'\n';
    constexpr size_t N = 1000;;'\n';
    Vector<double> x(N);;'\n';
    Vector<double> y(N);;'\n';
    Matrix<double> A(N, N);;'\n';
    Timer timer;;'\n';
    ;'\n';
    timer.start_timer_silent();;'\n';
    x = linspace<double>(0, 1, N);;'\n';
    for (size_t k = 0; k < N*N; k++) {
      ;'\n';
      ;' ';A[k] = sin(double(k)*pi/double(N*N));;'\n';
    };'\n';
    y = A | x;;'\n';
    double elapsed = timer.stop_timer();;'\n';
    );

    CR();
    SRDISP(" sec", elapsed);
    // ETV(x);
    // ETV(A);
    // ETV(y);
    GMD_CODE_END();
  }

  CR();


  return 0;
}
