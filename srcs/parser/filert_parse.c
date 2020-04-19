/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:10:40 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:41:01 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"
#include <stdbool.h>

static bool			isignorechar(char c)
{
	char *cur_ign;

	cur_ign = FILERT_PARSER_IGNORE;
	while (*cur_ign)
	{
		if (*cur_ign == c)
			return (true);
		cur_ign++;
	}
	return (false);
}

t_filert_parser_com	filert_parse(char **str, t_filert_parsed_obj *parsed)
{
	static char					*prefix[9] = {"A", "R", "cy", "l", "sp"
										, "pl", "sq", "c", "tr"};
	static t_filert_parser_obj	parse[9] = {filert_parse_ambiant_light
		, filert_parse_resolution, filert_parse_cylinder, filert_parse_light
		, filert_parse_sphere, filert_parse_plane, filert_parse_square
		, filert_parse_camera, filert_parse_triangle};
	short						cur;
	char						*cur_str;

	cur = 0;
	while (cur < 9)
	{
		cur_str = *str;
		if (filert_parse_str(&cur_str, prefix[cur]) == filert_internal)
		{
			if (isignorechar(*cur_str))
			{
				*str = cur_str;
				return (parse[cur](str, parsed));
			}
		}
		cur++;
	}
	return (filert_error_unknown_type);
}
