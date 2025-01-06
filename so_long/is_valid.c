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
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}