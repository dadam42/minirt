#include "bmpfile.h"
#include "bmpfile_utils.h"
#include "libft.h"

void	bmpfile_init(t_bmpfile *bmpfile, t_bmpfile_info *info)
{
	ft_memcpy(bmpfile, info, sizeof(t_bmpfile_info));
	bmpfile->padding = (4 - (info->width  & 3)) & 3;
	bmpfile->bpp = 24;
	t_bmpfile_set_headers(bmpfile);
	bmpfile->hcur = 0;
	bmpfile->wcur = 0;
	bmpfile->write = 0;
}
