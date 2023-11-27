/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:57:38 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/02 11:03:53 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	ft_check(char value)
{
	int		i;
	char	*spec;

	i = 0;
	spec = "cspdiuxX%";
	while (spec[i])
	{
		if (value == spec[i])
			return (spec[i]);
		i++;
	}
	return (0);
}
