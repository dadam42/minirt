#include "minirt.h"
#include <stdlib.h>

t_object	*minirt_add_rtsquare(t_minirt *minirt, t_filert_parsed_obj *parsed)
{
	t_square	*square;
	t_direction	normal;

	square = malloc(sizeof(t_square));
	if (!square)
		return (0);
	vec3_from_filert(square->object.origin, ((t_filert_square*)parsed)->center);
	direction_from_filert(minirt, normal, ((t_filert_square*)parsed)->orth);
	object_base_init((t_object*)square, normal, *minirt->canonical);
	color_from_filert(square->object.albedo, ((t_filert_square*)parsed)->color);
	square->size = ((t_filert_square*)parsed)->size / 2;
	square->object.get_first_intersection = square_get_first_intersection;
	square->object.get_coord = plane_get_coord;
	square->object.get_normal = plane_get_normal;
	square->object.get_albedo = object_dummy_get_albedo;
	return ((t_object*)square);
}
