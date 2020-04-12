#include "minirt.h"

t_camera	*scene_camera_iterator_deref(t_scene_camera_iterator *iterator)
{
	return ((t_camera*)
			((t_array_collection_iterator*)iterator)
			->deref((t_array_collection_iterator*)iterator));
}

bool		scene_camera_iterator_next(t_scene_camera_iterator *iterator)
{
	return (((t_array_collection_iterator*)iterator)
			->next((t_array_collection_iterator*)iterator));
}	

void	scene_get_camera_iterator(t_scene *scene
					, t_scene_camera_iterator* iterator)
{
	t_array_collection_init_fwiterator(&scene->camera_collection
							, (t_array_collection_iterator*)iterator);
	iterator->next = scene_camera_iterator_next;
	iterator->deref = scene_camera_iterator_deref;
}

