#include "minirt.h"
#include "libft.h"
#include <math.h>

t_minirt_size	t_minirt_ray_init(t_minirt_ray *ray
						, t_minirt_position orig
						, t_minirt_position target)
{
		t_minirt_size	norm;

		ft_memcpy(ray->start, orig, sizeof(t_minirt_position));
		t_vec3_init_by_plot3(orig, target, ray->direction);
		norm = sqrt(t_vec3_sqnorm(ray->direction));
		t_vec3_smult(1 / norm, ray->direction, ray->direction);
		return (norm);
}
