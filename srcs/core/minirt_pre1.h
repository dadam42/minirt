/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_pre1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 19:53:35 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/20 00:23:39 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PRE1_H
# define MINIRT_PRE1_H
# include "utils_3d.h"
# include "filert_parser.h"
# include "array_collection.h"
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# define PI 3.141592653589793
# define PREC 1e-15
# define SQPREC 1e-6
# define FOREVER	1e15

/*
** Basic typedefs for further structures.
*/
typedef double			t_float;
typedef t_vec3			t_position;
typedef t_vec3			t_direction;
typedef	t_vec3			t_translation;
typedef t_vec3			t_normal;
typedef	t_mat3			t_base;
typedef unsigned char	t_rgb_comp;
typedef t_float			t_size;
typedef t_vec3			t_intensity;
typedef	t_vec3			t_albedo;
typedef t_float			t_time;
typedef t_rgb_comp		t_pixel_color[3];
typedef t_size			t_local_coord[2];

/*
** Aliases
*/
typedef	t_intensity		t_color;
typedef t_time			t_distance;

/*
** Own minirt structures.
*/

typedef enum			e_minirt_com
{
	minirt_ok, minirt_error
	, minirt_mem_error
	, minirt_parse_error
	, minirt_bad_object
}						t_minirt_com;

typedef enum			e_minirt_warning
{
	direction_is_nul, height_is_nul, width_is_nul, size_is_nul
}						t_minirt_warning;

typedef enum			e_comp
{
	red, green, blue
}						t_comp;
#endif
