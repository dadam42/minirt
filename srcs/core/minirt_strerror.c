/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_strerror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:29:56 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:29:58 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*minirt_strerror(t_minirt *minirt, t_minirt_com errcode)
{
	if (errcode >= 0)
		return (minirt->err_msg[errcode - minirt_error]);
	return (0);
}
