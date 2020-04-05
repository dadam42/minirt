#include "minirt.h"
#include <fcntl.h>
#include <stdlib.h>
#include "filert_parser.h"

static t_minirt_com	t_minirt_add_rtobject(t_minirt *minirt, t_filert_com type
											, t_filert_parsed_obj	*parsed)
{
	static t_minirt_rtobject_adder	adder[] = {t_minirt_add_rtresolution,
		, t_minirt_add_rtambiant_light, t_minirt_add_rtcamera
		, t_minirt_add_rtlight, t_minirt_add_rtsphere
		, t_minirt_add_rtcylinder, t_minirt_add_rtsquare
		, t_minirt_add_rttriangle, t_minirt_add_rtplane}

	if (type == filert_error)
		return (minirt_filert_error);
	return (adder[type](minirt, parsed));
}


t_minirt_com		t_minirt_load_filert(t_minirt *minirt, char *filename)
{
	char				*line;
	int					fd;
	int					gnl;
	t_filert_parsed_obj	parsed;
	t_minirt_com		ret;

	fd = open(filename, O_RDONLY);
	ret = minirt_ok;
	if (fd < 0)
		return (minirt_error);
	while (1)
	{
		gnl = get_next_line(fd, &line);
		if (gnl != gnl_ok)
		{
			if (gnl == gnl_error)
				ret = minirt_file_error;
			break;
		}
		ret = t_minirt_add_rtobject(minirt
				, filert_parse(&line, &parsed), &parsed)
		if (ret != minirt_ok)
			break;
	}
	return (ret);
}
