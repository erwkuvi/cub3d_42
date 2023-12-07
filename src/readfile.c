/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:45 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/07 18:40:45 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

//static void	check_missing(t_game game);

int	*open_map(char *filename)
{
	int *fd;
	int	name_len;
	int	i;

	fd = (int *)malloc(sizeof(int) * 2);
	if (fd == NULL)
        ft_error("Memory allocation failed", -1);
	name_len = ft_strlen(filename) - 4;
	if ((ft_strncmp(".cub", filename + name_len, 4)))
		ft_error("wrong format", -1);
	i = -1;
	while (++i < 2)
	{
		fd[i] = open(filename, O_RDONLY, 0);
		if (fd[i] < 0)
			ft_error("open failed", -1);
	}
	return (fd);
}

void	allocate_map(char **map, int fd, char *line, t_game *game)
{
	int	    i;

	i = 1;
	map[0] = ft_strdup(ft_strtrim(line, "\n"));
    game->x = ft_strlen(map[0]);
	free(line);
	while (get_next_line(fd, &line) && i < game->y)
	{
		map[i] = ft_strdup(ft_strtrim(line, "\n"));
        if (ft_strlen(map[i]) > game->x)
            game->x = ft_strlen(map[i]);
		free (line);
		i++;
	}
}

char	**generate_map(int fd, t_game *game)
{
	char    *line;
	char    **map;

    map = (char **)malloc(sizeof(char *) * game->y);
	if (map == NULL)
		ft_error("map memory allocation failed", -1);
	while (get_next_line(fd, &line))
	{
		if (!empty_line(line) && !valid_type(line))
		{
			allocate_map(map, fd, line, game);
			break ;
		}
		free(line);
	}
	return (map);
}

void	get_height(int fd, char *line, t_game *game)
{
	if (!line)
		ft_error("no map found", -1);
	if (valid_map(line))
        game->y = 1;
	free(line);
	while (get_next_line(fd, &line))
	{
        if (valid_map(line))
        {
            free (line);
            game->y++;
        }
        else
            break;
	}
}

void	read_map(int *fd, t_game *game)
{
	char	*line;

	while (get_next_line(fd[0], &line))
	{
		if (!empty_line(line) && valid_type(line))
			check_type(line, game);
		else if (!empty_line(line) && !valid_type(line))
			break ;
		free(line);
	}
	get_height(fd[0], line, game);
	close(fd[0]);
	check_missing(game);
	game->map = generate_map(fd[1], game);
    map_len_check(game);

	close(fd[1]);
}
