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
    if (keypress == 65307) // ESC key to exit
        exit_game(game);
    
    // W key (119) or Up arrow (65362) to move up
    if (keypress == 119 || keypress == 65362)
        move_player(game, 0, -1);
    
    // A key (97) or Left arrow (65361) to move left
    if (keypress == 97 || keypress == 65361)
        move_player(game, -1, 0);
    
    // S key (115) or Down arrow (65364) to move down
    if (keypress == 115 || keypress == 65364)
        move_player(game, 0, 1);
    
    // D key (100) or Right arrow (65363) to move right
    if (keypress == 100 || keypress == 65363)
        move_player(game, 1, 0);
    
    return 0;
}


void move_player(t_game *game, int x, int y)
{
    int new_x = game->player_x + x;
    int new_y = game->player_y + y;

    // Check if the new position is not a wall ('1')
    if (game->map->array[new_y][new_x] != '1') {
        game->player_x = new_x;  // Update player x position
        game->player_y = new_y;  // Update player y position

        // Check if the player collected an item ('C')
        if (game->map->array[new_y][new_x] == 'C') {
            game->map->collectable_count--;
            game->map->array[new_y][new_x] = '0';
        }
        if (game->map->array[new_y][new_x] == 'E' && game->map->collectable_count == 0) {
            exit_game(game); 
        }
        redraw_player(game, game->mlx, game->window);
    }
}



void redraw_player(t_game *game, void *mlx, void *window)
{
    put_image(game, game->map);

    int player_x = game->player_x ;
    int player_y = game->player_y ;
    
    mlx_put_image_to_window(mlx, window, game->image->player, player_x * 64, player_y * 64);
}


void exit_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx); 
    free(game->mlx); 
    exit(0);
}

void player_position(t_game *game)
{
    int i = 0;
    int j;

    // Loop through all rows and columns of the map using while loop
    while (i < game->map->height) {  // Iterate over rows (y-axis)
        j = 0;
        while (j < game->map->width) {  // Iterate over columns (x-axis)
            if (game->map->array[i][j] == 'P') {  // If 'P' is found
                game->player_x = j;  // Set player's x position
                game->player_y = i;  // Set player's y position
                return;  // Exit the function once the player is found
            }
            j++;
        }
        i++;
    }
}


// void	redraw_player(t_game *game, void *mlx, void *win)
// {
// 	load(game);
// 	mlx_put_image_to_window(mlx, win, game->image->player,
// 		game->player->player_x * 64, game->player->player_y * 64);
// }
