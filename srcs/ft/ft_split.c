/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:57:24 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/17 13:31:50 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*next(char const *start, char c)
{
	while (*start && *start != c)
		start++;
	return (start);
}

static size_t		wc(char const *str, char c)
{
	size_t		ret;
	char const	*fwd;

	ret = 0;
	fwd = str;
	while (*str)
	{
		fwd = next(str, c);
		if (fwd == str)
			fwd++;
		else
			ret++;
		str = fwd;
	}
	return (ret);
}

int					check_build_chunk(char const *str, char const *fwd_str,
		char ***ret, char **fwd_ret)
{
	char	*chunk;
	size_t	wc;

	if ((chunk = malloc((fwd_str - str + 1) * sizeof(char))))
	{
		ft_memcpy(chunk, str, fwd_str - str);
		chunk[fwd_str - str] = 0;
		*fwd_ret = chunk;
		return (1);
	}
	else
	{
		wc = fwd_ret - *ret + 1;
		while (wc-- > 0)
			free(*--fwd_ret);
		free(*ret);
		*ret = NULL;
		return (0);
	}
}

char				**ft_split(char const *str, char c)
{
	size_t		wcount;
	char		**ret;
	char		**fwd_ret;
	char const	*fwd_str;

	wcount = wc(str, c);
	if ((ret = malloc((wcount + 1) * sizeof(char*))))
	{
		ret[wcount] = NULL;
		fwd_ret = ret;
		while (*str)
		{
			fwd_str = next(str, c);
			if (fwd_str == str)
				fwd_str++;
			else if (!check_build_chunk(str, fwd_str, &ret, fwd_ret++))
				break ;
			str = fwd_str;
		}
	}
	return (ret);
}
