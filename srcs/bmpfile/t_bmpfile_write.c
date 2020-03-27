#include "bmpfile_utils.h"
#include <unistd.h>

static t_bmpfile_com	write_line(t_bmpfile *bmpfile, unsigned char *content, int len)
{
	char	padder[3];

	if ((write(bmpfile->fd, content, len) != len)
		|| (write(bmpfile->fd, padder, bmpfile->padding)
			!= bmpfile->padding))
		return (bmpfile_error);
	bmpfile->wcur = 0;
	bmpfile->hcur++;
	return (bmpfile_ok);
}

t_bmpfile_com	t_bmpfile_write_with_headers(t_bmpfile *bmpfile
											, unsigned char *content
											, int len)
{
	if (bmpfile_write_headers(bmpfile) == bmpfile_ok)
		bmpfile->write = t_bmpfile_write_no_header;
	else
		return (bmpfile_error);
	return (bmpfile->write(bmpfile, content, len));
}

t_bmpfile_com	t_bmpfile_write_no_header(t_bmpfile *bmpfile
										, unsigned char *content
										, int len)
{
	int		shift;

	shift = 0;
	while (1)
	{
		if (len - shift < bmpfile->info.width - bmpfile->wcur)
		{
			if ((len - shift > 0)
				&& (write(bmpfile->fd, content + shift * bmpfile->bpp / 8
				, (len - shift) * bmpfile->bpp / 8) != (len - shift) * bmpfile->bpp / 8))
					return (bmpfile_error);
			bmpfile->wcur += len - shift;
			return (bmpfile_ok);
		}
		while (1)
		{
			if (write_line(bmpfile, content + shift * bmpfile->bpp / 8
				, (bmpfile->info.width - bmpfile->wcur) * bmpfile->bpp / 8 )
				== bmpfile_error)
				return (bmpfile_error);
			shift += bmpfile->info.width;
			if (len - shift < bmpfile->info.width)
				break;
		}
	}
}
