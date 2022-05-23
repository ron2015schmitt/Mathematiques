
[Table of Contents](README.md)


# The `range` function in Mathématiques
_This document was automatically generated from file_ **`range.cpp`** (Mathématiques-v3.2-r1).

### Increasing Sequences
* The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start, start+1, start+2, ..., (end)}`

**EXAMPLE 1**: Increasing sequences using `range`
```C++
range<int>(1,10) = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
range<double>(-3,3) = {-3, -2, -1, 0, 1, 2, 3}; 
```
### Decreasing Sequences
* Counting down is also supported

**EXAMPLE 2**: Decreasing sequence using `range`
```C++
range<int>(10,0) = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 
```
### Non-integer Sequences
* The start and end need not be integers 

**EXAMPLE 3**: Floating point sequences using `range`
```C++
range<double>(1.5,5.5) = {1.5, 2.5, 3.5, 4.5, 5.5}; 
range<double>(5.5,1.5) = {5.5, 4.5, 3.5, 2.5, 1.5}; 
```
### Arbitrary stride
* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start, start+stride, start+2*stride, ..., (end)}`

**EXAMPLE 4**: Seqeunces of different strides using `range`
```C++
range<int>(2,10,2) = {2, 4, 6, 8, 10}; 
range<double>(0,10,0.5) = {0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10}; 
```
### The end point isn't always included
* The end point is only included when 
```C++
end == start + n * stride
```
where `n` is an integer.


**EXAMPLE 5**: End point is not included in certain cases
```C++
range<int>(0,5,2) = {0, 2, 4}; 
range<double>(1,3.5) = {1, 2, 3}; 
```
### Initializing `Vector`'s using `range`


**EXAMPLE 6**: Initialize `Vector`'s of various data types  using the *`range`* function
```C++
Vector<unsigned int> v1 ( range<unsigned int>(0,3) );
Vector<int> v2 ( range<int>(0,3) );
Vector<double> v3 ( range<double>(0,3));
```

**The result is**
```C++
  v1 = {0, 1, 2, 3}; 
  v2 = {0, 1, 2, 3}; 
  v3 = {0, 1, 2, 3}; 
```

### Assigning `Vector`'s using `range`


**EXAMPLE 7**: Assigning a `Vector`'s to a *`range`*
```C++
const size_t N = 10;
Vector<double> v (N);
v = range<double>(0,N-1);
```

**The result is**
```C++
  v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
```


[Table of Contents](README.md)
