#############################################################
# VARIABLES
#############################################################

MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include ../make-lib/dirmathq.config.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))


NONEXEC = libmathq.a
EXEC = 
ALL = $(LIBFILE_MATHQ)

# overide the default compiler options
OPTIMIZE = -O3 -finline-limit=750


#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------


include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk


libmathq.a: display.o debug.o slices.o 
	@echo "generating libmathq.a `cat $(TAG_FILE_MATHQ)`"
	@\ar rUuv libmathq.a $?

$(LIBFILE_MATHQ): libmathq.a 
	@\mkdir -p $(DIR_MATHQ)/lib
	@\cp libmathq.a $(DIR_MATHQ)/lib/

lib: $(LIBFILE_MATHQ)

clean::
	@\rm -f $(DIR_MATHQ)/lib/libmathq.a

	