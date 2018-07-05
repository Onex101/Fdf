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
#include "vector.h"

#define FOCAL_DISTANCE 200
#define WIDTH 500
#define HEIGHT 500
#define NAME "fdf"

typedef	struct	s_vec3
{
	double 		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_window
{
	void		*win;
	double		x_factor;
	double		y_factor;
}				t_window;

typedef struct		s_line
{
	double 		x1;
	double		y1;
	double 		x2;
	double		y2;
}					t_line;

typedef struct	s_line_list
{
	t_vector *ver_vec;
	t_vector *ind_vec;
} 				t_line_list;


void		matrix_cpy(double source[4][4], double dest[4][4]);
void		matrix_mult(double mat1[4][4], double mat2[4][4], double dest[4][4]);
void		matrix_vec_mult(t_vec3 *source, double mat[4][4], t_vec3 *dest);
void		matrix_identity(double mat[4][4]);
void		matrix_translate(double mat[4][4], double tx, double ty, double tz);
void		matrix_scale(double mat1[4][4], double tx, double ty, double tz);
void		matrix_rotate(double matrix[4][4],int ax,int ay,int az);

void		new_vertex(double x, double y, double z);
void		del_vertex(t_vec3 *vertex);

void		*get_mlx(void);
void		*get_window(char *title);

void		draw_grid(t_vec3	**ver_arr);
void		draw_line(t_line *line);

t_line_list	*new_line_list(void);


#endif