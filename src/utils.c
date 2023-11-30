/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/11/30 18:05:22 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	instances(char *str, char c)
{
	int	i;
	int	inst;

	i = -1;
	inst = 0;
	while (str[++i])
	{
		if (str[i] == c)
			inst++;
	}
	return (inst);
}

bool	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}