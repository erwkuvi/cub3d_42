/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:39:02 by ekuchel           #+#    #+#             */
/*   Updated: 2023/09/19 13:04:49 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:locates the first occurrence of the null-terminated string
needle in the string haystack, where not more than len characters
are searched.  Characters that appear after a `\0' character are
not searched.  Since the strnstr() function is a FreeBSD specific
API, it should only be used when portability is not a concern.

Return: If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the
first character of the first occurrence of needle is returned.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*ptr;

	i = 0;
	ptr = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0] && len - i >= needle_len)
			if (ft_memcmp(haystack + i, needle, needle_len) == 0)
				return ((char *) haystack + i);
		i++;
	}
	return (ptr);
}
