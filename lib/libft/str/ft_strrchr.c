/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:14:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 09:55:58 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:The strrchr() function is identical to strchr(), except it locates
the last occurrence of c.
Return: return a pointer to the located character, or NULL
if the character does not appear in the string.*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if ((char) c == '\0')
		return ((char *) s + ft_strlen(s));
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
