#ifndef BMPFILE_H
# define BMPFILE_H
# define BMPFILE_HEADER "BM\0\0\0\0\0\0\0\0\0\0\0\0"

typedef enum e_bmpfile_com
	{
		bmpfile_ok, bmpfile_error
	}	t_bmpfile_com;

typedef unsigned char	t_bmpfile_header[14];
typedef unsigned char	t_bmpfile_infoheader[40];

typedef struct	s_bmpfile_info
{
	unsigned char			*content;
	int						height;
	int						width;
}				t_bmpfile_info;

typedef struct	s_bmpfile_spec
{
	t_bmpfile_info			info;
	t_bmpfile_header		header;
	t_bmpfile_infoheader	infoheader;
	short					padding;
}				t_bmpfile_spec;

t_bmpfile_com bmpfile_save(char *filename, t_bmpfile_info *info);
t_bmpfile_com bmpfile_load(char *filename, t_bmpfile_info *info);
#endif
