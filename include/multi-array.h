#ifndef MATHQ__MULTI_ARRAY
#define MATHQ__MULTI_ARRAY 1

namespace mathq {



  /********************************************************************
   * MultiArray<Element,rank, dim_ints...>
   *
   *            rank = number of rank (0=scalar,1=vector,2=matrix,etc)
   *            dim_ints
   *
   * This is the template definition, ie not a specialization
   ********************************************************************
   */

  template <typename Element, size_t rank_, size_t... dim_ints> requires (validate_multi_array<rank_, dim_ints...>())
    class MultiArray : public MultiArrayData<Element, rank_, dim_ints...>,
    public ExpressionRW<
    MultiArray<Element, rank_, dim_ints...>,  // Derived
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

      using Type = MultiArray<Element, rank_value, dim_ints...>;
      using ConcreteType = Type;


      using ElementType = Element;
      using NumberType = typename NumberTrait<Element>::Type;
      using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

      using ParentDataType = MultiArrayData<Element, rank_, dim_ints...>;
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

      using MyArrayType = typename ArrayTypeTrait<Element, compile_time_size>::Type;

      using InitializerType = typename MakeInitializer<Element, rank_value >::Type;

      template <typename NewElement>
      using Type_ReplaceElement = MultiArray<NewElement, rank_value, dim_ints...>;


    public:

      //**********************************************************************
      //                            CONSTRUCTORS 
      //**********************************************************************

      // --------------------- default CONSTRUCTOR ---------------------

      MultiArray() {
      }

      // --------------------- copy constructor --------------------
      MultiArray(const Type& var) {
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

      // ----------------------- std::vector ---------------------
      explicit MultiArray(const std::vector<Element>& var) {
        *this = var;
      }

      // ----------------------- std::valarray ---------------------
      explicit MultiArray(const std::valarray<Element>& var) {
        *this = var;
      }

      // ----------------------- std::array ---------------------
      template<size_t NE2>
      explicit MultiArray(const std::array<Element, NE2>& var) {
        *this = var;
      }

      //--------------------- EXPRESSION CONSTRUCTOR --------------------
      template <class Derived>
      MultiArray(const ExpressionR<Derived, Element, NumberType, depth_value, rank_value>& x) {
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

      // template<typename NT = NumberType, EnableIf<(!is_dynamic_value)&&(depth_value>1)&&(!std::is_same<Element, NT>::value)> = 1>

      template<bool enable = !is_dynamic_value> requires ((enable) && (depth_value>1) && (!std::is_same<Element, NumberType>::value))
        explicit MultiArray(const NumberType val) {
        *this = val;
      }

      // ----------------------- FIXED SIZE: flat initializer_list ---------------------
      // not explicit: allows use of nested init lists when depth_value > 1
      template<bool enable = !is_dynamic_value> requires (enable)
        MultiArray(const std::initializer_list<Element>& var) {
        *this = var;
      }

      //**********************************************************************
      //                    CONSTRUCTORS: DYNAMIC dimensions  
      //**********************************************************************

      // --------------------- dynamic MultiArray --------------------

      template<size_t...mysizes> requires (is_dynamic_value)
        explicit MultiArray(const MultiArray<Element, rank_value, mysizes...>& var) {
        *this = var;
      }


      // --------------------- DYNAMIC SIZE: set size from Dimensions  ---------------------

      template<bool enable = is_dynamic_value> requires (enable)
        explicit MultiArray(const Dimensions& dims) {
        // ETV(dims);
        this->resize(dims);
      }

      // --------------------- DYNAMIC SIZE: set size from RecursiveDimensions  ---------------------
      template<bool enable = is_dynamic_value> requires (enable)
        explicit MultiArray(const RecursiveDimensions& recursive_dims) {
        // ETV(recursive_dims);
        this->resize(recursive_dims);
      }


      // --------------------- DYNAMIC SIZE: set dims and set all to same value  ---------------------

      template<bool enable = is_dynamic_value> requires (enable)
        explicit MultiArray(const Dimensions& dims, const Element val) {
        this->resize(dims);
        *this = val;
      }

      //**********************************************************************
      //                             DESTRUCTOR 
      //**********************************************************************

      ~MultiArray() {
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

      // defined later since Dimensions is dependent on MultiArray
      Dimensions& dims(void) const {
        return *(new Dimensions(dims_array()));
      }

      inline std::array<size_t, rank_value> dims_array(void) const {
        if constexpr (is_dynamic_value) {
          return ParentDataType::dynamic_dims_array;
        }
        else {
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

      template <typename... U> requires ((is_dynamic_value) && (std::conjunction<std::is_integral<U>...>::value) && (sizeof...(U) == rank_value))
        Type& resize(const U... args) {
        std::array<size_t, rank_value> new_dims_array{ size_t(args)... };
        if (ParentDataType::dynamic_dims_array != new_dims_array) {
          ParentDataType::dynamic_dims_array = new_dims_array;
          size_t new_size = std::accumulate(new_dims_array.begin(), new_dims_array.end(), 1, std::multiplies<size_t>());  // product of elements
          ParentDataType::data_.resize(new_size);
        }
        return *this;
      }



      template <bool enabled = is_dynamic_value> requires (enabled)
        Type& resize(const Dimensions& new_dims) {
        auto new_dims_array = new_dims.toArray<rank_value>();
        if (ParentDataType::dynamic_dims_array != new_dims_array) {
          ParentDataType::dynamic_dims_array = new_dims_array;
          ParentDataType::data_.resize(new_dims.num_elements());
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
        const Dimensions& new_dims = parent_rdims[depth_index];
        if constexpr (is_dynamic_value) {
          resize(new_dims);
        }
        if constexpr (depth_value > 1) {
          if (++depth_index < resize_depth) {
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
        index(const U... args) const {
        std::array<size_t, rank_value> arr{ std::make_unsigned<int>::type(args)... };
        return index(*(new mathq::Indices(arr)));
      }

      //**********************************************************************
      //******* A(i,j,k,...) *********************
      //**********************************************************************



      template <typename... U>
      Element& operator()(const U... args) requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_unsigned<U>...>::value && (sizeof...(args) == rank_value)) {
        size_t k = this->index(args...);
        return (*this)[k];
      }

      template <typename... U>
      const Element& operator()(const U... args) const requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_unsigned<U>...>::value && (sizeof...(args) == rank_value)) {
        size_t k = this->index(args...);
        return (*this)[k];
      }


      // negative indexing 

      template <typename... U>
      Element& operator()(const U... args) requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value)) {
        Indices inds = Indices::from_signed({ args... }, dims());
        // OUTPUT("method 2");
        // ETV({ args... });
        // ETV(inds);
        return (*this)[inds];
      }

      template <typename... U>
      const Element& operator()(const U... args) const requires (std::conjunction< std::is_integral<U>...>::value&& std::conjunction<std::is_signed<U>...>::value && (sizeof...(args) == rank_value)) {
        Indices inds = Indices::from_signed({ args... }, dims());
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

      template <size_t... sizes> requires (multi_array_compatibility<rank_value, rank_value, dim_ints..., sizes...>())
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
          }
          else {
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
        std::string s = "MultiArray";
        s += StyledString::get(ANGLE1).get();
        Element d;
        s += getTypeName(d);
        s += StyledString::get(COMMA).get();
        s += " rank=";
        s += std::to_string(rank_value);
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
