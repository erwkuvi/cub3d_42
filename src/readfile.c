/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:45 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/07 15:07:24 by ekuchel          ###   ########.fr       */
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
        ft_error("Memory allocation failed", -1, NULL, NULL);
	name_len = ft_strlen(filename) - 4;
	i = -1;
	while (++i < 2)
	{
		fd[i] = open(filename, O_RDONLY, 0);
		if (fd[i] < 0)
			ft_error("Error, open failed", -1, NULL, NULL);
	}
	if ((ft_strncmp(".cub", filename + name_len, 4)))
		ft_error("Error, wrong format", -1, NULL, NULL);
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

void    wall_checker(char **map, int x, int y)
{
    if ((x == 0 || y == 0) || (map[y][x + 1] == ' ' || map[y][x + 1] == 0)
        || (map[y - 1][x] == ' ' || map[y - 1][x] == 0) || (map[y + 1][x] == ' '
        || map[y + 1][x] == 0) || (map[y][x - 1] == ' ' || map[y][x - 1] == 0))
    {
        ft_free_array(map);
        ft_error("Error, invalid map format", -1, NULL, NULL);
    }
}

void    map_check(char **map, int x, int y)
{
    int player;

    player = 0;
    while (map[y])
    {
        while (map[y][x])
        {
            if (valid_char_map(map[y][x]))
                if(++player > 1)
                    ft_error("Error, more than one player", -1, NULL, NULL);
            if (!valid_map_char(map[y][x]))
                ft_error("Error, wrong map format", -1, NULL, NULL);
            if (map[y][x] == '0' || valid_char_map(map[y][x]))
                wall_checker(map, x, y);
            x++;
        }
        y++;
    }
    if (!player)
        ft_error("Error, no player available", -1, NULL, NULL);
}

void    map_len_check(t_game *game, char **map)
{
    int     i;
//    char    *tmp;
//    char    *tmp2;
    (void) game;

    i = 0;
    while (map[i])
    {
//        if ((int)ft_strlen(map[i]) < game->x)
//        {
//            tmp = calloc(1, sizeof(char) * (1 + game->x - ft_strlen(map[i])));
//            ft_memset(tmp, ' ', game->x - ft_strlen(map[i]));
//            tmp[game->x - ft_strlen(map[i])] = '\0';
////            tmp2 = map[i];
//            map[i] = ft_strjoin(map[i], tmp);
////            free(tmp2);
//            free(tmp);
//        }
        i++;
    }
}

char	**generate_map(int fd, t_game *game)
{
	char	*line;
	char	**map;

	map = (char **)malloc(sizeof(char *) * game->y);
	if (map == NULL)
		ft_error("Error, map memory allocation failed", -1, NULL, game);
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

void	get_xy_map(int fd, char *line, t_game *game)
{
	int		line_len;

	if (!line)
		ft_error("Error, no map found", -1, NULL, game);
	if (valid_map(line))
        game->y = 1;
	game->x = ft_strlen(line);
	free(line);
	while (get_next_line(fd, &line))
	{
        if (valid_map(line))
        {
            line_len = ft_strlen(line);
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
    printf("%s", game->map[7]);
    printf("\n");
    int i = -1;
    while(game->map[0][++i])
        printf("%c", game->map[7][i]);
    printf("\n");
    map_len_check(game, game->map);
//    map_check(game->map, 0, 0);
	close(fd[1]);
}

void	check_missing(t_game *game)
{
	if (!game->ea_tex || !game->no_tex || !game->so_tex 
		|| !game->we_tex)
		ft_error("Error, texture are missing", -1, NULL, game);
	if (game->floor_color == -1 || game->ceiling_color == -1)
		ft_error("Error, ceiling/floor color missing", -1, NULL, game);
    if (!game->y)
        ft_error("Error, no map found", -1 ,NULL, game);
}