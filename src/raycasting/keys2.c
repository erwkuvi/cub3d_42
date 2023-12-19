/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:43:52 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 19:44:22 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_handler(int key, t_data *d)
{
	if (key == ESC)
		ft_clean(d);
	if (key == W || key == UP)
		d->player->walk_direction = 1;
	if (key == S || key == DOWN)
		d->player->walk_direction = -1;
	if (key == A)
		d->player->turn_direction = 1;
	if (key == D)
		d->player->turn_direction = -1;
	if (key == LEFT)
		d->player->rotation_direction = 1;
	if (key == RIGHT)
		d->player->rotation_direction = -1;
	return (0);
}

int	key_release(int key, t_data *d)
{
	if (key == W || key == S || key == UP || key == DOWN)
		d->player->walk_direction = 0;
	if (key == A || key == D)
		d->player->turn_direction = 0;
	if (key == LEFT || key == RIGHT)
		d->player->rotation_direction = 0;
	return (0);
}
