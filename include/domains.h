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
  // ComplexRectangle
  //

  template <typename GridElement> requires(IsSimpleNumber<GridElement>)
    class
    ComplexRectangle;


  template <typename GridElement>
  bool is_complex_rectangle_test(ComplexRectangle<GridElement> x) {
    return true;
  }

  template <class T>
  concept IsComplexRectangle = requires(T x) {
    is_complex_rectangle_test(x);
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
  // IsRealDomain
  //

  template <class T>
  concept IsRealDomain = IsInterval<T> || IsPointSequence<T>;


  //
  // IsComplexDomain
  //

  template <class T>
  concept IsComplexDomain = IsComplexRectangle<T>;


  // //
  // // IsDomain
  // //

  // template <class T>
  // concept IsDomain = IsRealDomain<T> || IsComplexDomain<T>;


  //
  // RealDomainWrapper
  //
  template <typename GridElement>
  using RealDomainWrapper = std::variant<Interval<GridElement>, PointSequence<GridElement>>;


  //
  // ComplexDomainWrapper
  //
  template <typename GridElement>
  using ComplexDomainWrapper = std::variant<ComplexRectangle<GridElement>>;



  // //
  // // DomainWrapper
  // //
  // template <typename GridElement>
  // // using DomainWrapper = std::variant<Interval<GridElement>, PointSequence<GridElement>, ComplexRectangle<GridElement>>;
  // using DomainWrapper = std::variant<Interval<GridElement>, PointSequence<GridElement>>;






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
        return N;
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

      Dimensions& dims(void) const {
        return *(new Dimensions({ num_elements() }));
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
        grid.resize(N);

        if (N == 0) return grid;

        GridElement Neff = N + size_t(!include_a) + size_t(!include_b);
        GridElement step = (b - a)/static_cast<GridElement>(Neff-1);
        GridElement start = (include_a) ? a : a + step;
        GridElement end = (include_b) ? b : b - step;

        for (size_t c = 0; c<(N-1); c++) {
          grid[c] = start + static_cast<GridElement>(c)*step;
        }
        grid[N-1] = end;

        return grid;
      }


      template <typename TargetElement, size_t... sizes>
      Vector<TargetElement, sizes...>& deriv(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>(), const GridElement periodic = 0) const {

        GridElement Neff = N + size_t(!include_a) + size_t(!include_b);
        GridElement step = (b - a)/static_cast<GridElement>(Neff-1);
        GridElement start = (include_a) ? a : a + step;
        GridElement end = (include_b) ? b : b - step;

        f.deriv(start, end, n, nabla.Nwindow, (periodic != 0));
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

      Dimensions& dims(void) const {
        return *(new Dimensions({ num_elements() }));
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
        GridType grid(N);
        if (N == 0) return grid;

        GridElement Neff = N + size_t(!include_a) + size_t(!include_b);
        GridElement log_a = std::log10(a);
        GridElement log_b = std::log10(b);
        GridElement step = (log_b - log_a)/static_cast<GridElement>(Neff-1);
        GridElement start = include_a ? log_a : log_a + step;
        GridElement end = (include_b) ? b : std::pow(10, log_b - step);

        for (size_t c = 0; c<(N-1); c++) {
          grid[c] = std::pow(10, start + static_cast<GridElement>(c)*step);
        }
        grid[N-1] = end;

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




  //
  // ComplexRectangle
  //
  template <typename SimpleNumber> requires(IsSimpleNumber<SimpleNumber>)
    class
    ComplexRectangle {
    public:
      using Type = ComplexRectangle<SimpleNumber>;
      using GridElement = std::complex<SimpleNumber>;
      using ComplexGridType = Matrix<GridElement>;
      using SimpleNumberType = SimpleNumber;
      using RealGridType = CoordGrid<SimpleNumberType, 2>;
      using RealGridsType = Vector<RealGridType, 2>;
      using IntervalType = Interval<SimpleNumberType>;

      constexpr static size_t num_dims = 2;

      IntervalType real_interval;
      IntervalType imag_interval;

      ComplexRectangle() : real_interval(IntervalType()), imag_interval(IntervalType()) {
        verify();
      }

      ComplexRectangle(const IntervalType& real_interval, const IntervalType& imag_interval) : real_interval(real_interval), imag_interval(imag_interval) {
        verify();
      }


      // // note that copy constructor works but not operator= (hence we don;t define one)
      ComplexRectangle(const Type& x) : real_interval(x.real_interval), imag_interval(x.imag_interval) {
        verify();
      }

      ~ComplexRectangle() {
      }

      Dimensions& dims(void) const {
        return *(new Dimensions({ real_interval.num_elements(), imag_interval.num_elements() }));
      }


      void verify() const {
        // if (b < a) {
        //   // TODO: issue error
        //   OUTPUT("ERROR: b must be greate than a");
        //   MDISP(a, b);
        // }
      }


      ComplexGridType& grid_complex() const {
        ComplexGridType& grid = *(new ComplexGridType);
        const Vector<SimpleNumber> real_grid = real_interval.grid();
        const Vector<SimpleNumber> imag_grid = imag_interval.grid();
        grid.resize(real_grid.size(), imag_grid.size());
        for (size_t rr = 0; rr < real_grid.size(); rr++) {
          SimpleNumber real_value = real_grid[rr];
          for (size_t ii = 0; ii < imag_grid.size(); ii++) {
            SimpleNumber imag_value = imag_grid[ii];
            grid(rr, ii) = std::complex<SimpleNumber>(real_value, imag_value);
          }
        }
        return grid;
      }

      Vector<SimpleNumber>& grid_real() const {
        return real_interval.grid();
      }

      Vector<SimpleNumber>& grid_imag() const {
        return imag_interval.grid();
      }

      template <typename TargetElement, size_t... sizes>
      Vector<TargetElement, sizes...>& deriv(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>(), const bool periodic = false) const {
        // TODO: write this
        // f.deriv(a, b, n, nabla.Nwindow, periodic);
        return f;
      }


      inline std::string classname() const {
        return ClassName();
      }

      static inline std::string ClassName() {
        using namespace display;
        std::string s = "ComplexRectangle";
        s += StyledString::get(ANGLE1).get();
        SimpleNumber d;
        s += getTypeName(d);
        s += StyledString::get(ANGLE2).get();
        return s;
      }


      inline friend std::ostream& operator<<(std::ostream& stream, const ComplexRectangle& x) {
        using namespace display;
        stream << "( ";
        stream << "real: ";
        dispval_strm(stream, x.real_interval);
        stream << "; imag: ";
        dispval_strm(stream, x.imag_interval);
        stream << " )";
        return stream;
      }




  };






};

#endif 
