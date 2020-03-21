#include "test.h"
#include <stdio.h>

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
	if (t_filert_color_equal(&l->color, &r->color) && l->intensity == r->intensity)
		return (1);
	return (0);
}
