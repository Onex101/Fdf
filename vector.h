/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/27 06:26:02 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

typedef struct	s_vector
{
	void		**items;
	int			capacity;
	int			total;
}				t_vector;

void		vector_init(t_vector *);
int			vector_total(t_vector *);
void		vector_resize(t_vector *, int);
void		vector_add(t_vector *, void *);
void		vector_set(t_vector *, int, void *);
void		*vector_get(t_vector *, int);
void		vector_delete(t_vector *, int);
void		vector_free(t_vector *);

#endif