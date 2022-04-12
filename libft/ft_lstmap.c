/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:26:40 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/29 14:19:38 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delete_link(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*head;

	new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (NULL);
	new = f(new);
	head = new;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		if (!tmp)
		{
			ft_lstdel(&head, &delete_link);
			return (NULL);
		}
		tmp = f(tmp);
		new->next = tmp;
		new = tmp;
		lst = lst->next;
	}
	return (head);
}
