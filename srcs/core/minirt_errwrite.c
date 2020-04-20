/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_errwrite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:02:29 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:02:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <unistd.h>

ssize_t	minirt_errwrite(t_minirt *minirt, char *msg)
{
	return (write(minirt->erroutput, msg, ft_strlen(msg)));
}
