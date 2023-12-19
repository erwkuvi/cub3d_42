/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:48:23 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/15 19:53:26 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_get_vertical(t_data *d, double angle, int px, int py)
{
	t_distance	*dist;
	int			size_box;

	dist = d->distance;
	size_box = d->box_size;
	if (cos(angle) > 0)
	{
		dist->x_ray = ((px / size_box) * size_box) + size_box;
		dist->y_ray = (px - dist->x_ray) * tan(angle) + py;
		dist->x_delta = size_box;
		dist->y_delta = -(dist->x_delta) * tan(angle);
	}
	else if (cos(angle) < 0)
	{
		dist->x_ray = ((px / size_box) * size_box) - EPSILON;
		dist->y_ray = (px - dist->x_ray) * tan(angle) + py;
		dist->x_delta = -(size_box);
		dist->y_delta = -(dist->x_delta) * tan(angle);
	}
	else
		dist->ray_len = d->game->map_width;
}

void	find_wall_intersection(t_data *d, t_distance *dist, int is_horizontal)
{
	int	mx;
	int	my;
	int	map_limit;

	if (is_horizontal)
		map_limit = d->game->map_height;
	else
		map_limit = d->game->map_width;
	while (dist->ray_len < map_limit)
	{
		mx = (int)(dist->x_ray) / d->box_size;
		my = (int)(dist->y_ray) / d->box_size;
		if (mx >= 0 && mx < d->game->map_width && my < d->game->map_height
			&& my >= 0 && d->game->map[my][mx] == WALL)
			dist->ray_len = map_limit;
		else
		{
			dist->x_ray += dist->x_delta;
			dist->y_ray += dist->y_delta;
			dist->ray_len++;
		}
	}
}

double	get_vertical(t_data *d, t_distance *dist, double angle, int count)
{
	int		px;
	int		py;

	px = d->player->x;
	py = d->player->y;
	dist->ray_len = 0;
	init_get_vertical(d, angle, px, py);
	find_wall_intersection(d, dist, FALSE);
	if (count == -1)
		return (hypot((dist->x_ray - px), (dist->y_ray - py)));
	d->rays_x[count] = dist->x_ray;
	d->rays_y[count] = dist->y_ray;
	d->is_horizontal[count] = FALSE;
	d->ray_angle[count] = angle;
	return (hypot((dist->x_ray - px), (dist->y_ray - py))
		* fabs(cos(d->player->angle - angle)));
}
