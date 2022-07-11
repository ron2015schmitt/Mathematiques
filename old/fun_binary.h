#ifndef MATHQ__FUN_BINARY_H
#define MATHQ__FUN_BINARY_H 1


#include "fun_binary_ops_AUTO.h"

namespace mathq {

  // DUSCUSSION:
  // It makes the most sense to put all the logic regarding types
  //  1. in once place 
  //  2. at the code entry point (the functions)
  //
  // For this reason, the type logic is placed in the functions
  // and then passed to the Functor and the Expression template.
  

  
  // ************************************************************************
  // *         FUNCTOR MACRO FOR GENERAL BINARY operators
  // ************************************************************************

  

  // ************************************************************************
  // *         FUNCTOR MACRO FOR GENERAL BINARY functions
  // ************************************************************************
  
  // ************************************************************************
  // *             BINARY FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************


  // work on addition 

  //  FUNCTOR_BINARY_OP(+,add);
  



  
  
  
  //----------------------------------------------
  // logical AND (&&)
  //----------------------------------------------


  // FUNCTOR_BINARY_OP(&&,and);
  // FUNCTION_BINARY(operator&&,FUNCTOR_and);



  
  // // MultiArray<NT1> && MultiArray<NT2>

  // template <class NT1, class NT2, class A, class B> 
  //   inline auto operator&&(const ExpressionR<NT1,A>& a, const ExpressionR<NT2,B>& b)
  // {
  //   return  TER_Binary<ExpressionR<NT1,A>,ExpressionR<NT2,B>,NT1,NT2,Fun_And<NT1,NT2>>(a,b);
  // }


  // // MultiArray<NT1> && bool

  // template <class NT1, class A> 
  //   inline auto operator&&(const ExpressionR<NT1,A>& a, const bool& b)
  //   {
  //     return  TER_Binary<ExpressionR<NT1,A>,bool,NT1,bool,Fun_And<NT1,bool>>(a,b);
  //   }

  
  // // bool && MultiArray<NT2>

  // template <class NT2, class B>
  //   inline auto operator&&(const bool& a, const ExpressionR<NT2,B>& b)
  //   {
  //     return  TER_Binary<bool,ExpressionR<NT2,B>,bool,NT2,Fun_And<bool,NT2>>(a,b);
  //   }

    
  // // MultiArray<T> && T
    
  // template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
  //   inline auto operator&&(const ExpressionR<T,A>& a, const T& b)
  //   {
  //     return  TER_Binary<ExpressionR<T,A>,T,T,T,Fun_And<T,T>>(a,b);
  //   }
    

  // // T && MultiArray<T>

  // template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
  //   inline auto operator&&(const T& a, const ExpressionR<T,B>& b)
  //   {
  //     return  TER_Binary<T,ExpressionR<T,B>,T,T,Fun_And<T,T>>(a,b);
  //   }



  
};

#endif 
