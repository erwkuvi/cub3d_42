/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:30:39 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/12 14:35:53 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_data(t_data *d)
{
	d->game = ft_calloc(1, sizeof(t_game));
	d->player = ft_calloc(1, sizeof(t_player));
	d->img_game = ft_calloc(1, sizeof(t_img));
	d->rays_dist = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->rays_x = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->rays_y = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->ray_angle = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->is_horizontal = ft_calloc(1, sizeof(int) * WIN_WIDTH);
	d->distance = ft_calloc(1, sizeof(t_distance));
	init_game(d->game);
}

void	init_imgs(t_data *d)
{
	d->img_game->img = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->img_game->addr = (int *)mlx_get_data_addr(d->img_game->img, \
&d->img_game->bits_per_pixel, &d->img_game->line_length, &d->img_game->endian);
}
