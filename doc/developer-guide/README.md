<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.78-c++17</h1>

<details>

<summary>User Manual</summary>

# [User Manual](../README.md)<br>
1. [About](../about/README.md)<br>
2. [License](../license/README.md)<br>
3. [Status, Planned Work & Release Notes](../status-release/README.md)<br>
4. [Description and Example Usage](../description-examples/README.md)<br>
5. [Installation](../installation/README.md)<br>
6. [Your First Mathématiques Project](../first-project/README.md)<br>
7. [Usage Guide: Syntax, Data Types, Functions, etc](../usage-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. _Developer Guide: Modifying and Extending Mathématiques_ <br>


</details>



# 10. Developer Guide: Modifying and Extending Mathématiques


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


| ⇦ <br />[Tests](../test/README.md)  | [User Manual](../README.md)<br />Developer Guide: Modifying and Extending Mathématiques<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

