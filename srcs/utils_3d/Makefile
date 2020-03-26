#-- TARGET definition :
TARGET_TYPE=lib#one of : exe, lib, default to exe
TARGET=libutils_3d.a
#-- libs definition :
LIBS=libft#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=#list of list which must be include to compile
#-- definitions for each libfoo from $(LIBS):
ft_DIR=../ft#mandatory, directory containing both library and its Makefile.
ft_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=mat3_operators_2.c mat3_operators_3.c mat3_operators.c t_vec3_inits.c vec3_applys.c vec3_operators_2.c vec3_operators.c 
SRCS_DIRS=srcs
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

