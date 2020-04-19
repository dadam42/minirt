/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:55:39 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 10:06:56 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char *c;

	c = (unsigned char*)dest;
	while (len-- > 0)
	{
		*c = (unsigned char)val;
		c++;
	}
	return (dest);
}
