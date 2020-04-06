#-- TARGET definition :
TARGET_TYPE=lib#one of : exe, lib, default to exe
TARGET=libgnl.a
#-- libs definition :
LIBS=libft#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=#list of list which must be include to compile
#-- definitions for each libfoo from $(LIBS):
ft_DIR=../ft#mandatory, directory containing both library and its Makefile.
foo_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=get_next_line.c get_next_line_utils.c 
SRCS_DIRS=
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/project/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

