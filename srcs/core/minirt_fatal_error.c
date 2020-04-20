/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_fatal_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:03:05 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:03:07 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt_fatal_error(t_minirt *minirt, t_minirt_com errcode)
{
	minirt->write_error(minirt, minirt_strerror(minirt, errcode));
	minirt_exit(minirt, minirt_error);
}
