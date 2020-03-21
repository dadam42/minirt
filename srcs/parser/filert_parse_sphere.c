#include "filert_parser.h"

t_filert_parser_com	filert_parse_sphere(char **str
												, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_position(str, &obj->sphere.center) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_float(str, &obj->sphere.diameter) == filert_error)
		return (filert_error);
	if (obj->sphere.diameter < 0)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_color(str, &obj->sphere.color) == filert_error)
		return (filert_error);
	if (**str)
		return (filert_error);
	return (filert_sphere);
}
