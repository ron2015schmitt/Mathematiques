<h1 style='border: 2px solid; text-align: center'><a href='../../../README.md'>Mathématiques 0.42.6</a></h1>

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Versioning](../versioning/README.md)<br>
Chapter 4. [Status & Release Notes](../status-release/README.md)<br>
Chapter 5. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 6. _Introduction with Examples_ <br>
Chapter 7. [Installation](../installation/README.md)<br>
Chapter 8. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 9. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 10. [Benchmarks](../benchmarks/README.md)<br>
Chapter 11. [Tests](../test/README.md)<br>
Chapter 12. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [6. Introduction with Examples](../README.md)<br>
6.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
6.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
6.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
6.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
6.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
6.6. [MultiArray Arithmetic and Operators](../multiarray-arithmetic/README.md)<br>
6.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
6.8. [Linear Algebra](../linear-algebra/README.md)<br>
6.9. _Indexing, Masks, Slicing, Sorting, etc._ <br>
6.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
6.11. [Numerical / Discretized Mathematical Function Objects](../numerical-functions/README.md)<br>
6.12. [Functions of Complex Variables](../complex-calculus/README.md)<br>
6.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
6.14. [Tensors](../tensors/README.md)<br>
6.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 6.9. Indexing, Masks, Slicing, Sorting, etc.



## Sequences
The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start, start+1, start+2, ..., (end)}`
* The sequence can be increasing (stride = +1) or decreasing (stride = -1)
* The start and end need not be integers 

```C++
☀ range<int>(1, 10) ➜ Vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
☀ range<double>(-3, 3) ➜ Vector<double> {-3, -2, -1, 0, 1, 2, 3};
☀ range<int>(10, 0) ➜ Vector<int> {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
☀ range<int>(1.5, 3.5) ➜ Vector<int> {1, 2, 3};
```
### Arbitrary stride
* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start, start+stride, start+2*stride, ..., (end)}`

Seqeunces of different strides using `range`
```C++
☀ range<int>(2, 10, 2) ➜ Vector<int> {2, 4, 6, 8, 10};
☀ range<double>(0, 5, 0.5) ➜ Vector<double> {0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5};
```
### Initializing and Assigning a `Vector` using `range`


Initialize `Vector`'s of various data types  using the *`range`* function
```C++
Vector<unsigned int> v{ range<unsigned int>(0, 3);
☀ v ➜ Vector<unsigned int> {0, 1, 2, 3};
v = range<unsigned int>(1, 4);
☀ v ➜ Vector<unsigned int> {1, 2, 3, 4};
```


<br>

## Element access
### Positive and negative indices
Similar to python, Mathématiques allows negative indices

`v[-1] == v[N-1]` == end element

`v[-2] == v[N-2]` == penultimate element

`v[-N] == v[0]`   == first element



Positive and negative indices
```C++
Vector<double> v{ 0,1,2,3 };
const int N = v.size();

☀ v ➜ Vector<double> {0, 1, 2, 3};
☀ N ➜ int 4;
☀ v[0] ➜ double 0;
☀ v[1] ➜ double 1;
☀ v[2] ➜ double 2;
☀ v[3] ➜ double 3;
☀ v[-1] ➜ double 3;
☀ v[-2] ➜ double 2;
☀ v[-3] ➜ double 1;
☀ v[-4] ➜ double 0;

Matrix<double> A{ {1,2,3,4},{5,6,7,8} };
☀ A ➜ Matrix<double> 
{
  {1, 2, 3, 4},
  {5, 6, 7, 8}
};
☀ A(0, 1) ➜ double 2;
☀ A(0, -1) ➜ double 4;
☀ A(-1, 0) ➜ double 5;
```
### Lists of indices

* The list can be smaller than or greater than or equal to the length to the data Vector.
* The list can have repeated indices and indices can be in any order!


```C++
Vector<double> v(linspace<double>(0, 1, 11));
☀ v ➜ Vector<double> {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};

☀ v[{0, 4}] ➜ Vector<double> {0, 0.4};
☀ v[{4, 0, 1, 4}] ➜ Vector<double> {0.4, 0, 0.1, 0.4};
☀ v[{1, 0, 2}] ➜ Vector<double> {0.1, 0, 0.2};
☀ v[{4, 3, 2, 1, 0}] ➜ Vector<double> {0.4, 0.3, 0.2, 0.1, 0};
☀ v[{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}] ➜ Vector<double> {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2};
```
🚧 This functionality is currently only available for vectors.

<br>

## Vector mask access
* A subset of a vector can be extracted using a boolean-valued vector of the same size.
* For example `v[v>0]` will return a vector containing only the positive values of v.
* Vector mask access can be used on the left hand side of assigment, allowing you to set values via masks.


Using vector masks
```C++
Vector<double> v(range<double>(-10, 10));

☀ v ➜ Vector<double> {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
☀ v > 6 ➜ Vector<bool> {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true};
☀ v[(v > 6)] ➜ Vector<double> {7, 8, 9, 10};
```

Now set all elements that are larger than 6 to 6 (clipping)
```C++
v[(v > 6)] = 6.;

☀ v ➜ Vector<double> {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
```

Now set all negative elements to zero
```C++
v[(v < 0)] = 0.;

☀ v ➜ Vector<double> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
```

🚧 This functionality is currently only available for vectors.

<br>

## Slices via the `slc` function
Slicing is very useful for numerical code and is a part of Fortran, python, and matlab.
### The `(start,end)` slice
* The form `v[slc(start,end)]` returns a `Vector` with every element from index=start to index=end, stepping by +1.

* Negative indices are permitted.

* Examples

  * `v[slc(0,-1)]` returns the entire vector

  * `v[slc(0,1)]` returns the first two elements

  * `v[slc(-2,-1)]` returns the last two elements

  *  if you can't count from the starting element to the ending element by +1, then an empty vector is returned.



slice `v[slc(start,end)]`
```C++
Vector<double> v(range<double>(0, 10));

☀ v[slc(2, 6)] ➜ Vector<double> {2, 3, 4, 5, 6};
☀ v[slc(0, -1)] ➜ Vector<double> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
☀ v[slc(0, 1)] ➜ Vector<double> {0, 1};
☀ v[slc(-2, -1)] ➜ Vector<double> {9, 10};
☀ v[slc(1, 0)] ➜ Vector<double> {};
☀ v[slc(-1, 0)] ➜ Vector<double> {};
```
### The `(start,end,step)` slice
* The form `v[slc(start,end,step)]` returns a `Vector` with every element from index=start to index=end, stepping by step.

* Negative indices are permitted.

* Examples

  * `v[slc(-1,0,-1)]` returns the entire vector in reverse

  * `v[slc(0,-1,2)]` returns the even-index elements

  * `v[slc(1,-1,2)]` returns the odd-index elements

  *  if you can't count from the starting element to the ending element by step, then an empty vector is returned.



slice `v[slc(start,end,step)]`
```C++
Vector<double> v0(0);
Vector<double> v4{ 0, 1, 2, 3 };
Vector<double> v5{ 0, 1, 2, 3, 4 };
```

Reverse vectors of various lengths using the same slice
```C++
☀ v0[slc(-1, 0, -1)] ➜ Vector<double> {};
☀ v4[slc(-1, 0, -1)] ➜ Vector<double> {3, 2, 1, 0};
☀ v5[slc(-1, 0, -1)] ➜ Vector<double> {4, 3, 2, 1, 0};
```

Get even-index elements of various vectors using the same slice
```C++
☀ v0[slc(0, -1, 2)] ➜ Vector<double> {};
☀ v4[slc(0, -1, 2)] ➜ Vector<double> {0, 2};
☀ v5[slc(0, -1, 2)] ➜ Vector<double> {0, 2, 4};
```

Get odd-index elements of various vectors using the same slice
```C++
☀ v0[slc(1, -1, 2)] ➜ Vector<double> {};
☀ v4[slc(1, -1, 2)] ➜ Vector<double> {1, 3};
☀ v5[slc(1, -1, 2)] ➜ Vector<double> {1, 3};
```


<br>

## Sorting
### The `sort` method sorts the vector in-place returns a vector with the indices.


```C++
Vector<double> v{ 22, -1, 3, 1, 200, 3, 17, 0 };
☀ v.sort() ➜ Vector<unsigned long> {1, 7, 3, 2, 5, 6, 0, 4};
☀ v ➜ Vector<double> {-1, 0, 1, 3, 3, 17, 22, 200};
```

### the `uniq` function
* Examples



```C++
Vector<double> v{ 22, -1, 3, 1, 200, 3, 17, 0 };
☀ v.uniq() ➜ Vector<unsigned long> {0, 1, 2, 3, 4, 6, 7};
☀ v ➜ Vector<double> {22, -1, 3, 1, 200, 17, 0};
```


<br>



| ⇦ <br />[Linear Algebra](../linear-algebra/README.md)  | [Introduction with Examples](../README.md)<br />Indexing, Masks, Slicing, Sorting, etc.<br /><img width=1000/> | ⇨ <br />[Common and Special Mathematical Functions](../math-functions/README.md)   |
| ------------ | :-------------------------------: | ------------ |

