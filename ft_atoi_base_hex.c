/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:29:34 by fshade            #+#    #+#             */
/*   Updated: 2019/03/18 23:10:01 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	ft_toupper_char(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		printf("AAA%c\n", c);
		c = c - 32;
		printf("AAA%c\n", c);
	}
	return (c);
}
static int		ft_check_symbols(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
				(c >= 'a' && c <= 'f'))
	{
		printf("AAA\n");
		return (1);
	}
	return (0);
}

int				ft_atoi_base(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v' || *str == 'x' || *str == '0')
		str++;
	while ((i = ft_check_symbols(*str)) == 1)
	{
		*str = ft_toupper_char(*str);
		printf("NEW=%c\n", *str);
		if (*str - 'A' >= 0)
		{
			printf("AAA\n");
			result = result * 16 + (*str - 'A' + 10);
		}
		else
		{
			printf("AAA\n");
			result = result * 16 + (*str - '0');
		}
		str++;
	}
	return (result);
}
