/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 08:42:56 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/24 22:39:58 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>

# include <stdlib.h>

# include <limits.h>

# include <stdio.h>

# include <string.h>

# include <fcntl.h>

# include <sys/types.h>

# include <sys/stat.h>

# include "get_next_line.h"

# include "ft_printf.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_strcdup(const char *s, char c);

char			*ft_strnjoin(char const *s1, char const *s2, size_t len);

void			ft_putchar(char const c);

void			ft_putstr(char const *s);

int				ft_tab_lenght(char **tab);

size_t			ft_strlen(const char *str);

void			ft_exit(char *str);

char			*ft_stradd_start(char *src, char *add);

char			*ft_add_char(char *str, char c, int nb, int start);

char			*ft_str_replace(char *erase, char *new);

char			*ft_strnfdup(char **s1, int len);

void			ft_deltab2(char **tab);

long long int	ft_atlli_base(char *nb, int base_nb, int maj);

int				*ft_creat_tabi(int size);

int				**ft_creat_tabi2(int x, int y);

int				ft_tabicopy(int *tab1, int *tab2, int x);

int				ft_tabi2copy(int **tab1, int **tab2, int x, int y);

int				ft_deltabi2(int ***tab, int size);

char			*ft_convert(char *nb, int base_nb, int new_base, int maj);

char			*ft_llitoa_base(long long int nb, int base, int maj);

void			ft_printtab(char **tab);

void			ft_printtabi(int *tab, int size);

void			ft_printtab2i(int **tab2i, int y, int x);

void			ft_swap(int *a, int *b);

int				ft_tabicmp(int *tab1, int*tab2, int size);

void			ft_sorttab(int *tab, int size);

void			ft_permutation(int *tab, int size);

char			*ft_strcpy(char *dst, const char *src);

int				ft_strcountchar(char *str, char c);

char			*ft_strncpy(char *dst, const char *src, size_t len);

int				ft_toupper(int c);

int				ft_tolower(int c);

char			*ft_strdup(const char *s1);

char			*ft_strndup(const char *str, int len);

char			*ft_strfdup(char **s1);

int				ft_strcmp(const char *s1, const char *s2);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strncat(char *s1, const char *s2, size_t n);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_stradd(char *s1, char *s2);

char			*ft_strstr(const char *big, const char *little);

char			*ft_strnstr(const char *big, const char *little, size_t len);

char			*ft_strchr(const char *s, int c);

int				ft_strchri(char const *str, char c);

char			*ft_strrchr(const char *s, int c);

int				ft_atoi(const char *str);

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(int c);

int				ft_isprint(int c);

int				ft_ishexa(char *str);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memset(void *b, int c, size_t len);

void			ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memchr(const void *s, int c, size_t n);

void			*ft_memalloc(size_t size);

void			ft_memdel(void **ap);

char			*ft_strnew(size_t size);

void			ft_strdel(char **as);

void			ft_printab(char **tab);

void			ft_strclr(char *s);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmap(char const *s, char (*f)(char));

char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));

int				ft_strequ(char const *s1, char const *s2);

int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_strfsub(char **s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strtrim(char const *s);

char			**ft_strsplit(char const *s, char c);

char			*ft_itoa(int n);

char			*ft_convert_base(long long nb, int base, int maj);

char			*ft_llitoa(long long int nb);

char			*ft_ullitoa(unsigned long long nb);

char			*ft_ullitoa_base(unsigned long long nb, int base, int maj);

char			*ft_itoa_base(long long int nb);

void			ft_putendl(char const *s);

void			ft_putnbr(int n);

void			ft_putchar_fd(char c, int fd);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			ft_putstr_fd(char const *s, int fd);

void			ft_putendl_fd(char const *s, int fd);

void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void			ft_lstadd(t_list **alst, t_list *new);

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
