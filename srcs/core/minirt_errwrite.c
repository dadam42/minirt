#include "minirt.h"
#include "libft.h"
#include <unistd.h>

ssize_t	minirt_errwrite(t_minirt *minirt, char* msg)
{
	return (write(minirt->erroutput, msg, ft_strlen(msg)));
}
