[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.038</h1>](../../README.md)

<details>

<summary>Documentation</summary>

# [Documentation](../README.md)<br>
Chapter 1. [License](../license/README.md)<br>
Chapter 2. [About](../about/README.md)<br>
Chapter 3. [Why?](../why/README.md)<br>
Chapter 4. [Objectives](../objectives/README.md)<br>
Chapter 5. [Versioning](../versioning/README.md)<br>
Chapter 6. [Status & Release Notes](../status-release/README.md)<br>
Chapter 7. [Upcoming Development](../development-schedule/README.md)<br>
Chapter 8. [Introduction with Examples](../intro/README.md)<br>
Chapter 9. _Installation_ <br>
Chapter 10. [Your First Mathématiques Project](../first-project/README.md)<br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 12. [Benchmarks](../benchmarks/README.md)<br>
Chapter 13. [Tests](../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 9. Installation



## Install Prerequisites

The following commands are required on your operating system: `bash`, `python3`, `make`, `g++`, and `gfortran`.

The version of `g++` must be `11.2.0` or higher.

The following library is required: `lapack`.

## Installation in Ubuntu 22.04

Download and install [Ubuntu 22.04 LTS](https://releases.ubuntu.com/22.04/).

In Ubuntu, you can install these as follows
```bash
sudo apt update
sudo apt upgrade
sudo apt-get install build-essential gfortran liblapacke-dev liblapack-doc
```

Verify the version for `g++` is `11.2.0` or higher as follows
```bash
g++ --version 
```


<a name="docker-images"></a>
### Docker images for the build environment

Docker build files and images are available with all of the prerequisites installed

| O/S  | Build file | Image |
| ----------- | ----------- | ----------- |
| [Ubuntu 22.04 LTS](https://releases.ubuntu.com/22.04/) | [Dockerfile](https://github.com/ron2015schmitt/Mathematiques/tree/master/docker/ubuntu-22.04) | [Image](https://hub.docker.com/repository/docker/electron2015/ubuntu-22.04-mathq-env) |

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

