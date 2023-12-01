/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:29:12 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/01 15:22:15 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/** @brief Compares 2 strings not more than n characters, characters
that appear after a `\0' character are not compared.
 Return: Zero if both strings are the same.

 * @param s1&s2 Strings to compare.
 * @param n number of characters to compare. */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	unsigned char		*str2;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	if (!s1 || !s2)
		return (1);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
