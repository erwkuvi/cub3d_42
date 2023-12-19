/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:48:35 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/12 14:35:34 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = (char *)data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_ceiling(t_data *data, int x, int wall_height)
{
	int	y;
	int	floor_start;
	int	ceiling_end;

	y = 0;
	ceiling_end = (WIN_HEIGHT - wall_height) / 2;
	floor_start = (WIN_HEIGHT + wall_height) / 2;
	while (y < ceiling_end)
	{
		my_mlx_pixel_put(data->img_game, x, y, data->game->ceiling_color);
		y++;
	}
	y = floor_start;
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(data->img_game, x, y, data->game->floor_color);
		y++;
	}
}

void	drw_column(t_data *data, int x, int wall_height, int offsetx)
{
	int	y;
	int	is_horizontal;

	is_horizontal = data->is_horizontal[WIN_WIDTH - x];
	y = (WIN_HEIGHT - wall_height) / 2;
	while (y++ < (WIN_HEIGHT + wall_height) / 2)
	{
		if (y >= WIN_HEIGHT)
			break ;
		else if (y < 0)
			y = 0;
		if (is_horizontal && sin(data->ray_angle[WIN_WIDTH - x]) > 0)
			my_mlx_pixel_put(data->img_game, x, y,
				shading_effect(data->sprite->north, offsetx, y, wall_height));
		else if (is_horizontal && sin(data->ray_angle[WIN_WIDTH - x]) < 0)
			my_mlx_pixel_put(data->img_game, x, y,
				shading_effect(data->sprite->south, offsetx, y, wall_height));
		else if (!is_horizontal && cos(data->ray_angle[WIN_WIDTH - x]) > 0)
			my_mlx_pixel_put(data->img_game, x, y,
				shading_effect(data->sprite->east, offsetx, y, wall_height));
		else if (!is_horizontal && cos(data->ray_angle[WIN_WIDTH - x]) < 0)
			my_mlx_pixel_put(data->img_game, x, y,
				shading_effect(data->sprite->west, offsetx, y, wall_height));
	}
}

static int	calculate_offsetx(t_data *data, int col, int is_horizontal)
{
	if (is_horizontal)
		return ((int)data->rays_x[WIN_WIDTH - col] % data->box_size);
	else
		return ((int)data->rays_y[WIN_WIDTH - col] % data->box_size);
}

void	draw_game(t_data *data)
{
	int	i;
	int	col;
	int	wall_height;
	int	offsetx;

	i = WIN_WIDTH - 1;
	col = 0;
	while (i >= 0)
	{
		wall_height = WIN_HEIGHT / (data->rays_dist[i] / data->box_size);
		draw_floor_ceiling(data, col, wall_height);
		offsetx = calculate_offsetx(data, col, data->is_horizontal[i]);
		drw_column(data, col, wall_height, offsetx);
		i--;
		col++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_game->img, 0, 0);
}
