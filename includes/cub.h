/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:45 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/07 18:22:02 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:30:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/05 16:31:32 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# define EMPTY '0'
# define WALL '1'
# define VALID_TYPE "SWENFC"
# define EMPTY_SPACES " \t\r\f\v\n"

typedef struct s_img
{
	unsigned int	*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				height;
	int				width;
	int				endian;
	bool			is_loaded;
}				t_img;

typedef struct s_sprite{
    int		        x;
    int		        y;
    int		        distance;
    t_img           *north;
    t_img	        *south;
    t_img	        *west;
    t_img	        *east;
}				t_sprite;

typedef struct s_player
{
    void	        *p_img;
    int		        width;
    int		        height;
    double	        x;
    double	        y;
    int		        turn_direction;
    int		        walk_direction;
    int		        rotation_direction;
    double	        angle;
    char	        view;

}				t_player;

typedef struct s_game
{
	char			**map;
	int				    y;
	size_t				x;
	char			*no_tex;
	char			*so_tex;
	char			*we_tex;
	char			*ea_tex;
	int				floor_color;
	int				ceiling_color;
}				t_game;

typedef struct s_data
{
    void		    *mlx;
    void		    *win;
	t_game			*game;
	t_img			*img;
    t_img		    *img_game;
    t_sprite        *sprite;
    t_player        *player;
    double		    *rays_dist;
    double		    *rays_x;
    double		    *rays_y;
    double		    *ray_angle;
    bool		    *is_horizontal;
}				t_data;

/*------error.c-------*/
int		ft_error(char *message, int ret_val);
void	ft_free_data(t_data *data);
int 	ft_free(t_data *d);
void	ft_free_array(char **array);

/*------readfile.c-------*/
int		*open_map(char *filename);
void	read_map(int *fd, t_game *game);
void	check_type(char *line, t_game *game);
void	check_missing(t_game *game);

/*------readfile_utils.c-------*/
bool    valid_map(char *line);
bool	valid_type(char *str);
bool	empty_line(char *str);
bool    valid_char_map(char c);
bool    valid_map_char(char c);
int		upto_empty(char *line);
int		upto_nonempty(char *line);
void	assign_type(char *tmp, int i, t_game *game);

/*------readfile_utils2.c-------*/

/*------utils.c-------*/
int		n_instances(char *str, char c);

/*------color.c-------*/
int		get_rgb(char *num);

#endif
