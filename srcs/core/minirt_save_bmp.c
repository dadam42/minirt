#include "minirt.h"
#include "bmpfile.h"
#include <fcntl.h>
#include <stdlib.h>

void	t_film_legacy_to_rgb(t_film *film
									, int size)
{
		int					cur;
		t_comp		comp;
		t_intensity	cur_intensity;

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

static t_com	bmp_writing_loop(t_minirt *minirt
					, t_image *i
					, t_bmpfile *file)
{
	t_screen		screen;
	t_screen_box	box;
	t_boxed_pixel_collection	pixel;

	box.ulc[height] = minirt->resolution.height - 1;
	box.ulc[width] = 0;
	box.brc[width] = minirt->resolution.width;
	t_camera_get_screen(camera, &minirt->resolution, &screen);
	while (box.ulc[height] >= 0)
	{
		box.brc[height] = box.ulc[height] + 1;
		t_screen_get_boxed_pixel_collection(&screen, &box, &pixel);
		t_boxed_pixel_collection_get_film(&pixel, minirt
		, &camera->position, &i->film);
		t_film_legacy_to_rgb(&i->film, minirt->resolution.width);
		if (file->write(file, i->film.rgb, minirt->resolution.width) == bmpfile_error)
			return (minirt_error);
		box.ulc[height]--;
	}
	return (minirt_ok);
}

t_com	t_save_bmpfile(t_minirt *minirt
									, char *filename)
{
	t_image 		image;
	t_bmpfile_init_info bmpfile_info;
	t_bmpfile			bmpfile;
	t_com		ret;

	image.film.legacy = malloc(minirt->resolution.width
								* sizeof(t_color));
	if (!image.film.legacy)
		return (minirt_error);
	bmpfile_info.height = minirt->resolution.height;
	bmpfile_info.width = minirt->resolution.width;
	t_bmpfile_init(&bmpfile, &bmpfile_info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)
				== bmpfile_error)
		ret = bmpfile_error;
	else
		ret = bmp_writing_loop(minirt, &image, &bmpfile);
	bmpfile_close(&bmpfile);
	free(image.film.legacy);
	return (ret);
}

