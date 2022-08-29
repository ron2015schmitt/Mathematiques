#ifndef MATHQ__GRIDS
#define MATHQ__GRIDS 1


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


  // ***************************************************************************
  //                                 Coords
  //
  // ***************************************************************************

  template <typename GridElement, size_t Ndims, bool TimeCoord, class Derived, size_t... dim_ints>
  class CurvilinearCoords;

  template <class GridElement, size_t Ndims, bool TimeCoord>
  class CartesianCoords;
  template <class GridElement>
  class PolarCoords;


  // ***************************************************************************
  //  HasTimeCoord<T>
  //
  // For CurvilinearCoords 
  // ***************************************************************************

  template <typename GridElement, size_t Ndims, class Derived, size_t... dim_ints>
  bool has_time_coord_test(const CurvilinearCoords<GridElement, Ndims, true, Derived, dim_ints...>& x) {
    return true;
  }

  template <class T>
  concept HasTimeCoord = requires(T x) {
    has_time_coord_test(x);
  };

  // ***************************************************************************
  //  HasNotTimeCoord<T>
  //
  // For CurvilinearCoords 
  // ***************************************************************************

  template <typename GridElement, size_t Ndims, class Derived, size_t... dim_ints>
  bool has_not_time_coord_test(const CurvilinearCoords<GridElement, Ndims, false, Derived, dim_ints...>& x) {
    return true;
  }

  template <class T>
  concept HasNotTimeCoord = requires(T x) {
    has_not_time_coord_test(x);
  };


  // ***************************************************************************
  // * nabla object
  // ***************************************************************************

  template <class T>
  class Nabla {
  public:
    const unsigned int Nwindow;
  public:
    Nabla(const unsigned int Nwindow = 7) :
      Nwindow(Nwindow) {
    }
    ~Nabla() {
    }



    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "Nabla";
      s += StyledString::get(ANGLE1).get();
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const Nabla<T>& var) {
      using namespace display;
      stream << "(Nwindow=";
      dispval_strm(stream, var.Nwindow);
      stream << ")";
      return stream;
    }


  };





  //
  // Interval
  //
  template <typename GridElement> requires(IsSimpleNumber<GridElement>)
    class
    Interval {
    public:
      using Type = Interval<GridElement>;

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


      Vector<GridElement>& grid() const {
        Vector<GridElement>& grid = *(new Vector<GridElement>);
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
  //     mathq::Vector<GridElement> grid_vector;

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
  //       return mathq::Vector<GridElement>;
  //     }

  //     mathq::Vector<GridElement>& coord() {
  //       refreshGrid();
  //       return grid_vector;
  //     }
  //     mathq::Vector<GridElement>& refreshGrid() {
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

  //     mathq::Vector<GridElement>& makeGrid_Linear() {
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

  //     mathq::Vector<GridElement>& makeGrid_Log() {
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


      Vector<GridElement>& grid() const {
        Vector<GridElement>& grid = *(new Vector<GridElement>);
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






  // ***************************************************************************
  // * CurvilinearCoords 
  // ***************************************************************************

  template <typename GridElement, size_t Ndims, bool TimeCoord, class Derived, size_t... dim_ints>
  class
    CurvilinearCoords : public Vector< CoordGrid<GridElement, Ndims+size_t(TimeCoord), dim_ints...>, Ndims+size_t(TimeCoord) > {
    // CurvilinearCoords : public Vector< double, Ndims > {
    // CurvilinearCoords : public CoordGrid<GridElement, Ndims, dim_ints...> {
  public:
    static constexpr size_t Ndims_value = Ndims;
    static constexpr bool TimeCoord_value = TimeCoord;
    static constexpr size_t total_num_dims = Ndims + size_t(TimeCoord);
    constexpr static std::array<size_t, total_num_dims> static_grid_dims_array = { dim_ints... };
    constexpr static bool is_dynamic_value = (sizeof...(dim_ints) == 0);

    using Type = CurvilinearCoords<GridElement, Ndims, TimeCoord, Derived, dim_ints...>;
    using ElementType = CoordGrid<GridElement, total_num_dims, dim_ints...>;
    using NumberType = GridElement;
    using SimpleNumberType = typename SimpleNumberTrait<GridElement>::Type;
    using DomainType = Interval<GridElement>;
    using GridType = ElementType;

    using TypeWithTime = CurvilinearCoords<GridElement, Ndims, true, Derived, dim_ints...>;
    using TypeWithoutTime = CurvilinearCoords<GridElement, Ndims, false, Derived, dim_ints...>;

    using ParentType = Vector< ElementType, total_num_dims >;
    using ConcreteType = Vector< MultiArray<GridElement, total_num_dims, dim_ints...>, total_num_dims >;
    using DerivedType = Derived;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;
    using DeepDimensionsType = RecursiveDimensions;


    // using InitializerType = typename MakeInitializer<ElementType, 1 >::Type;  


    // Rank of our multiarray grid is equal to number of dimensions
    // For low dimensions, this type will be Scalar, Vector or Matrix, etc for efficency
    // the dimensions of the multiarray are dynamic

    std::array<DomainType, total_num_dims> domains_old;

    std::vector<DomainWrapper<GridElement>> domains;


    CurvilinearCoords() : ParentType() {
      setup_vector_indices();
    }

    CurvilinearCoords(const std::initializer_list<DomainWrapper<GridElement>>& mylist) : ParentType() {
      setup_vector_indices();
      *this = mylist;
    }

    CurvilinearCoords(const std::initializer_list<Interval<GridElement>>& mylist) : ParentType() {
      // TRDISP(mylist);
      // return;
      setup_vector_indices();
      *this = mylist;
    }

    CurvilinearCoords(const CurvilinearCoords& coords) : ParentType() {
      setup_vector_indices();
      *this = coords;
    }


    // Copy constructor: (coords w/o time) -> (coords with time)
    template <typename T>
    CurvilinearCoords(const T& coords, DomainType& time_domain)
      requires (HasNotTimeCoord<T>&& TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<DomainType> mylist(begin(coords.domains_old), end(coords.domains_old));
      mylist.push_back(time_domain); // add time domain
      *this = mylist;
    }

    // Copy constructor: (coords with time) -> (coords w/o time)
    template <typename T>
    CurvilinearCoords(const T& coords)
      requires (HasTimeCoord<T> && !TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<DomainType> mylist(begin(coords.domains_old), end(coords.domains_old));
      mylist.pop_back(); // remove time domain
      *this = mylist;
    }


    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const  Derived& derived() const {
      return static_cast<const Derived&>(*this);
    }

    size_t ndims(void) const {
      return total_num_dims;
    }

    Dimensions& grid_dims(void) const {
      if constexpr (total_num_dims > 0) {
        return coord(0).dims();
      }
    }

    Type& grids_resize(const Dimensions& dims) {
      for (size_t c = 0; c < total_num_dims; c++) {
        coord(c).resize(dims);
      }
      return *this;
    }


    Type& setup_vector_indices(void) {
      for (size_t c = 0; c < total_num_dims; c++) {
        (*this)[c].vector_index = c;
      }
      return *this;
    }

    const GridType& coord(size_t g) const {
      return (*this)[g];
    }
    GridType& coord(size_t g) {
      return (*this)[g];
    }

    CurvilinearCoords& operator=(const std::initializer_list<DomainType>& mylist) {
      size_t i = 0;
      typename std::initializer_list<DomainType>::iterator it;
      Dimensions dims(total_num_dims);
      for (it = mylist.begin(); it != mylist.end(); ++it, i++) {
        DomainType& domain = domains_old[i];
        domain = *it;
        dims[i] = domain.num_elements();
      }
      if constexpr (is_dynamic_value) {
        grids_resize(dims);
      }
      for (size_t c = 0; c < total_num_dims; c++) {
        auto vec = domains_old[c].grid();
        coord(c) = vec;
      }
      return *this;
    }

    CurvilinearCoords& operator=(const std::initializer_list<DomainWrapper<GridElement>>& mylist) {
      size_t i = 0;
      typename std::initializer_list<DomainWrapper<GridElement>>::iterator it;
      Dimensions dims(total_num_dims);
      for (it = mylist.begin(); it != mylist.end(); ++it, i++) {
        DomainWrapper<GridElement> domain = *it;
        TRDISP(domain.index());
        // dims[i] = domain.num_elements();
        domains.push_back(domain);
      }
      if constexpr (is_dynamic_value) {
        grids_resize(dims);
      }
      for (size_t c = 0; c < total_num_dims; c++) {
        // auto vec = domains[c].grid();
        // coord(c) = vec;
      }
      return *this;
    }


    CurvilinearCoords& operator=(const CurvilinearCoords& coords) {
      if constexpr (is_dynamic_value) {
        grids_resize(coords.grid_dims());
      }
      for (size_t c = 0; c < coords.total_num_dims; c++) {
        DomainType domain = coords.domains_old[c];
        domains_old[c] = domain;
      }
      for (size_t c = 0; c < coords.total_num_dims; c++) {
        coord(c) = domains_old[c].grid();
      }
      return *this;
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************
    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "CurvilinearCoords";
      s += StyledString::get(ANGLE1).get();
      GridElement d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "Ndims=";
      s += num2string(Ndims);
      s += StyledString::get(COMMA).get();
      s += "TimeCoord=";
      s += num2string(TimeCoord);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CurvilinearCoords& var) {
      stream << "{\n";
      for (size_t g = 0; g < var.size(); g++) {
        if (g > 0)
          stream << "; \n";
        stream << "  ";
        display::dispval_strm(stream, var[g]);
      }
      stream << "\n}}";
      return stream;
    }


  };



  // ***************************************************************************
  // * return slice
  //
  // TODO: convert to slice expression
  // ***************************************************************************
  template <typename T>
  auto& get_vector(const T& x_in, const size_t n, const Indices& inds_) {
    using ElementType = typename T::ElementType;
    // TRDISP(x_in);
    const size_t rank = T::rank_value;
    const Dimensions dims = x_in.dims();
    const size_t N = dims[n];
    Vector<ElementType>& v = *(new Vector<ElementType>);
    v.resize(N);

    Indices inds = inds_;
    for (size_t i = 0; i < N; i++) {
      inds[n] = i;
      // TRDISP(inds);
      // TRDISP(x[inds]);
      v[i] = x_in[inds];
    }
    return v;
  }


  // ***************************************************************************
  // * return slice
  //
  // TODO: convert to slice expression
  // ***************************************************************************
  template <typename T>
  auto& set_vector(T& x, const size_t n, const Indices& inds_, const Vector<typename T::ElementType>& v) {
    using ElementType = typename T::ElementType;
    const size_t rank = T::rank_value;
    const Dimensions dims = x.dims();
    const size_t N = dims[n];
    Indices inds = inds_;
    for (size_t i = 0; i < N; i++) {
      inds[n] = i;
      // TRDISP(inds);
      // TRDISP(x[inds]);
      x[inds] = v[i];
    }
    return v;
  }





  // ***************************************************************************
  // * CartesianCoords<GridElement, Ndims>
  // ***************************************************************************

  // TODO: need a way include optinal time coordinate, perhaps template bool


  template <class GridElement, size_t Ndims, bool TimeCoord>
  class CartesianCoords : public CurvilinearCoords<GridElement, Ndims, TimeCoord, CartesianCoords<GridElement, Ndims, TimeCoord>> {
  public:
    using Type = CartesianCoords<GridElement, Ndims, TimeCoord>;
    using TypeWithTime = CartesianCoords<GridElement, Ndims, true>;
    using TypeWithoutTime = CartesianCoords<GridElement, Ndims, false>;

    using ParentType = CurvilinearCoords<GridElement, Ndims, TimeCoord, Type>;
    class Point;  // sub class

    constexpr static bool isNotAbstract = true;
    static constexpr size_t Ndims_value = Ndims;
    static constexpr bool TimeCoord_value = TimeCoord;
    static constexpr size_t total_num_dims = Ndims + size_t(TimeCoord);
    constexpr static bool is_dynamic_value = ParentType::is_dynamic_value;

    // template<size_t TEMP = Ndims>
    // static EnableMethodIf<TEMP==2, CartesianCoords<GridElement, Ndims>> fromPolar(const GridElement& r, const GridElement& phi) {
    //   GridElement x = r * std::cos(phi);
    //   GridElement y = r * std::sin(phi);
    //   return CartesianCoords<GridElement, Ndims>(x, y);
    // }
    // template<size_t TEMP = Ndims>
    // EnableMethodIf<TEMP==2, PolarCoords<GridElement>> toPolar() {
    //   return PolarCoords<GridElement>(*this);
    // }



    explicit CartesianCoords() : ParentType() {
    }

    CartesianCoords(const std::initializer_list<Interval<GridElement>>& mylist) : ParentType(mylist) {
    }

    CartesianCoords(const std::initializer_list<mathq::DomainWrapper<GridElement>>& mylist) : ParentType(mylist) {
    }

    explicit CartesianCoords(const Type& obj) : ParentType(obj) {
    }


    // coordinates at a grid point
    template <typename... U> requires ((ParentType::is_dynamic_value) && (std::conjunction<std::is_integral<U>...>::value) && (sizeof...(U) == total_num_dims))
      Point& at(const U... args) {
      Point& vec = *(new Point);
      for (size_t c = 0; c < total_num_dims; c++) {
        typename ParentType::GridType& grid = ParentType::coord(c);
        vec[c] = grid(args...);
      }
      return vec;
    }

    // Jacobian 
    GridElement& J() const {
      GridElement& jacob = *(new GridElement);
      jacob = 1;
      return jacob;
    }

    // TODO: use diagonal specialty matrix
    Matrix<GridElement, Ndims, Ndims>& g() const {
      Matrix<GridElement, Ndims, Ndims>& metric = *(new Matrix<GridElement, Ndims, Ndims>);
      for (size_t r = 0; r < Ndims; r++) {
        for (size_t c = 0; c < Ndims; c++) {
          metric(r, c) = (r==c) ? 1 : 0;
        }
      }
      return metric;
    }

    // CartesianCoords<GridElement, Ndims>& pos() const {
    //   return toCartesian();
    // }
    // CartesianCoords<GridElement, Ndims>& toCartesian() const {
    //   return *(new CartesianCoords<GridElement, Ndims>(*this));
    // }

    Vector<GridElement, Ndims>& basis_vec(size_t n) const {
      Vector<GridElement, Ndims>& vec = *(new Vector<GridElement, Ndims>);
      for (size_t c = 0; c < Ndims; c++) {
        vec[c] = (c == n) ? 1 : 0;
      }
      return vec;
    }

    Vector<Vector<GridElement, Ndims>, Ndims>& basis() const {
      Vector<Vector<GridElement, Ndims>, Ndims>& vec = *(new Vector<Vector<GridElement, Ndims>, Ndims>);
      for (size_t c = 0; c < Ndims; c++) {
        vec[c] = basis_vec(c);
      }
      return vec;

    }


    //**********************************************************************
    //                    Named coordinate acces
    //**********************************************************************

    // "read/write"
    ParentType::GridType& x()  requires ((Ndims >= 1) && (Ndims <= 3)) {
      return ParentType::coord(0);
    }
    ParentType::GridType& y()  requires ((Ndims >= 2) && (Ndims <= 3)) {
      return ParentType::coord(1);
    }
    ParentType::GridType& z()  requires ((Ndims >= 3) && (Ndims <= 3)) {
      return ParentType::coord(2);
    }
    ParentType::GridType& t()  requires (TimeCoord) {
      return ParentType::coord(Ndims_value);
    }

    // "read only"
    const ParentType::GridType& x() const requires ((Ndims >= 1) && (Ndims <= 3)) {
      return ParentType::coord(0);
    }
    const ParentType::GridType& y() const requires ((Ndims >= 2) && (Ndims <= 3)) {
      return ParentType::coord(1);
    }
    const ParentType::GridType& z() const requires ((Ndims >= 3) && (Ndims <= 3)) {
      return ParentType::coord(2);
    }
    const ParentType::GridType& t() const requires (TimeCoord) {
      return ParentType::coord(Ndims_value);
    }

    //**********************************************************************
    //                    Derivatives
    //  These all except bare grids, not CurvilinearFields.
    //
    // You need to use the stand alone functions and nabla operators for 
    // CurvilinearFields
    //**********************************************************************

    //
    // df/dx_c 
    //     - partial derivative - with respect to coordinate c  (zero-referenced)
    //     - f is a single grid
    //

    template <class T>
    auto& pd(const T& f, const size_t c, const Nabla<>& nabla = Nabla<>()) const
      requires (IsGridlike<T>) {

      Dimensions grid_dims = ParentType::grid_dims();
      // TRDISP(grid_dims);
      using MyGridType = MultiArray<typename T::NumberType, total_num_dims>;
      MyGridType& mygrid = *(new MyGridType);
      if constexpr (mygrid.is_dynamic_value) {
        mygrid.resize(grid_dims);
      }
      size_t sz = 1;
      for (size_t k = 0; k < total_num_dims; k++) {
        if (k != c) {
          sz *= grid_dims[k];
        }
      }

      // for loop throgh each index, skipping coordinate c, which is grabbed as a vector taken
      Interval<GridElement> domain = ParentType::domains_old[c];
      Indices inds(total_num_dims);
      inds = 0;
      for (size_t k = 0; k < sz; k++) {
        auto vec = get_vector(f, c, inds);
        domain.deriv(vec, 1, nabla, false);
        set_vector(mygrid, c, inds, vec);
        inds.increment_over(grid_dims, c);  // this will skip over index c
      }
      return mygrid;
    }


    //
    // grad(f) - f is a grid
    //

    template <class T>
    auto& grad(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires (IsGridlike<T>) {

      using MyGridType = MultiArray<typename T::NumberType, total_num_dims>;
      constexpr auto result_dims = array_of_one_value<size_t, 1, Ndims>(); // Vector<Ndims>

      using ResultType = MultiArrayHelper< MyGridType, result_dims >;
      ResultType& result = *(new ResultType);

      for (size_t c = 0; c < Ndims; c++) {
        result[c] = pd(f, c, nabla);
      }
      return result;
    }

    //
    // div(f) - f is a vector
    //

    template <class T>
    auto& div(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires ((IsReadableExpressionOrArray<T>) && (T::rank_value == 1)) {

      using MyGridType = MultiArray<typename T::NumberType, total_num_dims>;
      MyGridType& result = *(new MyGridType);
      if constexpr (result.is_dynamic_value) {
        Dimensions grid_dims = ParentType::grid_dims();
        result.resize(grid_dims);
      }
      result = 0;

      for (size_t c = 0; c < Ndims; c++) {
        result = result + pd(f[c], c, nabla);
      }
      return result;
    }



    //
    // curl(f) - f is a vector of length = 3
    //

    template <class T>
    auto& curl(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires ((IsReadableExpressionOrArray<T>) && (T::rank_value == 1) && (Ndims == 3)) {

      using MyGridType = MultiArray<typename T::NumberType, total_num_dims>;
      constexpr auto result_dims = array_of_one_value<size_t, 1, Ndims>(); // Vector<Ndims>

      using ResultType = MultiArrayHelper< MyGridType, result_dims >;
      ResultType& result = *(new ResultType);
      if constexpr (result.is_dynamic_value) {
        Dimensions grid_dims = ParentType::grid_dims();
        result.resize(grid_dims);
      }
      result[0] = pd(f[2], 1, nabla) - pd(f[1], 2, nabla);
      result[1] = pd(f[0], 2, nabla) - pd(f[2], 0, nabla);
      result[2] = pd(f[1], 0, nabla) - pd(f[0], 1, nabla);
      return result;
    }

    //
    // df/dx - for convenience
    //

    template <class T>
    auto& pdx(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires ((Ndims >= 1) && (Ndims <= 3)) {
      return pd(f, 0, nabla);
    }

    //
    // df/dy - for convenience
    //

    template <class T>
    auto& pdy(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires ((Ndims >= 2) && (Ndims <= 3)) {
      return pd(f, 1, nabla);
    }

    //
    // df/dz - for convenience
    //

    template <class T>
    auto& pdz(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires ((Ndims >= 3) && (Ndims <= 3)) {
      return pd(f, 2, nabla);
    }

    //
    // df/dt - for convenience
    //

    template <class T>
    auto& pdt(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires (TimeCoord) {
      return pd(f, Ndims, nabla);
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    // instance classname() method 

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "CartesianCoords";
      s += StyledString::get(ANGLE1).get();
      GridElement d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "Ndims=";
      s += num2string(Ndims);
      s += StyledString::get(COMMA).get();
      s += "TimeCoord=";
      s += TimeCoord ? "true" : "false";
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CartesianCoords<GridElement, Ndims, TimeCoord>& var) {
      stream << "(";
      for (size_t c = 0; c < total_num_dims; c++) {
        if (c>0) stream << "; ";
        stream << var.name(c);
        stream << "=";
        stream << var.domains_old[c];
      }
      stream << ")";
      return stream;
    }


    std::array<std::string, total_num_dims>& names() const {
      return Names();
    }
    static inline std::array<std::string, total_num_dims>& Names() {
      std::array<std::string, total_num_dims> names;
      for (size_t c = 0; c < total_num_dims; c++) {
        names[c] = name(c);
      }
      return names;
    }

    const std::string& name(size_t n) const {
      return Name(n);
    }

    const static inline std::string& Name(size_t n) {
      std::string& s = *(new std::string());
      if (n >= total_num_dims) {
        // TODO: error 
        s += "bad coord";
      }
      if constexpr (TimeCoord) {
        if (n == Ndims) {
          s += "t";
          return s;
        }
      }
      if constexpr (Ndims == 1) {
        s += "x";
      }
      else if constexpr (Ndims == 2) {
        switch (n) {
        case 0:
          s += "x";
          break;
        case 1:
          s += "y";
          break;
        }
      }
      else if constexpr (Ndims == 3) {
        switch (n) {
        case 0:
          s += "x";
          break;
        case 1:
          s += "y";
          break;
        case 2:
          s += "z";
          break;
        }
      }
      else {
        s += "x";
        s += std::to_string(n+1);
      }
      return s;
    }


    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // GridElement& x1() const {
    //   return (*this)[0];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // CartesianCoords<GridElement, Ndims>& x1(const GridElement& x1) const {
    //   (*this)[0] = x1;
    //   return *this;
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // GridElement& x() const {
    //   return (*this)[0];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // CartesianCoords<GridElement, Ndims>& x(const GridElement& x) const {
    //   (*this)[0] = x;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // GridElement& x2() const {
    //   return (*this)[1];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // CartesianCoords<GridElement, Ndims>& x2(const GridElement& x2) const {
    //   (*this)[1] = x2;
    //   return *this;
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // GridElement& y() const {
    //   return (*this)[1];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // CartesianCoords<GridElement, Ndims>& y(const GridElement& y) const {
    //   (*this)[1] = y;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // GridElement& x3() const {
    //   return (*this)[2];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // CartesianCoords<GridElement, Ndims>& x3(const GridElement& x3) const {
    //   (*this)[2] = x3;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // GridElement& z() const {
    //   return (*this)[2];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // CartesianCoords<GridElement, Ndims>& z(const GridElement& z) const {
    //   (*this)[2] = z;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP==2)> = 0>
    // explicit CartesianCoords<GridElement, Ndims>(const PolarCoords<GridElement>& v2) {
    //   (*this)[0] = v2.r() * std::cos(v2.phi());
    //   (*this)[1] = v2.r() * std::sin(v2.phi());
    // }


    class Point : public Vector<GridElement, total_num_dims> {
    public:
      // instance classname() method 

      inline std::string classname() const {
        return ClassName();
      }

      // static ClassName() method 

      static inline std::string ClassName() {
        using namespace display;
        std::string s = CartesianCoords::ClassName();
        s += "::Point";
        return s;
      }


      inline friend std::ostream& operator<<(std::ostream& stream, const Type::Point& var) {
        stream << "(";
        for (size_t c = 0; c < total_num_dims; c++) {
          if (c>0) stream << ", ";
          stream << Type::Name(c);
          stream << "=";
          stream << var[c];
        }
        stream << ")";
        return stream;
      }

    };

  };



  // template <class GridElement, size_t Ndims>
  // auto dot(const CartesianCoords<GridElement, Ndims>& v1, const CartesianCoords<GridElement, Ndims>& v2) {
  //   return v1 | v2;
  // }




  //   // ***************************************************************************
  //   // * PolarCoords<GridElement>(r, phi)
  //   // ***************************************************************************

  //   template <class GridElement>
  //   class PolarCoords : public CurvilinearCoords<GridElement, 2, PolarCoords<GridElement>> {
  //   public:
  //     typedef PolarCoords<GridElement> CLASS;
  //     typedef CurvilinearCoords<GridElement, 2, CLASS> PARENT;
  //     typedef typename PARENT::PARENT BASE;

  //     static PolarCoords<GridElement> fromCartesian(GridElement x, GridElement y) {
  //       return PolarCoords<GridElement>(std::sqrt(x*x + y*y), std::atan2(y, x));
  //     }

  //     PolarCoords(const GridElement r, const GridElement phi) {
  //       (*this)[0] = r;
  //       (*this)[1] = phi;
  //     }
  //     PolarCoords(const std::initializer_list<GridElement>& mylist) {
  //       BASE& me = *this;
  //       me = mylist;
  //     }

  //     PolarCoords(const PolarCoords<GridElement>& v2) {
  //       BASE& me = *this;
  //       me = v2;
  //     }

  //     PolarCoords(const CartesianCoords<GridElement, 2>& v2) {
  //       (*this)[0] = std::sqrt(x*x + y*y);
  //       (*this)[1] = std::atan2(y, x);
  //     }


  //     // const std::vector<bool> periodic = { false, true };

  //     std::vector<std::string>& names() const {
  //       std::vector<std::string> names = { "r","𝜑" };
  //       return names;
  //     }
  //     const std::string& name(size_t n) const {
  //       if (n == 0) {
  //         return std::string("r");
  //       }
  //       else {
  //         return std::string("phi");
  //       }
  //     }


  //     GridElement& r() const {
  //       return (*this)[0];
  //     }
  //     GridElement& phi() const {
  //       return (*this)[1];
  //     }

  //     PolarCoords<GridElement>& r(const GridElement& r) const {
  //       (*this)[0] = r;
  //       return *this;
  //     }
  //     PolarCoords<GridElement>& phi(const GridElement& phi) const {
  //       (*this)[1] = phi;
  //       return *this;
  //     }


  //     GridElement x() const {
  //       const GridElement& r = (*this)[0];
  //       const GridElement& phi = (*this)[1];
  //       return r * std::cos(phi);
  //     }
  //     GridElement x1() const {
  //       return x();
  //     }

  //     GridElement y() const {
  //       const GridElement& r = (*this)[0];
  //       const GridElement& phi = (*this)[1];
  //       return r * std::sin(phi);
  //     }
  //     GridElement x2() const {
  //       return y();
  //     }


  //     CartesianCoords<GridElement, 2>& pos() const {
  //       return toCartesian();
  //     }
  //     CartesianCoords<GridElement, 2>& toCartesian() const {
  //       return *(new CartesianCoords<GridElement, 2>({ x(), y() }));
  //     }


  //     // unit vectors
  //     Vector<GridElement, 2>& basis_r() const {
  //       const GridElement& r = (*this)[0];
  //       const GridElement& phi = (*this)[1];
  //       return *(new Vector<GridElement, 2>{ std::cos(phi), std::sin(phi) });
  //     }
  //     Vector<GridElement, 2>& basis_phi() const {
  //       const GridElement& r = (*this)[0];
  //       const GridElement& phi = (*this)[1];
  //       return *(new Vector<GridElement, 2>{ -std::sin(phi), std::cos(phi) });
  //     }

  //     Vector<GridElement, 2>& basis_vec(size_t n) const {
  //       if (n == 0) {
  //         return basis_r();
  //       }
  //       else {
  //         return basis_phi();
  //       }
  //     }


  //     // Jacobian 
  //     GridElement J() const {
  //       const GridElement& r = (*this)[0];
  //       const GridElement& phi = (*this)[1];
  //       return r;
  //     }

  //     // metric tensor g^{ij} 
  //     Matrix<GridElement, 2, 2> g() const {
  //       const GridElement& r = (*this)[0];
  //       const GridElement& phi = (*this)[1];
  //       Matrix<GridElement, 2, 2> metric;
  //       metric = { ones<GridElement>(), zeros<GridElement>(), zeros<GridElement>(), r*r };
  //       return metric;
  //     }

  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "PolarCoords";
  //       s += StyledString::get(ANGLE1).get();
  //       GridElement d;
  //       s += getTypeName(d);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const PolarCoords<GridElement>& var) {
  //       const GridElement& r = var[0];
  //       const GridElement& phi = var[1];
  //       stream << "(r=";
  //       stream << r;
  //       stream << ", φ=";
  //       stream << phi;
  //       stream << ")";
  //       return stream;
  //     }


  //   };


  //   template <class GridElement>
  //   auto dot(const PolarCoords<GridElement>& v1, const PolarCoords<GridElement>& v2) {
  //     return v1[0] * v2[0] * std::cos(v1[1] - v2[1]);
  //   }

  //   // template <class GridElement>
  //   // auto& addpts(const PolarCoords<GridElement>& v1, const PolarCoords<GridElement>& v2) {
  //   //   const Vector<GridElement, 2> p = v1.toCartesian() + v2.toCartesian();
  //   //   return p.toPolar();
  //   // }

  //   // TODO: pmult for scalar * PolarCoords



  // template <class X, class Element, typename Num, size_t depth, size_t rank>
  // bool writable_expression_test(const ExpressionRW<X, Element, Num, depth, rank>& x) {

  // template <typename GridElement, size_t Ndims, class Derived, size_t... dim_ints>

  template <typename T, typename GridElement, size_t Ndims, bool TimeCoord>
  bool curvilinear_coords_test(CurvilinearCoords<GridElement, Ndims, TimeCoord, T>& x) {
    return true;
  }

  template <typename T>
  concept IsCurvilinear = requires (T x) {
    curvilinear_coords_test(x);
      requires std::is_same_v<bool const, decltype(T::isNotAbstract)>;
      requires (T::isNotAbstract == true);
  };


  // ***************************************************************************
  // * CurvilinearField
  // ***************************************************************************

  template <typename TargetElement, size_t target_rank, IsCurvilinear Coords>
  class
    CurvilinearField : public MultiArray< MultiArray<TargetElement, Coords::total_num_dims>, target_rank > {
  public:
    static constexpr size_t rank_value = target_rank;
    constexpr static bool is_dynamic_value = true;

    using ParentType = MultiArray< MultiArray<TargetElement, Coords::total_num_dims>, target_rank >;
    using GridElement = TargetElement;
    using CoordGridType = Coords::NumberType;
    using Type = CurvilinearField<TargetElement, target_rank, Coords>;
    using CoordsWithoutTime = typename Coords::TypeWithoutTime;
    using TypeWithoutTime = CurvilinearField<TargetElement, target_rank, CoordsWithoutTime>;

    template <size_t new_rank>
    using ReplaceRankType = CurvilinearField<TargetElement, new_rank, Coords>;

    using ParentType::operator=;
    using ParentType::resize;  // needed to find overloaded funcs
    using ParentType::set_equal_to;  // needed to find overloaded funcs

    const Coords& coordinates;

    CurvilinearField(const Coords& coords) : coordinates(coords) {
      Dimensions d(rank_value);
      d = Coords::total_num_dims;
      if constexpr (rank_value > 0) {
        ParentType::resize(d);
      }
      grids_resize(coords.grid_dims());
    }


    Dimensions& grid_dims(void) const {
      if constexpr (rank_value > 0) {
        return (*this)[0].dims();
      }
      else {
        return (*this)().dims();
      }
    }

    Type& grids_resize(const Dimensions& dims) {
      if constexpr (rank_value == 0) {
        (*this)().resize(dims);
      }
      else {
        for (size_t c = 0; c < ParentType::size(); c++) {
          (*this)[c].resize(dims);
        }
      }
      return *this;
    }


    //**********************************************************************
    //                    coordinates access
    //  Note: you cannot change the reference that holds the Coordinates 
    //        because C++ never allows this.
    //        and cannot change the coordinates themselves becasue they are const.
    //**********************************************************************

    // "read only"
    const Coords& coords() const {
      return coordinates;
    }

    bool at_time(const size_t t_i) const
      requires (Coords::TimeCoord_value) {
      // TypeWithoutTime& field = *(new TypeWithoutTime)
      return true;
    }


    template<typename T>
    inline Type& operator=(const T& rhs) {
      // TRDISP(ParentType());
      ParentType::set_equal_to(rhs);
      return *this;
    }

    inline Type& operator=(const Type& rhs) {
      // OUTPUT("operator= of field");
      ParentType::set_equal_to(rhs);
      return *this;
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    // instance classname() method 

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "CurvilinearField";
      s += StyledString::get(ANGLE1).get();
      TargetElement d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += std::to_string(target_rank);
      s += StyledString::get(COMMA).get();
      s += Coords::ClassName();
      s += StyledString::get(ANGLE2).get();
      return s;
    }


  };


  //   // ***************************************************************************
  //   // * PolarField<GridElement,RANK>
  //   //
  //   // physics field object: scalar field, vector field, tensor field 
  //   // uses curvilinear coordinates
  //   // ***************************************************************************
  //   template <typename GridElement, size_t RANK> class PolarField : public MultiGrid_A<GridElement, 2, RANK> {
  //   public:
  //     using Coords = PolarCoords<GridElement>;
  //     // need a grid
  //     // dot, grad, div
  // // Map a function to cartesian coordinates (pull-back)
  // // Map a function from cartesian coordinates (push-forward)

  //     PolarField() {

  //     }

  //     // operators[n] and (r,phi)

  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "PolarField";
  //       s += StyledString::get(ANGLE1).get();
  //       GridElement d;
  //       s += getTypeName(d);
  //       s += StyledString::get(COMMA).get();
  //       s += "RANK=";
  //       s += num2string(RANK);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const PolarField<GridElement, RANK>& var) {
  //       stream << "{ ";
  //       stream << "\n  coords=(";
  //       for (size_t n = 0; n < 2; n++) {
  //         if (n>0) {
  //           stream << ", ";
  //         }
  //         stream << var.names[n];
  //         if (var.periodic[n]) {
  //           stream << ": periodic";
  //         }
  //       }
  //       stream << ")";
  //       stream << "\n}";
  //       return stream;
  //     }

  //   };


  //   //
  //   // CurvilinearCoordinateSystem<GridElement>
  //   //

  //   //   template <typename... U>
  //     // typename std::enable_if<(std::is_same<U, GridElement>::value && ...), const GridElement>::type operator()(const U... args) 
  //     // https://en.cppreference.com/w/cpp/language/parameter_pack
  //     // https://en.cppreference.com/w/cpp/concepts

  //     // https://stackoverflow.com/questions/25885893/how-to-create-a-variadic-generic-lambda
  //     // https://stackoverflow.com/questions/24661902/fixed-length-variadic-parameter-packs-in-c11
  //     // https://stackoverflow.com/questions/63563252/c-template-concept-that-requires-specific-parameter-pack-size
  //     //https://stackoverflow.com/questions/70881511/is-there-a-way-to-make-a-concept-that-can-represent-a-template-parameter-pack
  //     // https://stackoverflow.com/questions/24912900/status-of-fixed-size-parameter-packs
  //     // https://stackoverflow.com/questions/63563252/c-template-concept-that-requires-specific-parameter-pack-size
  //     // https://stackoverflow.com/questions/30346652/enforce-variadic-template-of-certain-type
  //     // https://stackoverflow.com/questions/69302003/how-to-use-c20-concepts-to-compile-time-enforce-match-of-number-of-args-for-gi
  //     // 

  //   template <typename GridElement, size_t Ndims, typename CHILD>
  //   class
  //     CurvilinearCoordinateSystem {
  //   public:

  //     CHILD& derived() {
  //       return static_cast<CHILD&>(*this);
  //     }
  //     const CHILD& derived() const {
  //       return static_cast<const CHILD&>(*this);
  //     }


  //     CurvilinearCoordinateSystem(
  //     ) {
  //     }


  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "CurvilinearCoordinateSystem";
  //       s += StyledString::get(ANGLE1).get();
  //       GridElement d;
  //       s += getTypeName(d);
  //       s += StyledString::get(COMMA).get();
  //       s += "Ndims=";
  //       s += num2string(Ndims);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const CurvilinearCoordinateSystem& var) {
  //       stream << "{}";
  //       return stream;
  //     }


  //   };


  //   template <typename GridElement>
  //   class
  //     PolarCoordSystem : public CurvilinearCoordinateSystem<GridElement, 2, PolarCoordSystem<GridElement>> {
  //   public:
  //     using Func = std::function<GridElement(GridElement, GridElement)>;
  //     using VecFunc = std::function<Vector<GridElement, 2>(GridElement, GridElement)>;
  //     using Coords = PolarCoords<GridElement>;


  //     PolarCoordSystem() {
  //     }


  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "PolarCoordSystem";
  //       s += StyledString::get(ANGLE1).get();
  //       GridElement d;
  //       s += getTypeName(d);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const PolarCoordSystem& var) {
  //       stream << "{ ";
  //       stream << "\n  coords=(";
  //       for (size_t n = 0; n < 2; n++) {
  //         if (n>0) {
  //           stream << ", ";
  //         }
  //         stream << var.names[n];
  //         if (var.periodic[n]) {
  //           stream << ": periodic";
  //         }
  //       }
  //       stream << ")";
  //       stream << "\n}";
  //       return stream;
  //     }

  //   };


    // template <typename GridElement>
    // using PolarCoords = typename PolarCoordSystem<GridElement>::Coords;

    // template <typename GridElement = double>
    // auto dot(const typename PolarCoordSystem<GridElement>::Coords& v1, const typename PolarCoordSystem<GridElement>::Coords& v2) {
    //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
    // }


    // template <typename GridElement, template <typename> class T>
    // auto dot(const typename T<GridElement>::Coords& v1, const typename T<GridElement>::Coords& v2) {
    //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
    // }

    // template <typename GridElement>
    // auto dot(const typename PolarCoordSystem<GridElement>::Coords& v1, const typename PolarCoordSystem<GridElement>::Coords& v2) {
    //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
    // }







    // // ***************************************************************************
    // // * gradient of a scalar function in N dimensions
    // // ***************************************************************************

    // // gradient
    // // assumes a uniform linear grid spacing
    // // TODO: non-uniform grids

    // // 
    // // 1D
    // //

    // template <typename GridElement, typename = typename std::enable_if<std::is_arithmetic<GridElement>::value, GridElement>::type>
    // auto grad(const Vector<GridElement>& gridfunc, const Interval<GridElement>& range, const int Dpts = 7, const bool periodic = false) {
    //   const size_t N = gridfunc.size();
    //   Vector<GridElement>* df = new Vector<GridElement>(N);
    //   *df = gridfunc;
    //   df->deriv(range.a, range.b, 1, Dpts, periodic);
    //   return *df;
    // }

    // template <typename GridElement, typename = typename std::enable_if<std::is_arithmetic<GridElement>::value, GridElement>::type>
    // auto operator&(const Nabla_old<void> i, std::pair<Vector<GridElement>, Interval<GridElement>> funcANDrange) {
    //   return grad(funcANDrange.first, funcANDrange.second);
    // }

    // // 
    // // 2D
    // //

    // // template <typename GridElement, typename = typename std::enable_if<std::is_arithmetic<GridElement>::value, GridElement>::type>
    // // auto fgrid(std::function<GridElement(GridElement, GridElement)> func, const Vector<Matrix<GridElement>, 2>& grid) {
    // //   const Matrix<GridElement>& X = coord(0);
    // //   const Matrix<GridElement>& Y = coord(1);
    // //   auto* y = new Matrix<GridElement>(X.Nrows(), X.Ncols());
    // //   for (int k = 0; k < X.size(); k++) {
    // //     (*y)[k] = func(X[k], Y[k]);
    // //   }
    // //   return *y;
    // // }

    // template <typename GridElement, typename = typename std::enable_if<std::is_arithmetic<GridElement>::value, GridElement>::type>
    // auto grad(const Matrix<GridElement>& gridfunc, const Interval<GridElement>& domX, const Interval<GridElement>& domY, const int Dpts = 7, const bool periodic = false) {

    //   // TODO: rewrite with slices

    //   const size_t NR = gridfunc.Nrows();
    //   const size_t NC = gridfunc.Ncols();
    //   Vector<Matrix<GridElement>, 2>* df = new Vector<Matrix<GridElement>, 2>();
    //   // starts off with empty matrices
    //   // TRDISP(*df);

    //   // take d/dx
    //   Vector<GridElement> vtemp = Vector<GridElement>(NC);
    //   Matrix<GridElement> mtemp = Matrix<GridElement>(NR, NC);
    //   for (int r = 0; r < NR; r++) {
    //     for (int c = 0; c < NC; c++) {
    //       vtemp(c) = gridfunc(r, c);
    //     }
    //     vtemp.deriv(domX.a, domX.b, 1, Dpts, periodic);
    //     for (int c = 0; c < NC; c++) {
    //       mtemp(r, c) = vtemp(c);
    //     }
    //   }
    //   (*df)(0) = mtemp;

    //   // take d/dy
    //   vtemp.resize(NR);
    //   for (int c = 0; c < NC; c++) {
    //     for (int r = 0; r < NR; r++) {
    //       vtemp(r) = gridfunc(r, c);
    //     }
    //     vtemp.deriv(domY.a, domY.b, 1, Dpts, periodic);
    //     for (int r = 0; r < NR; r++) {
    //       mtemp(r, c) = vtemp(r);
    //     }
    //   }
    //   (*df)(1) = mtemp;

    //   // TRDISP(*df);
    //   return *df;
    // }

    // template <typename GridElement, typename = typename std::enable_if<std::is_arithmetic<GridElement>::value, GridElement>::type>
    // auto operator&(const Nabla_old<void> i, std::tuple<Matrix<GridElement>, Interval<GridElement>, Interval<GridElement>> funcANDrange) {
    //   return grad(std::get<0>(funcANDrange), std::get<1>(funcANDrange), std::get<2>(funcANDrange));
    // }



  //
  // MathFunction - multivariable scalar function in Cartesian metric
  //


  template <typename GridElement, size_t Ndims, bool TimeCoord, typename TargetElement = GridElement>
  using MathFunction = CurvilinearField<TargetElement, 0, CartesianCoords<GridElement, Ndims, TimeCoord>>;

  //
  // grad(f) - for scalar f
  //

  template <typename TargetElement, IsCurvilinear Coords>
  auto& grad(const CurvilinearField<TargetElement, 0, Coords>& f, const Nabla<>& nabla = Nabla<>()) {

    Coords const& coords = f.coords();
    CurvilinearField<TargetElement, 1, Coords>& g = *(new CurvilinearField<TargetElement, 1, Coords>(coords));
    g = coords.grad(f(), nabla);
    return g;
  }

  //
  // nabla & f - for scalar f
  //

  template <typename TargetElement, IsCurvilinear Coords>
  CurvilinearField<TargetElement, 1, Coords> operator&(const Nabla<>& nabla, const CurvilinearField<TargetElement, 0, Coords>& f) {
    return grad(f, nabla);
  }


  //
  // div(f) - for vector f
  //

  template <typename TargetElement, IsCurvilinear Coords>
  CurvilinearField<TargetElement, 0, Coords> div(const CurvilinearField<TargetElement, 1, Coords>& f, const Nabla<>& nabla = Nabla<>()) {

    Coords const& coords = f.coords();
    CurvilinearField<TargetElement, 0, Coords>& g = *(new CurvilinearField<TargetElement, 0, Coords>(coords));
    g = coords.div(f, nabla);
    return g;
  }

  //
  // nabla | f - for vector f
  //

  template <typename TargetElement, IsCurvilinear Coords>
  CurvilinearField<TargetElement, 0, Coords> operator|(const Nabla<>& nabla, const CurvilinearField<TargetElement, 1, Coords>& f) {
    return div(f, nabla);
  }


  //
  // curl(f) - for vector f
  //

  template <typename TargetElement, IsCurvilinear Coords>
  CurvilinearField<TargetElement, 1, Coords> curl(const CurvilinearField<TargetElement, 1, Coords>& f, const Nabla<>& nabla = Nabla<>()) {

    Coords const& coords = f.coords();
    CurvilinearField<TargetElement, 1, Coords>& g = *(new CurvilinearField<TargetElement, 1, Coords>(coords));
    g = coords.curl(f, nabla);
    return g;
  }


  namespace cross_product {

    //
    // nabla ^ f - for vector f
    //

    template <typename TargetElement, IsCurvilinear Coords>
    CurvilinearField<TargetElement, 1, Coords> operator^(const Nabla<>& nabla, const CurvilinearField<TargetElement, 1, Coords>& f) {
      return curl(f, nabla);
    }
  };

  //
  // pd(f,c) - for scalar f
  //

  template <typename TargetElement, IsCurvilinear Coords>
  CurvilinearField<TargetElement, 0, Coords> pd(const CurvilinearField<TargetElement, 0, Coords>& f, const size_t c, const Nabla<>& nabla = Nabla<>()) {

    Coords const& coords = f.coords();
    auto& g = *(new CurvilinearField<TargetElement, 0, Coords>(coords));
    g = coords.pd(f(), c, nabla);
    return g;
  }

  //
  // pd f - for scalar f
  //

  // template <typename TargetElement, IsCurvilinear Coords>
  // CurvilinearField<TargetElement, 1, Coords> operator&(const Nabla<>& nabla, const CurvilinearField<TargetElement, 0, Coords>& f) {
  //   return grad(f, nabla);
  // }



};

#endif 
