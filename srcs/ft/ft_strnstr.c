/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:08:05 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/10 17:29:46 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t idx;

	if (!*needle)
		return ((char *)haystack);
	while (len > 0 && *haystack)
	{
		idx = 0;
		while (*(needle + idx) && *(haystack + idx) == *(needle + idx))
		{
			if (!*(needle + idx + 1))
				return ((char *)haystack);
			if (idx + 1 >= len)
				return (NULL);
			idx++;
		}
		len--;
		haystack++;
	}
	return (NULL);
}
