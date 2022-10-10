#ifndef MATHQ__CURVFIELDS
#define MATHQ__CURVFIELDS 1


namespace mathq {

  template <typename TargetElement, size_t target_rank, IsCurvilinear Coords>
  class
    CurvilinearField;

  //
  // NumericalFunction - multivariable scalar function in Cartesian metric
  //

  template <typename GridElement, size_t Ndims = 1, bool TimeCoord = false, typename TargetElement = GridElement>
  using NumericalFunction = CurvilinearField<TargetElement, 0, CartesianCoords<GridElement, Ndims, TimeCoord>>;

  // ***************************************************************************
  // * CurvilinearField
  // ***************************************************************************

  template <typename TargetElement, size_t target_rank, IsCurvilinear Coords = CartesianCoords<double, 2, false>>
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
    const size_t time = Coords::Ndims_value;

    CurvilinearField() : CurvilinearField(*(new Coords())) {
    }

    CurvilinearField(const std::initializer_list<RealDomainWrapper<CoordGridType>>& mylist) : CurvilinearField(*(new Coords(mylist))) {
    }




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
      // ETV(ParentType());
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



  //
  // nabla ^ f - for vector f
  //

  template <typename TargetElement, IsCurvilinear Coords>
  CurvilinearField<TargetElement, 1, Coords> operator^(const Nabla<>& nabla, const CurvilinearField<TargetElement, 1, Coords>& f) {
    return curl(f, nabla);
  }


  //
  // d(f,c) - for scalar f
  //

  template <typename TargetElement, IsCurvilinear Coords> requires (Coords::total_num_dims == 1)
    auto& d(const CurvilinearField<TargetElement, 0, Coords>& f, const Nabla<>& nabla = Nabla<>()) {
    return pd(f, 0, nabla);
  }

  //
  // pd(f,c) - for  f
  //

  template <typename TargetElement, IsCurvilinear Coords, size_t rank>
  auto& pd(const CurvilinearField<TargetElement, rank, Coords>& f, const size_t c, const Nabla<>& nabla = Nabla<>()) {

    Coords const& coords = f.coords();
    auto& g = *(new CurvilinearField<TargetElement, rank, Coords>(coords));
    for (size_t i = 0; i < g.size(); i++) {
      g[i] = coords.pd(f[i], c, nabla);
    }
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
