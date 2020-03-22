#include "filert_parser.h"

t_filert_parser_com	filert_parse_str(char **str
												, char	*parsed)
{
	char	*cur;

	while (**str == *parsed && *parsed)
	{
		(*str)++;
		parsed++;
	}
	if (*parsed)
		return (filert_error);
	cur = FILERT_PARSER_IGNORE;
	while (*cur)
	{
		if (**str == *cur)
			return (filert_internal);
		else
			cur++;
	}
	return (filert_error);
}
