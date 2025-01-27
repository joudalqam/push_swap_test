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
    int new_x = game->player->player_x + x;
    int new_y = game->player->player_y + y;

    if (game->map->array[new_y][new_x] != '1')
    {
        game->player->player_x = new_x;
        game->player->player_y = new_y;
        if (game->map->array[new_y][new_x] == 'C') {
            game->map->collectable_count--;
            game->map->array[new_y][new_x] = '0';
        }
        if (game->map->array[new_y][new_x] == 'E' && game->map->collectable_count == 0) 
        {
             game->player->count++;
            ft_putnbr_fd(game->player->count,1);
            ft_putstr_fd("\n",1);
            exit_game(game);
        }
        game->player->count++;
        ft_putnbr_fd(game->player->count,1);
        ft_putstr_fd("\n",1);
        redraw_player(game, game->mlx, game->window);
    }
}

void	redraw_player(t_game *game, void *mlx, void *win)
{
	put_image(game);
	mlx_put_image_to_window(mlx, win, game->image->player,
		game->player->player_x * 64, game->player->player_y * 64);
}



