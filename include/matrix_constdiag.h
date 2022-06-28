#ifndef MATHQ__CONSTDIAGMATRIX_H
#define MATHQ__CONSTDIAGMATRIX_H 1




namespace mathq {


  /********************************************************************
   * MatrixConstDiag<Number        -- variable size matrix (valarray)
   *                        Number  = type for elements
   * MatrixConstDiag<Number,NR>    -- fixed number of rows (valarray)
   *                        NR = number of rows
   * MatrixConstDiag<Number,NR,NC> -- fixed number of rows and cols (array)
   *                        NC = number of cols
   ********************************************************************
   */

   //, typename = EnableIf<NumberTrait<Number>::value>
  template <typename Number, int NR, int NC >
  class MatrixConstDiag : public MArrayExpRW<MatrixConstDiag<Number, NR, NC>, Number, Number, 1, 2> {

  public:
    constexpr static int rank = 2;
    constexpr static int rank_value = 2;
    constexpr static int Mvalue = 1;
    static constexpr bool resizable = (NR*NC==0) ? true : false;
    static constexpr bool resizableRows = (NR==0) ? true : false;
    static constexpr bool resizableCols = (NC==0) ? true : false;
    typedef MatrixConstDiag<Number, NR, NC> ConcreteType;
    typedef Number ElementType;
    typedef Number NumberType;
    typedef typename OrderedNumberTrait<Number>::Type OrderedNumberType;



    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
  private:
    const Number zero_ = 0;
    Number value_ = 1;

    size_t Nrows_;
    size_t Ncols_;

    static_assert(NumberTrait<Number>::value,
      "class MatrixConstDiag can only have numbers as elements, ie not vectors, matrices etc.");



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

  public:

    // -------------------  DEFAULT  CONSTRUCTOR --------------------
    explicit MatrixConstDiag<Number, NR, NC>() {
      size_t NN = NR*NC;
      resize(NR, NC);
      value_ = 1;
    }

    // -------------------  Number value --------------------
    explicit MatrixConstDiag<Number, NR, NC>(const Number& value) {
      size_t NN = NR*NC;
      resize(NR, NC);
      value_ = value;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixConstDiag<Number, NR, NC>(const size_t Nr, const size_t Nc) {
      resize(Nr, Nc);
      value_ = 1;
    }

    // --------------------- variable-size CONSTRUCTOR ---------------------
    template<size_t NN = NR*NC, EnableIf<NN == 0> = 0>

    explicit MatrixConstDiag<Number, NR, NC>(const size_t Nr, const size_t Nc, const Number& value) {
      resize(Nr, Nc);
      value_ = value;
    }




    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MatrixConstDiag<Number, NR, NC>() {
      //remove from directory
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    size_t ndims(void)  const {
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

    Dimensions tdims(void) const {
      Dimensions dimensions(NR, NC);
      return dimensions;
    }


    constexpr size_t getDepth(void) const {
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

    MatrixConstDiag<Number, NR, NC>& resize(const int Nr, const int Nc) {
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

    MatrixConstDiag<Number, NR, NC>& resize(const Dimensions dims) {
      resize(dims[0], dims[1]);
      return *this;
    }



    MatrixConstDiag<Number, NR, NC>& resize(const std::vector<Dimensions>& deepdims_new) {
      std::vector<Dimensions> deepdims(deepdims_new);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      return *this;
    }



    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    MatrixConstDiag<Number, NR, NC>& reshape(const size_t nr, const size_t nc) {
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


    MatrixConstDiag<Number, NR, NC>& transpose(void) {
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = Number >
    typename std::enable_if<is_complex<T>{}, MatrixConstDiag<Number, NR, NC>& >::type adjoint() {
      return *this;
    }


    Number getValue() const {
      return value_;
    }
    MatrixConstDiag<Number, NR, NC>& setValue(const Number& value) {
      value_ = value;
      return *this;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // read
    const Number dat(const size_t n)  const {
      return (*this)[n];
    }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(Indices)
    const Number dat(const Indices& inds)  const {
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------


    // "read": x.dat(DeepIndices)
    const Number dat(const DeepIndices& dinds)  const {
      const size_t mydepth = dinds.size();
      const Indices& inds = dinds[mydepth - Mvalue];
      size_t r = inds[0];
      size_t c = inds[1];
      return (*this)(r, c);
    }


    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // read
    const Number operator[](const size_t n)  const {
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


    const Number operator()(const size_t r, const size_t c) const {
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

    MatrixConstDiag<Number, NR, NC>& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = Number >
    typename std::enable_if<is_complex<T>{}, MatrixConstDiag<Number, NR, NC>& >::type conj() {
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MatrixConstDiag";
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


    friend std::ostream& operator<<(std::ostream& stream, const MatrixConstDiag<Number, NR, NC>& m) {
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


    //template <typename Number>	
    friend inline std::istream& operator>>(const std::string s, MatrixConstDiag<Number, NR, NC>& m2) {
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream, MatrixConstDiag<Number, NR, NC>& m2) {
      return stream;
    }




  };




};


#endif 

