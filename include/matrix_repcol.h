#ifndef MATHQ__REPCOLMATRIX
#define MATHQ__REPCOLMATRIX 1




namespace mathq {


  /********************************************************************
   * MatrixRepCol<Num        -- variable size matrix (valarray)
   *                        Num  = type for elements
   * MatrixRepCol<Num,NR>    -- fixed number of rows (valarray)
   *                        NR = number of rows
   * MatrixRepCol<Num,NR,NC> -- fixed number of rows and cols (array)
   *                        NC = number of cols
   ********************************************************************
   */

   //, typename = EnableIf<NumberTrait<Num>::value>
  template <typename Num, int NR, int NC >
  class MatrixRepCol : public ExpressionRW<MatrixRepCol<Num, NR, NC>, Num, Num, 1, 2> {

  public:
    constexpr static int rank = 2;
    constexpr static int rank_value = 2;
    constexpr static int depth_value = 1;
    static constexpr bool resizable = (NR*NC==0) ? true : false;
    static constexpr bool resizableRows = (NR==0) ? true : false;
    static constexpr bool resizableCols = (NC==0) ? true : false;
    typedef MatrixRepCol<Num, NR, NC> ConcreteType;
    typedef Num ElementType;
    typedef Num NumberType;
    typedef typename SimpleNumberTrait<Num>::Type SimpleNumberType;


    // if either NR or NC is 0, then we use valarray
    typedef typename ArrayTypeTrait<Num, NR>::Type MyArrayType;

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    const Num zero_ = 0;
    Num dummy_ = 0;
    MyArrayType data_;

    size_t Nrows_;
    size_t Ncols_;

    static_assert(NumberTrait<Num>::value,
      "class MatrixRepCol can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixRepCol<Num, NR, NC>() {
      size_t NN = NR*NC;
      resize(NR, NC);
      *this = 0;
    }

    // -------------------  Num value --------------------
    explicit MatrixRepCol<Num, NR, NC>(const Num& value) {
      size_t NN = NR*NC;
      resize(NR, NC);
      *this = value;
    }

    // -------------------  (Column) Vector --------------------
    template<size_t NN = NR*NC, EnableIf<(NN > 0)> = 0>

      explicit MatrixRepCol<Num, NR, NC>(const Vector<Num>& v) {
      resize(NR, NC);
      *this = v;
    }


    // -------------------  (Column) Vector --------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRepCol<Num, NR, NC>(const Vector<Num>& v, const size_t Nc) {
      const size_t Nr = v.size();
      resize(Nr, Nc);  // this a *request* to resize
      *this = v;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRepCol<Num, NR, NC>(const size_t Nr, const size_t Nc) {
      resize(Nr, Nc);
      *this = 0;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRepCol<Num, NR, NC>(const size_t Nr, const size_t Nc, const Num& value) {
      resize(Nr, Nc);
      *this = value;
    }




    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixRepCol<Num, NR, NC>() {
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

    MatrixRepCol<Num, NR, NC>& resize(const int Nr, const int Nc) {
      Nrows_ = NR;
      Ncols_ = NC;
      if constexpr (resizableRows) {
        Nrows_ = Nr;
      }
      if constexpr (resizableCols) {
        Ncols_ = Nc;
      }
      if constexpr (resizable) {
        const size_t sz = Nrows_;
        data_.resize(sz);
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    MatrixRepCol<Num, NR, NC>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixRepCol<Num, NR, NC>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> recursive_dims(deepdims_new);
      Dimensions newdims = recursive_dims[0];
      resize(newdims);
      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    MatrixRepCol<Num, NR, NC>& reshape(const size_t nr, const size_t nc) {
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
      resize(Nrows_, Ncols_);
      return *this;
    }


    MatrixRepCol<Num, NR, NC>& transpose(void) {
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, MatrixRepCol<Num, NR, NC>& >::type adjoint() {
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
      const Indices& inds = dinds[mydepth -depth_value];
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // read / write
    Num& operator[](const size_t n) {
      const Indices& inds = indices(n);;
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }

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

    Num& operator()(const size_t r, const size_t c) {
      return data_[r];
    }

    const Num operator()(const size_t r, const size_t c) const {
      return data_[r];
    }



    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************


    MatrixRepCol<Num, NR, NC>& set(const Vector<Num>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }
    MatrixRepCol<Num, NR, NC>& operator=(const Vector<Num>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixRepCol<Num, NR, NC>& operator=(const ExpressionR<X, Num, Num, 1, 1>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }


    Vector<Num>& get() const {
      Vector<Num>& v = *(new Vector<Num>(data_.size()));
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return v;
    }

    MatrixRepCol<Num, NR, NC>& operator=(const Num& value) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = value;
      }
      return *this;
    }

    MatrixRepCol<Num, NR, NC>& operator=(const MatrixRepCol<Num, NR, NC>& b) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = b[k];
      }
      return *this;
    }


    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    MatrixRepCol<Num, NR, NC>& roundzero(SimpleNumberType tolerance = Functions<SimpleNumberType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, MatrixRepCol<Num, NR, NC>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixRepCol";
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixRepCol<Num, NR, NC>& m) {
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
    friend inline std::istream& operator>>(const std::string s, MatrixRepCol<Num, NR, NC>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixRepCol<Num, NR, NC>& m2) {
      return stream;
    }




  };




};


#endif 

