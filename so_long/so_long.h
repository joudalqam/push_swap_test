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
} t_map;

typedef struct s_images
{
    void    *wall;
    void    *floor;
    void    *collectible;
    void    *player;
    void    *exit;

}   t_images;

typedef struct s_game
{
    void *mlk;
    void *window;
    t_map *map;
} t_game; 

// void    load_map(char *file, t_map *map);

void    dimensions(char *map_name, t_map *map);
void    read_map(char *map_name, t_map *map);

void print_map(t_map *map);
int close_window(void *param);
int require_element(char *file, t_map *map);
// void line_count(char *file, t_map *map);
#endif
