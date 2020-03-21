#include "filert_parser.h"

t_filert_parser_com	filert_parse_ambiant_light(char **str
												, t_filert_parsed_obj *obj)
{
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (filert_parse_pcolor(str, &obj->ambiant_light) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error);
	return (filert_ambiant_light);
}
