#include "filert_parser.h"

t_filert_parser_com	filert_parse_camera(char **str, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_position(str, &obj->camera.position) == filert_error)
		return (filert_error);
	filert_parser_ignoer(str, FILERT_PARSER_IGNORE);
	if (filert_parse_direction(str, &obj->camera.direction) == filert_error)
		return (filert_error);
	if (filert_parse_float(str, &obj->camera.fov) == filert_error)
		return (filert_error);
	if (!(obj->camera.fov > 0 && obj->camera.fov < 180))
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error);
	return (filert_camera);
}
