#include "filert_parser.h"

t_filert_parser_com	filert_parse_resolution(char **str, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_int(str, &obj->resolution.x) == filert_error)
		return (filert_error);
	if (obj->resolution.x <= 0)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_int(str, &obj->resolution.y) == filert_error)
		return (filert_error);
	if (obj->resolution.y <= 0)
		return (filert_error);
	return (filert_resolution);
}
