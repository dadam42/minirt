#ifndef BMPFILE_UTILS_H
# define BMPFILE_UTILS_H
# include "bmpfile.h"

t_bmpfile_com	t_bmpfile_write_with_headers(t_bmpfile *bmpfile, unsigned char *content, int	len);
t_bmpfile_com	t_bmpfile_write_no_header(t_bmpfile *bmpfile, unsigned char *content, int	len);
void			bmpfile_set_infoheader(t_bmpfile *bmpfile);
void			bmpfile_set_header(t_bmpfile *bmpfile);
#endif
