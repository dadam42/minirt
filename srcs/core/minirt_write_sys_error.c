/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_write_sys_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:31:27 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:31:28 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>
#include <string.h>

void	minirt_write_sys_error(t_minirt *minirt)
{
	extern int errno;

	if (errno != 0)
	{
		minirt->write_error(minirt, "System says :\n");
		minirt->write_error(minirt, strerror(errno));
		minirt->write_error(minirt, "\n");
	}
}
