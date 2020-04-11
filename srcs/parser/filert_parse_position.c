#include "filert_parser.h"

t_filert_parser_com	filert_parse_position(char **str
												, t_filert_position *parsed)
{
	short				cur;
	t_filert_parser_com	ret;

	cur = 0;
	while (1)
	{
		filert_parser_ignore(str, FILERT_PARSER_IGNORE);
		ret = filert_parse_float(str, &(*parsed)[cur]);
		if (ret != filert_internal)
			return (ret);
		if (cur < 2)
		{
			filert_parser_ignore(str, FILERT_PARSER_IGNORE);
			if (filert_parse_str(str, FILERT_SEP_STR) != filert_internal)
				return (filert_error_bad_separator);
			cur++;
			continue ;
		}
		return (filert_internal);
	}
}
