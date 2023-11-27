/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:26:31 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/02 11:03:53 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len += ft_printfc('%');
	else if (format == 'c')
		len += ft_printfc(va_arg(args, int));
	else if (format == 's')
		len += ft_printfs(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_printfd(va_arg(args, int));
	else if (format == 'u')
		len += ft_printfu(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_printfx(va_arg(args, unsigned int), (char) format);
	else if (format == 'p')
		len += ft_printfp(va_arg(args, unsigned long int));
	return (len);
}
