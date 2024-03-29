#ifndef MATHQ__ZEROMATRIX
#define MATHQ__ZEROMATRIX 1




namespace mathq {


  /********************************************************************
   * MatrixZero<Num        -- variable size matrix (valarray)
   *                        Num  = type for elements
   * MatrixZero<Num,NR>    -- fixed number of rows (valarray)
   *                        NR = number of rows
   * MatrixZero<Num,NR,NC> -- fixed number of rows and cols (array)
   *                        NC = number of cols
   ********************************************************************
   */

   //, typename = EnableIf<NumberTrait<Num>::value>
  template <typename Num, int NR, int NC >
  class MatrixZero : public ExpressionRW<MatrixZero<Num, NR, NC>, Num, Num, 1, 2> {

  public:
    constexpr static int rank = 2;
    constexpr static int rank_value = 2;
    constexpr static int depth_value = 1;
    static constexpr bool resizable = (NR*NC==0) ? true : false;
    static constexpr bool resizableRows = (NR==0) ? true : false;
    static constexpr bool resizableCols = (NC==0) ? true : false;
    typedef MatrixZero<Num, NR, NC> ConcreteType;
    typedef Num ElementType;
    typedef Num NumberType;
    typedef typename SimpleNumberTrait<Num>::Type SimpleNumberType;



    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    const Num data_ = 0;

    size_t Nrows_;
    size_t Ncols_;

    static_assert(NumberTrait<Num>::value,
      "class MatrixZero can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR: empty --------------------
    explicit MatrixZero<Num, NR, NC>() {
      size_t NN = NR*NC;
      resize(NR, NC);
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixZero<Num, NR, NC>(const size_t Nr, const size_t Nc) {
      resize(Nr, Nc);
    }




    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixZero<Num, NR, NC>() {
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

    MatrixZero<Num, NR, NC>& resize(const int Nr, const int Nc) {
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

    MatrixZero<Num, NR, NC>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixZero<Num, NR, NC>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> recursive_dims(deepdims_new);
      Dimensions newdims = recursive_dims[0];
      resize(newdims);
      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    MatrixZero<Num, NR, NC>& reshape(const size_t nr, const size_t nc) {
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


    MatrixZero<Num, NR, NC>& transpose(void) {
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, MatrixZero<Num, NR, NC>& >::type adjoint() {
      return *this;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // read
    const Num dat(const size_t n)  const {
      return data_;
    }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(Indices)
    const Num dat(const Indices& inds)  const {
      return data_;
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(DeepIndices)
    const Num dat(const DeepIndices& dinds)  const {
      return data_;
    }


    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // read
    const Num& operator[](const size_t n)  const {
      return data_;
    }





    //**********************************************************************
    //***************MultiArray-style Element Access: A(r,c) *********************
    //**********************************************************************


    const Num operator()(const size_t r, const size_t c) const {
      return data_;
    }





    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    MatrixZero<Num, NR, NC>& roundzero(SimpleNumberType tolerance = Functions<SimpleNumberType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, MatrixZero<Num, NR, NC>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixZero";
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixZero<Num, NR, NC>& m) {
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
    friend inline std::istream& operator>>(const std::string s, MatrixZero<Num, NR, NC>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixZero<Num, NR, NC>& m2) {
      return stream;
    }




  };




};


#endif 

