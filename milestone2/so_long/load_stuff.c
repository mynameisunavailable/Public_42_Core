/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:50:14 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:25:45 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_load_floor(t_game *g, t_game_img *gi)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			mlx_put_image_to_window(g->mlx, g->win, gi->f, j * TS, i * TS);
			j++;
		}
		i++;
	}
}

void	window_load_pic(t_game *g, t_game_img *gi)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->win, gi->w, j * TS, i * TS);
			else if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, gi->p, j * TS, i * TS);
			else if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, gi->e, j * TS, i * TS);
			else if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, gi->c, j * TS, i * TS);
			else if (g->map[i][j] == 'M')
				mlx_put_image_to_window(g->mlx, g->win, gi->m, j * TS, i * TS);
			j++;
		}
		i++;
	}
}

void	load_player_pos(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->plr_i = i;
				g->plr_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
