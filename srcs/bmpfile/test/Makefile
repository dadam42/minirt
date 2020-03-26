#-- TARGET definition :
TARGET_TYPE=exe#one of : exe, lib, default to exe
TARGET=test_bmpfile_save
#-- libs definition :
LIBS=libbmpfile#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=libm#list of list which must be include to compile
#-- definitions for each libfoo from $(LIBS):
bmpfile_DIR=..#mandatory, directory containing both library and its Makefile.
bmpfile_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=bmpfile_save.c
SRCS_DIRS=
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

