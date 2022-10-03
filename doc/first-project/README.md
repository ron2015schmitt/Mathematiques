[<h1 style='border: 2px solid; text-align: center'>Mathématiques 0.42.1-alpha.024</h1>](../../README.md)

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
Chapter 9. [Installation](../installation/README.md)<br>
Chapter 10. _Your First Mathématiques Project_ <br>
Chapter 11. [Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)<br>
Chapter 12. [Benchmarks](../benchmarks/README.md)<br>
Chapter 13. [Tests](../test/README.md)<br>
Chapter 14. [Developer Guide: Modifying and Extending Mathématiques](../developer-guide/README.md)<br>


</details>



# Chapter 10. Your First Mathématiques Project


Now that you have completed installation, to use the Mathématiques library you need to 

## Overview

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## Compiling and running the example

The `Makefile` and `example.cpp` source in the `examples` subdirectory are the starting point for development.

Copy the files of the `examples` subdirectory into your account.  Assuming you are in the top level directory of Mathematiques, run the following commands:
```bash
mkdir ~/my-first-mathq-project/
cp examples/* ~/my-first-mathq-project/
```
Now compile `example.cpp` and run 
```bash
cd ~/my-first-mathq-project/
make example
./example
```


## Delaing with Errors

To see verbose error messages for your project, use

```bash
make example "COPT=--verbose"
```

For help, use

```bash
make help
```

For a list of all Makefile variables and their values, use
```bash
make info
```


## What's in the files?

The contents `Makefile` and `example.cpp` are listed below for convenience.

## example.cpp

```C++

#include <iostream>
#include <fstream>
#include <string>

#include "mathq.h"

void printoptsfile() {
  std::ifstream myfile;
  myfile.open("example.compiler");
  std::string myline;
  if (myfile.is_open()) {
    while (myfile) {
      std::getline(myfile, myline);
      std::cout << myline << '\n';
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
}

int main(int argc, char* argv[]) {
  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace mathq;
  using namespace display;

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << CREATESTYLE(BOLD).apply(myname) << std::endl;

  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  print_mathq_info();
  printoptsfile();

  Vector<double> v1(linspace<double>(-1, 1, 21));
  Vector<double> v2;
  v2 = 10 * sin(pi / 2 * v1) + 10;

  DISP(v1);
  DISP(v2);
  DISP(v1 + v2);

  // dot product
  DISP(v1 | v2);

  const double N = double(v2.size());
  // mean
  double mu2 = sum(v2) / N;

  // std deviation
  double sigma2 = norm(v2 - mu2) / sqrt(N - 1);

  MDISP(mu2, sigma2);

  CR();
  MOUT << "done: " << CREATESTYLE(BOLD).apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
```


<br>
<br>


## Makefile

```Makefile
##############################################################################################
# Mathematiques 0.42.1-alpha.023 User Code Makefile
#
# Copy this Makefile to your project directory
#
# Mon Oct  3 14:01:27 EDT 2022
#
# This Makefile was created by [BUILD_PARENT_DIR]/Mathematiques/configure from
#   [BUILD_PARENT_DIR]/Mathematiques/make-lib/variables.mk
#   [BUILD_PARENT_DIR]/Mathematiques/make-lib/example.variables.mk
#   [BUILD_PARENT_DIR]/Mathematiques/make-lib/recipes.mk
#   [BUILD_PARENT_DIR]/Mathematiques/make-lib/example.recipes.mk
##############################################################################################

DIR_MATHQ := [BUILD_PARENT_DIR]/Mathematiques

##############################################################################################
##############################################################################################
#                                       VARIABLES
##############################################################################################
##############################################################################################

###########################################################
# GENERAL VARS
###########################################################

SHELL := /bin/bash

# dynamic variables

PWD = $(shell pwd)
FIRST_MAKEFILE = $(abspath $(firstword $(MAKEFILE_LIST)))
WHOAMI = $(abspath $(lastword $(MAKEFILE_LIST)))
WHEREAMI = $(dir $(WHOAMI))

# dynamic variables

# all sub-directories
SUBS = $(wildcard */)

# all sub makefiles
SUBMAKES = $(wildcard */Makefile)
# all sub-directories with makefiles
MAKE_SUBDIRS = $(dir $(SUBMAKES))
MAKECLEAN_SUBDIRS = $(addprefix makeclean_,$(MAKE_SUBDIRS))

# all sub-directories without makefiles
NOMAKE_SUBDIRS = $(filter-out $(MAKE_SUBDIRS),$(SUBS))
NOMAKECLEAN_SUBDIRS = $(addprefix nomakeclean_,$(NOMAKE_SUBDIRS))


# Each Makefile that has an include statement for this file should:
#  - define a variable EXEC that includes of the executable targets
NONEXEC ?=
EXEC ?=
ALL ?=

# Each Makefile that has an include statement for this file should:
#  - define a variable ALL that includes any targets that are 
#    NOT part of "nonrecurse" nor "$(SUBMAKES)" but that should be
#    built for the "all" target defined in this file




###############################################################
# ITEMS SPECIFIC TO MATHQ FILES and DIRS
###############################################################

# static variables
MAKEDIR_MATHQ := $(DIR_MATHQ)/make-lib
TAG_FILE_MATHQ := $(DIR_MATHQ)/versioning/tag.mathq.out.txt

# dynamic variables
TAG_MATHQ = `cat $(TAG_FILE_MATHQ)`


# These vairables are used only for building Matehmatiques
# ie are not needed by the end user code
#
#  FEATURE_VERSION_MATHQ_FILE should be a bash file with: export FEATURE_VERSION_MATHQ=X.X

#scripts
CREATE_RUN := $(DIR_MATHQ)/scripts/create_run.bash

# static variables
TAG_ANNOTATION_FILE := $(DIR_MATHQ)/versioning/tag.annotation.mathq.out.txt
CPP_VERSION_FILE := $(DIR_MATHQ)/versioning/c++.version.src.txt
PRERELEASE_TAG_FILE := $(DIR_MATHQ)/versioning/prerelease.tag.src.txt
VERSION_HEADER_FILE_MATHQ := $(DIR_MATHQ)/include/version_mathq.h
FEATURE_VERSION_MATHQ_FILE := $(DIR_MATHQ)/versioning/feature.version.master.record.bash
COMPILER_VERSION_FILE := $(DIR_MATHQ)/versioning/config.compiler.out.txt

# dynamic variables
FEATURE_VERSION_MATHQ = `. $(FEATURE_VERSION_MATHQ_FILE) && echo "$${FEATURE_VERSION_MATHQ}"`
CPP_VERSION_MATHQ = `cat $(CPP_VERSION_FILE)`
PRERELEASE_TAG_MATHQ = `cat $(PRERELEASE_TAG_FILE)`


####################################################################
# VARIABLES SPECIFIC TO includes and libs for compilers and linkers
####################################################################

INCDIR_MATHQ := $(DIR_MATHQ)/include
INCLUDES := -I $(INCDIR_MATHQ) 

LIB_LAPACK := -llapack -lg2c

LIBDIR_MATHQ := $(DIR_MATHQ)/lib
LIBNAME_MATHQ += mathq
LIBFILE_MATHQ := $(LIBDIR_MATHQ)/lib$(LIBNAME_MATHQ).a
LIB_MATHQ := -l$(LIBNAME_MATHQ)

LIBS := -L$(LIBDIR_MATHQ) $(LIB_MATHQ)



####################################################################
# Compiler and Linker flags 
####################################################################

####################################################################
# g++ COMPILER
#
# make help-g++
#      This will give a nice shortened summary of options.
#
# For full details of options and up to date list see:
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
####################################################################

# COPT provided at the command line will append to options
override COPT ?=  -Wfatal-errors

# OPTIMIZE provided at the command line will supercede the following
#          That is the values below will be written over.
OPTIMIZE ?= -O2

CFLAGS = $(OPTIMIZE) $(COPT) $(INCLUDES)

CPP = g++
CPP_CMD = $(CPP) -pipe -std=$(CPP_VERSION_MATHQ)

ifdef MATHQ_DEBUG
CFLAGS += -D "MATHQ_DEBUG=$(MATHQ_DEBUG)"
endif


####################################################################
# gfortran COMPILER
####################################################################
FC = gfortran
override FOPT ?=
FFLAGS = $(FOPT)
LNK_FFLAGS = -lgfortran +fgcse-after-reload

####################################################################
# g++ linker
# LOPT provided at the command line will append to options
####################################################################
override LOPT ?=
LFLAGS = $(OPTIMIZE) $(LOPT)


MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include $(DIR_MATHQ)/make-lib/style.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))


####################################################################
################## PROJECT SPECIFIC VARIABLES ######################
####################################################################
EXEC += example example2 example-matrices example3
ALL += run gitignore
####################################################################


#---------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------
#                                         RECIPES
#---------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------


#---------------------------------------------------------------------
#  SPECIAL RECIPES -- THESE MUST BE FIRST
#---------------------------------------------------------------------

# force these to always run regardless if prereq's are older or newer
.PHONY: run gitignore clean cleanall cleansubs

# Each Makefile that has an include statement for this file should define a target "some" that makes all targets in that directory but not in subdirectories
default: some

#prevent any default rules from being used
.SUFFIXES:

# don't delete these files after compilation
.PRECIOUS: %.o 

FORCE: ;

# this forces all recipes to use a single shell
# note: ***make only reads the '@','-','+' prefixes of the first line in one shell!!!
.ONESHELL:



#---------------------------------------------------------------------
# g++ COMPILER
#
# For full details of options and up to date list see:
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
#---------------------------------------------------------------------

define generate_compiler_file
	@\date > $1.compiler
	@\echo -e "Mathématiques $(TAG_MATHQ)" >> $1.compiler
	@\lsb_release -d  >> $1.compiler 2>/dev/null
	@\echo -e `$(CPP) --version | head -1` >> $1.compiler
	@\echo -e "$(CPP_CMD) $(CFLAGS)" >> $1.compiler
endef


%.o: %.cpp 
	$(call generate_compiler_file,$*)
	$(CPP_CMD) $(CFLAGS) -c $*.cpp -o $@


%.s: %.cpp 
	\echo -e "compiler command used:  $(CPP_CMD) $(CFLAGS)" > $*.compiler
	$(CPP_CMD) $(CFLAGS) -S $*.cpp 

%.ii: %.cpp 
	\echo -e "compiler command used:  $(CPP_CMD) $(CFLAGS)" > $*.compiler
	$(CPP_CMD) $(CFLAGS) -E $*.cpp -o $@


#---------------------------------------------------------------------
# gfortran COMPILER
#---------------------------------------------------------------------
%.o: %.f 
	$(FC) $(FFLAGS) -c $*.f -o $*.o


#---------------------------------------------------------------------
# g++ linker
# LOPT provided at the command line will append to options
#---------------------------------------------------------------------
%: %.o 
	$(CPP_CMD) $(LFLAGS) $*.o -o $@ $(LIBS) 


#---------------------------------------------------------------------
# MATHQ related recipes
#---------------------------------------------------------------------


# This is used to recursively build - it calls the every subdirectory Makefile
$(MAKE_SUBDIRS): FORCE
	$(MAKE) -C $@ all

testsubs: FORCE
	@echo $(SUBS)
	@echo $(SUBMAKES)
	@echo $(MAKE_SUBDIRS)
	@echo $(MAKECLEAN_SUBDIRS)


some: $(NONEXEC) $(EXEC)

# Target "all" build everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - define a target "some" that makes all targets in that directory but not in subdirectories
all: $(NONEXEC) $(EXEC) $(ALL) $(MAKE_SUBDIRS) 


# creates a run file that executes all the $(EXEC) files
#  we can't detect changes in EXEC so force it
run: 
	@$(CREATE_RUN) $(EXEC)

# creates a .gitignore files for all the $(EXEC) files
#  we can't detect changes in EXEC so force it
gitignore: 
	@\echo -e ${BOLD}${BLUE}"Creating .gitignore file..."${DEFCLR}${NORMAL} 
	@\echo -e '# ****  This was created by the command "make gitignore".' > .gitignore
	@\echo -e '# ****  Do NOT manually edit.' >> .gitignore
	@\echo -e "/run" >> .gitignore
	@for name in $(EXEC)
	@do
	@  \printf "/$${name}\n" >> .gitignore
	@done


#---------------------------------------------------------------------
# CLEANING
#---------------------------------------------------------------------

# Each Makefile that has an include statement for this file should:
#  - define a "clean" target with "cleanstd" as a prerequisite
clean:: FORCE 
	@command rm -f *.o *.a *.s *.compiler core.* node.json *.temp.md
	@command rm -f $(EXEC) $(NONEXEC) 


makeclean_%: FORCE
	@$(MAKE) -C $* cleanall

nomakeclean_%: FORCE
	@echo "nomakeclean_$(*)"
# ONSHELL is on
	@cd $(*)  
	@command rm -f *.o *.a *.s *.compiler core.* *.temp *.tmp *~ ~* *.gz *.tar *.old node.json *.temp.md
#  DONT NEED ANYMORE: if body.cpp exists then body.md is an output file not a source
#	@if [[ -f body.cpp ]] ; then command rm -f body.md; fi

cleansubs:: $(MAKECLEAN_SUBDIRS) $(NOMAKECLEAN_SUBDIRS)


# Target "cleansall" cleans everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - can (but not necessary) define a "cleanall" target
cleanall:: FORCE clean cleansubs
	@\rm -f run *.temp *.tmp *~ ~* *.gz *.tar *.old 
	@\rm -f $(ALL)

include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk
#--------------------------------------------------------------------------
# --------------- PROJECT SPECIFIC RECIPES---------------------------------
#--------------------------------------------------------------------------

clean:: 

#--------------------------------------------------------------------------

```


<br>
<br>

/home/rs2015/Mathematiques/doc


| ⇦ <br />[Installation](../installation/README.md)  | [Documentation](../README.md)<br />Your First Mathématiques Project<br /><img width=1000/> | ⇨ <br />[Usage Guide: Syntax, Data Types, Functions, etc](../user-guide/README.md)   |
| ------------ | :-------------------------------: | ------------ |

