#include "filert_parser.h"

t_filert_parser_com	filert_parse_light(char **str
												, t_filert_parsed_obj *obj)
{
	t_filert_parser_com ret;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_position(str, &obj->light.position); 
	if (ret != filert_internal)
		return (ret);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_pcolor(str, &obj->light.pcolor);
	if (ret != filert_internal)
		return (ret);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);	
	if (**str)
		return (filert_error_end_of_line_expected);
	return (filert_light);
}
