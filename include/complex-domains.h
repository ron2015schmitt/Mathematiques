#ifndef MATHQ__COMPLEXDOMAINS
#define MATHQ__COMPLEXDOMAINS 1


namespace mathq {



  // ***************************************************************************
  //                           Complex Domains
  //
  // ***************************************************************************


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

      size_t num_elements_real() const {
        return real_interval.num_elements();
      }

      size_t num_elements_imag() const {
        return imag_interval.num_elements();
      }

      Vector<SimpleNumber>& grid_real() const {
        return real_interval.grid();
      }

      Vector<SimpleNumber>& grid_imag() const {
        return imag_interval.grid();
      }

      template <typename TargetElement, size_t... sizes> requires (IsSimpleNumber<TargetElement>)
        Vector<TargetElement, sizes...>& dx(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>()) const {
        f.deriv(real_interval.a, real_interval.b, n, nabla.Nwindow, false);
        return f;
      }
      template <typename TargetElement, size_t... sizes> requires (IsSimpleNumber<TargetElement>)
        Vector<TargetElement, sizes...>& dy(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>()) const {
        f.deriv(imag_interval.a, imag_interval.b, n, nabla.Nwindow, false);
        return f;
      }

      template <typename TargetElement, size_t... sizes> requires (IsComplex<TargetElement>::value)
        Vector<TargetElement, sizes...>& dx(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>()) const {
        using SimpleNumberType = typename SimpleNumberTrait<TargetElement>::Type;
        Vector<SimpleNumberType, sizes...> fr = real(f);
        Vector<SimpleNumberType, sizes...> fi = imag(f);
        ETV(fr);
        ETV(fi);
        fr.deriv(real_interval.a, real_interval.b, n, nabla.Nwindow, false);
        fi.deriv(real_interval.a, real_interval.b, n, nabla.Nwindow, false);
        ETV(fr);
        ETV(fi);
        f = fr + Imaginary<SimpleNumberType>(1)*fi;
        ETV(f);
        return f;
      }
      template <typename TargetElement, size_t... sizes> requires (IsComplex<TargetElement>::value)
        Vector<TargetElement, sizes...>& dy(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>()) const {
        using SimpleNumberType = typename SimpleNumberTrait<TargetElement>::Type;
        Vector<SimpleNumberType, sizes...> fr = real(f);
        Vector<SimpleNumberType, sizes...> fi = imag(f);
        fr.deriv(imag_interval.a, imag_interval.b, n, nabla.Nwindow, false);
        fi.deriv(imag_interval.a, imag_interval.b, n, nabla.Nwindow, false);
        f = fr + Imaginary<SimpleNumberType>(1)*fi;
        return f;
      }

      template <typename TargetElement, size_t... sizes> requires (IsComplex<TargetElement>::value)
        Vector<TargetElement, sizes...>& dz(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>()) const {
        using SimpleNumberType = typename SimpleNumberTrait<TargetElement>::Type;
        Vector<SimpleNumberType, sizes...> fr = real(f);
        Vector<SimpleNumberType, sizes...> fi = imag(f);
        fr.deriv(real_interval.a, real_interval.b, real_interval.N, nabla.Nwindow, false);
        fi.deriv(real_interval.a, real_interval.b, real_interval.N, nabla.Nwindow, false);
        f = fr + Imaginary<SimpleNumberType>(1)*fi;
        return f;
      }
      template <typename TargetElement, size_t... sizes> requires (IsComplex<TargetElement>::value)
        Vector<TargetElement, sizes...>& dz_star(Vector<TargetElement, sizes...>& f, const size_t n = 1, const Nabla<void>& nabla = Nabla<>()) const {
        using SimpleNumberType = typename SimpleNumberTrait<TargetElement>::Type;
        Vector<SimpleNumberType, sizes...> fr = real(f);
        Vector<SimpleNumberType, sizes...> fi = imag(f);
        fr.deriv(real_interval.a, real_interval.b, real_interval.N, nabla.Nwindow, false);
        fi.deriv(real_interval.a, real_interval.b, real_interval.N, nabla.Nwindow, false);
        f = fr - Imaginary<SimpleNumberType>(1)*fi;
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
