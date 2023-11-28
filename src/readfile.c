/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:57:25 by ekuchel           #+#    #+#             */
/*   Updated: 2023/11/28 20:12:38 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int open_map(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY, 0);
    if (fd < 0)
        ft_error("Error, open failed", -1, NULL);
    return(fd);
}

void    read_map(int fd, t_data *data)
{

}