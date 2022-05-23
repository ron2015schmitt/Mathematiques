
[Table of Contents](README.md)


# Vector declaration in Mathématiques
_This document was automatically generated from file_ **`vdeclaration.cpp`** (Mathématiques-v3.2-r1).

**EXAMPLE 1**: Declare vector `v` (initialize to zeros).
```C++
const size_type N = 4;
Vector<double> v(N);
```
**The result is**
```C++
  v = {0, 0, 0, 0}; 
```

**EXAMPLE 2**: Declare `v` and initialize to a constant
```C++
Vector<double> v(4, -1 );
```
**The result is**
```C++
  v = {-1, -1, -1, -1}; 
```

**EXAMPLE 3**: Declare `v` and initialize to a **C-style array** of values

In debug mode, this produces a warning, as shown below
```C++
Vector<double> v( 4, (const double[]) {10, 20, 30, 40} );
```
**The result is**
```C++
  v = {10, 20, 30, 40}; 
```

**EXAMPLE 4**: Declare `v` and initialize directly from a list (**__C++11__**)
```C++
Vector<double> v({10, 20, 30, 40});
```
**The result is**
```C++
  v = {10, 20, 30, 40}; 
```

**EXAMPLE 5**: Declare `v2` and initialize to values of `v1`
* Note that this is a _copy_ constructor.
* In fact _all_ of the `Vector` constructors are _copy_ constructors.
```C++
Vector<double> v1( {10,11,12,13} ); // C++11 list
Vector<double> v2(v1);
v1[0] = -1;
v2[0] = -2;
```
**The result is**
```C++
  v1 = {-1, 11, 12, 13}; 
  v2 = {-2, 11, 12, 13}; 
```

**EXAMPLE 6**: Declare `v2` and initialize to an expression
* The expression is computed without creating any intermediate objects.
```C++
Vector<double> v1({10,11,12,13} ); // C++11 list
Vector<double> v2(10*v1+1);
```
**The result is**
```C++
  v1 = {10, 11, 12, 13}; 
  v2 = {101, 111, 121, 131}; 
```


[Table of Contents](README.md)
