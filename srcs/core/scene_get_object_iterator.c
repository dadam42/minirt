#include "minirt.h"

t_object	*scene_object_iterator_deref(t_scene_object_iterator *iterator)
{
	return ((t_object*)
			((t_array_collection_iterator*)iterator)
			->deref((t_array_collection_iterator*)iterator));
}

bool		scene_object_iterator_next(t_scene_object_iterator *iterator)
{
	return (((t_array_collection_iterator*)iterator)
			->next((t_array_collection_iterator*)iterator));
}	

void	scene_get_object_iterator(t_scene *scene
					, t_scene_object_iterator* iterator)
{
	t_array_collection_init_fwiterator(&scene->object_collection
							, (t_array_collection_iterator*)iterator);
	iterator->next = scene_object_iterator_next;
	iterator->deref = scene_object_iterator_deref;
}

