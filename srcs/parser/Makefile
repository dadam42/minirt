#-- TARGET definition :
TARGET_TYPE=lib#one of : exe, lib, default to exe
TARGET=librtparser.a
#-- libs definition :
LIBS=#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=#list of list which must be include to compile
#-- definitions for each libfoo from $(LIBS):
foo_DIR=..#mandatory, directory containing both library and its Makefile.
foo_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=filert_parse_ambiant_light.c filert_parse.c filert_parse_camera.c filert_parse_color.c filert_parse_cylinder.c filert_parse_direction.c filert_parse_float.c filert_parse_int.c filert_parse_light.c filert_parse_pcolor.c filert_parse_plane.c filert_parse_position.c filert_parse_resolution.c filert_parser_ignore.c filert_parse_sphere.c filert_parse_square.c filert_parse_str.c filert_parse_triangle.c 
SRCS_DIRS=
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/project/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

