#include "filert_parser.h"

t_filert_parser_com	filert_parse_float(char **str
												, float	*parsed)
{
	short				isneg;
	t_filert_parser_com	int_part_com;
	int					int_part;
	float				cur;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	isneg = 0;
	if (**str == '-')
		isneg == 1;
	int_part_com = filert_parse_int(str, &int_part);
	parsed = int_part;
	if (!(**str == '.'))
		if (int_part_com == filert_error)
			return (filert_error)
		else
			return (filert_internal);
	(*str)++;
	cur = (isneg == 1 ? -0.1 : 0.1);
	while (**str >= '0' && **str <= '9')
	{
		*parsed += cur * (**str - '0');
		cur /= 10;
		(*str)++;
	}
	return (filert_internal);
}
