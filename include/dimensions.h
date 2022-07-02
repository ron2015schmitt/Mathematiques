#ifndef MATHQ__DIMENSIONS_H
#define MATHQ__DIMENSIONS_H



namespace mathq {



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


    constexpr static size_t   rank() noexcept {
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
    const size_t& operator[](const size_t   n) const {
      return derived()[n];
    }

    size_t   index(const mathq::Indices& inds) const {
      const size_t   M = this->rank();
      size_t   k = 0;
      for (size_t n = 0; n < M; n++) {
        size_t   N = (*this)[n];
        size_t   j = inds[n];
        k = N*k + j;
      }
      return k;
    }


    inline mathq::Indices& indices(const size_t   k) const {
      mathq::Indices& myinds = *(new mathq::Indices(rank()));
      size_t   prev = k;
      // This loop must go in reverse order.  Do NOT change.
      for (size_t n = rank()-1; n > 0; n--) {
        size_t   N = (*this)[n];
        size_t   temp = prev/N;
        myinds[n] = prev - N*temp;
        prev = temp;
      }
      if (rank()>0) {
        myinds[0] = prev;
      }
      return myinds;
    }


    size_t   size() const {
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
      size_t   ii = 0;
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


  template <size_t rank1, typename T1, size_t   rank2, typename T2>
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

    constexpr static size_t   rank_value = sizeof...(ints);
    constexpr static std::array<size_t, rank_value> data = { (static_cast<size_t>(ints))... };
    const static size_t   numElements = mathq::compile_time_product(data);

    constexpr static size_t   rank() noexcept {
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
    const size_t& operator[](const size_t   n) const {
      size_t   k = n;
      if (k < 0) {
        k += rank();
      }
      return data[k];
    }

    size_t   size() const {
      return numElements;
    }

    inline std::string classname() const {
      using namespace display;
      std::string s = "FixedDims";
      s += StyledString::get(ANGLE1).get();
      for (size_t ii = 0; ii < rank(); ii++) {
        if (ii>0)  s += StyledString::get(COMMA).get();
        size_t   value = data[ii];
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

    constexpr static size_t   rank_value = 0;
    const static size_t   numElements = 0;

    constexpr static size_t   rank() noexcept {
      return rank_value;
    }
    constexpr static bool is_dynamic() noexcept {
      return false;
    }

    // --- instance ---

    // Default constructor

    explicit NullDims() {
    }

    size_t   size() const {
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

    constexpr static size_t   rank_value = rank_;

    constexpr static size_t   rank() noexcept {
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

    template<typename...T, size_t   DUMMY = 0, mathq::EnableIf<(DUMMY == 0) && (sizeof...(T) == rank_) && (std::conjunction<std::is_integral<T>...>::value)> = 0>
    DynamicDims(T... dynamic_dims) {
      data = { (static_cast<size_t>(dynamic_dims))... };
    }

    template<typename T>
    DynamicDims(const Dimensions<rank_, T>& dims2) {
      *this = dims2;
    }

    DynamicDims(const std::initializer_list<size_t>& list) {
      // const size_t   N = list.size();
      size_t   i = 0;
      typename std::initializer_list<size_t>::iterator it;
      for (it = list.begin(); it != list.end(); ++it) {
        (*this)[i++] = *it;
      }
    }

    DynamicDims(const std::list<size_t>& mylist) {
      // const size_t   N = mylist.size();
      size_t   i = 0;
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
    // std::enable_if<is_dynamic(), size_t&> operator[](const size_t   n) {
    size_t& operator[](const size_t   n) {
      size_t   k = n;
      if (k < 0) {
        k += rank();
      }
      return data[k];
    }

    // read
    const size_t& operator[](const size_t   n) const {
      size_t   k = n;
      if (k < 0) {
        k += rank();
      }
      return data[k];
    }


    size_t   size() const {
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

    size_t   rank() const {
      return dimensions.rank();
    }

    NextDims& element_dims() {
      return nextDimensions;
    }
    const NextDims& element_dims() const {
      return nextDimensions;
    }


    size_t   depth() const {
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

    size_t   rank() const {
      return dimensions.rank();
    }

    size_t   depth() const {
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






};
#endif
