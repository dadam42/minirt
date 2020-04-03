#-- TARGET definition :
TARGET_TYPE=exe#one of : exe, lib, default to exe
TARGET=minirt
#-- libs definition :
LIBS=libft libbmpfile libutils_3d#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=libm#list of libs which must be include to compile
#-- definitions for each libfoo from $(LIBS):
ft_DIR=../ft#mandatory, directory containing both library and its Makefile.
bmpfile_DIR=../bmpfile
utils_3d_DIR=../utils_3d
ft_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=minirt.c minirt_save_bmp.c t_minirt_boxed_pixel_collection.c t_minirt_boxed_pixel_collection_get_film.c t_minirt_camera_get_image.c t_minirt_camera_get_screen.c t_minirt_ray_get_color.c t_minirt_ray_init.c t_minirt_scene_iterators.c t_minirt_screen_get_boxed_pixel_collection.c t_minirt_screen_get_image.c t_minirt_object_get_color.c 
SRCS_DIRS=
SRCS_INCS=.#
#
#---- dont change anything after this
#--------------------------------------------------------------------------------------

GEN_MAKEFILE_PATH=/home/david/42Projects/minirt/project/.d42Makefile
include $(GEN_MAKEFILE_PATH)/genMakefile

.PHONY: view
view: display.bmp
	gwenview display.bmp &
display.bmp: minirt
	./minirt
