/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:38:28 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/10 19:23:14 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static int		ft_join_keep(char **line, char *buf)
{
	char	*p;
	char	*tmp;
	char	*tmp2;

	if ((p = ft_strchr(buf, '\n')))
	{
		tmp = ft_strndup(buf, (p - buf));
		tmp2 = ft_strjoin(*line, tmp);
		free(*line);
		*line = ft_strsub(tmp2, 0, ft_strlen(tmp2));
		free(tmp2);
		p++;
		ft_strcpy(buf, p);
		free(tmp);
		return (1);
	}
	else
	{
		tmp = ft_strjoin(*line, buf);
		free(*line);
		*line = ft_strsub(tmp, 0, ft_strlen(tmp));
		free(tmp);
		ft_strclr(buf);
		return (0);
	}
}

static int		ft_read_lines(int const fd, char **line, char *buf)
{
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ft_join_keep(line, buf))
			return (1);
	}
	if (ret == 0)
	{
		if (**line)
			return (1);
		return (0);
	}
	return (1);
}

static int		ft_cat_lines(char **line, char *buf)
{
	char	*p;
	char	*tmp;

	if ((p = ft_strchr(buf, '\n')))
	{
		tmp = *line;
		*line = ft_strndup(buf, (p - buf));
		p++;
		ft_strcpy(buf, p);
		free(tmp);
		return (0);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		ft_strclr(buf);
		free(tmp);
		return (1);
	}
}

int				get_next_line(int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = {0};

	if (BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(0);
	if (buf[0] != 0)
	{
		if (!ft_cat_lines(line, buf))
			return (1);
	}
	return (ft_read_lines(fd, line, buf));
}
