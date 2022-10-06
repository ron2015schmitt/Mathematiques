#ifndef MATHQ__TYPE_DEFS
#define MATHQ__TYPE_DEFS



namespace mathq {



  template <typename T>
  class Realize_Type {
  public:
    using Type = T;
  };

  template <IsReadableExpression T>
  class Realize_Type<T> {
  public:
    using Type = T::ConcreteType;
  };


  template <typename T>
  T& realize(T&& x) {
    return x;
  }

  template <IsReadableExpression T>
  auto& realize(const T& expression) {
    using ConcreteType = typename T::ConcreteType;
    ConcreteType& temp = *(new ConcreteType);
    temp.resize(expression.recursive_dims());
    temp = expression;
    return temp;
  }

  template <typename... Ts> requires (sizeof...(Ts) > 1)
    auto& realize(Ts&&... args) {
    auto& data = *(new std::tuple<typename Realize_Type<Ts>::Type...>{ args... });
    return data;
  }




  // ***************************************************************************
  // * expr
  // ***************************************************************************

  template <typename... Ts>
  class expr {
  public:
    using Type = std::tuple<typename Realize_Type<Ts>::Type...>;
    const Type data;
  public:
    expr(const Ts&... args) : data({ args... }) {
    }
    ~expr() {
    }



    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "expr";
      s += StyledString::get(ANGLE1).get();
      s += StyledString::get(ANGLE2).get();
      return s;
    }

    inline friend std::ostream& operator<<(std::ostream& stream, const expr<Ts...>& var) {
      using namespace display;
      dispval_strm(stream, var.data);
      return stream;
    }


  };



  // **************************************************************************
  // * std::vector related functions
  // ************************************************************************** 


  // TODO: do we need these?  move inside the MAExpR class?
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
  // replace with std:: pair type

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










};
#endif
