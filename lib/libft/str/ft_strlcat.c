/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:59:37 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/03 18:52:41 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Desc:appends string src to the end of dst.  It will append at
most dstsize - strlen(dst) - 1 characters.  It will then NUL-termi-nate,
unless dstsize is 0 or the original dst string was longer than
dstsize (in practice this should not happen as it means that either
dstsize is incorrect or that dst is not a proper string).
Return: For strlcat() that means the initial length of dst plus
the length of src. For strlcat() that means the initial length of dst plus
the length of src.*/

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	len = ft_strlen(src);
	i = 0;
	while ((i + dst_len + 1 < dstsize) && (src[i] != '\0'))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dst_len >= dstsize)
		return (dstsize + len);
	return (dst_len + len);
}
