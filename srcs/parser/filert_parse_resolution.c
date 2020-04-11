#include "filert_parser.h"

t_filert_parser_com	filert_parse_resolution(char **str, t_filert_parsed_obj *obj)
{
	t_filert_parser_com	ret;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_int(str, &obj->resolution.x); 
	if (ret != filert_internal)
		return (ret);
	if (obj->resolution.x <= 0)
		return (filert_error_resolution_out_of_range);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_int(str, &obj->resolution.y); 
	if (ret != filert_internal)
		return (ret);
	if (obj->resolution.y <= 0)
		return (filert_error_resolution_out_of_range);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error_end_of_line_expected);
	return (filert_resolution);
}
