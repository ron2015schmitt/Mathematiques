
# Methods `Vector.sort()`, `Vector.uniq()`, `Vector.quniq()`   in Mathématiques
_This document was automatically generated from file_ **`vsort.cpp`** (Mathématiques-v3.2-r1).

## Sorting
* sorting is performed _in place_ via the `.sort()` method

* the indices for the sort are returned in a `Vector<index_type>`



**EXAMPLE 1**:  `Vector.sort()`
```C++
Vector<double> t( {23,-1,100,7});
Vector<double> y( {30,10,20,40} );
Vector<index_type> vindex;
vindex = t.sort();
y = y[vindex];
```

**The result is**
```C++
  t = {-1, 7, 23, 100}; 
  vindex = {1, 3, 0, 2}; 
  y = {10, 40, 10, 10}; 
```

## Removing duplicate elements
### The `.uniq()` method
* The `.uniq()` method operates _in place_, removing all duplicate values.

* The indices for the unique elements are returned in a `Vector<index_type>`



**EXAMPLE 2**: The `.uniq()` method
```C++
Vector<double> t( {23,-1,23,4,4,4,-1,3,3});
Vector<index_type> vindex;
vindex = t.uniq();
```

**The result is**
```C++
  t = {23, -1, 4, 3}; 
  vindex = {0, 1, 3, 7}; 
```

### The `.quniq()` method
* The `.quniq()` method operates _in place_, removing all _adjacent_ duplicate values.

* The indices for the unique elements are returned in a `Vector<index_type>`



**EXAMPLE 3**: The `.quniq()` method
```C++
Vector<double> t( {23,-1,23,4,4,4,-1,3,3});
Vector<index_type> vindex;
vindex = t.quniq();
```

**The result is**
```C++
  t = {23, -1, 23, 4, -1, 3}; 
  vindex = {0, 1, 2, 3, 6, 7}; 
```


[Table of Contents](README.md)
