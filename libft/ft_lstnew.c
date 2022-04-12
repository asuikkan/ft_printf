/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:04:22 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/25 16:22:54 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_struct(t_list *new, const void *content, size_t content_size)
{
	new->content = ft_memalloc(content_size);
	if (!new->content)
	{
		free(new);
		new = NULL;
	}
	else
	{
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
}

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
		set_struct(new, content, content_size);
	if (new)
		new->next = NULL;
	return (new);
}
