/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:23:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:00:17 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:Allocates (with malloc(3)) and returns a string representing the
integer received as an argument. Negative numbers must be handled.
Return: The string representing the integer. NULL if the allocation fails.*/

int	digsize(int num)
{
	int	i;
	int	pos;

	pos = num;
	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		i++;
		pos *= -1;
	}
	while (pos != 0)
	{
		i++;
		pos /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	long	num;

	num = n;
	size = digsize(n);
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[size--] = '\0';
	if (num == 0)
		ptr[0] = '0';
	else if (num < 0)
	{
		ptr[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		ptr[size--] = (num % 10) + '0';
		num /= 10;
	}
	return (ptr);
}
