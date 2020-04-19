/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:02:26 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 11:21:38 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			inc;
	const char	*copy_from;
	char		*copy_to;

	if ((src < dst) && (src + len - 1 >= dst))
	{
		copy_from = (const char *)src + len - 1;
		copy_to = (char*)dst + len - 1;
		inc = -1;
	}
	else
	{
		copy_from = (const char *)src;
		copy_to = (char *)dst;
		inc = 1;
	}
	while (len-- > 0)
	{
		*copy_to = *copy_from;
		copy_to = copy_to + inc;
		copy_from = copy_from + inc;
	}
	return (dst);
}
