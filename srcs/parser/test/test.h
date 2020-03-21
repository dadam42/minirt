#ifndef TEST_H
# define TEST_H
# include "filert_parser.h"

void	t_filert_color_printf(t_filert_color *color);
int		t_filert_color_equal(t_filert_color*, t_filert_color*);
void	t_filert_pcolor_printf(t_filert_pcolor *pcolor);
int		t_filert_pcolor_equal(t_filert_pcolor*, t_filert_pcolor*);
void	t_filert_position_printf(t_filert_position *pos);
int		t_filert_position_equal(t_filert_position*, t_filert_position*);
void	t_filert_direction_printf(t_filert_position *pos);
int		t_filert_direction_equal(t_filert_position*, t_filert_position*);
#endif
