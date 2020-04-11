#include "filert_parser.h"

t_filert_parser_com	filert_parse_color(char **str
												, t_filert_color *parsed)
{
	int 				cur_parsed;
	short				cur;
	t_filert_parser_com ret;

	cur = 0;
	while (1)
	{
		filert_parser_ignore(str, FILERT_PARSER_IGNORE);
		ret = filert_parse_int(str, &cur_parsed);
		if (ret != filert_internal)
			return (ret);
		if (!(cur_parsed >= 0 && cur_parsed <= 255))
			return (filert_error_color_out_of_range);
		(*parsed)[cur] = cur_parsed;
		if (cur < 2)
		{
			filert_parser_ignore(str, FILERT_PARSER_IGNORE);
			if (filert_parse_str(str, FILERT_SEP_STR) != filert_internal)
				return (filert_error_bad_separator);
			cur++;
			continue;
		}
		break;
	}
	return (filert_internal);
}
