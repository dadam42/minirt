#ifndef UTILS_3D_H
# define UTILS_3D_H

typedef double t_vec3[3];
typedef double (*t_real_app)(double);
typedef double (*t_bireal_app)(double, double);
typedef t_vec3 t_mat3_line;
typedef t_vec3 t_mat3_col;
typedef t_mat3_line t_mat3[3];

void	t_vec3_add(t_vec3 a, t_vec3 b, t_vec3 r);
void	t_vec3_lcomb(double l, t_vec3 a, t_vec3 b, t_vec3 r);
double	t_vec3_sprod(t_vec3 a, t_vec3 b);
double	t_vec3_sqnorm(t_vec3 a);
void	t_vec3_normalize(t_vec3 a);
void	t_vec3_vprod(t_vec3 a, t_vec3 b, t_vec3 r);
void	t_vec3_mult(t_vec3 a, t_vec3 b, t_vec3 r);
void	t_vec3_smult(double l, t_vec3 a, t_vec3 r);
void	t_vec3_apply(t_vec3 a, t_real_app app, t_vec3 r);
void	t_vec3_apply2(t_vec3 a, t_vec3 b, t_bireal_app app, t_vec3 r);
void	t_mat3_copy(t_mat3 dst, t_mat3 src);
void	t_mat3_add(t_mat3 a, t_mat3 b, t_mat3 r);
void	t_mat3_lcomb(double l, t_mat3 a, t_mat3 b, t_mat3 r);
void	t_mat3_smult(double l, t_mat3 a, t_mat3 r);
void	t_mat3_prod(t_mat3 a, t_mat3 b, t_mat3 r);
double	t_mat3_det(t_mat3 a);
double	t_mat3_trace(t_mat3 a);
void	t_mat3_inv(t_mat3 a, t_mat3 r);
void	t_mat3_transpose(t_mat3 a, t_mat3 r);
#endif