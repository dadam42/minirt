#include "minirt.h"
#include "bmpfile.h"
#include <fcntl.h>
#include <stdlib.h>

static t_minirt_com	writing_loop(t_minirt_camera *camera
					, t_minirt_resolution *resolution
					, t_minirt_scene *scene
					, t_minirt_image im
					, t_bmpfile *bmpfile)
{
	t_minirt_screen_box	box;
	int					cur;
	t_minirt_comp		comp;

	box.ulc[minirt_height] = resolution->height - 1;
	box.ulc[minirt_width] = 0;
	box.brc[minirt_width] = resolution->width;	
	while (box.ulc[minirt_height] >= 0)
	{
		box.brc[minirt_height] = box.ulc[minirt_height];
		t_minirt_camera_get_image(camera, resolution, &box, im, scene);
		cur = 0;
		while (cur < resolution->width)
		{
			comp = -1;
			while (++comp <= minirt_blue)
				im.rgb[3 * cur + 2 - comp] = im.minirt[cur][comp] * 256 > 255 ?
							255 : im.minirt[cur][comp] * 256;
			cur++;
		}
		if (bmpfile->write(bmpfile, im.rgb, resolution->width) == bmpfile_error)
			return (minirt_error);
		box.ulc[minirt_height]--;
	}
	return (minirt_ok);
}

t_minirt_com	t_minirt_camera_save_bmpfile(t_minirt_camera *camera
									, char *filename
									, t_minirt_scene *scene
									, t_minirt_resolution *resolution)
{
	t_minirt_image 		image;
	t_bmpfile_init_info bmpfile_info;
	t_bmpfile			bmpfile;
	t_minirt_com		ret;

	image.minirt = malloc(resolution->width * sizeof(t_minirt_color));
	if (!image.minirt)
		return (minirt_error);
	bmpfile_info.height = resolution->height;
	bmpfile_info.width = resolution->width;
	t_bmpfile_init(&bmpfile, &bmpfile_info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU) == bmpfile_error)
		return (minirt_error);
	ret = writing_loop(camera, resolution, scene, image, &bmpfile);
	bmpfile_close(&bmpfile);
	free(image.minirt);
	return (ret);
}

