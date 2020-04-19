/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parse_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:13:38 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:13:39 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

t_filert_parser_com	filert_parse_direction(char **str
												, t_filert_direction *parsed)
{
	short				cur;
	t_filert_parser_com	ret;

	ret = filert_parse_position(str, parsed);
	if (ret != filert_internal)
		return (ret);
	cur = 0;
	while (cur < 3)
		if ((*parsed)[cur] >= -1 && (*parsed)[cur] <= 1)
			cur++;
		else
			return (filert_error_direction_out_of_range);
	return (filert_internal);
}
