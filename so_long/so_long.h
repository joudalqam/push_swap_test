#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
    int height;
    int width;
    char **array;
    int player_count;
    int collectable_count;
    int exit_count;
    int count;
} t_map;

typedef struct s_images
{
    void    *wall;
    void    *floor;
    void    *collectible;
    void    *player;
    void    *exit;
    int	imagewidth;
	int	imageheight;

}   t_images;

typedef struct s_game
{
    void *mlx;
    void *window;
    t_map *map;
    t_images *image;
    int player_x;
    int player_y;
    int count;
} t_game; 


// void    load_map(char *file, t_map *map);

void    dimensions(char *map_name, t_map *map);
void    read_map(char *map_name, t_map *map);
t_images *init_structure(t_game *game);
void print_map(t_map *map);
int close_window(void *param);
void put_image(t_game *game, t_map *map);
int	get_image(t_game *game ,int i, int j);
int require_element(char *file, t_map *map);
void move_player(t_game *game, int x, int y);
int keypress_handle(int keypress, t_game *game);
void exit_game(t_game *game);
void player_position(t_game *game);
void redraw_player(t_game *game, void *mlx, void *win);
// void line_count(char *file, t_map *map);
#endif
