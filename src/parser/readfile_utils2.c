/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:53:46 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 19:46:36 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

int	valid_char_map(char c)
{
	return (c == 'S' || c == 'W' || c == 'E' || c == 'N');
}

int	valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\n');
}

void	assign_type(t_data *d, char *tmp, int i, t_game *game)
{
	if (i == 0 && game->so_tex)
		ft_error(d, "multiple south sprites existing");
	else if (i == 1 && game->we_tex)
		ft_error(d, "multiple west sprites existing");
	else if (i == 2 && game->ea_tex)
		ft_error(d, "multiple east sprites existing");
	else if (i == 3 && game->no_tex)
		ft_error(d, "multiple north sprites existing");
	else if (i == 4 && game->floor_color != -1)
		ft_error(d, "multiple floor color values existing");
	else if (i == 5 && game->ceiling_color != -1)
		ft_error(d, "multiple ceiling color values existing");
	if (i == 0)
		game->so_tex = ft_strdup(tmp);
	if (i == 1)
		game->we_tex = ft_strdup(tmp);
	if (i == 2)
		game->ea_tex = ft_strdup(tmp);
	if (i == 3)
		game->no_tex = ft_strdup(tmp);
	if (i == 4)
		game->floor_color = get_rgb(d, tmp);
	if (i == 5)
		game->ceiling_color = get_rgb(d, tmp);
}
