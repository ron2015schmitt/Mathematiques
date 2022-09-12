[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.146-c++20</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Chapter  Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Status & Release Notes](../status-release/README.md)<br>
Chapter 4. [Introduction with Examples](../intro/README.md)<br>
Chapter 5. [Installation](../installation/README.md)<br>
Chapter 6. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 7. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 8. _Benchmarks_ <br>
Chapter 9. [Tests](../test/README.md)<br>
Chapter 10. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 8. Benchmarks



## Vector math benchmarks 

Here we compare _Mathematiques_ vs. a handcoded `C` array loops.

### mathq syntax 
```C++
Vector<double> x(N);
x = linspace<double>(0,1,N);
Vector<double> f(N);
start();
f = cos(2*pi + pi*sin(2*pi*x + pi/6));
stop();
```

### hand-coded `C` loop 
```C++
std::valarray<double> x(N);
for(int i=0; i<N; i++)
  x[i] = double(i)/double(N-1);
std::valarray<double> f(N);
start();
for(int i=0; i<N; i++)
     f[i] = cos(2*pi + pi*sin(2*pi*x[i] + pi/6));
stop();
```
### results

![benchmarks](../files/benchmark.png)


## dot product benchmarks
---------------------------------------------------------------------------
To be written...


| ⇦ <br />[Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)  | [Documentation](../README.md)<br />Benchmarks<br /><img width=1000/> | ⇨ <br />[Tests](../test/README.md)   |
| ------------ | :-------------------------------: | ------------ |

