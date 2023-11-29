/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/11/29 15:38:33 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void    init_data(t_data *data)
{
    data->map = calloc(1, sizeof(t_map));
    data->img = calloc(1, sizeof(t_img));
}

void    ft_cub3d(t_data *data)
{
    (void) data;
    printf("Inside ft_cub3d\n");
}

int	main(int argc, char **argv)
{
    int     fd;
    t_data  data;

    if (argc == 2)
    {
        fd = open_map(argv[1]);
        init_data(&data);
        read_map(&fd, data.map);
        ft_cub3d(&data);
    }
    else
        return (ft_error("Error, wrong arguments amount", 1, &data));
    return (0);
}
