/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:56:17 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/22 10:43:23 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_check_player(t_fil *fil)
{
	if (ft_strstr(fil->line, "$$$ exec p1"))
	{
		fil->player.lettre = 'O';
		fil->enemy.lettre = 'X';
	}
	else if (ft_strstr(fil->line, "$$$ exec p2"))
	{
		fil->player.lettre = 'X';
		fil->enemy.lettre = 'O';
	}
	else
		return (1);
	return (0);
}

int			ft_map(t_fil *fil)
{
	int		nb_line;

	nb_line = 0;
	while (get_next_line(0, &(fil->line)) > 0 && nb_line < fil->map.y)
	{
		fil->i = 0;
		while (fil->line[fil->i] && fil->i < 4)
			fil->i++;
		if (ft_check_valid_char(fil->line[fil->i]) == 0 || fil->i != 4)
			return (1);
		fil->map.map[fil->map.i] = ft_strnew(fil->map.x);
		fil->map.map[fil->map.i] = ft_strncpy(fil->map.map[fil->map.i],
			fil->line + 4, fil->map.x);
		fil->map.i++;
		nb_line++;
		ft_strdel(&(fil->line));
	}
	if (nb_line != fil->map.y)
		return (1);
	fil->map.map[fil->map.i] = NULL;
	return (ft_piece(fil));
}

int			ft_init_piece(t_fil *fil)
{
	fil->i = 0;
	while (fil->line[fil->i] && fil->i < 6)
		fil->i++;
	if (!ft_isdigit(fil->line[fil->i]) || fil->i != 6)
		return (1);
	if ((fil->piece.y = ft_atlli_base(fil->line + fil->i, 10, 0)) <= 0)
		return (1);
	while (fil->line[fil->i] && ft_isdigit(fil->line[fil->i]))
		fil->i++;
	if (fil->line[fil->i] == ' ')
		fil->i++;
	else
		return (1);
	if (!ft_isdigit(fil->line[fil->i]))
		return (1);
	if (((fil->piece.x = ft_atlli_base(fil->line + fil->i, 10, 0)) <= 0))
		return (1);
	if (!(fil->piece.piece = (char**)malloc(sizeof(char*) *
		(fil->piece.y + 1))))
		return (1);
	fil->i = 0;
	while (fil->i < fil->piece.y + 1)
		fil->piece.piece[fil->i++] = NULL;
	return (0);
}

int			ft_init_map(t_fil *fil)
{
	fil->i = 0;
	while (fil->line[fil->i] && fil->i < 8)
		fil->i++;
	if (!ft_isdigit(fil->line[fil->i]) || fil->i != 8)
		return (1);
	if (((fil->map.y = ft_atlli_base(fil->line + fil->i, 10, 0)) <= 0))
		return (1);
	while (fil->line[fil->i] && ft_isdigit(fil->line[fil->i]))
		fil->i++;
	if (fil->line[fil->i] == ' ')
		fil->i++;
	else
		return (1);
	if (!ft_isdigit(fil->line[fil->i]))
		return (1);
	if ((fil->map.x = ft_atlli_base(fil->line + fil->i, 10, 0)) <= 0)
		return (1);
	if (!(fil->map.map = (char**)malloc(sizeof(char*) * (fil->map.y + 1))))
		return (1);
	fil->i = 0;
	while (fil->i < fil->map.y + 1)
		fil->map.map[fil->i++] = NULL;
	ft_strdel(&(fil->line));
	return (0);
}

int			ft_check_valid_char(char c)
{
	if (c == '.' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
