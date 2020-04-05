#include "minirt.c"
#include "libft.h"

void	t_object_dummy_get_albedo(t_object *obj, t_object_coord *coord, t_albedo albedo)
{
	(void)coord;
	ft_memcpy(albedo, obj->albedo, sizeof(albedo));	
}
