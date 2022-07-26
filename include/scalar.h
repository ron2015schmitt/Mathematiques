#ifndef MATHQ__SCALAR
#define MATHQ__SCALAR 1

  /******************************************************************************
   * Scalar<Element> == MultiArray<Element,0>
   *
   *                 Element  = type for elements
********************************************************************
 */


namespace mathq {

  template <typename Element>
  class MultiArray<Element, 0> : public ExpressionRW<
    Scalar<Element>,  // Derived
    Element,  // Element
    typename NumberTrait<Element>::Type, // Number
    1 + NumberTrait<Element>::depth(),  // depth
    0  // rank
  > {
  public:


    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 0;
    constexpr static std::array<size_t, rank_value> static_dims_array = { };
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = false;
    constexpr static size_t compile_time_size = 1;

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Type = MultiArray<Element, rank_value>;
    using ConcreteType = Scalar<Element>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using ParentType = ExpressionRW<
      ConcreteType,  // Derived
      Element,  // Element
      NumberType, // Number
      depth_value,  // depth
      rank_value  // rank
    >;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;
    using MyArrayType = Element;


    //**********************************************************************
    // OBJECT DATA 
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    //
    // size is taken from data_.size
    //**********************************************************************

  // private:
    Element data_;

  public:

//     //**********************************************************************
//     //                            CONSTRUCTORS 
//     //**********************************************************************


    // -------------------  default  --------------------
    MultiArray() {
    }

    // --------------------- copy constructor --------------------
    MultiArray(const Type& var) {
      *this = var;
    }

    // --------------------- FIXED SIZE: set all elements to same value   ---------------------

    explicit MultiArray(const Element val) {
      *this = val;
    }

    // --------------------- FIXED SIZE: set all bottom elements to same value   ---------------------

    // template<size_t depth = depth_value> requires ( (depth > 1) && (!std::is_same<Element, NumberType>::value) )
    //   explicit MultiArray(const NumberType val) {
    //   *this = val;
    // }

    //--------------------- EXPRESSION CONSTRUCTOR --------------------
    template <class Derived>
    MultiArray(const ExpressionR<Derived, Element, NumberType, depth_value, rank_value>& x) {
      if constexpr (is_dynamic_value) {
        this->resize(x.size());
      }
      *this = x;
    }


    //**********************************************************************
    //                             DESTRUCTOR 
    //**********************************************************************

    ~MultiArray() {
    }


    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return false;
    }
    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************

    size_t rank(void) const {
      return rank_value;
    }

    inline size_t depth(void) const {
      return depth_value;
    }

    inline size_t size(void) const {
      return 1;
    }

    // // the total number of numbers in this data structure
    size_t total_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        return this->el_total_size();
      }
    }

    // the size of each element
    inline size_t element_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        return data_.size();
      }
    }

    // the total number of numbers in an element
    inline size_t el_total_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        return data_.total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    Dimensions& dims(void) const {
      return *(new Dimensions());
    }

    inline std::array<size_t, rank_value> dims_array(void) const {
        return *(new std::array<size_t, rank_value>{} );
    }


    ElementDimensionsType& element_dims(void) const {
      if constexpr (depth_value > 1) {
        return data_.dims();
      }
      return *(new ElementDimensionsType{});
    }


    RecursiveDimensions& recursive_dims(void) const {
      RecursiveDimensions& rdims = *(new RecursiveDimensions(depth_value));
      this->recurse_dims(rdims, 0);
      return rdims;
    }

    const Type& recurse_dims(RecursiveDimensions& parent_rdims, const size_t di = 0) const {
      size_t depth_index = di;
      parent_rdims[depth_index++] = dims();
      if constexpr (depth_value>1) {
        data_.recurse_dims(parent_rdims, depth_index);
      }
      return *this;
    }


    //**********************************************************************
    //                          Resize
    //**********************************************************************


    // TODO: new_rdims.size() <= depth_value
    Type& resize(const RecursiveDimensions& new_rdims) {
      return recurse_resize(new_rdims);
    }

    // helper functions
    Type& recurse_resize(const RecursiveDimensions& parent_rdims, size_t di = 0) {
      size_t depth_index = di;
      size_t resize_depth = parent_rdims.size();
      const size_t newSize = parent_rdims[depth_index++];
      if constexpr (depth_value >= 1) {
        if (depth_index < resize_depth) {
          for (size_t ii = 0; ii < size(); ii++) {
            data_[ii].recurse_resize(parent_rdims, depth_index);
          }
        }
      }
      return *this;
    }



    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- dataobj() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& data_obj() {
      return data_;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      return &(data_);
    }

    //**********************************************************************
    //                              v(n) - tensor access
    //**********************************************************************

    // "read/write"
    Element& operator()() {
      return data_;
    }

    // "read only"
    const Element& operator()() const {
      return data_;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // "read/write"
    NumberType& dat(const size_t n) {
      using namespace::display;
      if constexpr (depth_value < 2) {
        return data_;
      }
      else {
        const int Ndeep = this->el_total_size();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }

    // read
    const NumberType& dat(const size_t n)  const {
      using namespace::display;
      if constexpr (depth_value < 2) {
        return data_;
      }
      else {
        const int Ndeep = this->el_total_size();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return data_[j].dat(k);
      }
    }


    //**********************************************************************
    //************* Array-style Element Access: v[n] ***********************
    //**********************************************************************

    // "read/write"
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      return data_;
    }

    // read
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      return data_;
    }

    // NOTE: if you feed literals, the following will be called, unless you use the `u` suffix, eg `10000u`
    // "read/write"
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      T m = signed_index_to_unsigned_index(n, size());
      return data_;
    }

    // read
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      T m = signed_index_to_unsigned_index(n, size());
      return data_;
    }


    //**********************************************************************
    //************************** v[Indices] ***********************************
    //**********************************************************************


    // "read/write"
    Element& operator[](const Indices& inds) {
      return data_;
    }

    // "read only"
    const Element& operator[](const Indices& inds)  const {
      return data_;
    }

//     // -------------------------------------------------------------
//     //                        [DeepIndices] 
//     // -------------------------------------------------------------

//     // "read/write"
//     NumberType& operator[](const DeepIndices& dinds) {
//       const size_t mydepth = dinds.size();
//       size_t n = dinds[mydepth - depth_value][0];

//       if constexpr (depth_value > 1) {
//         return (*this)[n][dinds];
//       }
//       else {
//         return (*this)[n];
//       }
//     }

//     // "read"
//     const NumberType& operator[](const DeepIndices& dinds) const {
//       const size_t mydepth = dinds.size();
//       size_t n = dinds[mydepth - depth_value][0];

//       if constexpr (depth_value > 1) {
//         return (*this)[n][dinds];
//       }
//       else {
//         return (*this)[n];
//       }
//     }




    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to ExpressionRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    Type& operator=(const Element& e) {
      data_ = e;
      return *this;
    }

    // set bottom elements to same value
    template <class T = Element>
    typename std::enable_if<!std::is_same<T, NumberType>::value, Type& >::type operator=(const NumberType& d) {
      for (size_t i = 0; i < total_size(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }




//     // ------------------------ Vector = Vector----------------

//     template <int NE2>
//     Type& operator=(const Vector<Element, NE2>& v) {
//       if constexpr (depth_value <= 1) {
//         if constexpr (is_dynamic_value) {
//           if (this->size() != v.size()) {
//             resize(v.size());
//           }
//         }
//         for (size_t i = 0; i < size(); i++) {
//           (*this)[i] = v[i];
//         }
//       }
//       else {
//         if constexpr (is_dynamic_value) {
//           resize(v.recursive_dims());
//         }
//         for (size_t i = 0; i < total_size(); i++) {
//           this->dat(i) = v.dat(i);
//         }
//       }
//       return *this;
//     }


    // // ------------------------ Vector = ExpressionR ----------------

    template <class X>
    Type& operator=(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {
      if constexpr (depth_value <= 1) {
        data_ = x[0];
      }
      else {
        for (size_t i = 0; i < total_size(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }




    // ------------------------ Vector = initializer_list ----------------

    Type& operator=(const std::initializer_list<Element>& mylist) {
      size_t k = 0;
      typename std::initializer_list<Element>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); ++it, k++) {
        data_[k] = *it;
      }
      return *this;
    }


    // ------------------------ Vector = std::vector ----------------

    Type& operator=(const std::vector<Element>& vstd) {
      data_ = vstd[0];
      return *this;
    }


    // ------------------------ Vector = std::array ----------------

    template <size_t N>
    Type& operator=(const std::array<NumberType, N>& varray) {
      data_ = varray[0];
      return *this;
    }


    // ------------------------ Vector = std::valarray ----------------

    Type& operator=(const std::valarray<Element>& varray) {
      data_ = varray[0];
      return *this;
    }








    //**********************************************************************
    //***************** in-place modification********************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------

    Type& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      data_ = mathq::roundzero(data_, tolerance);
    }


    //----------------- .conj() ---------------------------

    template<typename T = NumberType> requires(is_complex<T>::value)
    Type& conj() {
      using std::conj;
      data_ = conj(data_);
      return *this;
    }

    // .sort()
    //         sorts in place and returns the permuted indices

    Scalar<size_t>& sort() {
      return *(new Scalar<size_t>(0));
    }


    // .quniq()
    //         removes adjacent duplicates
    Scalar<size_t>& quniq() {
      return *(new Scalar<size_t>(0));
    }


    // .uniq()
    //         removes all duplicates
    Scalar<size_t>& uniq() {
      return *(new Scalar<size_t>(0));
    }


    Type& reverse() {
      return *this;
    }


    // .cumsum() -- cumulative sum

    Type& cumsum() {
      return *this;
    }

    // .cumprod()  --  cumulative product

    Type& cumprod() {
      return *this;
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    // instance classname() method 

    inline std::string classname() const {
      return ClassName();
    }

    // static ClassName() method 

    static inline std::string ClassName() {
      using namespace display;
      std::string s = "Scalar";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif


    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Type& x) {
      using namespace display;
      dispval_strm(stream, x());
      return stream;
    }


    friend inline std::istream& operator>>(const std::string s, Type& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    //**********************************************************************
    //                      CONVERSION OPERATORS 
    // use to dynamic_cast a Vector to another type of container
    //**********************************************************************

    operator Element* () const {
      Element* ptr = new Element{data_};
      return ptr;
    }


  };




};


#endif 

