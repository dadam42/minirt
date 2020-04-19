/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:26:53 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:27:01 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_triangle(char **str
											, t_filert_parsed_obj *obj)
{
	short	cur;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	cur = 0;
	while (1)
	{
		if (filert_parse_position(str, &obj->triangle.vertex[cur])
				== filert_error)
			return (filert_error);
		filert_parser_ignore(str, FILERT_PARSER_IGNORE);
		if (cur < 2)
		{
			cur++;
			continue ;
		}
		break ;
	}
	if (filert_parse_color(str, &obj->triangle.color) == filert_error)
		return (filert_error);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	if (**str)
		return (filert_error);
	return (filert_triangle);
}
