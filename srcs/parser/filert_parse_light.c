#include "filert_parser.h"

t_filert_parser_com	filert_parse_light(char **str
												, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_position(str, &obj->light.position) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_pcolor(str, &obj->light.pcolor) == filert_error)
		return (filert_error);
	if (**str)
		return (filert_error);
	return (filert_light);
}
