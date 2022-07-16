#ifndef MATHQ__MULTI_ARRAY_FIXED
#define MATHQ__MULTI_ARRAY_FIXED 1

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
  class MultiArray :public ExpressionRW<
    MultiArray<Element, rank_, dim_ints...>,  // Derived
    Element,  // Element
    typename NumberTrait<Element>::Type, // Number
    1 + NumberTrait<Element>::depth(),  // depth
    rank_  // rank
  > {


  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();    // constexpr static size_t static_dims_array = DimensionsType;
    constexpr static bool is_dynamic_value = false;
    constexpr static size_t compile_time_size = calc_size<rank_value, dim_ints...>();
    constexpr static std::array<size_t, rank_value> static_dims_array = { (static_cast<size_t>(dim_ints))... };

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Type = MultiArray<Element, rank_value, dim_ints...>;
    using ConcreteType = Type;

    constexpr static size_t rank_array = NumberTrait<Type>::rank_array();
    
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

    using DimensionsType = Dimensions<rank_value>;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;
    // using DeepDimensionsType = NumberTrait<Type>::rank_array()

    using MyArrayType = typename ArrayTypeTrait<Element, compile_time_size>::Type;


    // private:
      // *********************** OBJECT DATA ***********************************
      //
      // do NOT declare any other storage.
      // keep the instances lightweight
    MyArrayType data_;

  public:



    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************

    // --------------------- default CONSTRUCTOR ---------------------

    explicit MultiArray() {
    }





    // old----------------------
        // --------------------- constant=0 CONSTRUCTOR ---------------------

        // explicit MultiArray(const Dimensions& dims)   {
        // }

        // // --------------------- constant Element CONSTRUCTOR ---------------------

        // explicit MultiArray(const Dimensions& dims, const Element& e)   {
        //   resize(dims);
        //   constructorHelper();
        //   *this = e;
        // }

        // // --------------------- constant Element CONSTRUCTOR ---------------------

        // template <size_t D1 = depth, EnableIf<(D1 > 0)> = 0>

        //   explicit MultiArray(const Dimensions& dims, const NumberType d)   {
        //   resize(dims);
        //   constructorHelper();
        //   *this = d;
        // }

        // // ************* C++11 initializer_list CONSTRUCTOR---------------------
        // MultiArray(const NestedInitializerList<Element, rank>& mylist)   {
        //   *this = mylist;
        //   constructorHelper();
        // }

        // // ************* Expression CONSTRUCTOR---------------------

        // template <class X>
        // MultiArray(const ExpressionR<X, Element, NumberType, depth, rank>& x)   {
        //   *this = x;
        //   constructorHelper();
        // }


        // // ************* Vector Constructor---------------------
        // template <int NE>
        // MultiArray(const Vector<Element, NE>& v)   {
        //   resize(v.recursive_dims());
        //   for (int c = 0; c < v.total_size(); c++) {
        //     (*this)[c] = v[c];
        //   }
        //   constructorHelper();
        // }


        // --------------------- constructorHelper() --------------------

    void constructorHelper() {
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
      size_t Ntotal = size_true();
      TRDISP(Ntotal);
      if constexpr (is_dynamic_value) {
        if (rank_value <= Ntotal) {
          return Ntotal - rank_value;
        }
        else {
          return 0;
        }
      }
      else {
        return data_.size();
      }
    }

    inline size_t size_true(void) const {
      return data_.size();
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
          return data_[0].size();
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
          return data_[0].total_size();
        }
        else {
          Element& x = *(new Element);
          return x.total_size();
        }
      }
    }



    // resize_depth <= depth_value
    template <size_t resize_depth>
    Type& resize(const RecursiveDimensions<resize_depth>& new_rdims) {
      return recurse_resize(new_rdims, 0);
    }

    // helper functions
    template <size_t resize_depth>
    Type& recurse_resize(const RecursiveDimensions<resize_depth>& parent_rdims, const size_t di = 0) {
      size_t depth_index = di;
      // const size_t newSize = parent_rdims[depth_index++];
      // if constexpr (is_dynamic_value) {
      //   resize(newSize);
      // }
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
    //                        Dimensions
    //**********************************************************************

    // defined later since Dimensions is dependent on Vector
    Dimensions<rank_value>& dims(void) const {
      const size_t N = this->size();

      return *(new Dimensions<rank_value>({ this->size() }));
    }


    inline std::array<size_t, rank_value> dims_array(void) const {
        return static_dims_array;
    }

    ElementDimensionsType& element_dims(void) const {
      if constexpr (depth_value>1) {
        if (this->size()>0) {
          return data_[0].dims();
        }
        else {
          Element& x = *(new Element);
          return x.dims();
        }
      }
      return *(new ElementDimensionsType{});
    }


    RecursiveDimensions<depth_value>& recursive_dims(void) const {
      RecursiveDimensions<depth_value>& rdims = *(new RecursiveDimensions<depth_value>);
      recurse_dims(rdims, 0);
      return rdims;
    }

    template <size_t full_depth>
    const Type& recurse_dims(RecursiveDimensions<full_depth>& parent_rdims, const size_t di = 0) const {
      size_t depth_index = di;
      parent_rdims[depth_index++] = dims();
      if constexpr (depth_value>1) {
        if (size()>0) {
          data_[0].recurse_dims(parent_rdims, depth_index);
        }
        else {
          Element& x = *(new Element);
          x.recurse_dims(parent_rdims, depth_index);
        }
      }
      return *this;
    }




    //**********************************************************************
    //********************* Direct access to data_  ***********************************
    //**********************************************************************

    // -------------------- dataobj() --------------------
    // "read/write" to the wrapped valarray/aray
    auto& dataobj() {
      return data_;
    }

    // get C pointer to raw data
    // https://stackoverflow.com/questions/66072510/why-is-there-no-stddata-overload-for-stdvalarray
    Element* data() {
      // MutltiArrays are always wrap avalarray<Element>
      return &(data_[0]);
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    // NOTE: indexes over [0] to [total_size()] and note return type

    // // "read/write"
    // NumberType& dat(const size_t n) {
    //   using namespace ::display;
    //   //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
    //   if constexpr (depth < 2) {
    //     int k = n;
    //     if (k < 0) {
    //       k += size();
    //     }
    //     return data_[k];
    //   }
    //   else {
    //     const int Ndeep = this->el_total_size();
    //     const int j = n / Ndeep;
    //     const int k = n % Ndeep;
    //     return data_[j].dat(k);
    //   }
    // }

    // // read
    // const NumberType& dat(const size_t n) const {
    //   using namespace ::display;
    //   //    MOUT << CREATESTYLE(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
    //   if constexpr (depth < 2) {
    //     int k = n;
    //     if (k < 0) {
    //       k += size();
    //     }
    //     return data_[k];
    //   }
    //   else {
    //     const int Ndeep = this->el_total_size();
    //     const int j = n / Ndeep;
    //     const int k = n % Ndeep;
    //     return data_[j].dat(k);
    //   }
    // }

    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------

    // // "read/write": x.dat(Indices)
    // NumberType& dat(const Indices& inds) {
    //   // printf("MultiArray.dat(Indices)\n");
    //   // MOUT << "  ";
    //   // TLDISP(inds.size());
    //   // MOUT << "  ";
    //   // TLDISP(inds);
    //   // MOUT << "  ";
    //   // TLDISP(rank());
    //   Indices inds_next(inds);
    //   // error if (inds.size() != sum recursive_dims[i].rank
    //   Indices mine;
    //   for (int i = 0; i < rank(); i++) {
    //     mine.push_back(inds_next[0]);
    //     inds_next.erase(inds_next.begin());
    //   }
    //   // MOUT << "  ";
    //   // TLDISP(mine);
    //   // MOUT << "  ";
    //   // TLDISP(inds_next);
    //   if constexpr (depth > 1) {
    //     return (*this)(mine).dat(inds_next);
    //   }
    //   else {
    //     return (*this)(mine);
    //   }
    // }

    // // "read": x.dat(Indices)
    // const NumberType dat(const Indices& inds) const {
    //   // printf("MultiArray.dat(Indices) const\n");
    //   // MOUT << "  ";
    //   // TLDISP(inds.size());
    //   // MOUT << "  ";
    //   // TLDISP(inds);
    //   // MOUT << "  ";
    //   // TLDISP(rank());
    //   Indices inds_next(inds);
    //   // error if (inds.size() != sum recursive_dims[i].rank
    //   Indices mine;
    //   for (int i = 0; i < rank(); i++) {
    //     mine.push_back(inds_next[0]);
    //     inds_next.erase(inds_next.begin());
    //   }
    //   // MOUT << "  ";
    //   // TLDISP(mine);
    //   // MOUT << "  ";
    //   // TLDISP(inds_next);
    //   if constexpr (depth > 1) {
    //     return (*this)(mine).dat(inds_next);
    //   }
    //   else {
    //     return (*this)(mine);
    //   }
    // }

    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------

    // // "read/write": x.dat(DeepIndices)
    // NumberType& dat(const DeepIndices& dinds) {
    //   const size_t mydepth = dinds.size();
    //   const Indices& inds = dinds[mydepth  - depth];

    //   if constexpr (depth > 1) {
    //     return (*this)(inds).dat(dinds);
    //   }
    //   else {
    //     return (*this)(inds);
    //   }
    // }

    // // "read": x.dat(DeepIndices)
    // const NumberType dat(const DeepIndices& dinds) const {
    //   const size_t mydepth = dinds.size();
    //   const Indices& inds = dinds[mydepth  - depth];

    //   if constexpr (depth > 1) {
    //     return (*this)(inds).dat(dinds);
    //   }
    //   else {
    //     return (*this)(inds);
    //   }
    // }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    // // "read/write"
    // Element& operator[](const size_t n) {
    //   int k = n;
    //   if (k < 0) {
    //     k += size();
    //   }
    //   return data_[k];
    // }

    // // read
    // const Element& operator[](const size_t n) const {
    //   int k = n;
    //   if (k < 0) {
    //     k += size();
    //   }
    //   return data_[k];
    // }

    //**********************************************************************
    //*******MultiArray-style Element Access: A(i,j,k,...) *********************
    //**********************************************************************

    // size_t indexOf(const Indices& inds) const {
    //   return dimensions_->index(inds);
    // }

    /* template<typename... Ts> size_t index(int i, const Ts... args){ */
    /* const int size = sizeof...(args); */
    /* int argarray[size] = {args...}; */
    /*   Indices& inds = *(new Indices(rank())); */
    /*   const size_t depth = this->rank(); */
    /*   inds[0] = i;  */
    /*   for(size_t n = 1; n < depth; n++) { */
    /* 	inds[n] = argarray[n];  */
    /*   } */
    /*   size_t k = this->index(inds); */
    /*   return k; */
    /* } */

    // template <typename... U>
    // typename std::enable_if<std::conjunction<std::is_convertible<U, size_t>...>::value, size_t>::type index(const U... args) {

    //   const size_t size = sizeof...(args);
    //   size_t argarray[size] = { std::make_unsigned<int>::type(args)... };
    //   Indices& inds = *(new Indices(rank()));
    //   const size_t NN = this->rank();
    //   for (size_t n = 0; n < NN; n++) {
    //     inds[n] = argarray[n];
    //   }
    //   size_t k = this->indexOf(inds);
    //   return k;
    // }

    // size_t index(const std::initializer_list<size_t>& mylist) const {
    //   // TODO: check size
    //   const size_t NN = this->rank();
    //   const size_t N = mylist.size();
    //   size_t k = 0;
    //   size_t n = 0;
    //   typename std::initializer_list<size_t>::iterator it;
    //   for (it = mylist.begin(); it != mylist.end(); ++it, n++) {
    //     size_t N = (*dimensions_)[n];
    //     size_t j = *it;
    //     k = N * k + j;
    //   }
    //   return k;
    // }

    // // indices - This is the inverse of the above function
    // // TODO: test this code
    // // TODO: bounds check on k

    // inline Indices& indices(const size_t k) const {
    //   return dimensions_->indices(k);
    // }

    // //**********************************************************************
    // //************************** ACCESS() ***********************************
    // //**********************************************************************

    // // ---------------- tensor(Indices)--------------
    // Element& operator()(const Indices& inds) {
    //   size_t k = this->indexOf(inds);
    //   return (*this)[k];
    // }
    // const Element operator()(const Indices& inds) const {
    //   size_t k = this->indexOf(inds);
    //   return (*this)[k];
    // }

    // // ---------------- tensor(i,j,...)--------------


    // template <typename... U>
    // typename std::enable_if<std::conjunction<std::is_convertible<U, size_t>...>::value, Element&>::type operator()(const U... args) {

    //   // const int size = sizeof...(args);
    //   // int argarray[size] = {args...};
    //   size_t k = this->index(args...);

    //   return (*this)[k];
    // }
    // template <typename... U>
    // typename std::enable_if<std::conjunction<std::is_convertible<U, size_t>...>::value, const Element>::type operator()(const U... args) const {
    //   return (*this)(args...);
    // }

    // // ---------------- tensor({i,j,...})--------------
    // Element& operator()(const std::initializer_list<size_t>& mylist) {
    //   size_t k = this->index(mylist);
    //   return (*this)[k];
    // }
    // const Element operator()(const std::initializer_list<size_t>& mylist) const {
    //   size_t k = this->index(mylist);
    //   return (*this)[k];
    // }

    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to ExpressionRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // // ----------------- tensor = e ----------------
    // MultiArray<Element, rank>&
    //   operator=(const Element e) {
    //   for (size_t i = size(); i--;)
    //     data_[i] = e;
    //   return *this;
    // }

    // // ----------------- tensor = d ----------------
    // template <class T = Element>
    // typename std::enable_if<!std::is_same<T, NumberType>::value, MultiArray<T, rank>&>::type operator=(const NumberType& d) {

    //   for (size_t i = 0; i < total_size(); i++) {
    //     data_.dat(i) = d;
    //   }
    //   return *this;
    // }

    // // ----------------- tensor = C++11 init list
    // MultiArray<Element, rank>& operator=(const NestedInitializerList<Element, rank>& mylist) {
    //   // MOUT << "operator=: ";
    //   // TLDISP(mylist);
    //   int i = 0;
    //   Dimensions dims = NestedInitializerListDef<Element, rank>::dims(mylist);
    //   resize(dims);
    //   NestedInitializerListDef<Element, rank>::compute(*this, mylist, i);
    //   return *this;
    // }

    // // ----------------- tensor = MultiArray<Element,rank,NumberType,depth> ----------------
    // template <int R1>
    // MultiArray<Element, rank>&
    //   operator=(const MultiArray<Element, R1>& x) {
    //   // TODO: issue warning
    //   // TRDISP(x);
    //   resize(x.dims());
    //   for (size_t i = size(); i--;) {
    //     data_[i] = x[i]; // Inlined expression
    //   }
    //   return *this;
    // }

    // // ----------------- tensor = ExpressionR<X,Element,NumberType,depth,rank> ----------------
    // template <class X>
    // MultiArray<Element, rank>&
    //   operator=(const ExpressionR<X, Element, NumberType, depth, rank>& x) {

    //   if constexpr (depth <= 1) {
    //     resize(x.dims());
    //     for (size_t i = 0; i < size(); i++) {
    //       (*this)[i] = x[i];
    //     }
    //   }
    //   else {
    //     resize(x.recursive_dims());
    //     for (size_t i = 0; i < total_size(); i++) {
    //       this->dat(i) = x.dat(i);
    //     }
    //   }
    //   return *this;
    // }

    // //*********************************************************
    // //                   1D assignment
    // //********************************************************

    // // ------------- tensor = array[] ----------------

    // MultiArray<Element, rank>&
    //   operator=(const Element array1[]) {
    //   for (size_t i = 0; i < size(); i++) {
    //     (*this)[i] = array1[i];
    //   }
    //   return *this;
    // }

    // //**********************************************************************
    // //************************** MATH **************************************
    // //**********************************************************************

    // //----------------- .roundzero(tol) ---------------------------
    // // NOTE: in-place

    // MultiArray<Element, rank>& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
    //   for (size_t i = size(); i--;) {
    //     data_[i] = mathq::roundzero(data_[i], tolerance);
    //   }
    //   return *this;
    // }

    // //----------------- .conj() ---------------------------
    // // NOTE: in-place

    // template <typename T = NumberType>
    // typename std::enable_if<is_complex<T>{}, MultiArray<T>&>::type conj() {
    //   for (size_t i = size(); i--;) {
    //     data_[i] = std::conj(data_[i]);
    //   }
    //   return *this;
    // }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "MultiArray";
      s += StyledString::get(ANGLE1).get();
      Element d;
      s += getTypeName(d);
      s += StyledString::get(COMMA).get();
      s += "rank=";
      s += num2string(rank_value);
      size_t product = 1;
      for (size_t ii = 0; ii < static_dims_array.size(); ii++) {
        product *= static_dims_array[ii];
      }
      if (product > 0) {
        for (size_t ii = 0; ii < static_dims_array.size(); ii++) {
          if (ii == 0) {
            s += StyledString::get(COMMA).get();
          }
          else {
            s += "⨯";
          }
          s += template_size_to_string(static_dims_array[ii]);
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

    // std::ostream& send(std::ostream& stream, size_t& n, const Dimensions& dim) const {
    //   using namespace display;
    //   Style& style = FormatDataVector::style_for_punctuation;
    //   //      MDISP(n,dim);
    //   const int delta = this->rank() - dim.rank();
    //   if (delta == 0) {
    //     stream << std::endl;
    //   }
    //   std::string indent = "";
    //   for (size_t j = 0; j < delta; j++) {
    //     indent += "  ";
    //   }
    //   stream << indent << style.apply("{");

    //   if (dim.rank() > 1) {
    //     stream << std::endl;
    //   }
    //   if (dim.rank() > 0) {
    //     Dimensions newdim(dim);
    //     newdim.erase(newdim.begin());
    //     for (size_t j = 0; j < dim[0]; j++) {
    //       if (dim.rank() > 1) {
    //         Dimensions newdim(dim);
    //         newdim.erase(newdim.begin());
    //         this->send(stream, n, newdim);
    //         if (j < dim[0] - 1) {
    //           stream << style.apply(",") << std::endl;
    //         }
    //       }
    //       else {
    //         dispval_strm(stream, (*this)[n++]);
    //         if (j < dim[0] - 1) {
    //           stream << style.apply(", ");
    //         }
    //       }
    //     }
    //   }
    //   if (dim.rank() == 1) {
    //     stream << style.apply("}");
    //   }
    //   else if (dim.rank() == this->rank()) {
    //     stream << std::endl
    //       << indent << style.apply("}");
    //   }
    //   else {
    //     stream << std::endl
    //       << indent << style.apply("}");
    //   }
    //   return stream;
    // }

    // stream << operator

    // TODO: implement format

    // friend std::ostream& operator<<(std::ostream& stream, const Type& t) {
    //   using namespace display;
    //   size_t n = 0;
    //   // t.send(stream, n, t.dims());
    //   return stream;
    // }

    // // template <typename NumberType>
    // friend inline std::istream& operator>>(const std::string s, Type& x) {
    //   std::istringstream st(s);
    //   return (st >> x);
    // }

  };

}; // namespace mathq

#endif
