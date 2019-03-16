/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:28:52 by fshade            #+#    #+#             */
/*   Updated: 2019/03/16 21:21:50 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# define BUFF_SIZE 128
# define MAX  5

// typedef struct		s_param
// {
// 	void			*mlx_ptr;
// 	void			*win_ptr;
// }					t_param;

// typedef struct		s_dot
// {
// 	int				z;
// 	char			*color;
// }					t_dot;

typedef struct		s_gnl
{
	char			**split;
	char			*line;
	struct s_gnl	*next;
}					t_gnl;

int get_next_line(const int fd, char **line);
int     check_y(t_gnl *fd);
int     check_x(t_gnl *fd);

#endif