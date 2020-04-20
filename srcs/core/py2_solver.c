/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   py2_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 02:44:21 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 02:44:22 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils_3d.h"
#include <stdbool.h>
#include <math.h>

void	py2_solver_init(t_py2_solver *solver, t_float coefs[3])
{
	t_float disc;

	disc = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
	solver->cursol = -1;
	if (disc < 0)
		solver->nsol = 0;
	else
	{
		solver->nsol = 1;
		disc = sqrt(disc);
		solver->sol = (-coefs[1] + disc) / (2 * coefs[0]);
		solver->inc = -disc / (2 * coefs[0]);
		if (disc > SQPREC)
		{
			solver->nsol++;
			if (coefs[0] > 0)
			{
				solver->sol += solver->inc;
				solver->inc = -solver->inc;
			}
		}
	}
}

bool	py2_next_sol(t_py2_solver *solver)
{
	solver->cursol++;
	if (solver->cursol >= solver->nsol)
		return (false);
	if (solver->cursol == 1)
		solver->sol += solver->inc;
	return (true);
}

t_float	py2_get_sol(t_py2_solver *solver)
{
	return (solver->sol);
}

bool	get_minimum_positive_py2_solution_if_exists(double coefs[3]
												, double *sol
												, double max)
{
	double ucoefs[2];

	ucoefs[0] = coefs[1] / coefs[0];
	ucoefs[1] = coefs[2] / coefs[0];
	return (get_minimum_positive_upy2_solution_if_exists(ucoefs, sol, max));
}

bool	get_minimum_positive_upy2_solution_if_exists(double ucoefs[2]
		, double *sol
		, double max)
{
	double discr;
	double cur_sol;

	discr = ucoefs[0] * ucoefs[0] - 4 * ucoefs[1];
	if (discr < 0)
		return (false);
	discr = sqrt(discr);
	cur_sol = (-ucoefs[0] - discr) / 2;
	while (1)
	{
		if (cur_sol > SQPREC && cur_sol < max)
			break ;
		cur_sol += discr;
		if (cur_sol > SQPREC && cur_sol < max)
			break ;
		return (false);
	}
	*sol = cur_sol;
	return (true);
}
