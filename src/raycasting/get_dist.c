/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:21:03 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/15 19:37:46 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_distance(t_data *d)
{
	double	vertical_hit;
	int		count;
	double	angle;
	float	angle_increment;

	angle = d->player->angle - (FOV / 2);
	count = 0;
	angle_increment = FOV / WIN_WIDTH;
	while (count < WIN_WIDTH)
	{
		vertical_hit = get_vertical(d, d->distance, angle, count);
		d->rays_dist[count] = vertical_hit;
		get_horizontal(d, angle, count);
		angle += angle_increment;
		count++;
	}
}

double	move_dist(t_data *d, double angle)
{
	double	vertical_hit;
	double	horizontal_hit;
	int		count;

	vertical_hit = 0.0;
	horizontal_hit = 0.0;
	count = -1;
	if (fabs(cos(angle)) > fabs(sin(angle)))
	{
		horizontal_hit = get_horizontal(d, angle, count);
		if (horizontal_hit > MIN_DIST_THRESHOLD)
			vertical_hit = get_vertical(d, d->distance, angle, count);
	}
	else
	{
		vertical_hit = get_vertical(d, d->distance, angle, count);
		if (vertical_hit > MIN_DIST_THRESHOLD)
			horizontal_hit = get_horizontal(d, angle, count);
	}
	if (vertical_hit && (vertical_hit < horizontal_hit))
		return (vertical_hit);
	else
		return (horizontal_hit);
}
