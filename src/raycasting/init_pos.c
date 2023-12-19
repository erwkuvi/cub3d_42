/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:04:01 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/15 19:41:21 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_angle(t_data *data)
{
	if (data->player->cardinal_dir == 'N')
		data->player->angle = M_PI / 2;
	else if (data->player->cardinal_dir == 'W')
		data->player->angle = M_PI;
	else if (data->player->cardinal_dir == 'S')
		data->player->angle = 3 * (M_PI / 2);
	else if (data->player->cardinal_dir == 'E')
		data->player->angle = 2 * M_PI;
}

void	get_player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->game->map[y])
	{
		x = 0;
		while (data->game->map[y][x])
		{
			if (ft_strchr("NSEW", data->game->map[y][x]))
			{
				data->player->cardinal_dir = data->game->map[y][x];
				data->player->x = x * data->box_size + data->box_size / 2;
				data->player->y = y * data->box_size + data->box_size / 2;
			}
			x++;
		}
		y++;
	}
	init_angle(data);
	data->game->map_height = y;
	data->game->map_width = x;
}
