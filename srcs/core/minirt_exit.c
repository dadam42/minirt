/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:02:49 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:02:55 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

void	minirt_exit(t_minirt *minirt, t_minirt_com exitcode)
{
	minirt_release(minirt);
	exit(exitcode);
}
