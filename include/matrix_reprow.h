#ifndef MATHQ__REPROWMATRIX_H
#define MATHQ__REPROWMATRIX_H 1




namespace mathq {


  /********************************************************************
   * MatrixRepRow<D        -- variable size matrix (valarray)
   *                        D  = type for elements
   * MatrixRepRow<D,NR>    -- fixed number of rows (valarray)
   *                        NR = number of rows
   * MatrixRepRow<D,NR,NC> -- fixed number of rows and cols (array)
   *                        NC = number of cols
   ********************************************************************
   */

   //, typename = EnableIf<NumberType<D>::value>
  template <class D, int NR, int NC >
  class MatrixRepRow : public TensorRW<MatrixRepRow<D, NR, NC>, D, D, 1, 2> {

  public:
    constexpr static int R = 2;
    constexpr static int Rvalue = 2;
    constexpr static int Mvalue = 1;
    static constexpr bool resizable = (NR*NC==0) ? true : false;
    static constexpr bool resizableRows = (NR==0) ? true : false;
    static constexpr bool resizableCols = (NC==0) ? true : false;
    typedef MatrixRepRow<D, NR, NC> XType;
    typedef D EType;
    typedef D DType;
    typedef typename FundamentalType<D>::Type FType;


    // if either NR or NC is 0, then we use valarray
    typedef typename ArrayType<D, NC>::Type MyArrayType;

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    const D zero_ = 0;
    D dummy_ = 0;
    MyArrayType data_;

    index_type Nrows_;
    index_type Ncols_;

    static_assert(NumberType<D>::value,
      "class MatrixRepRow can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixRepRow<D, NR, NC>() {
      size_t NN = NR*NC;
      resize(NR, NC);
      *this = 0;
    }

    // -------------------  D value --------------------
    explicit MatrixRepRow<D, NR, NC>(const D& value) {
      size_t NN = NR*NC;
      resize(NR, NC);
      *this = value;
    }

    // -------------------  (Column) Vector --------------------
    template<size_t NN = NR*NC, EnableIf<(NN > 0)> = 0>

    explicit MatrixRepRow<D, NR, NC>(const Vector<D>& v) {
      resize(NR, NC);
      *this = v;
    }


    // -------------------  (Column) Vector --------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRepRow<D, NR, NC>(const Vector<D>& v, const index_type Nr) {
      const index_type Nc = v.size();
      resize(Nr, Nc);  // this a *request* to resize
      *this = v;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRepRow<D, NR, NC>(const size_type Nr, const size_type Nc) {
      resize(Nr, Nc);
      *this = 0;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRepRow<D, NR, NC>(const size_type Nr, const size_type Nc, const D& value) {
      resize(Nr, Nc);
      *this = value;
    }




    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixRepRow<D, NR, NC>() {
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
      return Nrows_;
    }
    inline size_type Ncols(void) const {
      return Ncols_;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(Nrows_, Ncols_);
      return dimensions;
    }


    bool isExpression(void) const {
      return false;
    }
    Tensors getEnum() const {
      return T_MATRIX;
    }

    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    Dimensions tdims(void) const {
      Dimensions dimensions(NR, NC);
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

    MatrixRepRow<D, NR, NC>& resize(const int Nr, const int Nc) {
      Nrows_ = NR;
      Ncols_ = NC;
      if constexpr (resizableRows) {
        Nrows_ = Nr;
      }
      if constexpr (resizableCols) {
        Ncols_ = Nc;
      }
      if constexpr (resizable) {
        const index_type sz = Ncols_;
        data_.resize(sz);
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    MatrixRepRow<D, NR, NC>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixRepRow<D, NR, NC>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> deepdims(deepdims_new);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    MatrixRepRow<D, NR, NC>& reshape(const size_type nr, const size_type nc) {
      const size_type nn = nr*nc;
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


    MatrixRepRow<D, NR, NC>& transpose(void) {
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, MatrixRepRow<D, NR, NC>& >::type adjoint() {
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
      const Indices& inds = indices(n);;
      index_type r = inds[0];
      index_type c = inds[1];
      return (*this)(r, c);
    }

    // read
    const D operator[](const index_type n)  const {
      const Indices& inds = indices(n);;
      index_type r = inds[0];
      index_type c = inds[1];
      return (*this)(r, c);
    }


    // --------------------------- index(r,c) -----------------------------

    index_type index(const index_type r, const index_type c) const {
      //TODO: bounds check
      return c + Ncols_*r; // row major
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the above function
    Indices& indices(const index_type k) const {
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
    //***************Tensor-style Element Access: A(r,c) *********************
    //**********************************************************************

    D& operator()(const index_type r, const index_type c) {
      return data_[c];
    }

    const D operator()(const index_type r, const index_type c) const {
      return data_[c];
    }



    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************


    MatrixRepRow<D, NR, NC>& set(const Vector<D>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }
    MatrixRepRow<D, NR, NC>& operator=(const Vector<D>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixRepRow<D, NR, NC>& operator=(const TensorR<X, D, D, 1, 1>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
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

    MatrixRepRow<D, NR, NC>& operator=(const D& value) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = value;
      }
      return *this;
    }

    MatrixRepRow<D, NR, NC>& operator=(const MatrixRepRow<D, NR, NC>& b) {
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

    MatrixRepRow<D, NR, NC>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, MatrixRepRow<D, NR, NC>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixRepRow";
      s += StyledString::get(ANGLE1).get();
      s += getTypeName(D());
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixRepRow<D, NR, NC>& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const mathq::index_type N = FormatDataMatrix::max_elements_per_line;

      for (mathq::index_type r = 0; r < m.Nrows(); r++) {
        stream << style.apply(FormatDataMatrix::string_row_opening);
        mathq::index_type k = 0;
        for (mathq::index_type c = 0; c < m.Ncols(); c++, k++) {
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


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s, MatrixRepRow<D, NR, NC>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixRepRow<D, NR, NC>& m2) {
      return stream;
    }




  };




};


#endif 

