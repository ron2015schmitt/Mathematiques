#ifndef MATHQ__MATRIX_UPPERTRIANGLE_H
#define MATHQ__MATRIX_UPPERTRIANGLE_H 1




namespace mathq {


  /********************************************************************
   * MatrixUpperTriangle<D>    -- variable size matrix (valarray)
   *                              D  = type for elements
   * MatrixUpperTriangle<D,N>  -- fixed number of rows (valarray)
   *                              N = number of rows
   *                                = number of cols
   ********************************************************************
   */

  template <class D, int N>
  class MatrixUpperTriangle : public MArrayExpRW<MatrixUpperTriangle<D, N>, D, D, 1, 2> {

  public:
    constexpr static int R = 2;
    constexpr static int Rvalue = 2;
    constexpr static int Mvalue = 1;
    constexpr static int NR = N;
    constexpr static int NC = N;
    static constexpr bool resizable = (N==0) ? true : false;
    typedef MatrixUpperTriangle<D, N> XType;
    typedef D EType;
    typedef D DType;
    typedef typename OrderedNumberTrait<D>::Type FType;


    // if N is 0, then we use valarray
    typedef typename ArrayType<D, ((N* N+N)/2)>::Type MyArrayType;

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    const D zero_ = 0;
    D dummy_ = 0;
    MyArrayType data_;

    size_t N_;

    static_assert(NumberTrait<D>::value,
      "class MatrixUpperTriangle can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // ********************* FIXED SIZE CONSTRUCTORS ***********************

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixUpperTriangle<D, N>() {
      resize(N);
      *this = 0;
    }

    // -------------------  D value --------------------
    explicit MatrixUpperTriangle<D, N>(const D& value) {
      resize(N);
      *this = value;
    }

    // -------------------  (Column) Vector --------------------
    template<size_t NN = N, EnableIf<(NN > 0)> = 0>

    explicit MatrixUpperTriangle<D, N>(const Vector<D>& v) {
      const size_t size = v.size();
      // TODO: chekc that size = N(N+1)/2
      resize(N);
      *this = v;
    }

    // --------------------- Matrix CONSTRUCTOR ---------------------
    template<class X, size_t NN = N, EnableIf<(NN>0)> = 0>

    explicit MatrixUpperTriangle<D, N>(const MArrayExpR<X, D, D, 1, 2> A) {
      // TODO: chekc that A is N x N
      resize(N);
      *this = A;
    }


    // ********************* VARIABLE SIZE CONSTRUCTORS ***********************


    // ------------------- variable size (Column) Vector --------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixUpperTriangle<D, N>(const Vector<D>& v) {
      const size_t len = v.size();
      const size_t M = (std::sqrt(1+8*len) - 1)/2;
      resize(M);
      *this = v;
    }

    // --------------------- variable-size zero-CONSTRUCTOR---------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixUpperTriangle<D, N>(const size_t M) {
      resize(M);
      *this = 0;
    }

    // --------------------- variable-size value CONSTRUCTOR ---------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixUpperTriangle<D, N>(const size_t M, const D& value) {
      resize(M);
      *this = value;
    }


    // --------------------- variable-size Matrix CONSTRUCTOR ---------------------
    template<class X, size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixUpperTriangle<D, N>(const MArrayExpR<X, D, D, 1, 2> A) {
      const size_t M = A.Nrows();
      // TODO: chekc that A is square
      resize(M);
      *this = A;
    }



    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixUpperTriangle<D, N>() {
      //remove from directory
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    size_t ndims(void)  const {
      return Rvalue;
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

    Dimensions tdims(void) const {
      Dimensions dimensions(N, N);
      return dimensions;
    }


    constexpr size_t depth(void) const {
      return Mvalue;
    }
    Dimensions eldims(void) const {
      Dimensions dimensions();
      return *(new Dimensions());
    }

    // the size of each element
    inline size_t elsize(void) const {
      return 1;
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_t eldeepsize(void) const {
      return 1;
    }

    // the total number of numbers in this data structure
    size_t deepsize(void) const {
      return this->size();
    }
    std::vector<Dimensions>& deepdims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return deepdims(ddims);
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      parentdims.push_back(dims());
      return parentdims;
    }




    //**********************************************************************
    //************************** RESIZE, RESHAPE, TRANSPOSE*****************
    //**********************************************************************
    // --------------------- resize() --------------------

    MatrixUpperTriangle<D, N>& resize(const int M) {
      N_ = N;
      if constexpr (resizable) {
        N_ = M;
        const size_t sz = (M*M+M)/2;
        data_.resize(sz);
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    MatrixUpperTriangle<D, N>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixUpperTriangle<D, N>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> deepdims(deepdims_new);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      return *this;
    }




    MatrixUpperTriangle<D, N>& transpose(void) {
      // TODO: implement
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, MatrixUpperTriangle<D, N>& >::type adjoint() {
      return *this;
    }



    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // read
    const D dat(const size_t n)  const {
      return (*this)[n];
    }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(Indices)
    const D dat(const Indices& inds)  const {
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(DeepIndices)
    const D dat(const DeepIndices& dinds)  const {
      const size_t depth = dinds.size();
      const Indices& inds = dinds[depth-Mvalue];
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // read / write
    D& operator[](const size_t n) {
      const Indices& inds = indices(n);
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }

    // read
    const D operator[](const size_t n)  const {
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

    D& operator()(const size_t r, const size_t c) {
      if (r <= c) {
        size_t q = c + N_*r - (r*r+r)/2;
        return data_[q];
      }
      else {
        return (dummy_ = 0);
      }
    }

    const D operator()(const size_t r, const size_t c) const {
      if (r <= c) {
        size_t q = c + N_*r - (r*r+r)/2;
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


    MatrixUpperTriangle<D, N>& set(const Vector<D>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }
    MatrixUpperTriangle<D, N>& operator=(const Vector<D>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixUpperTriangle<D, N>& operator=(const MArrayExpR<X, D, D, 1, 1>& v) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixUpperTriangle<D, N>& operator=(const MArrayExpR<X, D, D, 1, 2>& A) {
      const size_t M = A.Nrows();
      // TODO: check that A is square
      resize(M);
      for (size_t c = 0; c < N_; c++) {
        for (size_t r = 0; r <= c; r++) {
          data_(r, c) = A(r, c);
        }
      }
      return *this;
    }


    Vector<D>& get() const {
      Vector<D>& v = *(new Vector<D>(data_.size()));
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return v;
    }

    MatrixUpperTriangle<D, N>& operator=(const D& value) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = value;
      }
      return *this;
    }

    MatrixUpperTriangle<D, N>& operator=(const MatrixUpperTriangle<D, N>& b) {
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

    MatrixUpperTriangle<D, N>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, MatrixUpperTriangle<D, N>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixUpperTriangle";
      s += StyledString::get(ANGLE1).get();
      s += getTypeName(D());
      if (N!=0) {
        s += StyledString::get(COMMA).get();
        s += "N=";
        s += num2string(N);
      }
      //    if (M>1) {
      //      s += StyledString::get(COMMA).get();
      //      s += "M=";
      //      s += num2string(M);
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixUpperTriangle<D, N>& m) {
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


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s, MatrixUpperTriangle<D, N>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixUpperTriangle<D, N>& m2) {
      return stream;
    }




  };




};


#endif 

