/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:22:53 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:01:10 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc: copies len bytes from string src to string dst.  The two strings
may overlap; the copy is always done in a non-destructive manner.
Return: returns the original value of dst.*/

void	*ft_memmove(void *des, const void *src, size_t n)
{
	size_t		i;

	if ((des == 0) && (src == 0))
		return (0);
	if (des < src)
	{
		i = 0;
		while (i < n)
		{
			*((char *)des + i) = *((char *)src + i);
			i++;
		}
		return (des);
	}
	while (n--)
		*((char *) des + n) = *((char *) src + n);
	return (des);
}
