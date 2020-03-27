#include "bmpfile.h"
#include "bmpfile_utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

t_bmpfile_com	bmpfile_open(t_bmpfile *bmpfile, char *filename, int flags, mode_t mode)
{
	int			fd;

	fd = open(filename, flags, mode);
	if (fd < 0)
		return (0);
	bmpfile->fd = fd;
	bmpfile_set_header(bmpfile);
	bmpfile_set_infoheader(bmpfile);
	bmpfile->write = t_bmpfile_write_with_headers;
	return(bmpfile_ok);
}

void			bmpfile_close(t_bmpfile *bmpfile)
{
	close(bmpfile->fd);
}
