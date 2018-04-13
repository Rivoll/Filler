/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:10:37 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/22 10:43:48 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_is_placeable(t_fil *fil, int x, int y)
{
	int x_p;
	int y_p;
	int touch;

	y_p = 0;
	touch = 0;
	if (y + fil->piece.y > fil->map.y || x + fil->piece.x > fil->map.x)
		return (0);
	while (y_p < fil->piece.y)
	{
		x_p = 0;
		while (x_p < fil->piece.x)
		{
			if (fil->piece.piece[y_p][x_p] == '*' &&
						fil->map.map[y_p + y][x_p + x] == fil->player.lettre)
				touch++;
			if (fil->piece.piece[y_p][x_p] == '*' &&
						fil->map.map[y_p + y][x_p + x] == fil->enemy.lettre)
				return (0);
			++x_p;
		}
		++y_p;
	}
	return (touch == 1 ? 1 : 0);
}

int		ft_get_closer(t_fil *fil, int i, int j)
{
	int x_distance;
	int y_distance;
	int distance;

	x_distance = i - fil->enemy.x_lst;
	y_distance = j - fil->enemy.y_lst;
	x_distance < 0 ? x_distance = -x_distance : 0;
	y_distance < 0 ? y_distance = -y_distance : 0;
	distance = x_distance + y_distance;
	if (fil->piece.score <= 0)
	{
		if (distance < fil->piece.distance)
		{
			fil->piece.distance = distance;
			fil->x_place = i;
			fil->y_place = j;
		}
	}
	else if (fil->piece.score > fil->piece.score_act)
	{
		fil->piece.score_act = fil->piece.score;
		fil->x_place = i;
		fil->y_place = j;
	}
	return (0);
}

int		ft_place_lul(t_fil *fil, int i, int j)
{
	int	flag;

	flag = 0;
	while (j < fil->map.y)
	{
		i = 0;
		while (i < fil->map.x)
		{
			if (ft_is_placeable(fil, i, j))
			{
				flag = 1;
				fil->piece.score = ft_count_score(fil, i, j);
				ft_get_closer(fil, i, j);
			}
			i++;
		}
		j++;
	}
	return (flag == 0 ? 1 : 0);
}

int		ft_place(t_fil *fil)
{
	ft_check_enemy_pos(fil, 0, 0);
	if (ft_place_lul(fil, 0, 0))
	{
		fil->x_place = 0;
		fil->y_place = 0;
	}
	ft_putnbr(fil->y_place - fil->piece.empty_line_start);
	ft_putchar(' ');
	ft_putnbr(fil->x_place - fil->piece.empty_coll_start);
	ft_putchar('\n');
	return (0);
}

int		ft_handle_all(t_fil *fil)
{
	if (fil->line && fil->line != NULL)
		ft_strdel(&(fil->line));
	if (fil->piece.i == 0)
		return (1);
	ft_clear_piece(fil, 0);
	if (fil->piece.x > fil->map.x || fil->piece.y > fil->map.y)
		return (1);
	ft_place(fil);
	free_piece(fil);
	free_map(fil);
	ft_ini(fil);
	return (0);
}
