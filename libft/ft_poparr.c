/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:45:55 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/29 12:46:50 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_poparr(char **s_arr, int n, char const *s, char c)
{
	char	*pnt;
	int		i;

	i = 0;
	while (i < n)
	{
		s = ft_strctrim(s, c);
		pnt = malloc(ft_strlen(ft_pull(s, c)));
		pnt = ft_pull(s, c);
		s_arr[i] = ft_strnew(ft_strlen(pnt));
		ft_strcpy(s_arr[i], pnt);
		free(pnt);
		if (!(s_arr[i]))
			return (NULL);
		while (*s && *s != c && *s != '\0')
			s++;
		i++;
	}
	s_arr[i] = NULL;
	return (s_arr);
}
