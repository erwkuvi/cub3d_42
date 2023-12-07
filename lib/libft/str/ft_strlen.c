/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:54:12 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/07 16:30:28 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc: computes the length of the string s.  The strnlen() function
attempts to compute the length of s, but never scans beyond the
first maxlen bytes of s.
Returns: returns the number of characters that precede the terminating
NUL charactern*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if (!s[i])
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
