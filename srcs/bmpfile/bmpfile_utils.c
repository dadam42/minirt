#include "bmpfile_utils.h"
#include "d42_sys.h"
#include "libft.h"

static void	t_bmpfile_set_header(t_bmpfile *bmpfile, t_sys *sys)
{
	int		out;

	ft_memcpy(bmpfile->header, BMPFILE_HEADER, 14);
	out = bmpfile->info.height * (3 * bmpfile->info.width + bmpfile->padding) + 54;
	sys->dump_to_little_endian(&bmpfile->header[2], &out, 4);
	out = 54;
	sys->dump_to_little_endian(&bmpfile->header[10], &out, 4);
}

static void	t_bmpfile_set_infoheader(t_bmpfile *bmpfile, t_sys *sys)
{
	int		out;

	ft_bzero(bmpfile->infoheader,40);
	out = 40;
	sys->dump_to_little_endian(&bmpfile->infoheader[0], &out, 4);
	sys->dump_to_little_endian(&bmpfile->infoheader[4], &bmpfile->info.width, 4);
	sys->dump_to_little_endian(&bmpfile->infoheader[8], &bmpfile->info.height,4);
	bmpfile->infoheader[12] = 1u;
	sys->dump_to_little_endian(&bmpfile->infoheader[14], &bmpfile->bpp, 2);
	out = 3 * bmpfile->info.height * (bmpfile->info.width + bmpfile->padding);
	sys->dump_to_little_endian(&bmpfile->infoheader[20], &out, 4);
}

void	t_bmpfile_set_headers(t_bmpfile *bmpfile)
{
	t_sys	sys;

	t_sys_init(&sys);
	t_bmpfile_set_header(bmpfile, &sys);
	t_bmpfile_set_infoheader(bmpfile, &sys);
}
