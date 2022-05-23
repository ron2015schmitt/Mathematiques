###########################################################
#      Common help commands
###########################################################


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


export OPTSHELP
help-g++:
	@echo "$${OPTSHELP}"




