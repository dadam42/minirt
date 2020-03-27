#include "bmpfile.h"
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "d42_sys.h"
#include "bmpfile_utils.h"


t_bmpfile_com			bmpfile_save(char *filename, unsigned char *content
									, t_bmpfile_init_info *info)
{
	t_bmpfile_com	ret;
	t_bmpfile		bmpfile;

	ret = bmpfile_error;
	t_bmpfile_init(&bmpfile, info);
	if (bmpfile_open(&bmpfile, filename, O_WRONLY | O_CREAT, S_IRWXU) == bmpfile_error)
		return (bmpfile_error);
	ret = bmpfile.write(&bmpfile, content, info->width * info->height);
	bmpfile_close(&bmpfile);
	return (ret);
}
