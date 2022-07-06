#ifndef MATHQ__SCALAR_H
#define MATHQ__SCALAR_H 1

namespace mathq {

  /******************************************************************************
   * Scalar<Element> == MultiArray<Element>
   *
   *                 Element  = type for elements
   *
   *                 NumberType = number type
   *                   = underlying algebraic field
   *                     ex. int, double, std::complex<double>
   *                 depth = tensor depth. if Element=NumberType, then depth=1.
  *********************************************************************************
   */



  template <typename Element>
  class ScalarHelper {
  public:
    constexpr static size_t rank_value = 0;
    constexpr static bool is_dynamic = false;
    constexpr static bool num_compile_time_elements = 1;


    using ConcreteType = Scalar<Element>;
    using DimensionsType = const FixedDims<>;

    // ---- same for all subtypes --------
    constexpr static size_t depth_value = 1 + NumberTrait<Element>::depth();
    using MyArrayType = typename ArrayTypeTrait<Element, num_compile_time_elements>::Type;
    using NestedDimensionsType = NestedDims<DimensionsType, ElementDimensionsType>;
    using ElementDimensionsType = typename std::conditional< (depth_value == 1), NullDims, Element::DimensionsType>::type;

    // ---- same for all subtypes --------
    using ParentType = MArrayExpRW<
      MultiArray<Element, rank_value>,  // Derived
      Element,  // Element
      typename NumberTrait<Element>::Type,  // Number
      depth_value,  // depth
      rank_value,  // rank
      DimensionsType,  // DimensionsT
    >;
  };



  template <class Element>
  class MultiArray<Element, 0> : public ScalarHelper<Element>::ParentType {

  public:

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using Helper = ScalarHelper<Element>;

    // ---- same for all subtypes --------
    using ConcreteType = typename Helper::ConcreteType;
    using MyArrayType = Helper::MyArrayType;
    using DimensionsType = typename Helper::DimensionsType;
    using ElementDimensionsType = typename Helper::ElementDimensionsType;
    using NestedDimensionsType = typename Helper::NestedDimensionsType;
    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;


    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = Helper::rank_value;
    constexpr static size_t depth_value = Helper::depth_value;
    constexpr static size_t template_dimensions_value = DimensionsType;

    constexpr static bool is_dynamic() noexcept {
      return Helper::is_dynamic;
    }


    //**********************************************************************
    // OBJECT DATA 
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    //**********************************************************************
  private:
    Element data;


  public:


    //**********************************************************************
    //                            CONSTRUCTORS 
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: zero --------------------
    Scalar<Element>() {
      if constexpr (depth==1) {
        *this = 0;
      }
      else {
        data = *(new Element());
      }
      constructorHelper();
    }

    // --------------------- constant Element CONSTRUCTOR ---------------------

    Scalar<Element>(const Element e) {

      *this = e;
      constructorHelper();
    }

    // --------------------- constant NumberType CONSTRUCTOR ---------------------

    template<int D1 = depth, EnableIf<(D1>1)> = 0>

    Scalar<Element>(const NumberType d) {

      *this = d;
      constructorHelper();
    }

    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class X>
    Scalar<Element>(const MArrayExpR<X, Element, NumberType, depth, rank_value>& x) {

      *this = x;
      constructorHelper();
    }


    // CONSTRUCTOR: initializer_list 
    Scalar<Element>(const std::initializer_list<Element>& mylist) {
      *this = mylist;
      constructorHelper();
    }


    // --------------------- constructorHelper() --------------------

    void constructorHelper() {
      //add to MultiArrayPool
    }


    //**********************************************************************
    //                             DESTRUCTOR 
    //**********************************************************************

    ~Scalar<Element>() {
    }


    //**********************************************************************
    //                         Basis characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return false;
    }
    MultiArrays getEnum(void) const {
      return T_SCALAR;
    }
    VectorofPtrs getAddresses(void) const {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }


    //**********************************************************************
    //                            Size related  
    //**********************************************************************

    size_t getRank(void) const {
      return rank_value;
    }
    inline size_t depth(void) const {
      return depth_value;
    }
    inline size_t size(void) const {
      return 1;
    }

    DimensionsType& dims(void) const {
      return template_dims();
    }
    const DimensionsType& template_dims(void) const {
      return template_dimensions_value;
    }


    //**********************************************************************
    //                    Element Size related  
    //**********************************************************************

    inline size_t element_size(void) const {
      if constexpr (depth<2) {
        return 1;
      }
      else {
        return data.size();
      }
    }
    Dimensions element_dims(void) const {
      if constexpr (depth>1) {
        return data.dims();
      }
      else {
        return *(new FixedDims<>);
      }
    }
    inline size_t element_size(void) const {
      if constexpr (depth<2) {
        return 1;
      }
      else {
        return data.size();
      }
    }
    inline size_t eldeepsize(void) const {
      if constexpr (depth<2) {
        return 1;
      }
      else {
        return data.deepsize();
      }
    }



    //**********************************************************************
    //                       Nested Size related  
    //**********************************************************************

    size_t deepsize(void) const {
      if constexpr (depth<2) {
        return this->size();
      }
      else {
        return (this->size())*(this->eldeepsize());
      }
    }
    std::vector<Dimensions>& deepdims(void) const {
      std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
      return deepdims(ddims);
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      parentdims.push_back(dims());
      if constexpr (depth>1) {
        data.deepdims(parentdims);
      }
      return parentdims;
    }



    //**********************************************************************
    //                        Text Related
    //**********************************************************************

    inline std::string classname() const {
      using namespace display;
      std::string s = "Scalar";
      s += StyledString::get(ANGLE1).get();
      Element e;
      s += getTypeName(e);
      //if (depth>1) {
      //  s += StyledString::get(COMMA).get();
      //  s += "depth=";
      //  s += num2string(depth);
      //}
      s += StyledString::get(ANGLE2).get();
      return s;
    }


    // stream << operator

    friend std::ostream& operator<<(std::ostream& stream, const Scalar<Element>& s) {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      dispval_strm(stream, s());
      stream << style.apply(FormatDataVector::string_closing);

      return stream;
    }


    //template <typename NumberType>	
    friend inline std::istream& operator>>(const std::string s, Scalar<Element>& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream, Scalar<Element>& x) {
      return stream;
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
  }
#endif


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************

    // -------------------- NumberType dat(n) --------------------
    // NOTE: indexes over [0] to [deepsize()]
    // -------------------------------------------------------------

    // "read/write": unsigned
    NumberType& dat(const size_t n) {
      if constexpr (depth <= 1) {
        return data;
      }
      else {
        return (data).dat(n);
      }
    }

    // "read/write": signed
    const NumberType& dat(const size_t n)  const {
      if constexpr (depth <= 1) {
        return data;
      }
      else {
        return (data).dat(n);
      }
    }

    // -------------------- auto x.dat(DeepIndices) --------------------
    // -------------------------------------------------------------

    // "read/write": DeepIndices
    NumberType& dat(const DeepIndices& dinds) {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (depth>1) {
        return (*this)().dat(dinds);
      }
      else {
        return (*this)();
      }
    }

    // "read": DeepIndices
    const NumberType dat(const DeepIndices& dinds)  const {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (depth>1) {
        return (*this)().dat(dinds);
      }
      else {
        return (*this)();
      }
    }


    // -------------------- auto x.dat(Indices) --------------------
    // -------------------------------------------------------------

    // "read/write": Indices
    NumberType& dat(const Indices& inds) {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (depth>1) {
        return (*this)().dat(inds);
      }
      else {
        return (*this)();
      }
    }

    // "read": Indices
    const NumberType dat(const Indices& inds)  const {
      // error if (inds.size() != sum deepdims[i].rank
      if constexpr (depth>1) {
        return (*this)().dat(inds);
      }
      else {
        return (*this)();
      }
    }




    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************

    // "read/write": unsigned
    Element& operator[]() {
      return data;
    }

    // "read/write": signed
    const Element& operator[]()  const {
      return data;
    }

    // "read/write": unsigned
    Element& operator[](const size_t n) {
      return data;
    }

    // "read/write": signed
    const Element& operator[](const size_t n)  const {
      return data;
    }


    //**********************************************************************
    //***************** Element ACCESS as a tensor *************************
    //**********************************************************************



    // "read/write"
    Element& operator()() {
      return data;
    }

    // "read only"
    const Element& operator()()  const {
      return data;
    }

    // "read/write": unsigned
    Element& operator()(const size_t n) {
      return data;
    }

    // "read/write": signed
    const Element& operator()(const size_t n)  const {
      return data;
    }




    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    Scalar<Element>& operator=(const Element e) {
      data = e;
      return *this;
    }

    template <int D1 = depth>
    typename std::enable_if<(D1>1), Scalar<Element>& >::type operator=(const NumberType& d) {
      for (size_t i = 0; i < deepsize(); i++) {
        (*this).dat(i) = d;
      }
      return *this;
    }


    Scalar<Element>& operator=(const Scalar<Element>& s2) {
      if constexpr (depth<=1) {
        data = s2();
      }
      else {
        resize(s2.deepdims());
        for (size_t i = 0; i < deepsize(); i++) {
          (*this).dat(i) = s2.dat(i);
        }
      }
      return *this;
    }


    Scalar<Element>& operator=(const std::initializer_list<Element>& mylist) {
      typename std::initializer_list<Element>::iterator it = mylist.begin();
      data = *it;
      return *this;
    }


    template <class X>
    Scalar<Element>& operator=(const MArrayExpR<X, Element, NumberType, depth, rank_value>& x) {
      if constexpr (depth<=1) {
        data = x[0];
      }
      else {
        resize(x.deepdims());
        for (size_t i = 0; i < deepsize(); i++) {
          this->dat(i) = x.dat(i);
        }
      }
      return *this;
    }



    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place


    Scalar<Element>& roundzero(OrderedNumberType tolerance = Functions<OrderedNumberType>::tolerance) {
      data = mathq::roundzero(data, tolerance);
      return *this;
    }

    //----------------- .conj() ---------------------------
    // NOTE: in-place. Don't allow if not complex.
    //----------------------------------------------------
    template< typename T = NumberType >
    typename std::enable_if<is_complex<T>{}, Scalar<T>& >::type conj() {
      using std::conj;
      data = conj(data);
      return *this;
    }

};


};


#endif 

