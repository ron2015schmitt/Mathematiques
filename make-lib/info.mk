###########################################################
#      Full Informative Dump 
###########################################################


info::
	@echo
	@$(call hr)
	@$(call title,"Variables")
	@$(call echovar,SHELL)
	@$(call echovar,CURDIR)
	@$(call echovar,PWD)
	@$(call echovar,VPATH)
	@$(call echovar,MAKE)
	@$(call echovar,FIRST_MAKEFILE)
	@$(call echovar,_)
	@$(call echovar,MAKECMDGOALS)
	@$(call echovar,MAKE_VERSION)
	@$(call echovar,MAKEFLAGS)
	@$(call echovar,GNUMAKEFLAGS)
	@$(call echovar,MAKEFILES)
	@$(call echovar,MAKEFILE_LIST)
	@$(call echovar,MAKE_HOST)
	@$(call echovar,MAKELEVEL)
	@$(call echovar,NONEXEC)
	@$(call echovar,EXEC)
	@$(call echovar,ALL)
	@$(call echovar,SUBDIRS)
	@$(call echovar,WHOAMI)
	@$(call echovar,WHEREAMI)
	@$(call echovar,MAKEFILE)
	@$(call echovar,MAKEFILE_REL)
	@echo
	@$(call title,"mathq")
	@$(call echovar,DIR_MATHQ)
	@$(call echovar,MAKEDIR_MATHQ)
	@$(call echovar,INCDIR_MATHQ)
	@$(call echovar,LIBDIR_MATHQ)
	@$(call echovar,LIB_MATHQ)
	@$(call echovar,LIB_LAPACK)

	@$(call echovar,SUBS)
	@$(call echovar,SUBMAKES)
	@$(call echovar,MAKE_SUBDIRS)
	@$(call echovar,MAKECLEAN_SUBDIRS)
	@$(call echovar,NOMAKE_SUBDIRS)
	@$(call echovar,NOMAKECLEAN_SUBDIRS)
ifdef FEATURE_VERSION_MATHQ_FILE
	@$(call echovar,FEATURE_VERSION_MATHQ_FILE)
	@$(call echovar,FEATURE_VERSION_MATHQ)
endif
	@$(call echovar,CPP_VERSION_FILE)
	@$(call echovar,TAG_MATHQ)
	@$(call hr)
	@echo
	@$(call title,"Includes")
	@$(call echovar,INCLUDES)
	@echo
	@$(call title,"Libraries")
	@$(call echovar,LIBS)
	@echo
	@$(call title,"Optimizations")
	@$(call echovar,OPTIMIZE)
	@echo
	@$(call title,"C++ Compiler")
	@$(call echovar,CPPC)
	@$(call echovar,COPT)
	@$(call echovar,CFLAGS)
	@echo
	@$(call title,"Fortran")
	@$(call echovar,FC)
	@$(call echovar,FOPT)
	@$(call echovar,LNK_FFLAGS)
	@echo
	@$(call title,"Linker")
	@$(call echovar,LNK)
	@$(call echovar,LOPT)
	@$(call echovar,LFLAGS)
	@$(call hr)
	@echo


