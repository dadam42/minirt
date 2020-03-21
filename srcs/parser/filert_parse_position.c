#include "filert_parser.h"

t_filert_parser_com	filert_parse_position(char **str
												, t_filert_position *parsed)
{
	short cur;

	cur = 0;
	while (1)
	{
		filert_parser_ignore(str, FILERT_PARSER_IGNORE);
		if (filert_parse_float(str, &(*parsed)[cur]) == filert_error)
			return (filert_error);
		if (cur < 2)
		{
			filert_parser_ignore(str, FILERT_PARSER_IGNORE);
			if (filert_parse_str(str, FILERT_SEP_STR) == filert_error)
				return (filert_error);
			cur++;
			continue ;
		}
		return (filert_internal);
	}
}
