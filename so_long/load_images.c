/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:08:16 by jalqam            #+#    #+#             */
/*   Updated: 2025/01/07 19:34:31 by jalqam           ###   ########.fr       */
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
	img->exit_win = mlx_xpm_file_to_image(game->mlx, "exit2.xpm", &width, &height);
	img->floor= mlx_xpm_file_to_image(game->mlx, "floor.xpm", &width, &height);
	if (!img->floor)
		perror("failed to load image");
	img->player= mlx_xpm_file_to_image(game->mlx, "player.xpm", &width, &height);
	if (!img->floor)
		perror("failed to load image");
	return (img);
}

void	get_image(t_game *game ,int i, int j)
{
	void	*image;

	if (game->map->array[i][j] == '1')
		image = game->image->wall;
	else if (game->map->array[i][j] == '0')
		image = game->image->floor;
	else if (game->map->array[i][j] == 'E')
	{
		if (game->map->collectable_count == 0)
			image = game->image->exit_win;
		else
			image = game->image->exit;
	}
	else if (game->map->array[i][j] == 'P')
		image = game->image->floor;
	else if (game->map->array[i][j] == 'C')
		image = game->image->collectible;
	else
		return;
	mlx_put_image_to_window(game->mlx, game->window, image, j * 64, i * 64);
}

void put_image(t_game *game, t_map *map)
{
	(void)map;
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while(j < game->map->width)
		{
			 get_image(game, i, j);
			j++;
		}
		i++;
	}
}

