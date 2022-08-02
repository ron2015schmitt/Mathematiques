#############################################################
# VARIABLES
#############################################################

MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include ../make-lib/dirmathq.config.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))


NONEXEC = 
EXEC += dimensions expressions dotproducts type-traits math_real math_imag multiarrays-conversion parmpacktwo \
        parmpack pointersandrefs testing2 tfoverloading indexing imaginary enableexperiment selfmethod typeinfo \
				classes testrelops multiarraydata printing recurseadd testing depth test4deep insideout \
				## need to fix:      containerdata testunary testunary2 testunary3 testbinary  testternary testjoin  specialmats
ALL += run gitignore

# overide the default compiler options so that build happens faster
OPTIMIZE = -O1

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------

include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk


clean::

