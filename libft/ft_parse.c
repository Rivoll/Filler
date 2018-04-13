/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:47:52 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:47:54 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void		ft_parse(t_st *st, char *restrict fmt)
{
	ft_caplus(fmt, st);
	ft_parseldc(fmt, st);
	ft_parse_preci(fmt, st);
	ft_parse_mdl(fmt, st);
}

void		ft_caplus(char *restrict str, t_st *cc)
{
	while (ft_strchr("#0- +I", str[cc->i]))
	{
		str[cc->i] == '#' ? cc->flag.dies = 1 : 0;
		str[cc->i] == ' ' ? cc->flag.space = 1 : 0;
		str[cc->i] == '+' ? cc->flag.plus = 1 : 0;
		str[cc->i] == '0' ? cc->flag.zero = 1 : 0;
		str[cc->i] == '-' ? cc->flag.minus = 1 : 0;
		cc->flag.minus == 1 ? cc->flag.zero = 0 : 0;
		cc->flag.plus == 1 ? cc->flag.space = 0 : 0;
		cc->i++;
	}
}

void		ft_parseldc(char *restrict str, t_st *cc)
{
	if (str[cc->i] >= '1' && str[cc->i] <= '9')
	{
		cc->flag.ldc = ft_atoi(str + cc->i);
		while (str[cc->i] && str[cc->i] >= '0' && str[cc->i] <= '9')
			cc->i++;
	}
}

void		ft_parse_preci(char *restrict str, t_st *cc)
{
	if (str[cc->i] == '.')
	{
		cc->flag.isprec = 1;
		cc->i++;
		if (str[cc->i] >= '0' && str[cc->i] <= '9')
		{
			cc->flag.prec = ft_atoi(str + cc->i);
			while (str[cc->i] && str[cc->i] >= '0' && str[cc->i] <= '9')
				cc->i++;
		}
		else if (str[cc->i] == '-')
		{
			cc->i++;
			if (str[cc->i] >= '0' && str[cc->i] <= '9')
			{
				while (str[cc->i] && str[cc->i] >= '0' && str[cc->i] <= '9')
					cc->i++;
			}
			cc->flag.prec = 0;
		}
		else
			cc->flag.prec = 0;
	}
}

void		ft_parse_mdl(char *restrict str, t_st *cc)
{
	if (str[cc->i] == '\0')
		return ;
	if (str[cc->i] == 'h' && str[cc->i + 1] == 'h')
		cc->mdl = hh;
	else if (str[cc->i] == 'h' && str[cc->i + 1] != 'h')
		cc->mdl = h;
	else if (str[cc->i] == 'l' && str[cc->i + 1] == 'l')
		cc->mdl = ll;
	else if (str[cc->i] == 'l' && str[cc->i + 1] != 'l')
		cc->mdl = l;
	else if (str[cc->i] == 'q')
		cc->mdl = ll;
	else if (str[cc->i] == 'j')
		cc->mdl = j;
	else if (str[cc->i] == 'z')
		cc->mdl = z;
	else
		cc->mdl = 0;
	while (ft_strchr("hlLqjtz", str[cc->i]))
		cc->i++;
}
