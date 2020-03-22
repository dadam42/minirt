#ifndef TEST_H
# define TEST_H
# include "filert_parser.h"
# define FILERT_COM_STR_SUFFIX { "resolution", "ambiant_light"\
								, "camera", "light", "sphere", "cylinder"\
								, "square", "triangle", "plane", "internal", "error"}

typedef void (*t_filert_parsed_obj_printf)(t_filert_parsed_obj *);
typedef int  (*t_filert_parsed_obj_equal)(t_filert_parsed_obj *, t_filert_parsed_obj *);

void	t_filert_color_printf(t_filert_color *color);
int		t_filert_color_equal(t_filert_color*, t_filert_color*);
void	t_filert_pcolor_printf(t_filert_pcolor *pcolor);
int		t_filert_pcolor_equal(t_filert_pcolor*, t_filert_pcolor*);
void	t_filert_position_printf(t_filert_position *pos);
int		t_filert_position_equal(t_filert_position*, t_filert_position*);
void	t_filert_direction_printf(t_filert_position *pos);
int		t_filert_direction_equal(t_filert_position*, t_filert_position*);
void	t_filert_com_printf(t_filert_parser_com com);
void	t_filert_resolution_printf(t_filert_parsed_obj*);
int		t_filert_resolution_equal(t_filert_parsed_obj*, t_filert_parsed_obj*);

void	t_filert_parse_printf(t_filert_parser_com com, t_filert_parsed_obj*);
int		t_filert_parse_equal(t_filert_parser_com com, t_filert_parsed_obj*, t_filert_parsed_obj*);
#endif
