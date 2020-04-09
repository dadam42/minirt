#include "minirt.h"

t_minirt_com	t_scene_add_object(t_scene *scene, t_object *object)
{
	return (t_array_collection_add(&scene->object_collection, object));
}

t_minirt_com	t_scene_add_light(t_scene *scene, t_light *light)
{
	return (t_array_collection_add(&scene->light_collection, light));
}

t_minirt_com	t_scene_add_camera(t_scene *scene, t_camera *camera)
{
	return (t_array_collection_add(&scene->camera_collection, camera));
}
