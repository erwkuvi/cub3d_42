/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/15 18:08:42 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

int	frames(t_data *data)
{
	change_position(data);
	get_distance(data);
	draw_game(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		*fd;
	t_data	*d;

	d = calloc(1, sizeof(t_data));
	init_data(d);
	fd = open_map(d, argc, argv[1]);
	read_map(d, fd, d->game);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	check_textures(d);
	get_player_pos(d);
	init_imgs(d);
	mlx_loop_hook(d->mlx, frames, d);
	mlx_hook(d->win, 2, 0, &key_handler, d);
	mlx_hook(d->win, 3, 0, &key_release, d);
	mlx_hook(d->win, 17, 0, &ft_clean, d);
	mlx_loop(d->mlx);
	ft_clean(d);
	return (0);
}
