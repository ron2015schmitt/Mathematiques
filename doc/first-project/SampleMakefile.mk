#
# ****  THIS IS AN EXAMPLE USER MAKEFILE WITH LOTS OF FEATURES***
# ****  THIS WAS CREATED DURING  CONFIGURATION ******************


##################################################################
#  ./configure                                                   #
##################################################################
EXEC += example
##################################################################
#  files/Makefile                                                #
##################################################################

#SOME USEFUL DEFINITIONS
SHELL:=/bin/bash


# TEXT ATTRIBUTES
BLACK :='\033[0;30m'
RED   :='\033[0;31m'
GREEN  :='\033[0;32m'
YELLLOW  :='\033[0;33m'
BLUE  :='\033[0;34m'
MAGENTA  :='\033[0;35m'
CYAN  :='\033[0;36m'
GRAYlIGHT  :='\033[0;37m'
DEFCLR:='\033[0;39m'
GRAYDARK  :='\033[0;90m'
REDLIGHT  :='\033[0;91m'
GREENLIGHT  :='\033[0;92m'
YELLOWLGIHT  :='\033[0;93m'
BLUELIGHT  :='\033[0;94m'
MAGNETALIGHT  :='\033[0;95m'
CYANLIGHT  :='\033[0;96m'
WHITE  :='\033[0;97m'

BOLD:='\e[0;1m'
BOLD_OFF:='\e[0;0m'

UNDERLINEON:='\e[0;4m'
UNDERLINEOFF:='\e[0;0m'

EXECUTABLES = $(shell find . -type f -executable)

where-am-i = $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))
THIS_MAKEFILE := $(call where-am-i)

define echovar
 echo -e $(BOLD)"${1}"$(BOLD_OFF)" = ${${1}}"
endef

define title
 echo -e $(BLUE)"${1}"$(DEFCLR)
endef

define hr
 echo -e $(BOLD)"-------------------------------------------------------------------------------"$(BOLD_OFF)
endef



###########################################################
#  SPECIAL TARGETS
###########################################################

.PHONY: default
default: makecleanall

#prevent any default rules from being used
.SUFFIXES:

# don't delete .o files
.PRECIOUS: %.o %_opts.cpp

EXEC ?=


#############################################################################
# g++ OPTIMIZATIONS (provided at compile and link time)
#
# Note from
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
# OPTIMIZE provided at the command line will supercede the following
#          That is the values below will be written over.
##############################################################################
#
# -O0
#     Reduce compilation time and make debugging produce the expected results.
#     This is the DEFAULT.
#     Option -Og completely disables a number of optimization passes so
#     that individual options controlling them have no effect.
#
# -O1 (or -O)
#     Optimize. Optimizing compilation takes somewhat more time, and a lot
#     more memory for a large function.
#       -fauto-inc-dec            -fbranch-count-reg
#       -fcombine-stack-adjustments
#       -fcompare-elim            -fcprop-registers
#       -fdce                     -fdefer-pop
#       -fdelayed-branch          -fdse
#       -fforward-propagate       -fguess-branch-probability
#       -fif-conversion           -fif-conversion2
#       -finline-functions-called-once
#       -fipa-profile             -fipa-pure-const
#       -fipa-reference           -fipa-reference-addressable
#       -fmerge-constants         -fmove-loop-invariants
#       -fomit-frame-pointer      -freorder-blocks
#       -fshrink-wrap             -fshrink-wrap-separate
#	-fsplit-wide-types        -fssa-backprop
#       -fssa-phiopt              -ftree-bit-ccp
#       -ftree-ccp                -ftree-ch
#       -ftree-coalesce-vars      -ftree-copy-prop
#       -ftree-dce                -ftree-dominator-opts
#       -ftree-dse                -ftree-forwprop
#       -ftree-fre                -ftree-phiprop
#       -ftree-pta                -ftree-scev-cprop
#       -ftree-sink               -ftree-slsr
#       -ftree-sra                -ftree-ter
#       -funit-at-a-time
#
# -O2
#     Optimize even more. GCC performs nearly all supported optimizations
#     that do not involve a space-speed tradeoff. The compiler does not
#     perform loop unrolling or function inlining when you specify -O2.
#     As compared to -O, this option increases both compilation time and
#     the performance of the generated code.  This includes all the -O1
#     optimizations plus:
#       -finline-functions        -funswitch-loops,
#       -fpredictive-commoning    -fgcse-after-reload
#       -ftree-vectorize options  -fgcse-after-reload 
#       -finline-functions        -fipa-cp-clone
#       -floop-interchange        -floop-unroll-and-jam 
#       -fpeel-loops              -fpredictive-commoning
#       -fsplit-paths             -ftree-loop-distribute-patterns
#       -ftree-loop-distribution  -ftree-loop-vectorize
#       -ftree-partial-pre        -ftree-slp-vectorize
#       -funswitch-loops          -fvect-cost-model
#                                 -fversion-loops-for-strides
#     Please note the warning under -fgcse about invoking -O2
#     on programs that use COMPUTED GOTOS (eg FORTRAN).
#
# -O3
#     Optimize yet more. -O3 turns on all optimizations specified by -O2
#     and also turns on the
#       -fgcse-after-reload       -finline-functions
#       -fipa-cp-clone            -floop-interchange
#       -floop-unroll-and-jam     -fpeel-loops
#       -fpredictive-commoning    -fsplit-paths
#                                 -ftree-loop-distribute-patterns
#       -ftree-loop-distribution  -ftree-loop-vectorize
#       -ftree-partial-pre        -ftree-slp-vectorize
#       -funswitch-loops          -fvect-cost-model
#                                 -fversion-loops-for-strides
# -Os
#     Optimize for size. -Os enables all -O2 optimizations that do not
#     typically increase code size. It also performs further optimizations
#     designed to reduce code size.
#     Specifically -Os enables all -O2 optimizations except those that
#     often increase code size:
#       -falign-functions         -falign-jumps
#       -falign-labels            -falign-loops
#       -fprefetch-loop-arrays    -freorder-blocks-algorithm=stc
#
#     It also enables
#       -finline-functions
#     causes the compiler to tune for
#     code size rather than execution speed, and performs further
#     optimizations designed to reduce code size.
#
#-Ofast
#     Disregard strict standards compliance. -Ofast enables all -O3
#     optimizations. It also enables optimizations that are not valid for
#     all standard-compliant programs. It turns on
#       -ffast-math
#       -fstack-arrays (FORTRAN-specific)
#     unless -fmax-stack-var-size is specified, and -fno-protect-parens.
#
#-Og  
#     Optimize debugging experience. -Og should be the optimization level of
#     choice for the standard edit-compile-debug cycle, offering a reasonable
#     level of optimization while maintaining fast compilation and a good
#     debugging experience. It is a better choice than -O0 for producing
#     debuggable code because some compiler passes that collect debug
#     information are disabled at -O0.
#
#     Option -Og completely disables a number of optimization passes so
#     that individual options controlling them have no effect.
#     Otherwise -Og enables all -O1 optimization flags EXCEPT for those that may
#     interfere with debugging:
#       -fbranch-count-reg        -fdelayed-branch
#       -fdse                     -fif-conversion
#       -fif-conversion2          -finline-functions-called-once
#       -fmove-loop-invariants    -fssa-phiopt
#       -ftree-bit-ccp            -ftree-dse
#       -ftree-pta                -ftree-sra
#
# OTHER OPTIMZATIONS
#      -finline-functions
#      -finline-limit=750
###############################################################################
OPTIMIZE ?=



#############################################################################
# g++ COMPILER
# COPT provided at the command line will append to options
#############################################################################
CPPC = g++ -pipe --std=c++17 
override COPT ?=  -Wfatal-errors
CFLAGS = $(OPTIMIZE) $(COPT) $(INCLUDES)

%_opts.cpp:
	@echo "char COMPILE_OPTIMIZE[] = "'"'$(OPTIMIZE)'";' > $@
	@cat $@


%.o: %.cpp 
ifdef MATHQ_DEBUG
	$(CPPC) $(CFLAGS) -D"MATHQ_DEBUG=$(MATHQ_DEBUG)" -c $*.cpp -o $@
else
	$(CPPC) $(CFLAGS) -c $*.cpp -o $@
endif


#############################################################################
# gfortran COMPILER
#############################################################################
FC = gfortran
override FOPT ?=
FFLAGS = $(FOPT)
LNK_FFLAGS = -lgfortran +fgcse-after-reload

%.o: %.f 
	$(FC) $(FFLAGS) -c $*.f -o $*.o


#############################################################################
# g++ linker
# LOPT provided at the command line will append to options
#############################################################################
LNK = g++
override LOPT ?=
LFLAGS = $(OPTIMIZE) $(LOPT)

%: %.o %_opts.o
	$(CPPC) $(LFLAGS) $*.o $*_opts.o -o $@ $(LIBS) 



###########################################################
#      Full Informative Dump (This is default)
###########################################################

info:
	@echo
	@$(call hr)
	@$(call title,"Variables")
	@$(call echovar,SHELL)
	@$(call echovar,CURDIR)
	@$(call echovar,PWD)
	@$(call echovar,VPATH)
	@$(call echovar,MAKE)
	@$(call echovar,_)
	@$(call echovar,MAKECMDGOALS)
	@$(call echovar,MAKE_VERSION)
	@$(call echovar,MAKEFLAGS)
	@$(call echovar,GNUMAKEFLAGS)
	@$(call echovar,MAKEFILES)
	@$(call echovar,MAKEFILE_LIST)
	@$(call echovar,THIS_MAKEFILE)
	@$(call echovar,MAKE_HOST)
	@$(call echovar,MAKELEVEL)
	@echo
	@$(call title,"Includes")
	@$(call echovar,INCLUDES)
	@echo
	@$(call title,"Libraries")
	@$(call echovar,LIBS)
	@echo
	@$(call title,"Optimizations")
	@$(call echovar,OPTIMIZE)
	@echo
	@$(call title,"C++ Compiler")
	@$(call echovar,CPPC)
	@$(call echovar,COPT)
	@$(call echovar,CFLAGS)
	@echo
	@$(call title,"Fortran")
	@$(call echovar,FC)
	@$(call echovar,FOPT)
	@$(call echovar,LNK_FFLAGS)
	@echo
	@$(call title,"Linker")
	@$(call echovar,LNK)
	@$(call echovar,LOPT)
	@$(call echovar,LFLAGS)
	@$(call hr)
	@echo


diff:
	@diff Makefile.pristine.mk Makefile || exit 0

cdiff:
	@colordiff Makefile.pristine.mk Makefile || exit 0

clean:: FORCE
	@command rm -f *.o
	@command rm -f $(DOC)
	@command rm -f *.a
	@command rm -f *.s
	@command rm -f *_opts.*
	@command rm -f *.temp
	@command rm -f *.tmp
	@command rm -f *.link_md
	@command rm -f *~
	@command rm -f $(EXEC)
	@command rm -f core.*

cleanexec: FORCE
	@command rm -f $(EXECUTABLES)
FORCE:

all: $(EXEC) 

makecleanall:
	make -j clean
	make -j all


##################################################################
#  files/Makefile.mathq.mk                                       #
##################################################################


###############################################################
# ITEMS SPECIFIC TO MATHQ
###############################################################


DIR_MATHQ = /home/username/Mathematiques
INCDIR_MATHQ = $(DIR_MATHQ)/include
LIBDIR_MATHQ = $(DIR_MATHQ)/lib
LIB_MATHQ = -lmathq
INCLUDES += -I $(INCDIR_MATHQ) 
LIBS += -L$(LIBDIR_MATHQ) $(LIB_MATHQ)

#  FEATURE_VERSION_MATHQ_FILE should be a bash file with FEATURE_VERSION_MATHQ=X.X
FEATURE_VERSION_MATHQ_FILE = $(DIR_MATHQ)/files/version.mathq
FEATURE_VERSION_MATHQ = `. $(FEATURE_VERSION_MATHQ_FILE) && echo "$${FEATURE_VERSION_MATHQ}"`
TAG_FILE_MATHQ = $(DIR_MATHQ)/files/tag.mathq
TAG_MATHQ = `cat $(TAG_FILE_MATHQ)`
VERSION_HEADER_FILE_MATHQ = $(DIR_MATHQ)/include/version_mathq.h

LIB_LAPACK = -llapack -lg2c


info_mathq:
	@echo
	@$(call hr)
	@$(call title,"mathq")
	@$(call echovar,DIR_MATHQ)
	@$(call echovar,INCDIR_MATHQ)
	@$(call echovar,LIBDIR_MATHQ)
	@$(call echovar,LIB_MATHQ)
	@$(call echovar,LIB_LAPACK)
	@$(call echovar,FEATURE_VERSION_MATHQ_FILE)
	@$(call echovar,FEATURE_VERSION_MATHQ)
	@$(call echovar,TAG_MATHQ)
	@$(call hr)
	@echo




