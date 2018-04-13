/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:48:10 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/10 21:43:53 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int				ft_printf(const char *restrict fmt, ...)
{
	t_st		st;

	ft_bzero(&st, sizeof(st));
	va_start(st.ap, fmt);
	ft_init(&st);
	while (fmt[st.i])
	{
		if (fmt[st.i] == '%' && fmt[st.i + 1] == '%')
		{
			st.ret += write(1, "%", 1);
			st.i += 2;
		}
		else if (fmt[st.i] == '%' && fmt[st.i + 1] == '\0')
			return (st.ret);
		else if (fmt[st.i] == '%' && fmt[st.i + 1] != '%')
		{
			ft_handle_everything(&st, (char *restrict)fmt);
		}
		else
			st.ret += write(1, &(fmt[st.i++]), 1);
	}
	va_end(st.ap);
	return (st.ret);
}

void			ft_init(t_st *st)
{
	st->flag.dies = 0;
	st->flag.zero = 0;
	st->flag.minus = 0;
	st->flag.space = 0;
	st->flag.plus = 0;
	st->flag.isprec = 0;
	st->flag.prec = 1;
	st->flag.ldc = 0;
}

void			ft_handle_everything(t_st *st, char *restrict fmt)
{
	st->i += 1;
	ft_parse(st, fmt);
	if (ft_cast(st, fmt) == 1)
		return ;
	if (fmt[st->i] == 'C' || (fmt[st->i] == 'c') ||
		fmt[st->i] == 'S' || (fmt[st->i] == 's' && st->mdl == l))
	{
		if (fmt[st->i] != '\0')
			st->i++;
		return ;
	}
	ft_handle_precision(st, fmt);
	ft_add_flag(st, fmt);
	ft_padding(st);
	st->ret += write(1, st->str, ft_strlen(st->str));
	ft_strdel(&(st->str));
	if (fmt[st->i] != '\0')
		st->i++;
	ft_init(st);
}
