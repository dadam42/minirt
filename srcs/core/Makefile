#-- TARGET definition :
TARGET_TYPE=#one of : exe, lib, default to exe
TARGET=minirt
#-- libs definition :
LIBS=libft libutils_3d libbmpfile#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=libm#list of list which must be include to compile
#-- definitions for each libfoo from $(LIBS):
ft_DIR=../ft#mandatory, directory containing both library and its Makefile.
utils_3d_DIR=../utils_3d
bmpfile_DIR=../bmpfile
#-- srcs definition :
SRCS=minirt.c pixel_collection.c save_bmpfile.c 
SRCS_DIRS=.
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

