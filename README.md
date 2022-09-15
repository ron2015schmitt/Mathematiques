

# Mathématiques v0.41.158-c++20


## Phase 1 (in progress): C++ Numerical Library
  
Using modern C++ (C++20), create an extensive, open source, numerical C++ library that provides / supports

* compact **data structures** that represent **mathematical objects** 
* user **code that looks like mathematical notation**
* **state of the art performance** (both speed and memory usage)
* **multithreading**
* convenient **pretty printing of results** including **data type information**
* several **compilation modes** (DEBUG, PRODUCTION) via command line flags and the C++ macro preprocessor
  + **DEBUG mode** checks bounds, vector and matrix sizes, etc and generates clear, pretty printed errors to stderr
  + **PRODUCTION mode** runs as without any checks
* **i/o in popular formats** for analysis and plotting

<br>

**Function of a vector**

$\mathbf{w} = 1 + 10 \mathbf{v} + e^{i  [   2 \pi   +   \pi sin(  2 \mathbf{v} + \pi / 6  )   ] }$ 

```C++
w = 1 + 10 * v + exp(i * (2 * pi + pi * sin(2 * pi * v + pi / 6)));
```

<br>

**Linear Algebra**

$\mathbf{y} = \mathbf{A} \cdot \mathbf{x}$

$\mathbf{y} = \mathbf{x}^\dagger \cdot ( \mathbf{A} \mathbf{A^\dagger} + \mathbf{A^\dagger} \mathbf{A}) \cdot \mathbf{x}$

```C++
y = A | x;
y = ~x | (A|~A + ~A|A) | x;
```


<br>

**Vector Calculus**

$\mathbf{E} = \mathbf{\nabla} \cdot \mathbf{\Phi}$


```C++
E = nabla | Phi;
```

<br>

**Number Systems**

```C++
double x = 23.2;
Imaginary<double> y = 5*i;
std::complex<double> z = 3 + 4*i;
Quaternion<double> q = 16 + 2*i + 3*j + 13*k;
```


<br>

**Special Functions**

$f(x) = \Gamma(x)$ 

$g(x) = J_\nu(x)$ 

```C++
Vector<double> x = linspace(0., 1., 100);
Vector<double> f = tgamma(x);
Vector<double> g = cyl_bessel_j(nu, x);
```


<br>

✳ [Introduction with Examples](doc/intro/README.md) ✳ 

[Benchmarks](doc/benchmarks/README.md)

[Full Documentation](doc/README.md)

<br>

---------------------------------
## Phase 2 (planned): Symbolic Mathematics Built into a Modern High-Performance Language

Create a new language that implements the phase 1 library above plus
* supports unicode characters in source code 
  + supports greek language characters for variables
  + supports operator definitions for mathematical unicode symbols so that the code really looks like mathematical notation
  + also has multi-character ASCII symbols for each unicode symbol
* modern, cloud-based module/package loader
* package repository site, eg [npm for NodeJs](https://www.npmjs.com/) for user-created open-source packages
* web API for remote computation, likely using [gRPC](https://en.wikipedia.org/wiki/GRPC) and [GraphQL](https://en.wikipedia.org/wiki/GraphQL)

The current language candidates to build upon are [Rust](https://en.wikipedia.org/wiki/Rust_(programming_language)) and [Carbon](https://en.wikipedia.org/wiki/Carbon_(programming_language)).

