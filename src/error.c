/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:10:47 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/09 14:06:39 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_free_game(t_data *data)
{
	free(data->game);
	free(data->rays_dist);
	free(data->ray_angle);
	free(data->rays_x);
	free(data->rays_y);
	free(data->is_horizontal);
	free(data->player);
//	if (data -> win)
//	{
//		mlx_destroy_image(data->mlx, data->img);
//		mlx_destroy_window(data->mlx, data->win);
//		free(data->mlx);
//	}
	exit(0);
}

int	ft_free(t_data *d)
{
	static t_data	*data = NULL;

	if (data == NULL)
		return (data = d, 0);
//	if (data->sprite)
//	{
//		if (data -> sprite -> west && data -> sprite -> west ->is_loaded)
//			mlx_destroy_image(data->mlx, data -> sprite -> west -> img);
//		if (data -> sprite -> north && data -> sprite -> north ->is_loaded)
//			mlx_destroy_image(data->mlx, data -> sprite -> north -> img);
//		if (data -> sprite -> south && data -> sprite -> south ->is_loaded)
//			mlx_destroy_image(data->mlx, data -> sprite -> south -> img);
//		if (data -> sprite -> east && data -> sprite -> east ->is_loaded)
//			mlx_destroy_image(data->mlx, data -> sprite -> east -> img);
//		if (data -> player -> p_img)
//			mlx_destroy_image(data->mlx, data -> player -> p_img);
//		if (data -> img_game)
//			mlx_destroy_image(data->mlx, data -> img_game);
//		free(data -> sprite);
//	}
	ft_free_game(data);
	return (0);
}

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_error(char *message, int ret_val)
{
	ft_putstr_fd("Error, ", 2);
	ft_putendl_fd(message, 2);
	ft_free(NULL);
	if (ret_val < 0)
		exit(1);
	return (ret_val);
}
