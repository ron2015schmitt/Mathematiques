#ifndef MATHQ__TENSOR_H
#define MATHQ__TENSOR_H 1

namespace mathq {

  /********************************************************************
   * Tensor<E>      -- Tensor of 0 dimension (scalar)
   *                   E  = type for elements
   * Tensor<E,NDIM> -- Tensor of NDIM dimension
   *                   NDIM = number of dimensions (0=scalar,1=vector,2=matrix,etc)
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
    Tensor : public TensorRW<Tensor<E, R, D, M>, E, D, M, R> {
  public:
    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight

    typedef Tensor<E, R, D, M> XType;
    typedef E EType;
    typedef D DType;
    typedef typename FundamentalType<D>::Type FType;

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

    explicit Tensor<E, R, D, M>() {
      std::vector<size_type> dv(R);
      resize(new Dimensions(dv));
      constructorHelper();
    }

    // --------------------- constant=0 CONSTRUCTOR ---------------------

    explicit Tensor<E, R, D, M>(const Dimensions& dims) {
      resize(dims);
      constructorHelper();
    }

    // --------------------- constant E CONSTRUCTOR ---------------------

    explicit Tensor<E, R, D, M>(const Dimensions& dims, const E& e) {
      resize(dims);
      constructorHelper();
      *this = e;
    }

    // --------------------- constant E CONSTRUCTOR ---------------------

    template <size_t M1 = M, EnableIf<(M1 > 0)> = 0>

    explicit Tensor<E, R, D, M>(const Dimensions& dims, const D d) {
      resize(dims);
      constructorHelper();
      *this = d;
    }

    // ************* C++11 initializer_list CONSTRUCTOR---------------------
    Tensor<E, R, D, M>(const NestedInitializerList<E, R>& mylist) {
      *this = mylist;
      constructorHelper();
    }

    // ************* Expression CONSTRUCTOR---------------------

    template <class X>
    Tensor<E, R, D, M>(const TensorR<X, E, D, M, R>& x) {
      *this = x;
      constructorHelper();
    }

    // --------------------- constructorHelper() --------------------

    void constructorHelper() {
    }

    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Tensor<E, R, D, M>() {
      // remove from directory
    }

    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    inline size_type size(void) const {
      return data_.size();
    }
    size_type ndims(void) const {
      return dimensions_->ndims();
    }
    Dimensions dims(void) const {
      return *dimensions_;
    }
    bool isExpression(void) const {
      return false;
    }
    Tensors getEnum() const {
      return T_TENSOR;
    }

    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    size_type tdims(void) const {
      return dims();
    }

    inline size_type depth(void) const {
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
    inline size_type elsize(void) const {
      if constexpr (M < 2) {
        return 1;
      }
      else {
        const size_type Nelements = this->size();
        if (Nelements == 0) {
          return 0;
        }
        else {
          return data_[0].size();
        }
      }
    }

    // the deep size of an element: the total number of numbers in an element
    inline size_type eldeepsize(void) const {
      if constexpr (M < 2) {
        return 1;
      }
      else {
        const size_type Nelements = this->size();
        if (Nelements == 0) {
          return 0;
        }
        else {
          return data_[0].deepsize();
        }
      }
    }

    // the total number of numbers in this data structure
    size_type deepsize(void) const {
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

    Tensor& resize(const Dimensions& dims_in) {
      Dimensions dims = dims_in;
      while (dims.rank() < R) {
        dims.push_back(0);
      }
      dimensions_ = new Dimensions(dims);
      data_.resize(dimensions_->datasize());
      return *this;
    }

    Tensor& resize(const Dimensions* dims_in) {
      return resize(*dims_in);
    }

    // TODO: should just pass an index and make deepdims const

    Tensor<E, R, D, M>& resize(const std::vector<Dimensions>& deepdims_in) {
      std::vector<Dimensions> deepdims(deepdims_in);
      Dimensions newdims = deepdims[0];
      resize(newdims);
      if constexpr (M > 1) {
        deepdims.erase(deepdims.begin());
        for (index_type i = 0; i < size(); i++) {
          std::vector<Dimensions> ddims(deepdims);
          data_[i].resize(ddims);
        }
      }
      return *this;
    }

    //**********************************************************************
    //*********************  Accesss to Internal valarray ******************
    //**********************************************************************

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [deepsize()] and note return type

    // "read/write"
    D& dat(const index_type n) {
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
    const D& dat(const index_type n) const {
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
      // printf("Tensor.dat(Indices)\n");
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
      // printf("Tensor.dat(Indices) const\n");
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
      const index_type depth = dinds.size();
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
      const index_type depth = dinds.size();
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
    E& operator[](const index_type n) {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }

    // read
    const E& operator[](const index_type n) const {
      int k = n;
      if (k < 0) {
        k += size();
      }
      return data_[k];
    }

    //**********************************************************************
    //*******Tensor-style Element Access: A(i,j,k,...) *********************
    //**********************************************************************

    index_type indexOf(const Indices& inds) const {
      return dimensions_->index(inds);
    }

    /* template<typename... Ts> index_type index(int i, const Ts... args){ */
    /* const int size = sizeof...(args); */
    /* int argarray[size] = {args...}; */
    /*   Indices& inds = *(new Indices(ndims())); */
    /*   const index_type M = this->ndims(); */
    /*   inds[0] = i;  */
    /*   for(index_type n = 1; n < M; n++) { */
    /* 	inds[n] = argarray[n];  */
    /*   } */
    /*   index_type k = this->index(inds); */
    /*   return k; */
    /* } */

    template <typename... U>
    typename std::enable_if<(std::is_same<U, index_type>::value && ...), index_type>::type index(const U... args) {

      const int size = sizeof...(args);
      int argarray[size] = { args... };
      Indices& inds = *(new Indices(ndims()));
      const index_type NN = this->ndims();
      for (index_type n = 0; n < NN; n++) {
        inds[n] = argarray[n];
      }
      index_type k = this->indexOf(inds);
      return k;
    }

    index_type index(const std::initializer_list<size_type>& mylist) const {
      // TODO: check size
      const index_type NN = this->ndims();
      const size_type N = mylist.size();
      index_type k = 0;
      index_type n = 0;
      typename std::initializer_list<size_type>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it, n++) {
        size_type N = (*dimensions_)[n];
        index_type j = *it;
        k = N * k + j;
      }
      return k;
    }

    // indices - This is the inverse of the above function
    // TODO: test this code
    // TODO: bounds check on k

    inline Indices& indices(const index_type k) const {
      return dimensions_->indices(k);
    }

    //**********************************************************************
    //************************** ACCESS() ***********************************
    //**********************************************************************

    // ---------------- tensor(Indices)--------------
    E& operator()(const Indices& inds) {
      index_type k = this->indexOf(inds);
      return (*this)[k];
    }
    const E operator()(const Indices& inds) const {
      index_type k = this->indexOf(inds);
      return (*this)[k];
    }

    // ---------------- tensor(i,j,...)--------------

    template <typename... U>
    typename std::enable_if<(std::is_same<U, index_type>::value && ...), E&>::type operator()(const U... args) {

      // const int size = sizeof...(args);
      // int argarray[size] = {args...};
      index_type k = this->index(args...);

      return (*this)[k];
    }
    template <typename... U>
    typename std::enable_if<(std::is_same<U, index_type>::value && ...), const E>::type operator()(const U... args) const {
      return (*this)(args...);
    }

    // ---------------- tensor({i,j,...})--------------
    E& operator()(const std::initializer_list<size_type>& mylist) {
      index_type k = this->index(mylist);
      return (*this)[k];
    }
    const E operator()(const std::initializer_list<size_type>& mylist) const {
      index_type k = this->index(mylist);
      return (*this)[k];
    }

    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to TensorRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // ----------------- tensor = e ----------------
    Tensor<E, R, D, M>&
      operator=(const E e) {
      for (index_type i = size(); i--;)
        data_[i] = e;
      return *this;
    }

    // ----------------- tensor = d ----------------
    template <class T = E>
    typename std::enable_if<!std::is_same<T, D>::value, Tensor<T, R, D, M>&>::type operator=(const D& d) {

      for (index_type i = 0; i < deepsize(); i++) {
        data_.dat(i) = d;
      }
      return *this;
    }

    // ----------------- tensor = C++11 init list
    Tensor<E, R, D, M>& operator=(const NestedInitializerList<E, R>& mylist) {
      // MOUT << "operator=: ";
      // TLDISP(mylist);
      int i = 0;
      Dimensions dims = NestedInitializerListDef<E, R>::dims(mylist);
      resize(dims);
      NestedInitializerListDef<E, R>::compute(*this, mylist, i);
      return *this;
    }

    // ----------------- tensor = Tensor<E,R,D,M> ----------------
    template <int R1>
    Tensor<E, R, D, M>&
      operator=(const Tensor<E, R1, D, M>& x) {
      // TODO: issue warning
      // TRDISP(x);
      resize(x.dims());
      for (index_type i = size(); i--;) {
        data_[i] = x[i]; // Inlined expression
      }
      return *this;
    }

    // ----------------- tensor = TensorR<X,E,D,M,R> ----------------
    template <class X>
    Tensor<E, R, D, M>&
      operator=(const TensorR<X, E, D, M, R>& x) {

      if constexpr (M <= 1) {
        resize(x.dims());
        for (index_type i = 0; i < size(); i++) {
          (*this)[i] = x[i];
        }
      }
      else {
        resize(x.deepdims());
        for (index_type i = 0; i < deepsize(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }

    //*********************************************************
    //                   1D assignment
    //********************************************************

    // ------------- tensor = array[] ----------------

    Tensor<E, R, D, M>&
      operator=(const E array1[]) {
      for (index_type i = 0; i < size(); i++) {
        (*this)[i] = array1[i];
      }
      return *this;
    }

    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Tensor<E, R, D, M>& roundzero(FType tolerance = Functions<FType>::tolerance) {
      for (index_type i = size(); i--;) {
        data_[i] = mathq::roundzero(data_[i], tolerance);
      }
      return *this;
    }

    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template <typename T = D>
    typename std::enable_if<is_complex<T>{}, Tensor<T>&>::type conj() {
      for (index_type i = size(); i--;) {
        data_[i] = std::conj(data_[i]);
      }
      return *this;
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "Tensor";
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

    std::ostream& send(std::ostream& stream, index_type& n, const Dimensions& dim) const {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      //      MDISP(n,dim);
      const int delta = this->ndims() - dim.ndims();
      if (delta == 0) {
        stream << std::endl;
      }
      std::string indent = "";
      for (index_type j = 0; j < delta; j++) {
        indent += "  ";
      }
      stream << indent << style.apply("{");

      if (dim.ndims() > 1) {
        stream << std::endl;
      }
      if (dim.ndims() > 0) {
        Dimensions newdim(dim);
        newdim.erase(newdim.begin());
        for (index_type j = 0; j < dim[0]; j++) {
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

    friend std::ostream& operator<<(std::ostream& stream, const Tensor<E, R, D, M>& t) {
      using namespace display;
      index_type n = 0;
      t.send(stream, n, t.dims());
      return stream;
    }

    // template <class D>
    friend inline std::istream& operator>>(const std::string s, Tensor<E, R, D, M>& x) {
      std::istringstream st(s);
      return (st >> x);
    }

    // stream >> operator
    // TODO: implement

    friend std::istream& operator>>(std::istream& stream, Tensor<E, R, D, M>& x) {
      return stream;
    }

    // --------------------- FRIENDS ---------------------
  };

}; // namespace mathq

#endif
