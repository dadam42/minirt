#include "test.h"
#include <stdio.h>
#define TPREC 1e-7

static int t_filert_float_equal(float *l, float *r)
{
	if (*r >= *l && *r - *l <= TPREC)
		return (1);
	if (*l > *r && *l - *r <= TPREC)
		return (1);
	return (0);
}

void t_filert_color_printf(t_filert_color *color)
{
	printf("%u, %u, %u", (unsigned int)(*color)[0], (unsigned int)(*color)[1], (unsigned int)(*color)[2]);
}

int	t_filert_color_equal(t_filert_color *l, t_filert_color *r)
{
	if ((*l)[0] == (*r)[0] && (*l)[1] == (*r)[1] && (*l)[2] == (*r)[2])
		return (1);
	return (0);
}

void	t_filert_pcolor_printf(t_filert_pcolor *pcolor)
{
	printf("%f ", pcolor->intensity);
	t_filert_color_printf(&pcolor->color);
}

int		t_filert_pcolor_equal(t_filert_pcolor* l , t_filert_pcolor* r)
{
	if (t_filert_color_equal(&l->color, &r->color) && t_filert_float_equal(&l->intensity, &r->intensity))
		return (1);
	return (0);
}

void	t_filert_position_printf(t_filert_position *position)
{
	printf("%f, %f, %f ", (*position)[0],(*position)[1],(*position)[2]);
}

int		t_filert_position_equal(t_filert_position* l , t_filert_position* r)
{
	if (t_filert_float_equal(&(*l)[0], &(*r)[0]) && t_filert_float_equal(&(*l)[1], &(*r)[1]) && t_filert_float_equal(&(*l)[2], &(*r)[2])) 
		return (1);
	return (0);
}

void	t_filert_direction_printf(t_filert_direction *direction)
{
	t_filert_position_printf(direction);
}

int		t_filert_direction_equal(t_filert_direction *l , t_filert_direction *r)
{
	return (t_filert_position_equal(l, r));
}
