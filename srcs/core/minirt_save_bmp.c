#include "minirt.h"
#include "bmpfile.h"
#include <fcntl.h>
#include <stdlib.h>

void	t_minirt_film_legacy_to_rgb(t_minirt_film *film
									, int size)
{
		int					cur;
		t_minirt_comp		comp;
		t_minirt_intensity	cur_intensity;

		cur = 0;
		while (cur < size)
		{
			comp = -1;
			while (++comp <= minirt_blue)
			{
				cur_intensity = 256 * film->legacy[cur][comp];
				film->rgb[3 * cur + 2 - comp] =
					(cur_intensity > 255 ? 255 : cur_intensity);
			}
			cur++;
		}
}

static t_minirt_com	bmp_writing_loop(t_minirt_camera *camera
					, t_minirt_scene *scene
					, t_minirt_image *i
					, t_bmpfile *file)
{
	t_minirt_screen		screen;
	t_minirt_screen_box	box;
	t_minirt_boxed_pixel_collection	pixel;

	box.ulc[height] = i->resolution.height - 1;
	box.ulc[width] = 0;
	box.brc[width] = i->resolution.width;
	t_minirt_camera_get_screen(camera, &i->resolution, &screen);
	while (box.ulc[height] >= 0)
	{
		box.brc[height] = box.ulc[height] + 1;
		t_minirt_screen_get_boxed_pixel_collection(&screen, &box, &pixel);
		t_minirt_boxed_pixel_collection_get_film(&pixel, scene
		, &camera->position, &i->film);
		t_minirt_film_legacy_to_rgb(&i->film, i->resolution.width);
		if (file->write(file, i->film.rgb, i->resolution.width) == bmpfile_error)
			return (minirt_error);
		box.ulc[height]--;
	}
	return (minirt_ok);
}

t_minirt_com	t_minirt_save_bmpfile(t_minirt *minirt
									, char *filename)
{
	t_minirt_image 		image;
	t_bmpfile_init_info bmpfile_info;
	t_bmpfile			bmpfile;
	t_minirt_com		ret;

	image.film.legacy = malloc(minirt->resolution.width
								* sizeof(t_minirt_color));
	if (!image.film.legacy)
		return (minirt_error);
	image.resolution.width = minirt->resolution.width;
	image.resolution.height = minirt->resolution.height;
	bmpfile_info.height = minirt->resolution.height;
	bmpfile_info.width = minirt->resolution.width;
	t_bmpfile_init(&bmpfile, &bmpfile_info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)
				== bmpfile_error)
		ret = bmpfile_error;
	else
		ret = bmp_writing_loop(minirt->camera, &minirt->scene, &image, &bmpfile);
	bmpfile_close(&bmpfile);
	free(image.film.legacy);
	return (ret);
}

