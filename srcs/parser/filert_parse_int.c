#include "filert_parser.h"

t_filert_parser_com	filert_parse_int(char **str
												, int	*parsed)
{
	short	isneg;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	isneg = 0;
	if (**str == '-')
	{
		isneg = 1;
		(*str)++;
	}
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	*parsed = 0;
	if (!(**str >= '0' && **str <= '9'))
		return (filert_error);
	while (1)
	{
		*parsed = 10 * *parsed - **str + '0';
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
			break;
	}
	if (!isneg)
		*parsed *= -1;
	return (filert_internal);
}
