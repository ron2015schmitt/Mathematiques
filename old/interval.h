//
  // Domain<GridElement>
  //

template <typename GridElement, typename Derived>
class
  Domain {
};



//
// Interval<Reals>
//
template <typename GridElement> requires(IsSimpleNumber<GridElement>)
class
  Interval : public Domain<GridElement, Interval<GridElement>> {
public:
  using Type = Interval<GridElement>;
  using ParentType = Domain<GridElement, Interval<GridElement>>;

  constexpr static bool is_uniform_spaced = true;

  size_t N;
  GridElement a;
  GridElement b;
  bool include_a;
  bool include_b;

private:
  size_t Neff;
  GridElement start;
  GridElement step;
  mathq::Vector<GridElement> grid_vector;

  Interval() noexcept :
    a(-std::numeric_limits<GridElement>::infinity()), b(std::numeric_limits<GridElement>::infinity()), N(0), include_a(true), include_b(true) {
    refresh();
  }

  Interval(const GridElement& a, const GridElement& b, const size_t N, const bool include_a = true, const bool include_b = true) noexcept :
    a(a), b(b), N(N), include_a(include_a), include_b(include_b) {
    refresh();
  }

  ~Interval() {
  }


  mathq::Vector<GridElement>& coord() {
    refresh();
    return grid_vector;
  }

  size_t size() const {
    return grid_vector.size();
  }

  mathq::Vector<GridElement>& refresh() {
    grid_vector.resize(N);
    init();
    return makeGrid();
  }

private:
  Type& init() {
    Neff = N +  size_t(!include_a) + size_t(!include_b);
    step = (b - a)/static_cast<GridElement>(Neff-1);
    if (include_a) {
      start = a;
    }
    else {
      start = a + step;
    }
    return *this;
  }

  mathq::Vector<GridElement>& makeGrid() {
    if (N == 0) return grid_vector;

    for (size_t c = 0; c<(N-1); c++) {
      grid_vector[c] = start + static_cast<GridElement>(c)*step;
    }
    if (include_b) {
      grid_vector[N-1] = b;
    }
    else {
      grid_vector[N-1] = b - step;
    }
    return grid_vector;
  }
public:


  //------------------------------------------------------------------------------------
  //
  // static "factory" methods
  //
  //------------------------------------------------------------------------------------

  // [a,b]
  inline static Type c_interval_c(const GridElement& a, const GridElement& b, const size_t N) {
    return Type(a, b, N, true, true);
  }
  inline static Type interval(const GridElement& a, const GridElement& b, const size_t N) {
    return c_interval_c(a, b, N);
  }

  // (a,b]
  static Type o_interval_c(const GridElement& a, const GridElement& b, const size_t N) {
    return Type(a, b, N, false, true);
  }

  // [a,b)
  static Type c_interval_o(const GridElement& a, const GridElement& b, const size_t N) {
    return Type(a, b, N, true, false);
  }

  // (a,b)
  static Type o_interval_o(const GridElement& a, const GridElement& b, const size_t N) {
    return Type(a, b, N, false, false);
  }



  static Type realLine(const bool include_a = true, const bool include_b = true) {
    GridElement a;
    if (include_a) {
      a = -std::numeric_limits<GridElement>::infinity();
    }
    else {
      a = std::numeric_limits<GridElement>::lowest();
    }
    GridElement b;
    if (include_b) {
      b = std::numeric_limits<GridElement>::infinity();
    }
    else {
      b = std::numeric_limits<GridElement>::max();
    }
    return Type(a, b, 0, include_a, include_b);
  }

  static Type realLineNeg(const bool include_a = true, const bool include_b = true) {
    GridElement a;
    if (include_a) {
      a = -std::numeric_limits<GridElement>::infinity();
    }
    else {
      a = std::numeric_limits<GridElement>::lowest();
    }
    GridElement b;
    if (include_b) {
      b = 0;
    }
    else {
      b = -std::numeric_limits<GridElement>::min();
    }
    return Type(a, b, 0, include_a, include_b);
  }

  static Type realLinePos(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
    GridElement a;
    if (include_a) {
      a = 0;
    }
    else {
      a = std::numeric_limits<GridElement>::min();
    }
    GridElement b;
    if (include_b) {
      b = std::numeric_limits<GridElement>::infinity();
    }
    else {
      b = std::numeric_limits<GridElement>::max();
    }
    return Type(a, b, 0, include_a, include_b);
  }



  inline std::string classname() const {
    return ClassName();
  }

  static inline std::string ClassName() {
    using namespace display;
    std::string s = "Interval";
    s += StyledString::get(ANGLE1).get();
    GridElement d;
    s += getTypeName(d);
    s += StyledString::get(ANGLE2).get();
    return s;
  }


  inline friend std::ostream& operator<<(std::ostream& stream, const Type& var) {
    using namespace display;
    stream << "{";
    stream << "interval=";
    if (var.include_a) {
      stream << "[";
    }
    else {
      stream << "(";
    }
    dispval_strm(stream, var.a);
    stream << ", ";
    dispval_strm(stream, var.b);
    if (var.include_a) {
      stream << "]";
    }
    else {
      stream << ")";
    }
    stream << ", N=";
    dispval_strm(stream, var.N);


    // stream << ", gridState=";
    // dispval_strm(stream, (var.grid_vector.size() == 0) ? "deflated" : "inflated");
    stream << "}";
    return stream;
  }


};
