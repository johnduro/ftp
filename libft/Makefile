# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 17:12:05 by mle-roy           #+#    #+#              #
#    Updated: 2014/04/28 22:32:27 by mle-roy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
VERSION=1.0.6
CFLAGS=-Wall -Werror -Wextra -g
INCLUDES=-I ./includes

SRC=free.c \
	free_large.c \
	ft_atoi.c \
	ft_atom_lst_cpy.c \
	ft_atom_lst_del.c \
	ft_atom_lst_delatom.c \
	ft_atom_lst_index.c \
	ft_atom_lst_iter.c \
	ft_atom_lst_iteratom.c \
	ft_atom_lst_new.c \
	ft_atom_lst_pop.c \
	ft_atom_lst_popend.c \
	ft_atom_lst_push.c \
	ft_atom_lst_pushend.c \
	ft_atom_new.c \
	ft_bzero.c \
	ft_chartostr.c \
	ft_exit.c \
	ft_free_all_four.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isgreater.c \
	ft_isprint.c \
	ft_issmaller.c \
	ft_isspace.c \
	ft_iswhitespace.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memdup.c \
	ft_memmove.c \
	ft_memset.c \
	ft_multistrjoin.c \
	ft_putaddr.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putnspace.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strcdup.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoinnfree.c \
	ft_strjoinwsep.c \
	ft_strjoinwsep_nfree.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strsplitspace.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tab_realloc.c \
	ft_tabfree.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c \
	malloc.c \
	realloc.c \

OBJ=$(SRC:.c=.o)

all: $(NAME) finish

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c ./includes
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v
