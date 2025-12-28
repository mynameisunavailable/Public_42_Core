/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winlose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:52:56 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:20:16 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	you_win(t_game *g)
{
	mlx_string_put(g->mlx, g->win, 60, 60, 0, "YOU WONNERED");
	mlx_string_put(g->mlx, g->win, 62, 62, -1, "YOU WONNERED");
	ft_putstr("YOU WONNERED\n");
	redx(g);
}

void	you_lose(t_game *g)
{
	mlx_string_put(g->mlx, g->win, 60, 60, 0, "YOU LOST");
	mlx_string_put(g->mlx, g->win, 62, 62, -1, "YOU LOST");
	ft_putstr("YOU LOST\n");
	redx(g);
}
