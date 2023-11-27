/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:02:59 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 09:54:46 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:Applies the function ’f’ to each character of the string ’s’,
and passing its index as first argument to create a new string
(with malloc(3)) resulting from successive applications of ’f’.
Return:The string created from the successive applications of ’f’.
Returns NULL if the allocation fails.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	ptr = 0;
	i = 0;
	if (!s)
		return (ptr);
	ptr = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!ptr)
		return (ptr);
	while (s[i] != '\0')
	{
		ptr[i] = f(i, (int)s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
