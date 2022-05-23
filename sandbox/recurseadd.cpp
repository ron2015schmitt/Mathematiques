#include <fstream>

#define MATHQ_DEBUG 0
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
    } else if (label.find("cpu MHz") != std::string::npos) {
      mymap[label] = value;
    } else if (label.find("cache size") != std::string::npos) {
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





int main(int argc, char *argv[]) {

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = CREATESTYLE(BOLD);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();



  Timer tfull, t;

  tfull.start_timer_verbose();
  CR();



  {
    CR();
    const int N1 = 5;
    const int N2 = 3;
    MOUT << "" << CREATESTYLE(BOLD).apply("Vector<Vector<double>> + Vector<Vector<double>>") << ", N1=" << N1 << ", N2=" << N2 << std::endl;

    Vector<Vector<double>> v1(N1);
    Vector<Vector<double>> v2(N1);
    Vector<Vector<double>> v3(N1);
    Vector<Vector<double>> v4(N1);
    for (int i = 0; i < N1; i++) {
      v1[i].resize(N2);
      v1[i][0] = 1.1;
      v1[i][1] = 2.2;
      v1[i][2] = 3.3;
      v2[i].resize(N2);
      v2[i][0] = 10;
      v2[i][1] = 20;
      v2[i][2] = 30;
      v3[i].resize(N2);
      v4[i].resize(N2);
    }
    TLDISP(v1);
    TLDISP(v2);

    MOUT << "Deep add (v1+v2)" << std::endl;
    t.start_timer_silent();
    v3 = v1 + v2;
    t.stop_timer_curt();
    TLDISP(v3);
  }

  // two-level recurse std::vector
  {
    using namespace std;
    CR();
    const int N1 = 2;
    const int N2 = 3;
    const int N3 = 2;
    MOUT << "" << CREATESTYLE(BOLD).apply("vector<vector<vector<double>>> + vector<vector<vector<double>>>") << ", N1=" << N1 << ", N2=" << N2 << ", N3=" << N3 << std::endl;

    CR();
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("vector<vector<double>> x") << std::endl;
    vector<vector<double>> x{{.1, .2}, {.3, .4}, {.5, .6}};
    TLDISP(x);
    TLDISP((void *)&x);
    for (int i = 0; i < x.size(); i++) {
      TLDISP((void *)&(x[i]));
    }


    CR();
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("vector<vector<vector<double>>> v1") << std::endl;
    vector<vector<vector<double>>> v1{{{.1, .2}, {.3, .4}, {.5, .6}}, {{.7, .8}, {.9, 1.0}, {1.1, 1.2}}};
    TLDISP(v1);
  }


  // two-level recurse
  {
    CR();
    CR();
    CR();
    const int N1 = 2;
    const int N2 = 3;
    const int N3 = 2;
    MOUT << "" << CREATESTYLE(BOLD).apply("Vector<Vector<Vector<double>>> + Vector<Vector<Vector<double>>>") << ", N1=" << N1 << ", N2=" << N2 << ", N3=" << N3 << std::endl;

    CR();
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("Vector<Vector<double>> x") << std::endl;
    Vector<Vector<double>> x{{.1, .2}, {.3, .4}, {.5, .6}};
    TLDISP(x);
    TLDISP((void *)&x);
    for (int i = 0; i < x.size(); i++) {
      TLDISP((void *)&(x[i]));
    }


    CR();
    MOUT << "  " << CREATESTYLE(BLUE2 + BOLD).apply("Vector<Vector<Vector<double>>> v1") << std::endl;
    Vector<Vector<Vector<double>>> v1{{{.1, .2}, {.3, .4}, {.5, .6}}, {{.7, .8}, {.9, 1.0}, {1.1, 1.2}}};
    TLDISP(v1);

    Vector<Vector<Vector<double>>> v2{{{100., 200.}, {300., 400.}, {500., 600.}}, {{700., 800.}, {900., 1000.}, {1100., 1200.}}};
    Vector<Vector<Vector<double>>> v3(N1);
    Vector<Vector<Vector<double>>> v4(N1);
    for (int i = 0; i < N1; i++) {
      v3[i].resize(N2);
      v4[i].resize(N2);
      for (int j = 0; j < N2; j++) {
        v3[i][j].resize(N3);
        v4[i][j].resize(N3);
      }
    }
    TLDISP(v1);
    TLDISP(v2);

    MOUT << "Deep add (v1+v2)" << std::endl;
    t.start_timer_silent();
    v3 = v1 + v2;
    t.stop_timer_curt();
    TLDISP(v3);

    CR();
    decltype(v3)::EType e;
    decltype(v3)::DType d;
    TLDISP(e);
    TLDISP(d);
    TLDISP(decltype(v3)::Rvalue);
    TLDISP(decltype(v3)::Mvalue);
  }




  // add vector to each element
  {
    CR();
    CR();
    CR();
    const int N1 = 2;
    const int N2 = 3;
    MOUT << "" << CREATESTYLE(BOLD).apply("Vector<Vector<double>> + Vector<double>") << ", N1=" << N1 << ", N2=" << N2 << std::endl;

    CR();
    Vector<Vector<double>> pairs{{.1, .2}, {.3, .4}, {.5, .6}};
    TLDISP(pairs);
    Vector<double> origin{10., 20.};
    TLDISP(origin);
    Vector<Vector<double>> v3{{0, 0}, {0, 0}, {0, 0}};
    TLDISP(v3);


    t.start_timer_silent();
    v3 = pairs + origin;
    t.stop_timer_curt();
    TLDISP(v3);


    MOUT << "" << CREATESTYLE(BOLD).apply("Vector<double> + Vector<Vector<double>>") << ", N1=" << N1 << ", N2=" << N2 << std::endl;
    v3 = {{0, 0}, {0, 0}, {0, 0}};
    TLDISP(v3);
    t.start_timer_silent();
    v3 = origin + pairs;
    t.stop_timer_curt();
    TLDISP(v3);
  }


  tfull.stop_timer_silent();
  CR();
  printf("TOTAL TIME ELAPSED (including text display) = %f sec\n", tfull.cputime());
  CR();
  MOUT << StyledString::get(HORLINE);
  CR();
  //------------------------------------------------------

  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
