#include "minirt.h"
#include "libft.h"

static void t_minirt_init_warn_msg(t_minirt *minirt)
{
	static char *(warn_msg[]) = 
	{
		"Direction was null, changed to negx direction relatively to canonical base.\n"
	};

	minirt->warn_msg = warn_msg;
}

static void	t_minirt_init_err_msg(t_minirt *minirt)
{
	static char *(err_msg[]) = 
	{
		"Minirt error.\n"
		, "Minirt mem error.\n"
		, "Minirt parse error.\n"
		, "Minirt wtf gnl.\n"
	};

	minirt->err_msg = err_msg;
}

void		t_minirt_init(t_minirt *minirt)
{
	static t_base		canonical = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	static t_direction	default_direction = {-1, 0, 0};

	minirt->stdoutput = 1;
	minirt->erroutput = 2;
	minirt->write_error = t_minirt_errwrite;
	minirt->write_info = t_minirt_stdwrite;
	minirt->write_warning = t_minirt_stdwrite;
	minirt->canonical = &canonical;
	minirt->default_direction = &default_direction;
	t_minirt_init_err_msg(minirt);
	t_minirt_init_warn_msg(minirt);
	t_scene_init(&minirt->scene);
}
