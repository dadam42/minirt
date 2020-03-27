#include "bmpfile_utils.h"
#include "d42_sys.h"
#include "libft.h"

void			bmpfile_set_header(t_bmpfile *bmpfile)
{
	t_sys	sys;
	int		out;

	t_sys_init(&sys);
	ft_memcpy(bmpfile->header, BMPFILE_HEADER, 14);
	out = bmpfile->info.height * (3 * bmpfile->info.width + bmpfile->padding) + 54;
	t_sys_init(&sys);
	sys.dump_to_little_endian(&bmpfile->header[2], &out, 4);
	out = 54;
	sys.dump_to_little_endian(&bmpfile->header[10], &out, 4);
	ft_bzero(bmpfile->infoheader,40);
}

void			bmpfile_set_infoheader(t_bmpfile *bmpfile)
{
	t_sys	sys;
	int		out;

	out = 40;
	t_sys_init(&sys);
	sys.dump_to_little_endian(&bmpfile->infoheader[0], &out, 4);
	sys.dump_to_little_endian(&bmpfile->infoheader[4], &bmpfile->info.width, 4);
	sys.dump_to_little_endian(&bmpfile->infoheader[8], &bmpfile->info.height,4);
	bmpfile->infoheader[12] = 1u;
	sys.dump_to_little_endian(&bmpfile->infoheader[14], &bmpfile->bpp, 2);
}
