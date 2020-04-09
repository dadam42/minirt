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
	minirt_ok, minirt_error, minirt_mem_error, minirt_parse_error, minirt_file_error
}						t_minirt_com;

typedef t_vec3			t_position;
typedef t_vec3			t_direction;
typedef	t_vec3			t_translation;
typedef t_vec3			t_normal;
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

/*
**	t_film can be
**		- 'legacy'	(t_color array) 
**		- 'rgb'		(t_rgb_comp array)			
*/
typedef union			u_film
{
	t_color		*legacy;
	t_rgb_comp	*rgb;
}						t_film;
/*Convert (in place)size pixels from legacy to rgb starting at film*/
void					t_film_legacy_to_rgb(t_film *film
									, int size);

/*
**	t_image : model for... an image, owns its film.
*/
typedef struct			s_image
{
	t_film			film;
	t_resolution	resolution;
}						t_image;

/*
**	t_screen : model for a screen.
**	t_screen can produce boxed_pixel_collections from a screen_box
*/
typedef	struct			s_screen
{
	t_resolution	resolution;
	t_size			pixel_size;
	t_position		ulc_position;
	t_translation	dh;
	t_translation	dw;
}						t_screen;
typedef struct s_boxed_pixel_collection
						t_boxed_pixel_collection;
typedef struct s_screen_box
						t_screen_box;
void					t_screen_get_boxed_pixel_collection(
							t_screen					*screen
							, t_screen_box				*box
							, t_boxed_pixel_collection	*collection);
typedef int				t_screen_coord[2];
/*
**	t_screen_box : model for a rectangular window on a t_screen.
**	ulc and brc resp. stand for upper-left corner and bottom-right corner.
**	no check on these values is done : use with caution.
*/
struct					s_screen_box
{
	t_screen_coord	ulc;
	t_screen_coord	brc;
};

typedef enum			e_pixel_coord
{
	height, width
}						t_pixel_coord;

/*
**	t_boxed_pixel_collection : model for the collection of pixels of a screen
**	boxed by a screen_box
**	Can be used as an iterator with the function t_boxed_pixel_collection_next
**	Can produce film : obs is then usually the camera's position whose produced 
**	the screen whose produced the the boxed_pixel_collection.
**	camera (+resolution)			-> screen
**	screen (+screen_box)			-> boxed_pixel_collection
**	boxed_pixel_collection(+obs +minirt)	-> film
**	(?) Can produce image but seems useless (?)
*/
typedef struct s_minirt	t_minirt;
typedef struct s_scene	t_scene;

struct					s_boxed_pixel_collection
{
	t_screen_coord	min;
	t_screen_coord	cur;
	t_screen_coord	max;
	t_position		position;
	t_translation	dh;
	t_translation	dw;
};
void					t_boxed_pixel_collection_get_film(
							t_boxed_pixel_collection	*collection
							, t_minirt					*minirt
							, t_position				*obs
							, t_film					*film);
void					t_boxed_pixel_collection_get_image(
							t_boxed_pixel_collection *collection
							, t_scene				*scene
							, t_position			*obs
							, t_image				*image);
bool					t_boxed_pixel_collection_next(
							t_boxed_pixel_collection	*collection);

/*
**	t_camera : model for a camera.
**	Can produce screens.
**	(?) Can also produce images and boxed_images... maybe useless (?)
*/

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
void					t_camera_get_image(
							t_camera	*camera
							, t_scene	*scene
							, t_image	*image);
void					t_camera_get_screen(
							t_camera		*camera
							, t_resolution	*resolution
							, t_screen		*screen);
void					t_camera_get_boxed_image(
							t_camera		*camera
							, t_scene		*scene
							, t_image		*image
							, t_screen_box	*box);

/*
**	t_ray : model for a ray.
**	Can produce color 
**	t_ray_get_color(t_ray*, t_scene*, t_color) is the entry point
**		of the raytracing algorithm.
*/
typedef struct			s_ray
{
	t_position	start;
	t_direction	direction;
}						t_ray;
/* t_ray_init returns the distance between orig and target */
t_size					t_ray_init(
							t_ray			*ray
							, t_position	orig
							, t_position	target);
void					t_ray_get_color(
							t_ray		*ray
							, t_minirt	*minirt
							, t_color	color);
/*(?) t_color_ray : Never used, to remove (?)*/
typedef struct			s_color_ray
{
	t_ray	ray;
	t_color	color;
}						t_color_ray;

typedef struct			s_light
{
	t_position	position;
	t_color		color;
}						t_light;

typedef	t_color 		t_ambiant_light;

typedef struct s_intersection
						t_intersection;

/*
**	t_object : structural specification of all visible objects.
**				mostly pointers on functions.
*/

typedef struct s_object
						t_object;
typedef struct s_object_coord
						t_object_coord;
/*
**		Catalog of pointers, 
**		_each_ one of these must be defined by 
**		any new object realisation
*/

typedef void			(*t_object_set_intersection)
							(t_object*, t_ray*, t_intersection*);
typedef void			(*t_object_get_albedo)
							(t_object*, t_object_coord*, t_albedo);
typedef void			(*t_object_get_coord)
							(t_object*, t_position, t_object_coord*);
typedef void			(*t_object_get_normal)
							(t_object*, t_object_coord*, t_direction);
struct					s_object
{
	t_base						base;
	t_color						albedo;
	t_object_set_intersection	set_intersection;
	t_object_get_coord			get_coord;
	t_object_get_normal			get_normal;
	t_object_get_albedo			get_albedo;
};

void					t_object_preset_intersection(t_object *object
								, t_intersection *inter);
/*
**	Fall over get_albedo
*/

void					t_object_dummy_get_albedo
							(t_object *obj
							, t_object_coord *coord, t_albedo albedo);

/*
**	The following realisations of the above t_object type can use a couple of
**	coordinates system to localize a point on its surface : 
**		cartesian 	: 	a t_vec3 aka t_position in the global coordinates 
**						system which will be provided by the t_minirt struct 
**						(see canonical member)
**		local		:	a t_float[2] aka t_local_coord which will be computed,
**						if needed it can be of various coordinates system,
**						typically spherical for a sphere,
**						barycentric for a triangle,
**						cylindrical for cylinders...
*/

struct			s_object_coord
{
	t_position		cartesian;
	t_local_coord	local;
};

/*
** t_sphere :  a realisation of t_object defined above.
*/

typedef struct			s_sphere
{
	t_object	object;
	t_position	center;
	t_size		radius;
}						t_sphere;

void 					t_sphere_set_intersection(t_object *obj
							, t_ray *ray, t_intersection *intersection);
void 					t_sphere_set_intersection_alt(t_object *obj
							, t_ray *ray, t_intersection *intersection);
void					*t_sphere_get_albedo(t_object*
							, t_object_coord *coord, t_albedo);
void					t_sphere_get_coord
							(t_object*, t_position, t_object_coord*);
void					t_sphere_get_normal
							(t_object*, t_object_coord*, t_direction);
/*
**	t_intersection : 	heart of ray tracing algorithm's datas.
**						it gather and cache any data required for
**						the ray tracing algorithm.
*/

struct					s_intersection
{
	t_object		*object;
	t_ray			*ray;
	t_time			time;
	t_position		position;
	t_object_coord	coords;
	t_direction		normal;
	t_albedo		albedo;
	t_color			light_influence;
};

void					t_intersection_init(t_intersection *inter
							, t_scene *scene, t_ray *ray);
void					t_intersection_complete(t_intersection *inter);

/*
**	t_scene and iterators : basically gathering visual objects and lights
**	defines its iterators if the type of collection is changed so the
**	other parts of the program don't have to be changed
*/

typedef struct			s_scene
{
	t_array_collection	light_collection;
	t_array_collection	object_collection;
	t_array_collection	camera_collection;
	t_color				*background_color;
	t_color				*black;
	t_ambiant_light		ambiant_light;
}						t_scene;

typedef struct s_scene_object_iterator
						t_scene_object_iterator;
struct					s_scene_object_iterator
{
	t_array_collection_iterator 	iterator;
	bool							(*next)(t_scene_object_iterator*);
	t_object						*(*deref)(t_scene_object_iterator*);
};

typedef struct s_scene_light_iterator
						t_scene_light_iterator;
struct					s_scene_light_iterator
{
	t_array_collection_iterator 	iterator;
	bool							(*next)(t_scene_light_iterator*);
	t_light							*(*deref)(t_scene_light_iterator*);
};

typedef struct s_scene_camera_iterator
						t_scene_camera_iterator;
struct					s_scene_camera_iterator
{
	t_array_collection_iterator 	iterator;
	bool							(*next)(t_scene_camera_iterator*);
	t_camera						*(*deref)(t_scene_camera_iterator*);
};

void					t_scene_get_object_iterator(
							t_scene						*scene
							, t_scene_object_iterator	*it);
void					t_scene_get_light_iterator(
							t_scene						*scene
							, t_scene_light_iterator	*it);
void					t_scene_get_camera_iterator(
							t_scene						*scene
							, t_scene_camera_iterator	*it);
void					t_scene_get_light_influence(t_scene *scene
							, t_intersection *inter);
void					t_scene_init(t_scene* scene);
void					t_scene_release(t_scene* scene);
/*
**	t_minirt :  the minirt principal structure, open door for UIs.
*/
typedef struct			s_minirt
{
	t_scene			scene;
	t_camera		*camera;
	t_resolution	resolution;
	t_base			*canonical;
	t_direction		*default_direction;
	t_color			*background_color;
	int				max_bounce;
}						t_minirt;

void					t_minirt_init(t_minirt *minirt);
void					t_minirt_release(t_minirt* minirt);

t_minirt_com			t_save_bmpfile(
							t_minirt	*minirt
							, char		*filename);
/*
** t_scene's functions
*/

t_minirt_com	t_scene_add_object(t_scene *scene, t_object *object);
t_minirt_com	t_scene_add_light(t_scene *scene, t_light *light);
t_minirt_com	t_scene_add_camera(t_scene *scene, t_camera *camera);


/*
**	t_minirt's functions
*/
void					t_minirt_init_object(t_minirt *minirt
							, t_object *object);

/*
**	Pluggging in filertparser
*/

typedef t_minirt_com (*t_minirt_rtobject_adder)(t_minirt*, t_filert_parsed_obj*);

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
void					t_color_from_filert(
							t_color		color
							, t_filert_color	rtcolor);
void					t_pcolor_from_filert(
							t_color		*color
							, t_filert_pcolor	*rtpcolor);
void					t_direction_from_filert(
							t_direction	dir
							, t_filert_direction	rtdir
							, t_direction	default_dir);
#endif
