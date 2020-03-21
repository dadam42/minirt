#include "filert_parser.h"

t_filert_parser_com	filert_parse_color(char **str
												, t_filert_color *parsed)
{
	int 	cur_parsed;
	short	cur;

	cur = 0;
	while (1)
	{
		filert_parser_ignore(str, FILERT_IGNORE_STR);
		if (filert_parse_int(str, &cur_parsed) == filert_error)
			return (filert_error);
		if (!(cur_parsed >= 0 && cur_parsed <= 255))
			return (filert_error);
		(*parsed)[cur] = cur_parsed;
		if (cur < 2)
		{
			filert_parser_ignore(str, FILERT_IGNORE_STR);
			if (filert_parse_str(str, FILERT_SEP_STR) == filert_error)
				return (filert_error);
			cur++;
			continue;
		}
		break;
	}
	return (filert_internal);
}
