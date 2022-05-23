
[Table of Contents](README.md)


# Access subsets of Vector elements in Mathématiques
_This document was automatically generated from file_ **`vsubsets.cpp`** (Mathématiques-v3.2-r1).

You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices
## Access vector elements using a `Vector` of indices
### Element access `Vector[Vector]`

* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!
* The index Vector _can have repeated indices and indices can be in any order_!


**EXAMPLE 1**: Access via a Vector of indices
```C++
Vector<double> v( linspace<double>(0,1,11) );
Vector<index_type> veven( range<index_type>(0,10,2) );
Vector<index_type> vodd( range<index_type>(1,10,2) );
Vector<index_type> vconst(15,1 );
```

**The result is**
```C++
  v = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1}; 
  veven = {0, 2, 4, 6, 8, 10}; 
  v[veven] = Vector<double> {0, 0.2, 0.4, 0.6, 0.8, 1}; 
  v[veven[1]] = 0.2; 
  vodd = {1, 3, 5, 7, 9}; 
  v[vodd] = Vector<double> {0.1, 0.3, 0.5, 0.7, 0.9}; 
  v[vodd[1]] = 0.3; 
  v[veven,vodd] = Vector<double> {0, 0.2, 0.4, 0.6, 0.8, 1, 0.1, 0.3, 0.5, 0.7, 0.9}; 
  v[vodd[veven[1]]] = 0.5; 
  vconst = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  v[vconst] = Vector<double> {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}; 
```

## Access vector elements using an C++11 `initializer_list` of indices
### Element access `Vector[initializer_list]`

* The list can be smaller than or greater than or equal to the length to the data Vector.
* The list can have repeated indices and indices can be in any order!


**EXAMPLE 2**: Access via a C++11 initializer_list
```C++
Vector<double> v( linspace<double>(0,1,11) );
v = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1}; 
```

**The result is**
```C++
  v[{0,4}] = Vector<double> {0, 0.4}; 
  v[{4,0,1,4}] = Vector<double> {0.4, 0, 0.1, 0.4}; 
  v[{1,0,2}] = Vector<double> {0.1, 0, 0.2}; 
  v[{4,3,2,1,0}] = Vector<double> {0.4, 0.3, 0.2, 0.1, 0}; 
  v[{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}] = Vector<double> {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2}; 
```


[Table of Contents](README.md)
