#ifndef MATHQ__VECTOR_CONSTANT
#define MATHQ__VECTOR_CONSTANT 1

/********************************************************************
 * Vector_Constant<Element, dim_ints...>
 *
 * every element has the same value
 *
 * This is the specialization of MultiArray_Constant_Constant for rank=1.
 ********************************************************************
 */


namespace mathq {

  template <typename Element, size_t... dim_ints>
  class MultiArray_Constant<Element, 1, dim_ints...> :

    public SpecialData<Element, 1, dim_ints...>,

    public ExpressionRW<
    MultiArray_Constant<Element, 1, dim_ints...>,  // Derived
    Element,  // Element
    typename NumberTrait<Element>::Type, // Num
    1 + NumberTrait<Element>::depth(),  // depth
    1  // rank
    > {

  public:


    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static bool isNotExpression = true;
    constexpr static size_t rank_value = 1;
    constexpr static std::array<size_t, rank_value> static_dims_array = { dim_ints... };
    constexpr static size_t N0 = std::get<0>(static_dims_array);
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = (sizeof...(dim_ints) == 0);
    constexpr static size_t compile_time_size = calc_size<rank_value, N0>();

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Type = MultiArray_Constant<Element, rank_value, dim_ints...>;
    using ConcreteType = Type;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using ParentDataType = SpecialData<Element, rank_value, dim_ints...>;
    using ParentType = ExpressionRW<
      ConcreteType,  // Derived
      Element,  // Element
      NumberType, // Num
      depth_value,  // depth
      rank_value  // rank
    >;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;
    using MyArrayType = typename ArrayTypeTrait<Element, N0>::Type;

    template <typename NewElement>
    using Type_ReplaceElement = Vector<NewElement, dim_ints...>;

    //**********************************************************************
    // OBJECT DATA 
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    //
    //**********************************************************************

    Element value;
  public:

    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************


    // -------------------  default  --------------------
    MultiArray_Constant() {
    }

    // --------------------- copy constructor --------------------
    MultiArray_Constant(const Type& var) {
      *this = var;
    }


    //--------------------- EXPRESSION CONSTRUCTOR --------------------
    template <class Derived>
    MultiArray_Constant(const ExpressionR<Derived, Element, NumberType, depth_value, rank_value>& x) {
      if constexpr (is_dynamic_value) {
        this->resize(x.size());
      }
      *this = x;
    }


    //**********************************************************************
    //                    CONSTRUCTORS: FIXED size  
    //**********************************************************************

    // --------------------- FIXED SIZE: from dynamic size --------------------
    template<bool enabled = !is_dynamic_value> requires (enabled)
      explicit MultiArray_Constant(const Vector<Element>& var) {
      *this = var;
    }

    // --------------------- FIXED SIZE: set all elements to same value   ---------------------

    template<bool enabled = !is_dynamic_value> requires (enabled)
      explicit MultiArray_Constant(const Element val) {
      *this = val;
    }

    // --------------------- FIXED SIZE: set all bottom elements to same value   ---------------------

    template<bool enabled = !is_dynamic_value> requires (enabled && (depth_value > 1) && (!std::is_same<Element, NumberType>::value))
      explicit MultiArray_Constant(const NumberType val) {
      *this = val;
    }

    //**********************************************************************
    //                    CONSTRUCTORS: Dynamic size  
    //**********************************************************************

    // --------------------- copy constructor --------------------
    template<size_t NE2, bool enabled = is_dynamic_value> requires (enabled)
      MultiArray_Constant(const Vector<Element, NE2>& var) {
      resize(var.size());
      *this = var;
    }

    // --------------------- DYNAMIC SIZE: set size from int  ---------------------
    // need condition otherwise floats can be converted
    // can't have is_unsigned because 0 and positive ints are of type `int` by default.
    template<typename T> requires (is_dynamic_value && (std::is_integral<T>::value))
      explicit MultiArray_Constant(const T N) {
      resize(N);
    }

    // --------------------- DYNAMIC SIZE: set size from Dimensions  ---------------------

    template<bool enabled = is_dynamic_value> requires (enabled)
      explicit MultiArray_Constant(const Dimensions& dims) {
      // TRDISP(dims);
      this->resize(dims);
    }

    // --------------------- DYNAMIC SIZE: set size from RecursiveDimensions  ---------------------

    template<size_t dim_depth> requires (is_dynamic_value && (dim_depth <= depth_value))
      explicit MultiArray_Constant(const RecursiveDimensions& recursive_dims) {
      // TRDISP(recursive_dims);
      this->resize(recursive_dims);
    }



    // --------------------- DYNAMIC SIZE: set size = N and set all to same value  ---------------------

    template<bool enabled = is_dynamic_value> requires (enabled)
      explicit MultiArray_Constant(const size_t N, const Element val) {
      resize(N);
      *this = val;
    }

    // --------------------- DYNAMIC SIZE: set size from Dimensions  ---------------------

    template<bool enabled = is_dynamic_value> requires (enabled)
      explicit MultiArray_Constant(const Dimensions& dims, const Element val) {
      // TRDISP(dims);
      this->resize(dims);
      *this = val;
    }

    //**********************************************************************
    //                             DESTRUCTOR 
    //**********************************************************************

    ~MultiArray_Constant() {
    }


    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

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
      if constexpr (is_dynamic_value) {
        return ParentDataType::N0;
      }
      else {
        return N0;
      }
    }

    inline size_t actual_size(void) const {
      return 1;
    }

    // // the total number of numbers in this data structure
    size_t total_size(void) const {
      if constexpr (depth_value<2) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }

    // the size of each element
    inline size_t element_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        if (size() > 0) {
          return value.size();
        }
        else {
          Element& x = *(new Element);
          return x.size();
        }
      }
    }

    // the total number of numbers in an element
    inline size_t el_total_size(void) const {
      if constexpr (depth_value<2) {
        return 1;
      }
      else {
        if (size() > 0) {
          return value.total_size();
        }
        else {
          Element& x = *(new Element);
          return x.total_size();
        }
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    Dimensions& dims(void) const {
      return *(new Dimensions({ this->size() }));
    }

    inline std::array<size_t, rank_value> dims_array(void) const {
      if constexpr (is_dynamic_value) {
        return *(new std::array<size_t, rank_value>{ this->size() });
      }
      else {
        return static_dims_array;
      }
    }


    ElementDimensionsType& element_dims(void) const {
      if constexpr (depth_value>1) {
        if (this->size()>0) {
          return value.dims();
        }
        else {
          Element& x = *(new Element);
          return x.dims();
        }
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
        if (size() > 0) {
          value.recurse_dims(parent_rdims, depth_index);
        }
        else {
          Element& x = *(new Element);
          x.recurse_dims(parent_rdims, depth_index);
        }
      }
      return *this;
    }


    //**********************************************************************
    //                          Resize
    //**********************************************************************

    Type& resize(const size_t N) {
      if constexpr (is_dynamic_value) {
        if (N != this->size()) {
          ParentDataType::N0 = N;
        }
      }
      return *this;
    }

    Type& resize(const Dimensions& new_dims) {
      return resize(new_dims[0]);
    }

    // new_rdims.size() <= depth_value
    Type& resize(const RecursiveDimensions& new_rdims) {
      return recurse_resize(new_rdims);
    }

    // helper functions
    Type& recurse_resize(const RecursiveDimensions& parent_rdims, size_t di = 0) {
      size_t depth_index = di;
      size_t resize_depth = parent_rdims.size();
      const size_t newSize = parent_rdims[depth_index++][0];
      if constexpr (is_dynamic_value) {
        resize(newSize);
      }
      if constexpr (depth_value > 1) {
        if (depth_index < resize_depth) {
          value.recurse_resize(parent_rdims, depth_index);
        }
      }
      return *this;
    }



    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- data_obj() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& data_obj() {
      return value;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      if constexpr (is_dynamic_value) {
        // valarray<Element>
        return &(value);
      }
      else {
        // array<Element>
        return value.data();
      }
    }

    //**********************************************************************
    //                              v(n) - tensor access
    //**********************************************************************

    // "read/write"
    Element& operator()(const size_t n) {
      return value;
    }

    // "read only"
    const Element& operator()(const size_t n) const {
      return value;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // "read/write"
    NumberType& dat(const size_t n) {
      using namespace::display;
      if constexpr (depth_value < 2) {
        return value;
      }
      else {
        const int Ndeep = this->el_total_size();
        // const int j = n / Ndeep;
        const int k = n % Ndeep;
        return value.dat(k);
      }
    }

    // read
    const NumberType& dat(const size_t n)  const {
      using namespace::display;
      if constexpr (depth_value < 2) {
        return value;
      }
      else {
        const int Ndeep = this->el_total_size();
        // const int j = n / Ndeep;
        const int k = n % Ndeep;
        return value.dat(k);
      }
    }


    //**********************************************************************
    //************* Array-style Element Access: v[n] ***********************
    //**********************************************************************

    // "read/write"
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
      Element& operator[](const T n) {
      return value;
    }

    // read
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
      const Element& operator[](const T n)  const {
      return value;
    }

    // NOTE: if you feed literals, the following will be called, unless you use the `u` suffix, eg `10000u`
    // "read/write"
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
      Element& operator[](const T n) {
      return value;
    }

    // read
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
      const Element& operator[](const T n)  const {
      return value;
    }


    //**********************************************************************
    //************************** v[Indices] ***********************************
    //**********************************************************************


    // "read/write"
    Element& operator[](const Indices& inds) {
      return value;
    }

    // "read only"
    const Element& operator[](const Indices& inds)  const {
      return value;
    }

    // -------------------------------------------------------------
    //                        [DeepIndices] 
    // -------------------------------------------------------------

    // "read/write"
    NumberType& operator[](const DeepIndices& dinds) {
      const size_t mydepth = dinds.size();
      size_t n = dinds[mydepth - depth_value][0];

      if constexpr (depth_value > 1) {
        return (*this)[n][dinds];
      }
      else {
        return (*this)[n];
      }
    }

    // "read"
    const NumberType& operator[](const DeepIndices& dinds) const {
      const size_t mydepth = dinds.size();
      size_t n = dinds[mydepth - depth_value][0];

      if constexpr (depth_value > 1) {
        return (*this)[n][dinds];
      }
      else {
        return (*this)[n];
      }
    }


    //**********************************************************************
    //                          subset: v[Vector]      
    //**********************************************************************

    // Accessing a SET of values using a vector of ints

    ExpressionRW_Subset<Element> operator[](const Vector<size_t>& ii) {
      return ExpressionRW_Subset<Element>(*this, ii);
    }
    const ExpressionRW_Subset<Element> operator[](const Vector<size_t>& ii) const {
      return ExpressionRW_Subset<Element>(*this, ii);
    }


    //**********************************************************************
    //                              V[mask]
    //**********************************************************************


    // Accessing a SET of values using a MASK

    ExpressionRW_Submask<Element> operator[](const Vector<bool>& mask) {
      return  ExpressionRW_Submask<Element>(*this, mask);
    }
    const ExpressionRW_Submask<Element> operator[](const Vector<bool>& mask)  const {
      return  ExpressionRW_Submask<Element>(*this, mask);
    }


    //Accessing a SET of values using a list

    ExpressionRW_Subset<Element> operator[](const std::initializer_list<size_t>& list) {
      return  ExpressionRW_Subset<Element>(*this, list);
    }
    const ExpressionRW_Subset<Element> operator[](const std::initializer_list<size_t>& list) const {
      return  ExpressionRW_Subset<Element>(*this, list);
    }


    //**********************************************************************
    //                              v[slice]
    //**********************************************************************

    // Accessing a slice of values
    template <typename T>
    ExpressionRW_Subset<Element> operator[](const slc<T>& slice) {
      Vector<size_t>& ii = *(new Vector<size_t>(size(), slice));
      return ExpressionRW_Subset<Element>(*this, ii);
    }

    template <typename T>
    const ExpressionRW_Subset<Element> operator[](const slc<T>& slice) const {
      Vector<size_t>& ii = *(new Vector<size_t>(size(), slice));
      return ExpressionRW_Subset<Element>(*this, ii);
    }



    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to ExpressionRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    template<typename T> requires (std::is_convertible<T, Element>::value)
      Type& operator=(const T& e) {
      value = e;
      return *this;
    }

    // set bottom elements to same value
    template <class T = Element>
    typename std::enable_if<!std::is_same<T, NumberType>::value, Vector<T, N0>& >::type operator=(const NumberType& d) {
      for (size_t i = 0; i < total_size(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }




    // ------------------------ Vector = Vector----------------

    template <int NE2>
    Type& operator=(const Vector<Element, NE2>& v) {
      return (*this = +v);  // should call expression assigment
      return *this;
    }


    // // ------------------------ Vector = ExpressionR ----------------

    template <class X>
    bool verify(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {
      Element temp = x[0];
      for (size_t i = 0; i < size(); i++) {
        if (x[i] != temp) {
          OUTPUT("ERROR: attept to set MultiArray_Constant from non-compatible expression.");
          TRDISP(*this);
          TRDISP(x);
          return false;
        }
      }
      return true;
    }


    template <class X>
    Type& operator=(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {

      if (!verify(x)) return *this;

      if constexpr (depth_value <= 1) {
        if constexpr (is_dynamic_value) {
          resize(x.size());
        }
        value = x[0];
      }
      else {
        resize(x.recursive_dims());
        for (size_t i = 0; i < total_size(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }










    //**********************************************************************
    //***************** in-place modification*******************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------

    Type& roundzero(SimpleNumberType tolerance = Functions<SimpleNumberType>::tolerance) {
      value = mathq::roundzero(value, tolerance);
      return *this;
    }


    //----------------- .conj() ---------------------------

    template<typename T = NumberType> EnableMethodIf<is_complex<T>::value, Vector<T>&>
    conj() {
      using std::conj;
      value = conj(value);
      return *this;
    }

    // .sort()
    //         sorts in place and returns the permuted indices

    Vector<size_t>& sort() {

      const size_t N = size();
      Vector<size_t>& ivec = *(new Vector<size_t>(N));

      if (N==0)
        return ivec;

      for (size_t i = 0; i < N; i++) {
        ivec(i) = i;
      }

      return ivec;

    }


    // .quniq() -- finds consequeutive duplicates
    //         removes all duplicates
    //         returns a new vector with the preserved indices
    template<typename T = size_t> EnableMethodIf<is_dynamic_value, Vector<T>& >
    quniq() {

      const size_t N = size();

      if (N==0)
        return *(new Vector<size_t>());

      std::queue<Pair<Element> > unique;

      Pair<Element> prevpair(0, value);
      unique.push(prevpair);

      const size_t Nnew = unique.size();
      Vector<size_t>& indexvec = *(new Vector<size_t>(Nnew));
      resize(Nnew);
      for (size_t i = 0; i < Nnew; i++) {
        Pair<Element> mypair = unique.front();
        unique.pop();
        indexvec(i) = mypair.index;
        value = mypair.data;
      }

      return indexvec;
    }


    // .uniq()
    //         removes all duplicates
    //         returns a new vector with the preserved indices
    template<typename T = size_t> EnableMethodIf<is_dynamic_value, Vector<T>& >
    uniq() {
      return quniq();
    }


    Type& reverse() {
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
      std::string s = "Vector_Constant";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      if constexpr (!is_dynamic_value) {
        s += StyledString::get(COMMA).get();
        s += "N0=";
        s += std::to_string(N0);
      }
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif


    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Type& v) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      const size_t N = FormatDataVector::max_elements_per_line;
      size_t k = 0;
      for (size_t ii = 0; ii < v.size(); ii++, k++) {
        if (k >= N) {
          stream << style.apply(FormatDataVector::string_endofline);
          k = 0;
        }
        dispval_strm(stream, v(ii));
        if (ii < v.size()-1) {
          stream << style.apply(FormatDataVector::string_delimeter);
        }
      }
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }





    //**********************************************************************
    //                      CONVERSION OPERATORS 
    // use to dynamic_cast a Vector to another type of container
    //**********************************************************************


  };




};


#endif 

