#ifndef MATHQ__REVDIAGMATRIX_H
#define MATHQ__REVDIAGMATRIX_H 1




namespace mathq {


  /********************************************************************
   * MatrixRevDiag<Number        -- variable size matrix (valarray)
   *                        Number  = type for elements
   * MatrixRevDiag<Number,NR>    -- fixed number of rows (valarray)
   *                        NR = number of rows
   * MatrixRevDiag<Number,NR,NC> -- fixed number of rows and cols (array)
   *                        NC = number of cols
   ********************************************************************
   */

   //, typename = EnableIf<NumberTrait<Number>::value>
  template <typename Number, int NR, int NC >
  class MatrixRevDiag : public MArrayExpRW<MatrixRevDiag<Number, NR, NC>, Number, Number, 1, 2> {

  public:
    constexpr static int rank = 2;
    constexpr static int rank_value = 2;
    constexpr static int depth_value = 1;
    static constexpr bool resizable = (NR*NC==0) ? true : false;
    static constexpr bool resizableRows = (NR==0) ? true : false;
    static constexpr bool resizableCols = (NC==0) ? true : false;
    typedef MatrixRevDiag<Number, NR, NC> ConcreteType;
    typedef Number ElementType;
    typedef Number NumberType;
    typedef typename SimpleNumberTrait<Number>::Type OrderedNumberType;


    // if either NR or NC is 0, then we use valarray
    typedef typename ArrayTypeTrait<Number, std::min(NR, NC)>::Type MyArrayType;

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    const Number zero_ = 0;
    Number dummy_ = 0;
    MyArrayType data_;

    size_t   Nrows_;
    size_t   Ncols_;

    static_assert(NumberTrait<Number>::value,
      "class MatrixRevDiag can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixRevDiag<Number, NR, NC>() {
      size_t   NN = NR*NC;
      resize(NR, NC);
      *this = 1;
    }

    // -------------------  Number value --------------------
    explicit MatrixRevDiag<Number, NR, NC>(const Number& value) {
      size_t   NN = NR*NC;
      resize(NR, NC);
      *this = value;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRevDiag<Number, NR, NC>(const size_t   Nr, const size_t   Nc) {
      resize(Nr, Nc);
      *this = 1;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixRevDiag<Number, NR, NC>(const size_t   Nr, const size_t   Nc, const Number& value) {
      resize(Nr, Nc);
      *this = value;
    }




    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixRevDiag<Number, NR, NC>() {
      //remove from directory
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    size_t   rank(void)  const {
      return rank_value;
    }


    inline size_t   size(void) const {
      return Nrows()*Ncols();
    }
    inline size_t   Nrows(void) const {
      return Nrows_;
    }
    inline size_t   Ncols(void) const {
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


    constexpr size_t   depth(void) const {
      return depth_value;
    }
    Dimensions element_dims(void) const {
      Dimensions dimensions();
      return *(new Dimensions());
    }

    // the size of each element
    inline size_t   element_size(void) const {
      return 1;
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_t   eldeepsize(void) const {
      return 1;
    }

    // the total number of numbers in this data structure
    size_t   deepsize(void) const {
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

    MatrixRevDiag<Number, NR, NC>& resize(const int Nr, const int Nc) {
      Nrows_ = NR;
      Ncols_ = NC;
      if constexpr (resizableRows) {
        Nrows_ = Nr;
      }
      if constexpr (resizableCols) {
        Ncols_ = Nc;
      }
      if constexpr (resizable) {
        const size_t   sz = std::min(Nrows_, Ncols_);
        data_.resize(sz);
      }
      return *this;
    }



    // -------------------------- resize(Dimensions) --------------------------------

    MatrixRevDiag<Number, NR, NC>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixRevDiag<Number, NR, NC>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> deepdims(deepdims_new);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    MatrixRevDiag<Number, NR, NC>& reshape(const size_t   nr, const size_t   nc) {
      const size_t   nn = nr*nc;
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


    MatrixRevDiag<Number, NR, NC>& transpose(void) {
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = Number >
    typename std::enable_if<is_complex<T>{}, MatrixRevDiag<Number, NR, NC>& >::type adjoint() {
      return *this;
    }



    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // read
    const Number dat(const size_t   n)  const {
      return (*this)[n];
    }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(Indices)
    const Number dat(const Indices& inds)  const {
      size_t   r = inds[0];
      size_t   c = inds[1];
      return (*this)(r, c);
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(DeepIndices)
    const Number dat(const DeepIndices& dinds)  const {
      const size_t   mydepth = dinds.size();
      const Indices& inds = dinds[mydepth -depth_value];
      size_t   r = inds[0];
      size_t   c = inds[1];
      return (*this)(r, c);
    }


    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // read / write
    Number& operator[](const size_t   n) {
      const Indices& inds = indices(n);;
      size_t   r = inds[0];
      size_t   c = inds[1];
      return (*this)(r, c);
    }

    // read
    const Number operator[](const size_t   n)  const {
      const Indices& inds = indices(n);;
      size_t   r = inds[0];
      size_t   c = inds[1];
      return (*this)(r, c);
    }


    // --------------------------- index(r,c) -----------------------------

    size_t   index(const size_t   r, const size_t   c) const {
      //TODO: bounds check
      return c + Ncols_*r; // row major
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the above function
    Indices& indices(const size_t   k) const {
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

    Number& operator()(const size_t   r, const size_t   c) {
      if (r+c+1==Ncols_) {
        return data_[r];
      }
      else {
        return (dummy_ = 0);
      }
    }

    const Number operator()(const size_t   r, const size_t   c) const {
      if (r+c+1==Ncols_) {
        return data_[r];
      }
      else {
        return zero_;
      }
    }



    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************

    MatrixRevDiag<Number, NR, NC>& operator=(const Number& value) {
      for (size_t k = 0; k < data_.size(); k++) {
        data_[k] = value;
      }
      return *this;
    }

    MatrixRevDiag<Number, NR, NC>& operator=(const MatrixRevDiag<Number, NR, NC>& b) {
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

    MatrixRevDiag<Number, NR, NC>& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = Number >
    typename std::enable_if<is_complex<T>{}, MatrixRevDiag<Number, NR, NC>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixRevDiag";
      s += StyledString::get(ANGLE1).get();
      s += getTypeName(Number());
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixRevDiag<Number, NR, NC>& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const size_t   N = FormatDataMatrix::max_elements_per_line;

      for (size_t r = 0; r < m.Nrows(); r++) {
        stream << style.apply(FormatDataMatrix::string_row_opening);
        size_t   k = 0;
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


    //template <typename Number>	
    friend inline std::istream& operator>>(const std::string s, MatrixRevDiag<Number, NR, NC>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixRevDiag<Number, NR, NC>& m2) {
      return stream;
    }




  };




};


#endif 

