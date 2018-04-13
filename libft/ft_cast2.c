/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:43:20 by pkeita            #+#    #+#             */
/*   Updated: 2018/02/28 21:43:23 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	ft_o(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'O' || st->mdl == l)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long), 8, 0);
	else if (st->mdl == hh)
		st->str =
		ft_ullitoa_base((unsigned char)va_arg(st->ap, unsigned int), 8, 0);
	else if (st->mdl == h)
		st->str =
		ft_ullitoa_base((unsigned short)va_arg(st->ap, unsigned int), 8, 0);
	else if (st->mdl == ll)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long long), 8, 0);
	else if (st->mdl == j)
		st->str = ft_ullitoa_base(va_arg(st->ap, intmax_t), 8, 0);
	else if (st->mdl == z)
		st->str = ft_ullitoa_base(va_arg(st->ap, size_t), 8, 0);
	else
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned int), 8, 0);
	if (st->flag.isprec == 1)
		st->flag.zero = 0;
}

void	ft_grand_x(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] != 'X')
		return ;
	if (st->mdl == l)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long), 16, 1);
	else if (st->mdl == hh)
		st->str =
		ft_ullitoa_base((unsigned char)va_arg(st->ap, unsigned int), 16, 1);
	else if (st->mdl == h)
		st->str =
		ft_ullitoa_base((unsigned short)va_arg(st->ap, unsigned int), 16, 1);
	else if (st->mdl == ll)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long long), 16, 1);
	else if (st->mdl == j)
		st->str = ft_ullitoa_base(va_arg(st->ap, intmax_t), 16, 1);
	else if (st->mdl == z)
		st->str = ft_ullitoa_base(va_arg(st->ap, size_t), 16, 1);
	else
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned int), 16, 1);
	if (st->flag.isprec == 1)
		st->flag.zero = 0;
}

void	ft_s(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'S' || st->mdl == l)
		ft_handle_str_unicode(st, va_arg(st->ap, wchar_t*), 0);
	else
	{
		st->str = ft_strdup(va_arg(st->ap, char*));
		if (!(st->str))
		{
			st->str = ft_strdup("(null)");
		}
	}
}

void	ft_p(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'p')
	{
		st->str = ft_ullitoa_base((unsigned long)va_arg(st->ap, long), 16, 0);
		if (ft_strequ("0", st->str))
		{
			st->str = ft_str_replace(st->str, "0x");
			return ;
		}
		st->str = ft_stradd_start(st->str, "0x");
	}
	else
	{
		st->str = ft_ullitoa_base((unsigned long)va_arg(st->ap, long), 16, 1);
		if (ft_strequ("0", st->str))
		{
			st->str = ft_str_replace(st->str, "0X");
			return ;
		}
		st->str = ft_stradd_start(st->str, "0X");
	}
}

void	ft_c(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'C' || st->mdl == l)
		ft_handle_char_unicode(st, va_arg(st->ap, wchar_t));
	else
	{
		if (!(st->str = (char*)malloc(sizeof(char) * 2)))
			return ;
		st->str[0] = (char)va_arg(st->ap, int);
		st->flag.minus == 0 ? ft_put_ldc(st, st->flag.ldc - 1) : 0;
		st->ret += write(1, &(st->str[0]), 1);
		st->flag.minus == 1 ? ft_put_ldc(st, st->flag.ldc - 1) : 0;
		st->str[1] = '\0';
	}
}
