#-- TARGET definition :
TARGET_TYPE=exe#one of : exe, lib, default to exe
TARGET=minirt
#-- libs definition :
LIBS=libft libbmpfile libutils_3d libarray_collection librtparser libgnl#list of libs (prefixed with lib : e.g libfoo) which must be recompiled by this Makefile
STDLIBS=libm#list of libs which must be include to compile
#-- definitions for each libfoo from $(LIBS):
ft_DIR=../ft#mandatory, directory containing both library and its Makefile.
gnl_DIR=../rotrojan_gnl
bmpfile_DIR=../bmpfile
utils_3d_DIR=../utils_3d
array_collection_DIR=../array_collection
rtparser_DIR=../parser
ft_INC=#optionnal, default to lib_DIR : dirname containing lib's headers files.
#-- srcs definition :
SRCS=boxed_pixel_collection_get_film.c boxed_pixel_collection_next.c camera_get_images.c camera_get_screen.c intersection_complete.c intersection_init.c minirt_add_rtambiant_light.c minirt_add_rtcamera.c minirt_add_rtlight.c minirt_add_rtresolution.c minirt_add_rtsphere.c minirt.c minirt_color_from_filert.c minirt_direction_from_filert.c minirt_errwrite.c minirt_exit.c minirt_fatal_error.c minirt_init.c minirt_init_object.c minirt_load_filert.c minirt_pcolor_from_filert.c minirt_release.c minirt_save_bmpfile.c minirt_stdwrite.c minirt_strerror.c minirt_sys_fatal_error.c minirt_write_error.c minirt_write_sys_error.c minirt_write_warning.c object_dummy_get_albedo.c object_preset_intersection.c ray_get_color.c ray_init.c scene_adds.c scene_get_camera_iterator.c scene_get_light_influence.c scene_get_light_iterator.c scene_get_object_iterator.c scene_init.c scene_release.c screen_get_boxed_pixel_collection.c sphere_alt.c sphere.c unhandled_adders.c 
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
