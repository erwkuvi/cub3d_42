/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:30:40 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/03 18:53:29 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:locates the first occurrence of c (converted to a char)
in the string pointed to by s.  The terminating null character is
considered to be part of the string; therefore if c is `\0',
the functions locate the terminating `\0'.
Return: return a pointer to the located character, or NULL
if the character does not appear in the string.*/

char	*ft_strchr(const char *s, int c)
{
	char	*nullptr;
	int		i;

	nullptr = 0;
	i = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (((char *)s)[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	return (nullptr);
}
