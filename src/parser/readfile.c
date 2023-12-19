/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:45 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 19:37:16 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	*open_map(t_data *d, int argc, char *filename)
{
	int	*fd;
	int	name_len;
	int	i;

	if (argc != 2)
		ft_error(d, "argument error");
	fd = (int *)malloc(sizeof(int) * 2);
	if (fd == NULL)
		ft_error(d, "Memory allocation failed");
	name_len = ft_strlen(filename) - 4;
	if ((ft_strncmp(".cub", filename + name_len, 4)))
		ft_error(d, "wrong format");
	i = -1;
	while (++i < 2)
	{
		fd[i] = open(filename, O_RDONLY, 0);
		if (fd[i] < 0)
			ft_error(d, "open failed");
	}
	return (fd);
}

char	**allocate_map(t_data *d, int fd, char *line, t_game *game)
{
	int		i;
	char	**map;

	i = 1;
	map = calloc(1, sizeof(char *) * (game->y + 1));
	if (map == NULL)
		ft_error(d, "map memory allocation failed");
	map[0] = ft_strtrim(line, "\n");
	game->x = ft_strlen(map[0]);
	free(line);
	while (get_next_line(fd, &line) && i < game->y)
	{
		map[i] = ft_strtrim(line, "\n");
		if ((int_fast64_t)ft_strlen(map[i]) > game->x)
			game->x = (int)ft_strlen(map[i]);
		free (line);
		i++;
	}
	return (map);
}

char	**generate_map(t_data *d, int fd, t_game *game)
{
	char	*line;
	char	**map;

	map = NULL;
	while (get_next_line(fd, &line))
	{
		if (!empty_line(line) && !valid_type(line))
		{
			map = allocate_map(d, fd, line, game);
			break ;
		}
		free(line);
	}
	return (map);
}

void	get_height(t_data *d, int fd, char *line, t_game *game)
{
	if (!line)
		ft_error(d, "no map/height found");
	if (valid_map(line) && !empty_line(line))
		game->y = 1;
	free(line);
	while (get_next_line(fd, &line))
	{
		if (valid_map(line) && !empty_line(line))
		{
			free (line);
			game->y++;
			continue ;
		}
		free (line);
	}
}

void	read_map(t_data *d, int *fd, t_game *game)
{
	char	*line;

	while (get_next_line(fd[0], &line))
	{
		if (!empty_line(line) && valid_type(line))
			check_type(d, line, game);
		else if (!empty_line(line) && !valid_type(line))
			break ;
		free(line);
	}
	get_height(d, fd[0], line, game);
	close(fd[0]);
	check_missing(d, game);
	game->map = generate_map(d, fd[1], game);
	map_len_check(d, game);
	close(fd[1]);
}
