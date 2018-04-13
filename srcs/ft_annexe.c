/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:15:59 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/22 13:07:35 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_check_enemy_pos(t_fil *fil, int x, int y)
{
	while (y < fil->map.y)
	{
		x = 0;
		while (x < fil->map.x)
		{
			if (fil->map.map[y][x] == fil->enemy.lettre + 32)
			{
				fil->enemy.x_lst = x;
				fil->enemy.y_lst = y;
				return (0);
			}
			else if (fil->map.map[y][x] == fil->enemy.lettre)
			{
				fil->enemy.x_lst = x;
				fil->enemy.y_lst = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_line(t_fil *fil)
{
	fil->i = 0;
	while (fil->line[fil->i] && (fil->line[fil->i] == '.' ||
		fil->line[fil->i] == '*'))
		fil->i++;
	if (fil->i != fil->piece.x || fil->line[fil->i] != '\0')
		return (1);
	if (ft_strchr(fil->line, '*') || fil->piece.is_star_y == 1)
	{
		fil->piece.piece[fil->piece.i++] = ft_strdup(fil->line);
		fil->piece.is_star_y = 1;
	}
	else
		fil->piece.empty_line_start++;
	return (0);
}

int	ft_calc_score(int i, int j, int x, int y)
{
	int score;
	int res_y;
	int res_x;

	score = 100000;
	res_x = i - x;
	res_y = j - y;
	res_x < 0 ? res_x *= -1 : 0;
	res_y < 0 ? res_y *= -1 : 0;
	if (res_x + res_y == 0)
		return (score / 10);
	score /= ((res_x + res_y) * ((res_x + res_y) * (res_x + res_y) * 10));
	return (score);
}

int	ft_count_score(t_fil *fil, int x, int y)
{
	int i;
	int j;
	int score;

	i = 0;
	j = 0;
	score = 0;
	while (j < fil->map.y)
	{
		i = 0;
		while (i < fil->map.x)
		{
			if (fil->map.map[j][i] == fil->enemy.lettre)
				score += ft_calc_score(i++, j, x, y);
			else if (fil->map.map[j][i] == fil->enemy.lettre + 32)
				score += (ft_calc_score(i++, j, x, y) * 1000);
			else
				i++;
		}
		j++;
	}
	return (score);
}
