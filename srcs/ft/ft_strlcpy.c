/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:31:21 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 23:45:44 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *fwd_src;

	fwd_src = src;
	if (dstsize)
	{
		while (dstsize > 1 && *fwd_src)
		{
			*dst = *fwd_src;
			dstsize--;
			fwd_src++;
			dst++;
		}
		*dst = 0;
	}
	while (*fwd_src)
		fwd_src++;
	return (fwd_src - src);
}
