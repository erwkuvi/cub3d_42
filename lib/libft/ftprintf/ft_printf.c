/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:01:24 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/02 11:03:53 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]))
			len += ft_format(args, str[i++ + 1]);
		else if (str[i] == '%' && !ft_check(str[i + 1]))
		{
			write(1, "error\n", 6);
			return (len);
		}
		else
		{
			len += ft_printfc(str[i]);
		}
		i++;
	}
	va_end (args);
	return (len);
}

// int	main(void)
// {
// 	// int	a;
// 	// a = -10;
// 	// void			*b;
// 	// char	*string[20] = "This is a string";

// 	// printf("%d\n", printf("%x", 9223372036854775807LL));
// 	ft_printf("%d\n", ft_printf("%x\n", 9223372036854775807LL));
// 	// ft_printf("%d\n", ft_printf("%x", LONG_MAX));
// 	return (0);
// }
