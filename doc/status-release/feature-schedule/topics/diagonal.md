# Special matrices

_Back to [Table of Contents](../README.md)_

* Special matrices do *not* inherit from Matrix since dimensions() will distinguish
* Special matrices do *not* allow nesting, other than as noted for block style matrices.


### Already Implemented:
* `MatrixZero`
* `MatrixIdentity`
* `MatrixExchange` (The J matrix)
* `MatrixConstDiag`
* `MatrixDiagonal`
* `MatrixRevDiag`  
* `MatrixRepCol` -- repeated Column matrix. need for Grids/meshes to save memory
* `MatrixRepRow` -- repeated Row matrix. need for Grids/meshes to save memory
* `MatrixVandermonde`
* `MatrixToeplitz`
* `MatrixUpperTriag`
* `MatrixLowerTriag`
* `MatrixSymmetric`
* `MatrixSkewSymmetric`
* `MatrixHermitian`
* `MatrixSkewHermitian`

### TO-DO:
 
* write `diag(Matrix)`, which presents the diagonal of a matrix as a vector (via TERW expression Rin=2, Rout=1)
* write `diag(Vector)`, which presents a vector as the digonal of a matrix (via TERW expression Rin=1, Rout=2))
* implement `constructor(constTensor<X,D,D,1,2>& x)` and `operator=(constTensor<X,D,D,1,2>& x)`
   * need `(r,c)` method for TensorR
   * `Matrix` should use `(r,c)` instead of `.dat()` and `[k]`
* implement direct data access for each matrix
  * implement `dataIndex(r,c)` method for use with `data_`  (refer to `MatrixSymmetric`)
* implement `.transpose()` and `.adjoint()` where appropriate (ie where MatrixType is invariant under such operation)
* harmonize data storage with LAPACK
   * use [column major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order) - or allow use of either via a `#definwe`
   * `MatrixHermitian` diagonal must be real
   * `MatrixSkewHermitian` diagonal must be imaginary
* perhaps implement iterator for each type of matrix (as a subclass) at some point

## Other Matrices
* `MatrixSparse` - utilize `std::map`
* `MatrixRepMat`-- repeated Matrix matrix.
* `MatrixBlock` -- set via initializer list notation `G=((A,B),(C,D))`.  
   * all rows have same number of columns and deep columns.
   * all cols have same number of rowss and deep rows.
* `MatrixBanded`
* `MatrixBidiagonal` 
* `MatrixTridiagonal` 
* `MatrixJordanBlock`
* `MatrixJordanForm`



