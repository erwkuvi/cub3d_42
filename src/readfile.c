/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:45 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/06 14:16:20 by ekuchel          ###   ########.fr       */
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
        ft_error("Memory allocation failed", -1, NULL);
	name_len = ft_strlen(filename) - 4;
	i = -1;
	while (++i < 2)
	{
		fd[i] = open(filename, O_RDONLY, 0);
		if (fd[i] < 0)
			ft_error("Error, open failed", -1, NULL);
	}
	if ((ft_strncmp(".cub", filename + name_len, 4)))
		ft_error("Error, wrong format", -1, NULL);	
	return (fd);
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

void	allocate_map(char **map, int fd, char *line, t_game *game)
{
	int	i;

	i = 1;
	map[0] = ft_strdup(line);
	free(line);
	while (get_next_line(fd, &line) && i < game->y)
	{
		map[i] = ft_strdup(line);
		free (line);
		i++;
	}
}

char	**generate_map(int fd, t_game *game)
{
	char	*line;
	char	**map;

	map = (char **)malloc(sizeof(char *) * game->y);
	if (map == NULL)
		ft_error("Error, map memory allocation failed", -1, NULL);
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

// static void	check_missing(t_game game)
// {
// 	(void) game;
// }

int	mapline_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	get_xy_map(int fd, char *line, t_game *game)
{
	int		line_len;

	if (!line)
		ft_error("Error, no map found", -1, NULL);
	if (valid_map(line))
        game->y = 1;
	game->x = mapline_len(line);
	free(line);
	while (get_next_line(fd, &line))
	{
        if (valid_map(line))
        {
            line_len = mapline_len(line);
            if (line_len > game->x)
                game->x = line_len;
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
	get_xy_map(fd[0], line, game);
	close(fd[0]);
	check_missing(game);
	game->map = generate_map(fd[1], game);
	close(fd[1]);
}

void	check_missing(t_game *game)
{
	if (!game->ea_tex || !game->no_tex || !game->so_tex 
		|| !game->we_tex)
		ft_error("Error, texture are missing", -1, NULL);
	if (game->floor_color == -1 || game->ceiling_color == -1)
		ft_error("Error, ceiling/floor color missing", -1, NULL);
    if (!game->y)
        ft_error("Error, no map found", -1 ,NULL);
}