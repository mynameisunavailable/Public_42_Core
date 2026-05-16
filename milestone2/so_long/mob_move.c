/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:51:59 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:23:35 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	n_to_m(char **arr, size_t i, size_t j)
{
	if (arr[i][j] == 'N')
		arr[i][j] = 'M';
}

void	mobs_move_patrol(t_game *g, size_t i, size_t j)
{
	char			**arr;
	size_t			new_i;
	size_t			new_j;
	struct timeval	time;
	long			random;

	arr = g->map;
	new_i = i;
	new_j = j;
	gettimeofday(&time, NULL);
	random = time.tv_usec % 4;
	if (random == 0 && arr[i - 1][j] != '1' && arr[i - 1][j] != 'C' && arr[i
		- 1][j] != 'E')
		new_i -= 1;
	else if (random == 1 && arr[i + 1][j] != '1' && arr[i + 1][j] != 'C'
		&& arr[i - 1][j] != 'E')
		new_i += 1;
	else if (random == 2 && arr[i][j - 1] != '1' && arr[i][j - 1] != 'C'
		&& arr[i - 1][j] != 'E')
		new_j -= 1;
	else if (random == 3 && arr[i][j + 1] != '1' && arr[i][j + 1] != 'C'
		&& arr[i - 1][j] != 'E')
		new_j += 1;
	g->map[i][j] = '0';
	g->map[new_i][new_j] = 'N';
}

void	mobs_move(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'M')
			{
				mobs_move_patrol(g, i, j);
			}
			j++;
		}
		i++;
	}
}
