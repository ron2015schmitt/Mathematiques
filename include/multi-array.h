#ifndef MATHQ__TENSOR_H
#define MATHQ__TENSOR_H 1

namespace mathq {



  //----------------------------------------------
  // zeros
  //----------------------------------------------

  template <class E>
  inline auto& zeros() {
    E* e = new E();
    *e = 0 * *e;
    return *e;
  }


  //----------------------------------------------
  // ones
  //----------------------------------------------

  template <class E>
  inline auto& ones() {
    E* e = new E();
    *e = 0 * *e + 1;
    return *e;
  }




  /********************************************************************
   * MultiArray<E>      -- MultiArray of 0 rank (scalar)
   *                   E  = type for elements
   * MultiArray<E,R> -- MultiArray of R rank
   *                   R = number of rank (0=scalar,1=vector,2=matrix,etc)
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

  template <class E, int R, typename D, int M>
  class
    MultiArray : public MArrayExpRW<MultiArray<E, R, D, M>, E, D, M, R> {
  public:
    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight

    typedef MultiArray<E, R, D, M> XType;
    typedef E EType;
    typedef D DType;
    typedef typename OrderedNumberTrait<D>::Type FType;

    constexpr static int Rvalue = R;
    constexpr static int Mvalue = M;

    // always use valarray
    typedef typename ArrayType<E, 0>::Type MyArrayType;

  private:
    MyArrayType data_;
    Dimensions* dimensions_;

  public:
    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************

    // --------------------- default CONSTRUCTOR ---------------------

    explicit MultiArray<E, R, D, M>() {
      std::vector<size_t> dv(R);
      resize(new Dimensions(dv));
      constructorHelper();
    }

    // --------------------- constant=0 CONSTRUCTOR ---------------------

    explicit MultiArray<E, R, D, M>(const Dimensions& dims) {
      resize(dims);
      constructorHelper();
    }

    // --------------------- constant E CONSTRUCTOR ---------------------

    explicit MultiArray<E, R, D, M>(const Dimensions& dims, const E& e) {
      resize(dims);
      constructorHelper();
      *this = e;
    }

    // --------------------- constant E CONSTRUCTOR ---------------------

    template <size_t M1 = M, EnableIf<(M1 > 0)> = 0>

    explicit MultiArray<E, R, D, M>(const Dimensions& dims, const D d) {
      resize(dims);
      constructorHelper();
      *this = d;
    }

    // ************* C++11 initializer_list CONSTRUCTOR---------------------
    MultiArray<E, R, D, M>(const NestedInitializerList<E, R>& mylist) {
      *this = mylist;
      constructorHelper();
    }

    // ************* Expression CONSTRUCTOR---------------------

    template <class X>
    MultiArray<E, R, D, M>(const MArrayExpR<X, E, D, M, R>& x) {
      *this = x;
      constructorHelper();
    }


    // ************* Vector Constructor---------------------
    template <int NE>
    MultiArray<E, R, D, M>(const Vector<E, NE>& v) {
      resize(v.deepdims());
      for (int c = 0; c < v.deepsize(); c++) {
        (*this)[c] = v[c];
      }
      constructorHelper();
    }


    // --------------------- constructorHelper() --------------------

    void constructorHelper() {
    }

    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~MultiArray<E, R, D, M>() {
      // remove from directory
    }

    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    inline size_t size(void) const {
      return data_.size();
    }
    size_t ndims(void) const {
      return dimensions_->ndims();
    }
    Dimensions dims(void) const {
      return *dimensions_;
    }
    bool isExpression(void) const {
      return false;
    }
    MultiArrays getEnum() const {
      return T_TENSOR;
    }

    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    size_t tdims(void) const {
      return dims();
    }

    inline size_t depth(void) const {
      return M;
    }

    Dimensions eldims(void) const {
      Dimensions dimensions();
      if constexpr (M > 1) {
        if (size() > 0) {
          return data_[0].dims();
        }
      }
      return *(new Dimensions());
    }

    // the size of each element
    inline size_t elsize(void) const {
      if constexpr (M < 2) {
        return 1;
      }
      else {
        const size_t Nelements = this->size();
        if (Nelements == 0) {
          return 0;
        }
        else {
          return data_[0].size();
        }
      }
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_t eldeepsize(void) const {
      if constexpr (M < 2) {
        return 1;
      }
      else {
        const size_t Nelements = this->size();
        if (Nelements == 0) {
          return 0;
        }
        else {
          return data_[0].deepsize();
        }
      }
    }

    // the total number of numbers in this data structure
    size_t deepsize(void) const {
      if constexpr (M < 2) {
        return this->size();
      }
      else {
        return (this->size()) * (this->eldeepsize());
      }
    }
    std::vector<Dimensions>& deepdims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return deepdims(ddims);
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      parentdims.push_back(dims());
      if constexpr (M > 1) {
        if (size() > 0) {
          data_[0].deepdims(parentdims);
        }
      }
      return parentdims;
    }

    //**********************************************************************
    //********************* Resize ********************** ******************
    //**********************************************************************

    MultiArray& resize(const Dimensions& dims_in) {
      Dimensions dims = dims_in;
      while (dims.rank() < R) {
        dims.push_back(0);
      }
      dimensions_ = new Dimensions(dims);
      data_.resize(dimensions_->datasize());
      return *this;
    }

    MultiArray& resize(const Dimensions* dims_in) {
      return resize(*dims_in);
    }

    // TODO: should just pass an index and make deepdims const

    MultiArray<E, R, D, M>& resize(const std::vector<Dimensions>& deepdims_in) {
      std::vector<Dimensions> deepdims(deepdims_in);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      if constexpr (M > 1) {
        deepdims.erase(deepdims.begin());
        for (size_t i = 0; i < size(); i++) {
          std::vector<Dimensions> ddims(deepdims);
          data_[i].resize(ddims);
        }
      }
      return *this;
    }

    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- getInternalStdArray() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& getInternalStdArray() {
      return data_;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    E* data() {
      // MutltiArrays are always wrap avalarray<E>
      return &(data_[0]);
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // "read/write"
    D& dat(const size_t n) {
      using namespace ::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
      if constexpr (M < 2) {
        int k = n;
        if (k < 0) {
          k += size();
        }
        return data_[k];
      }
      else {
        const int Ndeep = this->eldeepsize();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }

    // read
    const D& dat(const size_t n) const {
      using namespace ::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
      if constexpr (M < 2) {
        int k = n;
        if (k < 0) {
          k += size();
        }
        return data_[k];
      }
      else {
        const int Ndeep = this->eldeepsize();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------

    // "read/write": x.dat(Indices)
    D& dat(const Indices& inds) {
      // printf("MultiArray.dat(Indices)\n");
      // MOUT << "  ";
      // TLDISP(inds.size());
      // MOUT << "  ";
      // TLDISP(inds);
      // MOUT << "  ";
      // TLDISP(ndims());
      Indices inds_next(inds);
      // error if (inds.size() != sum deepdims[i].rank
      Indices mine;
      for (int i = 0; i < ndims(); i++) {
        mine.push_back(inds_next[0]);
        inds_next.erase(inds_next.begin());
      }
      // MOUT << "  ";
      // TLDISP(mine);
      // MOUT << "  ";
      // TLDISP(inds_next);
      if constexpr (M > 1) {
        return (*this)(mine).dat(inds_next);
      }
      else {
        return (*this)(mine);
      }
    }

    // "read": x.dat(Indices)
    const D dat(const Indices& inds) const {
      // printf("MultiArray.dat(Indices) const\n");
      // MOUT << "  ";
      // TLDISP(inds.size());
      // MOUT << "  ";
      // TLDISP(inds);
      // MOUT << "  ";
      // TLDISP(ndims());
      Indices inds_next(inds);
      // error if (inds.size() != sum deepdims[i].rank
      Indices mine;
      for (int i = 0; i < ndims(); i++) {
        mine.push_back(inds_next[0]);
        inds_next.erase(inds_next.begin());
      }
      // MOUT << "  ";
      // TLDISP(mine);
      // MOUT << "  ";
      // TLDISP(inds_next);
      if constexpr (M > 1) {
        return (*this)(mine).dat(inds_next);
      }
      else {
        return (*this)(mine);
      }
    }

    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------

    // "read/write": x.dat(DeepIndices)
    D& dat(const DeepIndices& dinds) {
      const size_t depth = dinds.size();
      const Indices& inds = dinds[depth - M];

      if constexpr (M > 1) {
        return (*this)(inds).dat(dinds);
      }
      else {
        return (*this)(inds);
      }
    }

    // "read": x.dat(DeepIndices)
    const D dat(const DeepIndices& dinds) const {
      const size_t depth = dinds.size();
      const Indices& inds = dinds[depth - M];

      if constexpr (M > 1) {
        return (*this)(inds).dat(dinds);
      }
      else {
        return (*this)(inds);
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // "read/write"
    E& operator[](const size_t n) {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }

    // read
    const E& operator[](const size_t n) const {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }

    //**********************************************************************
    //*******MultiArray-style Element Access: A(i,j,k,...) *********************
    //**********************************************************************

    size_t indexOf(const Indices& inds) const {
      return dimensions_->index(inds);
    }

    /* template<typename... Ts> size_t index(int i, const Ts... args){ */
    /* const int size = sizeof...(args); */
    /* int argarray[size] = {args...}; */
    /*   Indices& inds = *(new Indices(ndims())); */
    /*   const size_t M = this->ndims(); */
    /*   inds[0] = i;  */
    /*   for(size_t n = 1; n < M; n++) { */
    /* 	inds[n] = argarray[n];  */
    /*   } */
    /*   size_t k = this->index(inds); */
    /*   return k; */
    /* } */

    template <typename... U>
    typename std::enable_if<std::conjunction<std::is_convertible<U,size_t>...>::value, size_t>::type index(const U... args) {

      const size_t size = sizeof...(args);
      size_t argarray[size] = {  std::make_unsigned<int>::type(args)... };
      Indices& inds = *(new Indices(ndims()));
      const size_t NN = this->ndims();
      for (size_t n = 0; n < NN; n++) {
        inds[n] = argarray[n];
      }
      size_t k = this->indexOf(inds);
      return k;
    }

    size_t index(const std::initializer_list<size_t>& mylist) const {
      // TODO: check size
      const size_t NN = this->ndims();
      const size_t N = mylist.size();
      size_t k = 0;
      size_t n = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it, n++) {
        size_t N = (*dimensions_)[n];
        size_t j = *it;
        k = N * k + j;
      }
      return k;
    }

    // indices - This is the inverse of the above function
    // TODO: test this code
    // TODO: bounds check on k

    inline Indices& indices(const size_t k) const {
      return dimensions_->indices(k);
    }

    //**********************************************************************
    //************************** ACCESS() ***********************************
    //**********************************************************************

    // ---------------- tensor(Indices)--------------
    E& operator()(const Indices& inds) {
      size_t k = this->indexOf(inds);
      return (*this)[k];
    }
    const E operator()(const Indices& inds) const {
      size_t k = this->indexOf(inds);
      return (*this)[k];
    }

    // ---------------- tensor(i,j,...)--------------


    template <typename... U>
    typename std::enable_if<std::conjunction<std::is_convertible<U,size_t>...>::value, E&>::type operator()(const U... args) {

      // const int size = sizeof...(args);
      // int argarray[size] = {args...};
      size_t k = this->index(args...);

      return (*this)[k];
    }
    template <typename... U>
    typename std::enable_if<std::conjunction<std::is_convertible<U,size_t>...>::value, const E>::type operator()(const U... args) const {
      return (*this)(args...);
    }

    // ---------------- tensor({i,j,...})--------------
    E& operator()(const std::initializer_list<size_t>& mylist) {
      size_t k = this->index(mylist);
      return (*this)[k];
    }
    const E operator()(const std::initializer_list<size_t>& mylist) const {
      size_t k = this->index(mylist);
      return (*this)[k];
    }

    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to MArrayExpRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // ----------------- tensor = e ----------------
    MultiArray<E, R, D, M>&
      operator=(const E e) {
      for (size_t i = size(); i--;)
        data_[i] = e;
      return *this;
    }

    // ----------------- tensor = d ----------------
    template <class T = E>
    typename std::enable_if<!std::is_same<T, D>::value, MultiArray<T, R, D, M>&>::type operator=(const D& d) {

      for (size_t i = 0; i < deepsize(); i++) {
        data_.dat(i) = d;
      }
      return *this;
    }

    // ----------------- tensor = C++11 init list
    MultiArray<E, R, D, M>& operator=(const NestedInitializerList<E, R>& mylist) {
      // MOUT << "operator=: ";
      // TLDISP(mylist);
      int i = 0;
      Dimensions dims = NestedInitializerListDef<E, R>::dims(mylist);
      resize(dims);
      NestedInitializerListDef<E, R>::compute(*this, mylist, i);
      return *this;
    }

    // ----------------- tensor = MultiArray<E,R,D,M> ----------------
    template <int R1>
    MultiArray<E, R, D, M>&
      operator=(const MultiArray<E, R1, D, M>& x) {
      // TODO: issue warning
      // TRDISP(x);
      resize(x.dims());
      for (size_t i = size(); i--;) {
        data_[i] = x[i]; // Inlined expression
      }
      return *this;
    }

    // ----------------- tensor = MArrayExpR<X,E,D,M,R> ----------------
    template <class X>
    MultiArray<E, R, D, M>&
      operator=(const MArrayExpR<X, E, D, M, R>& x) {

      if constexpr (M <= 1) {
        resize(x.dims());
        for (size_t i = 0; i < size(); i++) {
          (*this)[i] = x[i];
        }
      }
      else {
        resize(x.deepdims());
        for (size_t i = 0; i < deepsize(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }

    //*********************************************************
    //                   1D assignment
    //********************************************************

    // ------------- tensor = array[] ----------------

    MultiArray<E, R, D, M>&
      operator=(const E array1[]) {
      for (size_t i = 0; i < size(); i++) {
        (*this)[i] = array1[i];
      }
      return *this;
    }

    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    MultiArray<E, R, D, M>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      for (size_t i = size(); i--;) {
        data_[i] = mathq::roundzero(data_[i], tolerance);
      }
      return *this;
    }

    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template <typename T = D>
    typename std::enable_if<is_complex<T>{}, MultiArray<T>&>::type conj() {
      for (size_t i = size(); i--;) {
        data_[i] = std::conj(data_[i]);
      }
      return *this;
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MultiArray";
      s += StyledString::get(ANGLE1).get();
      E d;
      s += getTypeName(d);
      if (R != 0) {
        s += StyledString::get(COMMA).get();
        s += "R=";
        s += num2string(R);
      }
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      return "";
    }
#endif

    std::ostream& send(std::ostream& stream, size_t& n, const Dimensions& dim) const {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      //      MDISP(n,dim);
      const int delta = this->ndims() - dim.ndims();
      if (delta == 0) {
        stream << std::endl;
      }
      std::string indent = "";
      for (size_t j = 0; j < delta; j++) {
        indent += "  ";
      }
      stream << indent << style.apply("{");

      if (dim.ndims() > 1) {
        stream << std::endl;
      }
      if (dim.ndims() > 0) {
        Dimensions newdim(dim);
        newdim.erase(newdim.begin());
        for (size_t j = 0; j < dim[0]; j++) {
          if (dim.ndims() > 1) {
            Dimensions newdim(dim);
            newdim.erase(newdim.begin());
            this->send(stream, n, newdim);
            if (j < dim[0] - 1) {
              stream << style.apply(",") << std::endl;
            }
          }
          else {
            dispval_strm(stream, (*this)[n++]);
            if (j < dim[0] - 1) {
              stream << style.apply(", ");
            }
          }
        }
      }
      if (dim.ndims() == 1) {
        stream << style.apply("}");
      }
      else if (dim.ndims() == this->ndims()) {
        stream << std::endl
          << indent << style.apply("}");
      }
      else {
        stream << std::endl
          << indent << style.apply("}");
      }
      return stream;
    }

    // stream << operator

    // TODO: implement format

    friend std::ostream& operator<<(std::ostream& stream, const MultiArray<E, R, D, M>& t) {
      using namespace display;
      size_t n = 0;
      t.send(stream, n, t.dims());
      return stream;
    }

    // template <class D>
    friend inline std::istream& operator>>(const std::string s, MultiArray<E, R, D, M>& x) {
      std::istringstream st(s);
      return (st >> x);
    }

    // stream >> operator
    // TODO: implement

    friend std::istream& operator>>(std::istream& stream, MultiArray<E, R, D, M>& x) {
      return stream;
    }

    // --------------------- FRIENDS ---------------------
  };

}; // namespace mathq

#endif
