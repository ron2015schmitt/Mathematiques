

MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include $(DIR_MATHQ)/make-lib/style.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))


####################################################################
################## PROJECT SPECIFIC VARIABLES ######################
####################################################################
EXEC += example example2 example-matrices example3
ALL += run gitignore
####################################################################

