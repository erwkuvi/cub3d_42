/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:00:48 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/15 19:43:45 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	init_steps(t_data *d, int *mx, int *my, int *tx)
{
	int	ty;

	*mx = d->player->walk_direction
		* cos(d->player->angle) * PLAYER_SPEED;
	*my = d->player->walk_direction
		* sin(d->player->angle) * PLAYER_SPEED;
	*tx = d->player->turn_direction
		* cos(d->player->angle + (PI / 2)) * PLAYER_SPEED;
	ty = d->player->turn_direction
		* sin(d->player->angle + (PI / 2)) * PLAYER_SPEED;
	return (ty);
}

static void	turn(t_data *d, int turn_x, int turn_y)
{
	double	wall_dist;

	wall_dist = hypot(turn_x, turn_y);
	if (move_dist(d, (d->player->angle + (PI / 2) * (d->player->\
turn_direction))) - 50 > wall_dist && d->player->turn_direction)
	{
		d->player->x += turn_x;
		d->player->y -= turn_y;
	}
}

static void	walk(t_data *d, int move_x, int move_y)
{
	double	wall_dist;
	double	dist;

	dist = move_dist(d, d->player->angle);
	wall_dist = hypot(move_x, move_y);
	if (move_dist(d, d->player->angle - (PI * (d->player->\
walk_direction == -1))) - 50 > wall_dist && d->player->walk_direction)
	{
		d->player->x += move_x;
		d->player->y -= move_y;
	}
	else if (d->player->walk_direction && dist < 60)
		wall_collision(d, d->player->angle);
}

void	change_position(t_data *d)
{
	int	move_x;
	int	move_y;
	int	turn_x;
	int	turn_y;

	if (!d->player->walk_direction && !d->player->\
turn_direction && !d->player->rotation_direction)
		return ;
	d->player->angle += d->player->rotation_direction * ROTATE_SPEED;
	if (d->player->angle < 0)
		d->player->angle = 2 * PI + d->player->angle;
	else if (d->player->angle > 2 * PI)
		d->player->angle -= 2 * PI;
	turn_y = init_steps(d, &move_x, &move_y, &turn_x);
	turn(d, turn_x, turn_y);
	walk(d, move_x, move_y);
}
