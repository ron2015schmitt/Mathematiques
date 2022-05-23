#include <fstream>

//#define MATHQ_DEBUG
#include "mathq.h"

bool printCPUInfo() {
  using namespace std;
  ifstream file;
  file.open("/proc/cpuinfo", ifstream::in);

  if (!file.is_open()) {
    return false;
  }

  string label, value;
  map<string, string> mymap;
  while (std::getline(file, label, ':') && std::getline(file, value)) {
    if (label.find("model name") != std::string::npos) {
      mymap[label] = value;
    }
    else if (label.find("cpu MHz") != std::string::npos) {
      mymap[label] = value;
    }
    else if (label.find("cache size") != std::string::npos) {
      mymap[label] = value;
    }
  }
  file.close();

  map<string, string>::iterator it = mymap.begin();
  while (it != mymap.end()) {
    MOUT << it->first << "=" << it->second << std::endl;
    it++;
  }

  return true;
}

bool printMemInfo() {
  using namespace std;
  ifstream file;
  file.open("/proc/meminfo", ifstream::in);

  if (!file.is_open()) {
    return false;
  }

  string label, value;
  map<string, string> mymap;
  while (std::getline(file, label, ':') && std::getline(file, value)) {
    if (label.find("MemTotal") != std::string::npos) {
      mymap[label] = value;
    }
  }
  file.close();

  map<string, string>::iterator it = mymap.begin();
  while (it != mymap.end()) {
    MOUT << it->first << "=" << it->second << std::endl;
    it++;
  }

  return true;
}

int main() {

  using namespace mathq;
  using namespace display;

  print_mathq_info();

  MOUT << CREATESTYLE(BLUE2 + BOLD).apply("MACHINE INFO") << std::endl;
  printCPUInfo();
  printMemInfo();
  MOUT << StyledString::get(HORLINE);
  CR();

  Timer tfull, t;

  tfull.start_timer_verbose();
  CR();

  const int N = 2000000;
  const double pi = M_PI;

  MOUT << "" << CREATESTYLE(BOLD).apply("Fill with a constant value") << ", N=" << N << std::endl;

  // In these two cases, storgae is reserved and filled at compile time,
  // so it doesn;t make sense to test. There is nothing to test.
  // {
  //   MOUT << "  " << CREATESTYLE(BLUE2+BOLD).apply("double[N]") <<std::endl;
  //   double tdata[N];
  //   t.start_timer_silent();
  //   for(int i=0; i<N; i++)
  //     tdata[i] = 3.14;
  //   t.stop_timer_curt();
  // }
  // {
  //   MOUT << "  " << CREATESTYLE(BLUE2+BOLD).apply("std::array")<<std::endl;
  //   std::array<double,N> v;
  //   t.start_timer_silent();
  //   for(int i=0; i<N; i++)
  //     v[i] = 3.14;
  //   t.stop_timer_curt();
  // }

  {
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("new double[N]") << std::endl;
    double* temp1 = new double[N];
    t.start_timer_silent();
    for (int i = 0; i < N; i++)
      temp1[i] = 3.14;
    t.stop_timer_curt();
  }
  {
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("std::vector") << std::endl;
    std::vector<double> vstl(N);
    t.start_timer_silent();
    for (int i = 0; i < N; i++)
      vstl[i] = 3.14;
    t.stop_timer_curt();
  }
  {
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("std::valarray") << std::endl;
    std::valarray<double> v(N);
    t.start_timer_silent();
    for (int i = 0; i < N; i++)
      v[i] = 3.14;
    t.stop_timer_curt();
  }
  {
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("mathq::Vector") << std::endl;
    Vector<double> v1(N);
    t.start_timer_silent();
    for (int i = 0; i < N; i++)
      v1[i] = 3.14;
    t.stop_timer_curt();
  }

  CR();
  MOUT << "" << CREATESTYLE(BOLD).apply("cos(2*pi + pi*sin(2*pi*x + pi/6))") << ", N=" << N << std::endl;

  {
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("std::valarray") << std::endl;
    std::valarray<double> x(N);
    for (int i = 0; i < N; i++)
      x[i] = double(i) / double(N - 1);
    std::valarray<double> f(N);
    t.start_timer_silent();
    for (int i = 0; i < N; i++)
      f[i] = cos(2 * pi + pi * sin(2 * pi * x[i] + pi / 6));
    t.stop_timer_curt();
  }
  {
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("mathq::Vector") << std::endl;
    Vector<double> x(N);
    Vector<double> f(N);
    x = linspace<double>(0, 1, N);
    t.start_timer_silent();
    f = cos(2 * pi + pi * sin(2 * pi * x + pi / 6));
    t.stop_timer_curt();
  }

  CR();
  MOUT << "" << CREATESTYLE(BOLD).apply("complex numbers: sin(2*log10(abs(x/5)*100) + 3 + pow(-x,2))") << ", N=" << N << std::endl;
  {
    // int N = 5;
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("std::valarray") << std::endl;
    t.start_timer_silent();

    std::valarray<double> x1(N);
    for (int i = 0; i < N; i++)
      x1[i] = double(i) / double(N - 1);
    std::valarray<double> x2(N);
    for (int i = 0; i < N; i++)
      x2[i] = double(2 * i - N + 1) / double(N - 1);
    std::valarray<ComplexDouble> x(N);
    for (int i = 0; i < N; i++) {
      x[i] = *(new ComplexDouble(x1[i], x2[i]));
    }
    std::valarray<ComplexDouble> f(N);
    for (int i = 0; i < N; i++) {
      f[i] = sin(2 * log10(abs(x[i] / 5) * 100) + 3 + pow(-x[i], 2));
    }

    t.stop_timer_curt();
    // TLDISP(f);
  }
  {
    // int N = 5;
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("mathq::Vector") << std::endl;
    t.start_timer_silent();

    Vector<ComplexDouble> x(N);
    Vector<ComplexDouble> f(N);
    x = Complex(linspace<double>(0, 1, N), linspace<double>(-1, 1, N));
    f = sin(2 * log10(abs(x / 5) * 100) + 3 + pow(-x, 2));

    t.stop_timer_curt();
    // TLDISP(f);
  }

  tfull.stop_timer_silent();
  CR();
  printf("TOTAL TIME ELAPSED (including text display) = %f sec\n", tfull.cputime());
  CR();
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
