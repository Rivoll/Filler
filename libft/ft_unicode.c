/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:50:00 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:50:02 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void			ft_put_wstr_c(t_st *st, char c)
{
	st->ret += write(1, &c, 1);
}

void			ft_putwstr(unsigned int c, t_st *st)
{
	if (c <= 0x7F)
		st->ret += write(1, &c, 1);
	else if (c < 0x7FF)
	{
		ft_put_wstr_c(st, (c >> 6) + 0xC0);
		ft_put_wstr_c(st, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_put_wstr_c(st, (c >> 12) + 0xE0);
		ft_put_wstr_c(st, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wstr_c(st, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x1FFFFF)
	{
		ft_put_wstr_c(st, (c >> 18) + 0xF0);
		ft_put_wstr_c(st, ((c >> 12) & 0x3F) + 0x80);
		ft_put_wstr_c(st, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wstr_c(st, (c & 0x3F) + 0x80);
	}
}

void			ft_put_ldc(t_st *st, int nb_pad)
{
	char		c;

	if (st->flag.zero == 1 && st->flag.minus == 0)
		c = '0';
	else
		c = ' ';
	while (nb_pad > 0)
	{
		st->ret += write(1, &c, 1);
		--nb_pad;
	}
}

int				ft_get_wstr_len(wchar_t *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i] != 0)
		count += ft_get_wc_len(str[i++]);
	return (count);
}

void			ft_handle_str_unicode(t_st *st, wchar_t *str, unsigned long i)
{
	long int	nb_pad;
	long int	size;
	int			nb_write;

	nb_write = 0;
	if (!str)
	{
		st->ret += write(1, "(null)", 6);
		return ;
	}
	size = (st->flag.isprec == 0 ? ft_get_wstr_len(str) : st->flag.prec);
	nb_pad = st->flag.ldc - size;
	st->flag.minus == 0 ? ft_put_ldc(st, nb_pad) : 0;
	if (st->flag.isprec == 1)
		while (str[i] != 0 && nb_write + ft_get_wc_len(str[i]) <= size)
		{
			nb_write += ft_get_wc_len(str[i]);
			ft_putwstr(str[i++], st);
		}
	else
		while (str[i] != 0)
			ft_putwstr(str[i++], st);
	st->flag.minus == 1 ? ft_put_ldc(st, nb_pad) : 0;
}
