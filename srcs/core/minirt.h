/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 19:53:24 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 01:35:41 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "minirt_pre3.h"

/*
**	t_minirt :  the minirt principal structure, open door for UIs.
*/

typedef ssize_t			(*t_minirt_write)(t_minirt*, char*);
struct					s_minirt
{
	int				stdoutput;
	int				erroutput;
	char			**err_msg;
	char			**warn_msg;
	t_minirt_write	write_error;
	t_minirt_write	write_warning;
	t_minirt_write	write_info;
	t_scene			scene;
	t_camera		*camera;
	t_resolution	resolution;
	t_base			*canonical;
	t_direction		*default_direction;
	int				default_display_width;
	int				default_display_height;
	t_color			*background_color;
	int				max_bounce;
};

void					minirt_init(t_minirt *minirt);
void					minirt_release(t_minirt *minirt);
void					minirt_sys_fatal_error(t_minirt *minirt);
void					minirt_fatal_error(t_minirt *minirt
											, t_minirt_com errcode);
char					*minirt_strerror(t_minirt *minirt
											, t_minirt_com errcode);
void					minirt_exit(t_minirt *minirt, t_minirt_com exitcode);
void					minirt_write_sys_error(t_minirt *minirt);
void					minirt_write_error(t_minirt *minirt
											, t_minirt_com errcode);
void					minirt_write_warning(t_minirt *minirt
											, t_minirt_warning wcode);
ssize_t					minirt_stdwrite(t_minirt *minirt, char *msg);
ssize_t					minirt_errwrite(t_minirt *minirt, char *msg);
void					minirt_save_bmpfile(
							t_minirt	*minirt
							, char		*filename);

typedef struct			s_filert_load_loop_state
{
	char					*line;
	char					*cur;
	int						gnl;
	int						nline;
	t_filert_parsed_obj		parsed;
	t_filert_parser_com		parse_ret;
	t_minirt_com			ret;
}						t_filert_load_loop_state;

void					minirt_load_filert(
							t_minirt	*minirt
							, char		*filename);

t_minirt_com			minirt_check_object_integrity(
												t_minirt *minirt
												, t_object *object);
/*
**	t_minirt's functions
*/

/*
**	Pluggging in filertparser
*/

typedef t_object		*(*t_minirt_rtobject_adder)(
							t_minirt*
							, t_filert_parsed_obj*);

t_minirt_com			minirt_add_prop_from_filert(
							t_minirt	*minirt
							, t_filert_parser_com type
							, t_filert_parsed_obj	*parsed);
t_minirt_com			minirt_add_rtresolution(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com			minirt_add_rtambiant_light(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com			minirt_add_rtcamera(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_minirt_com			minirt_add_rtlight(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_object				*minirt_add_rtsphere(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
void					vec3_from_filert(t_vec3 minirt_vec
							, float filert_vec[3]);
void					color_from_filert(
							t_color		color
							, t_filert_color	rtcolor);
void					pcolor_from_filert(
							t_color		*color
							, t_filert_pcolor	*rtpcolor);
void					direction_from_filert(t_minirt *minirt
							, t_direction	dir
							, t_filert_direction	rtdir);
t_object				*minirt_add_rtcylinder(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_object				*minirt_add_rtsquare(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_object				*minirt_add_rttriangle(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);
t_object				*minirt_add_rtplane(
							t_minirt				*minirt
							, t_filert_parsed_obj	*parsed);

void					get_flipped_direction(t_vec3 dir
											, t_vec3 normal
											, t_vec3 flipped);

/*
** Struct solvers
*/

typedef struct			s_py2_solver
{
	t_float			sol;
	t_float			inc;
	char			nsol;
	char			cursol;
}						t_py2_solver;

void					py2_solver_init(t_py2_solver *solver
										, t_float coefs[3]);
bool					py2_next_sol(t_py2_solver *solver);
t_float					py2_get_sol(t_py2_solver *solver);
bool					get_minimum_positive_upy2_solution_if_exists(
													double ucoefs[2]
													, double *sol
													, double max);
bool					get_minimum_positive_py2_solution_if_exists(
													double coefs[3]
													, double *sol
													, double max);
#endif
