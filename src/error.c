/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:31:47 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/01 13:44:51 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_free_data(t_data *data)
{
	free(data);
}

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_error(char *message, int ret_val, t_data *data)
{
	ft_putendl_fd(message, 2);
	if (ret_val < 0)
	{
		if (data)
			ft_free_data(data);
		exit(1);
	}
	return (ret_val);
}
