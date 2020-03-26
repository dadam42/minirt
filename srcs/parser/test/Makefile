#-- TARGET definition :
TARGET_TYPE=exe#one of : exe, lib, default to exe
TARGET=test
#-- libs definition :
LIBS=librtparser#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=#list of list which must be include to compile
#-- definitions for each libfoo from $(LIBS):
rtparser_DIR=..#mandatory, directory containing both library and its Makefile.
rtparser_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=filert_parse_position.c test.c
SRCS_DIRS=
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

