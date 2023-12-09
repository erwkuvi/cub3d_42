/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:57:02 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/09 15:40:40 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	map_check(char **map, int x, int y)
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
					ft_error("more than one player", -1);
			if (!valid_map_char(map[y][x]))
				ft_error("wrong map format", -1);
			if (map[y][x] == '0' || valid_char_map(map[y][x]))
				wall_checker(map, x, y);
			x++;
		}
		y++;
	}
	if (!player)
		ft_error("no player available", -1);
}

void	check_type(char *line, t_game *game)
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
			tmp = ft_strdup(ft_strtrim(line + j + k, EMPTY_SPACES));
			assign_type(tmp, i, game);
			break ;
		}
	}
	if (tmp)
		free(tmp);
	ft_free_array(element);
}

void	wall_checker(char **map, int x, int y)
{
	if ((x == 0 || y == 0) || (map[y][x + 1] == ' ' || map[y][x + 1] == 0)
		|| (map[y - 1][x] == ' ' || map[y - 1][x] == 0) || (map[y + 1][x] == ' '
		|| map[y + 1][x] == 0) || (map[y][x - 1] == ' ' || map[y][x - 1] == 0))
	{
		ft_free_array(map);
		ft_error("invalid map format", -1);
	}
}

void	check_missing(t_game *game)
{
	if (!game->ea_tex || !game->no_tex || !game->so_tex
		|| !game->we_tex)
		ft_error("texture are missing", -1);
	if (game->floor_color == -1 || game->ceiling_color == -1)
		ft_error("ceiling/floor color missing", -1);
	if (!game->y)
		ft_error("map missing", -1);
}

void	map_len_check(t_game *game)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	size_t	len;

	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (ft_strlen(game->map[i]) < game->x)
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
	map_check(game->map, 0, 0);
}
