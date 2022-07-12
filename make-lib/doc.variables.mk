#############################################################
# VARIABLES
#############################################################

# use this so that we can use $$==% as prerequisites of README targets
.SECONDEXPANSION: 


MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))

# Scripts
CREATE_DOC_BRANCH := $(DIR_MATHQ)/scripts/doc_create_subnodes.py
CREATE_DOC_LEAF := $(DIR_MATHQ)/scripts/doc_create_leaf.py

# CHAPTERS must be defined in the "incuder" file
CHAPExpressionR_NODE_FILES = $(addsuffix /node.json,$(CHAPTERS))
CHAPExpressionR_BRANCHES = $(subst /,,$(MAKE_SUBDIRS))
CHAPExpressionR_LEAVES = $(filter-out $(CHAPExpressionR_BRANCHES),$(CHAPTERS))

LEAF_READMES = $(addsuffix /README.md,$(CHAPExpressionR_LEAVES))


