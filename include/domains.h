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
      Vector<TargetElement, sizes...>& deriv(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>(), const GridElement periodic = 0) const {
        f.deriv(a, b, n, nabla.Nwindow, (periodic != 0));
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

      PointSequence(const GridType& grid_in, const GridElement& period) : grid_data(grid_in) {
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
      Vector<TargetElement, sizes...>& deriv(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>(), const GridElement period = 0) const {
        const size_t N = f.size();
        size_t Dpts = nabla.Nwindow;

        if (N<=1) return f;

        if (Dpts > N) {
          //TODO: error or warning
          Dpts = N;
        }

        if (Dpts > 3) {
          //TODO: error or warning
          Dpts = 3;
        }


        if (Dpts == 2) {
          TargetElement f0;
          GridElement d0;
          if (period != 0) {
            f0 = f[0] - f[N-1];
            d0 = grid_data[0] + (period - grid_data[N-1]);
          }
          else {
            f0 = f[1] - f[0];
            d0 = grid_data[1] - grid_data[0];
          }
          for (size_t i = 0; i < N-1; i++) {
            f[N-1-i] = f[N-1-i] - f[N-2-i];
          }
          f[0] = f0/d0;
          for (size_t i = 1; i < N; i++) {
            f[i] = f[i]/(grid_data[i] - grid_data[i-1]);
          }
        }
        else if (Dpts == 3) {
          TargetElement prev;
          TargetElement curr;
          TargetElement last;
          if (period != 0) {
            // first point
            {
              // (-d1,0,d2)  
              const size_t i0 = N-1;
              const size_t i1 = 0;
              const size_t i2 = 1;
              const GridElement d1 = grid_data[i1] - (grid_data[i0] - period);
              const GridElement d2 = grid_data[i2] - grid_data[i1];
              const GridElement coef0 = -d2/(d1*d1 + d1*d2);
              const GridElement coef1 = 1/d1-1/d2;
              const GridElement coef2 = d1/(d2*d2 + d1*d2);
              prev = coef0*f[i0] +coef1*f[i1] + coef2*f[i2];
            }
            // last
            {
              // (-d1,0,d2)  
              const size_t i0 = N-2;
              const size_t i1 = N-1;
              const size_t i2 = 0;
              const GridElement d1 = grid_data[i1]-grid_data[i0];
              const GridElement d2 = (grid_data[i2] + period) - grid_data[i1];
              const GridElement coef0 = -d2/(d1*d1 + d1*d2);
              const GridElement coef1 = 1/d1-1/d2;
              const GridElement coef2 = d1/(d2*d2 + d1*d2);
              last = coef0*f[i0] +coef1*f[i1] + coef2*f[i2];
            }
          }
          else {
            // first point
            {
              // (0,x1,x2)
              const GridElement x1 = grid_data[1]-grid_data[0];
              const GridElement x2 = grid_data[2]-grid_data[0];  // NOTE: subtract 0th elemnt here
              const GridElement coef0 = -(x1+x2)/(x1*x2);
              const GridElement coef1 = -x2/(x1*x1-x1*x2);
              const GridElement coef2 = -x1/(x2*x2-x1*x2);
              prev = coef0*f[0] +coef1*f[1] + coef2*f[2];
            }
            // last
            {
              // (-x2,-x1,0)
              const GridElement x2 = grid_data[N-1]-grid_data[N-3];
              const GridElement x1 = grid_data[N-1]-grid_data[N-2];
              const GridElement coef2 = sqr(x2)/(cube(x1)- cube(x2));
              const GridElement coef1 = -sqr(x1)/(cube(x1)- cube(x2));
              const GridElement coef0 = (x1+x2)/(sqr(x1) + x1*x2 + sqr(x2));
              last = coef2*f[N-3] + coef1*f[N-2] + coef0*f[N-1];
            }
          }

          for (size_t i = 1; i < N-1; i++) {
            // (-d1,0,d2)  
            const GridElement d1 = grid_data[1]-grid_data[0];
            const GridElement d2 = grid_data[2]-grid_data[1];
            const GridElement coef0 = -d2/(d1*d1 + d1*d2);
            const GridElement coef1 = 1/d1-1/d2;
            const GridElement coef2 = d1/(d2*d2 + d1*d2);
            curr = coef0*f[i-1] +coef1*f[i] + coef2*f[i+1];
            f[i-1] = prev;
            prev = curr;
          }
          f[N-2] = prev;
          f[N-1] = last;
        }
        else {
          //TODO: issue error
        }
        if (n>1) {
          return deriv(f, n-1, nabla, period);
        }
        return f;
      }


      // static inline Vector<GridElement>& coefs(const Vector<GridElement>& grid_points) {
      //   const size_t npts = grid_points.size();
      //   Vector<GridElement>& coef = *(new Vector<GridElement>(npts));
      //   // TODO: implement other numbers of pts
      //   const GridElement d1 = grid_points[1]-grid_points[0];
      //   const GridElement d2 = grid_points[2]-grid_points[1];
      //   coef[0] = -d2/(d1*d1 + d1*d2);
      //   coef[1] = 1/d1-1/d2;
      //   coef[2] = d1/(d2*d2 + d1*d2);
      //   return coef;
      // }

      // Type& operator=(const Type& x) {
      //   return *this;
      // }
      // operator DomainWrapper<GridElement>() const {
      //   DomainWrapper<GridElement> dw{ this };
      //   return dw;
      // }

      //------------------------------------------------------------------------------------
      //
      // static "factory" methods
      //
      //------------------------------------------------------------------------------------

      // [a,b]

      inline static Type log10(const GridElement& a, const GridElement& b, const size_t N, const bool include_a = true, const bool include_b = true) {
        GridType grid;
        if (N == 0) return grid;

        GridElement Neff = N + size_t(!include_a) + size_t(!include_b);
        GridElement log_a = std::log10(a);
        GridElement log_b = std::log10(b);
        GridElement step = (log_b - log_a)/static_cast<GridElement>(Neff-1);

        GridElement start = include_a ? log_a : log_a + step;

        for (size_t c = 0; c<(N-1); c++) {
          grid[c] = std::pow(10, start + static_cast<GridElement>(c)*step);
        }

        grid[N-1] = include_b ? b : std::pow(10, log_b - step);

        return grid;

        return *(new PointSequence<GridElement>(grid));
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
  //     mathq::GridType grid;

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
  //       return grid;
  //     }
  //     mathq::GridType& refreshGrid() {
  //       grid.resize(N);
  //       init();
  //       if (scale == GridScale::LOG) {
  //         return makeGrid_Log();
  //       }
  //       else {
  //         return makeGrid_Linear();
  //       }
  //     }

  //     size_t size() const {
  //       return grid.size();
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
  //       if (N == 0) return grid;

  //       for (size_t c = 0; c<(N-1); c++) {
  //         grid[c] = start + static_cast<GridElement>(c)*step;
  //       }
  //       if (include_b) {
  //         grid[N-1] = b;
  //       }
  //       else {
  //         grid[N-1] = b - step;
  //       }
  //       return grid;
  //     }

  //     mathq::GridType& makeGrid_Log() {
  //       if (N == 0) return grid;

  //       for (size_t c = 0; c<(N-1); c++) {
  //         grid[c] = std::pow(10, start + static_cast<GridElement>(c)*step);
  //       }
  //       if (include_b) {
  //         grid[N-1] = b;
  //       }
  //       else {
  //         grid[N-1] = std::pow(10, log_b - step);
  //       }
  //       return grid;
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
  //         // dispval_strm(stream, (var.grid.size() == 0) ? "deflated" : "inflated");
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
  //         // dispval_strm(stream, (var.grid.size() == 0) ? "deflated" : "inflated");
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
