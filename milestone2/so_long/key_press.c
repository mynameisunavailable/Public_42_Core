/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:53:44 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:24:24 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MOVES_OFFSETX 10
#define MOVES_OFFSETY 20
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

void	update_plr_moves(t_game *g)
{
	char	moves[12];

	g->plr_moves++;
	ft_itoa_fast(g->plr_moves, moves);
	ft_putstr("Current moves: ");
	ft_putstr(moves);
	ft_putstr("\n");
	mlx_put_image_to_window(g->mlx, g->win, g->gi->w, 0, 0);
	mlx_string_put(g->mlx, g->win, MOVES_OFFSETX, MOVES_OFFSETY, 0, moves);
	mlx_string_put(g->mlx, g->win, MOVES_OFFSETX + 2, MOVES_OFFSETY + 2, -1,
		moves);
}

void	player_move(t_game *g, size_t dest_i, size_t dest_j)
{
	char	dest_tile;

	dest_tile = g->map[dest_i][dest_j];
	if (dest_tile == '1')
		return ;
	else if (dest_tile == 'C' || dest_tile == '0')
	{
		if (dest_tile == 'C')
			g->coin_col++;
		g->map[dest_i][dest_j] = 'P';
		g->map[g->plr_i][g->plr_j] = '0';
		g->plr_i = dest_i;
		g->plr_j = dest_j;
	}
	else if (dest_tile == 'E')
	{
		if (g->coin_col < g->coin_num)
			return ;
		you_win(g);
	}
	else if (dest_tile == 'M')
		you_lose(g);
}

// 13 = w; 0 = a; 1 = s; 2 = d;
int	keypress(int key, t_game *g)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_ESC)
	{
		if (key == KEY_W)
			player_move(g, g->plr_i - 1, g->plr_j);
		else if (key == KEY_A)
			player_move(g, g->plr_i, g->plr_j - 1);
		else if (key == KEY_S)
			player_move(g, g->plr_i + 1, g->plr_j);
		else if (key == KEY_D)
			player_move(g, g->plr_i, g->plr_j + 1);
		else if (key == KEY_ESC)
			redx(g);
		mobs_move(g);
		if (ft_count_cina((const char **)g->map, 'P') < 1)
			you_lose(g);
		ft_foreach_arr(g->map, &n_to_m);
		window_load_floor(g, g->gi);
		window_load_pic(g, g->gi);
		update_plr_moves(g);
	}
	return (0);
}

int	redx(t_game *g)
{
	free_t_game_img(g);
	free_t_game(g);
	exit(0);
	return (0);
}
