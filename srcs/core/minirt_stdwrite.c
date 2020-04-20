/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_stdwrite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:28:06 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:28:20 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <unistd.h>

ssize_t	minirt_stdwrite(t_minirt *minirt, char *msg)
{
	return (write(minirt->stdoutput, msg, ft_strlen(msg)));
}
