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
	i = -1;
	while (++i < 2)
	{
		fd[i] = open(filename, O_RDONLY, 0);
		if (fd[i] < 0)
			ft_error("open failed", -1);
	}
	if ((ft_strncmp(".cub", filename + name_len, 4)))
		ft_error("wrong format", -1);
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

void    wall_checker(char **map, int x, int y)
{
    if ((x == 0 || y == 0) || (map[y][x + 1] == ' ' || map[y][x + 1] == 0)
        || (map[y - 1][x] == ' ' || map[y - 1][x] == 0) || (map[y + 1][x] == ' '
        || map[y + 1][x] == 0) || (map[y][x - 1] == ' ' || map[y][x - 1] == 0))
    {
        ft_free_array(map);
        ft_error("invalid map format", -1);
    }
}

void    map_check(char **map, int x, int y)
{
    int player;

    player = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (valid_char_map(map[y][x]))
                if(++player > 1)
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

void    map_len_check(t_game *game)
{
    int     i;
    char    *tmp;
    char    *tmp2;
    (void) game;

    i = 0;
    while (game->map[i])
    {
//        printf("Strlen: %zu + Line:%s\n", ft_strlen(game->map[i]), game->map[i]);
        if (ft_strlen(game->map[i]) < game->x)
        {
            tmp = calloc(1, sizeof(char) * (1 + game->x - ft_strlen(game->map[i])));
            ft_memset(tmp, ' ', game->x - ft_strlen(game->map[i]));
            tmp[game->x - ft_strlen(game->map[i])] = 0;
            tmp2 = game->map[i];
            game->map[i] = ft_strjoin(tmp2, tmp);
            free(tmp2);
            free(tmp);
        }
        i++;
    }
    map_check(game->map, 0, 0);
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