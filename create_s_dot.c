/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:09:56 by fshade            #+#    #+#             */
/*   Updated: 2019/03/20 17:26:06 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot			***malloc_s_dot(int x, int y)
{
	t_dot		***matr;
	int			i;
	int			j;

	i = 0;
	if ((matr = (t_dot***)malloc(sizeof(t_dot **) * (y + 1))) == NULL)
		return (NULL);
	while (i < y)
	{
		j = 0;
		if ((matr[i] = (t_dot**)malloc(sizeof(t_dot*) * (x + 1))) == NULL)
			return (NULL);
		while (j < x)
		{
			if ((matr[i][j] = (t_dot*)malloc(sizeof(t_dot))) == NULL)
				return (NULL);
			j++;
		}
		i++;
	}
	matr[i] = NULL;
	return (matr);
}

t_dot			***fulfill_matr(t_dot ***matr, t_gnl *list, int x, int y)
{
	int		i;
	int 	j;
	char	**str;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x)
		{
			str = ft_strsplit(*list->split,',');
			matr[i][j]->z = ft_atoi_base(str[0], 10);
			if (str[1] != NULL)
				matr[i][j]->color = ft_atoi_base(str[1], 16);
			else
				matr[i][j]->color = 16777214;
			j++;
			list->split++;
		}
		list = list->next;
		j = 0;
		i++;
	}
	return (matr);
}
