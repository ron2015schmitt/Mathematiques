#############################################################
# VARIABLES
#############################################################

CHAPTERS_AND_HEADINGS = notation numbers multiarrays operators functions linear-algebra indexing-sorting ranges-grids calculus vector-calculus tensor-calculus display file-io debug

include ../../make-lib/dirmathq.config.mk
include $(DIR_MATHQ)/make-lib/doc.variables.mk

NONEXEC = README.md $(LEAF_READMES)
EXEC += ./notation/body ./functions/body ./vector-calculus/body
ALL += 

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------
include $(DIR_MATHQ)/make-lib/doc.recipes.mk

