#include "bmpfile.h"
#include "bmpfile_utils.h"
#include "libft.h"

void	t_bmpfile_init(t_bmpfile *bmpfile, t_bmpfile_init_info *info)
{
	ft_memcpy(bmpfile, info, sizeof(t_bmpfile_init_info));
	bmpfile->padding = (4 - (3 * info->width  & 3)) & 3;
	bmpfile_set_header(bmpfile);
	bmpfile_set_infoheader(bmpfile);
	bmpfile->hcur = 0;
	bmpfile->wcur = 0;
	bmpfile->bpp = 24;
}
