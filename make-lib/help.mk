###########################################################
#      Common help commands
###########################################################


define GENERALOPTSHELP
#############################################################################

-x language
Specify explicitly the language for the following input files (rather than letting the compiler choose a default based on the file name suffix). This option applies to all following input files until the next -x option. Possible values for language are:

c  c-header  cpp-output
c++  c++-header  c++-cpp-output
objective-c  objective-c-header  objective-c-cpp-output
objective-c++ objective-c++-header objective-c++-cpp-output
assembler  assembler-with-cpp
ada
f77  f77-cpp-input f95  f95-cpp-input
go
brig
-x none
Turn off any specification of a language, so that subsequent files are handled according to their file name suffixes (as they are if -x has not been used at all).

If you only want some of the stages of compilation, you can use -x (or filename suffixes) to tell gcc where to start, and one of the options -c, -S, or -E to say where gcc is to stop. Note that some combinations (for example, ‘-x cpp-output -E’) instruct gcc to do nothing at all.

-c
Compile or assemble the source files, but do not link. The linking stage simply is not done. The ultimate output is in the form of an object file for each source file.

By default, the object file name for a source file is made by replacing the suffix ‘.c’, ‘.i’, ‘.s’, etc., with ‘.o’.

Unrecognized input files, not requiring compilation or assembly, are ignored.

-S
Stop after the stage of compilation proper; do not assemble. The output is in the form of an assembler code file for each non-assembler input file specified.

By default, the assembler file name for a source file is made by replacing the suffix ‘.c’, ‘.i’, etc., with ‘.s’.

Input files that don’t require compilation are ignored.

-E
Stop after the preprocessing stage; do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output.

Input files that don’t require preprocessing are ignored.

-o file
Place output in file file. This applies to whatever sort of output is being produced, whether it be an executable file, an object file, an assembler file or preprocessed C code.

If -o is not specified, the default is to put an executable file in a.out, the object file for source.suffix in source.o, its assembler file in source.s, a precompiled header file in source.suffix.gch, and all preprocessed C source on standard output.

-v
Print (on standard error output) the commands executed to run the stages of compilation. Also print the version number of the compiler driver program and of the preprocessor and the compiler proper.

-###
Like -v except the commands are not executed and arguments are quoted unless they contain only alphanumeric characters or ./-_. This is useful for shell scripts to capture the driver-generated command lines.

--help
Print (on the standard output) a description of the command-line options understood by gcc. If the -v option is also specified then --help is also passed on to the various processes invoked by gcc, so that they can display the command-line options they accept. If the -Wextra option has also been specified (prior to the --help option), then command-line options that have no documentation associated with them are also displayed.

--target-help
Print (on the standard output) a description of target-specific command-line options for each tool. For some targets extra target-specific information may also be printed.

--help={class|[^]qualifier}[,…]
Print (on the standard output) a description of the command-line options understood by the compiler that fit into all specified classes and qualifiers. These are the supported classes:

‘optimizers’
Display all of the optimization options supported by the compiler.

‘warnings’
Display all of the options controlling warning messages produced by the compiler.

‘target’
Display target-specific options. Unlike the --target-help option however, target-specific options of the linker and assembler are not displayed. This is because those tools do not currently support the extended --help= syntax.

‘params’
Display the values recognized by the --param option.

language
Display the options supported for language, where language is the name of one of the languages supported in this version of GCC.

‘common’
Display the options that are common to all languages.

These are the supported qualifiers:

‘undocumented’
Display only those options that are undocumented.

‘joined’
Display options taking an argument that appears after an equal sign in the same continuous piece of text, such as: ‘--help=target’.

‘separate’
Display options taking an argument that appears as a separate word following the original option, such as: ‘-o output-file’.
endef

# options listed below for reference

define OPTSHELP
#############################################################################
# g++ OPTIMIZATIONS (provided at compile and link time)
#
# For full details and up to date list see:
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
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
endef



export GENERALOPTSHELP
help-g++:
	@echo "$${GENERALOPTSHELP}"

export OPTSHELP
help-g++-optimize:
	@echo "$${OPTSHELP}"




