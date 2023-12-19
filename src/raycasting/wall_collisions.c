/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collisions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:23:33 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/12 14:32:27 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	adjust_player_x(t_data *data, double angle)
{
	double	potential_move;

	potential_move = cos(angle) * PLAYER_SPEED;
	if ((angle > PI / 2 || angle < 3 * PI / 2) && move_dist(data, PI) - 100
		> potential_move)
		data->player->x += potential_move;
	else if ((angle < PI / 2 || angle > 3 * PI / 2) && move_dist(data, 0) - 100
		> potential_move)
		data->player->x += potential_move;
}

static void	adjust_player_y(t_data *data, double angle)
{
	double	potential_move;

	potential_move = sin(angle) * PLAYER_SPEED;
	if ((angle > 0 && angle <= PI) && move_dist(data, PI / 2) - 100
		> potential_move)
		data->player->y -= potential_move;
	else if ((angle < 0 || angle > PI) && move_dist(data, 3 * PI / 2) - 100
		> potential_move)
		data->player->y -= potential_move;
}

void	wall_collision(t_data *data, double angle)
{
	if (data->is_horizontal[WIN_WIDTH / 2])
		adjust_player_x(data, angle);
	else
		adjust_player_y(data, angle);
}
