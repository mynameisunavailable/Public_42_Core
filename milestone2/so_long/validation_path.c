/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:46:06 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:23:40 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_to_f(char **arr, size_t i, size_t j)
{
	if (arr[i][j] == 'P')
		arr[i][j] = 'F';
}

void	infect_straight(char **arr, size_t i, size_t j)
{
	int	x;

	if (arr[i][j] == 'F')
	{
		x = 1;
		while (arr[i - x][j] != '1')
		{
			arr[i - x++][j] = 'F';
		}
		x = 1;
		while (arr[i + x][j] != '1')
		{
			arr[i + x++][j] = 'F';
		}
		x = 1;
		while (arr[i][j - x] != '1')
		{
			arr[i][j - x++] = 'F';
		}
		x = 1;
		while (arr[i][j + x] != '1')
		{
			arr[i][j + x++] = 'F';
		}
	}
}

int	floodable(char **arr, size_t i, size_t j)
{
	if (arr[i][j] == 'F')
	{
		if (i > 0 && arr[i - 1][j] != '1' && arr[i - 1][j] != 'F')
			return (1);
		else if (arr[i + 1] != NULL && arr[i + 1][j] != '1' && arr[i
			+ 1][j] != 'F')
			return (1);
		else if (j > 0 && arr[i][j - 1] != '1' && arr[i][j - 1] != 'F')
			return (1);
		else if (arr[i][j + 1] != '\0' && arr[i][j + 1] != '1' && arr[i][j
			+ 1] != 'F')
			return (1);
	}
	return (0);
}

// turn all reachable blocks starting from 'P' into 'F'
char	**flood_fill(char **arr)
{
	int	stop;

	ft_foreach_arr(arr, &p_to_f);
	stop = 0;
	while (stop == 0)
	{
		stop = 1;
		ft_foreach_arr(arr, &infect_straight);
		if (ft_checkeach_arr(arr, &floodable))
			stop = 0;
	}
	return (arr);
}

int	path_is_valid(t_game *g)
{
	char	**temp_map;

	temp_map = ft_arrdup((const char **)g->map);
	temp_map = flood_fill(temp_map);
	if (ft_count_cina((const char **)temp_map, 'E') > 0)
		return (0);
	else if (ft_count_cina((const char **)temp_map, 'C') > 0)
		return (0);
	free_arr(temp_map);
	return (1);
}
