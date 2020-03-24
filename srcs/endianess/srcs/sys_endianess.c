#include "d42_sys.h"

t_sys_endianess	sys_get_endianess()
{
	union {unsigned char my_int_bytes[4]; unsigned int	my_int;} tester;

	tester.my_int = 1;
	if (tester.my_int_bytes[0] == 1)
		return (sys_little_endian);
	return (sys_big_endian);	
}

void				sys_preserv_endianess_dump(void *in, void *out, size_t len)
{
	unsigned char	*ucin;
	unsigned char	*ucout;

	ucin = in;
	ucout = out;
	while (len > 0)
	{
		*ucin = *ucout;
		ucin++;
		ucout++;
		len--;
	}
}

void				sys_invert_endianess_dump(void *in, void *out, size_t len)
{
	unsigned char *ucin;
	unsigned char *ucout;

	ucin = in;
	ucout = out + len - 1;
	while (len > 0)
	{
		*ucin = *ucout;
		ucin++;
		ucout--;
		len--;
	}
}
