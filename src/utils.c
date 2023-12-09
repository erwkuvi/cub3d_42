/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/09 15:40:56 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	n_instances(char *str, char c)
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
