/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:54:49 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/07 18:25:29 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

bool	ft_isnumber(char *str)
{
	char	*tmp;

	str = ft_strtrim(str, EMPTY_SPACES);
	tmp = str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	free(tmp);
	return (true);
}

int	get_rgb(char *num)
{
	char	**tmp;
	int		len;
	int		r;
	int		g;
	int		b;
    char    *trimmed;

	if (n_instances(num, ',') != 2)
		ft_error("Invalid color format", -1);
    trimmed = ft_strtrim(num, EMPTY_SPACES);
	tmp = ft_split(trimmed, ',');
    free(trimmed);
	len = -1;
	while (tmp[++len])
    {
		if (!ft_isnumber(tmp[len]))
			ft_error("Invalid color", -1);
    }
	if (len != 3)
		ft_error("Invalid color format", -1);
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("Invalid color", -1);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	return ((r << 16) | (g << 8) | b);
}