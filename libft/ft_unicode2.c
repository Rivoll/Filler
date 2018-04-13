/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:50:10 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:50:11 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void		ft_put_wchar(t_st *st, wchar_t c)
{
	if (c <= 0x7F)
		ft_put_wstr_c(st, c);
	else if (c <= 0x7FF)
	{
		ft_put_wstr_c(st, (c >> 6) + 0xC0);
		ft_put_wstr_c(st, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_put_wstr_c(st, ((c >> 12) + 0xE0));
		ft_put_wstr_c(st, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wstr_c(st, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_put_wstr_c(st, (c >> 18) + 0xF0);
		ft_put_wstr_c(st, ((c >> 12) & 0x3F) + 0x80);
		ft_put_wstr_c(st, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wstr_c(st, (c & 0x3F) + 0x80);
	}
}

void		ft_handle_char_unicode(t_st *st, wchar_t c)
{
	if (st->flag.minus == 0)
		ft_put_ldc(st, st->flag.ldc - 1);
	ft_put_wchar(st, c);
	if (st->flag.minus == 1)
		ft_put_ldc(st, st->flag.ldc - 1);
}

int			ft_get_wc_len(wchar_t c)
{
	int		len;

	len = 0;
	if (c <= 0x7F)
		++len;
	else if (c <= 0x7FF)
		len += 2;
	else if (c <= 0xFFFF)
		len += 3;
	else if (c <= 0x10FFFF)
		len += 4;
	return (len);
}
