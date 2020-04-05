#-- TARGET definition :
TARGET_TYPE=lib#one of : exe, lib, default to exe
TARGET=libd42_sys.a
#-- libs definition :
LIBS=#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=#list of list which must be include to compile
#-- definitions for each libfoo from $(LIBS):
foo_DIR=..#mandatory, directory containing both library and its Makefile.
foo_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=sys_endianess.c t_sys.c 
SRCS_DIRS=srcs
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/project/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

