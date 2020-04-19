/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filert_error_get_msg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:08:08 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:08:10 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filert_parser.h"

char	*t_filert_error_get_msg(t_filert_error *error, t_filert_parser_com com)
{
	return (error->msg[com - filert_error]);
}
