/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/02 14:04:31 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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

void	init_data(t_data *data)
{
	data->game = calloc(1, sizeof(t_game));
	data->img = calloc(1, sizeof(t_img));
	init_game(data->game);
}

void	ft_cub3d(t_data *data)
{
	(void) data;
	printf("Inside ft_cub3d\n");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc == 2)
	{
		fd = open_map(argv[1]);
		init_data(&data);
		read_map(&fd, data.game);
		printf("SO:%s\n", data.game->so_tex);
		printf("WE:%s\n", data.game->we_tex);
		printf("EA:%s\n", data.game->ea_tex);
		printf("NO:%s\n", data.game->no_tex);
		printf("F:%d\n", data.game->floor_color);
		printf("C:%d\n", data.game->ceiling_color);
		ft_cub3d(&data);
	}
	else
		return (ft_error("Error, wrong arguments amount", 1, &data));
	return (0);
}
