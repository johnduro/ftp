/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:34:02 by mle-roy           #+#    #+#             */
/*   Updated: 2014/05/18 20:20:33 by mle-roy          ###   ########.fr       */
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
** CD
*/

# define CD_OK "SUCCESS changing directory"
# define CD_FAIL "ERROR changing directory"

/*
** GET
*/

# define GET_OK "204 GET"
# define GET_FAIL "504 GET"

typedef struct			s_serv
{
	int					sock;
	char				*pwd;
	char				*root;
}						t_serv;

typedef struct			s_env
{
	char				*home;
	char				*pwd;
	char				*old;
}						t_env;

int						sock_to_file(int sock, int fd);
int						file_to_sock(int sock, int fd);
int						put_client(int sock, char *cmd);
int						get_client(int sock, char *cmd);
int						get_list(int sock, char *cmd);
int						client_error(int code);
int						serv_error(int code);
int						print_path(int sock, char *cmd);
int						quit_client(int sock, char *cmd);
int						change_dir(int sock, char *cmd);
void					print_client(char *addr, char *port);
int						put_file(t_serv *serv, char *cmd);
int						get_file(t_serv *serv, char *cmd);
int						rep_list(t_serv *serv, char *cmd);
int						change_dir_serv(t_serv *serv, char *cmd);
int						print_path_serv(t_serv *serv, char *cmd);
int						quit_serv(t_serv *serv, char *cmd, int id);
t_serv					*init_serv(int port);
int						send_cmd_bonus(char *cmd, int sock, t_env *env);
t_env					*ft_create_env(char **env);
void					client_ls(char *cmd);
void					client_cd(char *cmd, t_env *env);
void					client_pwd(t_env *env);
int						mget_client(int sock, char *cmd);
int						mput_client(int sock, char *cmd);
void					ft_get_file(char *file, int sock);
int						change_arg_get(char **arg, t_serv *serv);
void					change_arg_ls(char **arg, t_serv *serv);

#endif
