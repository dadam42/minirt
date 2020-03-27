#include "bmpfile.h"
#include "bmpfile_utils.h"
#include <unistd.h>

t_bmpfile_com	bmpfile_write_headers(t_bmpfile *bmpfile)
{
	if (write(bmpfile->fd, bmpfile->header, 14) != 14
		|| write(bmpfile->fd, bmpfile->infoheader, 40) != 40)
		return (bmpfile_error);
	bmpfile->write = t_bmpfile_write_no_header;
	return (bmpfile_ok);
}

