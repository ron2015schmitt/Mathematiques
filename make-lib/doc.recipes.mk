#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------

include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk



# add subdir nodefiles as target
README.md: $(CREATE_DOC_BRANCH) $(TAG_FILE_MATHQ) body.temp.md title.src.md
	python3 $(CREATE_DOC_BRANCH) $(TAG_FILE_MATHQ)  --chapters $(CHAPTERS)  --branches $(CHAPTER_BRANCHES)


# MAKE all subdir README files (used for dsubdirs that do NOT have a Makefile)
# this requires .SECONDEXPANSION to be defined in avriables
%/README.md: $(CREATE_DOC_LEAF) $$*/title.src.md $$*/body.temp.md $$*/node.json
	python3 $(CREATE_DOC_LEAF) $*

# 	@chmod a-w $*/README.md

# --- 3 ways to create the body.temp.md file:

# create from c++ executable
%.temp.md: %
	./$* > $@

# create from .src.md file
%.temp.md: %.src.md
	cp $*.src.md $@

# create from bash script
%.temp.md: %.bash
	./$*.bash > $@

clean:: 
	\rm -f README.md $(LEAF_READMES) $(CHAPTER_NODE_FILES) 

info::
	@echo
	@$(call hr)
	@$(call title,"doc related")
	@$(call echovar,MAKEFILE)
	@$(call echovar,MAKEFILE_REL)
	@$(call echovar,CREATE_DOC_BRANCH)
	@$(call echovar,CREATE_DOC_LEAF)
	@$(call echovar,CHAPTER_NODE_FILES)
	@$(call echovar,CHAPTER_BRANCHES)
	@$(call echovar,CHAPTER_LEAVES)
	@$(call echovar,LEAF_READMES)

