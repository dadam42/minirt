#ifndef SYS_H
# define SYS_H
#include <stddef.h>

typedef enum	e_sys_endianess
{
	sys_little_endian, sys_big_endian
}				t_sys_endianess;

typedef void	(*t_sys_dump)(void *, void *, size_t);

typedef	struct	s_sys
{
	t_sys_endianess	endianess;
	t_sys_dump		dump_to_little_endian;
	t_sys_dump		dump_to_big_endian;
}				t_sys;

void			t_sys_init(t_sys *sys);
t_sys_endianess	sys_get_endianess();
void			sys_preserv_endianess_dump(void *in, void *out, size_t len);
void			sys_invert_endianess_dump(void *in, void *out, size_t len);
#endif

