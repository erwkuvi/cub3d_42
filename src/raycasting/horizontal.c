/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:48:30 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/15 19:40:46 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_horizontal(t_data *d, double angle, int px, int py)
{
	t_distance	*dist;
	int			size_box;

	dist = d->distance;
	size_box = d->box_size;
	if (sin(angle) > 0)
	{
		dist->y_ray = ((py / size_box) * size_box) - EPSILON;
		dist->x_ray = (py - dist->y_ray) * (1 / tan(angle)) + px;
		dist->y_delta = -size_box;
		dist->x_delta = - (dist->y_delta) * (1 / tan(angle));
	}
	else if (sin(angle) < 0)
	{
		dist->y_ray = ((py / size_box) * size_box) + size_box;
		dist->x_ray = (py - dist->y_ray) * (1 / tan(angle)) + px;
		dist->y_delta = size_box;
		dist->x_delta = - (dist->y_delta) * (1 / tan(angle));
	}
	else
		dist->ray_len = d->game->map_height;
}

double	get_horizontal(t_data *d, double angle, int count)
{
	int			px;
	int			py;
	t_distance	*dist;

	dist = d->distance;
	px = d->player->x;
	py = d->player->y;
	dist->ray_len = 0;
	init_horizontal(d, angle, px, py);
	find_wall_intersection(d, dist, FALSE);
	if (count == -1)
		return (hypot((dist->x_ray - px), (dist->y_ray - py)));
	if (d->rays_dist[count] > hypot((dist->x_ray - px),
			(dist->y_ray - py)) * fabs(cos(d->player->angle - angle)))
	{
		d->rays_x[count] = dist->x_ray;
		d->rays_y[count] = dist->y_ray;
		d->is_horizontal[count] = TRUE;
		d->rays_dist[count] = hypot((dist->x_ray - px),
				(dist->y_ray - py)) * fabs(cos(d->player->angle - angle));
	}
	return (hypot((dist->x_ray - px), (dist->y_ray - py)) * \
				fabs(cos(d->player->angle - angle)));
}
