/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_to_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 19:29:39 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/17 20:54:18 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "serveur.h"

int					file_to_sock(int sock, int fd)
{
	struct stat		buf;
	void			*data;

	fstat(fd, &buf);
	data = mmap(0, buf.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
	send(sock, data, buf.st_size, 0);
	send(sock, END_MARK, MARK_LEN, 0);
	munmap(data, buf.st_size);
	return (0);
}

static int			check_mark(char *buf, int ret, char *mark)
{
	int		i;

	i = MARK_LEN - 1;
	while (ret >= 0 && i >= 0 && buf[ret - 1] == mark[i])
	{
		i--;
		ret--;
	}
	if (i == -1)
		return (1);
	return (0);
}

int					sock_to_file(int sock, int fd)
{
	int		flag;
	int		ret;
	char	buf[BUFF_GET + 1];

	flag = 0;
	ret = 0;
	while ((ret = recv(sock, buf, BUFF_GET, 0)))
	{
		buf[ret] = '\0';
		if (check_mark(buf, ret, END_MARK))
		{
			ret -= MARK_LEN;
			flag++;
		}
		write(fd, buf, ret);
		if (flag)
			return (0);
	}
	return (0);
}
