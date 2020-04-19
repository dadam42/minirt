/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_pcolor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:19:54 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:19:55 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_pcolor(char **str
												, t_filert_pcolor *parsed)
{
	t_filert_parser_com ret;

	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_float(str, &parsed->intensity);
	if (ret != filert_internal)
		return (ret);
	if (parsed->intensity < 0)
		return (filert_error_intensity_out_of_range);
	filert_parser_ignore(str, FILERT_PARSER_IGNORE);
	ret = filert_parse_color(str, &parsed->color);
	if (ret != filert_internal)
		return (ret);
	return (filert_internal);
}
