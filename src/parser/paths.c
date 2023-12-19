/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:04:24 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 19:36:38 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_size(t_data *d, int height, int width)
{
	static int	h;
	static int	w;

	if (!h)
		h = height;
	if (!w)
		w = width;
	if (!w || !h || width != w || height != h || w != h)
		ft_error(d, "texture should be square");
}

void	load_texture(t_data *d, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(d->mlx, path,
			&(img->width), &(img->height));
	if (img->img == NULL)
	{
		free(path);
		ft_error(d, "Invalid texture");
	}
	img->addr = (int *) mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (img->addr == NULL)
	{
		free(path);
		ft_error(d, "Invalid texture");
	}
	check_size(d, img->height, img->width);
	img->img_loaded = TRUE;
}

int	valid_path(t_data *d, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error(d, "wrong texture path");
		return (0);
	}
	close(fd);
	return (1);
}

void	check_textures(t_data *d)
{
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;

	d->sprite = calloc(1, sizeof(t_sprite));
	north = calloc(1, sizeof(t_img));
	south = calloc(1, sizeof(t_img));
	west = calloc(1, sizeof(t_img));
	east = calloc(1, sizeof(t_img));
	if (valid_path(d, d->game->no_tex))
		load_texture(d, north, d->game->no_tex);
	if (valid_path(d, d->game->so_tex))
		load_texture(d, south, d->game->so_tex);
	if (valid_path(d, d->game->ea_tex))
		load_texture(d, east, d->game->ea_tex);
	if (valid_path(d, d->game->we_tex))
		load_texture(d, west, d->game->we_tex);
	d->box_size = north->height;
	d->sprite->north = north;
	d->sprite->south = south;
	d->sprite->west = west;
	d->sprite->east = east;
}
