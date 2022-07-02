#ifndef MATHQ__MULTI_ARRAY_EXPRESSIONS_H
#define MATHQ__MULTI_ARRAY_EXPRESSIONS_H



namespace mathq {



  // -------------------------------------------------------------------
  //
  // MultiArrays enum - one enum for each actual MultiArray:
  //                Scalar, Vector, Matrix, etc. And then two expressions.
  //                return type of getEnum
  //
  // MultiArrayType struct - this returns the corresponding type for
  //                     a given enum, which allows to create a new
  //                     varieble that is of the same class as a variable
  //                     that was passed to the code
  //
  // NOTE: by combining this enum functionality with the dims() method,
  //       we can determine what type of tensor is returned by an expression
  //       and even create a new object of the same type!
  //       Another technique that can be used is the vistor design pattern,
  //       as described below.
  // -------------------------------------------------------------------

/// TODO: get this working or remove

  enum MultiArrayOrExpression : unsigned int { T_TENSOR_OBJ, T_TENSOR_EXP };


  enum MultiArrays : unsigned int { T_SCALAR, T_VECTOR, T_MATRIX, T_TENSOR, T_EXPRESSION_R, T_EXPRESSION_RW };





  template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
  bool dimequiv(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
    return equiv(x1.dims(), x2.dims());
  }

  template <class A, class B, class E1, class E2, class NT1, class NT2, int depth, int rank>
  bool common(const MArrayExpR<A, E1, NT1, depth, rank>& x1, const MArrayExpR<B, E2, NT2, depth, rank>& x2) {
    // PRINTF3("in common");
    return common(x1.getAddresses(), x2.getAddresses());
  }



  // -------------------------------------------------------------------
  //
  // printMultiArrayExpression
  //
  // Basically this is the vistor design pattern.
  // -------------------------------------------------------------------

/// TODO: get this working or remove


  template <class X, class Element, typename Number, int depth, int rank>
  std::ostream& printMultiArrayExpression(std::ostream& stream, const MArrayExpR<X, Element, Number, depth, rank>& te) {

    if constexpr (rank==0) {
      Scalar<Element> s;
      s = te;
      stream << "" +display::getTypeName(s)+" ";
      stream << s;
      return stream;
    }
    else
      if constexpr (rank==1) {
        Vector<Element> v;
        v = te;
        stream << "" +display::getTypeName(v)+" ";
        stream << v;
        return stream;
      }
      else
        if constexpr (rank==2) {
          Matrix<Element> m;
          m = te;
          stream << "" +display::getTypeName(m)+" ";
          stream << m;
          return stream;
        }
        else
          if constexpr (rank>=3) {
            MultiArray<Element, rank> t;
            t = te;
            stream << "" +display::getTypeName(t)+" ";
            stream << t;
            return stream;
          }
  }



  // -------------------------------------------------------------------
  //
  // MArrayExpR -- Abstract class that represents 
  //            either a tensor or a tensor expression that is "read only"
  // -------------------------------------------------------------------

  template <class Derived, typename Element, typename Number, size_t depth, size_t rank, class DimensionsT>
  class MArrayExpR {
  public:

    //**********************************************************************
    //                            TYPES 
    //**********************************************************************

    typedef Materialize<Element, Number> ConcreteType;

    using ElementType = Element;
    using NumberType = Number;
    using OrderedNumberType = typename SimpleNumberTrait<NumberType>::Type;

    using DimensionsType = DimensionsT;
    using ElementDimensionsType = typename std::conditional< (depth_value == 1), NullDims, Element::DimensionsType>::type;
    using NestedDimensionsType = NestedDims<DimensionsType, ElementDimensionsType>;

    using MyArrayType = Element;

    //**********************************************************************
    //                  Compile Time Constant
    //**********************************************************************

    constexpr static size_t rank_value = rank;
    constexpr static size_t depth_value = depth;
    constexpr static size_t template_dimensions_value = DimensionsType;

    // the size of an expression cannot be changed
    constexpr static bool is_dynamic() noexcept {
      return false;
    }

    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const  Derived& derived() const {
      return static_cast<const Derived&>(*this);
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Number dat(const size_t i) const {
      return derived().dat(i);
    }

    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************

    const Element operator[](const size_t i) const {
      return derived()[i];
    }



    size_t size(void) const {
      return derived().size();
    }

    size_t rank(void) const {
      return derived().rank();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return derived().deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return derived().deepdims(parentdims);
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    MultiArrays getEnum(void) const {
      // return T_EXPRESSION_R;
      return derived().getEnum();
    }
    size_t depth(void) const {
      return derived().depth();
    }
    Dimensions element_dims(void) const {
      return derived().element_dims();
    }

    size_t element_size(void) const {
      return derived().element_size();
    }
    size_t eldeepsize(void) const {
      return derived().eldeepsize();
    }
    size_t deepsize(void) const {
      return derived().deepsize();
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
    }
#else
    std::string expression(void) const {
      return "";
    }
#endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
    }


    inline std::string classname() const {
      return derived().classname();
    }

    friend std::ostream& operator<<(std::ostream& stream, const MArrayExpR<Derived, Element, Number, depth, rank>& te) {
      const Derived& td = te.derived();
      if (td.isExpression()) {
        return printMultiArrayExpression(stream, te);
      }
      else {
        stream << te.derived();
        return stream;
      }
    }

  };





  // -------------------------------------------------------------------
  //
  // MArrayExpRW -- Abstract class that represents 
  //             either a tensor or a tensor expression that can be
  //             both read and written
  // -------------------------------------------------------------------


  template <class Derived, class Element, typename Number, size_t depth, size_t rank, class DimensionsT> class
    MArrayExpRW : public MArrayExpR<MArrayExpRW<Derived, Element, Number, depth, rank, DimensionsT>, Element, Number, depth, rank, DimensionsT> {
  public:
    typedef Materialize<Element, Number, depth, rank> ConcreteType;
    typedef Element ElementType;
    typedef Number NumberType;
    constexpr static int rank_value = rank;
    constexpr static int depth_value = depth;

    Derived& derived() {
      return static_cast<Derived&>(*this);
    }
    const Derived& derived() const {
      return static_cast<const Derived&>(*this);
    }


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const Number dat(const size_t i) const {
      return derived().dat(i);
    }
    Number& dat(const size_t i) {
      return derived().dat(i);
    }

    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************
    const Element operator[](const size_t i) const {
      return derived()[i];
    }
    Element& operator[](const size_t i) {
      return derived()[i];
    }


    size_t size(void) const {
      return derived().size();
    }

    size_t rank(void) const {
      return derived().rank();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return derived().deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return derived().deepdims(parentdims);
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    MultiArrays getEnum(void) const {
      return derived().getEnum();
      // return T_EXPRESSION_RW;
    }
    size_t depth(void) const {
      return derived().depth();
    }
    Dimensions element_dims(void) const {
      return derived().element_dims();
    }
    size_t element_size(void) const {
      return derived().element_size();
    }
    size_t eldeepsize(void) const {
      return derived().eldeepsize();
    }
    size_t deepsize(void) const {
      return derived().deepsize();
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
    }
#else
    std::string expression(void) const {
      return "";
    }
#endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
    }


    std::string classname() const {
      return derived().classname();
    }

    friend std::ostream& operator<<(std::ostream& stream, const MArrayExpRW<Derived, Element, Number, depth, rank>& te) {
      const Derived& td = te.derived();
      if (td.isExpression()) {
        return printMultiArrayExpression(stream, te);
      }
      else {
        stream << te.derived();
        return stream;
      }
    }


    // Assign to constant value
    Derived& equals(const Element e) {
      for (size_t i = 0; i<size(); i++)
        (*this)[i] = e;
      return derived();
    }



    // assign to vector or expression
    template <class Y>
    Derived& equals(const MArrayExpR<Y, Element, Number, depth, rank>& rhs) {

      const size_t N = size();


      if (common(*this, rhs)) {
        // if a vector appears on both the right hand and left hand side,
        // we need to make a copy of the rhs first
        Vector<Number> y(N);

        for (size_t i = 0; i<N; i++)
          y[i] = rhs[i];
        for (size_t i = 0; i<N; i++)
          derived()[i] = y[i];
      }
      else {
        for (size_t i = 0; i<N; i++)
          derived()[i] = rhs[i];
      }
      return derived();
    }



  };






};
#endif
