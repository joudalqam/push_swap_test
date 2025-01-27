/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:45:16 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/27 20:11:55 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_values(t_game *game)
{
        game->map = NULL;
	game->player = NULL;
	game->image = NULL;
	game->mlx = NULL;
	game->window = NULL;
}

t_map	*init_map(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		exit(1);
		free(game);
	}
	map->width = 0;
	map->height = 0;
	map->collectable_count = 0;
	map->exit_count = 0;
	map->width = 0;
	map->array = NULL;
	return (map);
}

int	length(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

char	**initmap(char *file)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	len = length(fd);
	close(fd);
	map = malloc((len + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}

int	read_map(char **av, t_game *game)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("error opening map file");
		free(game->map);
		free(game);
		exit(1);
	}
	return (fd);
}

int	lines_count(int map_fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		line_count++;
		free(line);
	}
	return (line_count);
}

t_map	*store_map(t_game *game, char **av)
{
	int	line_count;
	int	i;
	int	fd;

	i = 0;
	fd = read_map(av, game);
	line_count = lines_count(fd);
	game->map->array = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map->array)
		exit_game(game);
	close(fd);
	fd = read_map(av, game);
	while (i < line_count)
	{
		game->map->array[i] = get_next_line(fd);
		if (i == 0)
		{
			game->map->width = ft_strlen(game->map->array[i]) - 2;
		}
		
		i++;
	}
	game->map->height = line_count;
	game->map->array[line_count] = NULL;
	close(fd);
	return (game->map);
}
t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player_x = 0;
	player->player_y = 0;
	return (player);
}
int	get_player_postion(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->array[i][j] == 'P')
			{
				game->player->player_x = j;
				game->player->player_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->exit_count = 0;
	map->player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j] == 'E')
				map->exit_count++;
			else if (map->array[i][j] == 'P')
				map->player_count++;
			else if (map->array[i][j] != 'C' && map->array[i][j] != '0'
					&& map->array[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	is_right(t_game *game)
{
	int	i;
	int	h;

	h = game->map->height;
	i = 0;
	while (i < game->map->width)
	{
		if (game->map->array[0][i] == '0' || game->map->array[h - 1][i] == '0')
		{
			return (1);
		}
		i++;
	}
	i = 1;
	while (i < h - 1)
	{
		if (game->map->array[i][0] == '0'
			|| game->map->array[i][game->map->width - 1] == '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
void	free_map(t_game *game)
{
	int	i;

	if (game->map->array)
	{
		i = 0;
		while (game->map->array[i])
		{
			free(game->map->array[i]);
			i++;
		}
		free(game->map->array);
		free(game->map);
	}
}

int	is_valid(t_map *map, t_game *game)
{
	check_count(map);
	if (is_right(game))
		return (1);
	if (map->exit_count != 1)
		return (1);
	if (map->player_count != 1)
		return (1);
	if (map->collectable_count == 0)
		return (1);
	if (check_count(map))
		return (1);
	return (0);
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
void	exit_game(t_game *game)
{
	if (game)
	{
		if (game->image)
		{
			free_images(game);
			free(game->image);
		}
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->player)
			free(game->player);
		if (game->map)
			free_map(game);
		free(game);
	}
	exit(1);
}

void	free_images(t_game *game)
{
	if (game->image)
	{
		if (game->image->wall)
			mlx_destroy_image(game->mlx, game->image->wall);
		if (game->image->floor)
			mlx_destroy_image(game->mlx, game->image->floor);
		if (game->image->exit)
			mlx_destroy_image(game->mlx, game->image->exit);
		if (game->image->player)
			mlx_destroy_image(game->mlx, game->image->player);
		if (game->image->collectible)
			mlx_destroy_image(game->mlx, game->image->collectible);
        if(game->image->exit_win)
            mlx_destroy_image(game->mlx, game->image->exit_win);
	}
}

t_game	*init_game(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	// init_values(game);
	game->map = init_map(game);
	store_map(game, argv);
	game->player = init_player();
	get_player_postion(game);
	if (check_map_valid_chars(game) || is_square(game) || valid_path(game))
	{
		perror("Error: Invalid map.");
		exit_game(game);
	}
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->height * 64, "so_long");
	game->image = init_structure(game);
	put_image(game);
	game->player->count = 0;
	game->map->collectable_count = check_collectible(game);
	return (game);
}

int	check_collectible(t_game *game)
{
	game->map->collectable_count = number_collectib(game);
	return (game->map->collectable_count);
}

int	number_collectib(t_game *game)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->array[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		i;

	if (argc != 2)
		return (1);
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '.' && argv[1][i + 1] != 'b')
			return (1);
		i++;
	}
	game = init_game(argv);
	redraw_player(game, game->mlx, game->window);
	if (!game)
		return (1);
	mlx_hook(game->window, 2, 1L << 0, keypress_handle, game);
	mlx_hook(game->window, 17, 0, free_game, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}
int	free_game(t_game *game)
{
	exit_game(game);
	exit(0);
}
int	number_collectibtotal(t_map *map)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}


int	valid_path(t_game *game)
{
	t_flood	data;
	char	**map_copy;
	int		collectibles;

	map_copy = fmap(game->map->array, game->map->height);
	if (!map_copy)
		return (1);
	collectibles = number_collectibtotal(game->map);
	data.map = map_copy;
	data.map_foold = game->map;
	data.collectibles = &collectibles;
	flood_fill(game->player->player_x, game->player->player_y, &data);
	free_2d_array(map_copy, game->map->height);
	if (collectibles > 0)
	{
		perror("Error: Not all collectibles are reachable.");
		return (1);
	}
	if (!data.map_foold->path)
	{
		perror("Error: Exit is not reachable.");
		return (1);
	}
	return (0);
}



// int close_window(void *param)
// {
//     (void)param;
//     exit(0);
// }

// t_map *init_map(t_game *game ,t_map *map)
// {
//     game->map = malloc(sizeof(t_map));  // Allocate memory for game->map
//     if (!game->map)
//     {
//         perror("Error: Memory allocation failed for map.");
//         exit(EXIT_FAILURE);
//     }
//     // map = malloc(sizeof(t_map));
//     map->height = 0;
//     map->width = 0;
//     game->map->player_count = 0;
//     game->map->collectable_count = 0;
//     game->map->exit_count = 0;
//     game->map->array = NULL;
//     game->map->count = 0;
//     game->image = NULL;
//     game->mlx = NULL;
//     game->window = NULL;
//     return game->map;
// }

// void    line_count(char *map_name, t_map *map)
// {
//     int     fd;
//     char    *line;

//     fd = open(map_name, O_RDONLY);
//     if (fd == -1)
//     {
//         write(1, "open map Error\n", 16);
//         exit(1);
//     }
//     line = get_next_line(fd);
//     // printf("the line from gnl : %s",line);
//     if (!line)
//     {
//         write(1, "Error: Empty map\n", 17);
//         exit(1);
//     }
//     map->width = ft_strlen(line) - 1;
//     // printf("width is %d\n",map->width);
//     map->height = 0;
//     while (1)
//     {
//         if (!line)
//             return;
//         map->height++;
//         free(line);
//         line = get_next_line(fd);
//     }
//     close(fd);
// }
// void    read_map(char *map_name, t_map *map)
// {
//     int     fd;
//     int     i;

//     i = 0;
//     fd = open(map_name, O_RDONLY);
//     if (fd == -1)
//     {
//         write(1, "open map Error\n", 16);
//         exit(1);
//     }
//     map->array = malloc(sizeof(char *) * (map->height + 1));
//     while (i < map->height)
//     {
//         map->array[i] = get_next_line(fd);
//         i++;
//     }
//     map->array[i] = NULL;
//     close(fd);
// }

// void print_map(t_map *map)
// {
//     int i = 0;

//     while (i < map->height)
//     {
//         printf("read map fucntion %s\n", map->array[i]);
//         i++;
//     }

// }

// int require_element(char *file, t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	fd;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	i = 0;
// 	while(map->array[i])
// 	{
// 		j = 0;
// 		while (map->array[i][j])
// 		{
// 			if (map->array[i][j] == 'P')
// 				map->player_count++;
// 			else if (map->array[i][j] == 'C')
// 				map->collectable_count++;
// 			else if (map->array[i][j] == 'E')
// 				map->exit_count++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	close(fd);
// 	return (map->exit_count == 1 && map->player_count == 1 && map->collectable_count > 0);
// }

// int main(int argc, char **argv)
// {
//     t_game *game;
//     t_images *image;
//     t_map   *map;

//     if (argc != 2)
//         return (0);
//     game = malloc(sizeof(t_game));
//     map = malloc(sizeof(t_map));
//     game->map = init_map(game,map);
//     line_count(argv[1], game->map);
//     read_map(argv[1], game->map);
//     if (!check_wall(game->map))
//     {
//         write(1, "Error: Map boundaries are not surrounded by 1\n", 46);
//         exit(1);
//     }
//     if (!require_element("map.ber", game->map))
//     {
//         write(1, "Error: Map missing required elements\n", 37);
//         exit(1);
//     }
//     player_position(game, game->map);
//     game->mlx = mlx_init();
//     game->window = mlx_new_window(game->mlx, 64 * game->map->width, 64 * game->map->height, "Hello world!");
//     mlx_hook(game->window, 17, 0, close_window, game->mlx);
//     print_map(game->map);
//     image = init_structure(game);
//     game->image = image;
//     game->count = 0;
//     put_image(game, game->map);
//     redraw_player(game,game->mlx,game->window);
//     mlx_hook(game->window, 2, 1L <<0, keypress_handle, game);
//     mlx_loop(game->mlx);
// }

// // t_game *init_game(char *argv[], t_game *game)
// // {
// //     game = malloc(sizeof(t_game));
// //     if (!game)
// //     {
// //         perror("Error: Memory allocation failed for game.");
// //         return NULL;
// //     }
// //     game = init_map(game);  // Initialize the map
// //     read_map(argv[1], game->map);  // Ensure read_map properly initializes game->map->array
// //     player_position(game, game->map);
// //     game = init_player();  // Make sure this function is correctly implemented
// //     if (!is_square(game) || !check_wall(game->map) || !valid_path(game))
// //     {
// //         perror("Error: Invalid map.");
// //         exit_game(game);
// //     }
// //     game->mlx = mlx_init();
// //     game->window = mlx_new_window(game->mlx, game->map->width * 64,
// //                                   game->map->height * 64, "so_long");
// //     game->image = init_structure(game);
// //     put_image(game, game->map);
// //     game->map->collectable_count = collect_count(game);
// //     return game;
// // }