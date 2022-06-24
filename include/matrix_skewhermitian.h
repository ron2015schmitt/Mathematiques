#ifndef MATHQ__MATRIX_SKEWHERMITIAN_H
#define MATHQ__MATRIX_SKEWHERMITIAN_H 1



namespace mathq {


  /********************************************************************
   * MatrixSkewHermitian<D>    -- variable size matrix (valarray)
   *                              D  = type for elements
   * MatrixSkewHermitian<D,N>  -- fixed number of rows (valarray)
   *                              N = number of rows
   *                                = number of cols
   ********************************************************************
   */

  template <class D, int N>
  class MatrixSkewHermitian : public MArrayExpRW<MatrixSkewHermitian<D, N>, D, D, 1, 2> {

  public:
    constexpr static int R = 2;
    constexpr static int Rvalue = 2;
    constexpr static int Mvalue = 1;
    constexpr static int NR = N;
    constexpr static int NC = N;
    static constexpr bool resizable = (N==0) ? true : false;
    typedef MatrixSkewHermitian<D, N> XType;
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

    index_type N_;

    static_assert(NumberTrait<D>::value,
      "class MatrixSkewHermitian can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // ********************* FIXED SIZE CONSTRUCTORS ***********************

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixSkewHermitian<D, N>() {
      resize(N);
      *this = 0;
    }

    // -------------------  D value --------------------
    explicit MatrixSkewHermitian<D, N>(const D& value) {
      resize(N);
      *this = value;
    }

    // -------------------  (Column) Vector --------------------
    template<size_t NN = N, EnableIf<(NN > 0)> = 0>

    explicit MatrixSkewHermitian<D, N>(const Vector<D>& v) {
      const index_type size = v.size();
      // TODO: chekc that size = N(N+1)/2
      resize(N);
      *this = v;
    }

    // --------------------- Matrix CONSTRUCTOR ---------------------
    template<class X, size_t NN = N, EnableIf<(NN>0)> = 0>

    explicit MatrixSkewHermitian<D, N>(const MArrayExpR<X, D, D, 1, 2> A) {
      // TODO: chekc that A is N x N
      resize(N);
      *this = A;
    }


    // ********************* VARIABLE SIZE CONSTRUCTORS ***********************


    // ------------------- variable size (Column) Vector --------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixSkewHermitian<D, N>(const Vector<D>& v) {
      const index_type len = v.size();
      const index_type M = (std::sqrt(1+8*len) - 1)/2;
      resize(M);
      *this = v;
    }

    // --------------------- variable-size zero-CONSTRUCTOR---------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixSkewHermitian<D, N>(const size_type M) {
      resize(M);
      *this = 0;
    }

    // --------------------- variable-size value CONSTRUCTOR ---------------------
    template<size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixSkewHermitian<D, N>(const size_type M, const D& value) {
      resize(M);
      *this = value;
    }


    // --------------------- variable-size Matrix CONSTRUCTOR ---------------------
    template<class X, size_t NN = N, EnableIf<NN == 0> = 0>

    explicit MatrixSkewHermitian<D, N>(const MArrayExpR<X, D, D, 1, 2> A) {
      const index_type M = A.Nrows();
      // TODO: chekc that A is square
      resize(M);
      *this = A;
    }



    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixSkewHermitian<D, N>() {
      //remove from directory
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    size_type ndims(void)  const {
      return Rvalue;
    }


    inline size_type size(void) const {
      return Nrows()*Ncols();
    }
    inline size_type Nrows(void) const {
      return N_;
    }
    inline size_type Ncols(void) const {
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


    constexpr size_type depth(void) const {
      return Mvalue;
    }
    Dimensions eldims(void) const {
      Dimensions dimensions();
      return *(new Dimensions());
    }

    // the size of each element
    inline size_type elsize(void) const {
      return 1;
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_type eldeepsize(void) const {
      return 1;
    }

    // the total number of numbers in this data structure
    size_type deepsize(void) const {
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

    MatrixSkewHermitian<D, N>& resize(const int M) {
      N_ = N;
      if constexpr (resizable) {
        N_ = M;
        const index_type sz = (M*M-M)/2;
        data_.resize(sz);
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    MatrixSkewHermitian<D, N>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixSkewHermitian<D, N>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> deepdims(deepdims_new);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      return *this;
    }




    MatrixSkewHermitian<D, N>& transpose(void) {
      // TODO: implement
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, MatrixSkewHermitian<D, N>& >::type adjoint() {
      return *this;
    }



    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // read
    const D dat(const index_type n)  const {
      return (*this)[n];
    }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(Indices)
    const D dat(const Indices& inds)  const {
      index_type r = inds[0];
      index_type c = inds[1];
      return (*this)(r, c);
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(DeepIndices)
    const D dat(const DeepIndices& dinds)  const {
      const index_type depth = dinds.size();
      const Indices& inds = dinds[depth-Mvalue];
      index_type r = inds[0];
      index_type c = inds[1];
      return (*this)(r, c);
    }


    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // read / write
    D& operator[](const index_type n) {
      const Indices& inds = indices(n);
      index_type r = inds[0];
      index_type c = inds[1];
      return (*this)(r, c);
    }

    // read
    const D operator[](const index_type n)  const {
      const Indices& inds = indices(n);
      index_type r = inds[0];
      index_type c = inds[1];
      return (*this)(r, c);
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the index function
    Indices& indices(const index_type k) const {
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

    const index_type dataIndex(const index_type r, const index_type c) const {
      return c + N_*r - (r*r+r)/2;
    }

    D& operator()(const index_type r, const index_type c) {
      if (r <= c) {
        return data_[dataIndex(r, c)];
      }
      else {
        return dummy_ = -mathq::conj(data_[dataIndex(c, r)]);
      }
    }

    const D operator()(const index_type r, const index_type c) const {
      if (r <= c) {
        return data_[dataIndex(r, c)];
      }
      else {
        return -mathq::conj(data_[dataIndex(c, r)]);
      }
    }

    // --------------------------- index(r,c) -----------------------------

    index_type index(const index_type r, const index_type c) const {
      //TODO: bounds check
      return c + N_*r; // row major
    }


    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************


    MatrixSkewHermitian<D, N>& set(const Vector<D>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }
    MatrixSkewHermitian<D, N>& operator=(const Vector<D>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixSkewHermitian<D, N>& operator=(const MArrayExpR<X, D, D, 1, 1>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixSkewHermitian<D, N>& operator=(const MArrayExpR<X, D, D, 1, 2>& A) {
      const index_type M = A.Nrows();
      // TODO: check that A is square
      resize(M);
      for (index_type c = 0; c < N_; c++) {
        for (index_type r = 0; r <= c; r++) {
          data_(r, c) = A(r, c);
        }
      }
      return *this;
    }


    Vector<D>& get() const {
      Vector<D>& v = *(new Vector<D>(data_.size()));
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return v;
    }

    MatrixSkewHermitian<D, N>& operator=(const D& value) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = value;
      }
      return *this;
    }

    MatrixSkewHermitian<D, N>& operator=(const MatrixSkewHermitian<D, N>& b) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = b[k];
      }
      return *this;
    }


    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    MatrixSkewHermitian<D, N>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, MatrixSkewHermitian<D, N>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixSkewHermitian";
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixSkewHermitian<D, N>& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const mathq::index_type P = FormatDataMatrix::max_elements_per_line;

      for (mathq::index_type r = 0; r < m.Nrows(); r++) {
        stream << style.apply(FormatDataMatrix::string_row_opening);
        mathq::index_type k = 0;
        for (mathq::index_type c = 0; c < m.Ncols(); c++, k++) {
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
    friend inline std::istream& operator>>(const std::string s, MatrixSkewHermitian<D, N>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixSkewHermitian<D, N>& m2) {
      return stream;
    }




  };




};


#endif 

