/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:54:49 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 19:33:27 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_isnumber(char *str)
{
	char	*tmp;

	if (!str)
		return (FALSE);
	str = ft_strtrim(str, EMPTY_SPACES);
	tmp = str;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			free(str);
			return (FALSE);
		}
		str++;
	}
	free(tmp);
	return (TRUE);
}

int	ft_num_len(t_data *d, char **tmp)
{
	int	len;

	len = 0;
	while (tmp[len])
	{
		if (!ft_isnumber(tmp[len]))
		{
			ft_free_array(tmp);
			ft_error(d, "Invalid color format (not number)");
			return (-1);
		}
		len++;
	}
	return (len);
}

int	get_rgb(t_data *d, char *num)
{
	char	**tmp;
	char	*trimmed;
	int		r;
	int		g;
	int		b;

	if (n_instances(num, ',') != 2 || !num)
		ft_error(d, "Invalid color format");
	trimmed = ft_strtrim(num, EMPTY_SPACES);
	tmp = ft_split(trimmed, ',');
	free(trimmed);
	if (ft_num_len(d, tmp) != 3)
		return (ft_free_array(tmp), ft_error(d, "Invalid color format"), -1);
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_free_array(tmp), ft_error(d, "Invalid color"), -1);
	ft_free_array(tmp);
	return ((r << 16) | (g << 8) | b);
}
