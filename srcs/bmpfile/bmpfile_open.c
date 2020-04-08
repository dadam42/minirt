#include "bmpfile.h"
#include "bmpfile_utils.h"
#include <fcntl.h>

t_bmpfile_com	bmpfile_open(t_bmpfile *bmpfile
							, char *filename
							, int flags, mode_t mode)
{
	int			fd;

	fd = open(filename, flags, mode);
	if (fd < 0)
		return (bmpfile_error);
	bmpfile->fd = fd;
	bmpfile->write = t_bmpfile_write_with_headers;
	return(bmpfile_ok);
}
