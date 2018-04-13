/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:47:20 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:47:21 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	ft_add_flag(t_st *st, char *restrict fmt)
{
	if (st->flag.dies == 1)
		ft_handle_dies(st, fmt);
	if (st->flag.plus == 1)
		ft_handle_plus(st, fmt);
	if (st->flag.space == 1)
		ft_handle_space(st, fmt);
}

void	ft_handle_dies(t_st *st, char *restrict fmt)
{
	uintmax_t nb;

	if (fmt[st->i] != 'x' && fmt[st->i] != 'X' && fmt[st->i] != 'o' &&
		fmt[st->i] != 'O')
		return ;
	nb = (fmt[st->i] == 'X' ? ft_atlli_base(st->str, 10, 1) :
		ft_atlli_base(st->str, 10, 0));
	if (fmt[st->i] == 'x' && st->str[0] != '\0' && nb != 0)
		st->str = ft_stradd_start(st->str, "0x");
	else if (fmt[st->i] == 'X' && nb != 0 && st->str[0] != '\0')
		st->str = ft_stradd_start(st->str, "0X");
	else if ((fmt[st->i] == 'o' || fmt[st->i] == 'O') && fmt &&
		st->str[0] != '0')
		st->str = ft_stradd_start(st->str, "0");
}

void	ft_handle_plus(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'd' || fmt[st->i] == 'i')
	{
		if (st->str[0] != '-')
			st->str = ft_add_char(st->str, '+', 1, 0);
	}
}

void	ft_handle_space(t_st *st, char *restrict fmt)
{
	if (fmt[st->i] == 'd' || fmt[st->i] == 'i')
	{
		if (st->str[0] != '-')
			st->str = ft_add_char(st->str, ' ', 1, 0);
	}
}
