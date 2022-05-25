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



  
  // // MultiArray<D1> && MultiArray<D2>

  // template <class D1, class D2, class A, class B> 
  //   inline auto operator&&(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
  // {
  //   return  TER_Binary<MArrayExpR<D1,A>,MArrayExpR<D2,B>,D1,D2,Fun_And<D1,D2>>(a,b);
  // }


  // // MultiArray<D1> && bool

  // template <class D1, class A> 
  //   inline auto operator&&(const MArrayExpR<D1,A>& a, const bool& b)
  //   {
  //     return  TER_Binary<MArrayExpR<D1,A>,bool,D1,bool,Fun_And<D1,bool>>(a,b);
  //   }

  
  // // bool && MultiArray<D2>

  // template <class D2, class B>
  //   inline auto operator&&(const bool& a, const MArrayExpR<D2,B>& b)
  //   {
  //     return  TER_Binary<bool,MArrayExpR<D2,B>,bool,D2,Fun_And<bool,D2>>(a,b);
  //   }

    
  // // MultiArray<T> && T
    
  // template <class T, class A, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
  //   inline auto operator&&(const MArrayExpR<T,A>& a, const T& b)
  //   {
  //     return  TER_Binary<MArrayExpR<T,A>,T,T,T,Fun_And<T,T>>(a,b);
  //   }
    

  // // T && MultiArray<T>

  // template <class T, class B, typename = std::enable_if_t<std::is_base_of<MultiArrayAbstract,T>::value>> 
  //   inline auto operator&&(const T& a, const MArrayExpR<T,B>& b)
  //   {
  //     return  TER_Binary<T,MArrayExpR<T,B>,T,T,Fun_And<T,T>>(a,b);
  //   }



  
};

#endif 
