# New Methodology for arithmetic operators

_Back to [Table of Contents](../README.md)_

+ **IMPLEMENTED IN v2.27-r4**

1. This has been trialed with the addition operator (`operator+`) and simply needs to be repeated for the other operators
1. Can then delete file `functions_complex.h`  
1. also: define `operator+=` etc.  These are needed for `std::complex<Vector<double>>` etc . to work properly.

### `operator+` code in `functions.h`
```C++
  // MultiArray<D1> + MultiArray<D2>

  template <class D1, class D2, class A, class B> 
    inline TER_Binary<typename AddType<D1,D2>::Type,MArrayExpR<D1,A>,MArrayExpR<D2,B>,Fun_Add_New<D1,D2> > 
    operator+(const MArrayExpR<D1,A>& a, const MArrayExpR<D2,B>& b)
    {
      using namespace display;
      // MOUT<< a << CREATESTYLE(BOLD).apply("+") << b << std::endl;
      return  TER_Binary<typename AddType<D1,D2>::Type,MArrayExpR<D1,A>,MArrayExpR<D2,B>,Fun_Add_New<D1,D2> >(a,b);
    }


  // D1 + MultiArray<D2>

  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D1>::value> > 
    inline TER_ScalarOpMultiArray_New<typename AddType<D1,D2>::Type,D1,MArrayExpR<D2,B>,Fun_Add_New<D1,D2> >
    operator+(const D1& a, const MArrayExpR<D2,B>& b)
    {
      return  TER_ScalarOpMultiArray_New<typename AddType<D1,D2>::Type,D1,MArrayExpR<D2,B>,Fun_Add_New<D1,D2> >(a,b);
    }

  // MultiArray<D1> + D2

  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<MultiArrayAbstract,D2>::value> > 
    inline TER_MultiArrayOpScalar_New<typename AddType<D1,D2>::Type,MArrayExpR<D1,A>,D2,Fun_Add_New<D1,D2> >
    operator+(const MArrayExpR<D1,A>& a, const D2& b)
    {
      return TER_MultiArrayOpScalar_New<typename AddType<D1,D2>::Type,MArrayExpR<D1,A>,D2,Fun_Add_New<D1,D2> >(a,b);
    }
  


  // T + MultiArray<T>

  template <class T, class B> 
    inline TER_ScalarOpMultiArray_New<typename AddType<T,T>::Type,T,MArrayExpR<T,B>,Fun_Add_New<T,T> >
    operator+(const T& a, const MArrayExpR<T,B>& b)
    {
      return TER_ScalarOpMultiArray_New<typename AddType<T,T>::Type,T,MArrayExpR<T,B>,Fun_Add_New<T,T> >(a,b);
    }

  // MultiArray<T> + T

  template <class T, class A> 
    inline TER_MultiArrayOpScalar_New<typename AddType<T,T>::Type,MArrayExpR<T,A>,T,Fun_Add_New<T,T> >
    operator+(const MArrayExpR<T,A>& a, const T&b)
    {
      return TER_MultiArrayOpScalar_New<typename AddType<T,T>::Type,MArrayExpR<T,A>,T,Fun_Add_New<T,T> >(a,b);
    }
```

