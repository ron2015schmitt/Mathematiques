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
CHAPExpr_R_NODE_FILES = $(addsuffix /node.json,$(CHAPTERS))
CHAPExpr_R_BRANCHES = $(subst /,,$(MAKE_SUBDIRS))
CHAPExpr_R_LEAVES = $(filter-out $(CHAPExpr_R_BRANCHES),$(CHAPTERS))

LEAF_READMES = $(addsuffix /README.md,$(CHAPExpr_R_LEAVES))


