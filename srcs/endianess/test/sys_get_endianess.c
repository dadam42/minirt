#include <stdio.h>
#include "d42_sys.h"

void print_endianess(t_sys_endianess endianess)
{
	switch(endianess)
	{
		case sys_little_endian:
			printf("little endian");
			break ;
		default:
			printf("big endian");
			break;
	}
}

int main()
{
	print_endianess(sys_get_endianess());
	return (0);
}
