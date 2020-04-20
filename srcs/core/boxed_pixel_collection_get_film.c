/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxed_pixel_collection_get_film.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:39:01 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:39:02 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	boxed_pixel_collection_get_film(
						t_boxed_pixel_collection *collection
						, t_minirt *minirt
						, t_position *obs
						, t_film *film)
{
	t_ray					ray;

	ft_memcpy(ray.start, *obs, sizeof(t_position));
	while (1)
	{
		t_vec3_init_by_plot3(ray.start, collection->position, ray.direction);
		t_vec3_normalize(ray.direction);
		scene_get_ray_intensity(&minirt->scene, &ray
			, film->legacy[collection->cur[height]
							* (collection->max[0] - collection->min[0])
							+ collection->cur[width] - collection->min[0]]);
		if (boxed_pixel_collection_next(collection))
			continue ;
		break ;
	}
}
