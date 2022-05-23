
[Table of Contents](README.md)


# python-like access: negative indices & slices in Mathématiques
_This document was automatically generated from file_ **`vslices.cpp`** (Mathématiques-v3.2-r1).

## Element access
### Positive and negative indices
Similar to python, Mathématiques allows negative indices

`v[-1] == v[N-1]` == end element

`v[-2] == v[N-2]` == penultimate element

`v[-N] == v[0]`   == first element



**EXAMPLE 1**: Positive and negative indices
```C++
Vector<double> v( range<double>(0,10) );
const int N = v.size();
```

**Some expressions with results**
```C++
  v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
  N = 11; 
  v[0] = 0; 
  v[1] = 1; 
  v[N-1] = 10; 
  v[-1] = 10; 
  v[-2] = 9; 
  v[-N] = 0; 
  v[{0,-1}] = Vector<double> {0, 10}; 
  v[{2,2,-2,-2}] = Vector<double> {2, 2, 9, 9}; 
```



**EXAMPLE 2**: Reverse a vector in place.
```C++
Vector<double> v( range<double>(0,10) );
```

**The result is**
```C++
  v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
```

```C++
for (int i = 0; i < v.size()/2; i++) std::swap(v[i],v[-i-1]);
```

**The result is**
```C++
  v = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 
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



**EXAMPLE 3**: slice `v[slc(start,end)]`
```C++
Vector<double> v( range<double>(0,10) );
```

**Some expressions with results**
```C++
  v[slc(2,6)] = Vector<double> {2, 3, 4, 5, 6}; 
  v[slc(0,-1)] = Vector<double> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
  v[slc(0,1)] = Vector<double> {0, 1}; 
  v[slc(-2,-1)] = Vector<double> {9, 10}; 
  v[slc(1,0)] = Vector<double> {}; 
  v[slc(-1,0)] = Vector<double> {}; 
```

### The `(start,end,step)` slice
* The form `v[slc(start,end,step)]` returns a `Vector` with every element from index=start to index=end, stepping by step.

* Negative indices are permitted.

* Examples

  * `v[slc(-1,0,-1)]` returns the entire vector in reverse

  * `v[slc(0,-1,2)]` returns the even-index elements

  * `v[slc(1,-1,2)]` returns the odd-index elements

  *  if you can't count from the starting element to the ending element by step, then an empty vector is returned.



**EXAMPLE 4**: slice `v[slc(start,end,step)]`
```C++
Vector<double> v0(0);
Vector<double> v1(1,0. );
Vector<double> v2( range<double>(0,1) );
Vector<double> v3( range<double>(0,2) );
Vector<double> v4( range<double>(0,3) );
Vector<double> v10( range<double>(0,10) );
```

**Some expressions with results**: reverse vectors of various lengths using the same slice
```C++
  v0[slc(-1,0,-1)] = Vector<double> {}; 
  v1[slc(-1,0,-1)] = Vector<double> {}; 
  v2[slc(-1,0,-1)] = Vector<double> {1, 0}; 
  v3[slc(-1,0,-1)] = Vector<double> {2, 1, 0}; 
  v4[slc(-1,0,-1)] = Vector<double> {3, 2, 1, 0}; 
  v10[slc(-1,0,-1)] = Vector<double> {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 
```

**Some expressions with results**: get even-index elements of various vectors using the same slice
```C++
  v0[slc(0,-1,2)] = Vector<double> {}; 
  v1[slc(0,-1,2)] = Vector<double> {0}; 
  v2[slc(0,-1,2)] = Vector<double> {0}; 
  v3[slc(0,-1,2)] = Vector<double> {0, 2}; 
  v4[slc(0,-1,2)] = Vector<double> {0, 2}; 
  v10[slc(0,-1,2)] = Vector<double> {0, 2, 4, 6, 8, 10}; 
```

**Some expressions with results**: get odd-index elements of various vectors using the same slice
```C++
  v0[slc(1,-1,2)] = Vector<double> {}; 
  v1[slc(1,-1,2)] = Vector<double> {}; 
  v2[slc(1,-1,2)] = Vector<double> {1}; 
  v3[slc(1,-1,2)] = Vector<double> {1}; 
  v4[slc(1,-1,2)] = Vector<double> {1, 3}; 
  v10[slc(1,-1,2)] = Vector<double> {1, 3, 5, 7, 9}; 
```


[Table of Contents](README.md)
