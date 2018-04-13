/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:51:16 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/22 10:44:41 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_ini(t_fil *fil)
{
	fil->piece.i = 0;
	fil->piece.y = 0;
	fil->piece.x = 0;
	fil->i = 0;
	fil->map.i = 0;
	fil->piece.empty_line_start = 0;
	fil->piece.empty_line_end = 0;
	fil->piece.empty_coll_start = 0;
	fil->piece.empty_coll_end = 0;
	fil->piece.is_star_y = 0;
	fil->piece.is_star_x = 0;
	fil->x_place = 0;
	fil->y_place = 0;
	fil->piece.score = 0;
	fil->piece.score_act = 0;
	fil->piece.distance = 2147483647;
	return (0);
}

void		ft_quit_properly(t_fil *fil, char *str, int exit)
{
	free_piece(fil);
	free_map(fil);
	if (fil->line && fil->line != NULL)
		ft_strdel(&(fil->line));
	if (exit)
		ft_exit(str);
}

int			free_map(t_fil *fil)
{
	int		i;

	i = 0;
	if (fil->map.map)
	{
		while ((fil->map.map)[i])
		{
			if (fil->map.map[i] != NULL)
				ft_strdel(&(fil->map.map[i]));
			++i;
		}
		free(fil->map.map);
		fil->map.map = NULL;
	}
	return (0);
}

int			free_piece(t_fil *fil)
{
	int		i;

	i = 0;
	if (fil->piece.piece)
	{
		while ((fil->piece.piece)[i])
		{
			if (fil->piece.piece[i] != NULL)
				ft_strdel(&(fil->piece.piece[i]));
			++i;
		}
		free(fil->piece.piece);
		fil->piece.piece = NULL;
	}
	return (0);
}

int			main(void)
{
	t_fil	fil;

	ft_bzero(&fil, sizeof(fil));
	ft_ini(&fil);
	while (get_next_line(0, &(fil.line)) > 0)
	{
		if (fil.player.lettre == 0 && ft_strstr(fil.line, "$$$ exec p"))
			if (ft_check_player(&fil))
				ft_quit_properly(&fil, "That's not a good sign!..\n\n", 1);
		if (ft_strstr(fil.line, "Plateau "))
		{
			if (ft_init_map(&fil) || fil.player.lettre == 0)
				ft_quit_properly(&fil, "Nope\n\n", 1);
			if (fil.map.map)
			{
				get_next_line(0, &(fil.line));
				ft_strdel(&(fil.line));
			}
			if (ft_map(&fil))
				ft_quit_properly(&fil, "Stop trying to fuck me\n", 1);
		}
		ft_strdel(&(fil.line));
	}
	ft_quit_properly(&fil, "", 0);
	return (0);
}
