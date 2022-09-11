[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.139-c++20</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Chapter  Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Status, Planned Work & Release Notes](../status-release/README.md)<br>
Chapter 4. [Introduction with Examples](../intro/README.md)<br>
Chapter 5. [Installation](../installation/README.md)<br>
Chapter 6. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 7. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 8. [Benchmarks](../benchmarks/README.md)<br>
Chapter 9. [Tests](../test/README.md)<br>
Chapter 10. _Developer Guide: Modifying and Extending Mathématiques_ <br>


</details>



# Chapter 10. Developer Guide: Modifying and Extending Mathématiques


🚧 *in progress...*

## Topics to cover

1. ```configure```, ```deconfigure```, ```reconfigure```
3. Makefiles
4. Use of Python for metacoding
   1. use `python3` not `python` in code
   2. how to run
6. git tag versioning: ```files.matricks.vers```, ```reconfigure``` and ```make git```
7. multi-threading makefiles
8. directories:
   1. ```example```
   1. ```test``` (including metacode for test generation)
   1. ```benchmark```
   1. ```doc``` as well as scripts ```build``` and ```build1``` and ```toc```
   1. ```sandbox```

# Release Checklist

* Update `files/matricks.vers`
* `reconfigure`
* update README
* Update docs
* git push
* clone from github into a separate directory and verify all code compiles and works

# Online Documentation

When adding or removing chapters in the main TOC
+ edit the `CHAPTERS` variable in `doc/Makefile`
+ edit the `doc/toc.txt`


| ⇦ <br />[Tests](../test/README.md)  | [Documentation](../README.md)<br />Developer Guide: Modifying and Extending Mathématiques<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

