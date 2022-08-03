#ifndef MATHQ__EXPRESSIONRW
#define MATHQ__EXPRESSIONRW



namespace mathq {




  // --------------------------------------------------------------------------------------------------
  //
  // ExpressionRW
  //
  // Abstract class that represents either a MultiArray or a MultiArray expression that is "read only"
  // --------------------------------------------------------------------------------------------------

  template <class Derived, typename Element, typename Number, size_t depth_, size_t rank_>
  class ExpressionRW : public ExpressionR<ExpressionRW<Derived, Element, Number, depth_, rank_>, Element, Number, depth_, rank_> {
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
    using Type = ExpressionRW<Derived, Element, Number, depth_value, rank_value>;
    using ConcreteType = MultiArray<Element, rank_value>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

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


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Number dat(const size_t i) const {
      return derived().dat(i);
    }

    Number& dat(const size_t i) {
      return derived().dat(i);
    }

    // **********************************************************************
    // ***************** Element ACCESS *************************************
    // **********************************************************************

    const Element operator[](const size_t i) const {
      return derived()[i];
    }

    Element& operator[](const size_t i) {
      return derived()[i];
    }

    const Element operator[](const Indices& inds) const {
      return (*this)[inds.index(dims())];
    }

    Element& operator[](const Indices& inds) {
      return (*this)[inds.index(dims())];
    }


    // **********************************************************************
    // ***************** Assignment *************************************
    // **********************************************************************

    // Assign to constant value
    Derived& equals(const Element e) {
      for (size_t i = 0; i<size(); i++)
        (*this)[i] = e;
      return derived();
    }


    // assign to vector or expression
    template <class Y, size_t... ints2>
    Derived& equals(const ExpressionR<Y, Element, Number, depth_, rank_>& rhs) {
      const size_t N = size();

      if (common(*this, rhs)) {
        // if a vector appears on both the right hand and left hand side,
        // we need to make a copy of the rhs first
        Vector<Number> y(N);
        for (size_t i = 0; i<N; i++) {
          y[i] = rhs[i];
        }
        for (size_t i = 0; i<N; i++) {
          derived()[i] = y[i];
        }
      }
      else {
        for (size_t i = 0; i<N; i++) {
          derived()[i] = rhs[i];
        }
      }
      return derived();
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline const std::string expression_name() const {
      return std::string("ExpressionRW::") + derived().classname();
    }

    inline const std::string classname() const {
      ConcreteType temp;
      return temp.classname();
    }


    friend std::ostream& operator<<(std::ostream& stream, const ExpressionRW<Derived, Element, Number, depth_value, rank_value>& expression) {
      ConcreteType temp;
      temp = expression;
      stream << temp;
      return stream;
    };


  };


};
#endif
