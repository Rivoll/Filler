/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 07:31:24 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/22 07:31:26 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define TEST 0

# include <string.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/include/libft.h"

typedef struct			s_piece
{
	char				**piece;
	int					x;
	int					y;
	int					i;
	int					is_star_y;
	int					is_star_x;
	int					empty_coll_start;
	int					empty_coll_end;
	int					empty_line_end;
	int					empty_line_start;
	unsigned	long	score;
	unsigned	long	score_act;
	int					distance;
}						t_piece;

typedef	struct			s_map
{
	char				**map;
	int					x;
	int					y;
	int					i;
}						t_map;

typedef	struct			s_player
{
	char				lettre;
	int					x_min;
	int					x_max;
	int					y_min;
	int					y_max;
	int					y_pos;
	int					x_pos;
}						t_player;

typedef	struct			s_enemy
{
	char				lettre;
	int					x_min;
	int					x_max;
	int					y_min;
	int					y_max;
	int					y_lst;
	int					x_lst;
}						t_enemy;

typedef	struct			s_fil
{
	t_piece				piece;
	t_map				map;
	t_player			player;
	t_enemy				enemy;
	char				*line;
	int					i;
	int					x_place;
	int					y_place;
}						t_fil;

int						ft_handle_all(t_fil *fil);
int						ft_check_player(t_fil *fil);
int						ft_init_map(t_fil *fil);
int						ft_creat_piece(t_fil *fil, char *l, char *x, char *y);
int						ft_check_part(t_fil *fil, int nb_part);
int						ft_check_enemy_pos(t_fil *fil, int x, int y);
int						ft_modify_part(t_fil *fil, int nb_part);
int						ft_get_closer(t_fil *fil, int i, int j);
int						ft_ini(t_fil *fil);
int						ft_count_part(t_fil *fil);
int						ft_is_placeable(t_fil *fil, int x, int y);
int						ft_place(t_fil *fil);
int						ft_handle_piece(t_fil *fil, char *line);
int						ft_piece(t_fil *fil);
int						ft_init_piece(t_fil *fil);
int						ft_map(t_fil *fil);
void					ft_quit_properly(t_fil *fil, char *str, int exit);
int						ft_free_all(t_fil *fil);
int						free_map(t_fil *fil);
int						free_piece(t_fil *fil);
int						ft_check_enemy_pos(t_fil *fil, int x, int y);
int						ft_clear_down_line(t_fil *fil);
int						ft_clear_piece(t_fil *fil, int y);
int						ft_clear_left_coll(t_fil *fil);
int						ft_clear_right_coll(t_fil *fil);
int						ft_check_valid_char(char c);
int						ft_check_line(t_fil *fil);
int						ft_calc_score(int i, int j, int x, int y);
int						ft_count_score(t_fil *fil, int x, int y);
int						ft_place_lul(t_fil *fil, int i, int j);
int						ft_place_rur(t_fil *fil, int i, int j);
int						ft_place_ldl(t_fil *fil, int i, int j);
int						ft_place_rdr(t_fil *fil, int i, int j);
int						ft_place_uul(t_fil *fil, int i, int j);
int						ft_place_uur(t_fil *fil, int i, int j);
int						ft_place_ddl(t_fil *fil, int i, int j);
int						ft_place_ddr(t_fil *fil, int i, int j);
#endif
