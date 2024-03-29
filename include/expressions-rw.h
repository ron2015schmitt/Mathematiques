#ifndef MATHQ__EXPRESSIONSRW
#define MATHQ__EXPRESSIONSRW


namespace mathq {




  //---------------------------------------------------------------------------
  // ExpressionRW_Subset   Subset Expression
  //---------------------------------------------------------------------------
  template<typename Num>
  class ExpressionRW_Subset : public  ExpressionRW<ExpressionRW_Subset<Num>, Num, Num, 1, 1> {
  public:
    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 1;
    constexpr static size_t depth_value = 1;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Num;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionRW_Subset<NumberType>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;


  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    // can't be constant since we alow to be on left hand side
    Vector<Num>& x_;
    const Vector<size_t>& ii_;
    const bool delete_ii_;
    VectorofPtrs* vptrs;
  public:

    //**********************************************************************
    //                      Constructors
    //**********************************************************************
    typedef typename NumberTrait<Num>::Type MyNumberType;

    ExpressionRW_Subset(Vector<Num>& x, const Vector<size_t>& ii)
      : x_(x), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    ExpressionRW_Subset(Vector<Num>& x, const std::initializer_list<size_t>& list)
      : x_(x), ii_(*(new Vector<size_t>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }

    ~ExpressionRW_Subset() {
      if (delete_ii_) delete& ii_;
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************


    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************
    size_t rank(void) const {
      return x_.rank();
    }
    size_t depth(void) const {
      return depth_value;
    }
    size_t size(void) const {
      return ii_.size();
    }
    size_t total_size(void) const {
      if constexpr (depth_value<=1) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }
    size_t element_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************
    DimensionsType& dims(void) const {
      return x_.dims();
    }
    RecursiveDimensions& recursive_dims(void) const {
      return x_.recursive_dims();
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    const NumberType dat(const size_t i) const {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }
    NumberType& dat(const size_t i) {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const ElementType operator[](const size_t i) const {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_[ind];
    }
    ElementType& operator[](const size_t i) {
      size_t ind = ii_[i];
      if (ind < 0) {
        ind = x_.size() + ind;
      }
      return x_[ind];
    }

    //**********************************************************************
    //                        operator=
    //**********************************************************************

    template <class Y, class NT2>
    ExpressionRW_Subset<NumberType>& operator=(const ExpressionR<Y, NT2, NT2, depth_value, rank_value>& rhs) {
      return this->equals(rhs);
    }

    ExpressionRW_Subset<NumberType>& operator=(const NumberType d) {
      return this->equals(d);
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionRW_Subset";
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_ExpressionRW_Subset(a_.expression(),ii_.expression());
    }
#endif
  };




  //--------------------------------------------------------------------------
  // ExpressionRW_Submask   Submask Expression
  //--------------------------------------------------------------------------
  template<typename Num>
  class ExpressionRW_Submask : public  ExpressionRW<ExpressionRW_Submask<Num>, Num, Num, 1, 1> {
  public:
    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 1;
    constexpr static size_t depth_value = 1;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Num;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionRW_Submask<NumberType>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;


  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
    // can't be constant since we alow to be on left hand side
    Vector<NumberType>& x_;
    const Vector<size_t>& ii_;
    VectorofPtrs* vptrs;

  public:
    //**********************************************************************
    //                      Constructors
    //**********************************************************************

    ExpressionRW_Submask(Vector<NumberType>& x, const Vector<bool>& mask)
      : x_(x), ii_(*(new Vector<size_t>(findtrue(mask)))) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    ~ExpressionRW_Submask() {
      delete& ii_;
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************


    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************
    size_t rank(void) const {
      return x_.rank();
    }
    size_t depth(void) const {
      return depth_value;
    }
    size_t size(void) const {
      return ii_.size();
    }
    size_t total_size(void) const {
      if constexpr (depth_value<=1) {
        return this->size();
      }
      else {
        return (this->size())*(this->el_total_size());
      }
    }
    size_t element_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth_value<=1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }

    //**********************************************************************
    //                        Dimensions
    //**********************************************************************
    DimensionsType& dims(void) const {
      return x_.dims();
    }
    RecursiveDimensions& recursive_dims(void) const {
      return x_.recursive_dims();
    }



    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    const NumberType dat(const size_t i) const {
      size_t ind = ii_[i];
      return x_.dat(ind);
    }
    NumberType& dat(const size_t i) {
      size_t ind = ii_[i];
      return x_.dat(ind);
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************

    const ElementType operator[](const size_t i) const {
      size_t ind = ii_[i];
      return x_[ind];
    }
    ElementType& operator[](const size_t i) {
      size_t ind = ii_[i];
      return x_[ind];
    }

    //**********************************************************************
    //                        operator=
    //**********************************************************************

    template <class Y, class NT2>
    ExpressionRW_Submask<Num>& operator=(const ExpressionR<Y, NT2, NT2, depth_value, rank_value>& rhs) {
      return this->equals(rhs);
    }

    ExpressionRW_Submask<Num>& operator=(const Num d) {
      return this->equals(d);
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionRW_Submask";
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_ExpressionRW_Submask(a_.expression(),ii_.expression());
    }
#endif
  };



  //---------------------------------------------------------------------------
  // VERW_Join   joining two Vectors (RHS only)
  //---------------------------------------------------------------------------

  template <class X, class Y, class Element, typename Num, size_t depth_>
  class ExpressionRW_Join : public  ExpressionRW<ExpressionRW_Join<X, Y, Element, Num, depth_>, Element, Num, depth_, 1> {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = 1;
    constexpr static size_t depth_value = depth_;



    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ElementType = Element;
    using NumberType = typename NumberTrait<ElementType>::Type;
    using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using Type = ExpressionRW_Join<X, Y, Element, Num, depth_>;
    using ParentType = ExpressionR<Type, ElementType, NumberType, depth_value, rank_value>;
    using ConcreteType = MultiArray<ElementType, rank_value>;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<ElementType>::Type;

  private:
    //**********************************************************************
    // OBJECT DATA 
    //**********************************************************************
  // can't be constant since we alow to be on left hand side
    X& x_;
    Y& y_;
    VectorofPtrs* vptrs;

  public:
    //**********************************************************************
    //                      Constructors
    //**********************************************************************
    ExpressionRW_Join(X& x, Y& y) : x_(x), y_(y) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      vptrs->add(y_.getAddresses());
      // DISP3(x);
    }

    ~ExpressionRW_Join() {
      delete vptrs;
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************


    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }

    //**********************************************************************
    //                         Rank,Depth,Sizes
    //**********************************************************************
    size_t rank(void) const {
      return rank_value;
    }
    size_t depth(void) const {
      return depth;
    }
    size_t size(void) const {
      return x_.size()+y_.size();
    }
    size_t total_size(void) const {
      if constexpr (depth<=1) {
        return this->size();
      }
      else {
        return x_.total_size() + y_.total_size();
      }
    }
    size_t element_size(void) const {
      if constexpr (depth<=1) {
        return 1;
      }
      else {
        return x_.element_size();
      }
    }
    size_t el_total_size(void) const {
      if constexpr (depth<=1) {
        return 1;
      }
      else {
        return x_.el_total_size();
      }
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************
    DimensionsType& dims(void) const {
      DimensionsType& d = *(new DimensionsType(x_.size()+y_.size()));
      return d;
    }
    DimensionsType& element_dims(void) const {
      return x_.element_dims();
    }
    RecursiveDimensions& recursive_dims(void) const {
      RecursiveDimensions& rdims = *(new RecursiveDimensions);
      rdims = x_.recursive_dims();
      rdims[0] = dims();
      return rdims;
    }


    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************
    const Num dat(const size_t i) const {
      if (i < x_.total_size()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i-x_.total_size());
      }
    }
    Num& dat(const size_t i) {
      if (i < x_.total_size()) {
        return x_.dat(i);
      }
      else {
        return y_.dat(i-x_.total_size());
      }
    }

    //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const Element operator[](const size_t i) const {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i-x_.size()];
      }
    }
    Element& operator[](const size_t i) {
      if (i < x_.size()) {
        return x_[i];
      }
      else {
        return y_[i-x_.size()];
      }
    }

    //**********************************************************************
    //                        operator=
    //**********************************************************************

    template <class Z>
    ExpressionRW_Join<X, Y, Element, Num, depth_value>& operator=(const ExpressionR<Z, Element, Num, depth_value, 1>& rhs) {
      return this->equals(rhs);
    }

    ExpressionRW_Join<X, Y, Element, Num, depth_value>& operator=(const Num d) {
      return this->equals(d);
    }
    ExpressionRW_Join<X, Y, Element, Num, depth_value>& operator=(const Element& e) {
      return this->equals(e);
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    std::string expression_name() const {
      return "ExpressionRW_Join";
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return sx;
    }
#endif

  };


};
#endif 
