/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:31:47 by ekuchel           #+#    #+#             */
/*   Updated: 2023/11/29 11:51:04 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void    ft_free_data(t_data *data)
{
        free(data);
}

int ft_error(char *message, int ret_val, t_data *data)
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
