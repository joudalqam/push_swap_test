/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:19:10 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/26 19:49:23 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_flood	*init_floodfill(char **map, t_map *map_flood, int *collectibles)
{
	t_flood	*flood;	
	flood = malloc(sizeof(t_flood));
	if (!flood)
		return (NULL);
	flood->map = map;
	flood->map_foold = map_flood;
	flood->collectibles = collectibles;
	return (flood);
}

char	**fmap(char **map_flood, int height)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * height);
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = ft_strdup(map_flood[i]);
		if (!map[i])
		{
			free_2d_array(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	flood_fill(int x, int y, t_flood *data)
{
	if (x < 0 || y < 0 || x >= data->map_foold->width
		|| y >= data->map_foold->height)
		return (0);
	if (data->map[y][x] == '1' || data->map[y][x] == 'V')
		return (0);
	if (data->map[y][x] == 'C')
		(*data->collectibles)--;
	if (data->map[y][x] == 'E')
		data->map_foold->path = 1;
	data->map[y][x] = 'V';
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
	return (0);
}
