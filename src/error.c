/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:10:47 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/06 22:47:05 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:31:47 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/03 12:19:50 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void    ft_free_game(t_game *game)
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
}

void	ft_free_data(t_data *data)
{
    // ft_free_game(data->game);
	free(data);
}

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_error(char *message, int ret_val, t_data *data, t_game *game)
{
	ft_putendl_fd(message, 2);
    ft_free_game(game);
	if (ret_val < 0)
	{
		if (data)
			ft_free_data(data);
		exit(1);
	}
	return (ret_val);
}
