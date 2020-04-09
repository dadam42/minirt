#include "bmpfile_utils.h"
#include <unistd.h>
#define BPP 3

t_bmpfile_com	t_bmpfile_write_with_headers(t_bmpfile *bmpfile
											, unsigned char *content
											, int len)
{
	if (t_bmpfile_write_headers(bmpfile) == bmpfile_ok)
		bmpfile->write = t_bmpfile_write_no_header;
	else
		return (bmpfile_error);
	return (bmpfile->write(bmpfile, content, len));
}

static t_bmpfile_com	write_line(t_bmpfile *bmpfile
						, unsigned char **content, int *len)
{
	int		nout;

	nout = bmpfile->info.width - bmpfile->wcur;
	if ((write(bmpfile->fd, *content, nout * BPP) != nout * BPP)
		|| (write(bmpfile->fd, bmpfile->padder, bmpfile->padding)
			!= bmpfile->padding))
		return (bmpfile_error);
	*content += BPP * (bmpfile->info.width - bmpfile->wcur);
	*len -= bmpfile->info.width - bmpfile->wcur;
	bmpfile->hcur++;
	return (bmpfile_ok);
}

t_bmpfile_com	t_bmpfile_write_no_header(t_bmpfile *bmpfile
										, unsigned char *content
										, int len)
{
	t_bmpfile_com	ret;

	while (1)
	{
		if (len < bmpfile->info.width - bmpfile->wcur)
		{
			if (len > 0)
			{
				if (write(bmpfile->fd, content, len * BPP) != len * BPP)
					return (bmpfile_error);
				bmpfile->wcur += len;
			}
			return (bmpfile_ok);
		}
		while (1)
		{
			ret = write_line(bmpfile, &content, &len); 
			if (ret != bmpfile_ok)
				return (ret);
			if (len < bmpfile->info.width - bmpfile->wcur)
				break;
		}
	}
}
