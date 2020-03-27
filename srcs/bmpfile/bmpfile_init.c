#include "bmpfile.h"

void	t_bmpfile_init(t_bmpfile *bmpfile, t_bmpfile_init_info *info)
{
	ft_memcpy(bmpfile, info, sizeof(t_bmpfile_init_info));
	bmpfile->padding = (4 - (3 * info->width  & 3)) & 3;
	bmpfile_set_headers(bmpfile);
	bmpfile_set_infoheader(bmpfile);
	bmpfile_init->hcur = 0;
	bmpfile_init->wcur = 0;
}
