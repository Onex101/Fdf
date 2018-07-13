/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:10:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/25 06:10:43 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fdf.h"

void	matrix_cpy(t_mat *source, t_mat *dest)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest->mat[i][j] = source->mat[i][j];
			j++;
		}
		i++;
	}
}

t_mat	*matrix_mult(t_mat *mat1, t_mat *mat2)
{
	int i;
	int j;
	t_mat *ret;

	i = 0;
	ret = (t_mat *)malloc(sizeof(t_mat));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ret->mat[i][j] = 	mat1->mat[i][0]*mat2->mat[0][j]+
						 		mat1->mat[i][1]*mat2->mat[1][j]+
						 		mat1->mat[i][2]*mat2->mat[2][j]+
						 		mat1->mat[i][3]*mat2->mat[3][j];
			j++;
		}
		i++;
	}
	return (ret);
}

t_vec3  *matrix_vec_mult(t_vec3 *source, t_mat *mat)
{
	t_vec3 *dest;

	dest = (t_vec3 *)malloc(sizeof(t_vec3));
	dest->x =	source->x * mat->mat[0][0]+
				source->y * mat->mat[1][0]+
				source->z * mat->mat[2][0]+
							mat->mat[3][0];
	dest->y =	source->x * mat->mat[0][1]+
				source->y * mat->mat[1][1]+
				source->z * mat->mat[2][1]+
							mat->mat[3][1];
	dest->z =	source->x * mat->mat[0][2]+
				source->y * mat->mat[1][2]+
				source->z * mat->mat[2][2]+
							mat->mat[3][2];
	return (dest);
}

void	matrix_identity(t_mat *mat)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat->mat[i][j] = 1;
			else
				mat->mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_mat	*matrix_translate(t_vec3 *trans)
{
	t_mat	*ret;

	ret = (t_mat *)malloc(sizeof(t_mat));
	matrix_identity(ret);
	ret->mat[3][0] = trans->x;
	ret->mat[3][1] = trans->y;
	ret->mat[3][2] = trans->z;
	return (ret);
}

t_mat	*matrix_scale(t_vec3 *scale)
{
	t_mat	*ret;

	ret = (t_mat *)malloc(sizeof(t_mat));
	matrix_identity(ret);
	ret->mat[0][0] = scale->x;
	ret->mat[1][1] = scale->y;
	ret->mat[2][2] = scale->z;
	return (ret);
}

t_mat *matrix_rotate(t_vec3 *rot)
{
	t_mat *xmat;
	t_mat *ymat;
	t_mat *zmat;
	t_mat *ret;
	t_mat *tmp;

	matrix_identity(xmat = (t_mat *)malloc(sizeof(t_mat)));
	xmat->mat[1][1] = cos(rot->x);
	xmat->mat[1][2] = sin(rot->x);
	xmat->mat[2][1] = -sin(rot->x);
	xmat->mat[2][2] = cos(rot->x);

	matrix_identity(ymat = (t_mat *)malloc(sizeof(t_mat)));
	ymat->mat[0][0] = cos(rot->y);
	ymat->mat[0][2] = -sin(rot->y);
	ymat->mat[2][0] = sin(rot->y);
	ymat->mat[2][2] = cos(rot->y);

	matrix_identity(zmat = (t_mat *)malloc(sizeof(t_mat)));
	zmat->mat[0][0] = cos(rot->z);
	zmat->mat[0][1] = sin(rot->z);
	zmat->mat[1][0] = -sin(rot->z);
	zmat->mat[1][1] = cos(rot->z);

	tmp = matrix_mult(xmat,ymat);
	ret = matrix_mult(tmp, zmat);
	free(xmat);
	free(ymat);
	free(tmp);
	free(zmat);
	return (ret);
}

t_mat *matrix_master(t_mat *scale, t_mat *trans, t_mat *rot)
{
	t_mat *ret;
	t_mat *tmp;

	tmp = matrix_mult(scale, trans);
	ret = matrix_mult(tmp, rot);
	free(tmp);
	return (ret);
}