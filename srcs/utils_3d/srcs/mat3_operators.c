/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:50:20 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:50:22 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

void	t_mat3_copy(t_mat3 dst, t_mat3 src)
{
	short ldx;
	short cdx;

	ldx = 0;
	while (ldx < 3)
	{
		cdx = 0;
		while (cdx < 3)
		{
			dst[ldx][cdx] = src[ldx][cdx];
			cdx++;
		}
		ldx++;
	}
}

void	t_mat3_add(t_mat3 a, t_mat3 b, t_mat3 r)
{
	short ldx;
	short cdx;

	ldx = 0;
	while (ldx < 3)
	{
		cdx = 0;
		while (cdx < 3)
		{
			r[ldx][cdx] = a[ldx][cdx] + b[ldx][cdx];
			cdx++;
		}
		ldx++;
	}
}

void	t_mat3_lcomb(double l, t_mat3 a, t_mat3 b, t_mat3 r)
{
	short ldx;
	short cdx;

	ldx = 0;
	while (ldx < 3)
	{
		cdx = 0;
		while (cdx < 3)
		{
			r[ldx][cdx] = l * a[ldx][cdx] + b[ldx][cdx];
			cdx++;
		}
		ldx++;
	}
}

void	t_mat3_smult(double l, t_mat3 a, t_mat3 r)
{
	short ldx;
	short cdx;

	ldx = 0;
	while (ldx < 3)
	{
		cdx = 0;
		while (cdx < 3)
		{
			r[ldx][cdx] = l * a[ldx][cdx];
			cdx++;
		}
		ldx++;
	}
}

void	t_mat3_prod(t_mat3 a, t_mat3 b, t_mat3 r)
{
	short	ldx;
	short	cdx;
	short	sdx;
	t_mat3	tmpres;

	ldx = 0;
	while (ldx < 3)
	{
		cdx = 0;
		while (cdx < 3)
		{
			tmpres[ldx][cdx] = 0;
			sdx = 0;
			while (sdx < 3)
			{
				tmpres[ldx][cdx] += a[ldx][sdx] * b[sdx][cdx];
				sdx++;
			}
			cdx++;
		}
		ldx++;
	}
	t_mat3_copy(r, tmpres);
}
