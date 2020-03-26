#include "utils_3d.h"

void	t_vec3_init_by_plots(t_plot3 a, t_plot3 b, t_vec3 r)
{
	t_vec3_smult(-1, a, r);
	t_vec3_add(r, b, r); 
}
