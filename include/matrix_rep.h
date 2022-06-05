#ifndef MATHQ__REPMATRIX_H
#define MATHQ__REPMATRIX_H 1



namespace mathq {


  using namespace MatrixRepTypes;


  /********************************************************************
   * MatrixRep<D>        -- variable size matrix (valarray)
   *                        D  = type for elements
  * Matrix defined by a single vector that can have repeated rows or repeated cols
   ********************************************************************
   */

  template <class D>
  class MatrixRep : public MArrayExpRW<MatrixRep<D>, D, D, 1, 2> {

  public:
    constexpr static int R = 2;
    constexpr static int Rvalue = 2;
    constexpr static int Mvalue = 1;
    typedef MatrixRep<D> XType;
    typedef D EType;
    typedef D DType;
    typedef typename FundamentalType<D>::Type FType;


    typedef typename std::valarray<D> MyArrayType;

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
    MatrixRepEnum repeatType;

    static_assert(NumberType<D>::value,
      "class MatrixRep can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:



    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixRep<D>() {
      resize(0, 0);
      repeatType = REPEAT_ROW;
      *this = 0;
    }


    // -------------------  Full constructor  --------------------

    explicit MatrixRep<D>(const size_t Nrows, const size_t Ncols, const MatrixRepEnum& type, const Vector<D>& v) {
      // debug: verify that v is correct size per repeatType
      resize(Nrows, Ncols);
      repeatType = type;
      *this = v;
    }



    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixRep<D>() {
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
    MultiArrays getEnum() const {
      return T_MATRIX;
    }

    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    Dimensions tdims(void) const {
      Dimensions dimensions(0, 0);
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

    MatrixRep<D>& resize(const int Nr, const int Nc) {
      Nrows_ = Nr;
      Ncols_ = Nc;
      const index_type sz;
      if (repeatType == REPEAT_ROW) {
        sz = Ncols_;
      }
      else {
        sz = Nrows_;
      }
      data_.resize(sz);
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    MatrixRep<D>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixRep<D>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> deepdims(deepdims_new);
      Dimensions newdims = deepdims[0];
      resize(newdims);
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
    //***************MultiArray-style Element Access: A(r,c) *********************
    //**********************************************************************

    D& operator()(const index_type r, const index_type c) {
      if (repeatType == REPEAT_ROW) {
        return data_[c];
      }
      else {
        return data_[r];
      }
    }

    const D operator()(const index_type r, const index_type c) const {
      if (repeatType == REPEAT_ROW) {
        return data_[c];
      }
      else {
        return data_[r];
      }
    }



    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************


    MatrixRep<D>& set(const Vector<D>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }
    MatrixRep<D>& operator=(const Vector<D>& v) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = v[k];
      }
      return *this;
    }

    template <class X>
    MatrixRep<D>& operator=(const MArrayExpR<X, D, D, 1, 1>& v) {
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

    MatrixRep<D>& operator=(const D& value) {
      for (index_type k = 0; k < data_.size(); k++) {
        data_[k] = value;
      }
      return *this;
    }

    MatrixRep<D>& operator=(const MatrixRep<D>& b) {
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

    MatrixRep<D>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = D >
    typename std::enable_if<is_complex<T>{}, MatrixRep<D>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixRep";
      s += StyledString::get(ANGLE1).get();
      s += getTypeName(D());
      s += StyledString::get(ANGLE2).get();
      return s;
    }



    // stream << operator


    friend std::ostream& operator<<(std::ostream& stream, const MatrixRep<D>& m) {
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
    friend inline std::istream& operator>>(const std::string s, MatrixRep<D>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixRep<D>& m2) {
      return stream;
    }



#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif




  };




};


#endif 

