#ifndef MATHQ__TENSORS_H
#define MATHQ__TENSORS_H



namespace mathq {

  //-------------------------------------------------------------------
  //                  Classes etc defined in this file
  //-------------------------------------------------------------------

  class VectorofPtrs;
  template <class DAT> class Pair;
  class Indices;
  enum MultiArrays : unsigned int;
  enum MultiArrayOrExpression : unsigned int;



  // **************************************************************************
  // * std::vector related functions
  // ************************************************************************** 

  template <typename Number, int NN> class ArrayTypeTrait {
  public:
    typedef std::array<Number, NN> Type;
  };

  template <typename Number> class ArrayTypeTrait<Number, 0> {
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



  // ***************************************************************************
  // Dimensions classes
  // ***************************************************************************


  //
  // Dimensions<rank_, Derived> - virtual class
  //

  template<size_t rank_, typename Derived>
  class Dimensions {
  public:
    typedef Dimensions<rank_, Derived> Type;
    typedef Derived DerivedType;


    constexpr static size_t rank() noexcept {
      return rank_;
    }
    constexpr static bool is_dynamic() noexcept {
      return Derived::is_dynamic;
    }


    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const Derived& derived() const {
      return static_cast<const Derived&>(*this);
    }

    // read
    const size_t& operator[](const size_t n) const {
      return derived()[n];
    }

    size_t index(const mathq::Indices& inds) const {
      const size_t M = this->rank();
      size_t k = 0;
      for (size_t n = 0; n < M; n++) {
        size_t N = (*this)[n];
        size_t j = inds[n];
        k = N*k + j;
      }
      return k;
    }


    inline mathq::Indices& indices(const size_t k) const {
      mathq::Indices& myinds = *(new mathq::Indices(rank()));
      size_t prev = k;
      // This loop must go in reverse order.  Do NOT change.
      for (size_t n = rank()-1; n > 0; n--) {
        size_t N = (*this)[n];
        size_t temp = prev/N;
        myinds[n] = prev - N*temp;
        prev = temp;
      }
      if (rank()>0) {
        myinds[0] = prev;
      }
      return myinds;
    }


    size_t size() const {
      return derived().size();
    }

    std::vector<size_t>& reduce() const {
      std::vector<size_t>& v = *(new std::vector<size_t>{});
      for (size_t i = 0; i < this->rank(); i++) {
        if ((*this)[i] != 1) {
          v.push_back((*this)[i]);
        }
      }
      return v;
    }

    template <size_t rank2, typename T2>
    bool equiv(const Dimensions<rank2, T2>& dims2) const {
      return (this->reduce() == dims2.reduce());
    }

    DynamicDims<rank_>& getReverse() const {
      DynamicDims<rank_>& dims2 = *(new DynamicDims<rank_>{});
      // reverse order
      size_t ii = 0;
      for (size_t k = this->rank()-1; k >= 0; k--) {
        dims2[ii++] = (*this)[k];
      }
      return dims2;
    }

    explicit operator DynamicDims<rank_>() const {
      DynamicDims<rank_>& dims2 = *(new DynamicDims<rank_>{});
      // reverse order
      for (size_t k = 0; k < rank(); k++) {
        dims2[k] = (*this)[k];
      }
      return dims2;
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "Dimensions";
      s += StyledString::get(ANGLE1).get();
      s += num2string(rank_);
      s += StyledString::get(COMMA).get();
      s += derived().classname();
      s += StyledString::get(ANGLE2).get();
      return s;
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const Type& dims2) {
      using namespace display;
      stream << "{";
      for (size_t ii = 0; ii < dims2.rank(); ii++) {
        if (ii>0)  stream << ", ";
        dispval_strm(stream, dims2[ii]);
      }
      stream << "}";
      return stream;
    }


  };


  template <size_t rank1, typename T1, size_t rank2, typename T2>
  inline bool equiv(const Dimensions<rank1, T1>& dims1, const Dimensions<rank2, T2>& dims2) {
    return dims1.equiv(dims2);
  }


  // 
  // FixedDims<ints...>
  // 


  template<size_t... ints>
  class FixedDims : public Dimensions<sizeof...(ints), FixedDims<ints...>> {
  public:
    typedef FixedDims<ints...> Type;
    typedef Dimensions<sizeof...(ints), Type> ParentType;

    constexpr static size_t rank_value = sizeof...(ints);
    constexpr static std::array<size_t, rank_value> data = { (static_cast<size_t>(ints))... };
    const static size_t numElements = mathq::compile_time_product(data);

    constexpr static size_t rank() noexcept {
      return rank_value;
    }
    constexpr static bool is_dynamic() noexcept {
      return false;
    }

    // --- instance ---

    // Default constructor

    explicit FixedDims() {
    }

    // read
    const size_t& operator[](const size_t n) const {
      size_t k = n;
      if (k < 0) {
        k += rank();
      }
      return data[k];
    }

    size_t size() const {
      return numElements;
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "FixedDims";
      s += StyledString::get(ANGLE1).get();
      for (size_t ii = 0; ii < rank(); ii++) {
        if (ii>0)  s += StyledString::get(COMMA).get();
        size_t value = data[ii];
        s += num2string(value);
      }
      s += StyledString::get(ANGLE2).get();
      return s;
    }

  };


  // 
  // NullDims
  // 


  class NullDims : public Dimensions<0, NullDims> {
  public:
    typedef NullDims Type;
    typedef Dimensions<0, Type> ParentType;

    constexpr static size_t rank_value = 0;
    const static size_t numElements = 0;

    constexpr static size_t rank() noexcept {
      return rank_value;
    }
    constexpr static bool is_dynamic() noexcept {
      return false;
    }

    // --- instance ---

    // Default constructor

    explicit NullDims() {
    }

    size_t size() const {
      return numElements;
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "NullDims";
      return s;
    }
  };




  // 
  // DynamicDims<rank_>
  // 

  template<size_t rank_>
  class DynamicDims : public Dimensions<rank_, DynamicDims<rank_>> {
  public:
    typedef DynamicDims<rank_> Type;
    typedef Dimensions<rank_, Type> ParentType;

    constexpr static size_t rank_value = rank_;

    constexpr static size_t rank() noexcept {
      return size;
    }
    constexpr static bool is_dynamic() noexcept {
      return true;
    }


    // --- instance ---

    std::array<size_t, rank_> data;

    // Default constructor: all zeroes

    explicit DynamicDims() {
      for (size_t n = 0; n < rank(); n++) {
        data[n] = 0;
      }
    }

    // Dynamic constructor

    template<typename...T, size_t DUMMY = 0, mathq::EnableIf<(DUMMY == 0) && (sizeof...(T) == rank_) && (std::conjunction<std::is_integral<T>...>::value)> = 0>
    DynamicDims(T... dynamic_dims) {
      data = { (static_cast<size_t>(dynamic_dims))... };
    }

    template<typename T>
    DynamicDims(const Dimensions<rank_, T>& dims2) {
      *this = dims2;
    }

    DynamicDims(const std::initializer_list<size_t>& list) {
      // const size_t N = list.size();
      size_t i = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = list.begin(); it != list.end(); ++it) {
        (*this)[i++] = *it;
      }
    }

    DynamicDims(const std::list<size_t>& mylist) {
      // const size_t N = mylist.size();
      size_t i = 0;
      for (auto it = mylist.begin(); it != mylist.end(); ++it) {
        (*this)[i++] = *it;
      }
    }

    DynamicDims(const std::vector<size_t>& vec) {
      for (int k = 0; k < vec.size(); k++) {
        (*this)[k] = vec[k];
      }
    }

    template<typename T>
    DynamicDims(const mathq::Vector<T, rank()>& vec) {
      for (int k = 0; k < vec.size(); k++) {
        (*this)[k] = vec[k];
      }
    }

    template<typename T>
    DynamicDims(const mathq::Vector<T, 0>& vec) {
      for (int k = 0; k < vec.size(); k++) {
        (*this)[k] = vec[k];
      }
    }


    // "read/write"
    // std::enable_if<is_dynamic(), size_t&> operator[](const size_t n) {
    size_t& operator[](const size_t n) {
      size_t k = n;
      if (k < 0) {
        k += rank();
      }
      return data[k];
    }

    // read
    const size_t& operator[](const size_t n) const {
      size_t k = n;
      if (k < 0) {
        k += rank();
      }
      return data[k];
    }


    size_t size() const {
      // returns 1 if rank==0
      return std::accumulate(data.begin(), data.end(), 1, std::multiplies<size_t>());
    }

    template<typename T>
    DynamicDims<rank_>& operator=(const Dimensions<rank_, T>& dims2) {
      for (size_t k = 0; k < rank(); k++) {
        (*this)[k] = dims2[k];
      }
      return *this;
    }


    inline std::string classname() const {
      using namespace display;
      std::string s = "DynamicDims";
      s += StyledString::get(ANGLE1).get();
      s += num2string(rank_);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

  };






  // 
  // NestedDims<Dims,NextDims>
  // 


  template<typename Dims, typename NextDims>
  class NestedDims : public Dims {
  public:
    typedef NestedDims<Dims, NextDims> Type;
    typedef Dims DimsType;
    typedef NextDims NextDimsType;
    constexpr static bool hasNext = true;

    Dims dimensions;
    NextDims nextDimensions;

    NestedDims() : dimensions(*(new DimsType)), nextDimensions(*(new NextDimsType)) {
    }
    NestedDims(Dims dims_) : dimensions(dims_), nextDimensions(*(new NextDimsType)) {
    }
    NestedDims(Dims dims_, NextDims nextDims_) : dimensions(dims_), nextDimensions(nextDims_) {
    }

    Dims& dims() {
      return dimensions;
    }
    const Dims& dims() const {
      return dimensions;
    }

    size_t rank() const {
      return dimensions.rank();
    }

    NextDims& element_dims() {
      return nextDimensions;
    }
    const NextDims& element_dims() const {
      return nextDimensions;
    }


    size_t depth() const {
      return 1 + nextDimensions.depth();
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "NestedDims";
      s += StyledString::get(ANGLE1).get();
      s += dimensions.classname();
      s += StyledString::get(COMMA).get();
      s += nextDimensions.classname();
      s += StyledString::get(ANGLE2).get();
      return s;
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const Type& dims2) {
      using namespace display;
      dispval_strm(stream, dims2.dimensions);
      stream << ", ";
      dispval_strm(stream, dims2.nextDimensions);
      return stream;
    }


  };


  // 
  // NestedDims<Dims>
  // 

  template<typename Dims>
  class NestedDims<Dims, void> : public Dims {
  public:
    typedef NestedDims<Dims, void> Type;
    typedef Dims DimsType;
    typedef void NextDimsType;
    constexpr static bool hasNext = false;

    Dims dimensions;

    NestedDims() : dimensions(*(new DimsType)) {
    }
    NestedDims(Dims dims_) : dimensions(dims_) {
    }

    size_t rank() const {
      return dimensions.rank();
    }

    size_t depth() const {
      return 1;
    }

    Dims& dims() {
      return dimensions;
    }
    const Dims& dims() const {
      return dimensions;
    }
    inline std::string classname() const {
      using namespace display;
      std::string s = "NestedDims";
      s += StyledString::get(ANGLE1).get();
      s += dimensions.classname();
      s += StyledString::get(ANGLE2).get();
      return s;
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const Type& dims2) {
      using namespace display;
      dispval_strm(stream, dims2.dimensions);
      return stream;
    }

  };


  // -------------------------------------------------------------------
  //
  // Deepindices - class to full indices of nested MultiArrays
  // -------------------------------------------------------------------
  template <typename NestedDims>
  class DeepIndices : public NestedDims {
  public:

    DeepIndices() : deepdims_(deepdims) {

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
    template <int rank>
    static void compute(MultiArray<Element, rank>& t, const type& list, int& i) {

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

    template <int rank>
    static void compute(MultiArray<Element, rank>& t, const type& item, int& i) {
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

    using Type = typename InversionType<X, NullType>::Type Type;
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





  template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
  bool dimequiv(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
    return equiv(x1.dims(), x2.dims());
  }

  template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
  bool common(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
    // PRINTF3("in common");
    return common(x1.getAddresses(), x2.getAddresses());
  }



  // -------------------------------------------------------------------
  //
  // printMultiArrayExpression
  //
  // Basically this is the vistor design pattern.
  // -------------------------------------------------------------------



  template <class X, class Element, typename Number, int depth, int rank>
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

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class MArrayExpR {
  public:

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    typedef Materialize<Element, Number> ConcreteType;

    using ElementType = Element;
    using NumberType = Number;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using DimensionsType = DimensionsT;
    using ElementDimensionsType = typename std::conditional< (depth_value == 1), NullDims, Element::DimensionsType>::type;
    using NestedDimensionsType = NestedDimensions<DimensionsType, ElementDimensionsType>;

    using MyArrayType = Element;

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank;
    constexpr static size_t depth_value = depth;
    constexpr static size_t template_dimensions_value = DimensionsType;

    // the size of an expression cannot be changed
    constexpr static bool is_dynamic() noexcept {
      return false;
    }

    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const  Derived& derived() const {
      return static_cast<const Derived&>(*this);
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

    size_t rank(void) const {
      return derived().rank();
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
    size_t depth(void) const {
      return derived().depth();
    }
    Dimensions element_dims(void) const {
      return derived().element_dims();
    }

    size_t element_size(void) const {
      return derived().element_size();
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

    friend std::ostream& operator<<(std::ostream& stream, const MArrayExpR<Derived, Element, Number, depth, rank>& te) {
      const Derived& td = te.derived();
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


  template <class Derived, class Element, typename Number, size_t depth, size_t rank, class DimensionsT> class
    MArrayExpRW : public MArrayExpR<MArrayExpRW<Derived, Element, Number, depth, rank, DimensionsT>, Element, Number, depth, rank, DimensionsT> {
  public:
    typedef Materialize<Element, Number, depth, rank> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;
    constexpr static int rank_value = rank;
    constexpr static int depth_value = depth;

    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const Derived& derived() const {
      return static_cast<const Derived&>(*this);
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

    size_t rank(void) const {
      return derived().rank();
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
    size_t depth(void) const {
      return derived().depth();
    }
    Dimensions element_dims(void) const {
      return derived().element_dims();
    }
    size_t element_size(void) const {
      return derived().element_size();
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

    friend std::ostream& operator<<(std::ostream& stream, const MArrayExpRW<Derived, Element, Number, depth, rank>& te) {
      const Derived& td = te.derived();
      if (td.isExpression()) {
        return printMultiArrayExpression(stream, te);
      }
      else {
        stream << te.derived();
        return stream;
      }
    }


    // Assign to constant value
    Derived& equals(const Element e) {
      for (size_t i = 0; i<size(); i++)
        (*this)[i] = e;
      return derived();
    }



    // assign to vector or expression
    template <class Y>
    Derived& equals(const MArrayExpR<Y, Element, Number, depth, rank>& rhs) {

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






};
#endif
