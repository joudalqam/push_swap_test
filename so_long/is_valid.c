/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:34:55 by marvin            #+#    #+#             */
/*   Updated: 2025/01/06 23:34:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_char(char c)
{
    return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

int check_map_valid_chars(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map->height)
    {
        j = 0;
        while (j < game->map->width)
        {
            if (!is_valid_char(game->map->array[i][j]))
            {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}
int collect_count(t_game *game)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;
    while (i < game->map->height)
    {
        j = 0;
        while(i < game->map->width)
        {
            if (game->map->array[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

// int valid_path(t_game *game)
// {
//     t_flood data;
//     char **copy;
//     int     collect;

//     copy = fmap(game->map->array, game->map->height);
//     if(!copy)
//         return (1);
//     collect = collect_count(game); // maybe game->map
//     data.map = copy;
//     data.map_foold = game->map;
//     data.collectibles = &collect;
//     flood_fill(game->player->player_x, game->player->player_y, &data);
//     free_2d_array(copy , game->map->height);
//     if(collect > 0)
//     {
//         perror("Error: Not all collectibles are reachable.");
// 	    return (1);
//     }
//     if (!data.map_foold->path)
// 	{
// 		perror("Error: Exit is not reachable.");
// 		return (1);
// 	}
// 	return (0);
// }
