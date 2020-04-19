/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:35:57 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 23:27:19 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	const	*find_first_not_in_set(char const *start, char const *set)
{
	while (*start)
		if (ft_ischarinset(*start, set))
			start++;
		else
			break ;
	return (start);
}

static char const	*find_last_not_in_set(char const *start, char const *set)
{
	char const *bwd_end;

	bwd_end = start;
	while (*bwd_end)
		bwd_end++;
	bwd_end--;
	while (bwd_end > start)
	{
		if (ft_ischarinset(*bwd_end, set))
			bwd_end--;
		else
			break ;
	}
	return (bwd_end);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*ret;
	size_t		len;

	start = find_first_not_in_set(s1, set);
	end = find_last_not_in_set(start, set);
	len = end - start + 2;
	if ((ret = malloc(len * sizeof(char))))
	{
		ft_memcpy(ret, start, len - 1);
		ret[len - 1] = 0;
	}
	return (ret);
}
