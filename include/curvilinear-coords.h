#ifndef MATHQ__CURVCOORDS
#define MATHQ__CURVCOORDS 1


namespace mathq {





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
    using ConcreteType = Vector<
      MultiArray<GridElement, total_num_dims, dim_ints...>, total_num_dims >;
    using DerivedType = Derived;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;
    using DeepDimensionsType = RecursiveDimensions;


    // using InitializerType = typename MakeInitializer<ElementType, 1 >::Type;  


    // Rank of our multiarray grid is equal to number of dimensions
    // For low dimensions, this type will be Scalar, Vector or Matrix, etc for efficency
    // the dimensions of the multiarray are dynamic

    std::vector<DomainWrapper<GridElement>> domains;


    CurvilinearCoords() : ParentType() {
      setup_vector_indices();
    }

    CurvilinearCoords(const std::initializer_list<DomainWrapper<GridElement>>& mylist) : ParentType() {
      // OUTPUT("initializer_list<DomainWrapper");
      setup_vector_indices();
      *this = mylist;
    }

    CurvilinearCoords(const CurvilinearCoords& coords) : ParentType() {
      setup_vector_indices();
      *this = coords;
    }


    // Copy constructor: (coords w/o time) -> (coords with time)
    template <typename T>
    CurvilinearCoords(const T& coords, DomainWrapper<GridElement>& time_domain)
      requires (HasNotTimeCoord<T>&& TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<DomainWrapper<GridElement>> mylist(begin(coords.domains), end(coords.domains));
      mylist.push_back(time_domain); // add time domain
      *this = mylist;
    }

    // Copy constructor: (coords with time) -> (coords w/o time)
    template <typename T>
    CurvilinearCoords(const T& coords)
      requires (HasTimeCoord<T> && !TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<DomainWrapper<GridElement>> mylist(begin(coords.domains), end(coords.domains));
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
      DomainWrapper<GridElement> domain = domains[g];
      Vector<GridElement> vec;
      std::visit([&vec](auto&& arg) {
        vec = arg.grid();
        }, domain);
      return (*this)[g] = vec;
    }

    Type& init_grids() {
      for (size_t c = 0; c < total_num_dims; c++) {
        set_grid(c);
      }
      return *this;
    }



    CurvilinearCoords& operator=(const std::initializer_list<DomainWrapper<GridElement>>& mylist) {
      *this = std::list<DomainWrapper<GridElement>>(mylist);
      return *this;
    }

    CurvilinearCoords& operator=(const std::list<DomainWrapper<GridElement>>& mylist) {
      domains.clear();
      Dimensions dims(total_num_dims);
      // get each domain and size
      size_t i = 0;
      typename std::list<DomainWrapper<GridElement>>::const_iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it, i++) {
        DomainWrapper<GridElement> domain = *it;
        size_t dim;
        std::visit([&dim](auto&& arg) {
          dim = arg.num_elements();
          }, domain);
        dims[i] = dim;
        domains.push_back(domain);
      }

      resize_grids(dims);
      init_grids();
      return *this;
    }


    CurvilinearCoords& operator=(const CurvilinearCoords& coords) {
      domains.clear();

      // get each domain 
      for (size_t c = 0; c < coords.total_num_dims; c++) {
        DomainWrapper<GridElement> domain = coords.domains[c];
        domains.push_back(domain);
      }

      resize_grids(coords.grid_dims());
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



    CartesianCoords() : ParentType() {
    }

    CartesianCoords(const std::initializer_list<mathq::DomainWrapper<GridElement>>& mylist) : ParentType(mylist) {
    }

    CartesianCoords(const Type& obj) : ParentType(obj) {
    }

    // Copy constructor: (coords w/o time) -> (coords with time)
    template <typename T> requires (HasNotTimeCoord<T>&& TimeCoord)
      CartesianCoords(const T& coords, DomainWrapper<GridElement>& time_domain)
      : ParentType(coords, time_domain) {
    }

    // Copy constructor: (coords with time) -> (coords w/o time)
    template <typename T>
    CartesianCoords(const T& coords)
      requires (HasTimeCoord<T> && !TimeCoord) : ParentType(coords) {
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
      DomainWrapper<GridElement> domain = ParentType::domains[c];
      Indices inds(total_num_dims);
      inds = 0;
      for (size_t k = 0; k < sz; k++) {
        auto vec = get_vector(f, c, inds);
        size_t dim;

        std::visit([&vec, &nabla](auto&& arg) {
          arg.deriv(vec, 1, nabla, 0);
          }, domain);

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
        DomainWrapper<GridElement> domain = var.domains[c];
        std::visit([&stream](auto&& arg) {
          stream << arg;
          }, domain);
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





};

#endif 
