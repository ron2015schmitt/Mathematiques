#ifndef MATHQ__MULTI_ARRAY_EXPRESSIONS_H
#define MATHQ__MULTI_ARRAY_EXPRESSIONS_H



namespace mathq {


  // template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank, class DT1, class DT2>
  // bool dimequiv(const ExpressionR<A, E1, NT1, depth, rank, DT1>& x1, const ExpressionR<B, E2, NT2, depth, rank, DT2>& x2) {
  //   return equiv(x1.dims(), x2.dims());
  // }

  // template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank, class DT1, class DT2>
  // bool common(const ExpressionR<A, E1, NT1, depth, rank, DT1>& x1, const ExpressionR<B, E2, NT2, depth, rank, DT2>& x2) {
  //   // PRINTF3("in common");
  //   return common(x1.getAddresses(), x2.getAddresses());
  // }




  // --------------------------------------------------------------------------------------------------
  //
  // ExpressionR 
  //
  // Abstract class that represents either a MultiArray or a MultiArray expression that is "read only"
  // --------------------------------------------------------------------------------------------------

  template <class Derived, typename Element, typename Number, size_t depth_, size_t rank_, size_t... ints>
  class ExpressionR {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = depth_;
    constexpr static std::array<size_t, rank_value> static_dims_array = { (static_cast<size_t>(ints))... };

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    using ParentType = NullType;
    using Type = ExpressionR<Derived, Element, Number, depth_value, rank_value, ints...>;
    using ConcreteType = Materialize<Element, rank_value, ints...>;

    using ElementType = Element;
    using NumberType = typename NumberTrait<Element>::Type;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using DimensionsType = Dimensions<rank_value>;
    using ElementDimensionsType = typename DimensionsTrait<Element>::Type;


    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    // the size of an expression cannot be changed
    constexpr static bool is_dynamic() noexcept {
      return false;
    }

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

    const Dimensions<rank_value>& dims(void) const {
      return derived().dims();
    }

    ElementDimensionsType& element_dims(void) const {
      return derived().element_dims();
    }

    const RecursiveDimensions<depth_value>& recursive_dims(void) const {
      return derived().recursive_dims();
    }

    template <size_t full_depth>
    const Type& recurse_dims(RecursiveDimensions<full_depth>& parent_rdims, const size_t di = 0) const {
      return derived().recurse_dims(parent_rdims, di);
    }


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Number dat(const size_t i) const {
      return derived().dat(i);
    }

    //**********************************************************************
    //***************** Element ACCESS *************************************
    //**********************************************************************

    const Element operator[](const size_t i) const {
      return derived()[i];
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      MultiArray<Element, rank> t;
      return t.classname();
      // return derived().classname();
    }

    friend std::ostream& operator<<(std::ostream& stream, const ExpressionR<Derived, Element, Number, depth_value, rank_value>& te) {
      MultiArray<Element, rank> t;
      t = te;
      stream << "" +display::getTypeName(t)+" ";
      stream << t;
      return stream;
    };

  };




  // --------------------------------------------------------------------------------------------------
  //
  // ExpressionRW
  //
  // Abstract class that represents either a MultiArray or a MultiArray expression that is "read only"
  // --------------------------------------------------------------------------------------------------

  template <class Derived, typename Element, typename Number, size_t depth_, size_t rank_, size_t... ints>
  class ExpressionRW  : public ExpressionR<ExpressionRW<Derived, Element, Number, depth_, rank_, ints...>, Element, Number, depth_, rank_, ints...> {
  public:

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank_;
    constexpr static size_t depth_value = depth_;
    constexpr static std::array<size_t, rank_value> static_dims_array = { (static_cast<size_t>(ints))... };


  };

      //**********************************************************************
      //                            TYPES 
      //**********************************************************************

  //     typedef Materialize<Element, rank, DimensionsT> ConcreteType;

  //     using ElementType = Element;
  //     using NumberType = Number;
  //     using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

  //     using DimensionsType = DimensionsT;
  //     using ElementDimensionsType = typename std::conditional< (depth_value == 1), NullDims, typename Element::DimensionsType>::type;
  //     using NestedDimensionsType = RecursiveDimensions<DimensionsType, ElementDimensionsType>;

  //     using MyArrayType = Element;

  //     //**********************************************************************
  //     //                  Compile Time Constant
  //     //**********************************************************************

  //     // the size of an expression cannot be changed
  //     constexpr static bool is_dynamic() noexcept {
  //       return false;
  //     }

  //     Derived& derived() {
  //       return static_cast<Derived&>(*this);
  //     }
  //     const Derived& derived() const {
  //       return static_cast<const Derived&>(*this);
  //     }


  //     //**********************************************************************
  //     //************************** DEEP ACCESS *******************************
  //     //**********************************************************************
  //     const Number dat(const size_t i) const {
  //       return derived().dat(i);
  //     }
  //     Number& dat(const size_t i) {
  //       return derived().dat(i);
  //     }

  //     //**********************************************************************
  //     //***************** Element ACCESS as an array *************************
  //     //**********************************************************************
  //     const Element operator[](const size_t i) const {
  //       return derived()[i];
  //     }
  //     Element& operator[](const size_t i) {
  //       return derived()[i];
  //     }



  //     size_t size(void) const {
  //       return derived().size();
  //     }

  //     size_t getRank(void) const {
  //       return derived().rank();
  //     }

  //     const DimensionsType& dims(void) const {
  //       return derived().dims();
  //     }
  //     const NestedDimensionsType& recursive_dims(void) const {
  //       return derived().recursive_dims();
  //     }
  //     // NestedDimensionsType& recursive_dims(std::vector<Dimensions>& parentdims) const {
  //     //   return derived().recursive_dims(parentdims);
  //     // }
  //     bool isExpression(void) const {
  //       return derived().isExpression();
  //     }
  //     ElementDimensionsType element_dims(void) const {
  //       return derived().element_dims();
  //     }

  //     size_t element_size(void) const {
  //       return derived().element_size();
  //     }
  //     size_t el_total_size(void) const {
  //       return derived().el_total_size();
  //     }
  //     size_t total_size(void) const {
  //       return derived().total_size();
  //     }


  // #if MATHQ_DEBUG>=1
  //     std::string expression(void) const {
  //       return derived().expression();
  //     }
  // #else
  //     std::string expression(void) const {
  //       return "";
  //     }
  // #endif
  //     VectorofPtrs getAddresses(void) const {
  //       return derived().getAddresses();
  //     }


  //     std::string classname() const {
  //       return derived().classname();
  //     }

  //     friend std::ostream& operator<<(std::ostream& stream, const ExpressionR<Derived, Element, Number, depth, rank, DimensionsT>& te) {
  //       const Derived& td = te.derived();
  //       if (td.isExpression()) {
  //         return printMultiArrayExpression(stream, te);
  //       }
  //       else {
  //         stream << te.derived();
  //         return stream;
  //       }
  //     }


  //     // Assign to constant value
  //     Derived& equals(const Element e) {
  //       for (size_t i = 0; i<size(); i++)
  //         (*this)[i] = e;
  //       return derived();
  //     }



  //     // assign to vector or expression
  //     template <class Y, class DT2>
  //     Derived& equals(const ExpressionR<Y, Element, Number, depth, rank, DT2>& rhs) {

  //       const size_t N = size();


  //       if (common(*this, rhs)) {
  //         // if a vector appears on both the right hand and left hand side,
  //         // we need to make a copy of the rhs first
  //         Vector<Number> y(N);

  //         for (size_t i = 0; i<N; i++)
  //           y[i] = rhs[i];
  //         for (size_t i = 0; i<N; i++)
  //           derived()[i] = y[i];
  //       }
  //       else {
  //         for (size_t i = 0; i<N; i++)
  //           derived()[i] = rhs[i];
  //       }
  //       return derived();
  //     }



  //   };


};
#endif
