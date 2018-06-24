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

#define FOCAL_DISTANCE 200 // 80 - 200

typedef struct	s_line
{
	float x;
	float y;
}				t_line;

typedef	struct	s_vector
{
	float 		x;
	float		y;
	float 		x;
}				t_vector;

typedef struct s_vertex
{
	t_vector *local;
	t_vector *world;
	t_vector *aligned
}				t_vertex;

void	matrix_cpy(float source[4][4], float dest[4][4]);
void	matrix_mult(float mat1[4][4], float mat2[4][4], float dest[4][4]);
void	matrix_vec_mult(t_vector *source, float mat[4][4], t_vector *dest);
void	matrix_identity(float mat[4][4]);
void	matrix_translate(float mat[4][4], float tx, float ty, float tz);
void	matrix_scale(float mat1[4][4], float tx, float ty, float tz);
void	matrix_rotate(float matrix[4][4],int ax,int ay,int az);

#endif
