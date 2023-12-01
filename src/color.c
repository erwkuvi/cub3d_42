/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:54:49 by ekuchel           #+#    #+#             */
/*   Updated: 2023/11/30 12:36:28 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static bool	ft_isnumber(char *str)
{
	char	*tmp;

	str = ft_strtrim(str, " ");
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

	if (n_instances(num, ',') != 2)
		ft_error("Invalid color format", -1, NULL);
	tmp = ft_split(num, ',');
	len = -1;
	while (tmp[++len])
		if (!ft_isnumber(tmp[len]))
			ft_error("Invalid color", -1, NULL);
	if (len != 3)
		ft_error("Invalid color format", -1, NULL);
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("Invalid color", -1, NULL);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	return ((r << 16) | (g << 8) | b);
}