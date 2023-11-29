/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:57:25 by ekuchel           #+#    #+#             */
/*   Updated: 2023/11/29 16:33:59 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int  ft_texcheck(int fd, t_map map);

int open_map(char *filename)
{
    int fd;
    int name_len;

    name_len = ft_strlen(filename) - 4;
    fd = open(filename, O_RDONLY, 0);
    if (fd < 0)
        ft_error("Error, open failed", -1, NULL);
    if ((ft_strncmp(".cub", filename + name_len, 4)))
        ft_error("Error, wrong format", -1, NULL);
    return(fd);
}

static void ft_checkfile(int fd, t_map map)
{
    //int texcheck;
    //int colorcheck;

    ft_texcheck(fd, map);
    /*colorcheck = ft_colorcheck(fd, map);
    if (texcheck && colorcheck)
        ft_mapcheck (fd, map;*/
}

void    read_map(int *fd, t_map *map)
{
    char    *line;

    get_next_line(*fd, &line);
    while(ft_strlen(line) == 0)
    {
        get_next_line(*fd, &line);

    }
    ft_checkfile(*fd, *map);
}


void    check4sprites(int fd)
{
    char *line;

    printf("inside check4sprites\n");
    while (get_next_line(fd, &line))
    {
        printf("%s", line);
        free(line);
    }
    /* int     i;
     int    so;
     int    we;
     int    ea;
     int    no;

     i = 0;
     so = 0;
     we = 0;
     ea = 0;
     no = 0;
     while (line[i])
     {
         if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == 32)
             so++;
         else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == 32)
             so++;
         else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == 32)
             so++;
         else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == 32)
             so++;
         i++;
     }*/
}

static int  ft_texcheck(int fd, t_map map)
{
    char    *line;
    int     i;

    i = 0;
    (void) map;
    while (i < 2)
    {
        get_next_line(fd, &line);
        printf("%s", line);
        free(line);
        i++;
    }
    check4sprites(fd);
    return (0);
}

void     ft_mapcheck(int fd, t_map map)
{
    int     i;
    char    *line;

    i = 0;
    (void) map;
    while(get_next_line(fd, &line))
    {
        printf("%s", line);
        free(line);
        i++;
    }
    printf("number of lines: %d\n", i);
}



