/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 08:15:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/19 06:14:42 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "vector.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef	struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_window
{
	void		*win;
	double		x_scale;
	double		y_scale;
}				t_window;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_array
{
	int			*array;
	size_t		used;
	size_t		size;
}				t_array;

typedef struct	s_line_list
{
	t_vector	*ver_vec;
	t_array		*ind_vec;
	double		max_x;
	double		max_y;
	double		max_z;
}				t_line_list;

typedef struct	s_param
{
	t_line_list *map;
	t_vec3		s;
	t_vec3		r;
	t_vec3		t;
	void		*mlx;
	void		*win;
}				t_param;

typedef struct	s_mat
{
	double		mat[4][4];
}				t_mat;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
}				t_line;

void			matrix_cpy(t_mat *source, t_mat *dest);
t_mat			*matrix_mult(t_mat *mat1, t_mat *mat2);
t_vec3			*matrix_vec_mult(t_vec3 *source, t_mat *mat);
void			matrix_identity(t_mat *mat);
t_mat			*matrix_translate(t_vec3 *trans);
t_mat			*matrix_scale(t_vec3 *scale);
t_mat			*matrix_rotate(t_vec3 *rot);
t_mat			*matrix_master(t_vec3 *s, t_vec3 *t, t_vec3 *r);

t_vec3			*new_vertex(double x, double y, double z);
t_vec3			*vertex_copy(t_vec3 *vec);
void			del_vertex(t_vec3 *vertex);

void			create_vertex_list(t_line_list *map, char *line, int y);

t_point			screen_transform(t_vec3 *v);
void			object_transform(t_param *p);
t_line_list		*t_map(t_line_list *map, t_vec3 *s, t_vec3 *r, t_vec3 *t);
void			draw_map(t_param *p, t_line_list *map);
void			draw_line(t_point *pnt1, t_point *pnt2, t_param *p);
int				draw_screen(t_param *p);

void			init_array(t_array *a, size_t size);
void			add_array(t_array *a, int element);
void			free_array(t_array *a);

t_line_list		*new_line_list(void);

t_line_list		*read_map(int fd);

int				key_hook(int keycode, t_param *p);

#endif
