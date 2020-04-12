#include "minirt.h"
#include "libft.h"
#include <math.h>

t_size	ray_init(t_ray *ray
						, t_position orig
						, t_position target)
{
		t_size	norm;

		ft_memcpy(ray->start, orig, sizeof(t_position));
		t_vec3_init_by_plot3(orig, target, ray->direction);
		norm = sqrt(t_vec3_sqnorm(ray->direction));
		t_vec3_smult(1 / norm, ray->direction, ray->direction);
		return (norm);
}
