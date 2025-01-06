/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:02:50 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/06 23:30:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int check_map(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len >= 4)
        {
		if (file[len - 4] == '.' && file[len - 3] == 'b' && file[len - 2] == 'e' && file[len - 1] == 'r')
            	return (1);  
	}
    return (0); 
}

int map_validity(t_map *map)
{
	int i;
	
	i = 0;
    while (i < map->width) {
        if (map->array[0][i] != '1') {
            return (0); 
        }
        i++;
    }
    i = 0;
    while (i < map->width) {
        if (map->array[map->height - 1][i] != '1') {
            return (0);
        }
        i++;
    }
    i = 1;  
    while (i < map->height - 1) {
        if (map->array[i][0] != '1') {
            return (0); 
        }
        i++;
    }
    i = 1;  
    while (i < map->height - 1)
     {
        if (map->array[i][map->width - 1] != '1')
	{
            return (0);
        }
        i++;
    }
    return (1);
}

int	is_square(t_game *game)
{
	size_t	row_length;
	int		i;

	row_length = removeln(game->map->array[0]);
	i = 0;
	while (game->map->array[i])
	{
		if (removeln(game->map->array[i]) != row_length)
		{
			perror("Error: The map is not square.");
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	removeln(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}