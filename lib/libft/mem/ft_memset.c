/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:03:37 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:01:14 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc: writes len bytes of value c (converted to an
unsigned char) to the string b.
Return: The memset() function returns its first argument.*/

void	*ft_memset(void *b, int c, size_t len )
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)b;
	while (i < len)
	{
		temp [i] = c;
		i++;
	}
	b = temp;
	return (b);
}
