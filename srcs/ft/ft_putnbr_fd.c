/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:36:46 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/17 13:51:34 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	q;

	if (n >= 0)
		n = -n;
	else
		ft_putchar_fd('-', fd);
	div = 1;
	while (n / div <= -10)
		div *= 10;
	while (div > 0)
	{
		q = n / div;
		ft_putchar_fd('0' - q, fd);
		n -= q * div;
		div /= 10;
	}
}
