/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_parser_ignore.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:24:12 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:24:18 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

void	filert_parser_ignore(char **str, char *ignore)
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
