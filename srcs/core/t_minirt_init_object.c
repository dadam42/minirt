#include "minirt.h"
#include <stdlib.h>

void			vec3_from_filert(t_vec3 minirt_vec, float filert_vec[3])
{
	char cur = 0;
	while (cur < 3)
	{
		minirt_vec[cur] = filert_vec[cur];
		cur++;
	}
}

void			t_minirt_init_object(t_minirt *minirt, t_object *object)
{
	ft_memcpy(object->base, minirt->canonical_base, sizeof(t_base));
}
