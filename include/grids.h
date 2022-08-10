#ifndef MATHQ__GRIDS
#define MATHQ__GRIDS 1


namespace mathq {



  template <class Element, size_t Ndims>
  class CartCoords;
  template <class Element>
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
  // RealSet<Number>
  //

  template <typename Number>
  class
    RealSet {
  public:
    size_t N;
    Number a;
    Number b;
    bool include_a;
    bool include_b;
    GridScaleEnum scale;

    // dependent variables
    // move to private
    Number log_a;
    Number log_b;
    size_t Neff;
    Number start;
    Number step;
    mathq::Vector<Number> grid;

    RealSet() noexcept {
      include_a = true;
      a = -std::numeric_limits<Number>::infinity();
      include_b = true;
      b = std::numeric_limits<Number>::infinity();
      N = 0;
      this->init_();
    }
    RealSet(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) noexcept :
      a(a), b(b), N(N), scale(scale), include_a(include_a), include_b(include_b) {
      refreshGrid();
    }
    ~RealSet() {
    }

    mathq::Vector<Number>& getGrid() {
      refreshGrid();
      return grid;
    }
    mathq::Vector<Number>& refreshGrid() {
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
    RealSet& init() {
      Neff = N +  size_t(!include_a) + size_t(!include_b);
      if (scale == GridScale::LOG) {
        log_a = std::log10(a);
        log_b = std::log10(b);
        step = (log_b - log_a)/static_cast<Number>(Neff-1);
        if (include_a) {
          start = log_a;
        }
        else {
          start = log_a + step;
        }
      }
      else {
        step = (b - a)/static_cast<Number>(Neff-1);
        if (include_a) {
          start = a;
        }
        else {
          start = a + step;
        }
      }
      return *this;
    }

    mathq::Vector<Number>& makeGrid_Linear() {
      if (N == 0) return grid;

      for (size_t c = 0; c<(N-1); c++) {
        grid[c] = start + static_cast<Number>(c)*step;
      }
      if (include_b) {
        grid[N-1] = b;
      }
      else {
        grid[N-1] = b - step;
      }
      return grid;
    }

    mathq::Vector<Number>& makeGrid_Log() {
      if (N == 0) return grid;

      for (size_t c = 0; c<(N-1); c++) {
        grid[c] = std::pow(10, start + static_cast<Number>(c)*step);
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

    static RealSet<Number> emptySet() {
      return RealSet<Number>(0, 0, 0, GridScale::LINEAR, false, false);
    }

    static RealSet<Number> point(const Number& p) {
      return RealSet<Number>(p, p, 1, GridScale::LINEAR, true, true);
    }

    // [a,b]
    static RealSet<Number> interval_CC(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, true, true);
    }

    // (a,b]
    static RealSet<Number> interval_OC(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, false, true);
    }

    // [a,b)
    static RealSet<Number> interval_CO(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, true, false);
    }

    // (a,b)
    static RealSet<Number> interval_OO(const Number& a, const Number& b, const size_t N, const GridScaleEnum& scale = GridScale::LINEAR) {
      return RealSet<Number>(a, b, N, scale, false, false);
    }



    static RealSet<Number> realLine(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      Number a;
      if (include_a) {
        a = -std::numeric_limits<Number>::infinity();
      }
      else {
        a = std::numeric_limits<Number>::lowest();
      }
      Number b;
      if (include_b) {
        b = std::numeric_limits<Number>::infinity();
      }
      else {
        b = std::numeric_limits<Number>::max();
      }
      return RealSet<Number>(a, b, 0, scale, include_a, include_b);
    }

    static RealSet<Number> realLineNeg(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      Number a;
      if (include_a) {
        a = -std::numeric_limits<Number>::infinity();
      }
      else {
        a = std::numeric_limits<Number>::lowest();
      }
      Number b;
      if (include_b) {
        b = 0;
      }
      else {
        b = -std::numeric_limits<Number>::min();
      }
      return RealSet<Number>(a, b, 0, scale, include_a, include_b);
    }

    static RealSet<Number> realLinePos(const GridScaleEnum& scale = GridScale::LINEAR, const bool include_a = true, const bool include_b = true) {
      Number a;
      if (include_a) {
        a = 0;
      }
      else {
        a = std::numeric_limits<Number>::min();
      }
      Number b;
      if (include_b) {
        b = std::numeric_limits<Number>::infinity();
      }
      else {
        b = std::numeric_limits<Number>::max();
      }
      return RealSet<Number>(a, b, 0, include_a, include_b);
    }



    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "RealSet";
      s += StyledString::get(ANGLE1).get();
      Number d;
      s += getTypeName(d);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const RealSet& var) {
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

  template <class Derived, typename Number, size_t Ndims, size_t ...dim_ints>
  class
    CurvilinearCoords : public Vector< MultiArray_RepeatVector<Number, Ndims, dim_ints...>, Ndims > {
  public:
    using Type = CurvilinearCoords<Derived, Number, Ndims, dim_ints...>;
    
    using ElementType = Number;
    using NumberType = typename NumberTrait<Number>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using ParentType = Vector< MultiArray_RepeatVector<Number, Ndims, dim_ints...>, Ndims >;
    using ConcreteType = Vector< MultiArray<Number, Ndims, dim_ints...>, Ndims >;
    using DerivedType = Derived;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;
    using DeepDimensionsType = RecursiveDimensions;

    // using InitializerType = typename MakeInitializer<ElementType, 1 >::Type;  

    static constexpr size_t Ndims_value = Ndims;

    // Rank of our multiarray grid is equal to number of dimensions
    // For low dimensions, this type will be Scalar, Vector or Matrix, etc for efficency
    // the dimensions of the multiarray are dynamic

    // std::array<RealSet<Number>, Ndims> rsets;


    CurvilinearCoords(const std::initializer_list<RealSet<Number>>& mylist) {
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

    // CurvilinearCoords& init_() {
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
    //     RealSet<Number>& set = get(g);
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
    //     RealSet<Number>& rs = get(g);
    //     dims.push_back(rs.N);
    //   }
    //   return dims;
    // }

    // CurvilinearCoords& operator=(const std::initializer_list<RealSet<Number>>& mylist) {
    //   size_t i = 0;
    //   typename std::initializer_list<RealSet<Number>>::iterator it;
    //   for (it = mylist.begin(); it != mylist.end(); ++it) {
    //     (*this)[i++] = *it;
    //   }
    //   return *this;
    // }


    // RealSet<Number>& get(size_t g) {
    //   return (*this)[g];
    // }

    // MULTIGRID& getGrid() {
    //   TRDISP(hasInflatedGrids_());
    //   if (hasInflatedGrids_()) return grid;
    //   return forceRegenGrid();
    // }


    // MULTIGRID& forceRegenGrid() {
    //   init_();

    //   if constexpr (Ndims == 0) {
    //     // do something?
    //   }
    //   else if constexpr (Ndims == 1) {
    //     grid = get(0).forceRegenGrid();
    //   }
    //   else if constexpr (Ndims == 2) {
    //     Grid<Number, 1>& xgrid = get(0).forceRegenGrid();
    //     Grid<Number, 1>& ygrid = get(1).forceRegenGrid();
    //     Grid<Number, Ndims>& X = grid[0];
    //     Grid<Number, Ndims>& Y = grid[1];
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
    //         RealSet<Number>& rs = get(g);
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
      Number d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "Ndims=";
      s += num2string(Ndims);
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const CurvilinearCoords& var) {
      stream << "{ ";
      stream << "gridState=";
      display::dispval_strm(stream, (var.grid.size() == 0) ? "deflated" : "inflated");
      stream << ", {\n";
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
  //   // * CurvilinearCoords<Number, Ndims>
  //   // ***************************************************************************

  //   template <class Element, size_t Ndims, class CHILD>
  //   class CurvilinearCoords : public Vector<Element, Ndims> {
  //   public:
  //     typedef CurvilinearCoords<Element, Ndims, CHILD> CLASS;
  //     typedef Vector<Element, Ndims> PARENT;

  //     CHILD& child() {
  //       return static_cast<CHILD&>(*this);
  //     }
  //     const  CHILD& child() const {
  //       return static_cast<const CHILD&>(*this);
  //     }


  //     // Jacobian 
  //     Element J() const {
  //       return child().J();
  //     }

  //     // metric tensor g^{ij} 
  //     Matrix<Element, Ndims, Ndims> g() const {
  //       return child().g();
  //     }
  //     // CartCoords<Element, Ndims>& pos() const {
  //     //   return child().pos();
  //     // }
  //     // CartCoords<Element, Ndims>& toCartesian() const {
  //     //   return child().toCartesian();
  //     // }
  //     Vector<Element, Ndims>& basis_vec(size_t n) const {
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


  //   // ***************************************************************************
  //   // * CartCoords<Number, Ndims>
  //   // ***************************************************************************

  //   template <class Element, size_t Ndims>
  //   class CartCoords : public CurvilinearCoords<Element, Ndims, CartCoords<Element, Ndims>> {
  //   public:
  //     typedef CartCoords<Element, Ndims> CLASS;
  //     typedef CurvilinearCoords<Element, Ndims, CLASS> PARENT;
  //     typedef typename PARENT::PARENT BASE;
  //     static int ron() {
  //       return Ndims;
  //     }

  //     template<size_t TEMP = Ndims>
  //     static EnableMethodIf<TEMP==2, CartCoords<Element, Ndims>> fromPolar(const Element& r, const Element& phi) {
  //       Element x = r * std::cos(phi);
  //       Element y = r * std::sin(phi);
  //       return CartCoords<Element, Ndims>(x, y);
  //     }
  //     template<size_t TEMP = Ndims>
  //     EnableMethodIf<TEMP==2, PolarCoords<Element>> toPolar() {
  //       return PolarCoords<Element>(*this);
  //     }


  //     explicit CartCoords(const std::initializer_list<Element>& mylist) {
  //       BASE& me = *this;
  //       me = mylist;
  //     }

  //     explicit CartCoords(const CartCoords<Element, Ndims>& v2) {
  //       BASE& me = *this;
  //       me = v2;
  //     }

  //     std::array<std::string, Ndims>& names() const {
  //       std::array<std::string, Ndims> names;
  //       for (size_t c = 0; c < Ndims; c++) {
  //         names[c] = name(c);
  //       }
  //       return names;
  //     }

  //     const std::string& name(size_t n) const {
  //       std::string* s = new std::string("x");
  //       *s += std::to_string(n+1);
  //       return *s;
  //     }


  //     // Jacobian 
  //     Element& J() const {
  //       Element* jacob = new Element();
  //       *jacob = 1;
  //       return *jacob;
  //     }

  //     // metric tensor g^{ij} 
  //     Matrix<Element, Ndims, Ndims> g() const {
  //       Matrix<Element, Ndims, Ndims> metric;
  //       for (size_t r = 0; r < Ndims; r++) {
  //         for (size_t c = 0; c < Ndims; c++) {
  //           metric(r, c) = (r==c) ? 1 : 0;
  //         }
  //       }
  //       return metric;
  //     }

  //     CartCoords<Element, Ndims>& pos() const {
  //       return toCartesian();
  //     }
  //     CartCoords<Element, Ndims>& toCartesian() const {
  //       return *(new CartCoords<Element, Ndims>(*this));
  //     }

  //     Vector<Element, Ndims>& basis_vec(size_t n) const {
  //       Vector<Element, Ndims>* vec = new Vector<Element, Ndims>(0);
  //       (*vec)[n] = 1;
  //       return *vec;
  //     }


  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "CartCoords";
  //       s += StyledString::get(ANGLE1).get();
  //       Element d;
  //       s += getTypeName(d);
  //       s += StyledString::get(COMMA).get();
  //       s += std::to_string(Ndims);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const CartCoords<Element, Ndims>& var) {
  //       stream << "(";
  //       for (size_t c = 0; c < Ndims; c++) {
  //         if (c>0) stream << ", ";
  //         stream << var.name(c);
  //         stream << "=";
  //         stream << var[c];
  //       }
  //       stream << ")";
  //       return stream;
  //     }



  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
  //     Element& x1() const {
  //       return (*this)[0];
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
  //     CartCoords<Element, Ndims>& x1(const Element& x1) const {
  //       (*this)[0] = x1;
  //       return *this;
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
  //     Element& x() const {
  //       return (*this)[0];
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=1)> = 0>
  //     CartCoords<Element, Ndims>& x(const Element& x) const {
  //       (*this)[0] = x;
  //       return *this;
  //     }

  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
  //     Element& x2() const {
  //       return (*this)[1];
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
  //     CartCoords<Element, Ndims>& x2(const Element& x2) const {
  //       (*this)[1] = x2;
  //       return *this;
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
  //     Element& y() const {
  //       return (*this)[1];
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=2)> = 0>
  //     CartCoords<Element, Ndims>& y(const Element& y) const {
  //       (*this)[1] = y;
  //       return *this;
  //     }

  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
  //     Element& x3() const {
  //       return (*this)[2];
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
  //     CartCoords<Element, Ndims>& x3(const Element& x3) const {
  //       (*this)[2] = x3;
  //       return *this;
  //     }

  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
  //     Element& z() const {
  //       return (*this)[2];
  //     }
  //     template<size_t TEMP = Ndims, EnableIf<(TEMP>=3)> = 0>
  //     CartCoords<Element, Ndims>& z(const Element& z) const {
  //       (*this)[2] = z;
  //       return *this;
  //     }

  //     template<size_t TEMP = Ndims, EnableIf<(TEMP==2)> = 0>
  //     explicit CartCoords<Element, Ndims>(const PolarCoords<Element>& v2) {
  //       (*this)[0] = v2.r() * std::cos(v2.phi());
  //       (*this)[1] = v2.r() * std::sin(v2.phi());
  //     }

  //   };



  //   template <class Element, size_t Ndims>
  //   auto dot(const CartCoords<Element, Ndims>& v1, const CartCoords<Element, Ndims>& v2) {
  //     return v1 | v2;
  //   }




  //   // ***************************************************************************
  //   // * PolarCoords<Number>(r, phi)
  //   // ***************************************************************************

  //   template <class Element>
  //   class PolarCoords : public CurvilinearCoords<Element, 2, PolarCoords<Element>> {
  //   public:
  //     typedef PolarCoords<Element> CLASS;
  //     typedef CurvilinearCoords<Element, 2, CLASS> PARENT;
  //     typedef typename PARENT::PARENT BASE;

  //     static PolarCoords<Element> fromCartesian(Element x, Element y) {
  //       return PolarCoords<Element>(std::sqrt(x*x + y*y), std::atan2(y, x));
  //     }

  //     PolarCoords(const Element r, const Element phi) {
  //       (*this)[0] = r;
  //       (*this)[1] = phi;
  //     }
  //     PolarCoords(const std::initializer_list<Element>& mylist) {
  //       BASE& me = *this;
  //       me = mylist;
  //     }

  //     PolarCoords(const PolarCoords<Element>& v2) {
  //       BASE& me = *this;
  //       me = v2;
  //     }

  //     PolarCoords(const CartCoords<Element, 2>& v2) {
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


  //     Element& r() const {
  //       return (*this)[0];
  //     }
  //     Element& phi() const {
  //       return (*this)[1];
  //     }

  //     PolarCoords<Element>& r(const Element& r) const {
  //       (*this)[0] = r;
  //       return *this;
  //     }
  //     PolarCoords<Element>& phi(const Element& phi) const {
  //       (*this)[1] = phi;
  //       return *this;
  //     }


  //     Element x() const {
  //       const Element& r = (*this)[0];
  //       const Element& phi = (*this)[1];
  //       return r * std::cos(phi);
  //     }
  //     Element x1() const {
  //       return x();
  //     }

  //     Element y() const {
  //       const Element& r = (*this)[0];
  //       const Element& phi = (*this)[1];
  //       return r * std::sin(phi);
  //     }
  //     Element x2() const {
  //       return y();
  //     }


  //     CartCoords<Element, 2>& pos() const {
  //       return toCartesian();
  //     }
  //     CartCoords<Element, 2>& toCartesian() const {
  //       return *(new CartCoords<Element, 2>({ x(), y() }));
  //     }


  //     // unit vectors
  //     Vector<Element, 2>& basis_r() const {
  //       const Element& r = (*this)[0];
  //       const Element& phi = (*this)[1];
  //       return *(new Vector<Element, 2>{ std::cos(phi), std::sin(phi) });
  //     }
  //     Vector<Element, 2>& basis_phi() const {
  //       const Element& r = (*this)[0];
  //       const Element& phi = (*this)[1];
  //       return *(new Vector<Element, 2>{ -std::sin(phi), std::cos(phi) });
  //     }

  //     Vector<Element, 2>& basis_vec(size_t n) const {
  //       if (n == 0) {
  //         return basis_r();
  //       }
  //       else {
  //         return basis_phi();
  //       }
  //     }


  //     // Jacobian 
  //     Element J() const {
  //       const Element& r = (*this)[0];
  //       const Element& phi = (*this)[1];
  //       return r;
  //     }

  //     // metric tensor g^{ij} 
  //     Matrix<Element, 2, 2> g() const {
  //       const Element& r = (*this)[0];
  //       const Element& phi = (*this)[1];
  //       Matrix<Element, 2, 2> metric;
  //       metric = { ones<Element>(), zeros<Element>(), zeros<Element>(), r*r };
  //       return metric;
  //     }

  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "PolarCoords";
  //       s += StyledString::get(ANGLE1).get();
  //       Element d;
  //       s += getTypeName(d);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const PolarCoords<Element>& var) {
  //       const Element& r = var[0];
  //       const Element& phi = var[1];
  //       stream << "(r=";
  //       stream << r;
  //       stream << ", φ=";
  //       stream << phi;
  //       stream << ")";
  //       return stream;
  //     }


  //   };


  //   template <class Element>
  //   auto dot(const PolarCoords<Element>& v1, const PolarCoords<Element>& v2) {
  //     return v1[0] * v2[0] * std::cos(v1[1] - v2[1]);
  //   }

  //   // template <class Element>
  //   // auto& addpts(const PolarCoords<Element>& v1, const PolarCoords<Element>& v2) {
  //   //   const Vector<Element, 2> p = v1.toCartesian() + v2.toCartesian();
  //   //   return p.toPolar();
  //   // }

  //   // TODO: pmult for scalar * PolarCoords


  //   // ***************************************************************************
  //   // * PolarField<Number,RANK>
  //   //
  //   // physics field object: scalar field, vector field, tensor field 
  //   // uses curvilinear coordinates
  //   // ***************************************************************************
  //   template <typename Number, size_t RANK> class PolarField : public MultiGrid_A<Number, 2, RANK> {
  //   public:
  //     using Coords = PolarCoords<Number>;
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
  //       Number d;
  //       s += getTypeName(d);
  //       s += StyledString::get(COMMA).get();
  //       s += "RANK=";
  //       s += num2string(RANK);
  //       s += StyledString::get(ANGLE2).get();
  //       return s;
  //     }


  //     inline friend std::ostream& operator<<(std::ostream& stream, const PolarField<Number, RANK>& var) {
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
  //   // CurvilinearCoordinateSystem<Number>
  //   //

  //   //   template <typename... U>
  //     // typename std::enable_if<(std::is_same<U, Number>::value && ...), const Number>::type operator()(const U... args) 
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

  //   template <typename Number, size_t Ndims, typename CHILD>
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
  //       Number d;
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


  //   template <typename Number>
  //   class
  //     PolarCoordSystem : public CurvilinearCoordinateSystem<Number, 2, PolarCoordSystem<Number>> {
  //   public:
  //     using Func = std::function<Number(Number, Number)>;
  //     using VecFunc = std::function<Vector<Number, 2>(Number, Number)>;
  //     using Coords = PolarCoords<Number>;


  //     PolarCoordSystem() {
  //     }


  //     inline std::string classname() const {
  //       using namespace display;
  //       std::string s = "PolarCoordSystem";
  //       s += StyledString::get(ANGLE1).get();
  //       Number d;
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


    // template <typename Number>
    // using PolarCoords = typename PolarCoordSystem<Number>::Coords;

    // template <typename Number = double>
    // auto dot(const typename PolarCoordSystem<Number>::Coords& v1, const typename PolarCoordSystem<Number>::Coords& v2) {
    //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
    // }


    // template <typename Number, template <typename> class T>
    // auto dot(const typename T<Number>::Coords& v1, const typename T<Number>::Coords& v2) {
    //   return v1.r * v2.r * std::cos(v1.phi - v2.phi);
    // }

    // template <typename Number>
    // auto dot(const typename PolarCoordSystem<Number>::Coords& v1, const typename PolarCoordSystem<Number>::Coords& v2) {
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

    // template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
    // auto grad(const Vector<Number>& gridfunc, const Interval<Number>& range, const int Dpts = 7, const bool periodic = false) {
    //   const size_t N = gridfunc.size();
    //   Vector<Number>* df = new Vector<Number>(N);
    //   *df = gridfunc;
    //   df->deriv(range.a, range.b, 1, Dpts, periodic);
    //   return *df;
    // }

    // template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
    // auto operator&(const Nabla_old<void> i, std::pair<Vector<Number>, Interval<Number>> funcANDrange) {
    //   return grad(funcANDrange.first, funcANDrange.second);
    // }

    // // 
    // // 2D
    // //

    // // template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
    // // auto fgrid(std::function<Number(Number, Number)> func, const Vector<Matrix<Number>, 2>& grid) {
    // //   const Matrix<Number>& X = grid(0);
    // //   const Matrix<Number>& Y = grid(1);
    // //   auto* y = new Matrix<Number>(X.Nrows(), X.Ncols());
    // //   for (int k = 0; k < X.size(); k++) {
    // //     (*y)[k] = func(X[k], Y[k]);
    // //   }
    // //   return *y;
    // // }

    // template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
    // auto grad(const Matrix<Number>& gridfunc, const Interval<Number>& domX, const Interval<Number>& domY, const int Dpts = 7, const bool periodic = false) {

    //   // TODO: rewrite with slices

    //   const size_t NR = gridfunc.Nrows();
    //   const size_t NC = gridfunc.Ncols();
    //   Vector<Matrix<Number>, 2>* df = new Vector<Matrix<Number>, 2>();
    //   // starts off with empty matrices
    //   // TRDISP(*df);

    //   // take d/dx
    //   Vector<Number> vtemp = Vector<Number>(NC);
    //   Matrix<Number> mtemp = Matrix<Number>(NR, NC);
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

    // template <typename Number, typename = typename std::enable_if<std::is_arithmetic<Number>::value, Number>::type>
    // auto operator&(const Nabla_old<void> i, std::tuple<Matrix<Number>, Interval<Number>, Interval<Number>> funcANDrange) {
    //   return grad(std::get<0>(funcANDrange), std::get<1>(funcANDrange), std::get<2>(funcANDrange));
    // }







};

#endif 
