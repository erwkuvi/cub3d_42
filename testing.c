/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:52:10 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/01 17:22:29 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

int	upto_empty(char *line)
{
	int	i;

	i = 0;
	while (!ft_strchr(" \t", line[i]))
		i++;
	return (i);
}

int upto_nonempty(char *line)
{
	int	i;

	i = 0;
	while (!ft_strchr(VALID_TYPE, line[i]))
		i++;
	return (i);
}

int	main(void)
{
	int		j;
	int		i;
	int		k;
	char	**element;
	char	**tmp;
	char 	*str = "      	 	 	 	F 		  		  105,90,70				";

	element = ft_split("SO,WE,EA,NO,F,C", ',');
	tmp = malloc(sizeof(char *) * 2);
	j = upto_nonempty(str);
	k = upto_empty(str + j);
	i = -1;
	while (element[++i])
	{
		if (!ft_strncmp(element[i], str + j, k))
		{
			tmp[0] = ft_strdup(element[i]);
			tmp[1] = ft_strdup(ft_strtrim(str + j + k, " \t"));
			printf("tmp 0: %s\n", tmp[0]);
			printf("tmp 1: %s\n", tmp[1]);
			break;
//			assign_type(element, i, line, game);
		}
	}
	ft_free_array(element);
	return (0);
}
