/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:15:52 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:00:58 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:locates the first occurrence of c (converted to an unsigned char)
in string s.
Return: returns a pointer to the byte located, or NULL if no such
byte exists within n bytes.*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == ((unsigned char)c))
			return ((void *)s + i);
		i++;
	}
	return (0);
}
