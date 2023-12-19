/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:17:01 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/15 17:35:57 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc: Allocates (with malloc(3)) and returns a copy of ’s1’ with the
characters specified in ’set’ removed from the beginning and the end
of the string.
Return: The trimmed string. NULL if the allocation fails.*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	ptr = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && (ft_strchr(set, *(s1 + i))))
		i++;
	while (s1[i] != '\0' && (ft_strchr(set, *(s1 + j))))
		j--;
	ptr = ft_substr(s1, i, ((j - i) + 1));
	return (ptr);
}
