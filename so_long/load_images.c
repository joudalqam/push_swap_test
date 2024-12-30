/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalqam <jalqam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:08:16 by jalqam            #+#    #+#             */
/*   Updated: 2024/12/30 18:43:18 by jalqam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_structure(void *mlx, t_game *game)
{
	t_images *img;

	img = malloc(sizeof(t_images));
	if(!img)
		return;
	img->wall = mlx_xpm_file_to_image(mlx, );
}



// init structure.
// init values;