[<h1 style='border: 2px solid; text-align: center'>Mathématiques v0.41.140-c++20</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Chapter  Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Status, Planned Work & Release Notes](../status-release/README.md)<br>
Chapter 4. [Introduction with Examples](../intro/README.md)<br>
Chapter 5. _Installation_ <br>
Chapter 6. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 7. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 8. [Benchmarks](../benchmarks/README.md)<br>
Chapter 9. [Tests](../test/README.md)<br>
Chapter 10. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 5. Installation



## Install Prerequisites

The following commands are required: `bash`, `python3`, `make`, `g++`, and `gfortran`.

The following library is required: `lapack`.

In Ubuntu, you can install these as follows
```bash
sudo apt update
sudo apt upgrade
sudo apt-get install build-essential gfortran liblapacke-dev liblapack-doc
```
The above installation has been verified in [Ubuntu 20.04 LTS](https://releases.ubuntu.com/20.04/)

<a name="docker-images"></a>
### Docker images for the build environment

Docker build files and images are available with all of the prerequisites installed

| O/S  | Build file | Image |
| ----------- | ----------- | ----------- |
| [Ubuntu 20.04 LTS](https://releases.ubuntu.com/20.04/) | [Dockerfile](https://github.com/ron2015schmitt/Mathematiques/tree/master/docker/ubuntu-20.04) | [Image](https://hub.docker.com/repository/docker/electron2015/ubuntu-20.04-mathq-env) |

*The above images do NOT contain the Mathématiques library*

## Download the source

The first step is to clone the repo from a Linux terminal

```bash
git clone https://github.com/ron2015schmitt/Mathematiques.git
```

You now have a directory with all the Mathématiques source code

## Run the configuration and build the library

From the same Linux terminal execute the following commands:

```bash
cd Mathematiques
./configure
make all
```

## Testing

Execute the following commands to perform a quick test:

```bash
make run
```

After executing has completed, the last output line should read:

```text
All executables in all subdirectories PASSED
```
in green text.

We do not yet have full code coverage testing.



| ⇦ <br />[Introduction with Examples](../intro/README.md)  | [Documentation](../README.md)<br />Installation<br /><img width=1000/> | ⇨ <br />[Your First Mathématiques Project](../first-project/README.md)   |
| ------------ | :-------------------------------: | ------------ |

