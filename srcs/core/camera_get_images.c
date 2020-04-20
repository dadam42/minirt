/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_get_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:40:03 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:40:04 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_get_boxed_image(t_camera *camera,
										t_scene *scene,
										t_image *image,
										t_screen_box *box)
{
	t_screen					screen;
	t_boxed_pixel_collection	pixel;

	(void)scene;
	camera_get_screen(camera, &image->resolution, &screen);
	screen_get_boxed_pixel_collection(&screen, box, &pixel);
}

void	camera_get_image(t_camera *camera,
									t_scene *scene,
									t_image *image)
{
	t_screen_box box;

	box.ulc[width] = 0;
	box.ulc[height] = 0;
	box.brc[width] = image->resolution.width;
	box.brc[height] = image->resolution.height;
	camera_get_boxed_image(camera, scene, image, &box);
}
