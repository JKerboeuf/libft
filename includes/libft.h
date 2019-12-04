/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:54:52 by jukerboe          #+#    #+#             */
/*   Updated: 2019/12/04 15:30:12 by jukerboe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**	CHAR
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
**	LIST
*/

void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *l, void*(*f)(void*), void(*d)(void*));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

/*
**	MATH
*/

int					ft_abs(int nb);
int					ft_fact(int nb);
int					ft_isprime(int nb);
int					ft_pow(int nb, int pow);
int					ft_sqrt(int nb);

/*
**	MEM
*/

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				ft_memdel(void **ptr);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t old, size_t size);
void				ft_swap(char *a, char *b);

/*
**	PUT
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_tab(int *n, size_t size);
void				ft_putstr(char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr_tab(char **s, size_t size);

/*
**	STR
*/

int					ft_atoi(char const *str);
char				*ft_itoa(int n);
int					ft_str_isalnum(char const *str);
int					ft_str_isalpha(char const *str);
int					ft_str_isascii(char const *str);
int					ft_str_isdigit(char const *str);
int					ft_str_isprint(char const *str);
int					ft_str_islower(char const *str);
int					ft_str_isupper(char const *str);
void				ft_str_tolower(char *str);
void				ft_str_toupper(char *str);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strchr(char const *s, int c);
int					ft_strchri(char const *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, char const *src);
void				ft_strdel(char **str);
char				*ft_strdup(char const *src);
char				*ft_stredit(char *s, size_t start, size_t end, char *mod);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
size_t				ft_strlcpy(char *dst, char const *src, size_t size);
size_t				ft_strlen(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char const *s2, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, char const *src, size_t len);
char				*ft_strndup(char const *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(char const *stack, char const *find, size_t n);
char				*ft_strrchr(char const *s, int c);
int					ft_strrchri(char const *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char const *stack, char const *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);

#endif
