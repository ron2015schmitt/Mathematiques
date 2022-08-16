#ifndef MATHQ__GRIDS
#define MATHQ__GRIDS 1


namespace mathq {



  template <class GridElementType, size_t Ndims>
  class CartesianCoords;
  template <class GridElementType>
  class PolarCoords;


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
  // Domain<GridElementType>
  //

  template <typename GridElementType>
  class
    Domain {
  };

  //
  // Domain<Reals>
  //
  template <typename GridElementType> requires(IsSimpleNumber<GridElementType>)
    class
    Domain<GridElementType> {
    public:
      size_t N;
      GridElementType a;
      GridElementType b;
      bool include_a;
      bool include_b;
      GridScaleEnum scale;

      // dependent variables
      // move to private
      GridElementType log_a;
      GridElementType log_b;
      size_t Neff;
      GridElementType start;
      GridElementType step;
      mathq::Vector<GridElementType> grid;

      Domain() noexcept {
        include_a = true;
        a = -std::numeric_limits<GridElementType>::infinity();
        include_b = true;
        b = std::numeric_limits<GridElementType>::infinity();
        N = 0;
        this->init();
      }
      Domain(const GridElementType& a, const GridElementType& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) noexcept :
        a(a), b(b), N(N), scale(scale), include_a(include_a), include_b(include_b) {
        refreshGrid();
      }
      ~Domain() {
      }

      mathq::Vector<GridElementType>& getGrid() {
        refreshGrid();
        return grid;
      }
      mathq::Vector<GridElementType>& refreshGrid() {
        grid.resize(N);
        init();
        if (scale == GridScale::LOG) {
          return makeGrid_Log();
        }
        else {
          return makeGrid_Linear();
        }
      }

    private:
      Domain& init() {
        Neff = N +  size_t(!include_a) + size_t(!include_b);
        if (scale == GridScale::LOG) {
          log_a = std::log10(a);
          log_b = std::log10(b);
          step = (log_b - log_a)/static_cast<GridElementType>(Neff-1);
          if (include_a) {
            start = log_a;
          }
          else {
            start = log_a + step;
          }
        }
        else {
          step = (b - a)/static_cast<GridElementType>(Neff-1);
          if (include_a) {
            start = a;
          }
          else {
            start = a + step;
          }
        }
        return *this;
      }

      mathq::Vector<GridElementType>& makeGrid_Linear() {
        if (N == 0) return grid;

        for (size_t c = 0; c<(N-1); c++) {
          grid[c] = start + static_cast<GridElementType>(c)*step;
        }
        if (include_b) {
          grid[N-1] = b;
        }
        else {
          grid[N-1] = b - step;
        }
        return grid;
      }

      mathq::Vector<GridElementType>& makeGrid_Log() {
        if (N == 0) return grid;

        for (size_t c = 0; c<(N-1); c++) {
          grid[c] = std::pow(10, start + static_cast<GridElementType>(c)*step);
        }
        if (include_b) {
          grid[N-1] = b;
        }
        else {
          grid[N-1] = std::pow(10, log_b - step);
        }
        return grid;
      }
    public:


      //
      // static "factor" methods"
      //
      static Domain<GridElementType> emptySet() {
        return Domain<GridElementType>(0, 0, 0, GridScale::LINEAR, false, false);
      }

      static Domain<GridElementType> point(const GridElementType& p) {
        return Domain<GridElementType>(p, p, 1, GridScale::LINEAR, true, true);
      }

      // [a,b]
      static Domain<GridElementType> interval_CC(const GridElementType& a, const GridElementType& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
        return Domain<GridElementType>(a, b, N, scale, true, true);
      }

      // (a,b]
      static Domain<GridElementType> interval_OC(const GridElementType& a, const GridElementType& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
        return Domain<GridElementType>(a, b, N, scale, false, true);
      }

      // [a,b)
      static Domain<GridElementType> interval_CO(const GridElementType& a, const GridElementType& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
        return Domain<GridElementType>(a, b, N, scale, true, false);
      }

      // (a,b)
      static Domain<GridElementType> interval_OO(const GridElementType& a, const GridElementType& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
        return Domain<GridElementType>(a, b, N, scale, false, false);
      }



      static Domain<GridElementType> realLine(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
        GridElementType a;
        if (include_a) {
          a = -std::numeric_limits<GridElementType>::infinity();
        }
        else {
          a = std::numeric_limits<GridElementType>::lowest();
        }
        GridElementType b;
        if (include_b) {
          b = std::numeric_limits<GridElementType>::infinity();
        }
        else {
          b = std::numeric_limits<GridElementType>::max();
        }
        return Domain<GridElementType>(a, b, 0, scale, include_a, include_b);
      }

      static Domain<GridElementType> realLineNeg(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
        GridElementType a;
        if (include_a) {
          a = -std::numeric_limits<GridElementType>::infinity();
        }
        else {
          a = std::numeric_limits<GridElementType>::lowest();
        }
        GridElementType b;
        if (include_b) {
          b = 0;
        }
        else {
          b = -std::numeric_limits<GridElementType>::min();
        }
        return Domain<GridElementType>(a, b, 0, scale, include_a, include_b);
      }

      static Domain<GridElementType> realLinePos(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
        GridElementType a;
        if (include_a) {
          a = 0;
        }
        else {
          a = std::numeric_limits<GridElementType>::min();
        }
        GridElementType b;
        if (include_b) {
          b = std::numeric_limits<GridElementType>::infinity();
        }
        else {
          b = std::numeric_limits<GridElementType>::max();
        }
        return Domain<GridElementType>(a, b, 0, include_a, include_b);
      }



      inline std::string classname() const {
        return ClassName();
      }

      static inline std::string ClassName() {
        using namespace display;
        std::string s = "Domain";
        s += StyledString::get(ANGLE1).get();
        GridElementType d;
        s += getTypeName(d);
        s += StyledString::get(ANGLE2).get();
        return s;
      }


      inline friend std::ostream& operator<<(std::ostream& stream, const Domain& var) {
        using namespace display;
        if (var.a == var.b) {
          // point
          stream << "{point=";
          dispval_strm(stream, var.a);
          // stream << ", gridState=";
          // dispval_strm(stream, (var.grid.size() == 0) ? "deflated" : "inflated");
          stream << "}";
        }
        else {
          stream << "{";
          stream << "interval=";
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

          stream << ", scale=";
          dispval_strm(stream, var.scale);

          // stream << ", gridState=";
          // dispval_strm(stream, (var.grid.size() == 0) ? "deflated" : "inflated");
          stream << "}";
        }
        return stream;
      }



  };



  // ***************************************************************************
  // * CurvilinearCoords 
  // ***************************************************************************

  template <typename GridElementType, size_t Ndims, class Derived, size_t ...dim_ints>
  class
    CurvilinearCoords : public Vector< MultiArray_RepeatVector<GridElementType, Ndims, dim_ints...>, Ndims > {
    // CurvilinearCoords : public Vector< double, Ndims > {
    // CurvilinearCoords : public MultiArray_RepeatVector<GridElementType, Ndims, dim_ints...> {
  public:
    static constexpr size_t Ndims_value = Ndims;

    using Type = CurvilinearCoords<GridElementType, Ndims, Derived, dim_ints...>;
    using ElementType = MultiArray_RepeatVector<GridElementType, Ndims, dim_ints...>;
    using NumberType = GridElementType;
    using SimpleNumberType = typename SimpleNumberTrait<GridElementType>::Type;

    using ParentType = Vector< ElementType, Ndims >;
    using ConcreteType = Vector< MultiArray<GridElementType, Ndims, dim_ints...>, Ndims >;
    using DerivedType = Derived;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;
    using DeepDimensionsType = RecursiveDimensions;

    // using InitializerType = typename MakeInitializer<ElementType, 1 >::Type;  


    // Rank of our multiarray grid is equal to number of dimensions
    // For low dimensions, this type will be Scalar, Vector or Matrix, etc for efficency
    // the dimensions of the multiarray are dynamic

    std::array<Domain<GridElementType>, Ndims> domains;


    CurvilinearCoords() : ParentType() {
      setup_grids();
    }

    CurvilinearCoords(const std::initializer_list<Domain<GridElementType>>& mylist) {
      // setup_grids();
      // *this = mylist;
    }

    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const  Derived& derived() const {
      return static_cast<const Derived&>(*this);
    }

    size_t ndims(void) const {
      return Ndims;
    }


    Type& setup_grids(void) {
      for (size_t c = 0; c < Ndims; c++) {
        (*this)[c].vector_index = c;
      }
      return *this;
    }


    // CurvilinearCoords& init() {
    //   inflateGrids_();
    //   return *this;
    // }

    // CurvilinearCoords& deflateGrids_() {
    //   for (size_t g = 0; g < Ndims; g++) {
    //     get(g).deflateGrid_();
    //     grid[g].resize(0);
    //   }
    //   return *this;
    // }
    // CurvilinearCoords& inflateGrids_() {
    //   const Dimensions gdims = gridDims();
    //   OUTPUT("inflategrids");
    //   TRDISP(gdims);
    //   for (size_t g = 0; g < Ndims; g++) {
    //     Domain<GridElementType>& set = get(g);
    //     set.inflateGrid_();
    //     grid[g].resize(gdims);
    //   }
    //   return *this;
    // }
    // bool hasInflatedGrids_() {
    //   if (Ndims == 0) return false;
    //   for (size_t g = 0; g < Ndims; g++) {
    //     if (!(get(g)).hasInflatedGrid_()) {
    //       return false;
    //     }
    //     if (grid[g].size() == 0) {
    //       return false;
    //     }
    //   }
    //   return true;
    // }

    // inline size_t gridDepth(void) const {
    //   return 1;
    // }

    // size_t gridRank(void) const {
    //   return Ndims;
    // }

    // Dimensions gridDims(void) {
    //   Dimensions dims;
    //   for (size_t g = 0; g < Ndims; g++) {
    //     Domain<GridElementType>& rs = get(g);
    //     dims.push_back(rs.N);
    //   }
    //   return dims;
    // }

    CurvilinearCoords& operator=(const std::initializer_list<Domain<GridElementType>>& mylist) {
      size_t i = 0;
      typename std::initializer_list<Domain<GridElementType>>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it) {
        domains[i++] = *it;
      }
      return *this;
    }


    // Domain<GridElementType>& get(size_t g) {
    //   return (*this)[g];
    // }

    // MULTIGRID& getGrid() {
    //   TRDISP(hasInflatedGrids_());
    //   if (hasInflatedGrids_()) return grid;
    //   return forceRegenGrid();
    // }


    // MULTIGRID& forceRegenGrid() {
    //   init();

    //   if constexpr (Ndims == 0) {
    //     // do something?
    //   }
    //   else if constexpr (Ndims == 1) {
    //     grid = get(0).forceRegenGrid();
    //   }
    //   else if constexpr (Ndims == 2) {
    //     Grid<GridElementType, 1>& xgrid = get(0).forceRegenGrid();
    //     Grid<GridElementType, 1>& ygrid = get(1).forceRegenGrid();
    //     Grid<GridElementType, Ndims>& X = grid[0];
    //     Grid<GridElementType, Ndims>& Y = grid[1];
    //     const size_t Nx = gridDims()[0];
    //     const size_t Ny = gridDims()[1];
    //     X.resize(Nx, Ny);
    //     Y.resize(Nx, Ny);
    //     for (size_t r = 0; r < Nx; r++) {
    //       for (size_t c = 0; c < Ny; c++) {
    //         X(r, c) = xgrid[r];
    //         Y(r, c) = ygrid[c];
    //       }
    //     }
    //   }
    //   else {
    //     for (size_t g = 0; g < Ndims; g++) {
    //       get(g).forceRegenGrid();
    //     }
    //     Indices indices(Ndims);  // all zeros
    //     // TRDISP(indices);
    //     setGrid_(0, indices);
    //     // DISP("DONE");
    //   }
    //   return grid;
    // }

    // void setGrid_(int coord, Indices& indices) {
    //   const size_t Npts = gridDims()[coord];  // grdi size of coord-th coordinate
    //   // MDISP("ENTRY for coord", coord, Npts);
    //   for (int p = 0; p < Npts; p++) {
    //     indices[coord] = p;
    //     if (coord < Ndims-1) {
    //       // OUTPUT("GO TO NEXT coord");
    //       setGrid_(coord+1, indices);
    //     }
    //     else {
    //       // we are inside the last coordinate's loop, ie inside all the loops
    //       // MDISP(coord, p, indices);
    //       for (int g = 0; g < Ndims; g++) {
    //         // this loop is for the Ndims different grids (vectors of size N)
    //         // we set the grid value of each grid
    //         Domain<GridElementType>& rs = get(g);
    //         // MDISP(g, indices[g]);
    //         grid[g][indices] = rs.getGrid()[indices[g]];
    //       }
    //     }
    //   }
    //   // OUTPUT("EXIT");
    // }

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
      GridElementType d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "Ndims=";
      s += num2string(Ndims);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CurvilinearCoords& var) {
      stream << "{\n";
      for (size_t g = 0; g < var.size(); g++) {
        if (g > 0)
          stream << ", \n";
        stream << "  ";
        display::dispval_strm(stream, var[g]);
      }
      stream << "\n}}";
      return stream;
    }


  };


  //   // ***************************************************************************
  //   // * CurvilinearCoords<GridElementType, Ndims>
  //   // ***************************************************************************

  //   template <class GridElementType, size_t Ndims, class CHILD>
  //   class CurvilinearCoords : public Vector<GridElementType, Ndims> {
  //   public:
  //     typedef CurvilinearCoords<GridElementType, Ndims, CHILD> CLASS;
  //     typedef Vector<GridElementType, Ndims> PARENT;

  //     CHILD& child() {
  //       return static_cast<CHILD&>(*this);
  //     }
  //     const  CHILD& child() const {
  //       return static_cast<const CHILD&>(*this);
  //     }


  //     // Jacobian 
  //     GridElementType J() const {
  //       return child().J();
  //     }

  //     // metric tensor g^{ij} 
  //     Matrix<GridElementType, Ndims, Ndims> g() const {
  //       return child().g();
  //     }
  //     // CartesianCoords<GridElementType, Ndims>& pos() const {
  //     //   return child().pos();
  //     // }
  //     // CartesianCoords<GridElementType, Ndims>& toCartesian() const {
  //     //   return child().toCartesian();
  //     // }
  //     Vector<GridElementType, Ndims>& basis_vec(size_t n) const {
  //       return child().basis_vec();
  //     }



  //     std::array<std::string, Ndims>& names() const {
  //       return child().names();
  //     }

  //     const std::string& name(size_t n) const {
  //       return child().name(n);
  //     }

  //     inline std::string classname() const {
  //       return child().classname();
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const CLASS& var) {
  //       return stream << var.child();
  //     }


  //   };


    // ***************************************************************************
    // * CartesianCoords<GridElementType, Ndims>
    // ***************************************************************************

  template <class GridElementType, size_t Ndims>
  class CartesianCoords : public CurvilinearCoords<GridElementType, Ndims, CartesianCoords<GridElementType, Ndims>> {
  public:

    using ParentType = CurvilinearCoords<GridElementType, Ndims, CartesianCoords<GridElementType, Ndims>>;

    // template<size_t TEMP = Ndims>
    // static EnableMethodIf<TEMP==2, CartesianCoords<GridElementType, Ndims>> fromPolar(const GridElementType& r, const GridElementType& phi) {
    //   GridElementType x = r * std::cos(phi);
    //   GridElementType y = r * std::sin(phi);
    //   return CartesianCoords<GridElementType, Ndims>(x, y);
    // }
    // template<size_t TEMP = Ndims>
    // EnableMethodIf<TEMP==2, PolarCoords<GridElementType>> toPolar() {
    //   return PolarCoords<GridElementType>(*this);
    // }


    explicit CartesianCoords() : ParentType() {
    }

    explicit CartesianCoords(const std::initializer_list<Domain<GridElementType>>& mylist) : ParentType(mylist) {
    }

    explicit CartesianCoords(const CartesianCoords<GridElementType, Ndims>& v2) {
      // BASE& me = *this;
      // me = v2;
    }

    // std::array<std::string, Ndims>& names() const {
    //   std::array<std::string, Ndims> names;
    //   for (size_t c = 0; c < Ndims; c++) {
    //     names[c] = name(c);
    //   }
    //   return names;
    // }

    const std::string& name(size_t n) const {
      std::string* s = new std::string("x");
      *s += std::to_string(n+1);
      return *s;
    }


    // // Jacobian 
    // GridElementType& J() const {
    //   GridElementType* jacob = new GridElementType();
    //   *jacob = 1;
    //   return *jacob;
    // }

    // // metric tensor g^{ij} 
    // Matrix<GridElementType, Ndims, Ndims> g() const {
    //   Matrix<GridElementType, Ndims, Ndims> metric;
    //   for (size_t r = 0; r < Ndims; r++) {
    //     for (size_t c = 0; c < Ndims; c++) {
    //       metric(r, c) = (r==c) ? 1 : 0;
    //     }
    //   }
    //   return metric;
    // }

    // CartesianCoords<GridElementType, Ndims>& pos() const {
    //   return toCartesian();
    // }
    // CartesianCoords<GridElementType, Ndims>& toCartesian() const {
    //   return *(new CartesianCoords<GridElementType, Ndims>(*this));
    // }

    // Vector<GridElementType, Ndims>& basis_vec(size_t n) const {
    //   Vector<GridElementType, Ndims>* vec = new Vector<GridElementType, Ndims>(0);
    //   (*vec)[n] = 1;
    //   return *vec;
    // }


    inline std::string classname() const {
      using namespace display;
      std::string s = "CartesianCoords";
      s += StyledString::get(ANGLE1).get();
      GridElementType d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += std::to_string(Ndims);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CartesianCoords<GridElementType, Ndims>& var) {
      stream << "(";
      for (size_t c = 0; c < Ndims; c++) {
        if (c>0) stream << ", ";
        stream << var.name(c);
        stream << "=";
        stream << var.domains[c];
      }
      stream << ")";
      return stream;
    }



    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // GridElementType& x1() const {
    //   return (*this)[0];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // CartesianCoords<GridElementType, Ndims>& x1(const GridElementType& x1) const {
    //   (*this)[0] = x1;
    //   return *this;
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // GridElementType& x() const {
    //   return (*this)[0];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
    // CartesianCoords<GridElementType, Ndims>& x(const GridElementType& x) const {
    //   (*this)[0] = x;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // GridElementType& x2() const {
    //   return (*this)[1];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // CartesianCoords<GridElementType, Ndims>& x2(const GridElementType& x2) const {
    //   (*this)[1] = x2;
    //   return *this;
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // GridElementType& y() const {
    //   return (*this)[1];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
    // CartesianCoords<GridElementType, Ndims>& y(const GridElementType& y) const {
    //   (*this)[1] = y;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // GridElementType& x3() const {
    //   return (*this)[2];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // CartesianCoords<GridElementType, Ndims>& x3(const GridElementType& x3) const {
    //   (*this)[2] = x3;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // GridElementType& z() const {
    //   return (*this)[2];
    // }
    // template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
    // CartesianCoords<GridElementType, Ndims>& z(const GridElementType& z) const {
    //   (*this)[2] = z;
    //   return *this;
    // }

    // template<size_t TEMP = Ndims, EnableIf<(TEMP==2)> = 0>
    // explicit CartesianCoords<GridElementType, Ndims>(const PolarCoords<GridElementType>& v2) {
    //   (*this)[0] = v2.r() * std::cos(v2.phi());
    //   (*this)[1] = v2.r() * std::sin(v2.phi());
    // }

  };



  template <class GridElementType, size_t Ndims>
  auto dot(const CartesianCoords<GridElementType, Ndims>& v1, const CartesianCoords<GridElementType, Ndims>& v2) {
    return v1 | v2;
  }




  //   // ***************************************************************************
  //   // * PolarCoords<GridElementType>(r, phi)
  //   // ***************************************************************************

  //   template <class GridElementType>
  //   class PolarCoords : public CurvilinearCoords<GridElementType, 2, PolarCoords<GridElementType>> {
  //   public:
  //     typedef PolarCoords<GridElementType> CLASS;
  //     typedef CurvilinearCoords<GridElementType, 2, CLASS> PARENT;
  //     typedef typename PARENT::PARENT BASE;

  //     static PolarCoords<GridElementType> fromCartesian(GridElementType x, GridElementType y) {
  //       return PolarCoords<GridElementType>(std::sqrt(x*x + y*y), std::atan2(y, x));
  //     }

  //     PolarCoords(const GridElementType r, const GridElementType phi) {
  //       (*this)[0] = r;
  //       (*this)[1] = phi;
  //     }
  //     PolarCoords(const std::initializer_list<GridElementType>& mylist) {
  //       BASE& me = *this;
  //       me = mylist;
  //     }

  //     PolarCoords(const PolarCoords<GridElementType>& v2) {
  //       BASE& me = *this;
  //       me = v2;
  //     }

  //     PolarCoords(const CartesianCoords<GridElementType, 2>& v2) {
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


  //     GridElementType& r() const {
  //       return (*this)[0];
  //     }
  //     GridElementType& phi() const {
  //       return (*this)[1];
  //     }

  //     PolarCoords<GridElementType>& r(const GridElementType& r) const {
  //       (*this)[0] = r;
  //       return *this;
  //     }
  //     PolarCoords<GridElementType>& phi(const GridElementType& phi) const {
  //       (*this)[1] = phi;
  //       return *this;
  //     }


  //     GridElementType x() const {
  //       const GridElementType& r = (*this)[0];
  //       const GridElementType& phi = (*this)[1];
  //       return r * std::cos(phi);
  //     }
  //     GridElementType x1() const {
  //       return x();
  //     }

  //     GridElementType y() const {
  //       const GridElementType& r = (*this)[0];
  //       const GridElementType& phi = (*this)[1];
  //       return r * std::sin(phi);
  //     }
  //     GridElementType x2() const {
  //       return y();
  //     }


  //     CartesianCoords<GridElementType, 2>& pos() const {
  //       return toCartesian();
  //     }
  //     CartesianCoords<GridElementType, 2>& toCartesian() const {
  //       return *(new CartesianCoords<GridElementType, 2>({ x(), y() }));
  //     }


  //     // unit vectors
  //     Vector<GridElementType, 2>& basis_r() const {
  //       const GridElementType& r = (*this)[0];
  //       const GridElementType& phi = (*this)[1];
  //       return *(new Vector<GridElementType, 2>{ std::cos(phi), std::sin(phi) });
  //     }
  //     Vector<GridElementType, 2>& basis_phi() const {
  //       const GridElementType& r = (*this)[0];
  //       const GridElementType& phi = (*this)[1];
  //       return *(new Vector<GridElementType, 2>{ -std::sin(phi), std::cos(phi) });
  //     }

  //     Vector<GridElementType, 2>& basis_vec(size_t n) const {
  //       if (n == 0) {
  //         return basis_r();
  //       }
  //       else {
  //         return basis_phi();
  //       }
  //     }


  //     // Jacobian 
  //     GridElementType J() const {
  //       const GridElementType& r = (*this)[0];
  //       const GridElementType& phi = (*this)[1];
  //       return r;
  //     }

  //     // metric tensor g^{ij} 
  //     Matrix<GridElementType, 2, 2> g() const {
  //       const GridElementType& r = (*this)[0];
  //       const GridElementType& phi = (*this)[1];
  //       Matrix<GridElementType, 2, 2> metric;
  //       metric = { ones<GridElementType>(), zeros<GridElementType>(), zeros<GridElementType>(), r*r };
  //       return metric;
  //     }

  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "PolarCoords";
  //       s += StyledString::get(ANGLE1).get();
  //       GridElementType d;
  //       s += getTypeName(d);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const PolarCoords<GridElementType>& var) {
  //       const GridElementType& r = var[0];
  //       const GridElementType& phi = var[1];
  //       stream << "(r=";
  //       stream << r;
  //       stream << ", φ=";
  //       stream << phi;
  //       stream << ")";
  //       return stream;
  //     }


  //   };


  //   template <class GridElementType>
  //   auto dot(const PolarCoords<GridElementType>& v1, const PolarCoords<GridElementType>& v2) {
  //     return v1[0] * v2[0] * std::cos(v1[1] - v2[1]);
  //   }

  //   // template <class GridElementType>
  //   // auto& addpts(const PolarCoords<GridElementType>& v1, const PolarCoords<GridElementType>& v2) {
  //   //   const Vector<GridElementType, 2> p = v1.toCartesian() + v2.toCartesian();
  //   //   return p.toPolar();
  //   // }

  //   // TODO: pmult for scalar * PolarCoords


  //   // ***************************************************************************
  //   // * PolarField<GridElementType,RANK>
  //   //
  //   // physics field object: scalar field, vector field, tensor field 
  //   // uses curvilinear coordinates
  //   // ***************************************************************************
  //   template <typename GridElementType, size_t RANK> class PolarField : public MultiGrid_A<GridElementType, 2, RANK> {
  //   public:
  //     using Coords = PolarCoords<GridElementType>;
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
  //       GridElementType d;
  //       s += getTypeName(d);
  //       s += StyledString::get(COMMA).get();
  //       s += "RANK=";
  //       s += num2string(RANK);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const PolarField<GridElementType, RANK>& var) {
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
  //   // CurvilinearCoordinateSystem<GridElementType>
  //   //

  //   //   template <typename... U>
  //     // typename std::enable_if<(std::is_same<U, GridElementType>::value && ...), const GridElementType>::type operator()(const U... args) 
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

  //   template <typename GridElementType, size_t Ndims, typename CHILD>
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
  //       GridElementType d;
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


  //   template <typename GridElementType>
  //   class
  //     PolarCoordSystem : public CurvilinearCoordinateSystem<GridElementType, 2, PolarCoordSystem<GridElementType>> {
  //   public:
  //     using Func = std::function<GridElementType(GridElementType, GridElementType)>;
  //     using VecFunc = std::function<Vector<GridElementType, 2>(GridElementType, GridElementType)>;
  //     using Coords = PolarCoords<GridElementType>;


  //     PolarCoordSystem() {
  //     }


  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "PolarCoordSystem";
  //       s += StyledString::get(ANGLE1).get();
  //       GridElementType d;
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


    // template <typename GridElementType>
    // using PolarCoords = typename PolarCoordSystem<GridElementType>::Coords;

    // template <typename GridElementType = double>
    // auto dot(const typename PolarCoordSystem<GridElementType>::Coords& v1, const typename PolarCoordSystem<GridElementType>::Coords& v2) {
    //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
    // }


    // template <typename GridElementType, template <typename> class T>
    // auto dot(const typename T<GridElementType>::Coords& v1, const typename T<GridElementType>::Coords& v2) {
    //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
    // }

    // template <typename GridElementType>
    // auto dot(const typename PolarCoordSystem<GridElementType>::Coords& v1, const typename PolarCoordSystem<GridElementType>::Coords& v2) {
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

    // template <typename GridElementType, typename = typename std::enable_if<std::is_arithmetic<GridElementType>::value, GridElementType>::type>
    // auto grad(const Vector<GridElementType>& gridfunc, const Interval<GridElementType>& range, const int Dpts = 7, const bool periodic = false) {
    //   const size_t N = gridfunc.size();
    //   Vector<GridElementType>* df = new Vector<GridElementType>(N);
    //   *df = gridfunc;
    //   df->deriv(range.a, range.b, 1, Dpts, periodic);
    //   return *df;
    // }

    // template <typename GridElementType, typename = typename std::enable_if<std::is_arithmetic<GridElementType>::value, GridElementType>::type>
    // auto operator&(const Nabla_old<void> i, std::pair<Vector<GridElementType>, Interval<GridElementType>> funcANDrange) {
    //   return grad(funcANDrange.first, funcANDrange.second);
    // }

    // // 
    // // 2D
    // //

    // // template <typename GridElementType, typename = typename std::enable_if<std::is_arithmetic<GridElementType>::value, GridElementType>::type>
    // // auto fgrid(std::function<GridElementType(GridElementType, GridElementType)> func, const Vector<Matrix<GridElementType>, 2>& grid) {
    // //   const Matrix<GridElementType>& X = grid(0);
    // //   const Matrix<GridElementType>& Y = grid(1);
    // //   auto* y = new Matrix<GridElementType>(X.Nrows(), X.Ncols());
    // //   for (int k = 0; k < X.size(); k++) {
    // //     (*y)[k] = func(X[k], Y[k]);
    // //   }
    // //   return *y;
    // // }

    // template <typename GridElementType, typename = typename std::enable_if<std::is_arithmetic<GridElementType>::value, GridElementType>::type>
    // auto grad(const Matrix<GridElementType>& gridfunc, const Interval<GridElementType>& domX, const Interval<GridElementType>& domY, const int Dpts = 7, const bool periodic = false) {

    //   // TODO: rewrite with slices

    //   const size_t NR = gridfunc.Nrows();
    //   const size_t NC = gridfunc.Ncols();
    //   Vector<Matrix<GridElementType>, 2>* df = new Vector<Matrix<GridElementType>, 2>();
    //   // starts off with empty matrices
    //   // TRDISP(*df);

    //   // take d/dx
    //   Vector<GridElementType> vtemp = Vector<GridElementType>(NC);
    //   Matrix<GridElementType> mtemp = Matrix<GridElementType>(NR, NC);
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

    // template <typename GridElementType, typename = typename std::enable_if<std::is_arithmetic<GridElementType>::value, GridElementType>::type>
    // auto operator&(const Nabla_old<void> i, std::tuple<Matrix<GridElementType>, Interval<GridElementType>, Interval<GridElementType>> funcANDrange) {
    //   return grad(std::get<0>(funcANDrange), std::get<1>(funcANDrange), std::get<2>(funcANDrange));
    // }







};

#endif 
