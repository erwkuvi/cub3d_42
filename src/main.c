/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:45 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/07 19:04:56 by ekuchel          ###   ########.fr       */
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
    data->mlx = mlx_init();
    data->win = mlx_new_window(data.mlx, 1200, 720, "cub3d");

}

void	print_values(t_data data)
{
	printf("SO: %s\n", data.game->so_tex);
	printf("WE: %s\n", data.game->we_tex);
	printf("EA: %s\n", data.game->ea_tex);
	printf("NO: %s\n", data.game->no_tex);
	printf("Floor color: %d\n", data.game->floor_color);
	printf("Ceiling color: %d\n", data.game->ceiling_color);
	printf("Map Values:\n\n");
	printf("Width: %zu\n", data.game->x);
	printf("Height: %d\n", data.game->y);

    if (data.game->map)
    {
        int i = 0;
        while (i < data.game->y) {
            printf("%s", data.game->map[i]);
            i++;
            printf("\n%d\n", i);
        }
    }
    printf("%zu\n", ft_strlen(data.game->map[0]));
}


int	main(int argc, char **argv)
{
	int		*fd;
	t_data	data;

	if (argc == 2)
	{
		fd = open_map(argv[1]);
		init_data(&data);
		read_map(fd, data.game);

		print_values(data);
//		ft_cub3d(&data);
	}
	else
		return (ft_error("wrong arguments amount", 1));
	return (0);
}
