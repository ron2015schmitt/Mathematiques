#ifndef MATHQ__MATRIX
#define MATHQ__MATRIX 1

namespace mathq {

  template <typename Element, size_t... dim_ints>
  class MultiArray<Element, 2, dim_ints...> : 
    public MultiArrayData<Element, 2, dim_ints...>, 
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
    constexpr static size_t N1 = get<0>(static_dims_array);
    constexpr static size_t N2 = get<1>(static_dims_array);
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = ( sizeof...(dim_ints) == 0 );
    constexpr static size_t compile_time_size = calc_size<rank_value, N1, N2>();

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Type = MultiArray<Element, rank_value, dim_ints...>;
    using ConcreteType = Matrix<Element, dim_ints...>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using ParentDataType = MultiArrayData<Element, rank_value, dim_ints...>;
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
    // OBJECT DATA 
    //
    // data is inherited from MultiArrayData<Element, 2>
    //**********************************************************************


  public:

    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************

    // --------------------- default CONSTRUCTOR ---------------------

    MultiArray() {
      if constexpr (is_dynamic_value) {
        resize(0,0);
      }
    }

    // --------------------- copy constructor --------------------
    MultiArray(const Type& var) {
      if constexpr (is_dynamic_value) {
        resize(var.dims());
      }
      *this = var;
    }



    // ----------------------- indices initializer_list ---------------------
    // not explicit: allows use of nested init lists when depth_value > 1
    MultiArray(const InitializerType& var) {
      if constexpr (is_dynamic_value) {
        auto mysizes = InitializerTrait< InitializerType >::get_size_array(var);
        resize(Dimensions(mysizes));
      }
      *this = var;
    }


    //--------------------- EXPRESSION CONSTRUCTOR --------------------
    template <class Derived>
    MultiArray(const ExpressionR<Derived, Element, NumberType, depth_value, rank_value>& x) {
      if constexpr (is_dynamic_value) {
        resize(0,0);
      }
      *this = x;
    }


    //**********************************************************************
    //                    CONSTRUCTORS: FIXED dimensions  
    //**********************************************************************

    // --------------------- FIXED SIZE: from dynamic MultiArray --------------------

    template<bool enable = !is_dynamic_value> requires (enable)
    explicit MultiArray(const MultiArray<Element, rank_value>& var) {
      *this = var;
    }

    // --------------------- FIXED SIZE: set all to same value   ---------------------

    template<bool enable = !is_dynamic_value> requires (enable)
    explicit MultiArray(const Element val) {
      *this = val;
    }

    // --------------------- FIXED SIZE: set all bottom Elements to same value   ---------------------

    template<bool enable = !is_dynamic_value> requires ((enable) && (depth_value > 1) && (!std::is_same<Element, NumberType>::value) )
    explicit MultiArray(const NumberType val) {
      *this = val;
    }

    // ----------------------- FIXED SIZE: flat initializer_list ---------------------
    // not explicit: allows use of nested init lists when depth_value > 1
    template<bool enable = !is_dynamic_value> requires (enable)
    MultiArray(const std::initializer_list<Element>& var) {
      *this = var;
    }


    // ----------------------- std::vector ---------------------
    template<bool enable = !is_dynamic_value> requires (enable)
    explicit MultiArray(const std::vector<Element>& var) {
      *this = var;
    }

    // ----------------------- std::valarray ---------------------
    template<bool enable = !is_dynamic_value> requires (enable)
    explicit MultiArray(const std::valarray<Element>& var) {
      *this = var;
    }

    // ----------------------- std::array ---------------------
    template<size_t NE2> requires (!is_dynamic_value && ((NE2 == 0) || (NE2 == compile_time_size)))
    explicit MultiArray(const std::array<Element, NE2>& var) {
      if constexpr (is_dynamic_value) {
        resize(0,0);
      }
      *this = var;
    }


    //**********************************************************************
    //                    CONSTRUCTORS: DYNAMIC dimensions  
    //**********************************************************************

    // --------------------- dynamic MultiArray --------------------

    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray(const MultiArray<Element, rank_value> var) {
      this->resize(var.dims());
      *this = var;
    }


    // --------------------- DYNAMIC SIZE: set size from ints  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    MultiArray(const size_t Nrows, const size_t Ncols) {
      resize(Nrows, Ncols);
    }

    // --------------------- DYNAMIC SIZE: set size from ints and values from constant  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    MultiArray(const size_t Nrows, const size_t Ncols, const Element& val) {
      resize(Nrows, Ncols);
      *this = val;
    }

    // --------------------- DYNAMIC SIZE: set size from Dimensions  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray(const Dimensions& dims) {
      // TRDISP(dims);
      this->resize(dims);
    }

    // --------------------- DYNAMIC SIZE: set size from RecursiveDimensions  ---------------------
    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray(const RecursiveDimensions& recursive_dims) {
      // TRDISP(recursive_dims);
      this->resize(recursive_dims);
    }


    // --------------------- DYNAMIC SIZE: set dims and set all to same value  ---------------------

    template<bool enable = is_dynamic_value> requires (enable)
    explicit MultiArray(const Dimensions& dims, const Element& val) {
      this->resize(dims);
      *this = val;
    }

    // ----------------------- DYNAMIC SIZE: flat initializer_list ---------------------
    // not explicit: allows use of nested init lists when depth_value > 1
    template<bool enable = is_dynamic_value> requires (enable)
    MultiArray(const size_t Nrows, const size_t Ncols, const std::initializer_list<Element>& var) {
      resize(Nrows, Ncols);
      *this = var;
    }


    // // ----------------------- std::vector ---------------------
    // explicit MultiArray(const std::vector<Element>& var) {
    //   *this = var;
    // }

    // // ----------------------- std::valarray ---------------------
    // explicit MultiArray(const std::valarray<Element>& var) {
    //   if constexpr (is_dynamic_value) {
    //     resize(0,0);
    //   }
    //   *this = var;
    // }

    // // ----------------------- std::array ---------------------
    // template<size_t NE2>
    // explicit MultiArray(const std::array<Element, NE2>& var) {
    //   if constexpr (is_dynamic_value) {
    //     resize(0,0);
    //   }
    //   *this = var;
    // }

    //**********************************************************************
    //                             DESTRUCTOR 
    //**********************************************************************

    ~MultiArray() {
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
      return ParentDataType::data_.size();
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
          return ParentDataType::data_[0].size();
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
          return ParentDataType::data_[0].total_size();
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
        return ParentDataType::N1;
      } else {
        return N1;
      }
    }
    inline size_t Ncols(void) const {
      if constexpr (is_dynamic_value) {
        return ParentDataType::N2;
      } else {
        return N2;
      }
    }


    // defined later since Dimensions is dependent on MultiArray
    Dimensions& dims(void) const {
      if constexpr (is_dynamic_value) {
        return *(new Dimensions({ ParentDataType::N1, ParentDataType::N2 }));
      } else {
        return *(new Dimensions(static_dims_array));
      }
    }

    inline std::array<size_t, rank_value> dims_array(void) const {
      if constexpr (is_dynamic_value) {
        return *(new std::array<size_t, rank_value>{ ParentDataType::N1, ParentDataType::N2 });
      } else {
        return static_dims_array;
      }
    }

    ElementDimensionsType& element_dims(void) const {
      if constexpr (depth_value > 1) {
        if (this->size() > 0) {
          return ParentDataType::data_[0].dims();
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
          ParentDataType::data_[0].recurse_dims(parent_rdims, depth_index);
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
      if ( (ParentDataType::N1 != Nrows_new) ||(ParentDataType::N2 != Ncols_new) ) {
        ParentDataType::N1 = Nrows_new;
        ParentDataType::N2 = Ncols_new;
        const size_t new_size = Nrows_new * Ncols_new;
        if (new_size != ParentDataType::data_.size() ) {
          ParentDataType::data_.resize( new_size );
        }
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
    //   this casted as MultiArrayData
    //**********************************************************************
    ParentDataType& asMultiArrayData() {
      return *((ParentDataType*)(this));
    }

    //**********************************************************************
    //********************* Direct access to ParentDataType::data_  ***********************************
    //**********************************************************************

    // -------------------- data_obj() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& data_obj() {
      return ParentDataType::data_;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      // MutltiArrays are always wrap avalarray<Element>
      return &(ParentDataType::data_[0]);
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
      size_t k = this->index(i1, i2);
      return (*this)[k];
    }

    const Element& operator()(const size_t i1, const size_t i2) const {
      size_t k = this->index(i1, i2);
      return (*this)[k];
    }

    // negative indexing 

    template <typename... U>
    Element& operator()(const U... args) requires (std::conjunction< std::is_integral<U>...>::value && std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value) )
    {
      Indices inds({ signed_index_to_unsigned_index(args, size())... });
      return (*this)[inds];
    }

    template <typename... U>
    const Element& operator()(const U... args) const 
    requires (std::conjunction< std::is_integral<U>...>::value && std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value) )
    {
      Indices inds({ signed_index_to_unsigned_index(args, size())... });
      return (*this)[inds];
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
        int k = n;
        if (k < 0) {
          k += size();
        }
        return ParentDataType::data_[k];
      }
      else {
        const int Ndeep = this->el_total_size();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return ParentDataType::data_[j].dat(k);
      }
    }

    // read
    const NumberType& dat(const size_t n) const {
      using namespace ::display;
      //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
      if constexpr (depth_value <= 1) {
        int k = n;
        if (k < 0) {
          k += size();
        }
        return ParentDataType::data_[k];
      }
      else {
        const int Ndeep = this->el_total_size();
        const int j = n / Ndeep;
        const int k = n % Ndeep;
        return ParentDataType::data_[j].dat(k);
      }
    }


    // **********************************************************************
    // ************* Array-style Element Access: x[n] ***********************
    // **********************************************************************

    // "read/write"
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      // OUTPUT("[] 1");
      return ParentDataType::data_[n];
    }

    // read
    template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      // OUTPUT("[] 2");
      return ParentDataType::data_[n];
    }

    // "read/write"
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    Element& operator[](const T n) {
      // OUTPUT("[] 3");
      T m = n;
      while (m < 0) m += size();
      return ParentDataType::data_[m];
    }

    // read
    template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
    const Element& operator[](const T n)  const {
      // OUTPUT("[] 4");
      T m = n;
      while (m < 0) m += size();
      return ParentDataType::data_[m];
    }

    //**********************************************************************
    //************************** A[Indices] ***********************************
    //**********************************************************************

    // ---------------- A[Indices]--------------
    Element& operator[](const Indices& inds) {
      size_t k = this->index(inds);
      return (*this)[k];
    }
    const Element& operator[](const Indices& inds) const {
      size_t k = this->index(inds);
      return (*this)[k];
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
      for (size_t i = 0; i < size(); i++) {
        (*this)[i] = e;
      }
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




    // ------------------------ MultiArray = MultiArray<Element,NE2,NumberType,depth_value> ----------------

    template <size_t... sizes> requires (multi_array_compatibility<rank_value,rank_value,dim_ints...,sizes...>())
    Type& operator=(const MultiArray<Element, rank_value, sizes...>& v) {
      for (size_t i = 0; i < size(); i++) {
        (*this)[i] = v[i];
      }
      return *this;
    }


    // ------------------------ MultiArray = ExpressionR ----------------

    template <class X>
    Type& operator=(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {
      if constexpr (depth_value <= 1) {
        if constexpr (is_dynamic_value) {
          if (this->size() != x.size()) {
            resize(x.dims());
          }
        }
        for (size_t i = 0; i < size(); i++) {
          (*this)[i] = x[i];
        }
      }
      else {
        resize(x.recursive_dims());
        for (size_t i = 0; i < total_size(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }



    // ------------------------ MultiArray = array[] ----------------

    Type& operator=(const Element array[]) {
      for (size_t i = 0; i < size(); i++) {
        (*this)(i) = array[i];
      }
      return *this;
    }


    // ------------------------ MultiArray = list ----------------

    Type& operator=(const std::list<Element>& mylist) {
      size_t i = 0;
      for (typename std::list<Element>::const_iterator it = mylist.begin(); it != mylist.end(); it++) {
        (*this)(i++) = *it;
      }
      return *this;
    }


    // ------------------------ MultiArray = initializer_list ----------------

    Type& operator=(const std::initializer_list<Element>& mylist) {
      size_t k = 0;
      typename std::initializer_list<Element>::iterator it;
      for (it = mylist.begin(); it != mylist.end(); it++, k++) {
        ParentDataType::data_[k] = *it;
      }
      return *this;
    }

    // // ------------------------ MultiArray = initializer_list ----------------

    Type& operator=(const typename MakeInitializer<Element, rank_value>::Type& mylist) {
      Indices& inds = *(new Indices(rank_value));
      list_helper<rank_value>(mylist, inds);
      return *this;
    }

    template <size_t list_depth> requires ((list_depth >= 1) && (list_depth <= rank_value))
    Type& list_helper(const typename MakeInitializer<Element, list_depth>::Type& mylist, Indices& inds) {
      size_t k = 0;
      using ListType = typename MakeInitializer<Element, list_depth>::Type;
      using Iterator = typename MakeInitializer<Element, list_depth>::Type::iterator;
      Iterator it = mylist.begin();

      for (it = mylist.begin(); it != mylist.end(); it++, k++) {
        inds[rank_value-list_depth] = k;
        if constexpr (list_depth == 1) {
          (*this)[inds] = *it;
        } else {
          list_helper<list_depth-1>(*it, inds);
        }
      }
      return *this;
    }


    // ------------------------ MultiArray = std::vector ----------------

    Type& operator=(const std::vector<Element>& vstd) {
      for (size_t i = 0; i < size(); i++)
        (*this)(i) = vstd[i];
      return *this;
    }


    // ------------------------ MultiArray = std::array ----------------

    template <size_t N>
    Type& operator=(const std::array<NumberType, N>& varray) {
      for (size_t i = 0; i < size(); i++)
        (*this)(i) = varray[i];

      return *this;
    }


    // ------------------------ MultiArray = std::valarray ----------------

    Type& operator=(const std::valarray<Element>& varray) {
      for (size_t i = 0; i < size(); i++)
        (*this)(i) = varray[i];

      return *this;
    }


    //**********************************************************************
    //***************** in-place modification*******************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Type& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      for (size_t i = 0; i < size(); i++) {
        ParentDataType::data_[i] = mathq::roundzero(ParentDataType::data_[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T = NumberType >
    typename std::enable_if<is_complex<T>::value, Type& >::type conj() {
      for (size_t i = 0; i < size(); i++) {
        ParentDataType::data_[i] = std::conj(ParentDataType::data_[i]);
      }
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
        size_t r, c;
        NumberType temp;
        for (r = 0; r < Nr; ++r)
          for (c = r + 1; c < Nr; ++c) {
            temp = (*this)[r + c * Nr];
            (*this)[r + c * Nr] = (*this)[c + r * Nr];
            (*this)[c + r * Nr] = temp;
          }
        return *this;
      }

      if constexpr (is_dynamic_value) {

      resize(Nc, Nr);

      // for "vectors" 
      if (Nc == 1 || Nr==1) {
        return *this;
      }

      // boolean array to make searching faster
      // can set Nmove=1, but this will be very slow
      // Nmove=(Nr+Nc)/2 is optimal
      const bool Nmove = (Nr+Nc)/2;
      size_t move[Nmove];
      for (size_t i = 0; i < Nmove; ++i)
        move[i] = false;


      // there are always at least 2 fixed points (at j=0 and j=Nminus1)
      size_t count = 2;
      // find the rest of the fixed points
      if (Nc >= 3 && Nr >= 3)
        count += std::gcd(Nc - 1, Nr - 1) - 1;	/* # fixed points */

      size_t jstart = 1;
      size_t magicnum = Nc;

      while (1) {
        size_t jnext, jnextc;
        size_t jstartC = Nminus1 - jstart;
        size_t j = jstart;
        size_t jC = jstartC;
        NumberType dstart = (*this)[jstart];
        NumberType dstartC = (*this)[jstartC];

        // PROCESS THE CURRENT SEQUENcE AND ITS COMPLIMENTARY SEQUENcE
        while (1) {
          jnext = Nc * j - Nminus1 * (j / Nr);
          jnextc = Nminus1 - jnext;
          if (j < Nmove)
            move[j] = true;
          if (jC < Nmove)
            move[jC] = true;
          count += 2;
          if (jnext == jstart) {
            (*this)[j] = dstart;
            (*this)[jC] = dstartC;
            break;
          }
          if (jnext == jstartC) {
            (*this)[j] = dstartC;
            (*this)[jC] = dstart;
            break;
          }
          (*this)[j] = (*this)[jnext];
          (*this)[jC] = (*this)[jnextc];
          j = jnext;
          jC = jnextc;
        }
        // DONE PROCESSING SEQUENcE


        // CHECK TO SEE IF WE'RE FINISHED
        if (count >= N)
          break;

        // FIND THE START OF THE NEXT SEQUENcE
        while (1) {
          // skip fixed points (jstart==magicnum)
          do {
            jstart++;
            if ((magicnum += Nc)>Nminus1)
              magicnum -= Nminus1;
          } while (jstart==magicnum);

          jnext = magicnum;
          const  size_t max = Nminus1-jstart+1;
          if (jstart < Nmove) {
            if (!move[jstart])
              break;
          }
          else {
            // this while loop is needed to cull out previously 
            // processed slcuences
            while (jnext > jstart && jnext < max) {
              j = jnext;
              jnext = Nc * j - Nminus1 * (j / Nr);
            }
          }
          if (jnext == jstart)
            break;
        }
        // WE HAVE FOUND START OF THE NEXT SEQUENcE

      }
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
      std::string s = "Matrix";
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
