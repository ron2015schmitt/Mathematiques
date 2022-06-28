# Index class and new indexing methodology

_Back to [Table of Contents](../README.md)_

Refer to file `sandbox/indexing.cpp` for prototyping.

* replace `size_t` everywhere with `size_t`
* index types
   * `size_t`
   * `sindex_type`  (signed index)
   * slice `start, stop`  (unsigned and signed)
   * slice `start, stop, step` (unsigned and signed)
   * `initializer_list` (subset)
   * `Vector<size_t>` (subset)
   * `Vector<bool>`  (mask)
   * `tensor<size_t>`(tensor subset)
   * `tensor<bool>`  (tensor mask)
* `IndexUnion` has member for each type / pointer to each type
* `IndexEnum` has an symbol for each type / pointer to each type
* `Index` class has constructors for each type / pointer to type
* implement `<<` and informative display of `Index` class
* harmonize negative index definition with that of Python
* Define both direct index (for speed) access for each tensor class
   * `Vector[size_t i]` and `Vector[Index ind]`
   * `Vector.dat(size_t i)` and `Vector.dat(Index ind)`
* Define both direct index (for speed) access for each tensor class
   * `Scalar()` - same method for both
   * `Vector(size_t k)` and `Vector(Index ind)`
   * `Matrix(size_t r, size_t c)` and  `Matrix(Index ind1, Index ind2)` and 
   * `MultiArray(size_t... ks)` and  `MultiArray(Index... inds)`
* define `even`, `odd`, `rev` slices in their own namespace

