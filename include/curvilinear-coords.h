#ifndef MATHQ__CURVCOORDS
#define MATHQ__CURVCOORDS 1


namespace mathq {





  // ***************************************************************************
  //                                 dot product
  //
  // ***************************************************************************


  // template <class GridElement, size_t Ndims>
  // auto dot(const CartesianCoords<GridElement, Ndims>& v1, const CartesianCoords<GridElement, Ndims>& v2) {
  //   return v1 | v2;
  // }



  // ***************************************************************************
  //                                 Coords
  //
  // ***************************************************************************

  template <typename GridElement, size_t Ndims, bool TimeCoord, class Derived, size_t... dim_ints>
  class CurvilinearCoords;

  template <class GridElement, size_t Ndims, bool TimeCoord>
  class CartesianCoords;
  template <class GridElement, bool TimeCoord>
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


  // template <typename GridElement, size_t Ndims, bool TimeCoord>
  // class CurvilinearCoordsTrait {
  // public:
  //   static constexpr size_t total_num_dims = Ndims + size_t(TimeCoord);
  // };

  // template <typename Element, size_t Ndims, bool TimeCoord>
  // class CurvilinearCoordsTrait<std::complex<Element>, Ndims, TimeCoord> {
  // public:
  //   static constexpr size_t total_num_dims = 2*Ndims + size_t(TimeCoord);
  // };


  // ***************************************************************************
  // * CurvilinearCoords 
  // ***************************************************************************

//   // additional deduction guide
// template<class Iter>
// container(Iter b, Iter e) -> container<typename std::iterator_traits<Iter>::value_type>;

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
    using CoordGridType = ElementType;

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

    std::vector<RealDomainWrapper<GridElement>> domains;


    CurvilinearCoords() : ParentType() {
      setup_vector_indices();
    }

    CurvilinearCoords(const std::initializer_list<RealDomainWrapper<GridElement>>& mylist) : ParentType() {
      // OUTPUT("initializer_list<RealDomainWrapper");
      setup_vector_indices();
      *this = mylist;
    }

    CurvilinearCoords(const std::list<RealDomainWrapper<GridElement>>& mylist) : ParentType() {
      // OUTPUT("initializer_list<RealDomainWrapper");
      setup_vector_indices();
      *this = mylist;
    }

    CurvilinearCoords(const CurvilinearCoords& coords) : ParentType() {
      setup_vector_indices();
      *this = coords;
    }


    // Copy constructor: (coords w/o time) -> (coords with time)
    template <typename T>
    CurvilinearCoords(const T& coords, RealDomainWrapper<GridElement>& time_domain)
      requires (HasNotTimeCoord<T>&& TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<RealDomainWrapper<GridElement>> mylist(begin(coords.domains), end(coords.domains));
      mylist.push_back(time_domain); // add time domain
      *this = mylist;
    }

    // Copy constructor: (coords with time) -> (coords w/o time)
    template <typename T>
    CurvilinearCoords(const T& coords)
      requires (HasTimeCoord<T> && !TimeCoord) : ParentType() {
      setup_vector_indices();
      std::list<RealDomainWrapper<GridElement>> mylist(begin(coords.domains), end(coords.domains));
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

    const CoordGridType& coord(size_t g) const {
      return (*this)[g];
    }
    CoordGridType& coord(size_t g) {
      return (*this)[g];
    }

    CoordGridType& set_grid(size_t g) {
      RealDomainWrapper<GridElement> domain = domains[g];
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



    CurvilinearCoords& operator=(const std::initializer_list<RealDomainWrapper<GridElement>>& mylist) {
      *this = std::list<RealDomainWrapper<GridElement>>(mylist);
      return *this;
    }

    CurvilinearCoords& operator=(const std::list<RealDomainWrapper<GridElement>>& mylist) {
      domains.clear();
      Dimensions dims(total_num_dims);
      // get each domain and size
      size_t i = 0;
      typename std::list<RealDomainWrapper<GridElement>>::const_iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it, i++) {
        RealDomainWrapper<GridElement> domain = *it;
        size_t dim;
        std::visit([&dim](auto&& arg) {
          dim = arg.dims()[0];
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
        RealDomainWrapper<GridElement> domain = coords.domains[c];
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
  // * CartesianCoords<GridElement, Ndims>
  // ***************************************************************************


  template <class GridElement, size_t Ndims, bool TimeCoord>
  class CartesianCoords : public CurvilinearCoords<GridElement, Ndims, TimeCoord, CartesianCoords<GridElement, Ndims, TimeCoord>> {
  public:
    using Type = CartesianCoords<GridElement, Ndims, TimeCoord>;
    using TypeWithTime = CartesianCoords<GridElement, Ndims, true>;
    using TypeWithoutTime = CartesianCoords<GridElement, Ndims, false>;

    using ParentType = CurvilinearCoords<GridElement, Ndims, TimeCoord, Type>;
    using CoordGridType = typename ParentType::CoordGridType;

    class Point;  // sub class

    constexpr static bool isNotAbstract = true;
    static constexpr size_t Ndims_value = Ndims;
    static constexpr bool TimeCoord_value = TimeCoord;
    static constexpr size_t total_num_dims = Ndims + size_t(TimeCoord);
    constexpr static bool is_dynamic_value = ParentType::is_dynamic_value;

    //Polar coords: factory, constructor, to method.

    // template<size_t TEMP = Ndims>
    // static EnableMethodIf<TEMP==2, CartesianCoords<GridElement, Ndims>> fromPolar(const GridElement& r, const GridElement& phi) {
    //   GridElement x = r * std::cos(phi);
    //   GridElement y = r * std::sin(phi);
    //   return CartesianCoords<GridElement, Ndims>(x, y);
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP==2)> = 0>
    // explicit CartesianCoords<GridElement, Ndims>(const PolarCoords<GridElement>& v2) {
    //   (*this)[0] = v2.r() * std::cos(v2.phi());
    //   (*this)[1] = v2.r() * std::sin(v2.phi());
    // }
    // template<size_t TEMP = Ndims>
    // EnableMethodIf<TEMP==2, PolarCoords<GridElement>> toPolar() {
    //   return PolarCoords<GridElement>(*this);
    // }


    CartesianCoords() : ParentType(
      list_of_one_value(
        mathq::RealDomainWrapper<GridElement>(Interval<GridElement>::interval(0, 1, 5)),
        total_num_dims
      )
    ) {
    }


    CartesianCoords(const std::initializer_list<mathq::RealDomainWrapper<GridElement>>& mylist) : ParentType(mylist) {
      std::array a = { mylist };
    }


    CartesianCoords(const Type& obj) : ParentType(obj) {
    }

    // Copy constructor: (coords w/o time) -> (coords with time)
    template <typename T> requires (HasNotTimeCoord<T>&& TimeCoord)
      CartesianCoords(const T& coords, RealDomainWrapper<GridElement>& time_domain)
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
        CoordGridType& grid = ParentType::coord(c);
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
    CoordGridType& x()  requires ((Ndims >= 1) && (Ndims <= 3)) {
      return ParentType::coord(0);
    }
    CoordGridType& y()  requires ((Ndims >= 2) && (Ndims <= 3)) {
      return ParentType::coord(1);
    }
    CoordGridType& z()  requires ((Ndims >= 3) && (Ndims <= 3)) {
      return ParentType::coord(2);
    }
    CoordGridType& t()  requires (TimeCoord) {
      return ParentType::coord(Ndims_value);
    }

    // "read only"
    const CoordGridType& x() const requires ((Ndims >= 1) && (Ndims <= 3)) {
      return ParentType::coord(0);
    }
    const CoordGridType& y() const requires ((Ndims >= 2) && (Ndims <= 3)) {
      return ParentType::coord(1);
    }
    const CoordGridType& z() const requires ((Ndims >= 3) && (Ndims <= 3)) {
      return ParentType::coord(2);
    }
    const CoordGridType& t() const requires (TimeCoord) {
      return ParentType::coord(Ndims_value);
    }


    //**********************************************************************
    //                   Named coordinate access: x1,x2,x3,x0
    //**********************************************************************

    // "read/write"

    CoordGridType& x1()  requires ((Ndims >= 1) && (Ndims <= 3)) {
      return ParentType::coord(0);
    }
    CoordGridType& x2()  requires ((Ndims >= 2) && (Ndims <= 3)) {
      return ParentType::coord(1);
    }
    CoordGridType& x3()  requires ((Ndims >= 3) && (Ndims <= 3)) {
      return ParentType::coord(2);
    }
    CoordGridType& x0()  requires (TimeCoord) {
      return ParentType::coord(Ndims_value);
    }

    // "read only"
    const CoordGridType& x1() const requires ((Ndims >= 1) && (Ndims <= 3)) {
      return ParentType::coord(0);
    }
    const CoordGridType& x2() const requires ((Ndims >= 2) && (Ndims <= 3)) {
      return ParentType::coord(1);
    }
    const CoordGridType& x3() const requires ((Ndims >= 3) && (Ndims <= 3)) {
      return ParentType::coord(2);
    }
    const CoordGridType& x0() const requires (TimeCoord) {
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
      // ETV(grid_dims);
      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      MyCoordGridType& mygrid = *(new MyCoordGridType);
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
      RealDomainWrapper<GridElement> domain = ParentType::domains[c];
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

      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      constexpr auto result_dims = array_of_one_value<size_t, 1, Ndims>(); // Vector<Ndims>

      using ResultType = MultiArrayHelper< MyCoordGridType, result_dims >;
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

      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      MyCoordGridType& result = *(new MyCoordGridType);
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

      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      constexpr auto result_dims = array_of_one_value<size_t, 1, Ndims>(); // Vector<Ndims>

      using ResultType = MultiArrayHelper< MyCoordGridType, result_dims >;
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
        RealDomainWrapper<GridElement> domain = var.domains[c];
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







  // ***************************************************************************
  //
  //
  //   PolarCoords<GridElement>(r, phi)
  //
  //
  // TODO: allows 2 (Polar) or 3 Dims (Cylindrical)
  // ***************************************************************************

  template <class GridElement, bool TimeCoord>
  class PolarCoords : public CurvilinearCoords<GridElement, 2, TimeCoord, PolarCoords<GridElement, TimeCoord>> {
  public:

    static constexpr size_t Ndims = 2;
    using Type = PolarCoords<GridElement, TimeCoord>;
    using TypeWithTime = PolarCoords<GridElement, true>;
    using TypeWithoutTime = PolarCoords<GridElement, false>;

    using ParentType = CurvilinearCoords<GridElement, Ndims, TimeCoord, Type>;
    using CoordGridType = typename ParentType::CoordGridType;
    using GridType = MultiArray<GridElement, Ndims>;
    class Point;  // sub class

    constexpr static bool isNotAbstract = true;
    static constexpr size_t Ndims_value = Ndims;
    static constexpr bool TimeCoord_value = TimeCoord;
    static constexpr size_t total_num_dims = Ndims + size_t(TimeCoord);
    constexpr static bool is_dynamic_value = ParentType::is_dynamic_value;

    //     CartesianCoords<GridElement, 2>& toCartesian() const {
    //       return *(new CartesianCoords<GridElement, 2>({ x(), y() }));
    //     }


      //Polar coords: factory, constructor, to method.

      // template<size_t TEMP = Ndims>
      // static EnableMethodIf<TEMP==2, Type> fromPolar(const GridElement& r, const GridElement& phi) {
      //   GridElement x = r * std::cos(phi);
      //   GridElement y = r * std::sin(phi);
      //   return Type(x, y);
      // }
      // template<size_t TEMP = Ndims, EnableIf<(TEMP==2)> = 0>
      // explicit Type(const PolarCoords<GridElement>& v2) {
      //   (*this)[0] = v2.r() * std::cos(v2.phi());
      //   (*this)[1] = v2.r() * std::sin(v2.phi());
      // }
      // template<size_t TEMP = Ndims>
      // EnableMethodIf<TEMP==2, PolarCoords<GridElement>> toPolar() {
      //   return PolarCoords<GridElement>(*this);
      // }



    PolarCoords() : ParentType() {
    }

    PolarCoords(const std::initializer_list<mathq::RealDomainWrapper<GridElement>>& mylist) : ParentType(mylist) {
    }

    PolarCoords(const Type& obj) : ParentType(obj) {
    }

    // Copy constructor: (coords w/o time) -> (coords with time)
    template <typename T> requires (HasNotTimeCoord<T>&& TimeCoord)
      PolarCoords(const T& coords, RealDomainWrapper<GridElement>& time_domain)
      : ParentType(coords, time_domain) {
    }

    // Copy constructor: (coords with time) -> (coords w/o time)
    template <typename T>
    PolarCoords(const T& coords)
      requires (HasTimeCoord<T> && !TimeCoord) : ParentType(coords) {
    }

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




      // coordinates at a grid point
    template <typename... U> requires ((ParentType::is_dynamic_value) && (std::conjunction<std::is_integral<U>...>::value) && (sizeof...(U) == total_num_dims))
      Point& at(const U... args) {
      Point& vec = *(new Point);
      for (size_t c = 0; c < total_num_dims; c++) {
        CoordGridType& grid = ParentType::coord(c);
        vec[c] = grid(args...);
      }
      return vec;
    }



    Type& toCartesian() const {
      return *(new Type(*this));
    }


    // unit vectors
    Vector<GridType, 2>& basis_r() const {
      const CoordGridType& r = (*this)[0];
      const CoordGridType& phi = (*this)[1];
      auto& vec = *(new Vector<GridType, 2>);
      vec[0] = cos(phi);
      vec[1] = sin(phi);
      return vec;
    }
    Vector<GridType, 2>& basis_phi() const {
      const CoordGridType& r = (*this)[0];
      const CoordGridType& phi = (*this)[1];
      auto& vec = *(new Vector<GridType, 2>);
      vec[0] = -sin(phi);
      vec[1] = cos(phi);
      return vec;
    }

    Vector<GridType, 2>& basis_vec(size_t n) const {
      if (n == 0) {
        return basis_r();
      }
      else {
        return basis_phi();
      }
    }

    Vector<Vector<GridType, Ndims>, Ndims>& basis() const {
      Vector<Vector<GridType, Ndims>, Ndims>& vec = *(new Vector<Vector<GridType, Ndims>, Ndims>);
      for (size_t c = 0; c < Ndims; c++) {
        vec[c] = basis_vec(c);
      }
      return vec;
    }



    // Jacobian 
    CoordGridType& J() const {
      CoordGridType& r = *(new CoordGridType);
      r = (*this)[0];
      return r;
    }

    // metric tensor g^{ij} 
    Matrix<GridType, 2, 2> g() const {
      const CoordGridType& r = (*this)[0];
      Matrix<GridType, 2, 2> metric;
      metric(0, 0).resize(r.dims()) = 1;
      metric(0, 1).resize(r.dims()) = 0;
      metric(1, 0).resize(r.dims()) = 0;
      metric(1, 1) = r * r;
      return metric;
    }




    //**********************************************************************
    //  POLAR              Named coordinate access: r,phi,t 
    //**********************************************************************

    // "read/write"
    CoordGridType& r() {
      return (*this)[0];
    }
    CoordGridType& phi() {
      return (*this)[1];
    }
    CoordGridType& t() requires (TimeCoord) {
      return (*this)[2];
    }


    // "read only"

    const CoordGridType& r() const {
      return (*this)[0];
    }
    const CoordGridType& phi() const {
      return (*this)[1];
    }
    const CoordGridType& t() const requires (TimeCoord) {
      return (*this)[2];
    }



    CoordGridType x() const {
      const CoordGridType& r = (*this)[0];
      const CoordGridType& phi = (*this)[1];
      return r * std::cos(phi);
    }
    CoordGridType x1() const {
      return x();
    }

    CoordGridType y() const {
      const CoordGridType& r = (*this)[0];
      const CoordGridType& phi = (*this)[1];
      return r * std::sin(phi);
    }
    CoordGridType x2() const {
      return y();
    }



    //**********************************************************************
    //   POLAR              Derivatives
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
    auto& pd(const T& f, const size_t c, const Nabla<>& nabla = Nabla<>()) const {

      Dimensions grid_dims = ParentType::grid_dims();
      // ETV(grid_dims);
      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      MyCoordGridType& mygrid = *(new MyCoordGridType);
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
      RealDomainWrapper<GridElement> domain = ParentType::domains[c];
      Indices inds(total_num_dims);
      inds = 0;
      for (size_t k = 0; k < sz; k++) {
        auto vec = get_vector(f, c, inds);
        size_t dim;

        const GridElement period = (c == 1) ? 2*3.141592653589793238462643383279 : 0;
        std::visit([&vec, &nabla, &period](auto&& arg) {
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
    auto& grad(const T& f, const Nabla<>& nabla = Nabla<>()) const {

      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      constexpr auto result_dims = array_of_one_value<size_t, 1, Ndims>(); // Vector<Ndims>

      using ResultType = MultiArrayHelper< MyCoordGridType, result_dims >;
      ResultType& result = *(new ResultType);

      result[0] = pd(f, 0, nabla);
      result[1] = pd(f, 1, nabla)/r();
      return result;
    }

    //
    // div(f) - f is a vector
    //

    template <class T>
    auto& div(const T& f, const Nabla<>& nabla = Nabla<>()) const {

      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      MyCoordGridType& result = *(new MyCoordGridType);
      Dimensions grid_dims = ParentType::grid_dims();
      result.resize(grid_dims);
      result = 0;
      MyCoordGridType temp(grid_dims);
      temp = r()*f[0];
      result = result + pd(temp, 0, nabla)/r();
      result = result + pd(f[1], 1, nabla)/r();
      return result;
    }


    //
    // curl(f) - f is a vector of length = 3
    //

    template <class T>
    auto& curl(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires ((IsReadableExpressionOrArray<T>) && (T::rank_value == 1) && (Ndims == 3)) {

      using MyCoordGridType = MultiArray<typename T::NumberType, total_num_dims>;
      constexpr auto result_dims = array_of_one_value<size_t, 1, Ndims>(); // Vector<Ndims>

      using ResultType = MultiArrayHelper< MyCoordGridType, result_dims >;
      ResultType& result = *(new ResultType);
      if constexpr (result.is_dynamic_value) {
        Dimensions grid_dims = ParentType::grid_dims();
        result.resize(grid_dims);
      }
      result[0] = pd(f[2], 1, nabla)/r() - pd(f[1], 2, nabla);
      result[1] = pd(f[0], 2, nabla) - pd(f[2], 0, nabla);
      result[2] = (pd(r()*f[1], 0, nabla) - pd(f[0], 1, nabla))/r();
      return result;
    }

    //
    // df/dr - for convenience
    //

    template <class T>
    auto& pd_r(const T& f, const Nabla<>& nabla = Nabla<>()) const {
      return pd(f, 0, nabla);
    }

    //
    // df/dphi - for convenience
    //

    template <class T>
    auto& pd_phi(const T& f, const Nabla<>& nabla = Nabla<>()) const {
      return pd(f, 1, nabla);
    }


    //
    // df/dt - for convenience
    //

    template <class T>
    auto& pd_t(const T& f, const Nabla<>& nabla = Nabla<>()) const
      requires (TimeCoord) {
      return pd(f, Ndims, nabla);
    }


    //**********************************************************************
    //************************** POLAR Text and debugging ************************
    //**********************************************************************

    // instance classname() method 

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "PolarCoords";
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


    inline friend std::ostream& operator<<(std::ostream& stream, const PolarCoords<GridElement, TimeCoord>& var) {
      stream << "(";
      for (size_t c = 0; c < total_num_dims; c++) {
        if (c>0) stream << "; ";
        stream << var.name(c);
        stream << "=";
        RealDomainWrapper<GridElement> domain = var.domains[c];
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
      if constexpr (Ndims == 2) {
        switch (n) {
        case 0:
          s += "r";
          break;
        case 1:
          s += "𝜑";
          break;
        }
      }
      else if constexpr (Ndims == 3) {
        switch (n) {
        case 0:
          s += "r";
          break;
        case 1:
          s += "𝜑";
          break;
        case 2:
          s += "z";
          break;
        }
      }
      return s;
    }

    class Point : public Vector<GridElement, total_num_dims> {
    public:
      // instance classname() method 

      inline std::string classname() const {
        return ClassName();
      }

      // POLAR static ClassName() method 

      static inline std::string ClassName() {
        using namespace display;
        std::string s = PolarCoords::ClassName();
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
