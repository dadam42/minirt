#include "filert_parser.h"

t_filert_parser_com	filert_parse_triangle(char **str
												, t_filert_parsed_obj *obj)
{
	short	cur;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	cur = 0;
	while (1)
	{
		if (filert_parse_position(str, &obj->triangle.vertex[cur])
				== filert_error)
			return (filert_error);
		filert_parser_ignore(str, FILERT_PARSER_IGNORE);
		if (cur < 2)
		{
			cur++;
			continue ;
		}
		break ;
	}
	if (filert_parse_color(str, &obj->triangle.color) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error);
	return (filert_triangle);
}
