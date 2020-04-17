#include "minirt.h"

t_minirt_com	minirt_check_object_integrity(t_minirt *minirt
											, t_object *object)
{
	(void)minirt;
	while (1)
	{
		if (object->get_albedo == 0)
			return (minirt_error);
		if (object->get_coord == 0)
			return (minirt_error);
		if (object->get_first_intersection == 0)
			return (minirt_error);
		break ;
	}
	return (minirt_ok);
}
