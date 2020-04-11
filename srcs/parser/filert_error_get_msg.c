#include "filert_parser.h"

char	*t_filert_error_get_msg(t_filert_error *error, t_filert_parser_com com)
{
	return (error->msg[com - filert_error]);
}
