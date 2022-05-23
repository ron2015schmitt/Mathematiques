

EXEC = vdeclaration  vassignment range linspace velmath vapply vcomplex vprint vscalarout vrelational vsubsets vconcatrep vslices vsort taylor fourier calculus vfile 

DOC = $(addsuffix .md,$(EXEC))

%.md: % 
	./$* > $@

%.link_md: %.md
	@echo

include ../Makefile

define placeversion
TAG=`cat $(TAG_FILE_MATHQ)` && echo -e " "$(BLUE)"FEATURE_VERSION_MATHQ"$(DEFCLR)"="$${TAG} && sed -i "s/__VERSION_MATHQ__/$${TAG}/g"  README.md
endef

doc:  $(DOC)


toc:  $(addsuffix .link_md, $(basename $(DOC)))
	@cat README.template.mk > README.md
	@echo >> README.md
	@cat $^ >> README.md
	@$(call placeversion)
	@cat README.coda.mk >> README.md
	@cat README.md


cleandocs:
	@./clean $(EXEC)

restore: 
	@git checkout -- $(addsuffix .md,$(EXEC)) README.md


# usage:
