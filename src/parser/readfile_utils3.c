/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:57:02 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 20:01:44 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_check(t_data *d, char **map, int x, int y)
{
	int	player;

	player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (valid_char_map(map[y][x]))
				if (++player > 1)
					ft_error(d, "more than one player");
			if (!valid_map_char(map[y][x]))
				ft_error(d, "wrong map format");
			if (map[y][x] == '0' || valid_char_map(map[y][x]))
				wall_checker(d, map, x, y);
			x++;
		}
		y++;
	}
	if (!player)
		ft_error(d, "no player available");
}

void	check_type(t_data *d, char *line, t_game *game)
{
	int		j;
	int		i;
	int		k;
	char	**element;
	char	*tmp;

	element = ft_split("SO,WE,EA,NO,F,C", ',');
	tmp = NULL;
	j = upto_nonempty(line);
	k = upto_empty(line + j);
	i = -1;
	while (element[++i])
	{
		if (!ft_strncmp(element[i], line + j, k))
		{
			tmp = ft_strtrim(line + j + k, EMPTY_SPACES);
			assign_type(d, tmp, i, game);
			break ;
		}
	}
	if (tmp)
		free(tmp);
	ft_free_array(element);
}

void	wall_checker(t_data *d, char **map, int x, int y)
{
	if ((x == 0 || y == 0) || (map[y][x + 1] == ' ' || map[y][x + 1] == 0)
		|| (map[y - 1][x] == ' ' || map[y - 1][x] == 0) || (map[y + 1][x] == ' '
		|| map[y + 1][x] == 0) || (map[y][x - 1] == ' ' || map[y][x - 1] == 0))
	{
		ft_error(d, "invalid map format");
	}
}

void	check_missing(t_data *d, t_game *game)
{
	if (!game->ea_tex || !game->no_tex || !game->so_tex
		|| !game->we_tex)
		ft_error(d, "one or more textures are missing");
	if (game->floor_color == -1 || game->ceiling_color == -1)
		ft_error(d, "ceiling/floor color missing");
	if (!game->y)
		ft_error(d, "map missing");
}

void	map_len_check(t_data *d, t_game *game)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	int		len;

	i = 0;
	while (game->map[i])
	{
		len = (int)ft_strlen(game->map[i]);
		if ((int)ft_strlen(game->map[i]) < game->x)
		{
			tmp = calloc(1, sizeof(char) * (1 + game->x - len));
			ft_memset(tmp, ' ', game->x - len);
			tmp[game->x - len] = 0;
			tmp2 = game->map[i];
			game->map[i] = ft_strjoin(tmp2, tmp);
			free(tmp2);
			free(tmp);
		}
		i++;
	}
	map_check(d, game->map, 0, 0);
}
