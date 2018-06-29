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

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "./libft/includes/libft.h"

#define FOCAL_DISTANCE 200
#define WIDTH 500
#define HEIGHT 500

typedef	struct	s_vector
{
	double 		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_window
{
	void		*win;
	double		x_factor;
	double		y_factor;
}				t_window;

typedef struct		s_line
{
	t_vector	*vec1;
	t_vector	*vec2;
	struct t_window	*window;
}					t_line;

typedef struct		s_vertex
{
	t_vector	*original;
	t_vector	*screen;
	t_vector	*aligned;
}					t_vertex;

void		matrix_cpy(double source[4][4], double dest[4][4]);
void		matrix_mult(double mat1[4][4], double mat2[4][4], double dest[4][4]);
void		matrix_vec_mult(t_vector *source, double mat[4][4], t_vector *dest);
void		matrix_identity(double mat[4][4]);
void		matrix_translate(double mat[4][4], double tx, double ty, double tz);
void		matrix_scale(double mat1[4][4], double tx, double ty, double tz);
void		matrix_rotate(double matrix[4][4],int ax,int ay,int az);

void		orgin_factor(t_vector *vector);

void		new_vector(t_vector **vector, double x, double y, double z);
t_vertex	new_vertex(double x, double y, double z);
void		del_vector(t_vector *vector);
void		del_vertex(t_vertex *vertex);

void		draw_line(t_vector *vec1, t_vector *vec2);

//t_window	new_window(char *title);
void		*get_mlx(void);
void		*get_window(char *title);

void		draw_grid(t_vertex	**ver_arr, int row, int col);

#endif
