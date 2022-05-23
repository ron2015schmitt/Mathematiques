
[Table of Contents](README.md)


# under the hood—`Vector` definition in Mathématiques
_This document was automatically generated from file_ **`vdefinition.cpp`** (Mathématiques-v3.2-r1).

* _This information is mostly irrelavent to usage but is provided for rare cases when you may want to access the underlying data type_.
### The Vector class is a wrapper
* The `mathq::Vector` wraps a `std::valarray`
* In the example below
  * `valias` is referenced to the valarray inside `vec`.

**EXAMPLE 1**: Getting the `valarray` wrapped by a `Vector`.

```C++
using namespace std;
Vector<double> vec({0,1,2,3}); // C++11 list
valarray<double>& valias = vec.getValArray();
vec[1] = -1;
valias[2] = -2;
```

**The result is**
```C++
  vec = {0, -1, -2, 3}; 
  valias = {0, -1, -2, 3}; 
```

### Getting the wrapped `valarray`/`array`
* In the example below
  * `vec` is constructed
  * `valias` is referenced to the valarray inside `vec`.

**EXAMPLE 2**: Setting and getting the wrapped `valarray`

```C++
using namespace std;
Vector<double> vec(2);
valarray<double>& valias = vec.getValArray();
vec[1] = 1;
valias[2] = 2;
```

**The result is**
```C++
  vec = {0, 1}; 
  valias = {0, 1}; 
```


[Table of Contents](README.md)
