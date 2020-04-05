#ifndef MINIRT_H
# define MINIRT_H
# include "utils_3d.h"
# include "filert_parser.h"
# include "array_collection.h"
# include <stddef.h>
# include <stdbool.h>
# define PI 3.141592653589793
# define PREC 1e-15
# define SQPREC 1e-6
# define FOREVER	1e15

/*
** Basic typedefs for further structures.
*/
typedef enum			e_minirt_com
{
	minirt_ok, minirt_error, minirt_mem_error, minirt_parse_error
}						t_com;

typedef t_vec3			t_position;
typedef t_vec3			t_direction;
typedef	t_vec3			t_translation;
typedef	t_mat3			t_base;
typedef double			t_float;
typedef unsigned char	t_rgb_comp;
typedef t_float			t_size;
typedef t_float			t_intensity;
typedef t_float			t_time;
typedef t_rgb_comp		t_pixel_color[3];
typedef t_size			t_local_coord[2];
typedef enum			e_comp
{
	red, green, blue
}						t_comp;
typedef t_vec3			t_color;
typedef	t_color			t_albedo;

typedef struct			s_resolution
{
	int	width;
	int	height;
}						t_resolution;

typedef	struct			s_observer
{
	t_position		position;
	t_resolution	resolution;
}						t_observer;

typedef struct			s_pcolor
{
	t_color		color;
	t_intensity	intensity;
}						t_pcolor;

/*
**	t_film can be
**		- 'legacy' (t_color array) 
**		- 'rgb'		(t_rgp_comp array)			
*/

typedef union			u_film
{
	t_color	*legacy;
	t_rgb_comp	*rgb;
}						t_film;

typedef struct			s_image
{
	t_film		film;
	t_resolution	resolution;
}						t_image;

/*
**	t_camera, t_screen, t_boxed_pixel_collection
*/
typedef int				t_screen_coord[2];
typedef enum			e_pixel_coord
{
	height, width
}						t_pixel_coord;

typedef struct			s_boxed_pixel_collection
{
	t_screen_coord	min;
	t_screen_coord	cur;
	t_screen_coord	max;
	t_position		position;
	t_translation	dh;
	t_translation	dw;
}						t_boxed_pixel_collection;

typedef	struct			s_screen
{
	t_resolution	resolution;
	t_size			pixel_size;
	t_position		ulc_position;
	t_translation	dh;
	t_translation	dw;
}						t_screen;

typedef struct			s_screen_box
{
	t_screen_coord	ulc;
	t_screen_coord	brc;
}						t_screen_box;

typedef	enum	
{
	right, view, up
}						t_camera_base;

typedef struct			s_camera
{
	t_mat3		base;
	t_position	position;
	double		fov;
}						t_camera;
/* -- t_camera */

typedef struct			s_ray
{
	t_position	start;
	t_direction	direction;
}						t_ray;

typedef struct			s_color_ray
{
	t_ray	ray;
	t_color	color;
}						t_color_ray;

typedef struct			s_light
{
	t_position	position;
	t_pcolor	pcolor;
}						t_light;

typedef	t_pcolor 		t_ambiant_light;

typedef struct s_intersection_info
						t_intersection_info;

t_base canonical = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};//to remove.

/*
**	t_object : structural specification of all visible objects.
**				mostly pointers on functions.
*/

typedef struct s_object
						t_object;

/*		Catalog of pointers, 
**		_each_ one of these must be defined by 
**		any new object realisation
*/

typedef void			(*t_object_get_intersection_time)
							(t_object*, t_ray*, t_time*);
typedef void			(*t_object_get_albedo)
							(t_object*, t_object_coord, t_albedo);
typedef void			(*t_object_get_local_coord)
							(t_object*, t_position, t_local_coord);
typedef void			(*t_object_get_normal)
							(t_object*, t_object_coord, t_direction);
struct					s_object
{
	t_base							base;
	t_color							albedo;
	t_object_get_intersection_time	get_intersection_time;
	t_object_get_local_coord		get_local_coord;
	t_object_get_normal				get_normal;
	t_object_get_albedo				get_albedo;
};

/*
**	Fall over get_albedo
*/

void					t_object_dummy_get_albedo
							(t_object *obj
							, t_object_coord *coord, t_albedo albedo);

/*
**	The following realisations of the above t_object type can use a couple of
**	coordonates system to localize a point on its surface : 
**		cartesian 	: 	a t_vec3 aka t_position in the global coordonates 
**						system which will be provided by the t_minirt struct 
**						(see canonical member)
**		local		:	a t_float[2] aka t_local_coord awhich will be computed,
**						if needed it can be of various coordonates system,
**						typically spherical for a sphere,
**						barycentric for a triangle,
**						cylindrical for cylinders...
*/

typedef struct			s_object_coord
{
	t_position		cartesian;
	t_local_coord	local;
}						t_object_coord;

/*
** t_sphere :  a realisation of t_object defined above.
*/

typedef struct			s_sphere
{
	t_object	object;
	t_position	center;
	t_size		radius;
}						t_sphere;

void 					t_sphere_init(t_sphere *
							, t_position center, t_size radius);
void 					t_sphere_get_intersection_time(t_object *obj
							, t_ray *ray, t_time *time);
void					*t_sphere_get_albedo(t_object*
							, t_object_coord *coord, t_albedo);

/*
**	t_intersection_info : 	heart of ray tracing algorithm.
**							it gather and cache any data required for
**							the ray tracing algorithm.
**							when used, its datas must be accessed through
**							getters unless you know what you do _really_ well.
*/

typedef void			(*t_intersection_info_get_position)
							(t_intersection_info *, t_position *position);
typedef void			(*t_intersection_info_get_local_coord)
							(t_intersection_info *, t_local_coord *local);
typedef void			(*t_intersection_info_get_normal)
							(*t_intersection_info *, t_direction *normal);
struct					s_intersection_info
{
	t_object							*object;
	t_ray								*ray;
	t_direction							normal;
	t_object_coord						object_coord;
	t_time								time;
	t_intersection_info_get_position	get_position;
	t_intersection_info_get_local_coord	get_local_coord;
	t_intersection_info_get_normal		get_normal;
};

/*
**	t_scene and iterators : basically gathering visual objects and lights
**	defines its iterators if the type of collection is changed so the
**	other parts of the program don't have to be changed
*/

typedef struct			s_scene
{
	t_light			**lights;
	int				nlights;
	t_object		**objects;
	int				nobjects;
	t_color			background_color;
	t_ambiant_light	ambiant_light;
}						t_scene;

typedef	struct			s_scene_light_iterator
{
	t_light			**lights;
	t_light			*cur;
	int				curidx;
	int				maxidx;
}						t_scene_light_iterator;

typedef struct			s_scene_object_iterator
{
	t_object		**objects;
	t_object		*cur;
	int				curidx;
	int				maxidx;
}						t_scene_object_iterator;

void					t_scene_get_object_iterator(
							t_scene						*scene
							, t_scene_object_iterator	*it);
void					t_scene_get_light_iterator(
							t_scene						*scene
							, t_scene_light_iterator	*it);
bool					t_scene_object_iterator_next(
							t_scene_object_iterator *it);
bool					t_scene_light_iterator_next(
							t_scene_light_iterator *it);
/*
**	t_minirt :  the minirt principal structure, open door for UIs.
*/
typedef struct			s_minirt
{
	t_scene			scene;
	t_camera		*camera;
	t_resolution	resolution;
	t_base			canonical_base;
}						t_minirt;

typedef t_minirt_com (*t_minirt_rtobject_adder)(t_minirt*, t_filert_parsed_obj*);

void					t_boxed_pixel_collection_get_film(
							t_boxed_pixel_collection	*collection
							, t_scene					*scene
							, t_position				*obs
							, t_film					*film);
bool					t_boxed_pixel_collection_next(
							t_boxed_pixel_collection	*collection);
void					t_camera_get_boxed_image(
							t_camera		*camera
							, t_scene		*scene
							, t_image		*image
							, t_screen_box	*box);
void					t_camera_get_image(
							t_camera	*camera
							, t_scene	*scene
							, t_image	*image);
void					t_camera_get_screen(
							t_camera		*camera
							, t_resolution	*resolution
							, t_screen		*screen);
void					t_screen_get_boxed_pixel_collection(
							t_screen					*screen
							, t_screen_box				*box
							, t_boxed_pixel_collection	*collection);
t_com					t_save_bmpfile(
							t_minirt	*minirt
							, char		*filename);
t_size					t_ray_init(
							t_ray			*ray
							, t_position	orig
							, t_position	target);
void					t_ray_get_color(
							t_ray		*ray
							, t_scene	*scene
							, t_color	color);
void					t_intersection_info_get_color(
							t_intersection_info	*info
							, t_scene			*scene
							, t_color			color);
void					t_ray_trace(
							t_ray		*ray
							, t_scene	*scene
							, int		nbounce
							, t_color	color);
/*
**	t_minirt's functions
*/
void					t_minirt_init_object(t_minirt *minirt
							, t_object *object);

/*
**	Pluggging in filertparser
*/

t_minirt_com			t_minirt_load_filert(
							t_minirt	*minirt
							, char		*filename);
t_minirt_com 			t_minirt_add_rtresolution(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rtambiant_light(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rtcamera(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rtlight(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rtsphere(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rtcylinder(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rtsquare(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rttriangle(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com 			t_minirt_add_rtplane(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
void					vec3_from_filert(t_vec3 minirt_vec
							, float filert_vec[3]);
void					vec3_from_filert(t_vec3 minirt_vec
							, float filert_vec[3]);
#endif
