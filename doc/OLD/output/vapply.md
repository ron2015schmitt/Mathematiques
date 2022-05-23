
[Table of Contents](README.md)


# Applying User-defined functions in Mathématiques
_This document was automatically generated from file_ **`vapply.cpp`** (Mathématiques-v3.2-r1).

As an example, consider the following user-defined function `pos`, which forces negative values to zero.  Mathematically this is x*u(x), where u(x) is the (_Heaviside_) unit step function. 

```C++
template <class D> 
D pos(D x) {
  return (x>=0) ? x : 0;
}
```

**Some expressions with results**: `pos` function
```C++

  pos(-5) = 0; 
  pos(5) = 5; 
```


### Applying User-defined functions via `op1`

* The simplest way to apply a user-defined function is to use the function `op1<D,funcname>(Vector<D> v)`.
* This form can be used in `Vector` expressions

**EXAMPLE 1**: Applying User-defined function `pos` via `op1`

```C++
using namespace std;
Vector<double> v1(linspace<double>(-1,1,11) );
Vector<int> v2(range<int>(-2,2));
```

**Some expressions with results**: Applying User-defined function `pos` via `op1`
```C++
  op1(pos<double>,v1) = Vector<double> {0, 0, 0, 0, 0, 0, 0.2, 0.4, 0.6, 0.8, 1}; 
  op1(pos<int>,v2) = Vector<int> {0, 0, 0, 1, 2}; 
  2*v1 + op1(pos<double>, 2.3*sin(3.14159265358979323846*v1) ) = Vector<double> {-2, -1.6, -1.2, -0.8, -0.4, 0, 1.75191, 2.98743, 3.38743, 2.95191, 2}; 
```


### Applying User-defined binary functions via `op2`

* A similar function exists for binary user-defined functions: `op2<D,funcname>(Vector<D> v1, Vector<D> v2)`.
* This form can be used in `Vector` expressions as well.

**EXAMPLE 2**: Applying a function `ploy` via `op2`

```C++
double poly(double x, double y) { 
  return 5*x - 3*y*y*y;
}
Vector<double> v1(linspace<double>(-1,1,11) );
Vector<double> v2(11,0.25);
```

**The result is**
```C++
  v1 = {-1, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1}; 
  v2 = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25}; 
  op2(poly,v1,v2) = Vector<double> {-5.04688, -4.04688, -3.04688, -2.04687, -1.04687, -0.046875, 0.953125, 1.95313, 2.95313, 3.95312, 4.95312}; 
```


[Table of Contents](README.md)
