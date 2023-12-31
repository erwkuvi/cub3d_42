/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:26:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/15 17:42:00 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc: Allocates (with malloc(3)) and returns an array of strings obtained
by splitting ’s’ using the character ’c’ as a delimiter.
The array must end with a NULL pointer.
Return:The array of new strings resulting from the split.
NULL if the allocation fails.*/

static int	ft_wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_wordcount(char *s, char c)
{
	int			count;
	int			i;

	count = 0;
	while (*s)
	{
		i = 0;
		while (*s && (*s == c))
			s++;
		i = ft_wordlen(s, c);
		s += i;
		if (i)
			count++;
	}
	return (count);
}

static char	*ft_strdupp(char *s, int n)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (n + 1));
	if (!dst)
		return (0);
	while (s[i] && i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**ft_makesplit(char const *s, char c, char **des, int size)
{
	int	j;
	int	i;

	j = 0;
	while (j < size)
	{
		while (*s == c)
			s++;
		i = ft_wordlen((char *)s, c);
		des[j] = ft_strdupp((char *)s, i);
		if (!des[j])
		{
			while (j > 0)
			{
				free(des[j - 1]);
				j--;
			}
			free(des);
			return (0);
		}
		s += i;
		j++;
	}
	des[size] = 0;
	return (des);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		return (0);
	size = ft_wordcount((char *)s, c);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	result = ft_makesplit(s, c, result, size);
	return (result);
}
