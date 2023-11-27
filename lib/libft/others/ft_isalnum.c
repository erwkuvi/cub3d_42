/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:58:09 by ekuchel           #+#    #+#             */
/*   Updated: 2023/03/03 16:31:11 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Desc: tests for any character for which isalpha(3) or isdigit(3) is true.
Return:function returns zero if the character tests false and returns
non-zero if the character tests true. */

int	ft_isalnum(int c)
{
	if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		|| (c >= 48 && c < 58))
		return (1);
	return (0);
}
