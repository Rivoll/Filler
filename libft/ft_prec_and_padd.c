/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_padd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:48:01 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:48:03 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void		ft_precision_doibux(t_st *st, char *restrict fmt)
{
	int		dif;

	if (st->flag.prec <= 0 && ft_strequ("0", st->str))
	{
		st->str = ft_str_replace(st->str, "");
		return ;
	}
	dif = st->flag.prec - ft_strlen(st->str);
	if (fmt[st->i] == 'p' || fmt[st->i] == 'P')
		dif += 2;
	if (st->str[0] == '-')
		++dif;
	if (dif > 0)
		ft_handle_zero(st, dif);
}

void		ft_handle_zero(t_st *st, int dif)
{
	if (st->str[0] != '\0')
	{
		if (st->str[0] == '0' && (st->str[1] == 'x' || st->str[1] == 'X'))
		{
			st->str = ft_add_char(st->str, '0', dif, 2);
			return ;
		}
	}
	if (st->str[0] == '-' || st->str[0] == '+' || st->str[0] == ' ')
		st->str = ft_add_char(st->str, '0', dif, 1);
	else
		st->str = ft_add_char(st->str, '0', dif, 0);
}

void		ft_padding(t_st *st)
{
	int		dif;

	if (st->flag.ldc < 0)
	{
		st->flag.ldc *= -1;
		st->flag.minus = 1;
	}
	dif = st->flag.ldc - ft_strlen(st->str);
	if (dif < 1)
		return ;
	if (st->flag.minus == 1)
		st->str = ft_add_char_end(st->str, ' ', dif);
	else if (st->flag.zero == 1)
		ft_handle_zero(st, dif);
	else
		st->str = ft_add_char(st->str, ' ', dif, 0);
}

void		ft_handle_precision(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'd' || fmt[st->i] == 'D' || fmt[st->i] == 'o' ||
		fmt[st->i] == 'O' || fmt[st->i] == 'i' || fmt[st->i] == 'b' ||
		fmt[st->i] == 'B' || fmt[st->i] == 'u' || fmt[st->i] == 'p' ||
		fmt[st->i] == 'U' || fmt[st->i] == 'x' || fmt[st->i] == 'X' ||
		fmt[st->i] == 'P')
		ft_precision_doibux(st, fmt);
	else if (fmt[st->i] == 's' && st->flag.isprec == 1)
		st->str = ft_strnfdup(&(st->str), st->flag.prec);
}
