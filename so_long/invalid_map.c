/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:02:50 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/07 14:37:59 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int check_map_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 4] == '.' && file[len - 3] == 'b' && file[len - 2] == 'e' && file[len - 1] == 'r')
            	return (1);
	else
    		return (0);
}

int check_wall(t_map *map)
{
    int i;

    i = 0;
    while (i < map->width)
    {
        if (map->array[0][i] != '1' || map->array[map->height - 1][i] != '1')
            return (0);
        i++;
    }
    i = 1;
    while (i < map->height - 1)
    {
        if (map->array[i][0] != '1' || map->array[i][map->width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int is_square(t_game *game)
{
    if (!game->map->array || !game->map->array[0])
    {
        perror("Error: Map array is not initialized.");
        return (1);
    }

    size_t row_length = removeln(game->map->array[0]);
    for (int i = 0; game->map->array[i]; i++)
    {
        if (removeln(game->map->array[i]) != row_length)
        {
            perror("Error: The map is not square.");
            return (1);
        }
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