#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>
#include <variant>
#include <cmath>
#include "mathq.h"

inline double fradius2(double x, double y) { return  std::sqrt(x*x + y*y); }
inline double fradius3d_2(double x, double y, double z) { return  std::sqrt(x*x + y*y + z*z); }


template <class D = double, bool LOGSCALE = false>
class
  RealSet {
public:
  size_t N;
  D a;
  D b;
  bool include_a;
  bool include_b;
  bool logscale = LOGSCALE;

  // dependent variables
  // move to private
  D log_a;
  D log_b;
  size_t Neff;
  D start;
  D step;
  mathq::Vector<D> grid;

  RealSet() noexcept {
    include_a = true;
    a = -std::numeric_limits<D>::infinity();
    include_b = true;
    b = std::numeric_limits<D>::infinity();
    N = 0;
    this->init();
  }
  RealSet(const D& a, const D& b, const size_t N, const bool include_a = true, const bool include_b = true) noexcept :
    a(a), b(b), N(N), include_a(include_a), include_b(include_b) {
    this->init();
  }
  ~RealSet() {
  }

  void deflateGrid() {
    grid.resize(0);
  }
  void inflateGrid() {
    grid.resize(N);
  }
  bool hasInflatedGrid() {
    return grid.size() > 0;
  }


  RealSet& init() {
    Neff = N +  size_t(!include_a) + size_t(!include_b);
    if constexpr (LOGSCALE) {
      log_a = std::log10(a);
      log_b = std::log10(b);
      step = (log_b - log_a)/static_cast<D>(Neff-1);
      if (include_a) {
        start = log_a;
      }
      else {
        start = log_a + step;
      }
    }
    else {
      step = (b - a)/static_cast<D>(Neff-1);
      if (include_a) {
        start = a;
      }
      else {
        start = a + step;
      }
    }
    return *this;
  }


  const D getGridPoint(size_t c) const {
    if constexpr (LOGSCALE) {
      return getGridPoint_Log(c);
    }
    else {
      return getGridPoint_Linear(c);
    }
  }

  const D getGridPoint_Linear(size_t c) const {
    if (N == 0) return std::numeric_limits<D>::quiet_NaN();

    if (c == N-1) {
      if (include_b) {
        return b;
      }
      else {
        return b - step;
      }
    }
    return start + static_cast<D>(c)*step;
  }

  const D getGridPoint_Log(size_t c) const {
    if (N == 0) return std::numeric_limits<D>::quiet_NaN();

    if (c == N-1) {
      if (include_b) {
        return b;
      }
      else {
        return pow(10, log_b - step);
      }
    }
    return pow(10, log_a + static_cast<D>(c)*step);
  }


  mathq::Vector<D>& makeGrid() {
    if constexpr (LOGSCALE) {
      return makeGrid_Log();
    }
    else {
      return makeGrid_Linear();
    }
  }


  mathq::Vector<D>& makeGrid_Linear() {
    inflateGrid();
    init();
    if (N == 0) return grid;

    for (size_t c = 0; c<(N-1); c++) {
      grid[c] = start + static_cast<D>(c)*step;
    }
    if (include_b) {
      grid[N-1] = b;
    }
    else {
      grid[N-1] = b - step;
    }
    return grid;
  }


  mathq::Vector<D>& makeGrid_Log() {
    inflateGrid();
    init();
    if (N == 0) return grid;

    for (size_t c = 0; c<(N-1); c++) {
      grid[c] = std::pow(10, start + static_cast<D>(c)*step);
    }
    if (include_b) {
      grid[N-1] = b;
    }
    else {
      grid[N-1] = std::pow(10, log_b - step);
    }
    return grid;
  }


  static RealSet<D> emptySet() {
    return RealSet<D>(0, 0, 0, 0, false, false);
  }

  static RealSet<D> point(const D& p) {
    return RealSet<D>(p, p, 1, 0, true, true);
  }


  static RealSet<D> realLine(const bool include_a = true, const bool include_b = true) {
    D a;
    if (include_a) {
      a = -std::numeric_limits<D>::infinity();
    }
    else {
      a = std::numeric_limits<D>::lowest();
    }
    D b;
    if (include_b) {
      b = std::numeric_limits<D>::infinity();
    }
    else {
      b = std::numeric_limits<D>::max();
    }
    return RealSet<D>(a, b, 0, include_a, include_b);
  }

  static RealSet<D> realLineNeg(const bool include_a = true, const bool include_b = true) {
    D a;
    if (include_a) {
      a = -std::numeric_limits<D>::infinity();
    }
    else {
      a = std::numeric_limits<D>::lowest();
    }
    D b;
    if (include_b) {
      b = 0;
    }
    else {
      b = -std::numeric_limits<D>::min();
    }
    return RealSet<D>(a, b, 0, include_a, include_b);
  }

  static RealSet<D> realLinePos(const bool include_a = true, const bool include_b = true) {
    D a;
    if (include_a) {
      a = 0;
    }
    else {
      a = std::numeric_limits<D>::min();
    }
    D b;
    if (include_b) {
      b = std::numeric_limits<D>::infinity();
    }
    else {
      b = std::numeric_limits<D>::max();
    }
    return RealSet<D>(a, b, 0, include_a, include_b);
  }

};





int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  using namespace mathq::unit_quaternion;
  using namespace mathq::unit_imaginary;

  using std::sqrt;

  GMD_HEADER2("Introduction");





  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER3("Grids, Functions, and Vector Calculus");

  CR();
  CR();


  // TODO: give in terms of the size of the data
  GMD_CODE_START("C++");
  CR();

  Nabla d1;
  TRDISP(d1);

  TargetSet<std::complex<double>> u(1, 0);
  TRDISP(u);

  ECHO_CODE(GridSet<double> gs);
  TRDISP(gs);

  ECHO_CODE(Interval<double> x_interval(-1, 1, 5));
  TRDISP(x_interval);

  RealSet<double>  rs(-2, +2, 5);
  TRDISP(rs.a);
  TRDISP(rs.b);
  TRDISP(rs.N);
  TRDISP(rs.logscale);
  TRDISP(rs.include_a);
  TRDISP(rs.include_b);
  TRDISP(rs.hasInflatedGrid());
  TRDISP(rs.makeGrid());
  TRDISP(rs.hasInflatedGrid());

  RealSet<double>  rs1(-2, +3, 5, true, false);
  TRDISP(rs1.a);
  TRDISP(rs1.b);
  TRDISP(rs1.N);
  TRDISP(rs1.logscale);
  TRDISP(rs1.include_a);
  TRDISP(rs1.include_b);
  TRDISP(rs1.hasInflatedGrid());
  TRDISP(rs1.makeGrid());
  TRDISP(rs1.hasInflatedGrid());


  TRDISP(std::numeric_limits<double>::lowest());
  ECHO_CODE(RealSet<double>  rs2 = RealSet<double>::realLine(10));
  TRDISP(rs2.a);
  TRDISP(rs2.N);

  ECHO_CODE(RealSet<double, true>  rs3(10, 1e5, 10));
  TRDISP(rs3.a);
  TRDISP(rs3.b);
  TRDISP(rs3.N);
  TRDISP(rs3.logscale);
  TRDISP(rs3.include_a);
  TRDISP(rs3.include_b);
  TRDISP(rs3.hasInflatedGrid());
  TRDISP(rs3.makeGrid());
  TRDISP(mathq::log10(rs3.makeGrid()));
  TRDISP(rs3.hasInflatedGrid());


  TRDISP(std::numeric_limits<double>::infinity()  > 1);

  // ECHO_CODE(Coordinate2<double, Interval> x_coord2("x", x_interval));
  // TRDISP(x_coord2.gridSet);
  // TRDISP(x_coord);
  // ECHO_CODE(Coordinate<double> y_coord("y"));
  // TRDISP(y_coord);

  // ECHO_CODE(Coordinates<double> xy_coords("xy",{x_coord, y_coord}) );
  // TRDISP(xy_coords);

  // ECHO_CODE(Coordinates<double> xy_coords2("xy",{"x","y"}) );
  // TRDISP(xy_coords2);




  // ECHO_CODE(Interval<double> y_interval("y", 0, 3, 4));
  // TRDISP(y_interval);


  // ECHO_CODE(auto gridX0 = x_interval.makeGrid());
  // TRDISP(x_interval);
  // TRDISP(gridX0);

  // Vector<double, 5> g;
  // for (size_type i = 0; i<5; i++) {
  //   g(i) = x_interval.get(i);
  // }
  // TRDISP(g);

  // auto gridX = grid(x_interval);
  // TRDISP(gridX);


  // ECHO_CODE(Region<double> xy_region("Cartesian-2D", { x_interval, y_interval }));
  // TRDISP(xy_region);
  // TRDISP(xy_region[0]);
  // TRDISP(xy_region["x"]);

  // ECHO_CODE(Region<double> domXY2({ Interval<double>(-10, 10, 5), Interval<double>(0, 7, 4) }));
  // TRDISP(domXY2);
  // Region<double> domXY3(domXY2);
  // TRDISP(domXY3);
  // // Region<double> domXY4(domXY2.domains);
  // // TRDISP(domXY4);


  // Interval<double> rz(10, 11, 2);
  // TRDISP(rz);


  // auto divX = grad(grid(x_interval), x_interval);
  // TRDISP(divX);
  // Interval<double> rx2(-10, 10, 21);
  // auto gridX2 = grid(rx2);
  // TRDISP(gridX2);
  // auto gradX2 = grad(gridX2, rx2);
  // TRDISP(gradX2);
  // auto gradX2_2 = nabla_old & pair(gridX2, rx2);
  // TRDISP(gradX2_2);

  // TRDISP(sqr(gridX + 2));
  // std::function<double(double)> func = [](double d) {  return mathq::sqr(d+2); };
  // TRDISP(func(-3));
  // TRDISP(fgrid(func, gridX));
  // double (*func2)(double) = &std::exp;
  // TRDISP(func2(1));
  // TRDISP(fgrid(func2, gridX));  // doesnt work
  // TRDISP(static_cast<double (*)(double)>(&std::exp)(1));
  // std::function<double(double)> func3 = static_cast<double (*)(double)>(&std::exp);
  // TRDISP(func3(1));
  // TRDISP(fgrid(func3, gridX));
  // std::function<double(double)> func4 = [](double d) {  return std::exp(d); };
  // TRDISP(func4(-3));
  // TRDISP(fgrid(func4, gridX));
  // CR();
  // TRDISP(y_interval);
  // TRDISP(grid(y_interval));
  // TRDISP(rz);
  // TRDISP(grid(rz));
  // auto gridXY = grid(x_interval, y_interval);
  // TRDISP(gridXY(0));
  // TRDISP(gridXY(1));


  // std::function<double(double, double)> fradius = [](double x, double y) {  return std::sqrt(x*x + y*y); };
  // auto R = fgrid(fradius, gridXY);
  // TRDISP(R);
  // auto R2 = fgrid(fradius2, gridXY);
  // TRDISP(R2);

  // auto gradXY = grad(R, x_interval, y_interval);
  // TRDISP(gradXY(0));
  // TRDISP(gradXY(1));
  // gradXY = nabla_old & std::make_tuple(R, x_interval, y_interval);
  // TRDISP(gradXY(0));
  // TRDISP(gradXY(1));


  // CR();
  // auto gridXYZ = grid(x_interval, y_interval, rz);
  // TRDISP(gridXYZ(0));
  // TRDISP(gridXYZ(1));
  // TRDISP(gridXYZ(2));
  // std::function<double(double, double, double)> fradius3d = [](double x, double y, double z) {  return std::sqrt(x*x + y*y + z*z); };
  // auto R3D = fgrid(fradius3d, gridXYZ);
  // TRDISP(R3D);
  // auto R3D_2 = fgrid(fradius3d_2, gridXYZ);
  // TRDISP(R3D_2);


  GMD_CODE_END();



  return 0;
}
