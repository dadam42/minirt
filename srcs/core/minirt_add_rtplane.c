#include "minirt.h"
#include <stdlib.h>

t_object	*minirt_add_rtplane(t_minirt *minirt, t_filert_parsed_obj *parsed)
{
	t_plane		*plane;
	t_direction	normal;
	bool		base_is_complete;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (0);
	vec3_from_filert(plane->origin, ((t_filert_plane*)parsed)->insertion);
	direction_from_filert(minirt, normal
						, ((t_filert_plane*)parsed)->orth);
	base_is_complete = object_base_init(plane, normal
										, *minirt->canonical);
	if (!base_is_complete)
	{
		free(plane);
		return (0);
	}
	color_from_filert(plane->albedo, ((t_filert_plane*)parsed)->color);
	plane->get_first_intersection = plane_get_first_intersection;
	plane->get_coord = plane_get_coord;
	plane->get_normal = plane_get_normal;
	plane->get_albedo = object_dummy_get_albedo;
	return (plane);
}
