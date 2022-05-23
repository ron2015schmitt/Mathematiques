# Index class and new indexing methodology

_Back to [Table of Contents](../README.md)_

Refer to file `sandbox/indexing.cpp` for prototyping.

* replace `size_type` everywhere with `index_type`
* index types
   * `index_type`
   * `sindex_type`  (signed index)
   * slice `start, stop`  (unsigned and signed)
   * slice `start, stop, step` (unsigned and signed)
   * `initializer_list` (subset)
   * `Vector<index_type>` (subset)
   * `Vector<bool>`  (mask)
   * `tensor<index_type>`(tensor subset)
   * `tensor<bool>`  (tensor mask)
* `IndexUnion` has member for each type / pointer to each type
* `IndexEnum` has an symbol for each type / pointer to each type
* `Index` class has constructors for each type / pointer to type
* implement `<<` and informative display of `Index` class
* harmonize negative index definition with that of Python
* Define both direct index (for speed) access for each tensor class
   * `Vector[index_type i]` and `Vector[Index ind]`
   * `Vector.dat(index_type i)` and `Vector.dat(Index ind)`
* Define both direct index (for speed) access for each tensor class
   * `Scalar()` - same method for both
   * `Vector(index_type k)` and `Vector(Index ind)`
   * `Matrix(index_type r, index_type c)` and  `Matrix(Index ind1, Index ind2)` and 
   * `Tensor(index_type... ks)` and  `Tensor(Index... inds)`
* define `even`, `odd`, `rev` slices in their own namespace

