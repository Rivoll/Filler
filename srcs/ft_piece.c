/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piecev2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:23:33 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/17 17:23:36 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_clear_piece(t_fil *fil, int y)
{
	int decal_x_start;
	int decal_x_end;
	int i;

	fil->piece.is_star_y = 0;
	decal_x_start = ft_clear_left_coll(fil);
	decal_x_end = ft_clear_right_coll(fil);
	fil->piece.empty_line_end = ft_clear_down_line(fil);
	while (y < fil->piece.y && y < fil->piece.y - fil->piece.empty_line_end)
	{
		fil->piece.piece[y] = ft_strfsub(&(fil->piece.piece[y]),
		decal_x_start, fil->piece.x - (decal_x_start + decal_x_end));
		y++;
	}
	i = y;
	while (y < fil->piece.y)
		ft_strdel(&(fil->piece.piece[y++]));
	fil->piece.y = i;
	fil->piece.x = fil->piece.x - (decal_x_start + decal_x_end);
	fil->piece.piece[fil->piece.y] = NULL;
	return (0);
}

int		ft_clear_left_coll(t_fil *fil)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < fil->piece.x)
	{
		y = 0;
		while (y < fil->piece.y - 1 && fil->piece.piece[y][x] == '.')
			y++;
		if (fil->piece.piece[y][x] != '.')
			break ;
		x++;
	}
	if (x == fil->piece.x)
		ft_quit_properly(fil, "bad piece\n", 1);
	fil->piece.empty_coll_start = x;
	return (fil->piece.empty_coll_start);
}

int		ft_clear_down_line(t_fil *fil)
{
	int	x;
	int	y;

	y = fil->piece.y - 1;
	x = 0;
	while (y > 0)
	{
		x = 0;
		while (x < (fil->piece.x - 1) && fil->piece.piece[y][x] == '.')
			++x;
		if (fil->piece.piece[y][x] != '.')
			break ;
		fil->piece.empty_line_end++;
		--y;
	}
	if (y == -1)
		ft_quit_properly(fil, "bad piece\n\n", 1);
	return (fil->piece.empty_line_end);
}

int		ft_clear_right_coll(t_fil *fil)
{
	int	x;
	int	y;

	y = 0;
	x = (fil->piece.x - 1);
	while (x > -1)
	{
		y = 0;
		while (y < (fil->piece.y - 1) && fil->piece.piece[y][x] == '.')
			++y;
		if (fil->piece.piece[y][x] != '.')
			break ;
		fil->piece.empty_coll_end++;
		--x;
	}
	if (x == -1)
		ft_quit_properly(fil, "bad piece\n\n", 1);
	return (fil->piece.empty_coll_end);
}

int		ft_piece(t_fil *fil)
{
	int	nb_line;

	nb_line = 0;
	if (ft_init_piece(fil))
		return (1);
	if (fil->line && fil->line != NULL)
		ft_strdel(&(fil->line));
	while (nb_line < fil->piece.y)
	{
		if (get_next_line(0, &(fil->line)) < 0)
			return (1);
		if (!fil->line)
			return (1);
		if (ft_check_line(fil))
			return (1);
		nb_line++;
		ft_strdel(&(fil->line));
	}
	fil->piece.piece[fil->piece.y - fil->piece.empty_line_start] = NULL;
	fil->piece.y = fil->piece.y - fil->piece.empty_line_start;
	return (ft_handle_all(fil));
}
