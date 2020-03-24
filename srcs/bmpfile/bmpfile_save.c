#include "bmpfile.h"
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

static void		dump(unsigned char *out, void* in, size_t nbyte)
{
	unsigned char *cin;

	cin = in;
	while (nbyte)
	{
		*out = *cin;
		out++;
		cin++;
		nbyte--;
	}
}

static t_bmpfile_com	write_content_wpadding(int fd, short padding
												, t_bmpfile_info *info)
{
	unsigned char	padder[9] = {0,0,0,0,0,0,0,0,0};
	int				cur_line;

	cur_line = info->height - 1;
	while (cur_line >= 0)
		{
			if ((write(fd, &(info->screen[cur_line * info->width * 3])
						, info->width * 3) != info->width * 3)
				|| (write(fd, padder, padding * 3) != padding * 3))
				return (bmpfile_error);
			cur_line--;
		}
	return (bmpfile_ok);
}

static t_bmpfile_com	write_content(int fd, t_bmpfile_info *info
										, short padding)
{
	int				cur_line;

	if (padding == 0)
	{
		cur_line = info->height - 1;
		while (cur_line >= 0)
		{
			if (write(fd, &(info->screen[cur_line * info->width * 3])
						, info->width * 3) != info->width * 3)
				return (bmpfile_error);
			cur_line--;
		}
	}
	else
		return (write_content_wpadding(fd, padding, info));
	return (bmpfile_ok);
}

t_bmpfile_com	bmpfile_save(char *filename, t_bmpfile_info *info)
{
	static unsigned char	bmpfile_header[14] = {'B', 'M', 0, 0
		, 0, 0, 0, 0, 0, 0, 54};
	static unsigned char	bmpfile_infoheader[40] = {40, 0, 0, 0
		, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
	int	tmp;
	t_bmpfile_com			ret;
	short					padding;

	padding = (4 - info->width % 4) % 4;
	tmp = 54 + 3 * info->height * (info->width + padding);
	dump(&(bmpfile_header[2]), &tmp, sizeof(tmp));
	tmp = info->width;
	dump(&(bmpfile_infoheader[4]), &tmp, sizeof(tmp));
	tmp = info->height;
	dump(&(bmpfile_infoheader[8]), &tmp, sizeof(tmp));
	tmp = open(filename, O_WRONLY|O_CREAT, S_IRWXU);
	ret = bmpfile_error;
	if (tmp > 0)
	{
		if ((write(tmp, bmpfile_header, 14) == 14)
			&& (write(tmp, bmpfile_infoheader, 40) == 40))
			ret = write_content(tmp, info, padding);
		close(tmp);
	}
	return (ret);
}
