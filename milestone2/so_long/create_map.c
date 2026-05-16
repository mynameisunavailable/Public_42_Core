/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:54:04 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:36:29 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	line_width(char *buf)
{
	size_t	w;

	w = 0;
	if (!buf)
		return (w);
	w = ft_strlen(buf);
	if (w == 0)
		return (w);
	return (w - 1);
}

char	**alloc_map(char *filename, t_game *g)
{
	char	**map;
	int		fd;
	char	*buf;
	size_t	i;

	g->map_l = file_count_lines(filename);
	map = malloc(sizeof(char *) * (g->map_l + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	buf = get_next_line(fd);
	g->map_w = line_width(buf);
	i = 0;
	while (buf)
	{
		map[i++] = ft_strtrim(buf, "\n");
		free(buf);
		buf = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
