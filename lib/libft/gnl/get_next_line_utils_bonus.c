/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:36:14 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/05 15:55:51 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((char *)s1);
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	if (!s1)
		return (NULL);
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	unsigned int	len;
	char			*str;

	if (!s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	len = ft_strlen(s1);
	ft_strcpy(&str[len], s2);
	free(s1);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*nullptr;
	int		i;

	nullptr = 0;
	i = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (((char *)s)[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	return (nullptr);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*ptr;
// 	size_t	i;

// 	if (s == NULL)
// 		return (NULL);
// 	if (start >= (unsigned int)ft_strlen(s))
// 	{
// 		start = 0;
// 		len = 0;
// 	}
// 	if (len > ft_strlen(s) - (size_t)start)
// 		len = ft_strlen(s) - (size_t)start;
// 	ptr = (char *)malloc((len + 1) * sizeof(char));
// 	if (ptr == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		ptr[i] = ((char *)s)[(size_t)start + i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (free((char *)s), ptr);
// }
