/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:00:32 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 11:21:19 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			idx;
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	idx = 0;
	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	while (idx < len)
	{
		*(ucdst + idx) = *(ucsrc + idx);
		if (*(ucsrc + idx++) == (unsigned char)c)
			return (ucdst + idx);
	}
	return (NULL);
}
