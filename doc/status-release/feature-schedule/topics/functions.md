# Functions: R^n -> R^m

_Back to [Table of Contents](../README.md)_

* constructor takes:
  * number of coordinates
  * domain for each coordinate
  * can pass lambda function to calculate f
* need function to create n-dimensional grid tensor, like matlab
* Function class consists
   * an n-dimensional tensor for each of the n coordinates (or `Tensor<Vector<D,int N=n>>`)
   * an n-dimensional that holds m-dimensional tensors
