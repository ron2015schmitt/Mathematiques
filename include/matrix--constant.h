#ifndef MATHQ__MATRIX_CONSTANT
#define MATHQ__MATRIX_CONSTANT 1

  /********************************************************************
   * Matrix_Constant<Element, dim_ints...> 
   * 
   * every element has the same value
   *
   * This is the specialization of MultiArray_Constant for rank=2.
   ********************************************************************
   */

namespace mathq {

  template <typename Element, size_t... dim_ints>
  class MultiArray_Constant<Element, 2, dim_ints...> : 
    public SpecialData<Element, 2, dim_ints...>, 
    public ExpressionRW<
      Matrix<Element, dim_ints...>,  // Derived
      Element,  // Element
      typename NumberTrait<Element>::Type, // Number
      1 + NumberTrait<Element>::depth(),  // depth
      2  // rank
    > {  
  public:


    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 2;
    constexpr static std::array<size_t, rank_value> static_dims_array = { dim_ints... };
    constexpr static size_t N0 = std::get<0>(static_dims_array);
    constexpr static size_t N1 = std::get<1>(static_dims_array);
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = ( sizeof...(dim_ints) == 0 );
    constexpr static size_t compile_time_size = calc_size<rank_value, N0, N1>();

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Type = MultiArray_Constant<Element, rank_value, dim_ints...>;
    using ConcreteType = Matrix<Element, dim_ints...>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using ParentDataType = SpecialData<Element, rank_value, dim_ints...>;
    using ParentType = ExpressionRW<
      ConcreteType,  // Derived
      Element,  // Element
      NumberType, // Number
      depth_value,  // depth
      rank_value  // rank
    >;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;
    using DeepDimensionsType = RecursiveDimensions;

    using MyArrayType = typename ArrayTypeTrait<Element, compile_time_size>::Type;
    using InitializerType = typename MakeInitializer<Element, rank_value >::Type;


    //**********************************************************************
    //                      Object Data
    //**********************************************************************
    Element value;


  public:

    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************

    // --------------------- default CONSTRUCTOR ---------------------

    MultiArray_Constant() {
      if constexpr (is_dynamic_value) {
        resize(0,0);
      }
    }

    // --------------------- copy constructor --------------------
    MultiArray_Constant(const Type& var) {
      if constexpr (is_dynamic_value) {
        resize(var.dims());
      }
      *this = var;
    }


    //--------------------- EXPRESSION CONSTRUCTOR --------------------
    template <class Derived>
    MultiArray_Constant(const ExpressionR<Derived, Element, NumberType, depth_value, rank_value>& x) {
      if constexpr (is_dynamic_value) {
        resize(0,0);
      }
      *this = x;
    }


    //**********************************************************************
    //                    CONSTRUCTORS: FIXED dimensions  
    //**********************************************************************

    // --------------------- FIXED SIZE: from dynamic MultiArray_Constant --------------------

    template<bool enable = !is_dynamic_value> requires (enable)
    explicit MultiArray_Constant(const MultiArray_Constant<Element, rank_value>& var) {
      *this = var;
    }

    // --------------------- FIXED SIZE: set all to same value   ---------------------

    template<bool enable = !is_dynamic_value> requires (enable)
    explicit MultiArray_Constant(const Element val) {
      *this = val;
    }

    // --------------------- FIXED SIZE: set all bottom Elements to same value   ---------------------

    template<bool enable = !is_dynamic_value> requires ((enable) && (depth_value > 1) && (!std::is_same<Element, NumberType>::value) )
    explicit MultiArray_Constant(const NumberType val) {
      *this = val;
    }

    //**********************************************************************
    //                    CONSTRUCTORS: DYNAMIC dimensions  
    //**********************************************************************

    // --------------------- dynamic MultiArray_Constant --------------------

    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray_Constant(const MultiArray_Constant<Element, rank_value> var) {
      this->resize(var.dims());
      *this = var;
    }

    // --------------------- DYNAMIC SIZE: set size from ints  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    MultiArray_Constant(const size_t Nrows, const size_t Ncols) {
      resize(Nrows, Ncols);
    }

    // --------------------- DYNAMIC SIZE: set size from ints and values from constant  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    MultiArray_Constant(const size_t Nrows, const size_t Ncols, const Element& val) {
      resize(Nrows, Ncols);
      *this = val;
    }

    // --------------------- DYNAMIC SIZE: set size from Dimensions  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray_Constant(const Dimensions& dims) {
      // TRDISP(dims);
      this->resize(dims);
    }

    // --------------------- DYNAMIC SIZE: set size from RecursiveDimensions  ---------------------
    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray_Constant(const RecursiveDimensions& recursive_dims) {
      // TRDISP(recursive_dims);
      this->resize(recursive_dims);
    }


    // --------------------- DYNAMIC SIZE: set dims and set all to same value  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray_Constant(const Dimensions& dims, const Element& val) {
      this->resize(dims);
      *this = val;
    }


    //**********************************************************************
    //                             DESTRUCTOR 
    //**********************************************************************

    ~MultiArray_Constant() {
      // remove from directory
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
      return Nrows()*Ncols();
    }

    // // the total number of numbers in this data structure
    size_t total_size(void) const {
      if constexpr (depth_value <= 1) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }

    // the size of each element
    inline size_t element_size(void) const {
      if constexpr (depth_value <= 1) {
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
      if constexpr (depth_value <= 1) {
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


    inline size_t Nrows(void) const {
      if constexpr (is_dynamic_value) {
        return ParentDataType::N0;
      } else {
        return N0;
      }
    }
    inline size_t Ncols(void) const {
      if constexpr (is_dynamic_value) {
        return ParentDataType::N1;
      } else {
        return N1;
      }
    }


    // defined later since Dimensions is dependent on MultiArray_Constant
    Dimensions& dims(void) const {
      if constexpr (is_dynamic_value) {
        return *(new Dimensions({ ParentDataType::N0, ParentDataType::N1 }));
      } else {
        return *(new Dimensions(static_dims_array));
      }
    }

    inline std::array<size_t, rank_value> dims_array(void) const {
      if constexpr (is_dynamic_value) {
        return *(new std::array<size_t, rank_value>{ ParentDataType::N0, ParentDataType::N1 });
      } else {
        return static_dims_array;
      }
    }

    ElementDimensionsType& element_dims(void) const {
      if constexpr (depth_value > 1) {
        if (this->size() > 0) {
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
    //
    // resize / reshape is not allowed unless fixed-dimensions 
    //**********************************************************************

    template <typename... U> requires ( (is_dynamic_value) ) 
    Type& resize(const size_t Nrows_new, const size_t Ncols_new) {
      if ( (ParentDataType::N0 != Nrows_new) ||(ParentDataType::N1 != Ncols_new) ) {
        ParentDataType::N0 = Nrows_new;
        ParentDataType::N1 = Ncols_new;
      }
      return *this;
    }

    

    template <bool enabled = is_dynamic_value> requires (enabled)
    Type& resize(const Dimensions& new_dims) {
      return resize(new_dims[0], new_dims[1]);
    }


    Type& resize(const InitializerType& var) {
      auto mysizes = InitializerTrait< InitializerType >::get_size_array(var);
      resize(Dimensions(mysizes));
      return *this;
    }



    // new_rdims.size() <= depth_value
    Type& resize(const RecursiveDimensions& new_rdims) {
      return recurse_resize(new_rdims);
    }

    // helper functions
    Type& recurse_resize(const RecursiveDimensions& parent_rdims, size_t di = 0) {
      size_t depth_index = di;
      size_t resize_depth = parent_rdims.size();
      const Dimensions new_dims = parent_rdims[depth_index++];
      if constexpr (is_dynamic_value) {
        resize(new_dims);
      }
      if constexpr (depth_value > 1) {
        if (depth_index < resize_depth) {
          for (size_t ii = 0; ii < size(); ii++) {
            ParentDataType::data_[ii].recurse_resize(parent_rdims, depth_index);
          }
        }
      }
      return *this;
    }

    //**********************************************************************
    //   this casted as SpecialData
    //**********************************************************************
    ParentDataType& asSpecialData() {
      return *((ParentDataType*)(this));
    }

    //**********************************************************************
    //********************* Direct access to ParentDataType::data_  ***********************************
    //**********************************************************************

    // -------------------- data_obj() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& data_obj() {
      return value;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      // MutltiArrays are always wrap avalarray<Element>
      return &(value);
    }


    //**********************************************************************
    //*******indexing  *********************
    //**********************************************************************

    mathq::Indices& indices(const size_t k) const {
      mathq::Indices& myinds = *(new mathq::Indices(k, dims()));
      return myinds;
    }

    size_t index(const mathq::Indices& inds) const {
      return inds.index(dims());
    }

    // compiler actually will convert an init list and find the above method
    size_t index(const std::initializer_list<size_t>& mylist) const {
      return index(*(new mathq::Indices(mylist)));
    }

    template <typename... U>
    typename std::enable_if<(std::conjunction<std::is_integral<U>...>::value) && (sizeof...(U) == rank_value), size_t>::type 
    index(const U... args) {
      std::array<size_t,rank_value> arr { std::make_unsigned<int>::type(args)... };
      return index(*(new mathq::Indices(arr)));
    }

    //**********************************************************************
    //******* A(i,j,k,...) *********************
    //**********************************************************************

    Element& operator()(const size_t i1, const size_t i2) {
      return value;
    }

    const Element& operator()(const size_t i1, const size_t i2) const {
      return value;
    }

    // negative indexing 

    template <typename... U>
    Element& operator()(const U... args) requires (std::conjunction< std::is_integral<U>...>::value && std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value) )
    {
      return value;
    }

    template <typename... U>
    const Element& operator()(const U... args) const 
    requires (std::conjunction< std::is_integral<U>...>::value && std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value) )
    {
      return value;
    }


    //**********************************************************************
    //******************** BOTTOM ELEMENT ACCESS: x.dat(n) *****************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // "read/write"
    NumberType& dat(const size_t n) {
      using namespace ::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
      if constexpr (depth_value <= 1) {
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
    const NumberType& dat(const size_t n) const {
      using namespace ::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
      if constexpr (depth_value <= 1) {
        return value;
      }
      else {
        const int Ndeep = this->el_total_size();
        // const int j = n / Ndeep;
        const int k = n % Ndeep;
        return value.dat(k);
      }
    }


    // **********************************************************************
    // ************* Array-style Element Access: x[n] ***********************
    // **********************************************************************

    // "read/write"
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      return value;
    }

    // read
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      // OUTPUT("[] 2");
      return value;
    }

    // "read/write"
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      // OUTPUT("[] 3");
      return value;
    }

    // read
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      // OUTPUT("[] 4");
      return value;
    }

    //**********************************************************************
    //************************** A[Indices] ***********************************
    //**********************************************************************

    // ---------------- A[Indices]--------------
    Element& operator[](const Indices& inds) {
      return value;
    }
    const Element& operator[](const Indices& inds) const {
      return value;
    }

    // -------------------------------------------------------------
    //                        A[DeepIndices] 
    // -------------------------------------------------------------

    // "read/write"
    NumberType& operator[](const DeepIndices& dinds) {
      const size_t mydepth = dinds.size();
      Indices inds = dinds[mydepth - depth_value];

      if constexpr (depth_value > 1) {
        return (*this)[inds][dinds];
      }
      else {
        return (*this)[inds];
      }
    }

    // "read"
    const NumberType& operator[](const DeepIndices& dinds) const {
      const size_t mydepth = dinds.size();
      Indices inds = dinds[mydepth - depth_value];

      if constexpr (depth_value > 1) {
        return (*this)[inds][dinds];
      }
      else {
        return (*this)[inds];
      }
    }


    //**********************************************************************
    //************************** ASSIGNMENT ********************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to ExpressionRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    template<typename T> requires ( std::is_convertible<T, Element>::value )
    Type& operator=(const T& e) {
      value = e;
      return *this;
    }

    // set bottom elements to same value
    template <class T = Element>
    typename std::enable_if<!std::is_same<T, NumberType>::value, Type& >::type 
    operator=(const NumberType& d) {
      for (size_t i = 0; i < total_size(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }




    // ------------------------ MultiArray_Constant = MultiArray_Constant<Element,NE2,NumberType,depth_value> ----------------

    template <size_t... sizes> requires (multi_array_compatibility<rank_value,rank_value,dim_ints...,sizes...>())
    Type& operator=(const MultiArray_Constant<Element, rank_value, sizes...>& v) {
      return (*this = +v);  // should call expression assigment
    }


    // ------------------------ MultiArray_Constant = ExpressionR ----------------

    template <class X>
    Type& operator=(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {
      Element temp = x[0];
      for (size_t i = 0; i < size(); i++) {
        if (x[i] != temp) {
          OUTPUT("ERROR: attept to set MultiArray_Constant from non-compatible expression.");
          TRDISP(*this);
          TRDISP(x);
        }
      }

      if constexpr (depth_value <= 1) {
        if constexpr (is_dynamic_value) {
          if (this->size() != x.size()) {
            resize(x.dims());
          }
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
    // NOTE: in-place

    Type& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      value = mathq::roundzero(value, tolerance);
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = NumberType >
    typename std::enable_if<is_complex<T>::value, Type& >::type conj() {
      value = std::conj(value);
      return *this;
    }

    // -------------------------- transpose() --------------------------------
    // In-place transpose. 
    // 1) For square matrices this operation is quick and easy.
    // 2) For non-square matrices, this changes the shape and operation is time-consuming
    //    Note: Transpose function is much quicker. only use this for when memory is critical
    Type& transpose(void) {
      const size_t Nr = Nrows();
      const size_t Nc = Ncols();
      const size_t N = size();
      const size_t Nminus1 = N-1;

      // square matrix  
      if (Nc == Nr) {
        return *this;
      }

      if constexpr (is_dynamic_value) {
        resize(Nc, Nr);
      }
      return *this;
    }

    // -------------------------- adjoint() --------------------------------

    template< typename T = NumberType >
    typename std::enable_if<is_complex<T>::value, Type& >::type adjoint() {
      this->conj();
      this->transpose();
      return *this;
    }





    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************
    inline std::string classname() const {
      return ClassName();
    }

    static inline std::string ClassName() {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      std::string s = "Matrix_Constant";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      if constexpr (!is_dynamic_value) {
        for (size_t ii = 0; ii < static_dims_array.size(); ii++) {
          if (ii == 0) {
            s += StyledString::get(COMMA).get() + " ";
          }
          else {
            s += style.apply("⨯");
          }
          s += std::to_string(static_dims_array[ii]);
        }
      }
      s += StyledString::get(ANGLE2).get();
      return s;
    }

#if MATHQ_DEBUG >= 1
    std::string expression(void) const {
      return "";
    }
#endif

    // this is recursive 
    // TODO: implement format

    std::ostream& send(std::ostream& stream, size_t& n, const Dimensions& dim) const {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      // MDISP(n,dim);
      const int delta = this->rank() - dim.rank();
      if (delta == 0) {
        stream << std::endl;
      }
      std::string indent = "";
      for (size_t j = 0; j < delta; j++) {
        indent += "  ";
      }
      stream << indent << style.apply("{");

      if (dim.rank() > 1) {
        stream << std::endl;
      }
      if (dim.rank() > 0) {
        Dimensions newdim(dim);
        newdim.erase(newdim.begin());
        for (size_t j = 0; j < dim[0]; j++) {
          if (dim.rank() > 1) {
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
      if (dim.rank() == 1) {
        stream << style.apply("}");
      }
      else if (dim.rank() == this->rank()) {
        stream << std::endl
          << indent << style.apply("}");
      }
      else {
        stream << std::endl
          << indent << style.apply("}");
      }
      return stream;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Type& t) {
      using namespace display;
      size_t n = 0;
      t.send(stream, n, t.dims());
      return stream;
    }

    // template <typename NumberType>
    friend inline std::istream& operator>>(const std::string s, Type& x) {
      std::istringstream st(s);
      return (st >> x);
    }

  };

}; // namespace mathq

#endif
