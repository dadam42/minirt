#include "minirt.h"
#include "bmpfile.h"
#include <fcntl.h>
#include <stdlib.h>

t_minirt_com	t_minirt_save_bmpfile(t_minirt_scene *scene
									, char *filename
									, t_minirt_camera *camera
									, t_minirt_resolution *resolution)
{
	t_minirt_image 		image;
	unsigned char		*bmpimage;
	t_bmpfile_init_info bmpfile_info;
	t_bmpfile			bmpfile;
	int					cur;
	t_minirt_screen_box	box;

	image = malloc(resolution->width * resolution->height * sizeof(t_minirt_color));
	if (!image)
		return (minirt_error);
	bmpimage = malloc(resolution->width * resolution->height * 3 * sizeof(unsigned char));
	if (!bmpimage)
		return (minirt_error);
	bmpfile_info.height = resolution->height;
	bmpfile_info.width = resolution->width;
	t_bmpfile_init(&bmpfile, &bmpfile_info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU) == bmpfile_error)
		return (minirt_error);
	box.ulc[minirt_height] = 0;
	box.ulc[minirt_width] = 0;
	box.brc[minirt_height] = resolution->height;
	box.brc[minirt_width] = resolution->width;
	t_minirt_camera_get_image(camera, resolution, &box, image, scene);
	cur = 0;
	while (cur < resolution->width * resolution->height)
	{
		bmpimage[3 * cur + 2]		= image[cur][0] * 256 > 255 ? 255 : image[cur][0] * 256;
		bmpimage[3 * cur + 1]	= image[cur][1] * 256 > 255 ? 255 : image[cur][1] * 256;
		bmpimage[3 * cur]	= image[cur][2] * 256 > 255 ? 255 : image[cur][2] * 256;
		cur++;
	}
	bmpfile.write(&bmpfile, bmpimage, resolution->width * resolution->height);
	bmpfile_close(&bmpfile);
	free(image);
	free(bmpimage);
	return (minirt_ok);
}

