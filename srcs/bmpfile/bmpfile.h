#ifndef BMPFILE_H
# define BMPFILE_H
# define BMPFILE_HEADER "BM\0\0\0\0\0\0\0\0\0\0\0\0"
# define BMPFILE_BYPP 3
# include <sys/stat.h>
# include <stddef.h>

typedef enum e_bmpfile_com
{
	bmpfile_ok, bmpfile_error
}	t_bmpfile_com;

typedef unsigned char	t_bmpfile_header[14];
typedef unsigned char	t_bmpfile_infoheader[40];

typedef struct	s_bmpfile_info
{
	int						height;
	int						width;
}				t_bmpfile_info;

typedef struct	s_bmpfile
				t_bmpfile;

typedef t_bmpfile_com	
				(*t_bmpfile_write)(t_bmpfile *bmpfile, unsigned char *content
				, int len);
//bpp stands for bit_per_pixel
struct			s_bmpfile
{
	t_bmpfile_info			info;
	short					bpp;
	int						fd;
	short					padding;
	unsigned char			padder[3];
	t_bmpfile_header		header;
	t_bmpfile_infoheader	infoheader;
	t_bmpfile_write			write;
	int						wcur;
	int						hcur;
};

void			bmpfile_init(t_bmpfile *bmpfile, t_bmpfile_info *info);
t_bmpfile_com	bmpfile_open(t_bmpfile *bmpfile, char	*filename, int flags
								, mode_t mode);
void			bmpfile_close(t_bmpfile *file);
t_bmpfile_com	save_bmpfile(char *filename, unsigned char *content
							, t_bmpfile_info *info);
#endif
