/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/11/28 20:11:23 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
    int     fd;
    t_data  data;

    if (argc == 2)
    {
        fd = open_map(argv[1]);
        read_map(fd, &data);
    }
    else
    {
        return (ft_error("Error, wrong arguments amount", 1));
    }
	return (0);
}
