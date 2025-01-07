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
    int path;
    char *file;
} t_map;

typedef struct s_images
{
    void    *wall;
    void    *floor;
    void    *collectible;
    void    *player;
    void    *exit;
    void    *exit_win;
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

typedef struct s_flood
{
	t_map		*map_foold;
	char		**map;
	int			*collectibles;
}				t_flood;


void    line_count(char *map_name, t_map *map);
void	free_2d_array(char **array, int height);
int is_valid_char(char c);
int check_map_valid_chars(t_game *game);
size_t	removeln(char *line);
int	is_square(t_game *game);
t_game	*init_player(void);
void    read_map(char *map_name, t_map *map);
t_images *init_structure(t_game *game);
int collect_count(t_game *game);
void print_map(t_map *map);
t_flood	*init_floodfill(char **map, t_map *map_flood, int *collectibles);
char	**fmap(char **map_flood, int height);
int	flood_fill(int x, int y, t_flood *data);
int close_window(void *param);
void put_image(t_game *game, t_map *map);
void	get_image(t_game *game ,int i, int j);
int require_element(char *file, t_map *map);
void move_player(t_game *game, int x, int y);
int keypress_handle(int keypress, t_game *game);
void exit_game(t_game *game);
int check_map_extension(char *file);
int check_wall(t_map *map);
t_map *init_map(t_game *game);
int valid_path(t_game *game);
void player_position(t_game *game, t_map *map);
void redraw_player(t_game *game, void *mlx, void *win);
// void line_count(char *file, t_map *map);
#endif
