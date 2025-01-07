/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:43:15 by marvin            #+#    #+#             */
/*   Updated: 2025/01/05 21:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keypress_handle(int keypress, t_game *game)
{
    if (keypress == 65307)
        exit_game(game);
    if (keypress == 119 || keypress == 65362)
        move_player(game, 0, -1);
    if (keypress == 97 || keypress == 65361)
        move_player(game, -1, 0);
    if (keypress == 115 || keypress == 65364)
        move_player(game, 0, 1);
    if (keypress == 100 || keypress == 65363)
        move_player(game, 1, 0);
    return 0;
}


void move_player(t_game *game, int x, int y)
{
    int new_x = game->player_x + x;
    int new_y = game->player_y + y;

    if (game->map->array[new_y][new_x] != '1')
    {
        game->player_x = new_x;
        game->player_y = new_y;
        if (game->map->array[new_y][new_x] == 'C') {
            game->map->collectable_count--;
            game->map->array[new_y][new_x] = '0';
        }
        if (game->map->array[new_y][new_x] == 'E' && game->map->collectable_count == 0) 
        {
             game->count++;
            ft_putnbr_fd(game->count,1);
            ft_putstr_fd("\n",1);
            exit_game(game);
        }
        game->count++;
        ft_putnbr_fd(game->count,1);
        ft_putstr_fd("\n",1);
        redraw_player(game, game->mlx, game->window);
    }
}

void redraw_player(t_game *game, void *mlx, void *window)
{
    int player_x;
    int player_y;

    put_image(game, game->map);
    player_x = game->player_x ;
    player_y = game->player_y ;
    if(game->map->collectable_count == 0)
        mlx_put_image_to_window(mlx, window, game->image->exit, player_x * 64, player_y * 64);
    mlx_put_image_to_window(mlx, window, game->image->player, player_x * 64, player_y * 64);
}


void exit_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx); 
    free(game->mlx);
    exit(0);
}

void player_position(t_game *game, t_map *map)
{
    int i = 0;
    int j;

    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
         {
            if (map->array[i][j] == 'P')
             {
                game->player_x = j;
                game->player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}

t_game	*init_player(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player_x = 0;
	game->player_y = 0;
	return (game);
}