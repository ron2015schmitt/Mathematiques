#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>


#include "mathq.h"


std::string read_file(const std::string filename) {
  std::setlocale(LC_ALL, "");
  std::string fn = "benchmarks/" + filename;
  std::string s;
  std::ifstream fstrm(fn);

  if (!fstrm.is_open()) {
    std::cout << "failed to open " << fn << '\n';
  }
  else {
    char c;
    while (fstrm.get(c))          // loop getting single characters
      s += c;
  }

  return s;
}





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

  OUTPUT(CHAR_BIT*sizeof(char));



  GMD_VSPACE();
  GMD_HEADER2("Run-Time Performance");
  Timer timer;
  display::FormatData<double>::format_string = "%.0lf";

  OUTPUT("The following tests are run during each build. The Mathématiques code is usually faster than hand-coded C.  The tests are repeated `Nloop` times and then the results are averaged.");

  GMD_HEADER3("Test 1. Function of a Vector");
  CR();

  OUTPUT("$f(x) = 1 + 10 x + e^{i  [   2 \\pi   +   \\pi sin(  2 \\pi x + \\pi / 6  )   ] }$");
  CR();

  {
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    ECHO(size_t Nloop = 30);
    ECHO(constexpr size_t N = 10000);
    GMD_CODE_END();



    GMD_HEADER4("Results 1A. Hand-Coded C");
    {
      GMD_CODE_START("C++");
      std::cout << read_file("test1-hand-coded--vars.cpp");
      CR();
      std::cout << read_file("test1-hand-coded--code.cpp");
      GMD_CODE_END();

      double total = 0;
#include "test1-hand-coded--vars.cpp"
      for (size_t c = 0; c < Nloop; c++) {
        timer.start_timer_silent();
#include "test1-hand-coded--code.cpp"
        total += timer.stop_timer();
      }
      double elapsed_time = total/Nloop*1e6;
      SRDISP(" μsec", elapsed_time);
      CR();
      // ETV(x);
      // ETV(f);
    }


    CR();


    GMD_HEADER4("Results 1B. Mathématiques C");
    {
      GMD_CODE_START("C++");
      std::cout << read_file("test1-mathq--vars.cpp");
      CR();
      std::cout << read_file("test1-mathq--code.cpp");
      GMD_CODE_END();

      double total = 0;
#include "test1-mathq--vars.cpp"
      for (size_t c = 0; c < Nloop; c++) {
        timer.start_timer_silent();
#include "test1-mathq--code.cpp"
        total += timer.stop_timer();
      }
      double elapsed_time = total/Nloop*1e6;
      SRDISP(" μsec", elapsed_time);
      CR();
      // ETV(x);
      // ETV(f);
    }

  }

  GMD_VSPACE();
  GMD_HEADER3("Test 2. Matrix Multiply");
  CR();

  OUTPUT("$\\mathbf{y} = \\mathbf{A} \\cdot \\mathbf{x}$");
  {
    GMD_CODE_START("C++");
    ECHO(using namespace std::numbers);
    ECHO(size_t Nloop = 30);
    ECHO(constexpr size_t N = 500);
    GMD_CODE_END();

    GMD_HEADER4("Results 2A. Hand-Coded C");
    {
      GMD_CODE_START("C++");
      std::cout << read_file("test2-hand-coded--vars.cpp");
      CR();
      std::cout << read_file("test2-hand-coded--code.cpp");
      GMD_CODE_END();
      double total = 0;
#include "test2-hand-coded--vars.cpp"
      for (size_t c = 0; c < Nloop; c++) {
        timer.start_timer_silent();
#include "test2-hand-coded--code.cpp"
        total += timer.stop_timer();
      }
      double elapsed_time = total/Nloop*1e6;
      SRDISP(" μsec", elapsed_time);
      CR();
      // ETV(x);
      // ETV(f);
    }

    CR();

    GMD_HEADER4("Results 2B. Mathématiques C");
    {
      GMD_CODE_START("C++");
      std::cout << read_file("test2-mathq--vars.cpp");
      CR();
      std::cout << read_file("test2-mathq--code.cpp");
      GMD_CODE_END();

      double total = 0;
#include "test2-mathq--vars.cpp"
      for (size_t c = 0; c < Nloop; c++) {
        timer.start_timer_silent();
#include "test2-mathq--code.cpp"
        total += timer.stop_timer();
      }
      double elapsed_time = total/Nloop*1e6;
      SRDISP(" μsec", elapsed_time);
      CR();
      // ETV(x);
      // ETV(f);
    }

  }
  CR();


  return 0;
}
