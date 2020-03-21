#include "filert_parser.h"

void	filert_parser_ignore(char **str, char	*ignore)
{
	char	*cur_ignore;

	cur_ignore = ignore;
	while (*cur_ignore)
		if (**str == *cur_ignore)
		{
			(*str)++;
			cur_ignore = ignore;
		}
		else
			cur_ignore++;
}
