#include "minirt.h"

t_light	*t_scene_light_iterator_deref(t_scene_light_iterator *iterator)
{
	return ((t_light*)
			((t_array_collection_iterator*)iterator)
			->deref((t_array_collection_iterator*)iterator));
}

bool	t_scene_light_iterator_next(t_scene_light_iterator *iterator)
{
	return (((t_array_collection_iterator*)iterator)
			->next((t_array_collection_iterator*)iterator));
}	

void	t_scene_get_light_iterator(t_scene *scene
					, t_scene_light_iterator* iterator)
{
	t_array_collection_init_fwiterator(&scene->light_collection
							, (t_array_collection_iterator*)iterator);
	iterator->next = t_scene_light_iterator_next;
	iterator->deref = t_scene_light_iterator_deref;
}
