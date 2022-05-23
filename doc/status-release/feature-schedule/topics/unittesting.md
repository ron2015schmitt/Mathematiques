# Unit Testing

_Back to [Table of Contents](../README.md)_

* use one or more of the following open source math tools as a reference for results
  * [SciPy](https://scipy.org/) Python Library
  * [NumPy](https://numpy.org/) Python Library
  * [GNU Octave](https://www.gnu.org/software/octave/index)
  * [SciLab](https://www.scilab.org/)
  * [SageMath](https://www.sagemath.org/)
  * [Julia](https://docs.julialang.org/en/v1/base/math/)

* have only one executable, test.cpp
* inclue all tests as .cpp files into the main of test.cpp
* in this manner, all tests will be summarized in one final paragraph

* Write automated unit test creation code that can be re-used for Scalar, Vector, Matrix, and Tensor.  
   * `test/create/createtests.cpp` has been started.  
   * currently using `bc`
   * will switch to open source tools/libraier to calculate the expected results
   * start using Python instead of C++ for the scripting
   
   
* unit tests for helper types. Automate some of this.
   * Imaginary (use same test functions as that of Scalar, Vector etc)
   * Dimensions
   * Indices
   * Index
   * VectorofPtrs
   * calculus (on doc page)
   * Fourier Series
   * Taylor Series
   
