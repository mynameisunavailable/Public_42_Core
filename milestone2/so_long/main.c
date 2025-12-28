/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:50:12 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:25:44 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ini_t_game(t_game *new, t_game_img *gi)
{
	new->mlx = NULL;
	new->win = NULL;
	new->map = NULL;
	new->map_w = 0;
	new->map_l = 0;
	new->err = 0;
	new->coin_num = 0;
	new->coin_col = 0;
	new->plr_moves = 0;
	new->gi = gi;
}

void	run_game(t_game *g, t_game_img *gi)
{
	g->win = mlx_new_window(g->mlx, g->map_w * TS, g->map_l * TS, "so long");
	window_load_floor(g, gi);
	window_load_pic(g, gi);
	load_player_pos(g);
	g->coin_num = ft_count_cina((const char **)g->map, 'C');
	mlx_hook(g->win, 2, 1L << 0, &keypress, g);
	mlx_hook(g->win, 17, 0, &redx, g);
	mlx_loop(g->mlx);
}

void	*load_img(t_game *g, t_game_img *gi, char *imgname)
{
	void	*res;

	res = mlx_xpm_file_to_image(g->mlx, imgname, &gi->img_j, &gi->img_i);
	if (!res)
	{
		redx(g);
	}
	return (res);
}

void	init_t_game_img(t_game *g, t_game_img *gi)
{
	gi->c = load_img(g, gi, "img/coin.xpm");
	gi->e = load_img(g, gi, "img/exit.xpm");
	gi->f = load_img(g, gi, "img/flor.xpm");
	gi->m = load_img(g, gi, "img/mobs.xpm");
	gi->p = load_img(g, gi, "img/plyr.xpm");
	gi->w = load_img(g, gi, "img/wall.xpm");
	if (!gi->c || !gi->e || !gi->f || !gi->m || !gi->p || !gi->w)
		redx(g);
}

int	main(int argc, char **argv)
{
	t_game		g;
	t_game_img	gi;

	ini_t_game(&g, &gi);
	if (argc != 2)
		g.err = print_err("Incorrect number of argument(s)");
	else if (argv_invalid(argv[1]))
		g.err = print_err("Invalid argument format");
	else if (!file_exists(argv[1]))
		g.err = print_err("File doesn't exist or file inaccessible");
	else
	{
		g.map = alloc_map(argv[1], &g);
		g.err = map_invalid(&g);
		if (g.err == 0)
		{
			g.mlx = mlx_init();
			init_t_game_img(&g, &gi);
			run_game(&g, &gi);
			free_t_game_img(&g);
			free_t_game(&g);
		}
	}
	return (g.err);
}
