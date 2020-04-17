#include "minirt.h"

void print_cursor_line(t_minirt *minirt, t_filert_load_loop_state *state)
{
	while (state->cur >= state->line)
	{
		state->cur--;
		if (*state->cur == '\t')
			minirt->write_error(minirt, "\t");
		else
			minirt->write_error(minirt, " ");
	}
}
