#ifndef MINIRT_H
# define MINIRT_H
# include "utils_3d.h"
# include <stddef.h>
# define PI 3.141592653589793
# define PREC 1e-15

typedef t_vec3	t_minirt_position;
typedef t_vec3	t_minirt_direction;
typedef t_vec3	t_minirt_color;
typedef double	t_minirt_intensity;
typedef double	t_minirt_size;
typedef struct	s_minirt_pcolor
{
	t_minirt_color		color;
	t_minirt_intensity	intensity;
}				t_minirt_pcolor;

typedef struct	s_minirt_camera
{
	t_minirt_position	position;
	t_minirt_direction	view;
	t_minirt_direction	up;
	double				fov;
}				t_minirt_camera;

typedef struct	s_minirt_resolution
{
	int	width;
	int	height;
}				s_minirt_resolution;

typedef unsigned char	t_minirt_pixel[3];
typedef struct	s_minirt_image
{
	t_minirt_pixel	*content;
	int				width;
	int				height;
}				t_minirt_image;

typedef struct	s_minirt_ray
{
	t_minirt_position	start;
	t_minirt_direction	direction;
}				t_minirt_ray;

typedef struct	s_minirt_light
{
	t_minirt_position	position;
	t_minirt_pcolor		pcolor;
}				t_minirt_light;

typedef struct	s_minirt_sphere
{
	t_minirt_position	center;
	t_minirt_size		radius;
}				t_minirt_sphere;

typedef struct	s_minirt_cylinder
{
	t_minirt_position	base;
	t_minirt_direction	axe_dir;
	t_minirt_size		height;
	t_minirt_size		radius;
}				t_minirt_cylinder;

typedef struct	s_minirt_plane
{
	t_minirt_position	position;
	t_minirt_direction	axe_normal;
}				t_minirt_plane;

typedef struct	s_minirt_triangle
{
	t_minirt_position	vertex[3];
}				t_minirt_triangle;

typedef	struct	s_minirt_square
{
	t_minirt_position	bl_vertex;
	t_minirt_direction	norm;
}				t_minirt_square;

typedef union	u_minirt_geom
{
	t_minirt_sphere		sphere;
	t_minirt_cylinder	cylinder;
	t_minirt_plane		plane;
	t_minirt_triangle	triangle;
	t_minirt_square		square;
}				t_minirt_geom;

typedef enum	e_minirt_inter_info 
{minirt_inter_no = 0, minirt_inter_trans = 1, minirt_inter_tang = 2}
				t_minirt_inter_info; 

typedef struct s_minirt_obj
				t_minirt_obj;
typedef	e_minirt_inter_info	(*t_minirt_get_inter)(t_minirt_obj* 
												, t_minirt_ray *ray
												, double *t);
struct	s_minirt_obj
{
	t_minirt_geom		geom;
	t_minirt_get_inter	get_inter;
}				t_minirt_obj;

typedef t_list	*t_minirt_obj_collection;
typedef t_list	*t_minirt_light_collection;
typedef	t_list	*t_minirt_camera_collection;
typedef struct	s_minirt_scene
{
	t_minirt_obj_collection		obj;
	size_t						nobj;
	t_minirt_light_collection	light;
	size_t						nlight;
	t_minirt_camera_collection	camera;
	size_t						ncamera;
	t_minirt_ambiant_light		ambiant_light;
}				t_minirt_scene;

typedef	struct	s_minirt
{
	t_minirt_scene	scene;
	int				width;
	int				height;
}				t_minirt;

#endif
