#ifndef BMPFILE_H
# define BMPFILE_H
# include "d42_sys.h"
# define BMPFILE_HEADER "BM\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

typedef enum e_bmpfile_com
	{
		bmpfile_ok, bmpfile_error
	}	t_bmpfile_com;

typedef unsigned char	t_bmpfile_header[14];
typedef unsigned char	t_bmpfile_infoheader[40];

typedef struct	s_bmpfile
{
	t_bmpfile_header		header;
	t_bmpfile_infoheader	infoheader
	unsigned char			*content;
	int						height;
	int						width;
	short					padding;
}				t_bmpfile;


t_bmpfile_com bmpfile_save(char *filename, t_bmpfile *info);
t_bmpfile_com bmpfile_load(char *filename, t_bmpfile *info);
#endif
