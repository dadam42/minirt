#include "minirt.h"

void	t_scene_init(t_scene *scene)
{
	static t_color		background_color = {0, 0, 0};
	static t_color		black = {0, 0, 0};

	t_array_collection_init(&scene->object_collection);
	t_array_collection_init(&scene->light_collection);
	t_array_collection_init(&scene->camera_collection);
	scene->background_color = &background_color;
	scene->black = &black;
}
