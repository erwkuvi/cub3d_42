/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:41:08 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/05 15:59:50 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h>
// #include <fcntl.h>

char	*ft_str_storage(int fd, char *strholder)
{
	char		*buff;
	int			nb_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (NULL);
	nb_read = 1;
	while (nb_read)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free (buff);
			free (strholder);
			return (NULL);
		}
		buff[nb_read] = '\0';
		if (!strholder)
			strholder = ft_strdup("");
		strholder = ft_strjoin_gnl(strholder, buff);
		if (ft_strchr_gnl(buff, '\n'))
			break ;
	}
	free (buff);
	return (strholder);
}

char	*ft_substraction(char *strholder)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!strholder[i])
		return (NULL);
	while (strholder[i] != '\n' && strholder[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(*line) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (strholder[i] != '\n' && strholder[i])
	{
		line[i] = strholder[i];
		i++;
	}
	if (strholder[i] == '\n')
	{
		line[i] = strholder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_strholder(char *strholder)
{
	int		i;
	char	*newline;

	i = 0;
	while (strholder[i] != '\0' && strholder[i] != '\n')
		i++;
	if (!strholder[i])
	{
		free(strholder);
		return (NULL);
	}
	newline = malloc((ft_strlen(strholder) - i + 1) * sizeof(*newline));
	if (!newline)
		return (NULL);
	i++;
	newline = ft_strcpy(newline, &strholder[i]);
	return (free (strholder), newline);
}

int	get_next_line(int fd, char **line)
{
	static char	*strholder[400];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	strholder[fd] = ft_str_storage(fd, strholder[fd]);
	if (!strholder[fd])
		return (free(strholder[fd]), 0);
	*line = ft_substraction(strholder[fd]);
	strholder[fd] = ft_new_strholder(strholder[fd]);
	if (*line)
		return (1);
	return (0);
}
