/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:18:33 by ekuchel           #+#    #+#             */
/*   Updated: 2023/05/04 10:02:05 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/**
// Iterates the list ’lst’ and applies the function ’f’ on the content of
// each node. Creates a new list resulting of the successive applications
// of the function ’f’.The ’del’ function is used to delete the content of a
// node if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;

	if (!lst || !f)
		return (0);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
		return (0);
	lst = lst->next;
	while (lst != 0)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
