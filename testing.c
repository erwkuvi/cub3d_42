/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:52:10 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/02 12:23:01 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int	main(void)
{
    int fd;
    char *line;

    line = NULL;
    fd = open("test.cub", O_RDONLY, 0);
    while (get_next_line(fd, &line))
    {
        if (empty_line(line))
            printf("EL: %s", line);
        else if (!empty_line(line))
            printf("NotEL: %s", line);
        free (line);
    }
	return (0);
}
