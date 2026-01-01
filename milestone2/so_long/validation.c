/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:45:57 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:21:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argv_invalid(char *str)
{
	size_t	len;
	char	*extension;

	len = ft_strlen(str);
	if (len <= 4)
		return (1);
	extension = str + len - 4;
	if (ft_strcmp(extension, ".ber") == 0)
		return (0);
	return (1);
}

int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

int	map_invalid(t_game *g)
{
	int	invalid;

	invalid = 0;
	if (!g->map)
		invalid = print_err("Map alloc failed");
	else if (ft_arr_is_subset((const char **)g->map, "01CEPM") != 1)
		invalid = print_err("Illegal character(s) found");
	else if (ft_count_cina((const char **)g->map, 'E') != 1)
		invalid = print_err("Exit number incorrect");
	else if (ft_count_cina((const char **)g->map, 'P') != 1)
		invalid = print_err("starting position number incorrect");
	else if (ft_count_cina((const char **)g->map, 'C') < 1)
		invalid = print_err("Collectible number incorrect");
	else if (ft_is_rect((const char **)g->map) != 1)
		invalid = print_err("Map is not rectangular");
	else if (map_is_enclosed(g, '1') != 1)
		invalid = print_err("Map is not enclosed");
	else if (path_is_valid(g) != 1)
		invalid = print_err("Path is not valid");
	if (invalid)
		return (free_arr(g->map), 1);
	return (0);
}

int	map_is_enclosed(t_game *g, char c)
{
	char	**arr;
	size_t	i;

	arr = g->map;
	if (!arr || !*arr)
		return (0);
	if (g->map_w == 0 || g->map_l == 0)
		return (0);
	i = 0;
	while (i < g->map_w)
	{
		if (arr[0][i] != c || arr[g->map_l - 1][i] != c)
			return (0);
		i++;
	}
	i = 0;
	while (i < g->map_l)
	{
		if (arr[i][0] != c || arr[i][g->map_w - 1] != c)
			return (0);
		i++;
	}
	return (1);
}
