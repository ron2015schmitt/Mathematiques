# Recursive Tensors (Tensors with Tensor elements)
_Back to [Table of Contents](../README.md)_

_Most or all of these features have been implemented._

Implement code necessary so that mathematical operations work for recursive tensors, eg. `Vector<Vector<double>>`.  This allows for the most straightforward way to implement vector and tensor functions of space and time.

1. Methodology is to use `x[index]`, ie `operator[]`, for "deep indexing" that indexes from `0` to `deepsize()-1`, covering all the elements contained.  
1. For shallow indexing, ie first level indexing, use the `operator()` operators:
    1. `Scalar()` ✓ complete 
    1. `Vector(i)`-- in progress  
       1. need to convert all `[]` usage, eg in `operator=` and expressions, to `(i)` instead. or (better)  determine how to use deep access in expressions.
       1. derivatives for Vector<Vector><double>>?
       1. implement NN fixed size versus variable vector size
    1. `Matrix(i,j)` 
    1. `Tensor(i...)`

