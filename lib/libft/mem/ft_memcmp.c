/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:12:56 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:01:02 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:compares byte string s1 against byte string s2. Both strings
are assumed to be n bytes long.
Return: returns zero if the two strings are identical, otherwise
returns the difference between the first two differing bytes (treated
as unsigned char values, so that `\200' is greater than `\0',
for example).  Zero-length strings are always identical.*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;
	size_t				i;

	cs1 = s1;
	cs2 = s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
