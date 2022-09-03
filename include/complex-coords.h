#ifndef MATHQ__COMPLEX_COORDS
#define MATHQ__COMPLEX_COORDS 1


namespace mathq {




  // ***************************************************************************
  // * ComplexCoords 
  // ***************************************************************************

//   // additional deduction guide
// template<class Iter>
// container(Iter b, Iter e) -> container<typename std::iterator_traits<Iter>::value_type>;

  template <typename GridElement, bool TimeCoord>
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

    ComplexDomainWrapper<GridElement> domain;
    // ComplexDomainWrapper<GridElement> time_domain;


    ComplexCoords() : ParentType() {
      setup_vector_indices();
    }

    ComplexCoords(const ComplexRectangle<GridElement>& dom) : ParentType() {
      // OUTPUT("initializer_list<ComplexDomainWrapper");
      setup_vector_indices();
      // *this = dom;
    }


    ComplexCoords(const ComplexRectangle<GridElement>& dom, const Interval<GridElement>& time_dom) : ParentType() {
      // OUTPUT("initializer_list<ComplexDomainWrapper");
      setup_vector_indices();
      // *this = dom;
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

    GridType& set_grid(size_t g) {
      // ComplexDomainWrapper<GridElement> domain = domains[g];
      // Vector<GridElement> vec;
      // std::visit([&vec](auto&& arg) {
      //   vec = arg.grid();
      //   }, domain);
      // (*this)[g] = vec;
      return *this;
    }

    Type& init_grids() {
      for (size_t c = 0; c < total_num_dims; c++) {
        set_grid(c);
      }
      return *this;
    }




    ComplexCoords& operator=(ComplexRectangle<GridElement>& dom) {
      // Dimensions dims(total_num_dims);
      // // get each domain and size
      // size_t i = 0;
      // typename std::list<ComplexDomainWrapper<GridElement>>::const_iterator it;
      // for (it = mylist.begin(); it != mylist.end(); ++it, i++) {
      //   ComplexDomainWrapper<GridElement> domain = *it;
      //   size_t dim;
      //   std::visit([&dim](auto&& arg) {
      //     dim = arg.dims()[0];
      //     }, domain);
      //   dims[i] = dim;
      //   domains.push_back(domain);
      // }

      // resize_grids(dims);
      // init_grids();
      return *this;
    }


    ComplexCoords& operator=(const ComplexCoords& coords) {
      // domains.clear();

      // // get each domain 
      // for (size_t c = 0; c < coords.total_num_dims; c++) {
      //   ComplexDomainWrapper<GridElement> domain = coords.domains[c];
      //   domains.push_back(domain);
      // }

      // resize_grids(coords.grid_dims());
      // init_grids();
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
