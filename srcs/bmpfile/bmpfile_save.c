#include "bmpfile.h"
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "d42_sys.h"

static t_bmpfile_com	write_headers(int fd, int width, int height, short padding)
{
	t_sys	sys;
	int		out;
	static unsigned char header[14] = BMPFILE_HEADER;
	static unsigned char infoheader[40] = {0};

	out = height * (3 * width + padding) + 54;
	t_sys_init(&sys);
	sys.dump_to_little_endian(&header[2], &out, 4);
	out = 54;
	sys.dump_to_little_endian(&header[10], &out, 4);
	ft_bzero(infoheader,40);
	out = 40;
	sys.dump_to_little_endian(&infoheader[0], &out, 4);
	sys.dump_to_little_endian(&infoheader[4], &width, 4);
	sys.dump_to_little_endian(&infoheader[8], &height,4);
	infoheader[12] = 1u;
	infoheader[14] = 24u;
	if (write(fd, header, 14) != 14
		|| write(fd, infoheader, 40) != 40)
		return (bmpfile_error);
	return (bmpfile_ok);
}

static t_bmpfile_com	write_content(int fd, t_bmpfile_info *info, short padding)
{
	int				ldx;
	int				cdx;
	short			cur_comp;
	unsigned char	*buffer;

	buffer = malloc(sizeof(3 * info->width + padding));
	if (!buffer)
		return (bmpfile_error);
	ldx = info->height - 1;
	while (ldx >= 0)
	{
		cdx = 0;
		while (cdx < info->width)
		{
			cur_comp = -1;
			while (++cur_comp < 3)
				buffer[3 * cdx + 2 - cur_comp] = info->content[3 *(ldx * info->width + cdx) + cur_comp];
			cdx++;
		}
		if (write(fd, buffer, 3 * info->width + padding) != 3 * info->width + padding)
			return (bmpfile_error);
		ldx--;
	}
	free(buffer);
	return (bmpfile_ok);
}

t_bmpfile_com			bmpfile_save(char *filename, t_bmpfile_info *info)
{
	int				fd;
	short			padding;
	t_bmpfile_com	ret;

	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXU);
	ret = bmpfile_error;
	while (1)
	{
		if (fd < 0)
			break ;
		padding = (4 - (3 * info->width % 4)) % 4;
		if (write_headers(fd, info->width, info->height, padding) == bmpfile_error)
			break ;
		if (write_content(fd, info, padding) == bmpfile_error)
			break ;
		ret = bmpfile_ok;
		break ;
	}
	close(fd);
	return (ret);
}
