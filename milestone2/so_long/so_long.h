/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:46:10 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:25:44 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "minilibx-linux/mlx.h"
#include <sys/time.h>

struct						s_game
{
	void					*mlx;
	void					*win;
	char					**map;
	size_t					map_w;
	size_t					map_l;
	size_t					plr_i;
	size_t					plr_j;
	size_t					plr_moves;
	int						coin_num;
	int						coin_col;
	int						err;
	struct s_game_img		*gi;
};

typedef struct s_game		t_game;

struct						s_game_img
{
	void					*w;
	void					*f;
	void					*c;
	void					*p;
	void					*e;
	void					*m;
	int						img_i;
	int						img_j;
};

typedef struct s_game_img	t_game_img;

#define TS 64

// create_map.c
char						**alloc_map(char *filename, t_game *g);

// put_error.c
int							print_err(char *message);

// validation_path.c
void						p_to_f(char **arr, size_t i, size_t j);
void						infect_straight(char **arr, size_t i, size_t j);
int							floodable(char **arr, size_t i, size_t j);
char						**flood_fill(char **arr);
int							path_is_valid(t_game *g);

// validation.c
int							argv_invalid(char *str);
int							file_exists(char *filename);
int							map_invalid(t_game *g);
int							map_is_enclosed(t_game *g, char c);

// key_press.c
void						update_plr_moves(t_game *g);
void						player_move(t_game *g, size_t dest_i,
								size_t dest_j);
int							keypress(int key, t_game *g);
int							redx(t_game *g);

// load_img.c
// void	window_load_floor(t_game *g, t_game_img *gi);
// void	window_load_pic(t_game *g, t_game_img *gi);

// load_stuff.c
void						window_load_floor(t_game *g, t_game_img *gi);
void						window_load_pic(t_game *g, t_game_img *gi);
void						load_player_pos(t_game *g);

// mob_move.c
void						n_to_m(char **arr, size_t i, size_t j);
void						mobs_move_patrol(t_game *g, size_t i, size_t j);
void						mobs_move(t_game *g);

// free_game.c
void						free_t_game(t_game *g);
void						free_t_game_img(t_game *g);

// winlose.c
void						you_win(t_game *g);
void						you_lose(t_game *g);
