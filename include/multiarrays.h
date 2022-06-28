#ifndef MATHQ__TENSORS_H
#define MATHQ__TENSORS_H



namespace mathq {

  //-------------------------------------------------------------------
  //                  Classes etc defined in this file
  //-------------------------------------------------------------------

  class VectorofPtrs;
  template <class DAT> class Pair;
  class Dimensions;
  class Indices;
  enum MultiArrays : unsigned int;
  enum MultiArrayOrExpression : unsigned int;



  // **************************************************************************
  // * std::vector related functions
  // ************************************************************************** 

  template <class Number, int NN> class ArrayType {
  public:
    typedef std::array<Number, NN> Type;
  };

  template <class Number> class ArrayType<Number, 0> {
  public:
    typedef std::valarray<Number> Type;
  };


  // **************************************************************************
  // * std::vector related functions
  // ************************************************************************** 


  // TODO: do we need these?  move inside the class
  template <typename T>
  std::vector<T> mergeVectors(const std::vector<T> v1, const std::vector<T> v2) {
    std::vector<T> v3 = v1;
    v3.insert(v3.end(), v2.begin(), v2.end());
    return v3;
  }

  template <typename T>
  std::vector<T> createVector(const T x) {
    std::vector<T> v1;
    v1.push_back(x);
    return v1;
  }


  /**********************************************************************
   *  VectorofPtrs
   **********************************************************************
   */

  class VectorofPtrs : public std::vector<const void*> {

  public:
    typedef typename std::vector<const void*> Parent;

    VectorofPtrs() {
    }
    VectorofPtrs(const void* addr) {
      VectorofPtrs();
      this->add(addr);
    }
    VectorofPtrs(const std::vector<const void*> addrs) {
      VectorofPtrs();
      this->add(addrs);
    }

    inline void add(const void* addr) {
      this->push_back(addr);
    }

    inline void add(const VectorofPtrs& addrs) {
      this->insert(this->end(), addrs.begin(), addrs.end());
    }

    // true if this vector and another share an element in common (ie same value)

    inline bool common(const VectorofPtrs& addrs) const {
      for (size_t i = 0; i < addrs.size(); i++) {
        const void* addr = addrs[i];
        if (std::find(this->begin(), this->end(), addr) != this->end()) {
          return true;
        }
      }
      return false;
    }

    inline std::string classname() const {
      return "VectorofPtrs";
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const VectorofPtrs& vptrs) {
      using namespace display;

      stream << "{";
      for (size_t ii = 0; ii < vptrs.size(); ii++) {
        if (ii>0)  stream << ", ";
        dispval_strm(stream, vptrs[ii]);
      }
      stream << "}";

      return stream;
    }


  };

  // true if the two vectors have a value in common

  inline bool common(const VectorofPtrs& addrs1, const VectorofPtrs& addrs2) {
    return addrs1.common(addrs2);
  }

  //***********************************************************************
  //      Pair class:  each pair is (index, data)
  //                   index = int
  //                   data equals DAT
  //***********************************************************************

  // TODO: add classname() as well as << stream

  template <class DAT> class Pair {
  public:
    size_t index;
    DAT data;
    Pair(size_t index_, DAT data_) : index(index_), data(data_) {}
    Pair() : index(0), data(DAT(0)) {}
    bool operator<(const Pair<DAT>& pair2) const {
      return ((*this).data < pair2.data);
    }
    inline std::string classname() const {
      return "Pair";
    }
    inline friend std::ostream& operator<<(std::ostream& stream, const Pair<DAT>& pair) {
      using namespace display;

      stream << "(";
      stream << pair.index;
      stream << " : ";
      stream << pair.data;
      stream << ")";

      return stream;
    }
  };

  // ---------------------------------------------------------------------------
  //
  // Indices - class to hold indices to a tensor or arbitrary depth and rank(s)
  // ---------------------------------------------------------------------------



  class Indices : public std::vector<size_t> {
  private:
  public:
    typedef typename std::vector<size_t> Parent;
    typedef typename Parent::iterator Iterator;
    Indices(const Indices& inds) {
      resize(inds.size(), 0);
      for (int k = 0; k < inds.size(); k++) {
        (*this)[k] = inds[k];
      }
    }
    Indices() {
      resize(0, 0);
    }
    Indices(const size_t n) {
      resize(n, 0);
    }
    // arbitrary size. can alos use "push_back"
    Indices(const Parent& inds) {
      resize(inds.size(), 0);
      for (int k = 0; k < inds.size(); k++) {
        (*this)[k] = inds[k];
      }
    }

    // use C++11 init list for arbitrary rank
    Indices(const std::initializer_list<size_t> list) {
      const size_t N = list.size();
      resize(N, 0);
      size_t i = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = list.begin(); it != list.end(); ++it) {
        (*this)[i++] = *it;
      }
    }

    Indices(const std::list<size_t>& mylist) {
      const size_t N = mylist.size();
      resize(N, 0);
      size_t i = 0;
      std::list<size_t>::const_iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }
    }


    bool equiv(const Indices& inds) const {
      return (*this == inds);
    }

    Indices& getReverse() const {
      Indices& revinds = *(new Indices());
      for (int k = this->size()-1; k >= 0; k--) {
        revinds.push_back((*this)[k]);
      }
      return revinds;
    }


    std::string classname() const {
      return "Indices";
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const Indices& inds) {
      using namespace display;

      stream << "{";
      for (size_t ii = 0; ii < inds.size(); ii++) {
        if (ii>0)  stream << ", ";
        dispval_strm(stream, inds[ii]);
      }
      stream << "}";

      return stream;
    }


  };


  inline bool equiv(const Indices& inds1, const Indices& inds2) {
    return inds1.equiv(inds2);
  }


  // -------------------------------------------------------------------
  //
  // Dimensions - class to hold (top-level, depth=1) dimensions of a MultiArray
  // -------------------------------------------------------------------

  class Dimensions : public std::vector<size_t> {
  private:
    size_t datasize_;

  public:
    typedef typename std::vector<size_t> Parent;
    typedef typename Parent::iterator Iterator;
    typedef size_t ElementType;
    Dimensions(const Dimensions& dims) {
      resize(dims.rank(), 0);
      for (int k = 0; k < dims.rank(); k++) {
        (*this)[k] = dims[k];
      }
      calcSize();
    }
    // TODO: use parmpack or initializer_list instead, to handle any number of dimensions as input

    Dimensions() {
      resize(0, 0);
      calcSize();
    }
    Dimensions(const size_t dim1) {
      resize(1, 0);
      (*this)[0] = dim1;
      calcSize();
    }
    Dimensions(const size_t dim1, const size_t dim2) {
      resize(2, 0);
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      calcSize();
    }
    Dimensions(const size_t dim1, const size_t dim2, const size_t dim3) {
      //      MDISP3(dim1,dim2,dim3);
      resize(3, 0);
      //      DISP3(size());
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
      calcSize();
    }
    Dimensions(const size_t dim1, const size_t dim2, const size_t dim3, const size_t dim4) {
      //      MDISP3(dim1,dim2,dim3);
      resize(4, 0);
      //      DISP3(size());
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
      (*this)[3] = dim4;
      calcSize();
    }

    // C++11 init list 
    Dimensions(const std::initializer_list<size_t>& list) {
      const size_t N = list.size();
      resize(N, 0);
      size_t i = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = list.begin(); it != list.end(); ++it) {
        (*this)[i++] = *it;
      }
      calcSize();
    }


    Dimensions(const std::list<size_t>& mylist) {
      const size_t N = mylist.size();
      resize(N, 0);
      size_t i = 0;
      for (auto it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }
      calcSize();
    }

    Dimensions(const Parent& vec) {
      resize(vec.size(), 0);
      for (int k = 0; k < vec.size(); k++) {
        (*this)[k] = vec[k];
      }
      calcSize();
    }


    // return this object with size 1 dimensions removed

    Dimensions& reduce() const {
      Dimensions* v = new Dimensions();
      for (size_t i = 0; i < this->rank(); i++) {
        if ((*this)[i] != 1) {
          v->push_back((*this)[i]);
        }
      }
      return *v;
    }

    bool equiv(const Dimensions& dims) const {
      return (this->reduce() == dims.reduce());
    }

    size_t rank() const {
      return Parent::size();
    }
    size_t ndims() const {
      return Parent::size();
    }
    size_t datasize() const {
      return datasize_;
    }


    size_t index(const Indices& inds) const {
      const size_t depth = this->ndims();
      size_t k = 0;
      for (size_t n = 0; n < depth; n++) {
        size_t N = (*this)[n];
        size_t j = inds[n];
        k = N*k + j;
      }
      return k;
    }

    // convert a A[size_t] index to A[Indices]
    inline Indices& indices(const size_t k) const {
      Indices& myinds = *(new Indices(ndims()));
      if (ndims() == 0) return myinds;
      size_t prev = k;
      // This loop must go in reverse order.  Do NOT change.
      for (size_t n = ndims()-1; n > 0; n--) {
        size_t N = (*this)[n];
        size_t temp = prev/N;
        myinds[n] = prev - N*temp;
        prev = temp;
      }
      if (ndims()>0) {
        myinds[0] = prev;
      }
      return myinds;
    }


    // getTranspose() - this reverses the order of the dimensions

    Dimensions& getReverse() const {
      Dimensions* tdims = new Dimensions();
      if (ndims() == 0) return *tdims;
      // reverse order
      for (int k = this->ndims()-1; k >= 0; k--) {
        tdims->push_back((*this)[k]);
      }
      return *tdims;
    }

    Dimensions& operator=(const Dimensions& dims2) {
      resize(dims2.size(), 0);
      for (int k = 0; k < ndims(); k++) {
        (*this)[k] = dims2[k];
      }
      calcSize();
      return *this;
    }


    Iterator erase(const Iterator iterator) {
      Iterator newit = Parent::erase(iterator);
      this->calcSize();
      return newit;
    }

    void push_back(const ElementType n) {
      Parent::push_back(n);
      this->calcSize();
    }
    void pop_back() {
      Parent::pop_back();
      this->calcSize();
    }

    void calcSize() {
      datasize_ = 1;
      for (int k = 0; k < this->rank(); k++) {
        datasize_ *= (*this)[k];
      }
    }

    inline std::string classname() const {
      return "Dimensions";
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const Dimensions& dims) {
      using namespace display;
      stream << "{";
      for (size_t ii = 0; ii < dims.rank(); ii++) {
        if (ii>0)  stream << ", ";
        dispval_strm(stream, dims[ii]);
      }
      stream << "}";
      return stream;
    }
  };


  inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
    return dims1.equiv(dims2);
  }



  // -------------------------------------------------------------------
  //
  // Deepindices - class to full indices of nested MultiArrays
  // -------------------------------------------------------------------

  class DeepIndices : public std::vector<Indices> {
  private:
    std::vector<Dimensions> deepdims_;
  public:

    DeepIndices(const std::vector<Dimensions>& deepdims) : deepdims_(deepdims) {
      this->resize(deepdims.size());
      for (size_t i = 0; i < deepdims.size(); i++) {
        (*this)[i].resize(deepdims[i].size());
      }
    }


    DeepIndices& operator++(int dum) {
      const size_t N = deepdims_.size();
      size_t m = N;
      while (true) {
        if (m == 0) {
          this->clear();
          return *this;
        }
        m--;
        while ((*this)[m].size() == 0) {
          if (m == 0) {
            this->clear();
            return *this;
          }
          m--;
        }
        Dimensions& dims = deepdims_[m];
        Indices& inds = (*this)[m];
        size_t n = dims.size();
        size_t d = 0;
        size_t sz = dims[n-d-1];
        size_t ind = ++(inds[n-d-1]);
        // MDISP(m, n, d, sz, ind, inds[n-d-1]);
        while (ind >= sz) {
          inds[n-d-1] = 0;
          d++;
          if (d >= n) {
            break;
          }
          sz = dims[n-d-1];
          ind = ++(inds[n-d-1]);
        }
        if (d < n) {
          return *this;
        }
      } // while true
      return *this;  // should never get here
    }


    DeepIndices& getReverse() const {
      const size_t N = size();
      std::vector<Dimensions> rddims(N);
      for (int k = 0; k < N; k++) {
        rddims[k] = deepdims_[N-k-1];
      }
      DeepIndices& revinds = *(new DeepIndices(rddims));
      for (int k = 0; k < N; k++) {
        revinds[k] = (*this)[N-k-1];
      }
      return revinds;
    }


    inline friend std::ostream& operator<<(std::ostream& stream, const DeepIndices& dinds) {
      using namespace display;
      stream << "{";
      for (size_t ii = 0; ii < dinds.size(); ii++) {
        if (ii>0)  stream << ", ";
        dispval_strm(stream, dinds[ii]);
      }
      stream << "}";
      return stream;
    }

    std::string classname() const {
      return "DeepIndices";
    }
  };

  //*******************************************************
  //     NestedInitializerList  Type Definition
  //*******************************************************


  template<typename Element, int L>
  class NestedInitializerListDef {
  public:
    using type = std::initializer_list<
      typename NestedInitializerListDef<Element, L-1>::type
    >;
    template <class Number, int rank, int depth>
    static void compute(MultiArray<Element, rank, Number, depth>& t, const type& list, int& i) {

      for (auto nlist : list) {
        NestedInitializerListDef<Element, L-1>::compute(t, nlist, i);
      }
    }

    static Dimensions& dims(const type& list) {
      Dimensions& dims = *(new Dimensions());
      return NestedInitializerListDef::dims(list, dims);
    }
    static Dimensions& dims(const type& list, Dimensions& dims) {
      const int nl = list.size();
      dims.push_back(nl);
      if (nl==0) {
        return dims;
      }
      else {
        return NestedInitializerListDef<Element, L-1>::dims(*(list.begin()), dims);
      }
    }


  };

  template<typename Element>
  class NestedInitializerListDef<Element, 0> {
  public:
    using type = Element;

    template <class Number, int rank, int depth>
    static void compute(MultiArray<Element, rank, Number, depth>& t, const type& item, int& i) {
      //TLDISP(item);
      t[i++] = item;
    }

    static Dimensions& dims(const type& item, Dimensions& dims) {
      return dims;
    }

  };






  // Type to use NestedInitializerListDef<T,int>

  template<typename T, int T_levels>
  using NestedInitializerList =
    typename NestedInitializerListDef<T, T_levels>::type;



  // -------------------------------------------------------------------
  //
  // insideout - turn a nested set of tensors inside-out
  // -------------------------------------------------------------------


  template <class X, class Element, typename Number, int depth, int rank>
  auto& insideout(const MArrayExpRW<X, Element, Number, depth, rank>& t) {

    typedef typename InversionType<X, Null>::Type Type;
    Type* tout = new Type();
    const X& tin = t.derived();
    std::vector<Dimensions> ddims = t.deepdims();
    std::vector<Dimensions> rdims;
    // need to create the reverse dimensions
    for (int j = 0; j < ddims.size(); j++) {
      rdims.push_back(ddims[ddims.size()-j-1]);
    }
    tout->resize(rdims);

    const size_t Ndeep = tout->deepsize();

    //  flatten sizes into one vector
    std::vector<size_t> flatdims;
    for (int i = 0; i < depth; i++) {
      Dimensions dims = ddims[i];
      for (int j = 0; j < dims.size(); j++) {
        flatdims.push_back(dims[j]);
      }
    }
    //  flatten sizes into one vector
    std::vector<size_t> flatrdims;
    for (int i = 0; i < depth; i++) {
      Dimensions dims = rdims[i];
      for (int j = 0; j < dims.size(); j++) {
        flatrdims.push_back(dims[j]);
      }
    }
    std::vector<size_t> flatrinds(flatrdims.size());

    size_t mydepth = 0;
    size_t dim = 0;
    size_t index = 0;
    DeepIndices dinds(ddims);
    for (size_t i = 0; i < Ndeep; i++) {
      // set equal
      // MDISP(i, dinds, tin.dat(i), tin.dat(dinds));  // LEAVE THIS HERE BUT COMMENTED OUT!!!
      DeepIndices rinds = dinds.getReverse();
      tout->dat(rinds) = tin.dat(dinds);
      dinds++;
    }
    return *tout;
  }



  // -------------------------------------------------------------------
  //
  // MultiArrays enum - one enum for each actual MultiArray:
  //                Scalar, Vector, Matrix, etc. And then two expressions.
  //                return type of getEnum
  //
  // MultiArrayType struct - this returns the corresponding type for
  //                     a given enum, which allows to create a new
  //                     varieble that is of the same class as a variable
  //                     that was passed to the code
  //
  // NOTE: by combining this enum functionality with the dims() method,
  //       we can determine what type of tensor is returned by an expression
  //       and even create a new object of the same type!
  //       Another technique that can be used is the vistor design pattern,
  //       as described below.
  // -------------------------------------------------------------------

/// TODO: get this working or remove

  enum MultiArrayOrExpression : unsigned int { T_TENSOR_OBJ, T_TENSOR_EXP };


  enum MultiArrays : unsigned int { T_SCALAR, T_VECTOR, T_MATRIX, T_TENSOR, T_EXPRESSION_R, T_EXPRESSION_RW };





  template <class A, class B, class E1, class E2, class D1, class D2, int depth, int rank>
  bool dimequiv(const MArrayExpR<A, E1, D1, depth, rank>& x1, const MArrayExpR<B, E2, D2, depth, rank>& x2) {
    return equiv(x1.dims(), x2.dims());
  }

  template <class A, class B, class E1, class E2, class D1, class D2, int depth, int rank>
  bool common(const MArrayExpR<A, E1, D1, depth, rank>& x1, const MArrayExpR<B, E2, D2, depth, rank>& x2) {
    // PRINTF3("in common");
    return common(x1.getAddresses(), x2.getAddresses());
  }



  // -------------------------------------------------------------------
  //
  // printMultiArrayExpression
  //
  // Basically this is the vistor design pattern.
  // -------------------------------------------------------------------



  template <class X, class Element, class Number, int depth, int rank>
  std::ostream& printMultiArrayExpression(std::ostream& stream, const MArrayExpR<X, Element, Number, depth, rank>& te) {

    if constexpr (rank==0) {
      Scalar<Element> s;
      s = te;
      stream << "" +display::getTypeName(s)+" ";
      stream << s;
      return stream;
    }
    else
      if constexpr (rank==1) {
        Vector<Element> v;
        v = te;
        stream << "" +display::getTypeName(v)+" ";
        stream << v;
        return stream;
      }
      else
        if constexpr (rank==2) {
          Matrix<Element> m;
          m = te;
          stream << "" +display::getTypeName(m)+" ";
          stream << m;
          return stream;
        }
        else
          if constexpr (rank>=3) {
            MultiArray<Element, rank> t;
            t = te;
            stream << "" +display::getTypeName(t)+" ";
            stream << t;
            return stream;
          }
  }



  // -------------------------------------------------------------------
  //
  // MArrayExpR -- Abstract class that represents 
  //            either a tensor or a tensor expression that is "read only"
  // -------------------------------------------------------------------

  template <class X, class Element, typename Number, int depth, int rank> class
    MArrayExpR {
  public:
    typedef Materialize<Element, Number, depth, rank> XType;
    typedef Element EType;
    typedef Number DType;
    constexpr static int rank_value = rank;
    constexpr static int Mvalue = depth;

    X& derived() {
      return static_cast<X&>(*this);
    }
    const  X& derived() const {
      return static_cast<const X&>(*this);
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Number dat(const size_t i) const {
      return derived().dat(i);
    }

    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************

    const Element operator[](const size_t i) const {
      return derived()[i];
    }



    size_t size(void) const {
      return derived().size();
    }

    size_t ndims(void) const {
      return derived().ndims();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return derived().deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return derived().deepdims(parentdims);
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    MultiArrays getEnum(void) const {
      // return T_EXPRESSION_R;
      return derived().getEnum();
    }
    size_t getDepth(void) const {
      return derived().getDepth();
    }
    Dimensions eldims(void) const {
      return derived().eldims();
    }

    size_t elsize(void) const {
      return derived().elsize();
    }
    size_t eldeepsize(void) const {
      return derived().eldeepsize();
    }
    size_t deepsize(void) const {
      return derived().deepsize();
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
  }
#else
    std::string expression(void) const {
      return "";
    }
#endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
    }


    inline std::string classname() const {
      return derived().classname();
    }

    friend std::ostream& operator<<(std::ostream& stream, const MArrayExpR<X, Element, Number, depth, rank>& te) {
      const X& td = te.derived();
      if (td.isExpression()) {
        return printMultiArrayExpression(stream, te);
      }
      else {
        stream << te.derived();
        return stream;
      }
    }

};





  // -------------------------------------------------------------------
  //
  // MArrayExpRW -- Abstract class that represents 
  //             either a tensor or a tensor expression that can be
  //             both read and written
  // -------------------------------------------------------------------


  template <class X, class Element, typename Number, int depth, int rank> class
    MArrayExpRW : public MArrayExpR<MArrayExpRW<X, Element, Number, depth, rank>, Element, Number, depth, rank> {
  public:
    typedef Materialize<Element, Number, depth, rank> XType;
    typedef Element EType;
    typedef Number DType;
    constexpr static int rank_value = rank;
    constexpr static int Mvalue = depth;

    X& derived() {
      return static_cast<X&>(*this);
    }
    const X& derived() const {
      return static_cast<const X&>(*this);
    }


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Number dat(const size_t i) const {
      return derived().dat(i);
    }
    Number& dat(const size_t i) {
      return derived().dat(i);
    }

    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************
    const Element operator[](const size_t i) const {
      return derived()[i];
    }
    Element& operator[](const size_t i) {
      return derived()[i];
    }


    size_t size(void) const {
      return derived().size();
    }

    size_t ndims(void) const {
      return derived().ndims();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return derived().deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return derived().deepdims(parentdims);
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    MultiArrays getEnum(void) const {
      return derived().getEnum();
      // return T_EXPRESSION_RW;
    }
    size_t getDepth(void) const {
      return derived().getDepth();
    }
    Dimensions eldims(void) const {
      return derived().eldims();
    }
    size_t elsize(void) const {
      return derived().elsize();
    }
    size_t eldeepsize(void) const {
      return derived().eldeepsize();
    }
    size_t deepsize(void) const {
      return derived().deepsize();
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
  }
#else
    std::string expression(void) const {
      return "";
    }
#endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
    }


    std::string classname() const {
      return derived().classname();
    }

    friend std::ostream& operator<<(std::ostream& stream, const MArrayExpRW<X, Element, Number, depth, rank>& te) {
      const X& td = te.derived();
      if (td.isExpression()) {
        return printMultiArrayExpression(stream, te);
      }
      else {
        stream << te.derived();
        return stream;
      }
    }


    // Assign to constant value
    X& equals(const Element e) {
      for (size_t i = 0; i<size(); i++)
        (*this)[i] = e;
      return derived();
    }



    // assign to vector or expression
    template <class Y>
    X& equals(const MArrayExpR<Y, Element, Number, depth, rank>& rhs) {

      const size_t N = size();


      if (common(*this, rhs)) {
        // if a vector appears on both the right hand and left hand side,
        // we need to make a copy of the rhs first
        Vector<Number> y(N);

        for (size_t i = 0; i<N; i++)
          y[i] = rhs[i];
        for (size_t i = 0; i<N; i++)
          derived()[i] = y[i];
      }
      else {
        for (size_t i = 0; i<N; i++)
          derived()[i] = rhs[i];
      }
      return derived();
    }



  };





  //  template <class X, class Element, typename Number, int depth, int rank> class MultiArrayObject {
  //  };



};
#endif
