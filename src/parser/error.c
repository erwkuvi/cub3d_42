/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:10:47 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 19:36:03 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_game(t_game *game)
{
	if (game->map)
		ft_free_array(game->map);
	if (game->no_tex)
		free(game->no_tex);
	if (game->so_tex)
		free(game->so_tex);
	if (game->we_tex)
		free(game->we_tex);
	if (game->ea_tex)
		free(game->ea_tex);
	free(game);
}

void	ft_clear_res(t_data *d)
{
	free(d->rays_dist);
	free(d->ray_angle);
	free(d->rays_x);
	free(d->rays_y);
	free(d->is_horizontal);
	free(d->player);
	free(d->distance);
	free_game(d->game);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	free(d);
	exit(EXIT_SUCCESS);
}

int	ft_clean(t_data *d)
{
	if (!d)
		return (EXIT_FAILURE);
	if (d->sprite)
	{
		if (d->sprite->west && d->sprite->west ->img_loaded)
			mlx_destroy_image(d->mlx, d->sprite->west->img);
		if (d->sprite->north && d->sprite->north->img_loaded)
			mlx_destroy_image(d->mlx, d->sprite->north->img);
		if (d->sprite->south && d->sprite->south->img_loaded)
			mlx_destroy_image(d->mlx, d->sprite->south->img);
		if (d->sprite->east && d->sprite->east->img_loaded)
			mlx_destroy_image(d->mlx, d->sprite->east->img);
		if (d->img_game)
			mlx_destroy_image(d->mlx, d->img_game);
		free(d->sprite->east);
		free(d->sprite->north);
		free(d->sprite->west);
		free(d->sprite->south);
		free(d->sprite);
	}
	ft_clear_res(d);
	return (0);
}

void	ft_error(t_data *d, char *message)
{
	ft_putstr_fd("Error, ", 2);
	ft_putendl_fd(message, 2);
	free_game(d->game);
	exit (EXIT_FAILURE);
}
