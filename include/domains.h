#ifndef MATHQ__DOMAINS
#define MATHQ__DOMAINS 1


namespace mathq {



  // ***************************************************************************
  //                                 Domains
  //
  // ***************************************************************************

  //
  // Interval
  //

  template <typename GridElement> requires(IsSimpleNumber<GridElement>)
    class
    Interval;

  template <typename GridElement>
  bool is_interval_test(Interval<GridElement> x) {
    return true;
  }

  template <class T>
  concept IsInterval = requires(T x) {
    is_interval_test(x);
  };

  //
  // PointSequence
  //

  template <typename GridElement> requires(IsSimpleNumber<GridElement>)
    class
    PointSequence;

  template <typename GridElement>
  bool is_point_sequence_test(PointSequence<GridElement> x) {
    return true;
  }

  template <class T>
  concept IsPointSequence = requires(T x) {
    is_point_sequence_test(x);
  };


  //
  // Region
  //

  template <typename GridElement> requires(IsComplex<GridElement>::value)
    class
    Region;


  template <typename GridElement>
  bool is_region_test(Region<GridElement> x) {
    return true;
  }

  template <class T>
  concept IsRegion = requires(T x) {
    is_region_test(x);
  };


  //
  // Mesh
  //
  // TODO: presence of Ndims implies that it can't be used in DomainWrapper
  //       num_dims will need to be set at compile time via constructor
  template <typename GridElement, size_t Ndims> requires(IsSimpleNumber<GridElement>)
    class Mesh {
    public:
      constexpr static size_t num_dims = Ndims;
  };


  template <typename GridElement, size_t Ndims>
  bool is_mesh_test(Mesh<GridElement, Ndims> x) {
    return true;
  }

  template <class T>
  concept IsMesh = requires(T x) {
    is_mesh_test(x);
  };


  //
  // IsDomain
  //

  template <class T>
  concept IsDomain = IsInterval<T> || IsPointSequence<T> || IsRegion<T> || IsMesh<T>;

  //
  // DomainWrapper
  //

  template <typename GridElement>
  using DomainWrapper = std::variant<Interval<GridElement>, PointSequence<GridElement>>;






  //
  // Interval
  //
  template <typename GridElement> requires(IsSimpleNumber<GridElement>)
    class
    Interval {
    public:
      using Type = Interval<GridElement>;
      using GridType = Vector<GridElement>;

      constexpr static size_t num_dims = 1;

      size_t N;
      GridElement a;
      GridElement b;
      bool include_a;
      bool include_b;

      bool uniform_spaced() {
        return true;
      }
      bool mesh() {
        return false;
      }


      Interval() noexcept :
        a(-std::numeric_limits<GridElement>::infinity()), b(std::numeric_limits<GridElement>::infinity()), N(0), include_a(true), include_b(true) {
        verify();
      }

      Interval(const GridElement& a, const GridElement& b, const size_t N, const bool include_a = true, const bool include_b = true) noexcept :
        a(a), b(b), N(N), include_a(include_a), include_b(include_b) {
        verify();
      }

      // note that copy constructor works but not operator= (hence we don;t define one)
      Interval(const Type& x) noexcept :
        a(x.a), b(x.b), N(x.N), include_a(x.include_a), include_b(x.include_b) {
        verify();
      }

      ~Interval() {
      }

      size_t num_elements() const {
        if (N == 0) return 0;
        return N +  size_t(!include_a) + size_t(!include_b);
      }
      size_t length() const {
        return b-a;
      }
      size_t start() const {
        return a;
      }
      size_t end() const {
        return b;
      }


      void verify() const {
        if (b < a) {
          // TODO: issue error
          OUTPUT("ERROR: b must be greate than a");
          MDISP(a, b);
        }
      }


      GridType& grid() const {
        GridType& grid = *(new GridType);
        if (N == 0) return grid;

        size_t Neff = num_elements();
        grid.resize(Neff);
        GridElement step = (b - a)/static_cast<GridElement>(Neff-1);
        GridElement start = (include_a) ? a : a + step;

        for (size_t c = 0; c<(N-1); c++) {
          grid[c] = start + static_cast<GridElement>(c)*step;
        }
        if (include_b) {
          grid[N-1] = b;
        }
        else {
          grid[N-1] = b - step;
        }

        return grid;
      }


      template <typename TargetElement, size_t... sizes>
      Vector<TargetElement, sizes...>& deriv(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>(), const bool periodic = false) const {
        f.deriv(a, b, n, nabla.Nwindow, periodic);
        return f;
      }


      //------------------------------------------------------------------------------------
      //
      // static "factory" methods
      //
      //------------------------------------------------------------------------------------

      // [a,b]
      inline static Interval<GridElement> c_interval_c(const GridElement& a, const GridElement& b, const size_t N) {
        return Interval<GridElement>(a, b, N, true, true);
      }
      inline static Interval<GridElement> interval(const GridElement& a, const GridElement& b, const size_t N) {
        return c_interval_c(a, b, N);
      }

      // (a,b]
      static Interval<GridElement> o_interval_c(const GridElement& a, const GridElement& b, const size_t N) {
        return Interval<GridElement>(a, b, N, false, true);
      }

      // [a,b)
      static Interval<GridElement> c_interval_o(const GridElement& a, const GridElement& b, const size_t N) {
        return Interval<GridElement>(a, b, N, true, false);
      }

      // (a,b)
      static Interval<GridElement> o_interval_o(const GridElement& a, const GridElement& b, const size_t N) {
        return Interval<GridElement>(a, b, N, false, false);
      }



      static Interval<GridElement> realLine(const bool include_a = true, const bool include_b = true) {
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
        return Interval<GridElement>(a, b, 0, include_a, include_b);
      }

      static Interval<GridElement> realLineNeg(const bool include_a = true, const bool include_b = true) {
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
        return Interval<GridElement>(a, b, 0, include_a, include_b);
      }

      static Interval<GridElement> realLinePos(const bool include_a = true, const bool include_b = true) {
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
        return Interval<GridElement>(a, b, 0, include_a, include_b);
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


      inline friend std::ostream& operator<<(std::ostream& stream, const Interval& var) {
        using namespace display;
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
        return stream;
      }

  };




  //
  // PointSequence
  //
  // construct from:
  // 1. A defined interval, a&b, but in log space. stored as a sequence of points
  // 2. A sequence of aribitrary points given in a vector
  template <typename GridElement> requires(IsSimpleNumber<GridElement>)
    class
    PointSequence {
    public:
      using Type = PointSequence<GridElement>;
      using GridType = Vector<GridElement>;

      constexpr static size_t num_dims = 1;


      GridType grid_data;

      PointSequence() : grid_data(*(new GridType())) {
      }

      PointSequence(const GridType& grid_in) : grid_data(grid_in) {
      }

      PointSequence(const Type& ps) : grid_data(ps.grid()) {
      }

      // PointSequence() noexcept :
      //   a(-std::numeric_limits<GridElement>::infinity()), b(std::numeric_limits<GridElement>::infinity()), N(0), include_a(true), include_b(true) {
      //   verify();
      // }

      // PointSequence(const GridElement& a, const GridElement& b, const size_t N, const bool include_a = true, const bool include_b = true) noexcept :
      //   a(a), b(b), N(N), include_a(include_a), include_b(include_b) {
      //   verify();
      // }

      // note that copy constructor works but not operator= (hence we don;t define one)
      // PointSequence(const Type& x) noexcept :
      //   a(x.a), b(x.b), N(x.N), include_a(x.include_a), include_b(x.include_b) {
      //   verify();
      // }

      ~PointSequence() {
      }

      size_t num_elements() const {
        return grid_data.size();
      }
      size_t length() const {
        return end()-start();
      }
      size_t start() const {
        return grid_data[0];
      }
      size_t end() const {
        return grid_data[num_elements()-1];
      }


      void verify() const {
        // TODO: check all points and sort if needed
        if (length() < 0) {
          // TODO: issue error
          OUTPUT("ERROR: points must be ordered");
          TRDISP(*this);
        }
      }


      GridType& grid() const {
        GridType& grid_copy = *(new GridType(grid_data));
        return grid_copy;
      }


      // TODO: need to use non-euiqspaced derivative

      template <typename TargetElement, size_t... sizes>
      Vector<TargetElement, sizes...>& deriv(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>(), const bool periodic = false) const {
        // f.deriv(grid_data, n, nabla.Nwindow, periodic);
        return f;
      }

      // Type& operator=(const Type& x) {
      //   return *this;
      // }



      operator DomainWrapper<GridElement>() const {
        DomainWrapper<GridElement> dw{ this };
        return dw;
      }

      //------------------------------------------------------------------------------------
      //
      // static "factory" methods
      //
      //------------------------------------------------------------------------------------

      // [a,b]
      inline static PointSequence<GridElement> c_interval_c(const GridElement& a, const GridElement& b, const size_t N) {
        return PointSequence<GridElement>(a, b, N, true, true);
      }

      inline std::string classname() const {
        return ClassName();
      }

      static inline std::string ClassName() {
        using namespace display;
        std::string s = "PointSequence";
        s += StyledString::get(ANGLE1).get();
        GridElement d;
        s += getTypeName(d);
        s += StyledString::get(ANGLE2).get();
        return s;
      }


      inline friend std::ostream& operator<<(std::ostream& stream, const PointSequence& var) {
        using namespace display;
        dispval_strm(stream, var.grid_data);
        return stream;
      }

  };




  // //
  // // LogInterval
  // //
  // template <typename GridElement> requires(IsSimpleNumber<GridElement>)
  //   class
  //   LogInterval : public Interval<GridElement> {

  //   public:
  //     using Type = Interval<GridElement>;
  //     size_t N;
  //     GridElement a;
  //     GridElement b;
  //     bool include_a;
  //     bool include_b;
  //     GridScaleEnum scale;

  //     // dependent variables
  //     // move to private

  //     GridElement log_a;
  //     GridElement log_b;
  //     size_t Neff;
  //     GridElement start;
  //     GridElement step;
  //     mathq::GridType grid_vector;

  //     Interval() noexcept {
  //       include_a = true;
  //       a = -std::numeric_limits<GridElement>::infinity();
  //       include_b = true;
  //       b = std::numeric_limits<GridElement>::infinity();
  //       N = 0;
  //       scale = GridScale::LINEAR;
  //       this->init();
  //     }
  //     Interval(const GridElement& a, const GridElement& b, const size_t N, const bool include_a = true, const bool include_b = true) noexcept :
  //       a(a), b(b), N(N), scale(scale), include_a(include_a), include_b(include_b) {
  //       refreshGrid();
  //     }
  //     ~Interval() {
  //     }

  //     void grid() override const {
  //       return mathq::GridType;
  //     }

  //     mathq::GridType& coord() {
  //       refreshGrid();
  //       return grid_vector;
  //     }
  //     mathq::GridType& refreshGrid() {
  //       grid_vector.resize(N);
  //       init();
  //       if (scale == GridScale::LOG) {
  //         return makeGrid_Log();
  //       }
  //       else {
  //         return makeGrid_Linear();
  //       }
  //     }

  //     size_t size() const {
  //       return grid_vector.size();
  //     }

  //   private:
  //     Interval& init() {
  //       Neff = N +  size_t(!include_a) + size_t(!include_b);
  //       if (scale == GridScale::LOG) {
  //         log_a = std::log10(a);
  //         log_b = std::log10(b);
  //         step = (log_b - log_a)/static_cast<GridElement>(Neff-1);
  //         if (include_a) {
  //           start = log_a;
  //         }
  //         else {
  //           start = log_a + step;
  //         }
  //       }
  //       else {
  //         step = (b - a)/static_cast<GridElement>(Neff-1);
  //         if (include_a) {
  //           start = a;
  //         }
  //         else {
  //           start = a + step;
  //         }
  //       }
  //       return *this;
  //     }

  //     mathq::GridType& makeGrid_Linear() {
  //       if (N == 0) return grid_vector;

  //       for (size_t c = 0; c<(N-1); c++) {
  //         grid_vector[c] = start + static_cast<GridElement>(c)*step;
  //       }
  //       if (include_b) {
  //         grid_vector[N-1] = b;
  //       }
  //       else {
  //         grid_vector[N-1] = b - step;
  //       }
  //       return grid_vector;
  //     }

  //     mathq::GridType& makeGrid_Log() {
  //       if (N == 0) return grid_vector;

  //       for (size_t c = 0; c<(N-1); c++) {
  //         grid_vector[c] = std::pow(10, start + static_cast<GridElement>(c)*step);
  //       }
  //       if (include_b) {
  //         grid_vector[N-1] = b;
  //       }
  //       else {
  //         grid_vector[N-1] = std::pow(10, log_b - step);
  //       }
  //       return grid_vector;
  //     }
  //   public:


  //     //------------------------------------------------------------------------------------
  //     //
  //     // static "factory" methods
  //     //
  //     //------------------------------------------------------------------------------------

  //     static Interval<GridElement> emptySet() {
  //       return Interval<GridElement>(0, 0, 0, GridScale::LINEAR, false, false);
  //     }

  //     static Interval<GridElement> point(const GridElement& p) {
  //       return Interval<GridElement>(p, p, 1, GridScale::LINEAR, true, true);
  //     }

  //     // [a,b]
  //     inline static Interval<GridElement> c_interval_c(const GridElement& a, const GridElement& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
  //       return Interval<GridElement>(a, b, N, scale, true, true);
  //     }
  //     inline static Interval<GridElement> interval(const GridElement& a, const GridElement& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
  //       return c_interval_c(a, b, N, scale);
  //     }

  //     // (a,b]
  //     static Interval<GridElement> o_interval_c(const GridElement& a, const GridElement& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
  //       return Interval<GridElement>(a, b, N, scale, false, true);
  //     }

  //     // [a,b)
  //     static Interval<GridElement> c_interval_o(const GridElement& a, const GridElement& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
  //       return Interval<GridElement>(a, b, N, scale, true, false);
  //     }

  //     // (a,b)
  //     static Interval<GridElement> o_interval_o(const GridElement& a, const GridElement& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
  //       return Interval<GridElement>(a, b, N, scale, false, false);
  //     }



  //     static Interval<GridElement> realLine(const bool include_a = true, const bool include_b = true) {
  //       GridElement a;
  //       if (include_a) {
  //         a = -std::numeric_limits<GridElement>::infinity();
  //       }
  //       else {
  //         a = std::numeric_limits<GridElement>::lowest();
  //       }
  //       GridElement b;
  //       if (include_b) {
  //         b = std::numeric_limits<GridElement>::infinity();
  //       }
  //       else {
  //         b = std::numeric_limits<GridElement>::max();
  //       }
  //       return Interval<GridElement>(a, b, 0, scale, include_a, include_b);
  //     }

  //     static Interval<GridElement> realLineNeg(const bool include_a = true, const bool include_b = true) {
  //       GridElement a;
  //       if (include_a) {
  //         a = -std::numeric_limits<GridElement>::infinity();
  //       }
  //       else {
  //         a = std::numeric_limits<GridElement>::lowest();
  //       }
  //       GridElement b;
  //       if (include_b) {
  //         b = 0;
  //       }
  //       else {
  //         b = -std::numeric_limits<GridElement>::min();
  //       }
  //       return Interval<GridElement>(a, b, 0, scale, include_a, include_b);
  //     }

  //     static Interval<GridElement> realLinePos(const bool include_a = true, const bool include_b = true) {
  //       GridElement a;
  //       if (include_a) {
  //         a = 0;
  //       }
  //       else {
  //         a = std::numeric_limits<GridElement>::min();
  //       }
  //       GridElement b;
  //       if (include_b) {
  //         b = std::numeric_limits<GridElement>::infinity();
  //       }
  //       else {
  //         b = std::numeric_limits<GridElement>::max();
  //       }
  //       return Interval<GridElement>(a, b, 0, include_a, include_b);
  //     }



  //     inline std::string classname() const {
  //       return ClassName();
  //     }

  //     static inline std::string ClassName() {
  //       using namespace display;
  //       std::string s = "Interval";
  //       s += StyledString::get(ANGLE1).get();
  //       GridElement d;
  //       s += getTypeName(d);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const Interval& var) {
  //       using namespace display;
  //       if (var.a == var.b) {
  //         // point
  //         stream << "{point=";
  //         dispval_strm(stream, var.a);
  //         // stream << ", gridState=";
  //         // dispval_strm(stream, (var.grid_vector.size() == 0) ? "deflated" : "inflated");
  //         stream << "}";
  //       }
  //       else {
  //         stream << "{";
  //         stream << "interval=";
  //         if (var.include_a) {
  //           stream << "[";
  //         }
  //         else {
  //           stream << "(";
  //         }
  //         dispval_strm(stream, var.a);
  //         stream << ", ";
  //         dispval_strm(stream, var.b);
  //         if (var.include_a) {
  //           stream << "]";
  //         }
  //         else {
  //           stream << ")";
  //         }
  //         stream << ", N=";
  //         dispval_strm(stream, var.N);

  //         stream << ", scale=";
  //         dispval_strm(stream, var.scale);

  //         // stream << ", gridState=";
  //         // dispval_strm(stream, (var.grid_vector.size() == 0) ? "deflated" : "inflated");
  //         stream << "}";
  //       }
  //       return stream;
  //     }

  // };


  //
  // Region
  //
  template <typename GridElement> requires(IsComplex<GridElement>::value)
    class
    Region {
    public:
      using Type = Region<GridElement>;
      using GridType = Vector<GridElement>;

      constexpr static size_t num_dims = 1;

      size_t N;
      GridElement a;
      GridElement b;
      bool include_a;
      bool include_b;


      Region() noexcept :
        a(-std::numeric_limits<GridElement>::infinity()), b(std::numeric_limits<GridElement>::infinity()), N(0), include_a(true), include_b(true) {
        verify();
      }

      Region(const GridElement& a, const GridElement& b, const size_t N, const bool include_a = true, const bool include_b = true) noexcept :
        a(a), b(b), N(N), include_a(include_a), include_b(include_b) {
        verify();
      }

      // note that copy constructor works but not operator= (hence we don;t define one)
      Region(const Type& x) noexcept :
        a(x.a), b(x.b), N(x.N), include_a(x.include_a), include_b(x.include_b) {
        verify();
      }

      ~Region() {
      }

      size_t num_elements() const {
        if (N == 0) return 0;
        return N +  size_t(!include_a) + size_t(!include_b);
      }
      size_t length() const {
        return b-a;
      }
      size_t start() const {
        return a;
      }
      size_t end() const {
        return b;
      }


      void verify() const {
        if (b < a) {
          // TODO: issue error
          OUTPUT("ERROR: b must be greate than a");
          MDISP(a, b);
        }
      }


      GridType& grid() const {
        GridType& grid = *(new GridType);
        if (N == 0) return grid;

        size_t Neff = num_elements();
        grid.resize(Neff);
        GridElement step = (b - a)/static_cast<GridElement>(Neff-1);
        GridElement start = (include_a) ? a : a + step;

        for (size_t c = 0; c<(N-1); c++) {
          grid[c] = start + static_cast<GridElement>(c)*step;
        }
        if (include_b) {
          grid[N-1] = b;
        }
        else {
          grid[N-1] = b - step;
        }

        return grid;
      }


      template <typename TargetElement, size_t... sizes>
      Vector<TargetElement, sizes...>& deriv(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>(), const bool periodic = false) const {
        f.deriv(a, b, n, nabla.Nwindow, periodic);
        return f;
      }


      //------------------------------------------------------------------------------------
      //
      // static "factory" methods
      //
      //------------------------------------------------------------------------------------

      // [a,b]
      inline static Region<GridElement> c_interval_c(const GridElement& a, const GridElement& b, const size_t N) {
        return Region<GridElement>(a, b, N, true, true);
      }
      inline static Region<GridElement> interval(const GridElement& a, const GridElement& b, const size_t N) {
        return c_interval_c(a, b, N);
      }

      inline std::string classname() const {
        return ClassName();
      }

      static inline std::string ClassName() {
        using namespace display;
        std::string s = "Region";
        s += StyledString::get(ANGLE1).get();
        GridElement d;
        s += getTypeName(d);
        s += StyledString::get(ANGLE2).get();
        return s;
      }


      inline friend std::ostream& operator<<(std::ostream& stream, const Region& var) {
        using namespace display;
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
        return stream;
      }

  };






};

#endif 
