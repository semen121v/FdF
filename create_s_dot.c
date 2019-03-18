/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:09:56 by fshade            #+#    #+#             */
/*   Updated: 2019/03/18 20:23:44 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot			**malloc_s_dot(int x, int y)
{
	t_dot		**matr;
	int			i;

	i = 0;
	if ((matr = (t_dot**)malloc(sizeof(t_dot *) * (y + 1))) == NULL)
		return (NULL);
	while (i < x)
	{
		if ((matr[i] = (t_dot*)malloc(sizeof(t_dot) * (y + 1))) == NULL)
			return (NULL);
		i++;
	}
	matr[i] = NULL;
	return (matr);
}
