/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:33:06 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/02 11:03:53 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printfx_ptr(unsigned long int n, char c)
{
	int		len;
	char	*hex;

	len = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n < 16)
		len += ft_printfc(hex[n]);
	else
	{
		len += ft_printfx_ptr((n / 16), c);
		len += ft_printfx_ptr((n % 16), c);
	}
	return (len);
}

int	ft_printfp(unsigned long int n)
{
	int	len;

	len = 0;
	len += ft_printfs("0x");
	len += ft_printfx_ptr(n, 'x');
	return (len);
}
