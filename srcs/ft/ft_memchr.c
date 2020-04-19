/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:14:23 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 14:18:46 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *haystack, int needle, size_t range)
{
	size_t cdx;

	cdx = 0;
	while (cdx < range)
	{
		if (*((unsigned char*)haystack + cdx) ==
			(unsigned char)needle)
			return ((void*)(haystack + cdx));
		cdx++;
	}
	return (NULL);
}
