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
    int path;
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

typedef struct s_player
{
    int player_x;
    int player_y;
    int count;
}t_player;

typedef struct s_game
{
    void *mlx;
    void *window;
    t_map *map;
    t_images *image;
    t_player *player;
} t_game;

typedef struct s_flood
{
	t_map		*map_foold;
	char		**map;
	int			*collectibles;
}				t_flood;




void init_values(t_game *game);
t_map	*init_map(t_game *game);
int	length(int fd);
char	**initmap(char *file);
int	read_map(char **av, t_game *game);
int	lines_count(int map_fd);
t_map	*store_map(t_game *game, char **av);
t_player	*init_player(void);
int	get_player_postion(t_game *game);
int	check_count(t_map *map);
int	is_valid(t_map *map, t_game *game);
int require_element(char *file, t_map *map);
void	exit_game(t_game *game);
void	free_images(t_game *game);
t_game	*init_game(char **argv);
int	check_collectible(t_game *game);
int	number_collectib(t_game *game);
int	free_game(t_game *game);
t_flood	*init_floodfill(char **map, t_map *map_flood, int *collectibles);
char	**fmap(char **map_flood, int height);
int	flood_fill(int x, int y, t_flood *data);
void	free_2d_array(char **array, int height);
int check_map_extension(char *file);
int check_wall(t_map *map);
int is_square(t_game *game);
size_t	removeln(char *line);
t_images *init_structure(t_game *game);
void	get_image(t_game *game ,int i, int j);
void put_image(t_game *game);
int	is_right(t_game *game);
int	valid_path(t_game *game);
int	number_collectibtotal(t_map *map);
void	free_map(t_game *game);
int keypress_handle(int keypress, t_game *game);
void move_player(t_game *game, int x, int y);
void	redraw_player(t_game *game, void *mlx, void *win);
#endif
