/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:45:16 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/07 20:12:05 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
}

t_map *init_map(t_game *game)
{
    game->map = malloc(sizeof(t_map));  // Allocate memory for game->map
    if (!game->map)
    {
        perror("Error: Memory allocation failed for map.");
        exit(EXIT_FAILURE);
    }
    game->map->height = 0;
    game->map->width = 0;
    game->map->player_count = 0;
    game->map->collectable_count = 0;
    game->map->exit_count = 0;
    game->map->array = NULL;
    game->map->count = 0;
    game->image = NULL;
    game->mlx = NULL;
    game->window = NULL;
    return game->map;
}

void    line_count(char *map_name, t_map *map)
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
    // printf("the line from gnl : %s",line);
    if (!line)
    {
        write(1, "Error: Empty map\n", 17);
        exit(1);
    }
    map->width = ft_strlen(line) - 1;
    // printf("width is %d\n",map->width);
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

int main(int argc, char **argv)
{
    t_game *game;
    t_images *image;

    if (argc != 2)
        return (0);
    game = malloc(sizeof(t_game));

    game->map = init_map(game);
    line_count(argv[1], game->map);
    read_map(argv[1], game->map);
    if (!check_wall(game->map))
    {
        write(1, "Error: Map boundaries are not surrounded by 1\n", 46);
        exit(1);
    }
    if (!require_element("map.ber", game->map))
    {
        write(1, "Error: Map missing required elements\n", 37);
        exit(1);
    }
    player_position(game, game->map);
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, 64 * game->map->width, 64 * game->map->height, "Hello world!");
    mlx_hook(game->window, 17, 0, close_window, game->mlx);
    print_map(game->map);
    image = init_structure(game);
    game->image = image;
    game->count = 0;
    put_image(game, game->map);
    redraw_player(game,game->mlx,game->window);
    mlx_hook(game->window, 2, 1L <<0, keypress_handle, game);
    mlx_loop(game->mlx);
}



// t_game *init_game(char *argv[], t_game *game)
// {
//     game = malloc(sizeof(t_game));
//     if (!game)
//     {
//         perror("Error: Memory allocation failed for game.");
//         return NULL;
//     }
//     game = init_map(game);  // Initialize the map
//     read_map(argv[1], game->map);  // Ensure read_map properly initializes game->map->array
//     player_position(game, game->map);
//     game = init_player();  // Make sure this function is correctly implemented
//     if (!is_square(game) || !check_wall(game->map) || !valid_path(game))
//     {
//         perror("Error: Invalid map.");
//         exit_game(game);
//     }
//     game->mlx = mlx_init();
//     game->window = mlx_new_window(game->mlx, game->map->width * 64,
//                                   game->map->height * 64, "so_long");
//     game->image = init_structure(game);
//     put_image(game, game->map);
//     game->map->collectable_count = collect_count(game);
//     return game;
// }