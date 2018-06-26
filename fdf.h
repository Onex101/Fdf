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

#define FOCAL_DISTANCE 200

typedef struct		s_vlst
{
	struct t_vertex	*vertex;
 	int				index;
}					t_vlst;

typedef	struct	s_vector
{
	double 		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
}				t_window;

typedef struct	s_line
{
	struct t_vector	*vec1;
	struct t_vector	*vec2;
	struct t_window	*window;
}					t_line;

typedef struct		s_vertex
{
	struct t_vector	*orignal;
	struct t_vector	*screen;
	struct t_vector	*aligned;
}					t_vertex;

void		matrix_cpy(double source[4][4], double dest[4][4]);
void		matrix_mult(double mat1[4][4], double mat2[4][4], double dest[4][4]);
void		matrix_vec_mult(t_vector *source, double mat[4][4], t_vector *dest);
void		matrix_identity(double mat[4][4]);
void		matrix_translate(double mat[4][4], double tx, double ty, double tz);
void		matrix_scale(double mat1[4][4], double tx, double ty, double tz);
void		matrix_rotate(double matrix[4][4],int ax,int ay,int az);

// t_arrlst	*ft_alstnew(char **content, size_t i);
// void		ft_arrlst_addend(t_arrlst **alst, t_arrlst *new);

#endif
