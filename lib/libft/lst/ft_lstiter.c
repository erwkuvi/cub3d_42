/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:39:32 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:01:53 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// Iterates the list ’lst’ and applies the function ’f’
// on the content of each node.
void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst != 0)
	{
		tmp = lst->next;
		(f)(lst->content);
		lst = tmp;
	}
}
