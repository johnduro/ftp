/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:21:27 by mle-roy           #+#    #+#             */
/*   Updated: 2014/04/28 22:35:40 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "struct_lib.h"

t_atom	*ft_atom_new(void const *content, size_t size);
t_atom	*ft_atom_lst_pop(t_lst *list);
t_atom	*ft_atom_lst_popend(t_lst *list);
t_lst	*ft_atom_lst_new(t_atom *new_atom);
t_lst	*ft_atom_lst_cpy(t_lst *lst);
int		ft_atom_lst_index(t_lst *list, t_atom *atom);
void	ft_atom_lst_iter(t_lst *list, void (*f)(void *content));
void	ft_atom_lst_iteratom(t_lst *list, void (*f)(t_atom *atom));
void	ft_atom_lst_delatom(t_lst *l, t_atom *atom, void (*del)(void *content));
void	ft_atom_lst_del(t_lst *list, void (*del)(void *content));
void	ft_atom_lst_push(t_lst *list, t_atom *new);
void	ft_atom_lst_pushend(t_lst *list, t_atom *new);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinwsep(char const *s1, char const *s2, char c);
char	*ft_strjoinwsep_nfree(char *s1, char const *s2, char c);
char	*ft_strnew(size_t size);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	**ft_strsplitspace(char const *s);
char	*ft_strjoinnfree(char *s1, char const *s2);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strcdup(char const *s, char c);
char	*ft_multistrjoin(size_t nb_str, ...);
char	*ft_chartostr(char c);
char	*ft_itoa(int n);
char	*ft_itoa_base(int val, int base, int output_size);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnspace(size_t n);
void	ft_putnbr(int nb);
void	ft_putaddr(long unsigned int addr, int ret);
void	ft_putstr(char const *str);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_isspace(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_iswhitespace(int c);
int		ft_isgreater(int a, int b);
int		ft_issmaller(int a, int b);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **app);
void	*ft_memdup(void const *s, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);
int		ft_tab_realloc(char ***tab, char *str);
void	ft_tabfree(char ***tab);
void	ft_free_all_four(void *ptr1, void *ptr2, void *ptr3, void *ptr4);
void	ft_exit(char *errmsg, int errnum);

#endif
