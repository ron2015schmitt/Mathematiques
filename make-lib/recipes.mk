
#---------------------------------------------------------------------
#  SPECIAL RECIPES -- THESE MUST BE FIRST
#---------------------------------------------------------------------

# force these to always run regardless if prereq's are older or newer
.PHONY: run gitignore clean cleanall cleansubs

# Each Makefile that has an include statement for this file should define a target "some" that makes all targets in that directory but not in subdirectories
default: some

#prevent any default rules from being used
.SUFFIXES:

# don't delete these files after compilation
.PRECIOUS: %.o 

FORCE: ;

# this forces all recipes to use a single shell
.ONESHELL:



#---------------------------------------------------------------------
# g++ COMPILER
#
# For full details of options and up to date list see:
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
#---------------------------------------------------------------------
%.o: %.cpp 
	@\echo -e "g++ compile command used:  $(CPPC) $(CFLAGS)" > $*.g++_copts
	$(CPPC) $(CFLAGS) -c $*.cpp -o $@


#---------------------------------------------------------------------
# gfortran COMPILER
#---------------------------------------------------------------------
%.o: %.f 
	$(FC) $(FFLAGS) -c $*.f -o $*.o


#---------------------------------------------------------------------
# g++ linker
# LOPT provided at the command line will append to options
#---------------------------------------------------------------------
%: %.o 
	$(CPPC) $(LFLAGS) $*.o -o $@ $(LIBS) 


#---------------------------------------------------------------------
# MATHQ related recipes
#---------------------------------------------------------------------


# This is used to recursively build - it calls the every subdirectory Makefile
$(MAKE_SUBDIRS): FORCE
	$(MAKE) -C $@ all

testsubs: FORCE
	@echo $(SUBS)
	@echo $(SUBMAKES)
	@echo $(MAKE_SUBDIRS)
	@echo $(MAKECLEAN_SUBDIRS)


some: $(NONEXEC) $(EXEC)

# Target "all" build everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - define a target "some" that makes all targets in that directory but not in subdirectories
all: $(NONEXEC) $(EXEC) $(ALL) $(MAKE_SUBDIRS) 


# creates a run file that executes all the $(EXEC) files
#  we can't detect changes in EXEC so force it
run: 
	@$(CREATE_RUN) $(EXEC)

# creates a .gitignore files for all the $(EXEC) files
#  we can't detect changes in EXEC so force it
gitignore: 
	@\echo -e ${BOLD}${BLUE}"Creating .gitignore file..."${DEFCLR}${NORMAL} 
	@\echo -e '# ****  This was created by the command "make gitignore".' > .gitignore
	@\echo -e '# ****  Do NOT manually edit.' >> .gitignore
	@\echo -e "/run" >> .gitignore
	@for name in $(EXEC)
	@do
	@  \printf "/$${name}\n" >> .gitignore
	@done


#---------------------------------------------------------------------
# CLEANING
#---------------------------------------------------------------------

# Each Makefile that has an include statement for this file should:
#  - define a "clean" target with "cleanstd" as a prerequisite
clean:: FORCE 
	@command rm -f *.o *.a *.s *.g++_copts core.* node.json *.temp.md
	@command rm -f $(EXEC) $(NONEXEC) 


makeclean_%: FORCE
	@$(MAKE) -C $* cleanall

nomakeclean_%: FORCE
	@echo "nomakeclean_$(*)"
# ONSHELL is on
	@cd $(*)  
	@command rm -f *.o *.a *.s *.g++_copts core.* *.temp *.tmp *~ ~* *.gz *.tar *.old node.json *.temp.md
#  DONT NEED ANYMORE: if body.cpp exists then body.md is an output file not a source
#	@if [[ -f body.cpp ]] ; then command rm -f body.md; fi

cleansubs:: $(MAKECLEAN_SUBDIRS) $(NOMAKECLEAN_SUBDIRS)


# Target "cleansall" cleans everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - can (but not necessary) define a "cleanall" target
cleanall:: FORCE clean cleansubs
	@\rm -f run *.temp *.tmp *~ ~* *.gz *.tar *.old 
	@\rm -f $(ALL)

