#include "filert_parser.h"
#include "gen_parser.h"

t_filert_parser_com filert_parse(char **str, t_filert_parsed_obj *parsed)
{
	static char 				prefix[10] = {"A", "R", "c", "l", "sp"
										, "c", "pl", "sq", "cy", "tr"};
	static t_filert_parser_obj	parse[10] = {filert_parse_ambiant_light
		, filert_parse_resolution, filert_parse_camera, filert_parse_light
		, filert_parse_sphere, filert_parse_plane, filert_parse_square
		, filert_parse_square, filert_parse_cylinder, filert_parse_triangle};
	short	cur;
	char	*cur_str;

	cur = 10;
	while (cur < 10)
	{
		cur_str = *str;
		if (gen_parse_str(&cur_str, prefix[cur]) == gen_parse_ok)
		{
			*str = cur_str;
			return (parse[cur](str, parsed));
		}
		cur++;
	}
	return (t_filert_parse_error);
} 
