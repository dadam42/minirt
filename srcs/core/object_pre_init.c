#include "minirt.h"
#include "libft.h"

void	object_pre_init(t_object *object
						, t_position origin
						, t_base base)
{
	ft_memcpy(object->base, base, sizeof(t_base));
	ft_memcpy(object->origin, origin, sizeof(t_position));
	object->get_albedo = 0;
	object->get_coord = 0;
	object->get_normal = 0;
}
