/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:57:25 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/03 12:23:58 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

//static void	generate_map(int fd, char *str, t_game *game);
//static void	check_missing(t_game game);

int	open_map(char *filename)
{
	int	fd;
	int	name_len;

	name_len = ft_strlen(filename) - 4;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		ft_error("Error, open failed", -1, NULL);
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

//static void	generate_map(int fd, char *str, t_game *game)
//{
//	(void) game;
//}
//
//static void	check_missing(t_game game)
//{
//	(void) game;
//}
void	get_xy_map(int fd, char *line, t_game *game)
{
	int		y;
	int		x;
	char	*tmp;

	y = 1;
	x = 0;
	(void) line; 
	(void) game;
	printf("%s", line);
	while (get_next_line(fd, &tmp))
	{
		y++;	
		printf("%s", tmp);
		free (tmp);
	}
		printf("Height: %d\n", y);
		printf("width: %d\n", x);
}

void	read_map(int *fd, t_game *game)
{
	char	*line;

	while (get_next_line(*fd, &line))
	{
		if (!empty_line(line) && valid_type(line))
			check_type(line, game);
		else if (!empty_line(line) && !valid_type(line))
			break ;
		free(line);
	}
	get_xy_map(*fd, line, game);
	free(line);
	while (get_next_line(*fd, &line))
	{
		printf("%s", line);
	}
	
//	check_missing(*game);
//	generate_map(*fd, line, game);
	close(*fd);
}
