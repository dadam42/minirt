/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <dadamouyal42@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 18:45:25 by damouyal          #+#    #+#             */
/*   Updated: 2020/04/19 18:55:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_3D_H
# define UTILS_3D_H
# define PREC 1e-15

typedef double		t_vec3[3];
typedef double		(*t_real_app)(double);
typedef double		(*t_bireal_app)(double, double);
typedef t_vec3		t_plot3;
typedef t_vec3		t_mat3_line;
typedef t_vec3		t_mat3_col;
typedef t_mat3_line	t_mat3[3];

void				t_vec3_init_by_plot3(t_plot3 a, t_plot3 b, t_vec3 r);
void				t_vec3_copy(t_vec3	dst, t_vec3 src);
void				t_vec3_add(t_vec3 a, t_vec3 b, t_vec3 r);
void				t_vec3_lcomb(double l, t_vec3 a, t_vec3 b, t_vec3 r);
double				t_vec3_sprod(t_vec3 a, t_vec3 b);
double				t_vec3_sqnorm(t_vec3 a);
double				t_vec3_normalize(t_vec3 a);
void				t_vec3_vprod(t_vec3 a, t_vec3 b, t_vec3 r);
void				t_vec3_mult(t_vec3 a, t_vec3 b, t_vec3 r);
void				t_vec3_smult(double l, t_vec3 a, t_vec3 r);
void				t_vec3_apply(t_vec3 a, t_real_app app, t_vec3 r);
void				t_vec3_apply2(t_vec3 a, t_vec3 b, t_bireal_app app
									, t_vec3 r);
void				t_mat3_copy(t_mat3 dst, t_mat3 src);
void				t_mat3_add(t_mat3 a, t_mat3 b, t_mat3 r);
void				t_mat3_lcomb(double l, t_mat3 a, t_mat3 b, t_mat3 r);
void				t_mat3_smult(double l, t_mat3 a, t_mat3 r);
void				t_mat3_prod(t_mat3 a, t_mat3 b, t_mat3 r);
double				t_mat3_det(t_mat3 a);
double				t_mat3_trace(t_mat3 a);
void				t_mat3_inv(t_mat3 a, t_mat3 r);
void				t_mat3_transpose(t_mat3 a, t_mat3 r);
void				t_mat3_apply_vec3(t_mat3 a, t_vec3 v, t_vec3 r);
void				t_mat3_dapply_vec3(t_vec3 tv, t_mat3 a, t_vec3 r);
void				rotation_matrix(t_vec3 axis, double angle, t_mat3 rot);
#endif
