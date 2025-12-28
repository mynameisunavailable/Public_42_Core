/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:53:57 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:24:38 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_t_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free_arr(g->map);
}

void	free_t_game_img(t_game *g)
{
	if (g->gi->c)
		mlx_destroy_image(g->mlx, g->gi->c);
	if (g->gi->e)
		mlx_destroy_image(g->mlx, g->gi->e);
	if (g->gi->f)
		mlx_destroy_image(g->mlx, g->gi->f);
	if (g->gi->m)
		mlx_destroy_image(g->mlx, g->gi->m);
	if (g->gi->p)
		mlx_destroy_image(g->mlx, g->gi->p);
	if (g->gi->w)
		mlx_destroy_image(g->mlx, g->gi->w);
}
