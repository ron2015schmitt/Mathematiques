

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

