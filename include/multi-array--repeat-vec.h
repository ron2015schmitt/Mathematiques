#ifndef MATHQ__MULTI_ARRAY_REPEAT_VECTOR
#define MATHQ__MULTI_ARRAY_REPEAT_VECTOR 1


/********************************************************************
 * RepeatedVectorMultiArray is a MultiArray_RepeatVector that consists of a single
 * vector across index `slot` repeated to fill the multiarray.
 * This is useful for grids.
 *
 * This is the template definition, ie not a specialization
 ********************************************************************
 */


namespace mathq {


  template <typename Element, size_t rank_, size_t... dim_ints> requires (validate_multi_array<rank_, dim_ints...>())
    class MultiArray_RepeatVector :

    public SpecialData<Element, rank_, dim_ints...>,

    public ExpressionRW<
    MultiArray_RepeatVector<Element, rank_, dim_ints...>,  // Derived
    Element,  // Element
    typename NumberTrait<Element>::Type, // Num
    1 + NumberTrait<Element>::depth(),  // depth
    rank_  // rank
    > {


    public:

      //**********************************************************************
      //                  Compile Time Constant
      //**********************************************************************

      constexpr static bool isNotExpression = true;
      constexpr static size_t rank_value = rank_;
      constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
      constexpr static bool is_dynamic_value = (sizeof...(dim_ints) == 0);
      constexpr static size_t compile_time_size = calc_size<rank_value, dim_ints...>();

      // note that the following will be all zeroes for dyanmic multi-arrays
      constexpr static std::array<size_t, rank_value> static_dims_array = { (static_cast<size_t>(dim_ints))... };

      //**********************************************************************
      //                            TYPES 
      //**********************************************************************

      using Type = MultiArray_RepeatVector<Element, rank_, dim_ints...>;
      using ConcreteType = MultiArray<Element, rank_, dim_ints...>;


      using ElementType = Element;
      using NumberType = typename NumberTrait<Element>::Type;
      using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

      using ParentDataType = SpecialData<Element, rank_, dim_ints...>;
      using ParentType = ExpressionRW<
        ConcreteType,  // Derived
        Element,  // Element
        NumberType, // Num
        depth_value,  // depth
        rank_value  // rank
      >;

      using DimensionsType = Dimensions;
      using ElementDimensionsType = typename DimensionsTrait<Element>::Type;
      using DeepDimensionsType = RecursiveDimensions;

      using InitializerType = typename MakeInitializer<Element, 1 >::Type;  // <-- Vector

      template <typename NewElement>
      using Type_ReplaceElement = MultiArray<NewElement, rank_value, dim_ints...>;


      //**********************************************************************
      // OBJECT DATA 
      //
      //**********************************************************************
      std::valarray<Element> vector;
      size_t vector_index;

    public:

      //**********************************************************************
      //                            CONSTRUCTORS 
      //**********************************************************************

      // --------------------- default CONSTRUCTOR ---------------------

      MultiArray_RepeatVector() : vector_index(0) {
        initial_size();
      }

      // --------------------- basic CONSTRUCTOR ---------------------

      MultiArray_RepeatVector(const size_t vector_index) : vector_index(vector_index) {
        initial_size();
      }

      // --------------------- copy constructor --------------------
      MultiArray_RepeatVector(const Type& var) : vector_index(var.vector_index) {
        initial_size();
        *this = var;
      }

      // ----------------------- indices initializer_list ---------------------
      // not explicit: allows use of nested init lists when depth_value > 1
      MultiArray_RepeatVector(const size_t vector_index, const InitializerType& var) : vector_index(vector_index) {
        if constexpr (is_dynamic_value) {
          auto mysizes = InitializerTrait< InitializerType >::get_size_array(var);
          resize(Dimensions(mysizes));
        }
        else {
          initial_size();
        }
        *this = var;
      }

      // ----------------------- std::vector ---------------------
      explicit MultiArray_RepeatVector(const size_t vector_index, const std::vector<Element>& var) : vector_index(vector_index) {
        initial_size();
        *this = var;
      }

      // ----------------------- std::valarray ---------------------
      explicit MultiArray_RepeatVector(const size_t vector_index, const std::valarray<Element>& var) : vector_index(vector_index) {
        initial_size();
        *this = var;
      }

      // ----------------------- std::array ---------------------
      template<size_t NE2>
      explicit MultiArray_RepeatVector(const size_t vector_index, const std::array<Element, NE2>& var) : vector_index(vector_index) {
        initial_size();
        *this = var;
      }

      // //--------------------- EXPRESSION CONSTRUCTOR --------------------
      // template <class Derived>
      // MultiArray_RepeatVector(const size_t vector_index, const ExpressionR<Derived, Element, NumberType, depth_value, rank_value>& x)  : vector_index(vector_index)  {
      //   *this = x;
      // }


      //**********************************************************************
      //                    CONSTRUCTORS: FIXED dimensions  
      //**********************************************************************

      // --------------------- FIXED SIZE: from dynamic MultiArray_RepeatVector --------------------

      template<bool enable = !is_dynamic_value> requires (enable)
        explicit MultiArray_RepeatVector(const MultiArray_RepeatVector<Element, rank_value>& var) : vector_index(var.vector_index) {
        initial_size();
        *this = var;
      }

      // --------------------- FIXED SIZE: set all to same value   ---------------------

      template<bool enable = !is_dynamic_value> requires (enable)
        explicit MultiArray_RepeatVector(const size_t vector_index, const Element val) : vector_index(vector_index) {
        initial_size();
        *this = val;
      }

      // --------------------- FIXED SIZE: set all bottom Elements to same value   ---------------------

      // template<typename NT = NumberType, EnableIf<(!is_dynamic_value)&&(depth_value>1)&&(!std::is_same<Element, NT>::value)> = 1>

      template<bool enable = !is_dynamic_value> requires ((enable) && (depth_value>1) && (!std::is_same<Element, NumberType>::value))
        explicit MultiArray_RepeatVector(const size_t vector_index, const NumberType val) : vector_index(vector_index) {
        initial_size();
        *this = val;
      }

      // ----------------------- FIXED SIZE: flat initializer_list ---------------------
      // not explicit: allows use of nested init lists when depth_value > 1
      template<bool enable = !is_dynamic_value> requires (enable)
        MultiArray_RepeatVector(const size_t vector_index, const std::initializer_list<Element>& var) : vector_index(vector_index) {
        initial_size();
        *this = var;
      }

      //**********************************************************************
      //                    CONSTRUCTORS: DYNAMIC dimensions  
      //**********************************************************************

      // --------------------- dynamic MultiArray_RepeatVector --------------------

      template<size_t...mysizes> requires (is_dynamic_value)
        explicit MultiArray_RepeatVector(const MultiArray_RepeatVector<Element, rank_value, mysizes...>& var) : vector_index(var.vector_index) {
        *this = var;
      }


      // --------------------- DYNAMIC SIZE: set size from Dimensions  ---------------------

      template<bool enable = is_dynamic_value> requires (enable)
        explicit MultiArray_RepeatVector(const size_t vector_index, const Dimensions& dims) : vector_index(vector_index) {
        // TRDISP(dims);
        this->resize(dims);
      }

      // --------------------- DYNAMIC SIZE: set size from RecursiveDimensions  ---------------------
      template<bool enable = is_dynamic_value> requires (enable)
        explicit MultiArray_RepeatVector(const size_t vector_index, const RecursiveDimensions& recursive_dims) : vector_index(vector_index) {
        // TRDISP(recursive_dims);
        this->resize(recursive_dims);
      }


      // --------------------- DYNAMIC SIZE: set dims and set all to same value  ---------------------

      template<bool enable = is_dynamic_value> requires (enable)
        explicit MultiArray_RepeatVector(const size_t vector_index, const Dimensions& dims, const Element val) : vector_index(vector_index) {
        this->resize(dims);
        *this = val;
      }

      //**********************************************************************
      //                             DESTRUCTOR 
      //**********************************************************************

      ~MultiArray_RepeatVector() {
        // remove from directory
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
        OUTPUT("SIZE");
        if constexpr (is_dynamic_value) {
          auto myarray = dims_array();
          OUTPUT("SIZE::dynamic");
          return std::accumulate(myarray.begin(), myarray.end(), 1, std::multiplies<size_t>());  // product of elements
        }
        else {
          return compile_time_size;
        }
      }

      inline size_t actual_size(void) const {
        return vector.size();
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
            return vector[0].size();
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
            return vector[0].total_size();
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

      // defined later since Dimensions is dependent on MultiArray_RepeatVector
      Dimensions& dims(void) const {
        return *(new Dimensions(dims_array()));
      }

      inline std::array<size_t, rank_value> dims_array(void) const {
        if constexpr (is_dynamic_value) {
          if constexpr (rank_value == 0) {
            return std::array<size_t, rank_value>{};
          }
          else if constexpr (rank_value == 1) {
            return std::array<size_t, rank_value>{ ParentDataType::N0 };
          }
          else if constexpr (rank_value == 2) {
            return std::array<size_t, rank_value>{ ParentDataType::N0, ParentDataType::N1 };
          }
          else {
            return ParentDataType::dynamic_dims_array;
          }
        }
        else {
          return static_dims_array;
        }
      }

      ElementDimensionsType& element_dims(void) const {
        if constexpr (depth_value > 1) {
          if (this->size() > 0) {
            return vector[0].dims();
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
            vector[0].recurse_dims(parent_rdims, depth_index);
          }
          else {
            Element& x = *(new Element);
            x.recurse_dims(parent_rdims, depth_index);
          }
        }
        return *this;
      }

      //**********************************************************************//                          Resize
      //
      // resize / reshape is not allowed unless fixed-dimensions 
      //**********************************************************************

      Type& initial_size() {
        if constexpr (is_dynamic_value) {
          resize(Dimensions(rank_value)); // default is all zeroes
          vector.resize(0);
        }
        else {
          vector.resize(static_dims_array[vector_index]);
        }
        return *this;
      }


      template <typename... U> requires ((is_dynamic_value) && (std::conjunction<std::is_integral<U>...>::value) && (sizeof...(U) == rank_value))
        Type& resize(const U... args) {
        Dimensions new_dims{ size_t(args)... };
        return resize(new_dims);
      }

      Type& resize_vector(const size_t size) {
        Dimensions mydims = dims();
        mydims[vector_index] = size;
        if constexpr (is_dynamic_value) {
          resize(mydims);
        }
        return *this;
      }


      template <bool enabled = is_dynamic_value> requires (enabled)
        Type& resize(const Dimensions& new_dims) {
        if constexpr (is_dynamic_value) {
          if (new_dims != dims()) {
            if constexpr (rank_value == 0) {
            }
            else if constexpr (rank_value == 1) {
              ParentDataType::N0 = new_dims[0];
            }
            else if constexpr (rank_value == 2) {
              ParentDataType::N0 = new_dims[0];
              ParentDataType::N1 = new_dims[1];
            }
            else {
              for (size_t i = 0; i < rank_value; i++) {
                ParentDataType::dynamic_dims_array[i] = new_dims[i];
              }
            }
            size_t new_size = new_dims[vector_index];
            if (actual_size() != new_size) {
              vector.resize(new_size);
            }
          }
        }
        return *this;
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
        const Dimensions& new_dims = parent_rdims[depth_index++];
        if constexpr (is_dynamic_value) {
          resize(new_dims);
        }
        if constexpr (depth_value > 1) {
          if (depth_index < resize_depth) {
            for (size_t ii = 0; ii < size(); ii++) {
              (*this)[ii].recurse_resize(parent_rdims, depth_index);
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
      //********************* Direct access to (*this)  ***********************************
      //**********************************************************************

      // -------------------- data_obj() --------------------
      // "read/write" to the wrapped valarray/aray
      auto& data_obj() {
        return (*this);
      }

      // get C pointer to raw data
      // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
      Element* data() {
        // MutltiArrays are always wrap avalarray<Element>
        return &((*this)[0]);
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
        index(const U... args) const {
        std::array<size_t, rank_value> arr{ std::make_unsigned<int>::type(args)... };
        return index(*(new mathq::Indices(arr)));
      }

      //**********************************************************************
      //******* A(i,j,k,...) *********************
      //**********************************************************************


      template <typename... U>
      Element& operator()(const U... args) requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_unsigned<U>...>::value && (sizeof...(args) == rank_value)) {
        OUTPUT("inside");
        Indices inds = Indices({ args... });
        TRDISP(inds);
        return vector[inds[vector_index]];
      }

      template <typename... U>
      const Element& operator()(const U... args) const requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_unsigned<U>...>::value && (sizeof...(args) == rank_value)) {
        Indices inds = Indices({ args... });
        return vector[inds[vector_index]];
      }



      // negative indexing 
      template <typename... U>
      Element& operator()(const U... args) requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value)) {
        Indices inds({ signed_index_to_unsigned_index(args, size())... });
        return vector[inds[vector_index]];
      }

      template <typename... U>
      const Element& operator()(const U... args) const requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value)) {
        Indices inds({ signed_index_to_unsigned_index(args, size())... });
        return vector[inds[vector_index]];
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
          return (*this)[k];
        }
        else {
          const int Ndeep = this->el_total_size();
          const int j = n / Ndeep;
          const int k = n % Ndeep;
          return (*this)[j].dat(k);
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
          return (*this)[k];
        }
        else {
          const int Ndeep = this->el_total_size();
          const int j = n / Ndeep;
          const int k = n % Ndeep;
          return (*this)[j].dat(k);
        }
      }


      // **********************************************************************
      // ************* Array-style Element Access: x[n] ***********************
      // **********************************************************************

      // "read/write"
      template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
        Element& operator[](const T n) {
        // OUTPUT("[] 1");
        Indices inds = indices(n);
        return vector[inds[vector_index]];
      }

      // read
      template <typename T> requires ((std::is_unsigned<T>::value) && (std::is_integral<T>::value))
        const Element& operator[](const T n)  const {
        // OUTPUT("[] 2");
        Indices inds = indices(n);
        return vector[inds[vector_index]];
      }

      // "read/write"
      template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
        Element& operator[](const T n) {
        // OUTPUT("[] 3");
        T m = n;
        while (m < 0) m += size();
        return (*this)[size_t(m)];
      }

      // read
      template <typename T> requires ((std::is_signed<T>::value) && (std::is_integral<T>::value))
        const Element& operator[](const T n)  const {
        // OUTPUT("[] 4");
        T m = n;
        while (m < 0) m += size();
        return (*this)[size_t(m)];
      }

      //**********************************************************************
      //************************** A[Indices] ***********************************
      //**********************************************************************

      // ---------------- A[Indices]--------------
      Element& operator[](const Indices& inds) {
        vector[inds[vector_index]];
      }
      const Element& operator[](const Indices& inds) const {
        vector[inds[vector_index]];
      }

      // -------------------------------------------------------------
      //                        A[DeepIndices] 
      // -------------------------------------------------------------

      // "read/write"
      NumberType& operator[](const DeepIndices& dinds) {
        const size_t mydepth = dinds.size();
        const Indices& inds = dinds[mydepth - depth_value];

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
        const Indices& inds = dinds[mydepth - depth_value];

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
      template<typename T> requires (std::is_convertible<T, Element>::value)
        Type& operator=(const T& e) {
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = e;
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




      // ------------------------ MultiArray_RepeatVector = MultiArray_RepeatVector<Element,NE2,NumberType,depth_value> ----------------

      template <size_t... sizes> requires (multi_array_compatibility<rank_value, rank_value, dim_ints..., sizes...>())
        Type& operator=(const MultiArray_RepeatVector<Element, rank_value, sizes...>& v) {
        return (*this = +v);
      }


      template <class X>
      bool verify(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {
        // TODO: it owuld be better to check equivalent dimensions. need to support this somehow via a new Indices method for Indices with dimension(s) = 1
        if (dims() != x.dims()) {
          OUTPUT("ERROR: attempt to set MultiArray_RepeatVector from expression with incompatible dimensions.");
          TRDISP(dims());
          TRDISP(x.dims());
          return false;
        }
        Indices inds(dims());
        for (size_t i = 0; i < dims().num_elements(); i++) {
          Indices inds_ref(dims());
          inds_ref[vector_index] = inds[vector_index];
          // MDISP(inds, inds_ref);
          if (x[inds.index(dims())] != x[inds_ref.index(dims())]) {
            OUTPUT("ERROR: attepmt to set MultiArray_RepeatVector from non-compatible expression.");
            OUTPUT("       expressions values ");
            MDISP(x[inds], x[inds_ref]);
            OUTPUT("       for indices");
            MDISP(inds, inds_ref);
            OUTPUT("       should be equal.  ");
            //  TRDISP(*this);
            //  TRDISP(x);
            return false;
          }
          inds.increment(dims());
        }

        return true;
      }

      // ------------------------ MultiArray_RepeatVector = ExpressionR ----------------

      template <class X>
      Type& operator=(const ExpressionR<X, Element, NumberType, depth_value, rank_value>& x) {

        if (!verify(x)) return *this;

        if constexpr (depth_value <= 1) {
          if constexpr (is_dynamic_value) {
            if (this->size() != x.size()) {
              resize(x.dims());
            }
          }

          Indices inds(dims());
          for (size_t i = 0; i < dims()[vector_index]; i++) {
            inds[vector_index] = i;
            // we assume that expression has equiv dimensions, as checked in verify

            vector[i] = x[inds.index(dims())];
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



      // ------------------------ MultiArray_RepeatVector = Vector ----------------

      Type& operator=(const Vector<Element>& q) {
        resize_vector(q.size());
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = q[i];
        }
        return *this;
      }


      // ------------------------ MultiArray_RepeatVector = array[] ----------------

      Type& operator=(const Element q[]) {
        resize_vector(q.size());
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = q[i];
        }
        return *this;
      }


      // ------------------------ MultiArray_RepeatVector = list ----------------

      Type& operator=(const std::list<Element>& q) {
        resize_vector(q.size());
        size_t i = 0;
        for (typename std::list<Element>::const_iterator it = q.begin(); it != q.end(); it++) {
          vector[i++] = *it;
        }
        return *this;
      }


      // ------------------------ MultiArray_RepeatVector = initializer_list ----------------

      Type& operator=(const std::initializer_list<Element>& q) {
        resize_vector(q.size());
        size_t i = 0;
        for (typename std::initializer_list<Element>::const_iterator it = q.begin(); it != q.end(); it++) {
          vector[i++] = *it;
        }
        return *this;
      }


      // ------------------------ MultiArray_RepeatVector = std::vector ----------------

      Type& operator=(const std::vector<Element>& q) {
        resize_vector(q);
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = q[i];
        }
        return *this;
      }


      // ------------------------ MultiArray_RepeatVector = std::array ----------------

      template <size_t N>
      Type& operator=(const std::array<NumberType, N>& q) {
        resize_vector(q);
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = q[i];
        }
        return *this;
      }


      // ------------------------ MultiArray_RepeatVector = std::valarray ----------------

      Type& operator=(const std::valarray<Element>& q) {
        resize_vector(q);
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = q[i];
        }
        return *this;
      }


      //**********************************************************************
      //***************** in-place modification*******************************
      //**********************************************************************


      //----------------- .roundzero(tol) ---------------------------
      // NOTE: in-place

      Type& roundzero(SimpleNumberType tolerance = Functions<SimpleNumberType>::tolerance) {
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = mathq::roundzero(vector[i], tolerance);
        }
        return *this;
      }

      //----------------- .conj() ---------------------------
      // NOTE: in-place

      template< typename T = NumberType >
      typename std::enable_if<is_complex<T>::value, Type& >::type conj() {
        for (size_t i = 0; i < actual_size(); i++) {
          vector[i] = std::conj(vector[i]);
        }
        return *this;
      }


      // only allow when we don't need to resize. else use the transpose function
      Type& transpose() {
        Dimensions mydims = dims();
        if (mydims != mydims.getReverse()) {
          printf("ERROR: in-place transpose only allowed for square tensors");
          return *this;
        }
        Indices& inds = *(new Indices(rank_value));
        inds.clear();
        transpose_helper(inds);
        return *this;
      }

      Type& transpose_helper(Indices& inds, const size_t& index_number = 0) {
        for (size_t ii = 0; ii < dims()[index_number]; ii++) {
          inds[index_number] = ii;
          if (index_number < rank_value/2) {
            transpose_helper(inds, index_number - 1);
          }
          else {
            // we've reached the bottom
            Element temp = (*this)[inds];
            (*this)[inds] = (*this)[inds.getReverse()];
            (*this)[inds.getReverse()] = temp;
          }
        }
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
        // TRDISP(rank_value);
        // TRDISP(vector_index);
        // TRDISP(static_dims_array);
        // TRDISP(sizeof...(dim_ints));
        std::string s = "MultiArray_RepeatVector";
        s += StyledString::get(ANGLE1).get();
        Element d;
        s += getTypeName(d);
        s += StyledString::get(COMMA).get();
        s += " rank=";
        s += std::to_string(rank_value);
        // s += ", index=";
        // s += std::to_string(vector_index);
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
        stream << "vector_index=" << t.vector_index;
        stream << ", dims=" << t.dims();
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
