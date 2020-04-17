#include "minirt.h"
#include <stdlib.h>

void		t_cylinder_init(t_cylinder *cylinder)
{
	cylinder->object.get_first_intersection = cylinder_get_first_intersection;
	cylinder->object.get_coord = cylinder_get_coord;
	cylinder->object.get_normal = cylinder_get_normal;
	cylinder->object.get_albedo = object_dummy_get_albedo;
}

t_object	*minirt_add_rtcylinder(t_minirt *minirt
									, t_filert_parsed_obj *parsed)
{
	t_cylinder	*cylinder;
	t_direction	normal;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (0);
	vec3_from_filert(cylinder->object.origin
					, ((t_filert_cylinder*)parsed)->insertion);
	direction_from_filert(minirt, normal
						, ((t_filert_cylinder*)parsed)->direction);
	object_base_init(&cylinder->object, normal, *minirt->canonical);
	color_from_filert(cylinder->object.albedo
					, ((t_filert_cylinder*)parsed)->color);
	cylinder->radius = ((t_filert_cylinder*)parsed)->diameter / 2;
	cylinder->height = ((t_filert_cylinder*)parsed)->height;
	t_cylinder_init(cylinder);
	if (cylinder->radius < PREC || cylinder->height < PREC)
	{
		minirt_write_warning(minirt, size_is_nul);
		cylinder->object.get_first_intersection = 
									object_noop_get_first_intersection;
	}
	return ((t_object*)cylinder);
}
