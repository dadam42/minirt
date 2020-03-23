#ifndef BMPFILE_H
# define BMPFILE_H

typedef enum e_bmpfile_com
	{
		bmpfile_ok, bmpfile_error
	}	t_bmpfile_com;

typedef struct	s_bmpfile_info
{
	unsigned char	*screen;
	int				height;
	int				width;
}				t_bmpfile_info;

t_bmpfile_com bmpfile_save(char *filename, t_bmpfile_info *info);
t_bmpfile_com bmpfile_load(char *filename, t_bmpfile_info *info);
#endif
