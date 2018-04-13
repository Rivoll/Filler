/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:53:19 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:53:24 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		ft_cast(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'd' || fmt[st->i] == 'D' || fmt[st->i] == 'i')
		ft_di(st, fmt);
	else if (fmt[st->i] == 'b' || fmt[st->i] == 'B')
		ft_b(st, fmt);
	else if (fmt[st->i] == 'u' || fmt[st->i] == 'U')
		ft_u(st, fmt);
	else if (fmt[st->i] == 'o' || fmt[st->i] == 'O')
		ft_o(st, fmt);
	else if (fmt[st->i] == 'x')
		ft_x(st, fmt);
	else if (fmt[st->i] == 'X')
		ft_grand_x(st, fmt);
	else if (fmt[st->i] == 's' || fmt[st->i] == 'S')
		ft_s(st, fmt);
	else if (fmt[st->i] == 'p' || fmt[st->i] == 'P')
		ft_p(st, fmt);
	else if (fmt[st->i] == 'c' || fmt[st->i] == 'C')
		ft_c(st, fmt);
	else if (fmt[st->i] == '%')
		st->str = ft_strdup("%");
	else
		return (1);
	return (0);
}

void	ft_di(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'D' || st->mdl == l)
		st->str = ft_llitoa_base(va_arg(st->ap, long), 10, 0);
	else if (st->mdl == hh)
		st->str = ft_llitoa_base((char)va_arg(st->ap, int), 10, 0);
	else if (st->mdl == h)
		st->str = ft_llitoa_base((short)va_arg(st->ap, int), 10, 0);
	else if (st->mdl == ll)
		st->str = ft_llitoa_base(va_arg(st->ap, long long), 10, 0);
	else if (st->mdl == j)
		st->str = ft_llitoa_base(va_arg(st->ap, intmax_t), 10, 0);
	else if (st->mdl == z)
		st->str = ft_llitoa_base(va_arg(st->ap, size_t), 10, 0);
	else
		st->str = ft_llitoa_base((int)va_arg(st->ap, long), 10, 0);
	if (st->flag.isprec == 1)
		st->flag.zero = 0;
}

void	ft_b(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'B' || st->mdl == l)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long), 2, 0);
	else if (st->mdl == hh)
		st->str =
		ft_ullitoa_base((unsigned char)va_arg(st->ap, unsigned int), 2, 0);
	else if (st->mdl == h)
		st->str =
		ft_ullitoa_base((unsigned short)va_arg(st->ap, unsigned int), 2, 0);
	else if (st->mdl == ll)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long long), 2, 0);
	else if (st->mdl == j)
		st->str = ft_ullitoa_base(va_arg(st->ap, intmax_t), 2, 0);
	else if (st->mdl == z)
		st->str = ft_ullitoa_base(va_arg(st->ap, size_t), 2, 0);
	else
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned int), 2, 0);
	if (st->flag.isprec == 1)
		st->flag.zero = 0;
}

void	ft_u(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'U' || st->mdl == l)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long), 10, 0);
	else if (st->mdl == hh)
		st->str =
		ft_ullitoa_base((unsigned char)va_arg(st->ap, unsigned int), 10, 0);
	else if (st->mdl == h)
		st->str =
		ft_ullitoa_base((unsigned short)va_arg(st->ap, unsigned int), 10, 0);
	else if (st->mdl == ll)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long long), 10, 0);
	else if (st->mdl == j)
		st->str = ft_ullitoa_base(va_arg(st->ap, intmax_t), 10, 0);
	else if (st->mdl == z)
		st->str = ft_ullitoa_base(va_arg(st->ap, size_t), 10, 0);
	else
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned int), 10, 0);
	if (st->flag.isprec == 1)
		st->flag.zero = 0;
}

void	ft_x(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] != 'x')
		return ;
	if (st->mdl == l)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long), 16, 0);
	else if (st->mdl == hh)
		st->str =
		ft_ullitoa_base((unsigned char)va_arg(st->ap, unsigned int), 16, 0);
	else if (st->mdl == h)
		st->str =
		ft_ullitoa_base((unsigned short)va_arg(st->ap, unsigned int), 16, 0);
	else if (st->mdl == ll)
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned long long), 16, 0);
	else if (st->mdl == j)
		st->str = ft_ullitoa_base(va_arg(st->ap, intmax_t), 16, 0);
	else if (st->mdl == z)
		st->str = ft_ullitoa_base(va_arg(st->ap, size_t), 16, 0);
	else
		st->str = ft_ullitoa_base(va_arg(st->ap, unsigned int), 16, 0);
	if (st->flag.isprec == 1)
		st->flag.zero = 0;
}
