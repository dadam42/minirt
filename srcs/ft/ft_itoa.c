/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:54:20 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 15:36:03 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_builda_itoa(int n, int sign, int div, size_t dgt_cnt)
{
	int		q;
	char	*ret;
	char	*fwd_ret;

	if ((ret = malloc((dgt_cnt + 1 + (sign == -1 ? 1 : 0)) * sizeof(char))))
	{
		fwd_ret = ret;
		if (sign == -1)
			*fwd_ret++ = '-';
		while (div > 0)
		{
			q = n / div;
			*fwd_ret++ = '0' - q;
			n -= q * div;
			div /= 10;
		}
		*fwd_ret = 0;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	int		div;
	int		sign;
	int		dgt_cnt;

	sign = 1;
	if (n >= 0)
		n = -n;
	else
		sign = -1;
	div = 1;
	dgt_cnt = 0;
	while (n / div <= -10)
	{
		div *= 10;
		dgt_cnt++;
	}
	return (ft_builda_itoa(n, sign, div, dgt_cnt));
}
