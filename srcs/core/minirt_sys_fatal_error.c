/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_sys_fatal_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:30:21 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:30:23 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt_sys_fatal_error(t_minirt *minirt)
{
	minirt_write_sys_error(minirt);
	minirt_exit(minirt, minirt_error);
}
