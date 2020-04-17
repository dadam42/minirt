#include "utils_3d.h"

void	get_flipped_direction(t_vec3 dir, t_vec3 normal, t_vec3 flipped)
{
	t_vec3_smult(-1, dir, flipped);
	t_vec3_lcomb(2 * t_vec3_sprod(normal, dir),  normal, flipped, flipped);
}
