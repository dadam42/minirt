/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:52:44 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 23:23:48 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	len_alloc;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (len + start <= strlen)
		len_alloc = len;
	else
	{
		len_alloc = (strlen >= start ? strlen - start : 0);
	}
	if ((ret = malloc((len_alloc + 1) * sizeof(char))))
	{
		ft_memcpy(ret, s + start, len_alloc);
		ret[len_alloc] = 0;
	}
	return (ret);
}
