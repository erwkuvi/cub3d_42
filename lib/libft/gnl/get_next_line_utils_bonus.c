/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:36:14 by ekuchel           #+#    #+#             */
/*   Updated: 2023/12/01 19:03:43 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
