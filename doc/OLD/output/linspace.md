
[Table of Contents](README.md)


# The `linspace` functions in Mathématiques
_This document was automatically generated from file_ **`linspace.cpp`** (Mathématiques-v3.2-r1).

## The `linspace` function: numerical interval [a,b]
* The function `linspace<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a` to `b`, spaced by `(b-a)/(N-1)`
* Note that `b` can be less than `a`, in which case the returned sequence is decreasing
```C++
linspace<double>(100,400,4) = {100, 200, 300, 400}; 
linspace<unsigned int>(1,2,2) = {1, 2}; 
linspace<double>(0,1,11) = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1}; 
linspace<double>(1,0,11) = {1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0}; 
```
## The `linspace_a` function: numerical interval (a,b]
* The function `linspace_a<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a+delta` to `b`, where `delta=(b-a)/(N)` is the spacing between consecutive points.
* Note that `b` can be less than `a`, in which case the returned sequence is decreasing
```C++
linspace_a<double>(0,1,10) = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1}; 
linspace_a<double>(1,0,10) = {0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0}; 
```
## The `linspace_b` function: numerical interval [a,b)
* The function `linspace_b<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a` to `b-delta`, where `delta=(b-a)/(N)` is the spacing between consecutive points.
* Note that `b` can be less than `a`, in which case the returned sequence is decreasing
```C++
linspace_b<double>(0,1,10) = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9}; 
linspace_b<double>(1,0,10) = {1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1}; 
```
* This function is very useful for dealing the domain of trig functions, since typicallywe want to use the **interval [0,2*pi)**, ie we dont want to include the point 2*pi
## The `linspace_ab` function: numerical interval (a,b)
* The function `linspace_ab<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a+delta` to `b-delta`, where `delta=(b-a)/(N+1)` is the spacing between consecutive points.
* Note that `b` can be less than `a`, in which case the returned sequence is decreasing
```C++
linspace_ab<double>(0,1,9) = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9}; 
linspace_ab<double>(1,0,9) = {0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1}; 
```

[Table of Contents](README.md)
