#ifndef MATHQ__SCALAR_H
#define MATHQ__SCALAR_H 1


namespace mathq {

  //*************
  // DEPRECATED 
  //*************


    /********************************************************************
     * Scalar<Element>    -- variable size vector (valarray)
     *                 Element  = type for elements
     *
     * DO NOT SPECIFY: Number,M
     *                 The defaults are defined in the declaration in
     *                 preface.h
     *                 Number = number type
     *                   = underlying algebraic field
     *                     ex. int, double, std::complex<double>
     *                 M = tensor depth. if Element=Number, then M=1.
    ********************************************************************
     */


  template <class Element, typename Number, int M> class Scalar :
    public MArrayExpRW< Scalar<Element, Number, M>, Element, Number, M, 0> {
  public:
    typedef Scalar<Element, Number, M> XType;
    typedef Element EType;
    typedef Number DType;
    typedef typename OrderedNumberTrait<Number>::Type FType;
    constexpr static int Rvalue = 0;
    constexpr static int Mvalue = M;
    typedef typename std::conditional<M==1, Element, Element&>::type TypeA;

  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight

    Element data_;




  public:

    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: zero --------------------
    Scalar<Element, Number, M>() {
      if constexpr (M==1) {
        *this = 0;
      }
      else {
        data_ = *(new Element());
      }
      constructorHelper();
    }

    // --------------------- constant Element CONSTRUCTOR ---------------------

    Scalar<Element, Number, M>(const Element e) {

      *this = e;
      constructorHelper();
    }

    // --------------------- constant Number CONSTRUCTOR ---------------------

    template<int M1 = M, EnableIf<(M1>1)> = 0>

    Scalar<Element, Number, M>(const Number d) {

      *this = d;
      constructorHelper();
    }

    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class X>
    Scalar<Element, Number, M>(const MArrayExpR<X, Element, Number, M, Rvalue>& x) {

      *this = x;
      constructorHelper();
    }


    // ************* C++11 initializer_list CONSTRUCTOR---------------------
    Scalar<Element, Number, M>(const std::initializer_list<Element>& mylist) {
      *this = mylist;
      constructorHelper();
    }


    // --------------------- constructorHelper() --------------------

    void constructorHelper() {
      //add to MultiArrayPool
    }





    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Scalar<Element, Number, M>() {
      //remove from MultiArrayPool
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************


    inline size_t size(void) const {
      return 1;
    }
    inline size_t depth(void) const {
      return M;
    }

    Dimensions eldims(void) const {
      Dimensions dimensions();
      if constexpr (M>1) {
        return data_.dims();
      }
      else {
        return *(new Dimensions());
      }
    }
    inline size_t elsize(void) const {
      if constexpr (M<2) {
        return 1;
      }
      else {
        return data_.size();
      }
    }
    inline size_t eldeepsize(void) const {
      if constexpr (M<2) {
        return 1;
      }
      else {
        return data_.deepsize();
      }
    }
    size_t deepsize(void) const {
      if constexpr (M<2) {
        return this->size();
      }
      else {
        return (this->size())*(this->eldeepsize());
      }
    }
    std::vector<Dimensions>& deepdims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return deepdims(ddims);
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      parentdims.push_back(dims());
      if constexpr (M>1) {
        data_.deepdims(parentdims);
      }
      return parentdims;
    }


    size_t ndims(void) const {
      return 0;
    }
    Dimensions dims(void) const {
      Dimensions dimensions;
      return dimensions;
    }
    Dimensions tdims(void) const {
      Dimensions dimensions;
      return dimensions;
    }
    bool isExpression(void) const {
      return false;
    }
    MultiArrays getEnum(void) const {
      return T_SCALAR;
    }
    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }


    // TODO: should just pass an index and make deepdims const


    Scalar<Element, Number, M>& resize(std::vector<Dimensions>& deepdims) {
      if constexpr (M>1) {
        deepdims.erase(deepdims.begin());
        data_.resize(deepdims);
      }
      return *this;
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************

    // -------------------- Number dat(n) --------------------
    // NOTE: indexes over [0] to [deepsize()]
    // -------------------------------------------------------------

    // "read/write": unsigned
    Number& dat(const size_t n) {
      if constexpr (M <= 1) {
        return data_;
      }
      else {
        return (data_).dat(n);
      }
    }

    // "read/write": signed
    const Number& dat(const size_t n)  const {
      if constexpr (M <= 1) {
        return data_;
      }
      else {
        return (data_).dat(n);
      }
    }

    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------

    // "read/write": DeepIndices
    Number& dat(const DeepIndices& dinds) {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (M>1) {
        return (*this)().dat(dinds);
      }
      else {
        return (*this)();
      }
    }

    // "read": DeepIndices
    const Number dat(const DeepIndices& dinds)  const {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (M>1) {
        return (*this)().dat(dinds);
      }
      else {
        return (*this)();
      }
    }


    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------

    // "read/write": Indices
    Number& dat(const Indices& inds) {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (M>1) {
        return (*this)().dat(inds);
      }
      else {
        return (*this)();
      }
    }

    // "read": Indices
    const Number dat(const Indices& inds)  const {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (M>1) {
        return (*this)().dat(inds);
      }
      else {
        return (*this)();
      }
    }




    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************

    // "read/write": unsigned
    Element& operator[](const size_t n) {
      return data_;
    }

    // "read/write": signed
    const Element& operator[](const size_t n)  const {
      return data_;
    }


    //**********************************************************************
    //***************** Element ACCESS as a tensor *************************
    //**********************************************************************



    // "read/write"
    Element& operator()() {
      return data_;
    }

    // "read only"
    const Element& operator()()  const {
      return data_;
    }





    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    Scalar<Element, Number, M>& operator=(const Element e) {
      data_ = e;
      return *this;
    }

    template <int M1 = M>
    typename std::enable_if<(M1>1), Scalar<Element, Number, M>& >::type operator=(const Number& d) {
      for (size_t i = 0; i < deepsize(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }


    Scalar<Element, Number, M>& operator=(const Scalar<Element, Number, M>& s2) {
      if constexpr (M<=1) {
        data_ = s2();
      }
      else {
        resize(s2.deepdims());
        for (size_t i = 0; i < deepsize(); i++) {
          (*this).dat(i) = s2.dat(i);
        }
      }
      return *this;
    }


    Scalar<Element, Number, M>& operator=(const std::initializer_list<Element>& mylist) {
      typename std::initializer_list<Element>::iterator it = mylist.begin();
      data_ = *it;
      return *this;
    }


    template <class X>
    Scalar<Element, Number, M>& operator=(const MArrayExpR<X, Element, Number, M, Rvalue>& x) {
      if constexpr (M<=1) {
        data_ = x[0];
      }
      else {
        resize(x.deepdims());
        for (size_t i = 0; i < deepsize(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }



    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place


    Scalar<Element, Number, M>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      data_ = mathq::roundzero(data_, tolerance);
      return *this;
    }

    //----------------- .conj() ---------------------------
    // NOTE: in-place. Don't allow if not complex.
    //----------------------------------------------------
    template< typename T = Number >
    typename std::enable_if<is_complex<T>{}, Scalar<T>& >::type conj() {
      using std::conj;
      data_ = conj(data_);
      return *this;
    }





    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "Scalar";
      s += StyledString::get(ANGLE1).get();
      Element e;
      s += getTypeName(e);
      //if (M>1) {
      //  s += StyledString::get(COMMA).get();
      //  s += "M=";
      //  s += num2string(M);
      //}
      s += StyledString::get(ANGLE2).get();
      return s;
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif


    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Scalar<Element, Number, M>& s) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      dispval_strm(stream, s());
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }


    //template <class Number>	
    friend inline std::istream& operator>>(const std::string s, Scalar<Element, Number, M>& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream, Scalar<Element, Number, M>& x) {
      return stream;
    }

    // --------------------- FRIENDS ---------------------



  };




};


#endif 

