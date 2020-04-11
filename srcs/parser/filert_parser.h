#ifndef FILERT_PARSER
# define FILERT_PARSER
# define FILERT_PARSER_IGNORE " \t\v"
# define FILERT_SEP_STR	","

typedef enum	e_filert_parser_com
{
	filert_resolution
	, filert_ambiant_light
	, filert_camera
	, filert_light
	, filert_sphere
	, filert_cylinder
	, filert_square
	, filert_triangle
	, filert_plane
	, filert_internal
	, filert_error
	, filert_error_unknown_type
	, filert_error_int_expected
	, filert_error_float_expected
	, filert_error_end_of_line_expected
	, filert_error_bad_separator
	, filert_error_color_out_of_range
	, filert_error_intensity_out_of_range
	, filert_error_direction_out_of_range
	, filert_error_sphere_diameter_out_of_range
	, filert_error_fov_out_of_range
	, filert_error_resolution_out_of_range
}				t_filert_parser_com;

typedef struct	s_filert_error
{
	char	**msg;
}				t_filert_error;

void			t_filert_error_init(t_filert_error *error);
char			*t_filert_error_get_msg(t_filert_error *error
										, t_filert_parser_com com);

typedef struct	s_filert_resolution
{
	int x;
	int y;
}				t_filert_resolution;

typedef unsigned char t_filert_color[3];
typedef float	t_filert_position[3];
typedef float	t_filert_direction[3];

typedef struct	s_filert_camera
{
	t_filert_position	position;
	t_filert_direction	direction;
	float				fov;
}				t_filert_camera;

typedef struct	s_filert_pcolor
{
	t_filert_color	color;
	float			intensity;
}				t_filert_pcolor;

typedef t_filert_pcolor t_filert_ambiant_light;

typedef struct	s_filert_light
{
	t_filert_position	position;
	t_filert_pcolor		pcolor;
}				t_filert_light;

typedef struct	s_filert_sphere
{
	t_filert_position	center;
	float				diameter;
	t_filert_color		color;
}				t_filert_sphere;

typedef struct	s_filert_cylinder
{
	t_filert_position	insertion;
	t_filert_direction	direction;
	float				diameter;
	float				height;
	t_filert_color		color;
}				t_filert_cylinder;

typedef	struct	s_filert_square
{
	t_filert_position	center;
	t_filert_direction	orth;
	float				size;
	t_filert_color		color;
}				t_filert_square;

typedef struct	s_filert_triangle
{
	t_filert_position	vertex[3];
	t_filert_color		color;
}				t_filert_triangle;

typedef struct	s_filert_plane
{
	t_filert_position	insertion;
	t_filert_direction	orth;
	t_filert_color		color;
}				t_filert_plane;

typedef union	u_filert_parsed_obj
{
	t_filert_resolution		resolution;
	t_filert_camera			camera;
	t_filert_ambiant_light	ambiant_light;
	t_filert_light			light;
	t_filert_sphere			sphere;
	t_filert_cylinder		cylinder;
	t_filert_square			square;
	t_filert_triangle		triangle;
	t_filert_plane			plane;
}				t_filert_parsed_obj;

typedef t_filert_parser_com	(*t_filert_parser_obj)(char **str
							, t_filert_parsed_obj *parsed);

t_filert_parser_com	filert_parse(char **str, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_ambiant_light(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_resolution(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_camera(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_light(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_sphere(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_plane(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_square(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_cylinder(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_triangle(char **str
												, t_filert_parsed_obj *parsed);
t_filert_parser_com	filert_parse_direction(char **str
												, t_filert_direction *parsed);
t_filert_parser_com	filert_parse_position(char **str
												, t_filert_position *parsed);
t_filert_parser_com	filert_parse_pcolor(char **str
												, t_filert_pcolor *parsed);
t_filert_parser_com	filert_parse_color(char **str
												, t_filert_color *parsed);
t_filert_parser_com	filert_parse_float(char **str
												, float	*parsed);
t_filert_parser_com	filert_parse_int(char **str
												, int	*parsed);
t_filert_parser_com	filert_parse_str(char **str
												, char	*parsed);
void				filert_parser_ignore(char **str
												, char	*ignore);
#endif
