/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:46 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/06 14:10:40 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	upto_nonempty(char *line)
{
	int	i;

	i = 0;
	while (!ft_strchr(VALID_TYPE, line[i]))
		i++;
	return (i);
}

int	upto_empty(char *line)
{
	int	i;

	i = 0;
	while (!ft_strchr(" \t", line[i]))
		i++;
	return (i);
}

bool    empty_char(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

bool    valid_char(char c)
{
    return (c == 'S' || c == 'W' || c == 'E' || c == 'N' || c == 'F' || c == 'C');
}

bool    valid_map_char(char c)
{
    return (c == '0' || c == '1' || c == 'N' || c == 'S'
            || c == 'E' || c == 'W' || c == ' ' || c == '\n');
}

bool    valid_map(char *line)
{
    int	i;

    i = -1;
    while (line[++i])
    {
        if (!valid_map_char(line[i]))
            return (false);
    }
    return (true);
}

bool	valid_type(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (valid_char(str[i]))
			return (true);
	}
	return (false);
}

bool	empty_line(char *str)
{
	while (*str)
    {
        if (!empty_char(*str))
            return (false);
		str++;
    }
	return (true);
}

void	assign_type(char *tmp, int i, t_game *game)
{
	if (i == 0 && game->so_tex)
		ft_error("Error, multiple south sprites existing", -1, NULL);
	else if (i == 1 && game->we_tex)
		ft_error("Error, multiple west sprites existing", -1, NULL);
	else if (i == 2 && game->ea_tex)
		ft_error("Error, multiple east sprites existing", -1, NULL);
	else if (i == 3 && game->no_tex)
		ft_error("Error, multiple north sprites existing", -1, NULL);
	else if (i == 4 && game->floor_color != -1)
		ft_error("Error, multiple floor color values existing", -1, NULL);
	else if (i == 5 && game->ceiling_color != -1)
		ft_error("Error, multiple ceiling color values existing", -1, NULL);
	if (i == 0)
		game->so_tex = ft_strdup(tmp);
	if (i == 1)
		game->we_tex = ft_strdup(tmp);
	if (i == 2)
		game->ea_tex = ft_strdup(tmp);
	if (i == 3)
		game->no_tex = ft_strdup(tmp);
	if (i == 4)
		game->floor_color = get_rgb(tmp);
	if (i == 5)
		game->ceiling_color = get_rgb(tmp);
}