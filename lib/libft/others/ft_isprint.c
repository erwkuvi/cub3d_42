/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:33:18 by ekuchel           #+#    #+#             */
/*   Updated: 2023/03/03 16:33:12 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Desc: tests for any printing character, including space (` ').
The value of the argument must be representable as an unsigned
char or the value of EOF.*/

int	ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (1);
	return (0);
}
