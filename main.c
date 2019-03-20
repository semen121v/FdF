/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:45:44 by fshade            #+#    #+#             */
/*   Updated: 2019/03/20 20:08:48 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

int ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}


int put_pixell2(t_param *param, t_dot ***matr, int x , int y)
{
	int		i;
	int		j;
	int		l;
	int		h;
	int 	m;

	j = 0;
	h = 50;
	m = 0;
	while (j != y * 50)
	{
		i = 0;
		l = 50;
		while (i != x)
		{
			m = j / 50;
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, l, h, matr[m][i]->color);
			i++;
			l = l + 50;
		}
		m = 0;
		j++;
		h = h + 1;
	}
	return (0);
}

int put_pixell1(t_param *param, t_dot ***matr)
{
	int		i;
	int		j;
	int		l;
	int		h;
	int 	m;
	int		x;
	int		y;


	x = param->x;
	y = param->y;
	j = 0;
	h = 0;
	m = 0;
	while (j != y )
	{
		i = 0;
		h = h + 50;
		l = 50;
		while (i != x * 50)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, i + l, h, matr[j][m]->color);
			i++;
			m = i / 50;
		}
		m = 0;
		j++;
	}
	put_pixell2(param, matr, x , y);
	return (0);
}
int key_press(int keycode, t_param *param)
{
	if (keycode == 53)
		ft_close(0);
	else if (keycode == 256)
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
	else if (keycode == 12)
		put_pixell1(param, param->matr);
	return (0);
}

int main(int ac, char **av)
{
	t_param     *param;
	t_gnl		*line;
	t_gnl		*first;
	t_dot		***matr;
	char *str = "0xffffff";
	int			x;
	int			y;
	int			fd;

	x = 0;
	if (ac == 1)
        return (0);
    if ((fd = open(av[1], O_RDONLY)) == -1)
       return (0);
	else
	{
		if ((line = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
			return (0);
		first = line;
		while ((x = get_next_line(fd, &line->line)) > 0)
		{
			if ((line->next = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
				return (0);
			line = line->next;
		}
		line->next = NULL;
		line = first;

		x = check_x(first);
		y = check_y(first);
	}
	matr = malloc_s_dot(x, y);
	matr = fulfill_matr(matr, first, x, y);

	param = (t_param*)malloc(sizeof(t_param));
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr,2000,1500,"mlx_21");
	param->x = x;
	param->y = y;
	param->matr = matr;
	put_pixell1(param, matr);
	mlx_hook(param->win_ptr, 2, 0, key_press, param);
	mlx_hook(param->win_ptr, 17, 0, ft_close, 0);
	mlx_loop(param->mlx_ptr);
	return (0);
}
