/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:23:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/12 19:29:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char const *s)
{
	size_t		size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

char		*ft_strchr(char const *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (!c)
		return ((char*)s);
	return (NULL);
}

char		*ft_strdup(char const *s1)
{
	char			*str;
	char			*tmp;
	char const		*cpy_s1;
	size_t			len;

	len = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	tmp = str;
	cpy_s1 = s1;
	while (len--)
		*tmp++ = *cpy_s1++;
	*tmp = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*tmp;
	char const		*cpy_s;
	size_t			maxlen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		maxlen = 0;
	else
	{
		cpy_s = s;
		while (len-- && *cpy_s)
			cpy_s++;
		maxlen = (size_t)(cpy_s - s);
	}
	if (!(str = (char*)malloc(sizeof(*str) * (maxlen + 1))))
		return (NULL);
	tmp = str;
	cpy_s = s;
	while (maxlen--)
		*tmp++ = *(cpy_s++ + start);
	*tmp = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	char			*tmp;

	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	if (!s2)
		return (ft_strdup(s1));
	if (!(str = (char*)malloc((sizeof(*tmp)
		* (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (str);
}
