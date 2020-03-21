#include "filert_parser.h"

t_filert_parser_com	filert_parse_direction(char **str
												, t_filert_direction *parsed)
{
	short cur;

	if (filert_parse_position(str, parsed) == filert_error)
		return (filert_error);
	cur = 0;
	while (cur < 3)
		if ((*parsed)[cur] >= -1 && (*parsed)[cur] <= 1)
			cur++;
		else
			return (filert_error);
	return (filert_internal);
}
