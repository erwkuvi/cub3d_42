/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:30:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/01 18:21:28 by ekuchel          ###   ########.fr       */
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

typedef struct s_game
{
	char			**map;
	int				y;
	int				x;
	char			*no_tex;
	char			*so_tex;
	char			*we_tex;
	char			*ea_tex;
	int				floor_color;
	int				ceiling_color;
}				t_game;

typedef struct s_data
{
	t_game			*game;
	t_img			*img;
}				t_data;

/*------error.c-------*/
int		ft_error(char *message, int ret_val, t_data *data);
void	ft_free_data(t_data *data);
void	ft_free_array(char **array);

/*------readfile.c-------*/
int		open_map(char *filename);
void	read_map(int *fd, t_game *game);
void	check_type(char *line, t_game *game);

/*------readfile_utils.c-------*/
bool	valid_type(char *str);
bool	empty_line(char *str);
int		upto_empty(char *line);
int		upto_nonempty(char *line);
void	assign_type(char *tmp, int i, t_game *game);

/*------utils.c-------*/
int		n_instances(char *str, char c);

/*------color.c-------*/
int		get_rgb(char *num);

#endif
