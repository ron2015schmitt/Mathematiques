[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.006</h1>](../../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../../README.md)<br>
Chapter 1. [License](../../license/README.md)<br>
Chapter 2. [About](../../about/README.md)<br>
Chapter 3. [Why?](../../why/README.md)<br>
Chapter 4. [Objectives](../../objectives/README.md)<br>
Chapter 5. [Versioning](../../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../../development-schedule/README.md)<br>
Chapter 8. _Introduction with Examples_ <br>
Chapter 9. [Installation](../../installation/README.md)<br>
Chapter 10. [Your First Mathématiques Project](../../first-project/README.md)<br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../../user-guide/README.md)<br>
Chapter 12. [Benchmarks](../../benchmarks/README.md)<br>
Chapter 13. [Tests](../../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../../developer-guide/README.md)<br>


</details>



<details>

<summary>Introduction with Examples</summary>

# [8. Introduction with Examples](../README.md)<br>
8.1. [Pretty Printing and Debugging](../print-debug/README.md)<br>
8.2. [Number Systems and Arithmetic](../numbers/README.md)<br>
8.3. [Vectors, Matrices, and MultiArrays](../multiarrays/README.md)<br>
8.4. [Nested MultiArrays](../nested-multiarrays/README.md)<br>
8.5. [Special Vectors, Matrices, and MultiArrays](../special-multiarrays/README.md)<br>
8.6. [MultiArray Arithmetic](../multiarray-arithmetic/README.md)<br>
8.7. [Mixed-Rank & Mixed-Depth Arithmetic](../arithmetic-mixed/README.md)<br>
8.8. [Linear Algebra](../linear-algebra/README.md)<br>
8.9. _Sorting, Masks, Slices, etc._ <br>
8.10. [Common and Special Mathematical Functions](../math-functions/README.md)<br>
8.11. [Mutlivariate Calculus](../multi-var-calculus/README.md)<br>
8.12. [Calculus on Complex Number Domains](../complex-calculus/README.md)<br>
8.13. [Vector Calculus and Curvilinear Coordinates](../vector-calculus/README.md)<br>
8.14. [Tensors](../tensors/README.md)<br>
8.15. [Series and transforms](../series-transforms/README.md)<br>


</details>



# 8.9. Sorting, Masks, Slices, etc.



Mathématiques supports vectors, matrices and arbitrary rank multi-arrays.
### Increasing Sequences
* The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start, start+1, start+2, ..., (end)}`

Increasing sequences using `range`
```C++
☀ range<int>(1, 10) ➜ {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
☀ range<double>(-3, 3) ➜ {-3, -2, -1, 0, 1, 2, 3};
```
### Decreasing Sequences
* Counting down is also supported

Decreasing sequence using `range`
```C++
☀ range<int>(10, 0) ➜ {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
```
### Non-integer Sequences
* The start and end need not be integers 

Floating point sequences using `range`
```C++
☀ range<double>(1.5, 5.5) ➜ {1.5, 2.5, 3.5, 4.5, 5.5};
☀ range<double>(5.5, 1.5) ➜ {5.5, 4.5, 3.5, 2.5, 1.5};
```
### Arbitrary stride
* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start, start+stride, start+2*stride, ..., (end)}`

Seqeunces of different strides using `range`
```C++
☀ range<int>(2, 10, 2) ➜ {2, 4, 6, 8, 10};
☀ range<double>(0, 10, 0.5) ➜ {0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10};
```
### The end point isn't always included
* The end point is only included when 
```C++
end == start + n * stride
```
where `n` is an integer.


End point is not included in certain cases
```C++
☀ range<int>(0, 5, 2) ➜ {0, 2, 4};
☀ range<double>(1, 3.5) ➜ {1, 2, 3};
```
### Initializing `Vector`'s using `range`


Initialize `Vector`'s of various data types  using the *`range`* function
```C++
Vector<unsigned int> v1(range<unsigned int>(0, 3));
Vector<int> v2(range<int>(0, 3));
Vector<double> v3(range<double>(0, 3));
```

**The result is**
```C++
  ☀ v1 ➜ {0, 1, 2, 3};
  ☀ v2 ➜ {0, 1, 2, 3};
  ☀ v3 ➜ {0, 1, 2, 3};
```

### Assigning `Vector`'s using `range`


Assigning a `Vector`'s to a *`range`*
```C++
const size_t N = 10;
Vector<double> v(N);
v = range<double>(0, N-1);
```

## Relational operators
### Relational operators between two Vectors

Vector relations operate element-wise, similar to arithmetic operators. Given two Vectors of the same size, a vector relational expression (eg `(v1>v2)` returns a vector of booleans of the same size


relational operators between two vectors`
```C++
Vector<double> v1(range<double>(1, 3));
Vector<double> v2(range<double>(3, 1));
```

**Some expressions with results**
```C++
  ☀ v1 ➜ {1, 2, 3};
  ☀ v2 ➜ {3, 2, 1};
  ☀ v1 > v2 ➜ {false, false, true};
  ☀ v1 >= v2 ➜ {false, true, true};
  ☀ v1 < v2 ➜ {true, false, false};
  ☀ v1 <= v2 ➜ {true, true, false};
  ☀ v1 == v2 ➜ {false, true, false};
  ☀ v1 != v2 ➜ {true, false, true};
```

### Relational operators between a Vector and scalar


relational operators between a vector and a scalar`
```C++
Vector<double> v(range<double>(1, 3));
```

**Some expressions with results**
```C++
  ☀ v ➜ {1, 2, 3};
  ☀ v > 2 ➜ {false, false, true};
  ☀ v >= 2 ➜ {false, true, true};
  ☀ v < 2 ➜ {true, false, false};
  ☀ v <= 2 ➜ {true, true, false};
  ☀ v == 2 ➜ {false, true, false};
  ☀ v != 2 ➜ {true, false, true};
```

## Logical operators
### The element-wise logical operatora `&&`,`||`,`!`


The element-wise logical operators
```C++
Vector<double> v(range<double>(1, 5));
```

**Some expressions with results**
```C++
  ☀ v ➜ {1, 2, 3, 4, 5};
  ☀ (v > 2) ➜ {false, false, true, true, true};
  ☀ !(v > 2) ➜ {true, true, false, false, false};
  ☀ (v >= 2) && (v <= 4) ➜ {false, true, true, true, false};
  ☀ (v <= 2) || (v >= 4) ➜ {true, true, false, true, true};
```

## Vector mask access
* A subset of a vector can be extracted using a boolean-valued vector of the same size.
* For example `v[v>0]` will return a vector containing only the positive values of v.
* Vector mask access can be used on the left hand side of assigment, allowing you to set values via masks.


Using vector masks
```C++
Vector<double> v(range<double>(-10, 10));
```

**Some expressions with results**
```C++
  ☀ v ➜ {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ☀ v > 6 ➜ {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true};
  ☀ v[(v > 6)] ➜ {7, 8, 9, 10};
```


Now set all elements that are larger than 6 to 6 (clipping)
```C++
v[(v > 6)] = 6.;
```
**The result is**
```C++
  ☀ v ➜ {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
```


Now set all negative elements to zero
```C++
v[(v < 0)] = 0.;
```
**The result is**
```C++
  ☀ v ➜ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
```


## Logical functions
### The functions `alltrue`, `anytrue`, `numtrue`, and `findtrue`

* The function `alltrue(v)` returns a `bool`: true if every element of `v` is true, otherwise it returns false

* The function `anytrue(v)` returns a `bool`: true if any element of `v` is true, otherwise it returns false

* The function `numtrue(v)` returns a `size_t` equal to the number of elements of `v` that are true. 

* The function `findtrue(v)` returns a `Vector<size_t>` which contains the indices of the true elements of `v`. 


The functions `alltrue`, `anytrue`, `numtrue`, and `findtrue`
```C++
Vector<double> v(range<double>(1, 3));
```

**Some expressions with results**
```C++
  ☀ v ➜ {1, 2, 3};
  ☀ (v > 2) ➜ {false, false, true};
  ☀ alltrue(v > 2) ➜ false;
  ☀ alltrue(v > 0) ➜ true;
  ☀ anytrue(v > 2) ➜ true;
  ☀ numtrue(v > 2) ➜ 1;
  ☀ numtrue(v > 0) ➜ 3;
  ☀ findtrue(v > 2) ➜ {2};
  ☀ findtrue(v > 0) ➜ {0, 1, 2};
```

python-like access: negative indices & slices
## Element access
### Positive and negative indices
Similar to python, Mathématiques allows negative indices

`v[-1] == v[N-1]` == end element

`v[-2] == v[N-2]` == penultimate element

`v[-N] == v[0]`   == first element



Positive and negative indices
```C++
Vector<double> v(range<double>(0, 10));
const int N = v.size();
```

**Some expressions with results**
```C++
  ☀ v ➜ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ☀ N ➜ 11;
  ☀ v[0] ➜ 0;
  ☀ v[1] ➜ 1;
  ☀ v[N-1] ➜ 10;
  ☀ v[-1] ➜ 10;
  ☀ v[-2] ➜ 9;
  ☀ v[-N] ➜ 0;
```



Reverse a vector in place.
```C++
Vector<double> v(range<double>(0, 10));
```

**The result is**
```C++
  ☀ v ➜ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

```C++
for (int i = 0; i < v.size()/2; i++) std::swap(v[i], v[-i-1]);
```

**The result is**
```C++
  ☀ v ➜ {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
```

## Slices via the `slc` function
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
```

**Some expressions with results**
```C++
  ☀ v[slc(2, 6)] ➜ {2, 3, 4, 5, 6};
  ☀ v[slc(0, -1)] ➜ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ☀ v[slc(0, 1)] ➜ {0, 1};
  ☀ v[slc(-2, -1)] ➜ {9, 10};
  ☀ v[slc(1, 0)] ➜ {};
  ☀ v[slc(-1, 0)] ➜ {};
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
Vector<double> v1(1, 0.);
Vector<double> v2(range<double>(0, 1));
Vector<double> v3(range<double>(0, 2));
Vector<double> v4(range<double>(0, 3));
Vector<double> v10(range<double>(0, 10));
```

**Some expressions with results**: reverse vectors of various lengths using the same slice
```C++
  ☀ v0[slc(-1, 0, -1)] ➜ {};
  ☀ v1[slc(-1, 0, -1)] ➜ {};
  ☀ v2[slc(-1, 0, -1)] ➜ {1, 0};
  ☀ v3[slc(-1, 0, -1)] ➜ {2, 1, 0};
  ☀ v4[slc(-1, 0, -1)] ➜ {3, 2, 1, 0};
  ☀ v10[slc(-1, 0, -1)] ➜ {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
```

**Some expressions with results**: get even-index elements of various vectors using the same slice
```C++
  ☀ v0[slc(0, -1, 2)] ➜ {};
  ☀ v1[slc(0, -1, 2)] ➜ {0};
  ☀ v2[slc(0, -1, 2)] ➜ {0};
  ☀ v3[slc(0, -1, 2)] ➜ {0, 2};
  ☀ v4[slc(0, -1, 2)] ➜ {0, 2};
  ☀ v10[slc(0, -1, 2)] ➜ {0, 2, 4, 6, 8, 10};
```

**Some expressions with results**: get odd-index elements of various vectors using the same slice
```C++
  ☀ v0[slc(1, -1, 2)] ➜ {};
  ☀ v1[slc(1, -1, 2)] ➜ {};
  ☀ v2[slc(1, -1, 2)] ➜ {1};
  ☀ v3[slc(1, -1, 2)] ➜ {1};
  ☀ v4[slc(1, -1, 2)] ➜ {1, 3};
  ☀ v10[slc(1, -1, 2)] ➜ {1, 3, 5, 7, 9};
```

Access subsets of Vector elements
You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices
## Access vector elements using a `Vector` of indices
### Element access `Vector[Vector]`

* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!
* The index Vector _can have repeated indices and indices can be in any order_!


Access via a Vector of indices
```C++
Vector<double> v(linspace<double>(0, 1, 11));
Vector<size_t> veven(range<size_t>(0, 10, 2));
Vector<size_t> vodd(range<size_t>(1, 10, 2));
Vector<size_t> vconst(15, 1);
```

**The result is**
```C++
  ☀ v ➜ {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
  ☀ veven ➜ {0, 2, 4, 6, 8, 10};
  ☀ v[veven] ➜ {0, 0.2, 0.4, 0.6, 0.8, 1};
  ☀ v[veven[1]] ➜ 0.2;
  ☀ vodd ➜ {1, 3, 5, 7, 9};
  ☀ v[vodd] ➜ {0.1, 0.3, 0.5, 0.7, 0.9};
  ☀ v[vodd[1]] ➜ 0.3;
  ☀ v[vodd[veven[1]]] ➜ 0.5;
  ☀ vconst ➜ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  ☀ v[vconst] ➜ {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
```

## Access vector elements using an C++11 `initializer_list` of indices
### Element access `Vector[initializer_list]`

* The list can be smaller than or greater than or equal to the length to the data Vector.
* The list can have repeated indices and indices can be in any order!


Access via a C++11 initializer_list
```C++
Vector<double> v(linspace<double>(0, 1, 11));
☀ v ➜ {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
```

**The result is**
```C++
  ☀ v[{0, 4}] ➜ {0, 0.4};
  ☀ v[{4, 0, 1, 4}] ➜ {0.4, 0, 0.1, 0.4};
  ☀ v[{1, 0, 2}] ➜ {0.1, 0, 0.2};
  ☀ v[{4, 3, 2, 1, 0}] ➜ {0.4, 0.3, 0.2, 0.1, 0};
  ☀ v[{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}] ➜ {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2};
```


<br>



| ⇦ <br />[Linear Algebra](../linear-algebra/README.md)  | [Introduction with Examples](../README.md)<br />Sorting, Masks, Slices, etc.<br /><img width=1000/> | ⇨ <br />[Common and Special Mathematical Functions](../math-functions/README.md)   |
| ------------ | :-------------------------------: | ------------ |

