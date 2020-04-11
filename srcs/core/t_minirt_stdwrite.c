#include "minirt.h"
#include "libft.h"
#include <unistd.h>

ssize_t	t_minirt_stdwrite(t_minirt *minirt, char* msg)
{
	return (write(minirt->stdoutput, msg, ft_strlen(msg)));
}
