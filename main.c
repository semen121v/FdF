/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:45:44 by fshade            #+#    #+#             */
/*   Updated: 2019/03/16 20:29:51 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct      s_param
{
		void    *mlx_ptr;
		void    *win_ptr;
		int     x;
		int     y;
}                   t_param;

// int ft_close(void *param)
// {
// 	(void)param;
// 	exit(0);
// 	return (0);
// }

// int key_press(int keycode, t_param *param)
// {
// 	if (keycode == 53)
// 		ft_close(0);
// 	else if (keycode == 256)
// 		mlx_clear_window(param->mlx_ptr, param->win_ptr);
// 	return (0);
// }

// int put_pixell1(int button, int x, int y, t_param *param)
// {
// 	param->x = x;
// 	param->y = y;
// 	//mlx_hook(param->win_ptr, 5, 0, put_pixell2, param);
// 	return (0);
// }

int main(int ac, char **av)
{
	//t_param     *param;
	t_gnl		*line;
	t_gnl		*first;
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
		while((x  = get_next_line( fd , &line->line)) > 0)
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
	while (line->next != NULL)
	{
		printf ("%s\n", line->line);
		line = line->next;
	}
	printf("%d%d\n", x, y);

	// param = (t_param*)malloc(sizeof(t_param));
	// param->mlx_ptr = mlx_init();
	// param->win_ptr = mlx_new_window(param->mlx_ptr,1000,1000,"mlx_21");
	// mlx_hook(param->win_ptr, 4, 0, put_pixell1, param);
	// mlx_hook(param->win_ptr, 2, 0, key_press, param);
	// mlx_hook(param->win_ptr, 17, 0, ft_close, 0);
	// mlx_loop(param->mlx_ptr);
	return (0);
}
