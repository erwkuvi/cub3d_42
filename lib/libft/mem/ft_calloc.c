/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:01:55 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:00:54 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc: The calloc() function contiguously allocates enough space for count
objects that are size bytes of memory each and returns a pointer to
the allocated memory.  The allocated memory is filled with bytes of
value zero.
Return: return a pointer to allocated memory. If there is an error,
they return a NULL pointer and set errno to ENOMEM.*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
