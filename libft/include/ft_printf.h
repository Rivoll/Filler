/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:47:46 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/06 21:10:09 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

typedef struct	s_flag
{
	int			dies;
	int			zero;
	int			minus;
	int			space;
	int			plus;
	int			isprec;
	int			prec;
	int			ldc;
}				t_flag;

typedef enum	e_mdl
{
	nomod = 0,
	h,
	hh,
	l,
	ll,
	j,
	z,
}				t_mdl;

typedef	struct	s_st
{
	va_list		ap;
	int			i;
	t_flag		flag;
	t_mdl		mdl;
	char		*str;
	int			ret;
}				t_st;

char			*ft_add_char(char *str, char c, int nb, int start);
char			*ft_add_char_end(char *str, char c, int nb);
char			*ft_stradd_start(char *src, char *add);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			ft_exit(char *str);
char			*ft_llitoa_base(long long nb, int base, int maj);
void			ft_putchar(char c);
void			ft_strdel(char **ap);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_strnfdup(char **s1, int len);
char			*ft_ullitoa_base(unsigned long long nb, int base, int maj);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_str_replace(char *erase, char *new);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
long long int	ft_atlli_base(char *nb, int base_nb, int maj);
char			*ft_strchr(const char *s, int c);
void			ft_putstr_fd(const char *s, int fd);
char			*ft_strnew(size_t size);

int				ft_printf(const char *restrict fmt, ...);
void			ft_init(t_st *st);
void			ft_handle_everything(t_st *st, char *restrict fmt);

void			ft_parse(t_st *st, char *restrict fmt);
void			ft_caplus(char *restrict str, t_st *cc);
void			ft_parseldc(char *restrict str, t_st *cc);
void			ft_parse_preci(char *restrict str, t_st *cc);
void			ft_parse_mdl(char *restrict str, t_st *cc);

int				ft_cast(t_st *st, char *restrict fmt);
void			ft_di(t_st *st, char *restrict fmt);
void			ft_b(t_st *st, char *restrict fmt);
void			ft_u(t_st *st, char *restrict fmt);
void			ft_x(t_st *st, char *restrict fmt);
void			ft_o(t_st *st, char *restrict fmt);
void			ft_p(t_st *st, char *restrict fmt);
void			ft_s(t_st *st, char *restrict fmt);
void			ft_c(t_st *st, char *restrict fmt);
void			ft_grand_x(t_st *st, char *restrict fmt);

void			ft_handle_precision(t_st *st, char *restrict fmt);
void			ft_precision_doibux(t_st *st, char *restrict fmt);
void			ft_add_flag(t_st *st, char *restrict fmt);
void			ft_handle_dies(t_st *st, char *restrict fmt);
void			ft_handle_plus(t_st *st, char *restrict fmt);
void			ft_handle_space(t_st *st, char *restrict fmt);
void			ft_padding(t_st *st);
void			ft_handle_zero(t_st *st, int dif);

void			ft_putwstr(unsigned int c, t_st *st);
int				ft_get_wc_len(wchar_t c);
void			ft_put_wstr_c(t_st *st, char c);
void			ft_put_ldc(t_st *st, int nb_pad);
void			ft_put_wchar(t_st *st, wchar_t c);
void			ft_handle_char_unicode(t_st *st, wchar_t c);
void			ft_handle_str_unicode(t_st *st, wchar_t *str, unsigned long i);

#endif
