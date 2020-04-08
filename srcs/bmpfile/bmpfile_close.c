#include "bmpfile.h"
#include <unistd.h>
#include <fcntl.h>

void			bmpfile_close(t_bmpfile *bmpfile)
{
	close(bmpfile->fd);
}
