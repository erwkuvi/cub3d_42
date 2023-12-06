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

bool    empty_char(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

bool    valid_char(char c)
{
    return (c == 'S' || c == 'W' || c == 'E' || c == 'N' || c == 'F' || c == 'C');
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

