#include "minirt.h"
#include "bmpfile.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

void	film_legacy_to_rgb(t_film *film
		, int size)
{
	int			cur;
	t_comp		comp;
	t_float		cur_comp_intensity;

	cur = 0;
	while (cur < size)
	{
		comp = -1;
		while (++comp <= blue)
		{
			cur_comp_intensity = 256 * pow(film->legacy[cur][comp], 0.45);
			film->rgb[3 * cur + 2 - comp] =
				(cur_comp_intensity > 255 ? 255 : cur_comp_intensity);
		}
		cur++;
	}
}

static t_minirt_com	bmp_writing_loop(t_minirt *minirt
		, t_image *i
		, t_bmpfile *file)
{
	t_screen		screen;
	t_screen_box	box;
	t_boxed_pixel_collection	pixel;

	box.ulc[height] = minirt->resolution.height - 1;
	box.ulc[width] = 0;
	box.brc[width] = minirt->resolution.width;
	camera_get_screen(minirt->camera, &minirt->resolution, &screen);
	while (box.ulc[height] >= 0)
	{
		box.brc[height] = box.ulc[height] + 1;
		screen_get_boxed_pixel_collection(&screen, &box, &pixel);
		boxed_pixel_collection_get_film(&pixel, minirt
				, &minirt->camera->position, &i->film);
		film_legacy_to_rgb(&i->film, minirt->resolution.width);
		if (file->write(file, i->film.rgb, minirt->resolution.width)
			== bmpfile_error)
			return (minirt_error);
		box.ulc[height]--;
	}
	return (minirt_ok);
}

static void minirt_handle_save_bmperror(t_minirt* minirt, t_minirt_com com)
{
	if (com != minirt_ok)
	{
		minirt->write_error(minirt, "When I tried to save .bmp file\n");
		minirt_sys_fatal_error(minirt);
	}
}

void	minirt_save_bmpfile(t_minirt *minirt
		, char *filename)
{
	t_image 			image;
	t_bmpfile_info 		bmpfile_info;
	t_bmpfile			bmpfile;
	t_minirt_com		com;

	image.film.legacy = malloc(minirt->resolution.width
			* sizeof(t_color));
	if (!image.film.legacy)
		minirt_sys_fatal_error(minirt);
	bmpfile_info.height = minirt->resolution.height;
	bmpfile_info.width = minirt->resolution.width;
	image.resolution.height = minirt->resolution.height;
	image.resolution.width = minirt->resolution.width;
	bmpfile_init(&bmpfile, &bmpfile_info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)
			== bmpfile_error)
		com = bmpfile_error;
	else
		com = bmp_writing_loop(minirt, &image, &bmpfile);
	bmpfile_close(&bmpfile);
	free(image.film.legacy);
	minirt_handle_save_bmperror(minirt, com);
}
