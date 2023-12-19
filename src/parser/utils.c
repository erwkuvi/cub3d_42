/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/10 15:03:21 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	n_instances(char *str, char c)
{
	int	i;
	int	inst;

	i = -1;
	inst = 0;
	while (str[++i])
	{
		if (str[i] == c)
			inst++;
	}
	return (inst);
}

void	init_game(t_game *game)
{
	game->map = NULL;
	game->y = 0;
	game->x = 0;
	game->no_tex = NULL;
	game->so_tex = NULL;
	game->we_tex = NULL;
	game->ea_tex = NULL;
	game->floor_color = -1;
	game->ceiling_color = -1;
}
