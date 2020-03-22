#include "test.h"
#include <stdio.h>
#define TPREC 1e-6

static int t_filert_float_equal(float *l, float *r)
{
	if (*r >= *l && *r - *l <= TPREC)
		return (1);
	if (*l > *r && *l - *r <= TPREC)
		return (1);
	return (0);
}

void t_filert_color_printf(t_filert_color *color)
{
	printf("%u, %u, %u", (unsigned int)(*color)[0], (unsigned int)(*color)[1], (unsigned int)(*color)[2]);
}

int	t_filert_color_equal(t_filert_color *l, t_filert_color *r)
{
	if ((*l)[0] == (*r)[0] && (*l)[1] == (*r)[1] && (*l)[2] == (*r)[2])
		return (1);
	return (0);
}

void	t_filert_pcolor_printf(t_filert_pcolor *pcolor)
{
	printf("%f ", pcolor->intensity);
	t_filert_color_printf(&pcolor->color);
}

int		t_filert_pcolor_equal(t_filert_pcolor* l , t_filert_pcolor* r)
{
	if (t_filert_color_equal(&l->color, &r->color) && t_filert_float_equal(&l->intensity, &r->intensity))
		return (1);
	return (0);
}

void	t_filert_position_printf(t_filert_position *position)
{
	printf("%f, %f, %f ", (*position)[0],(*position)[1],(*position)[2]);
}

int		t_filert_position_equal(t_filert_position* l , t_filert_position* r)
{
	if (t_filert_float_equal(&(*l)[0], &(*r)[0]) && t_filert_float_equal(&(*l)[1], &(*r)[1]) && t_filert_float_equal(&(*l)[2], &(*r)[2])) 
		return (1);
	return (0);
}

void	t_filert_direction_printf(t_filert_direction *direction)
{
	t_filert_position_printf(direction);
}

int		t_filert_direction_equal(t_filert_direction *l , t_filert_direction *r)
{
	return (t_filert_position_equal(l, r));
}

void t_filert_com_printf(t_filert_parser_com com)
{
	static char *filert_com_str_suffix[]=FILERT_COM_STR_SUFFIX;

	printf("%s", filert_com_str_suffix[com]);
}

void	t_filert_resolution_printf(t_filert_parsed_obj* obj)
{
	printf("R %d %d\n", obj->resolution.x, obj->resolution.y);
}

int		t_filert_resolution_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (l->resolution.x == r->resolution.x && l->resolution.y == r->resolution.y)
		return (1);
	return (0);
}

void	t_filert_ambiant_light_printf(t_filert_parsed_obj* obj)
{
	printf("A ");
	t_filert_pcolor_printf(&obj->ambiant_light);
	printf("\n");
}

int		t_filert_ambiant_light_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	return (t_filert_pcolor_equal(&l->ambiant_light, &r->ambiant_light));
}

void	t_filert_cylinder_printf(t_filert_parsed_obj* obj)
{
	printf("cy ");
	t_filert_position_printf(&obj->cylinder.insertion);
	printf(" ");
	t_filert_direction_printf(&obj->cylinder.direction);
	printf(" %f %f ", obj->cylinder.diameter, obj->cylinder.height);
	t_filert_color_printf(&obj->cylinder.color);
	printf("\n");
}

int		t_filert_cylinder_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (t_filert_position_equal(&l->cylinder.insertion, &r->cylinder.insertion) &&
		t_filert_direction_equal(&l->cylinder.direction, &r->cylinder.direction) &&
		t_filert_float_equal(&l->cylinder.diameter, &r->cylinder.diameter) && 
		t_filert_float_equal(&l->cylinder.height, &r->cylinder.height) &&
		t_filert_color_equal(&l->cylinder.color, &r->cylinder.color))
		return (1);
	return (0);
}

void	t_filert_triangle_printf(t_filert_parsed_obj* obj)
{
	printf("tr ");
	t_filert_position_printf(&obj->triangle.vertex[0]);
	printf(" ");
	t_filert_position_printf(&obj->triangle.vertex[1]);
	printf(" ");
	t_filert_position_printf(&obj->triangle.vertex[2]);
	printf(" ");
	t_filert_color_printf(&obj->triangle.color);
	printf("\n");
}

int		t_filert_triangle_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (t_filert_position_equal(&l->triangle.vertex[0], &r->triangle.vertex[0]) &&
		t_filert_position_equal(&l->triangle.vertex[1], &r->triangle.vertex[1]) &&
		t_filert_position_equal(&l->triangle.vertex[2], &r->triangle.vertex[2]) &&
		t_filert_color_equal(&l->triangle.color, &r->triangle.color))
		return (1);
	return (0);
}

void	t_filert_plane_printf(t_filert_parsed_obj* obj)
{
	printf("pl ");
	t_filert_position_printf(&obj->plane.insertion);
	printf(" ");
	t_filert_direction_printf(&obj->plane.orth);
	printf(" ");
	t_filert_color_printf(&obj->plane.color);
	printf("\n");
}

int		t_filert_plane_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (t_filert_position_equal(&l->plane.insertion, &r->plane.insertion) &&
		t_filert_direction_equal(&l->plane.orth, &r->plane.orth) &&
		t_filert_color_equal(&l->plane.color, &r->plane.color))
		return (1);
	return (0);
}

void	t_filert_sphere_printf(t_filert_parsed_obj* obj)
{
	printf("sp ");
	t_filert_position_printf(&obj->sphere.center);
	printf(" %f ", obj->sphere.diameter);
	t_filert_color_printf(&obj->sphere.color);
	printf("\n");
}

int		t_filert_sphere_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (t_filert_position_equal(&l->sphere.center, &r->sphere.center) &&
		t_filert_float_equal(&l->sphere.diameter, &r->sphere.diameter) &&
		t_filert_color_equal(&l->sphere.color, &r->sphere.color))
		return (1);
	return (0);
}

void	t_filert_square_printf(t_filert_parsed_obj* obj)
{
	printf("sq ");
	t_filert_position_printf(&obj->square.center);
	printf(" ");
	t_filert_direction_printf(&obj->square.orth);
	printf(" %f ", obj->square.size);
	t_filert_color_printf(&obj->square.color);
	printf("\n");
}

int		t_filert_square_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (t_filert_position_equal(&l->square.center, &r->square.center) &&
		t_filert_direction_equal(&l->square.orth, &r->square.orth) &&
		t_filert_float_equal(&l->square.size, &r->square.size) && 
		t_filert_color_equal(&l->square.color, &r->square.color))
		return (1);
	return (0);
}

void	t_filert_camera_printf(t_filert_parsed_obj* obj)
{
	printf("c ");
	t_filert_position_printf(&obj->camera.position);
	printf(" ");
	t_filert_direction_printf(&obj->camera.direction);
	printf(" %f\n", obj->camera.fov);
	printf("\n");
}

int		t_filert_camera_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (t_filert_position_equal(&l->camera.position, &r->camera.position) &&
		t_filert_direction_equal(&l->camera.direction, &r->camera.direction) && 
		t_filert_float_equal(&l->camera.fov, &r->camera.fov))
		return (1);
	return (0);
}

void	t_filert_light_printf(t_filert_parsed_obj* obj)
{
	printf("l ");
	t_filert_position_printf(&obj->light.position);
	printf(" ");
	t_filert_pcolor_printf(&obj->light.pcolor);
	printf("\n");
}

int		t_filert_light_equal(t_filert_parsed_obj* l, t_filert_parsed_obj* r)
{
	if (t_filert_position_equal(&l->light.position, &r->light.position) &&
		t_filert_pcolor_equal(&l->light.pcolor, &r->light.pcolor))
		return (1);
	return (0);
}

void	t_filert_parse_printf(t_filert_parser_com com, t_filert_parsed_obj *obj)
{
	static t_filert_parsed_obj_printf obj_printf[] = {t_filert_resolution_printf, t_filert_ambiant_light_printf, 
		t_filert_camera_printf, t_filert_light_printf, t_filert_sphere_printf, t_filert_cylinder_printf,
		t_filert_square_printf, t_filert_triangle_printf, t_filert_plane_printf};
	
	obj_printf[com](obj); 
}

int		t_filert_parse_equal(t_filert_parser_com com, t_filert_parsed_obj *l, t_filert_parsed_obj *r)
{
	static t_filert_parsed_obj_equal obj_equal[] = {t_filert_resolution_equal, t_filert_ambiant_light_equal,
		t_filert_camera_equal, t_filert_light_equal, t_filert_sphere_equal, t_filert_cylinder_equal,
		t_filert_square_equal, t_filert_triangle_equal, t_filert_plane_equal};

	return (obj_equal[com](l, r));
}
