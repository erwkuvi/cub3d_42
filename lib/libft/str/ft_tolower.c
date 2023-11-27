/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:13:02 by ekuchel           #+#    #+#             */
/*   Updated: 2023/08/14 11:23:22 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Desc: converts a lower-case letter to the corre-
sponding upper-case letter.  The argument must be representable as
an unsigned char or the value of EOF.
Return:If the argument is a lower-case letter, the toupper() function
returns the corresponding upper-case letter if there is one; other-
wise, the argument is returned unchanged.*/

int	ft_tolower(int c)
{
	if ((c >= 65) && (c <= 90))
		c += 32;
	return (c);
}
