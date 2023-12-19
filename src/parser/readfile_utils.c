/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:48:46 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/11 20:27:31 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	empty_char(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

int	valid_char(char c)
{
	return (c == 'S' || c == 'W' || c == 'E'
		|| c == 'N' || c == 'F' || c == 'C');
}

int	valid_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!valid_map_char(line[i]))
			return (FALSE);
	}
	return (TRUE);
}

int	valid_type(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (valid_char(str[i]))
			return (TRUE);
	}
	return (FALSE);
}

int	empty_line(char *str)
{
	while (*str)
	{
		if (!empty_char(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
