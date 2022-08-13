#ifndef MATHQ__EXPRESSIONR
#define MATHQ__EXPRESSIONR



namespace mathq {


  //---------------------------------------------------------------------------
  // ExpressionR  Helper functions
  //---------------------------------------------------------------------------

  template <class A, class B, typename E1, typename E2, typename NT1, typename NT2, size_t depth, size_t rank>
  bool equiv_dims(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2) {
    return equiv(x1.dims(), x2.dims());
  }

  template <class A, class B, typename E1, typename E2, typename NT1, typename NT2, size_t depth, size_t rank>
  bool common(const ExpressionR<A, E1, NT1, depth, rank>& x1, const ExpressionR<B, E2, NT2, depth, rank>& x2) {
    // PRINTF3("in common");
    return common(x1.getAddresses(), x2.getAddresses());
  }






  // --------------------------------------------------------------------------------------------------
  //
  // ExpressionR 
  //
  // Abstract class that represents either a MultiArray or a MultiArray expression that is "read only"
  // --------------------------------------------------------------------------------------------------

  template <class Derived, typename Element, typename Num, size_t depth_, size_t rank_>
  class ExpressionR {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = depth_;

    // the size of an expression cannot be changed
    constexpr static bool is_dynamic_value = false;

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ParentType = NullType;
    using Type = ExpressionR<Derived, Element, Num, depth_value, rank_value>;
    using ConcreteType = MultiArray<Element, rank_value>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using SimpleNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using DimensionsType = Dimensions;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;



    //**********************************************************************
    //                Access to this object as its derived class
    //**********************************************************************

    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const  Derived& derived() const {
      return static_cast<const Derived&>(*this);
    }

    //**********************************************************************
    //                         Basic characteristics
    //**********************************************************************

    bool isExpression(void) const {
      return derived().isExpression();
    }

    // #if MATHQ_DEBUG>=1
    //     std::string expression(void) const {
    //       return derived().expression();
    //     }
    // #else
    //     std::string expression(void) const {
    //       return "";
    //     }
    // #endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
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

    size_t size(void) const {
      return derived().size();
    }

    size_t total_size(void) const {
      return derived().total_size();
    }

    size_t element_size(void) const {
      return derived().element_size();
    }

    size_t el_total_size(void) const {
      return derived().el_total_size();
    }


    //**********************************************************************
    //                        Dimensions
    //**********************************************************************

    DimensionsType& dims(void) const {
      return derived().dims();
    }

    ElementDimensionsType& element_dims(void) const {
      return derived().element_dims();
    }

    RecursiveDimensions& recursive_dims(void) const {
      return derived().recursive_dims();
    }

    // template <size_t full_depth>
    // const Type& recurse_dims(RecursiveDimensions<full_depth>& parent_rdims, const size_t di = 0) const {
    //   derived().recurse_dims(parent_rdims, di);
    //   return this;
    // }

    // //**********************************************************************
    // //************************** A[Indices] ***********************************
    // //**********************************************************************

    // // ---------------- A[Indices]--------------
    // Element& operator[](const Indices& inds) {
    //   return derived()[inds];
    // }
    // const Element operator[](const Indices& inds) const {
    //   return derived()[inds];
    // }


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Num dat(const size_t i) const {
      return derived().dat(i);
    }

    //**********************************************************************
    //***************** Element ACCESS *************************************
    //**********************************************************************

    const Element operator[](const size_t i) const {
      return derived()[i];
    }

    const Element operator[](const Indices& inds) const {
      return (*this)[inds.index(dims())];
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline const std::string expression_name() const {
      return std::string("ExpressionR::") + derived().classname();
    }

    inline const std::string classname() const {
      ConcreteType temp;
      return temp.classname();
    }


    friend std::ostream& operator<<(std::ostream& stream, const ExpressionR<Derived, Element, Num, depth_value, rank_value>& expression) {
      ConcreteType temp;
      temp = expression;
      stream << temp;
      return stream;
    };

  };




};
#endif
