/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:04:24 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/09 15:35:34 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	check_size(int height, int width)
{
	static int	h;
	static int	w;

	if (!h)
		h = height;
	if (!w)
		w = width;
	if (!w || !h || width != w || height != h || w != h)
		ft_error("texture should be square", -1);
}

void	load_texture(t_data *data, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path,
			&(img->width), &(img->height));
	if (img->img == NULL)
		ft_error("Invalid texture", -1);
	img->addr = (int *) mlx_get_data_addr(img->img, &(img->bpp),
			&(img->line_length), &(img->endian));
	if (img->addr == NULL)
		ft_error("Invalid texture", -1);
	check_size(img->height, img->width);
	img->is_loaded = true;
	free(path);
}

int	valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error("wrong texture path", -1);
		return (0);
	}
	close(fd);
	return (1);
}

void	check_textures(t_data *data)
{
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;

	data->sprite = calloc(1, sizeof(t_sprite));
	north = calloc(1, sizeof(t_img));
	south = calloc(1, sizeof(t_img));
	west = calloc(1, sizeof(t_img));
	east = calloc(1, sizeof(t_img));
	if (valid_path(data->game->no_tex))
		load_texture(data, north, data->game->no_tex);
	if (valid_path(data->game->so_tex))
		load_texture(data, north, data->game->so_tex);
	if (valid_path(data->game->ea_tex))
		load_texture(data, north, data->game->ea_tex);
	if (valid_path(data->game->we_tex))
		load_texture(data, north, data->game->we_tex);
	data->box_size = north->height;
	data->player->p_img = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm\
		", &data->player->width, &data->player->height);
	data->sprite->north = north;
	data->sprite->south = south;
	data->sprite->west = west;
	data->sprite->east = east;
}
