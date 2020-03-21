#include "filert_parser.h"

t_filert_parser_com	filert_parse_plane(char **str
												, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_position(str, &obj->plane.insertion) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_direction(str, &obj->plane.orth) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_color(str, &obj->plane.color) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error);
	return (filert_plane);
}
