#ifndef MINIRT_H
# define MINIRT_H
# include "utils_3d.h"

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

typedef struct	s_minirt_sphere
{
	t_minirt_position	center;
	t_minirt_size		radius;
}				t_minirt_sphere;

typedef struct	s_minirt_light
{
	t_minirt_position	position;
	t_minirt_pcolor		pcolor;
}				t_minirt_light;

#endif
