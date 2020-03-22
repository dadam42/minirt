#include "filert_parser.h"

t_filert_parser_com	filert_parse_str(char **str
												, char	*parsed)
{
	while (**str == *parsed && *parsed)
	{
		(*str)++;
		parsed++;
	}
	if (*parsed)
		return (filert_error);
	return (filert_internal);
}
