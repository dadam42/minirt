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
SRCS=minirt.c t_object_preset_intersection.c t_intersection_init.c t_intersection_complete.c t_scene_get_light_influence.c t_scene_get_camera_iterator.c t_scene_get_light_iterator.c t_scene_get_object_iterator.c t_ray_get_color.c t_boxed_pixel_collection_get_film.c t_boxed_pixel_collection_next.c t_camera_get_images.c t_camera_get_screen.c t_minirt_add_rtambiant_light.c t_minirt_add_rtcamera.c t_minirt_add_rtlight.c t_minirt_add_rtresolution.c t_minirt_add_rtsphere.c t_minirt_color_from_filert.c t_minirt_direction_from_filert.c t_minirt_init.c t_minirt_init_object.c t_minirt_load_filert.c t_minirt_pcolor_from_filert.c t_minirt_release.c t_minirt_save_bmpfile.c t_object_dummy_get_albedo.c t_ray_init.c t_scene_adds.c t_scene_init.c t_scene_release.c t_screen_get_boxed_pixel_collection.c t_sphere_alt.c t_sphere.c unhandled_adders.c 
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
