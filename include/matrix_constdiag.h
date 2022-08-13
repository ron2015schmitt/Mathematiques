#ifndef MATHQ__CONSTDIAGMATRIX
#define MATHQ__CONSTDIAGMATRIX 1




namespace mathq {


  template <typename Element, size_t... dim_ints>
  class MatrixConstDiag<Element, 2, dim_ints...> :
    public SpecialData<Element, 2, dim_ints...>,
    public ExpressionRW<
    Matrix<Element, dim_ints...>,  // Derived
    Element,  // Element
    typename NumberTrait<Element>::Type, // Num
    1 + NumberTrait<Element>::depth(),  // depth
    2  // rank
    > {
  public:


    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 2;
    constexpr static std::array<size_t, rank_value> static_dims_array = { dim_ints... };
    constexpr static size_t N0 = std::get<0>(static_dims_array);
    constexpr static size_t N1 = std::get<1>(static_dims_array);
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = (sizeof...(dim_ints) == 0);
    constexpr static size_t compile_time_size = calc_size<rank_value, N0, N1>();

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Type = MultiArray<Element, rank_value, dim_ints...>;
    using ConcreteType = Matrix<Element, dim_ints...>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using ParentDataType = MultiArrayData<Element, rank_value, dim_ints...>;
    using ParentType = ExpressionRW<
      ConcreteType,  // Derived
      Element,  // Element
      NumberType, // Num
      depth_value,  // depth
      rank_value  // rank
    >;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;
    using DeepDimensionsType = RecursiveDimensions;

    using MyArrayType = typename ArrayTypeTrait<Element, compile_time_size>::Type;
    using InitializerType = typename MakeInitializer<Element, rank_value >::Type;




    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    constexpr static Num zero_ = 0;
    Num value_ = 1;

    static_assert(NumberTrait<Num>::value,
      "class MatrixConstDiag can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit Type() {
      size_t NN = NR*NC;
      resize(NR, NC);
      value_ = 1;
    }

    // -------------------  Num value --------------------
    explicit Type(const Num& value) {
      size_t NN = NR*NC;
      resize(NR, NC);
      value_ = value;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit Type(const size_t Nr, const size_t Nc) {
      resize(Nr, Nc);
      value_ = 1;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit Type(const size_t Nr, const size_t Nc, const Num& value) {
      resize(Nr, Nc);
      value_ = value;
    }




    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Type() {
      //remove from directory
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    size_t rank(void)  const {
      return rank_value;
    }

    inline size_t size(void) const {
      return Nrows()*Ncols();
    }
    inline size_t Nrows(void) const {
      return Nrows_;
    }
    inline size_t Ncols(void) const {
      return Ncols_;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(Nrows_, Ncols_);
      return dimensions;
    }


    bool isExpression(void) const {
      return false;
    }
    MultiArrays getEnum() const {
      return T_MATRIX;
    }

    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    Dimensions template_dims(void) const {
      Dimensions dimensions(NR, NC);
      return dimensions;
    }


    constexpr size_t depth(void) const {
      return depth_value;
    }
    Dimensions element_dims(void) const {
      Dimensions dimensions();
      return *(new Dimensions());
    }

    // the size of each element
    inline size_t element_size(void) const {
      return 1;
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_t el_total_size(void) const {
      return 1;
    }

    // the total number of numbers in this data structure
    size_t total_size(void) const {
      return this->size();
    }
    std::vector<Dimensions>& recursive_dims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return recursive_dims(ddims);
    }
    std::vector<Dimensions>& recursive_dims(std::vector<Dimensions>& parentdims) const {
      parentdims.push_back(dims());
      return parentdims;
    }




    //**********************************************************************
    //************************** RESIZE, RESHAPE, TRANSPOSE*****************
    //**********************************************************************
    // --------------------- resize() --------------------

    Type& resize(const int Nr, const int Nc) {
      Nrows_ = NR;
      Ncols_ = NC;
      if constexpr (resizableRows) {
        Nrows_ = Nr;
      }
      if constexpr (resizableCols) {
        Ncols_ = Nc;
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    Type& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    Type& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> recursive_dims(deepdims_new);
      Dimensions newdims = recursive_dims[0];
      resize(newdims);
      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    Type& reshape(const size_t nr, const size_t nc) {
      const size_t nn = nr*nc;
      if (nn==size()) {
        if (nn == 0) {
          Nrows_ = 0;
          Ncols_ = 0;
        }
        else {
          Nrows_ = nr;
          Ncols_ = nc;
        }
      }
      return *this;
    }


    Type& transpose(void) {
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, Type& >::type adjoint() {
      return *this;
    }


    Num getValue() const {
      return value_;
    }
    Type& setValue(const Num& value) {
      value_ = value;
      return *this;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // read
    const Num dat(const size_t n)  const {
      return (*this)[n];
    }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(Indices)
    const Num dat(const Indices& inds)  const {
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(DeepIndices)
    const Num dat(const DeepIndices& dinds)  const {
      const size_t mydepth = dinds.size();
      const Indices& inds = dinds[mydepth - depth_value];
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // read
    const Num operator[](const size_t n)  const {
      const Indices& inds = indices(n);;
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    // --------------------------- index(r,c) -----------------------------

    size_t index(const size_t r, const size_t c) const {
      //TODO: bounds check
      return c + Ncols_*r; // row major
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the above function
    Indices& indices(const size_t k) const {
      // NOTE: a divide is between 6 to 40 times more costly than a multiply
      //       https://stackoverflow.com/questions/4125033/floating-point-division-vs-floating-point-multiplication
      //       So avoid using this whenever possible
      //       simplest way to calc is (k/Ncols_, k%Ncols_)
      //       but the following guarantees that the compution is done efficently
      //TODO: bounds check
      Indices& myinds = *(new Indices(2));
      myinds[0] = k/Ncols_;      // row
      myinds[1] = k - Ncols_*myinds[0];  // column
      return myinds;
    }



    //**********************************************************************
    //***************MultiArray-style Element Access: A(r,c) *********************
    //**********************************************************************


    const Num operator()(const size_t r, const size_t c) const {
      if (r==c) {
        return value_;
      }
      else {
        return zero_;
      }
    }





    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Type& roundzero(SimpleNumberType tolerance = Functions<SimpleNumberType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, Type& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixConstDiag";
      s += StyledString::get(ANGLE1).get();
      s += getTypeName(Num());
      if (NR!=0) {
        s += StyledString::get(COMMA).get();
        s += "NR=";
        s += num2string(NR);
      }
      if (NC!=0) {
        s += StyledString::get(COMMA).get();
        s += "NC=";
        s += num2string(NC);
      }
      //    if (depth>1) {
      //      s += StyledString::get(COMMA).get();
      //      s += "depth=";
      //      s += num2string(depth);
      //    }
      s += StyledString::get(ANGLE2).get();
      return s;
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif




    // stream << operator


    friend std::ostream& operator<<(std::ostream& stream, const Type& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const size_t N = FormatDataMatrix::max_elements_per_line;

      for (size_t r = 0; r < m.Nrows(); r++) {
        stream << style.apply(FormatDataMatrix::string_row_opening);
        size_t k = 0;
        for (size_t c = 0; c < m.Ncols(); c++, k++) {
          if (k >= N) {
            stream << style.apply(FormatDataMatrix::string_endofline);
            k = 0;
          }
          dispval_strm(stream, m(r, c));
          if (c < m.Ncols()-1) {
            stream << style.apply(FormatDataMatrix::string_delimeter);
          }
          else {
            if (r < m.Nrows()-1) {
              stream << style.apply(FormatDataMatrix::string_row_closing);
            }
            else {
              stream << style.apply(FormatDataMatrix::string_lastrow_closing);
            }
          }
        }
      }
      stream << style.apply(FormatDataMatrix::string_closing);

      return stream;
    }


    //template <typename Num>	
    friend inline std::istream& operator>>(const std::string s, Type& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, Type& m2) {
      return stream;
    }




  };




};


#endif 

