#ifndef MATHQ__SCALAR_H
#define MATHQ__SCALAR_H 1


namespace mathq {

  //*************
  // DEPRECATED 
  //*************


    /********************************************************************
     * Scalar<E>    -- variable size vector (valarray)
     *                 E  = type for elements
     *
     * DO NOT SPECIFY: D,M
     *                 The defaults are defined in the declaration in
     *                 preface.h
     *                 D = number type
     *                   = underlying algebraic field
     *                     ex. int, double, std::complex<double>
     *                 M = tensor depth. if E=D, then M=1.
    ********************************************************************
     */


  template <class E, typename D, int M> class Scalar :
    public TensorRW< Scalar<E, D, M>, E, D, M, 0> {
  public:
    typedef Scalar<E, D, M> XType;
    typedef E EType;
    typedef D DType;
    typedef typename FundamentalType<D>::Type FType;
    constexpr static int Rvalue = 0;
    constexpr static int Mvalue = M;
    typedef typename std::conditional<M==1, E, E&>::type TypeA;

  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight

    E data_;




  public:

    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: zero --------------------
    Scalar<E, D, M>() {
      if constexpr (M==1) {
        *this = 0;
      }
      else {
        data_ = *(new E());
      }
      constructorHelper();
    }

    // --------------------- constant E CONSTRUCTOR ---------------------

    Scalar<E, D, M>(const E e) {

      *this = e;
      constructorHelper();
    }

    // --------------------- constant D CONSTRUCTOR ---------------------

    template<int M1 = M, EnableIf<(M1>1)> = 0>

    Scalar<E, D, M>(const D d) {

      *this = d;
      constructorHelper();
    }

    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class X>
    Scalar<E, D, M>(const TensorR<X, E, D, M, Rvalue>& x) {

      *this = x;
      constructorHelper();
    }


    // ************* C++11 initializer_list CONSTRUCTOR---------------------
    Scalar<E, D, M>(const std::initializer_list<E>& mylist) {
      *this = mylist;
      constructorHelper();
    }


    // --------------------- constructorHelper() --------------------

    void constructorHelper() {
      //add to TensorPool
    }





    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Scalar<E, D, M>() {
      //remove from TensorPool
    }


    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************


    inline size_type size(void) const {
      return 1;
    }
    inline size_type depth(void) const {
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
    inline size_type elsize(void) const {
      if constexpr (M<2) {
        return 1;
      }
      else {
        return data_.size();
      }
    }
    inline size_type eldeepsize(void) const {
      if constexpr (M<2) {
        return 1;
      }
      else {
        return data_.deepsize();
      }
    }
    size_type deepsize(void) const {
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


    size_type ndims(void) const {
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
    Tensors getEnum(void) const {
      return T_SCALAR;
    }
    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }


    // TODO: should just pass an index and make deepdims const


    Scalar<E, D, M>& resize(std::vector<Dimensions>& deepdims) {
      if constexpr (M>1) {
        deepdims.erase(deepdims.begin());
        data_.resize(deepdims);
      }
      return *this;
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************

    // -------------------- D dat(n) --------------------
    // NOTE: indexes over [0] to [deepsize()]
    // -------------------------------------------------------------

    // "read/write": unsigned
    D& dat(const index_type n) {
      if constexpr (M <= 1) {
        return data_;
      }
      else {
        return (data_).dat(n);
      }
    }

    // "read/write": signed
    const D& dat(const index_type n)  const {
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
    D& dat(const DeepIndices& dinds) {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (M>1) {
        return (*this)().dat(dinds);
      }
      else {
        return (*this)();
      }
    }

    // "read": DeepIndices
    const D dat(const DeepIndices& dinds)  const {
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
    D& dat(const Indices& inds) {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (M>1) {
        return (*this)().dat(inds);
      }
      else {
        return (*this)();
      }
    }

    // "read": Indices
    const D dat(const Indices& inds)  const {
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
    E& operator[](const index_type n) {
      return data_;
    }

    // "read/write": signed
    const E& operator[](const index_type n)  const {
      return data_;
    }


    //**********************************************************************
    //***************** Element ACCESS as a tensor *************************
    //**********************************************************************



    // "read/write"
    E& operator()() {
      return data_;
    }

    // "read only"
    const E& operator()()  const {
      return data_;
    }





    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    Scalar<E, D, M>& operator=(const E e) {
      data_ = e;
      return *this;
    }

    template <int M1 = M>
    typename std::enable_if<(M1>1), Scalar<E, D, M>& >::type operator=(const D& d) {
      for (index_type i = 0; i < deepsize(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }


    Scalar<E, D, M>& operator=(const Scalar<E, D, M>& s2) {
      if constexpr (M<=1) {
        data_ = s2();
      }
      else {
        resize(s2.deepdims());
        for (index_type i = 0; i < deepsize(); i++) {
          (*this).dat(i) = s2.dat(i);
        }
      }
      return *this;
    }


    Scalar<E, D, M>& operator=(const std::initializer_list<E>& mylist) {
      typename std::initializer_list<E>::iterator it = mylist.begin();
      data_ = *it;
      return *this;
    }


    template <class X>
    Scalar<E, D, M>& operator=(const TensorR<X, E, D, M, Rvalue>& x) {
      if constexpr (M<=1) {
        data_ = x[0];
      }
      else {
        resize(x.deepdims());
        for (index_type i = 0; i < deepsize(); i++) {
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


    Scalar<E, D, M>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      data_ = mathq::roundzero(data_, tolerance);
      return *this;
    }

    //----------------- .conj() ---------------------------
    // NOTE: in-place. Don't allow if not complex.
    //----------------------------------------------------
    template< typename T = D >
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
      E e;
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

    friend std::ostream& operator<<(std::ostream& stream, const Scalar<E, D, M>& s) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      dispval_strm(stream, s());
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s, Scalar<E, D, M>& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream, Scalar<E, D, M>& x) {
      return stream;
    }

    // --------------------- FRIENDS ---------------------



  };




};


#endif 

