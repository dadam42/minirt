#include "utils_3d.h"
#include "libft.h"

void	t_vec3_init_by_plot3(t_plot3 a, t_plot3 b, t_vec3 r)
{
	short	cur;

	cur = 0;
	while (cur < 3)
	{
		r[cur] = b[cur] - a[cur];
		cur++;
	}
}
