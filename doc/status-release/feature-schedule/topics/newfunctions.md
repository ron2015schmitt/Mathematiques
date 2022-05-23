# New Methodology for arithmetic operators

_Back to [Table of Contents](../README.md)_

+ **IMPLEMENTED IN v2.27-r4**

1. This has been trialed with the addition operator (`operator+`) and simply needs to be repeated for the other operators
1. Can then delete file `functions_complex.h`  
1. also: define `operator+=` etc.  These are needed for `std::complex<Vector<double>>` etc . to work properly.

### `operator+` code in `functions.h`
```C++
  // Tensor<D1> + Tensor<D2>

  template <class D1, class D2, class A, class B> 
    inline TER_Binary<typename AddType<D1,D2>::Type,TensorR<D1,A>,TensorR<D2,B>,Fun_Add_New<D1,D2> > 
    operator+(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
    {
      using namespace display;
      // MOUT<< a << CREATESTYLE(BOLD).apply("+") << b << std::endl;
      return  TER_Binary<typename AddType<D1,D2>::Type,TensorR<D1,A>,TensorR<D2,B>,Fun_Add_New<D1,D2> >(a,b);
    }


  // D1 + Tensor<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline TER_ScalarOpTensor_New<typename AddType<D1,D2>::Type,D1,TensorR<D2,B>,Fun_Add_New<D1,D2> >
    operator+(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_ScalarOpTensor_New<typename AddType<D1,D2>::Type,D1,TensorR<D2,B>,Fun_Add_New<D1,D2> >(a,b);
    }

  // Tensor<D1> + D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline TER_TensorOpScalar_New<typename AddType<D1,D2>::Type,TensorR<D1,A>,D2,Fun_Add_New<D1,D2> >
    operator+(const TensorR<D1,A>& a, const D2& b)
    {
      return TER_TensorOpScalar_New<typename AddType<D1,D2>::Type,TensorR<D1,A>,D2,Fun_Add_New<D1,D2> >(a,b);
    }
  


  // T + Tensor<T>

  template <class T, class B> 
    inline TER_ScalarOpTensor_New<typename AddType<T,T>::Type,T,TensorR<T,B>,Fun_Add_New<T,T> >
    operator+(const T& a, const TensorR<T,B>& b)
    {
      return TER_ScalarOpTensor_New<typename AddType<T,T>::Type,T,TensorR<T,B>,Fun_Add_New<T,T> >(a,b);
    }

  // Tensor<T> + T

  template <class T, class A> 
    inline TER_TensorOpScalar_New<typename AddType<T,T>::Type,TensorR<T,A>,T,Fun_Add_New<T,T> >
    operator+(const TensorR<T,A>& a, const T&b)
    {
      return TER_TensorOpScalar_New<typename AddType<T,T>::Type,TensorR<T,A>,T,Fun_Add_New<T,T> >(a,b);
    }
```

