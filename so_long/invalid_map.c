/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:02:50 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/06 20:11:35 by jalqam           ###   ########.fr       */
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
            return 0; 
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