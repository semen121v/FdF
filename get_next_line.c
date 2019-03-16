/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:10:04 by fshade            #+#    #+#             */
/*   Updated: 2019/03/15 20:39:33 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_line(int ret, char **str, char *str1, char **line)
{
	if (ret == -1)
		return (-1);
	if (str1 && *str1)
	{
		if ((*str = ft_strchr(str1, '\n')) != NULL)
		{
			*line = ft_strsub(str1, 0, *str - str1);
			*str = ft_strdup(*str + 1);
		}
		else
			*line = ft_strdup(str1);
		ft_strdel(&str1);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str[MAX];
	char		*str1;

	if (fd >= MAX || fd < 0 || !line)
		return (-1);
	str1 = str[fd];
	if (!str[fd])
		str[fd] = ft_memalloc(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str1 = ft_strjoin(str[fd], buf);
		ft_strdel(&str[fd]);
		if (ft_strchr(str1, '\n') != NULL)
			break ;
		else
			str[fd] = str1;
	}
	return (ft_line(ret, &str[fd], str1, line));
}
