#include "minirt.h"

void	object_preset_intersection(t_object *object, t_intersection *inter)
{
	object->set_intersection(object, inter->ray, inter);
}
