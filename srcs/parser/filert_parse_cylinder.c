#include "filert_parser.h"

t_filert_parser_com	filert_parse_cylinder(char **str
												, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_position(str, &obj->cylinder.insertion) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_direction(str, &obj->cylinder.direction) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_float(str, &obj->cylinder.diameter) == filert_error)
		return (filert_error);
	if (obj->cylinder.diameter < 0)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_float(str, &obj->cylinder.height) == filert_error)
		return (filert_error);
	if (obj->cylinder.height < 0)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_color(str, &obj->cylinder.color) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error);
	return (filert_cylinder);
}
