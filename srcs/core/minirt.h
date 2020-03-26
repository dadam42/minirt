#ifndef MINIRT_H
# define MINIRT_H
# include "utils_3d.h"
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

typedef struct	s_minirt_screen
{
	t_minirt_camera	*camera;
	int				width;
	int				height;
}				t_minirt_screen;

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

typedef struct	s_minirt_obj
{
	t_minirt_geom	geom;
}				t_minirt_obj;


#endif
