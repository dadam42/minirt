#include "minirt.h"
#include "libft.h"

void	object_dummy_get_albedo(t_object *obj, t_object_coord *coord, t_albedo albedo)
{
	(void)coord;
	ft_memcpy(albedo, obj->albedo, sizeof(t_albedo));	
}
