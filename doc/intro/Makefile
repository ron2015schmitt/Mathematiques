#############################################################
# VARIABLES
#############################################################

CHAPTERS_AND_HEADINGS = basics.src.heading print-debug numbers \
multiarrays.src.heading multiarrays nested-multiarrays special-multiarrays \
math.src.heading multiarray-arithmetic arithmetic-mixed linear-algebra sort-mask-slice math-functions \
calculus.src.heading numerical-functions complex-calculus vector-calculus tensors series-transforms

include ../../make-lib/dirmathq.config.mk
include $(DIR_MATHQ)/make-lib/doc.variables.mk

NONEXEC = README.md $(LEAF_READMES)

EXEC += ./print-debug/body ./numbers/body \
./multiarrays/body ./nested-multiarrays/body ./special-multiarrays/body \
./multiarray-arithmetic/body ./arithmetic-mixed/body ./linear-algebra/body  ./sort-mask-slice/body ./math-functions/body \
./numerical-functions/body ./complex-calculus/body ./vector-calculus/body  ./tensors/body ./series-transforms/body 

ALL += 

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------
include $(DIR_MATHQ)/make-lib/doc.recipes.mk

