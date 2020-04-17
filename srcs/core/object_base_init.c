#include "minirt.h"
#include "libft.h"

bool	object_base_init(t_object *object, t_direction normal, t_base canonical)
{
	unsigned char	cur;
	t_float			candidate_sqnorm;

	ft_memcpy(object->base[2], normal, sizeof(t_direction));
	cur = 0;
	while (cur < 3)
	{
		t_vec3_vprod(canonical[cur], normal, object->base[1]);
		candidate_sqnorm = t_vec3_sqnorm(object->base[1]);
		if (candidate_sqnorm > PREC)
			break;
		cur++;
	}
	if (cur == 3)
		return (false);
	t_vec3_vprod(object->base[1], object->base[2], object->base[0]);
	return (true);
}
