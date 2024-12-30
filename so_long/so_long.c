/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:45:16 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/30 20:10:56 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
}

t_map *init_map()
{
	t_map *map;

	map = malloc(sizeof(t_map));
	map->height = 0;	
	map->width = 0;	
	map->player_count = 0;	
	map->exit_count = 0;	
	map->collectable_count = 0;	
	map->array = NULL;
	return (map);
}


void    dimensions(char *map_name, t_map *map)
{
    int     fd;
    char    *line;
    fd = open(map_name, O_RDONLY);
    if (fd == -1)
    {
        write(1, "open map Error\n", 16);
        exit(1);
    }
    line = get_next_line(fd);
    if (!line)
    {
        write(1, "Error: Empty map\n", 17);
        exit(1);
    }
    map->width = ft_strlen(line) - 1;
    map->height = 0;
    while (line)
    {
        map->height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
void    read_map(char *map_name, t_map *map)
{
    int     fd;
    int     i;
    i = 0;
    fd = open(map_name, O_RDONLY);
    if (fd == -1)
    {
        write(1, "open map Error\n", 16);
        exit(1);
    }
    map->array = malloc(sizeof(char *) * (map->height + 1));
    while (i < map->height)
    {
        map->array[i] = get_next_line(fd);
        i++;
    }
    map->array[i] = NULL;
    close(fd);
}


void print_map(t_map *map)
{
    int i = 0;

    while (i < map->height)
    {
        printf("read map fucntion %s\n", map->array[i]);
        i++;
    }
}


int require_element(char *file, t_map *map)
{
	int	i;
	int	j;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while(map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'P')
				map->player_count++;
			else if (map->array[i][j] == 'C')
				map->collectable_count++;
			else if (map->array[i][j] == 'E')
				map->exit_count++;
			j++;					
		}
		i++;
	}
	close(fd);
	return (map->exit_count == 1 && map->player_count == 1 && map->collectable_count > 0);
}
int	main(void)
{
	
	t_map *map;
	map = init_map();
	dimensions("map.ber", map);
	read_map("map.ber", map);
	require_element("map.ber",map);
	printf("map->player count %d\n", map->player_count);
	print_map(map);
}