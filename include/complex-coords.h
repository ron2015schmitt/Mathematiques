#ifndef MATHQ__COMPLEX_COORDS
#define MATHQ__COMPLEX_COORDS 1


namespace mathq {


  template <typename GridElement, bool TimeCoord> //requires (IsComplex<GridElement>::value)
  class ComplexCoords;


  template <typename GridElement, bool TimeCoord>
  bool complex_coords_test(ComplexCoords<GridElement, TimeCoord>& x) {
    return true;
  }

  template <typename T>
  concept IsComplexCoords = requires (T x) {
    complex_coords_test(x);
  };


  // ***************************************************************************
  // * ComplexCoords 
  // ***************************************************************************

//   // additional deduction guide
// template<class Iter>
// container(Iter b, Iter e) -> container<typename std::iterator_traits<Iter>::value_type>;

  template <typename GridElement, bool TimeCoord> //requires (IsComplex<GridElement>::value)
  class
    ComplexCoords : public Vector< CoordGrid<GridElement, 2+size_t(TimeCoord)>, 2+size_t(TimeCoord) > {
    // ComplexCoords : public Vector< double, Ndims > {
    // ComplexCoords : public CoordGrid<GridElement, Ndims, dim_ints...> {
  public:


    static constexpr size_t Ndims_value = 2;
    static constexpr bool TimeCoord_value = TimeCoord;
    static constexpr size_t total_num_dims = Ndims_value + size_t(TimeCoord);
    // constexpr static std::array<size_t, total_num_dims> static_grid_dims_array = { dim_ints... };
    constexpr static bool is_dynamic_value = true;

    using Type = ComplexCoords<GridElement, TimeCoord>;
    using ElementType = CoordGrid<GridElement, total_num_dims>;
    using GridType = ElementType;
    using NumberType = GridElement;
    using SimpleNumberType = typename SimpleNumberTrait<GridElement>::Type;

    using TypeWithTime = ComplexCoords<GridElement, true>;
    using TypeWithoutTime = ComplexCoords<GridElement, false>;

    using ParentType = Vector< ElementType, total_num_dims >;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;
    using DeepDimensionsType = RecursiveDimensions;


    // using InitializerType = typename MakeInitializer<ElementType, 1 >::Type;  


    // Rank of our multiarray grid is equal to number of dimensions
    // For low dimensions, this type will be Scalar, Vector or Matrix, etc for efficency
    // the dimensions of the multiarray are dynamic

    ComplexRectangle<GridElement> domain;
    Interval<GridElement> time_domain;


    ComplexCoords() : ParentType() {
      setup_vector_indices();
    }

    ComplexCoords(const ComplexRectangle<GridElement>& dom) : ParentType() {
      // OUTPUT("initializer_list<ComplexDomainWrapper");
      setup_vector_indices();
      domain = dom;
      init_grids();
    }


    ComplexCoords(const ComplexRectangle<GridElement>& dom, const Interval<GridElement>& time_dom) : ParentType() {
      // OUTPUT("initializer_list<ComplexDomainWrapper");
      setup_vector_indices();
      domain = dom;
      time_domain = time_dom;
      init_grids();
    }


    ComplexCoords(const ComplexCoords& coords) : ParentType() {
      setup_vector_indices();
      *this = coords;
    }


    // Copy constructor: (coords w/o time) -> (coords with time)
    template <typename T>
    ComplexCoords(const T& coords, const ComplexDomainWrapper<GridElement>& time_domain)
      requires (HasNotTimeCoord<T>&& TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<ComplexDomainWrapper<GridElement>> mylist(begin(coords.domains), end(coords.domains));
      mylist.push_back(time_domain); // add time domain
      *this = mylist;
    }

    // Copy constructor: (coords with time) -> (coords w/o time)
    template <typename T>
    ComplexCoords(const T& coords)
      requires (HasTimeCoord<T> && !TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<ComplexDomainWrapper<GridElement>> mylist(begin(coords.domains), end(coords.domains));
      mylist.pop_back(); // remove time domain
      *this = mylist;
    }


    size_t ndims(void) const {
      return total_num_dims;
    }

    Dimensions& grid_dims(void) const {
      if constexpr (total_num_dims > 0) {
        return coord(0).dims();
      }
    }

    Type& resize_grids(const Dimensions& dims) {
      if constexpr (is_dynamic_value) {
        for (size_t c = 0; c < total_num_dims; c++) {
          coord(c).resize(dims);
        }
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

    Type& set_grid(size_t g) {
      switch (g) {
      case 0:
        (*this)[g] = domain.grid_real();
        break;
      case 1:
        (*this)[g] = domain.grid_imag();
        break;
      case 2:
        (*this)[g] = time_domain.grid();
        break;
      }
      return *this;
    }

    Type& init_grids() {
      Dimensions dims(total_num_dims);
      dims[0] = domain.num_elements_real();
      dims[1] = domain.num_elements_imag();
      if constexpr (TimeCoord) {
        dims[2] = time_domain.num_elements();
      }
      resize_grids(dims);
      for (size_t c = 0; c < total_num_dims; c++) {
        set_grid(c);
      }
      return *this;
    }



    ComplexCoords& operator=(const ComplexCoords& coords) {
      domain = coords.domain;
      time_domain = coords.time_domain;
      init_grids();
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
      std::string s = "ComplexCoords";
      s += StyledString::get(ANGLE1).get();
      GridElement d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "TimeCoord=";
      s += num2string(TimeCoord);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const ComplexCoords& var) {
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





};

#endif 
