/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:34:02 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/17 21:07:47 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# define USAGE "Usage: ./server <port>\n"
# define BUFF_LEN 1024
# define BUFF_GET 5000

# define END_MARK " 4 2 "
# define MARK_LEN 5

/*
** LS
*/

# define LS_RET "201 LIST"
# define LS_FAIL "501 LIST"

/*
** CD
*/

# define CD_OK "SUCCESS changing directory"
# define CD_FAIL "ERROR changing directory"

/*
** PWD
*/

# define PWD_RET "203 PWD"
# define PWD_FAIL "503 PWD"

/*
** GET
*/

# define GET_TMP "102 GET"
# define GET_OK "204 GET"
# define GET_FAIL "504 GET"

/*
** PUT
*/

# define PUT_TMP "102 PUT"
# define PUT_OK "205 PUT"
# define PUT_FAIL "505 PUT"

typedef struct			s_serv
{
	int					sock;
	char				*pwd;
	char				*root;
}						t_serv;

int						sock_to_file(int sock, int fd);
int						file_to_sock(int sock, int fd);

#endif
