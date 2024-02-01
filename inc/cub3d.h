/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:48 by doduwole          #+#    #+#             */
/*   Updated: 2024/02/01 10:08:03 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// MLX_LIB
# ifdef __APPLE__
#  include "../mlx/mlx.h"
# else
#  include "../minilibx-linux/mlx.h"
# endif

# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

///////////////START/////////////
# include <math.h>

// KEYS //
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define EXIT 69

// MACROS ERMAL
# define TRUE 1
# define FALSE 0
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define PI M_PI
# define ROTATE_SPEED 0.05
# define PLAYER_SPEED 5
# define FOV 1.0471975512
# define EPSILON 0.0001
# define MIN_DIST_THRESHOLD 50

//MACROS ERWIN
# define EMPTY '0'
# define WALL '1'
# define VALID_TYPE "SWENFC"
# define EMPTY_SPACES " \t\r\f\v\n"

typedef struct s_img
{
	unsigned int	*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				height;
	int				width;
	int				endian;
	int				img_loaded;
}				t_img;

typedef struct s_sprite
{
	t_img			*north;
	t_img			*south;
	t_img			*west;
	t_img			*east;
}				t_sprite;

typedef struct s_player
{
	double			x;
	double			y;
	int				turn_direction;
	int				walk_direction;
	int				rotation_direction;
	double			angle;
	char			cardinal_dir;

}				t_player;

typedef struct s_game
{
	char			**map;
	int				map_height;
	int				map_width;
	int				y;
	int				x;
	char			*no_tex;
	char			*so_tex;
	char			*we_tex;
	char			*ea_tex;
	int				floor_color;
	int				ceiling_color;
}				t_game;

typedef struct s_distance
{
	double			x_ray;
	double			y_ray;
	double			x_delta;
	double			y_delta;
	int				ray_len;
}				t_distance;

typedef struct s_data
{
	int			box_size;
	void		*mlx;
	void		*win;
	t_game		*game;
	t_sprite	*sprite;
	t_player	*player;
	t_img		*img_game;
	t_distance	*distance;
	double		*rays_dist;
	double		*rays_x;
	double		*rays_y;
	double		*ray_angle;
	int			*is_horizontal;
}				t_data;

///////////////////////////END/////////////////////

//////////////ERMAL////////////////////////////

//draw.c
void			my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
void			draw_floor_ceiling(t_data *data, int x, int wall_height);
void			drw_column(t_data *data, int x, int wall_height, int offsetx);
void			draw_game(t_data *data);

//get_dist.c
void			get_distance(t_data *data);

double			move_dist(t_data *data, double angle);

//horizontal.c
double			get_horizontal(t_data *d, double angle, int count);

//init_pos.c
void			get_player_pos(t_data *data);

//init.c
void			init_data(t_data *d);
void			init_imgs(t_data *d);

//keys.c
void			change_position(t_data *d);
int				key_handler(int key, t_data *d);
int				key_release(int key, t_data *d);

//shading.c
unsigned int	apply_brightness(unsigned int color, double wall_height);
unsigned int	shading_effect(t_img *img, int x, int y, double wall_height);

//vertical.c
void			find_wall_intersection(t_data *d, t_distance *dist,
					int is_horizontal);

double			get_vertical(t_data *d, t_distance *dist,
					double angle, int count);

// wall_collisons.c
void			wall_collision(t_data *data, double angle);

//main.c
int				frames(t_data *data);
int				main(int argc, char **argv);

//////////////ERWIN///////////////////////////

/*------error.c-------*/
void			ft_clear_res(t_data *d);
void			ft_error(t_data *d, char *message);
void			ft_free_array(char **array);
int				ft_clean(t_data *d);

/*------readfile.c-------*/
int				*open_map(t_data *d, int argc, char *filename);

char			**allocate_map(t_data *d, int fd, char *line, t_game *game);
char			**generate_map(t_data *d, int fd, t_game *game);
void			read_map(t_data *d, int *fd, t_game *game);
void			get_height(t_data *d, int fd, char *line, t_game *game);
void			read_map(t_data *d, int *fd, t_game *game);

/*------readfile_utils.c-------*/
int				valid_map(char *line);
int				valid_type(char *str);
int				empty_line(char *str);
int				valid_char_map(char c);
int				valid_map_char(char c);
int				upto_empty(char *line);
int				upto_nonempty(char *line);
void			assign_type(t_data *d, char *tmp, int i, t_game *game);

/*------readfile_utils3.c-------*/
void			check_missing(t_data *d, t_game *game);
void			wall_checker(t_data *d, char **map, int x, int y);
void			map_check(t_data *d, char **map, int x, int y);
void			check_type(t_data *d, char *line, t_game *game);
void			map_len_check(t_data *d, t_game *game);

/*------utils.c-------*/
int				n_instances(char *str, char c);
void			init_game(t_game *game);
int				check_dir(char *filename);
// int				check_player_wall(char **map, int y, int x);

/*------color.c-------*/
int				get_rgb(t_data *d, char *num);

/*------paths.c-------*/
void			load_texture(t_data *d, t_img *img, char *path);
void			check_textures(t_data *d);
int				valid_path(t_data *d, char *path);

#endif
