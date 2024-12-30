/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:08:16 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/30 20:09:32 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_structure(void *mlx, t_game *game)
{
	t_images	*img;
	int	width;
	int	height;

	width = 64;
	height = 64;
	img = malloc(sizeof(t_images));
	if(!img)
		return;
	img->wall = mlx_xpm_file_to_image(mlx, "./photos/wall.xpm", &width, &height);
	if(!img->wall)
		perror("failed to load image");
	img->collectible = mlx_xpm_file_to_image(mlx, "./photos/collectible.xpm", &width, &height);
	if(!img->collectible)
		perror("failed to load image");
	img->exit = mlx_xpm_file_to_image(mlx, "./photos/exit.xpm", &width, &height);
	if(!img->exit)
		perror("failed to load image");
	img->floor= mlx_xpm_file_to_image(mlx, "./photos/floor.xpm", &width, &height);
	if (!img->floor)
		perror("failed to load image");
	img->player= mlx_xpm_file_to_image(mlx, "./photos/player.xpm", &width, &height);
	if (!img->floor)
		perror("failed to load image");
}



// init structure.
// init values;