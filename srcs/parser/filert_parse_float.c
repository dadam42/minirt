#include "filert_parser.h"

static	t_filert_parser_com filert_parse_float_tr_com(t_filert_parser_com com)
{
	if (com == filert_internal)
		return (filert_internal);
	else
		return (filert_error_float_expected);
}

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
		isneg = 1;
	int_part_com = filert_parse_int(str, &int_part);
	*parsed = int_part;
	if (!(**str == '.'))
		return (filert_parse_float_tr_com(int_part_com));
	(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		return (filert_parse_float_tr_com(int_part_com));
	cur = (isneg == 1 ? -0.1 : 0.1);
	while (1)
	{
		*parsed += cur * (**str - '0');
		cur /= 10;
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
			break;
	}
	return (filert_internal);
}
