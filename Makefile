#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/16 15:00:18 by mle-roy           #+#    #+#              #
#    Updated: 2014/05/18 20:01:13 by mle-roy          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_Serv = serveur

NAME_Client = client

SRC_S = ft_serv.c put_get_list_serv.c cd_serv.c pwd_quit_serv.c sock_to_file.c \
		init_serv.c change.c

SRC_C = ft_client.c put_get_client.c print_cd_quit_client.c sock_to_file.c \
		client_bonus.c client_cd.c client_cmd.c client_env.c

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

FLAGS = -g3 -Wall -Wextra -Werror

all: build $(NAME_Serv) $(NAME_Client) finish

build:
	@make -C libft

$(NAME_Serv): $(OBJ_S)
	@gcc $(OBJ_S) -L libft -lft -o $(NAME_Serv)

$(NAME_Client): $(OBJ_C)
	@gcc $(OBJ_C) -L libft -lft -o $(NAME_Client)

%.o: %.c
	@gcc $(FLAGS) -c -I libft/includes $<

clean:
	@rm -f $(OBJ_S)
	@rm -f $(OBJ_C)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME_Serv)
	@rm -f $(NAME_Client)
	@make -C libft/ fclean

re: fclean all

finish:
	@(echo "[\033[32m$(NAME_Serv)\033[00m]")
	@(echo "[\033[32m$(NAME_Client)\033[00m]")

.PHONY: all build clean fclean re
