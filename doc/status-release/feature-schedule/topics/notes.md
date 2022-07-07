
1. updating `g++`

```bash
g++ --version
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt update
sudo apt install build-essential
sudo apt -y install g++-9 g++-10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10
g++ --version
sudo update-alternatives --config g++
```

1. [dialects suppported by `g++`](https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html)

This is set using the `-std=<dialect>`  option

Currently using `c++20` and `g++ 10.3`

1. [g++ release list](https://gcc.gnu.org/releases.html)

1. turning an object "inside out" is referred to as __eversion__

1. template parameter packs, eg `size_t... dims`, cannot have a default value

1. You cannot specify or even determine the number of paramters for C-style variadic function parameters.  You have to pass the size first or have the size as a template and hope the user doesn't provide less because it will segmentation fault.  Same problem as arrays.

1. for the `Vector = MultiArray<Element, 1, N1>` specialization, Vector can be used for the constructor but it must be specified as `Vector<Element, N1>()`. The decontructor must be `~Vector()`. Best to use MultiArray instead