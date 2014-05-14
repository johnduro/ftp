/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:34:02 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/14 18:18:14 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# define USAGE "Usage: ./server <port>\n"
# define BUFF_LEN 1024

typedef struct			s_cnx
{
	char				code[3];
	char				str[512];
	void				*data;
}						t_cnx;

typedef struct			s_serv
{
	int					sock;
	char				*pwd;
	char				*root;
}						t_serv;

#endif
