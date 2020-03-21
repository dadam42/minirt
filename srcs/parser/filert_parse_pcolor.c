#include "filert_parser.h"

t_filert_parser_com	filert_parse_pcolor(char **str
												, t_filert_pcolor *parsed)
{
	filert_parser_ignore(str, FILERT_IGNORE_STR);
	if (filert_parse_float(str, &parsed->intensity) == filert_error)
		return (filert_error);
	if (parsed->intensity < 0)
		return (filert_error);
	filert_parser_ignore(str, FILERT_IGNORE_STR);
	if (filert_parse_color(str, &parsed->color) == filert_error)
		return (filert_error);
	return (filert_internal);
}
