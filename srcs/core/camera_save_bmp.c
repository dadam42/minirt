#include "minirt.h"
#include "bmpfile.h"
#include <fcntl.h>
#include <stdlib.h>

static t_minirt_com	writing_loop(t_minirt *minirt
					, t_minirt_image i
					, t_bmpfile *file)
{
	t_minirt_screen_box	box;
	int					cur;
	t_minirt_comp		comp;

	box.ulc[minirt_height] = minirt->resolution.height - 1;
	box.ulc[minirt_width] = 0;
	box.brc[minirt_width] = minirt->resolution.width;	
	while (box.ulc[minirt_height] >= 0)
	{
		box.brc[minirt_height] = box.ulc[minirt_height];
		t_minirt_camera_get_image(minirt, &box, i);
		cur = 0;
		while (cur < minirt->resolution.width)
		{
			comp = -1;
			while (++comp <= minirt_blue)
				i.rgb[3 * cur + 2 - comp] = i.minirt[cur][comp] * 256 > 255 ?
							255 : i.minirt[cur][comp] * 256;
			cur++;
		}
		if (file->write(file, i.rgb, minirt->resolution.width) == bmpfile_error)
			return (minirt_error);
		box.ulc[minirt_height]--;
	}
	return (minirt_ok);
}

t_minirt_com	t_minirt_camera_save_bmpfile(t_minirt *minirt
									, char *filename)
{
	t_minirt_image 		image;
	t_bmpfile_init_info bmpfile_info;
	t_bmpfile			bmpfile;
	t_minirt_com		ret;

	image.minirt = malloc(minirt->resolution.width * sizeof(t_minirt_color));
	if (!image.minirt)
		return (minirt_error);
	bmpfile_info.height = minirt->resolution.height;
	bmpfile_info.width = minirt->resolution.width;
	t_bmpfile_init(&bmpfile, &bmpfile_info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)
				== bmpfile_error)
		return (minirt_error);
	ret = writing_loop(minirt, image, &bmpfile);
	bmpfile_close(&bmpfile);
	free(image.minirt);
	return (ret);
}

