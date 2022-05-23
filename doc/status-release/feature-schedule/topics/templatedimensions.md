# Tensor Dimensions as Template Parameters

_Back to [Table of Contents](../README.md)_

Add template parameters for dimensions of each Tensor class.  
* Each parameter should have the default value of 0
* If parameters are > 0, then the tensor is of fixed size and the `array` class is used for storage
* If paramters are <= 0, then the tensor is of variable size and the class `valarray` is used for storage.  The initial size is abs(parameter).
* The static if construct,`if constexpr(expr)`, as introduced in `C++17` is used to select which code to enable, such as whether to use an `array` or `valarray`

## Scalar class
The `Scalar<D>` class has no size, so no changes are needed.

## Vector class
The `Vector<D>` class has one size parameter.  The new class will be:

```C++
template class Vector<class D, int N = 0>
```

* change size and dimensions methods to use `N` if `N>0`
* use `array` instad of `valarray` if `N>0`
* if `N <= 0`, then `valarray` is used and initial size is `abs(N)`
* change `.reshape()` method to a function and perhaps use 

## Matrix class
The `Matrix<D>` class has two size parameters.  The new class will be:

```C++
template class Vector<class D, int NR = 0, int NC = 0>
```
* if `NR>0 && NC>0` then use fixed size and `array`
* if `NR<=0 && NC<=0` then use variable size and `valarray`
* if only one of the values is greater than zero, then that dimension is fixed, but the other dimensions is variable and thus a `valarray` must be used.


## Tensor class
The `Tensor<D,int R>` class with Rank `R>=0` has size parameters.  Recall that R=0 is a scalar. The new class will use variadic template parameters.

```C++
template class Vector<class D, int R = 0, int ... Dims>
```
Likely don't need `R`, but may be useful for speficying if it can be resized, in which case better to change to `bool RESIZABLE`.

If not resizable, use static if's to enable one and only one element access function, for example if `Rank=3`

```C++
D& operator()(Index i1, Index i2, Index i3) {
  ....
}
```

Due to this, it is probably a good idea to not allow tensor to change rank, except by creating a new Tensor, similar to rehaphing a vector into a matrix.



# Expressions
Similar to tensor class

