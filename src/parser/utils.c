/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/21 16:46:36 by ekuchel          ###   ########.fr       */
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

int	check_dir(char *filename)
{
	int		nb;
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(char));
	nb = read(fd, buf, 1);
	if (nb <= 0)
		return (1);
	free(buf);
	return (0);
}
// int	check_player_wall(char **map, int y, int x)
// {
// 	int	og_y;
// 	int	og_x;
// 	int	check;

// 	check = 0;
// 	og_y = y;
// 	og_x = x;
// 	while (y > 0 && ft_strchr("01", map[--y][x]))
// 		if (map[y][x] == '1')
// 			check++;
// 	y = og_y;
// 	while (map[y + 1] && ft_strchr("01", map[++y][x]))
// 		if (map[y][x] == '1')
// 			check++;
// 	y = og_y;
// 	while (x > 0 && ft_strchr("01", map[y][--x]))
// 		if (map[y][x] == '1')
// 			check++;
// 	x = og_x;
// 	while (map[y][x + 1] && ft_strchr("01", map[y][++x]))
// 		if (map[y][x] == '1')
// 			check++;
// 	if (check == 4)
// 		return (1);
// 	return (0);
// }
