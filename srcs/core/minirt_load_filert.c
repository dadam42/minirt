#include "minirt.h"
#include "minirt_load_filert_utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include "filert_parser.h"
#include "get_next_line.h"
#include "libft.h"

static t_minirt_com minirt_add_rtobject(t_minirt *minirt
		, t_filert_parser_com type
		, t_filert_parsed_obj *parsed)
{
	static t_minirt_rtobject_adder	adder[] = {minirt_add_rtsphere
			, minirt_add_rtcylinder, minirt_add_rtsquare
			, minirt_add_rttriangle, minirt_add_rtplane};
	t_object	*obj;

	obj = adder[type](minirt, parsed);
	if (!obj)
		return (minirt_error);
	if (minirt_check_object_integrity(minirt, obj) != minirt_ok)
		return (minirt_bad_object);
	return (scene_add_object(&minirt->scene, obj));
}

static t_minirt_com	minirt_add_dispatch(t_minirt *minirt
		, t_filert_parser_com type
		, t_filert_parsed_obj	*parsed)
{
	if (type < filert_prop_end)
		return (minirt_add_prop_from_filert(minirt
					, type - filert_prop_begin, parsed));
	if (type < filert_camera_end)
		return (minirt_add_rtcamera(minirt, parsed));
	if (type < filert_light_end)
		return (minirt_add_rtlight(minirt, parsed));
	return (minirt_add_rtobject(minirt
					, type - filert_object_begin - 1, parsed));
}

static void parse_error_special_treatment(t_minirt *minirt
		, t_filert_load_loop_state *state
		, int fd)
{
	char *itoaed;
	t_filert_error filert_error;

	t_filert_error_init(&filert_error);
	minirt_write_error(minirt, minirt_parse_error);
	minirt->write_error(minirt
	, t_filert_error_get_msg(&filert_error, state->parse_ret));
	minirt->write_error(minirt, "\nLine #");
	itoaed = ft_itoa(state->nline);
	minirt->write_error(minirt, itoaed);
	minirt->write_error(minirt, " :\n");
	free(itoaed);
	minirt->write_error(minirt, state->line);
	minirt->write_error(minirt, "\n");
	print_cursor_line(minirt, state);
	minirt->write_error(minirt, "^\n");
	free(state->line);
	close(fd);
	minirt_exit(minirt, minirt_error);
}

static void	filert_load_loop(int fd, t_minirt* minirt)
{
	t_filert_load_loop_state state;

	state.nline = 1;
	while (1)
	{
		state.gnl = get_next_line(fd, &state.line);
		if (state.gnl != gnl_continue)
		{
			if (state.gnl != gnl_eof)
				minirt_sys_fatal_error(minirt);
			break;
		}
		state.cur = state.line;
		filert_parser_ignore(&state.cur, FILERT_PARSER_IGNORE);
		if (*(state.cur) && *(state.cur) != ':')//
		{
			state.parse_ret = filert_parse(&state.cur, &state.parsed);
			if (state.parse_ret >= filert_error)
				parse_error_special_treatment(minirt, &state, fd);
			state.ret = minirt_add_dispatch(minirt
											, state.parse_ret, &state.parsed);
			if (state.ret != minirt_ok)
			{
				char *itoaed;
				itoaed = ft_itoa(state.nline);
				minirt->write_error(minirt, "Line ");
				minirt->write_error(minirt, itoaed);
				minirt->write_error(minirt, " :\n");
				free(itoaed);
				minirt_fatal_error(minirt, state.ret);
			}
		}
		state.nline++;
		free(state.line);
	}
}

void				minirt_load_filert(t_minirt *minirt, char *filename)
{
	int					fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		minirt_sys_fatal_error(minirt);
	filert_load_loop(fd, minirt);
	close(fd);
}
