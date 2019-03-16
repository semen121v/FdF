/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serch_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:21:06 by fshade            #+#    #+#             */
/*   Updated: 2019/03/16 21:24:52 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

const int		count_x(t_gnl *str)
{
	int		i;
	char	**str1;

	str1 = ft_strsplit(str->line, ' ');
	str->split = str1;
	while (*str1 != '\0')
	{
		str1++;
		i++;
	}
	return (i);
}

int     check_x(t_gnl *fd)
{
	int     i;
	int     j;

	i = 0;
	if ((i = count_x(fd)) == 0)
		return (0);
	j = 0;
	printf("i = %d\n", i);
	while (fd->next != NULL)
	{
		if ((j = count_x(fd)) == 0)
			return (0);
		printf("j = %d\n", j);
		if (i != j)
			return (0);
		fd = fd->next;
	}
	return (i);
}



int     check_y(t_gnl *fd)
{
	int i;

	i = 0;
	while (fd->next != NULL)
	{
		i++;
		fd = fd->next;
	}
	return (i);
}
