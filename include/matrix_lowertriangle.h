#ifndef MATHQ__MATRIX_LOWERTRIANGLE
#define MATHQ__MATRIX_LOWERTRIANGLE 1




namespace mathq {


  /********************************************************************
   * MatrixLowerTriangle<Num>    -- variable size matrix (valarray)
   *                              Num  = type for elements
   * MatrixLowerTriangle<Num,N>  -- fixed number of rows (valarray)
   *                              N = number of rows
   *                                = number of cols
   ********************************************************************
   */

  template <typename Num, int N>
  class MatrixLowerTriangle : public ExpressionRW<MatrixLowerTriangle<Num, N>, Num, Num, 1, 2> {

  public:
    constexpr static int rank = 2;
    constexpr static int rank_value = 2;
    constexpr static int depth_value = 1;
    constexpr static int NR = N;
    constexpr static int NC = N;
    static constexpr bool resizable = (N==0) ? true : false;
    typedef MatrixLowerTriangle<Num, N> ConcreteType;
    typedef Num ElementType;
    typedef Num NumberType;
    typedef typename SimpleNumberTrait<Num>::Type SimpleNumberType;


    // if N is 0, then we use valarray
    typedef typename ArrayTypeTrait<Num, ((N* N+N)/2)>::Type MyArrayType;

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    const Num zero_ = 0;
    Num dummy_ = 0;
    MyArrayType data_;

    size_t N_;

    static_assert(NumberTrait<Num>::value,
      "class MatrixLowerTriangle can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // ********************* FIXED SIZE CONSTRUCTORS ***********************

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixLowerTriangle<Num, N>() {
      resize(N);
      *this = 0;
    }

    // -------------------  Num value --------------------
    explicit MatrixLowerTriangle<Num, N>(const Num& value) {
      resize(N);
      *this = value;
    }

    // -------------------  (Column) Vector --------------------
    template<size_t NN = N, EnableIf<(NN > 0)> = 0>

      explicit MatrixLowerTriangle<Num, N>(const Vector<Num>& v) {
      const size_t size = v.size();
      // TODO: chekc that size = N(N+1)/2
      resize(N);
      *this = v;
    }

    // --------------------- Matrix CONSTRUCTOR ---------------------
    template<class X, size_t NN = N, EnableIf<(NN>0)> = 0>

      explicit MatrixLowerTriangle<Num, N>(const ExpressionR<X, Num, Num, 1, 2> A) {
      // TODO: chekc that A is N x N
      resize(N);
      *this = A;
    }


    // ********************* VARIABLE SIZE CONSTRUCTORS ***********************


    // ------------------- variable size (Column) Vector --------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixLowerTriangle<Num, N>(const Vector<Num>& v) {
      const size_t len = v.size();
      const size_t depth = (std::sqrt(1+8*len) - 1)/2;
      resize(depth);
      *this = v;
    }

    // --------------------- variable-size zero-CONSTRUCTOR---------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixLowerTriangle<Num, N>(const size_t depth) {
      resize(depth);
      *this = 0;
    }

    // --------------------- variable-size value CONSTRUCTOR ---------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixLowerTriangle<Num, N>(const size_t depth, const Num& value) {
      resize(depth);
      *this = value;
    }


    // --------------------- variable-size Matrix CONSTRUCTOR ---------------------
    template<class X, size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixLowerTriangle<Num, N>(const ExpressionR<X, Num, Num, 1, 2> A) {
      const size_t depth = A.Nrows();
      // TODO: chekc that A is square
      resize(depth);
      *this = A;
    }



    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixLowerTriangle<Num, N>() {
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
      return N_;
    }
    inline size_t Ncols(void) const {
      return N_;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(N_, N_);
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
      Dimensions dimensions(N, N);
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

    MatrixLowerTriangle<Num, N>& resize(const int depth) {
      N_ = N;
      if constexpr (resizable) {
        N_ = depth;
        const size_t sz = (depth*depth+depth)/2;
        data_.resize(sz);
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    MatrixLowerTriangle<Num, N>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixLowerTriangle<Num, N>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> recursive_dims(deepdims_new);
      Dimensions newdims = recursive_dims[0];
      resize(newdims);
      return *this;
    }




    MatrixLowerTriangle<Num, N>& transpose(void) {
      // TODO: implement
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, MatrixLowerTriangle<Num, N>& >::type adjoint() {
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
      const Indices& inds = indices(n);
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }

    // read
    const Num operator[](const size_t n)  const {
      const Indices& inds = indices(n);
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the index function
    Indices& indices(const size_t k) const {
      // NOTE: a divide is between 6 to 40 times more costly than a multiply
      //       https://stackoverflow.com/questions/4125033/floating-point-division-vs-floating-point-multiplication
      //       So avoid using this whenever possible
      //       simplest way to calc is (k/Ncols_, k%Ncols_)
      //       but the following guarantees that the compution is done efficently
      //TODO: bounds check
      Indices& myinds = *(new Indices(2));
      myinds[0] = k/N_;      // row
      myinds[1] = k - N_*myinds[0];  // column
      return myinds;
    }






    //**********************************************************************
    //***************MultiArray-style Element Access: A(r,c) *********************
    //**********************************************************************

    Num& operator()(const size_t r, const size_t c) {
      if (c <= r) {
        size_t q = r*(r+1)/2 + c;
        return data_[q];
      }
      else {
        return (dummy_ = 0);
      }
    }

    const Num operator()(const size_t r, const size_t c) const {
      if (c <= r) {
        size_t q = r*(r+1)/2 + c;
        return data_[q];
      }
      else {
        return zero_;
      }
    }

    // --------------------------- index(r,c) -----------------------------

    size_t index(const size_t r, const size_t c) const {
      //TODO: bounds check
      return c + N_*r; // row major
    }


    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************


    MatrixLowerTriangle<Num, N>& set(const Vector<Num>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }
    MatrixLowerTriangle<Num, N>& operator=(const Vector<Num>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixLowerTriangle<Num, N>& operator=(const ExpressionR<X, Num, Num, 1, 1>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixLowerTriangle<Num, N>& operator=(const ExpressionR<X, Num, Num, 1, 2>& A) {
      const size_t NN = A.dims()[0];
      // TODO: check that A is square
      resize(NN);
      for (size_t r = 0; r < N_; r++) {
        for (size_t c = 0; c <= r; c++) {
          data_(r, c) = A(r, c);
        }
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

    MatrixLowerTriangle<Num, N>& operator=(const Num& value) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = value;
      }
      return *this;
    }

    MatrixLowerTriangle<Num, N>& operator=(const MatrixLowerTriangle<Num, N>& b) {
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

    MatrixLowerTriangle<Num, N>& roundzero(SimpleNumberType tolerance = Functions<SimpleNumberType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = Num >
    typename std::enable_if<is_complex<T>::value, MatrixLowerTriangle<Num, N>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixLowerTriangle";
      s += StyledString::get(ANGLE1).get();
      s += getTypeName(Num());
      if (N!=0) {
        s += StyledString::get(COMMA).get();
        s += "N=";
        s += num2string(N);
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixLowerTriangle<Num, N>& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const size_t P = FormatDataMatrix::max_elements_per_line;

      for (size_t r = 0; r < m.Nrows(); r++) {
        stream << style.apply(FormatDataMatrix::string_row_opening);
        size_t k = 0;
        for (size_t c = 0; c < m.Ncols(); c++, k++) {
          if (k >= P) {
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
    friend inline std::istream& operator>>(const std::string s, MatrixLowerTriangle<Num, N>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixLowerTriangle<Num, N>& m2) {
      return stream;
    }




  };




};


#endif 

