#include "minirt.h"

char	*minirt_strerror(t_minirt *minirt, t_minirt_com errcode)
{
	if (errcode >= 0)
		return minirt->err_msg[errcode - minirt_error];
	return (0);
}
