#include "minirt.h"

void	t_minirt_camera_get_boxed_image(t_minirt_camera *camera,
										t_minirt_scene *scene,
										t_minirt_image *image,
										t_minirt_screen_box	*box)
{
	t_minirt_screen					screen;
	t_minirt_boxed_pixel_collection	pixel;

	t_minirt_camera_get_screen(camera, &image->resolution, &screen);
	t_minirt_screen_get_boxed_pixel_collection(&screen, box, &pixel);
	t_minirt_boxed_pixel_collection_get_film(&pixel, scene
												, &camera->position
												, &image->film);
}

void	t_minirt_camera_get_image(t_minirt_camera *camera,
									t_minirt_scene *scene,
									t_minirt_image *image)
{
	t_minirt_screen_box box;

	box.ulc[width] = 0;
	box.ulc[height] = 0;
	box.brc[width] = image->resolution.width;
	box.brc[height] = image->resolution.height;
	t_minirt_camera_get_boxed_image(camera, scene, image, &box);
}