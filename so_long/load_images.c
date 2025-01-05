/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:08:16 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/05 19:28:03 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_images *init_structure(t_game *game)
{
	t_images	*img;
	int	width;
	int	height;

	img = malloc(sizeof(t_images));
	width =64;
	height=64;
	img->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &width, &height);
	if(!img->wall)
		perror("failed to load image");
	img->collectible = mlx_xpm_file_to_image(game->mlx, "collect.xpm", &width, &height);
	if(!img->collectible)
		perror("failed to load image");
	img->exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &width, &height);
	if(!img->exit)
		perror("failed to load image");
	img->floor= mlx_xpm_file_to_image(game->mlx, "floor.xpm", &width, &height);
	if (!img->floor)
		perror("failed to load image");
	img->player= mlx_xpm_file_to_image(game->mlx, "player.xpm", &width, &height);
	if (!img->floor)
		perror("failed to load image");
	return (img);
}

int	get_image(t_game *game ,int i, int j)
{
	void	*image;

	if (game->map->array[i][j] == '1')
		image = game->image->wall;
	else if (game->map->array[i][j] == '0')
		image = game->image->floor;
	else if (game->map->array[i][j] == 'E')
		image = game->image->exit;
	else if (game->map->array[i][j] == 'P')
		image = game->image->player;
	else if (game->map->array[i][j] == 'C')
		image = game->image->collectible;
	else
		return (1);
	mlx_put_image_to_window(game->mlx, game->window, image, j * 64, i * 64);
	return (0);
}

void put_image(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	
	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			 get_image(game, i, j);
			j++;
		}
		i++;
	}
}


// init structure.
// init values;